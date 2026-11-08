from __future__ import annotations

import copy
import logging
import random
from typing import Dict, List, Tuple

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import FallingEdge, ReadOnly, ReadWrite, RisingEdge

from CONSTANTS.constants import (
    L2_HEADER_SIZE_BYTES,
    L3_DEST_SAT_SIZE_BYTES,
    L3_HEADER_SIZE_BYTES,
    L3_PAYLOAD_LENGTH_SIZE_BYTES,
    L3_SRC_SAT_SIZE_BYTES,
    L3_TTL_SIZE_BYTES,
    NUM_LINKS,
    TEST_CLK_PERIOD_US,
    TOTAL_SATS,
)
from UTILS.utils import (
    assert_with_message,
    generate_l2_frame,
    generate_l3_packet_and_desc_pair,
    unpack_desc,
    wait_cycles,
)

RUNS = 100
UPLINK_INGRESS_ID_INTO_SRC_SAT = NUM_LINKS
MAX_STALL_CYLCES = 100000


# Scoreboard Value:
class ScoreboardValue:
    def __init__(self, l3_packet: list[int], ingest_timestamp_ns: float):
        self.l3_packet = l3_packet
        self.l3_packet_len = len(l3_packet)
        self.ingest_timestamp_ns = ingest_timestamp_ns
        self.receive_timestamp_ns = None


Scoreboard = Dict[
    Tuple[int, int, int], ScoreboardValue
]  # key: (src_sat, dest_sat, l3_packet_runing_sum) only invariants for packets across satellites
FinalState = List[ScoreboardValue]
working_scoreboard: Scoreboard = {}
committed_scoreboard: Scoreboard = {}


def scoreboard_analysis(
    working_scoreboard: Scoreboard, committed_scoreboard: Scoreboard
):
    dropped_packets = list(working_scoreboard)
    dropped_packet_count = len(dropped_packets)
    committed_packet_count = len(committed_scoreboard)
    committed_byte_count = sum(
        v.l3_packet_len + L2_HEADER_SIZE_BYTES for v in committed_scoreboard.values()
    )
    earliest_send_ns = min(v.ingest_timestamp_ns for v in committed_scoreboard.values())
    latest_receive_ns = max(
        v.receive_timestamp_ns
        for v in committed_scoreboard.values()
        if v.receive_timestamp_ns is not None
    )

    total_packet_count = dropped_packet_count + committed_packet_count
    latencies = 0
    worst_latency = 0
    worst_latency_key = (0, 0, 0)
    worst_latency_length = 0
    for k, v in committed_scoreboard.items():
        if v.receive_timestamp_ns is not None:
            curr_latency = v.receive_timestamp_ns - v.ingest_timestamp_ns
            worst_latency = max(worst_latency, curr_latency)
            if worst_latency == curr_latency:
                worst_latency_key = k
                worst_latency_length = v.l3_packet_len
            latencies += curr_latency

    network_throughput_gbps = (
        (committed_byte_count * 8)
        / ((latest_receive_ns - earliest_send_ns) / 1e9)
        / 1e9
    )
    print(
        f"""
        ========================SCOREBOARD_ANALYSIS===========================
        Total Packets Routed: {total_packet_count} ), 
        Total Packets Dropped: {dropped_packet_count} ({dropped_packet_count * 100 / total_packet_count} %), 
        Total Packets Sucessfully Received: {committed_packet_count} ({committed_packet_count * 100 / total_packet_count} %) ({committed_byte_count} Bytes) (Global {network_throughput_gbps} Gbps), 
        Avg Latency: {latencies / committed_packet_count} ns, 
        Worst Latency: {worst_latency} ns for packet of size {worst_latency_length} from SrcSat: {worst_latency_key[0]} to DestSat: {worst_latency_key[1]}))
        """
    )

    # 1. Defined header names and their specific spacing
    headers = [
        "SAT_ID",
        "PACKETS ORIGINATED",
        "EXPECTED PACKETS SUNK",
        "ACTUAL PACKETS SUNK",
        "MISSING PACKETS",
    ]

    # Calculate widths based on the column string lengths
    w_id = len(headers[0])  # 6
    w_tx = len(headers[1])  # 19
    w_exp = len(headers[2])  # 16
    w_rx = len(headers[3])  # 16
    w_missing = len(headers[4])  # 7

    # Print the header line exactly
    print(
        f" {headers[0]} | {headers[1]} | {headers[2]} | {headers[3]} | {headers[4]} |"
    )

    for i in range(TOTAL_SATS):
        transmitted_packet_count = sum(
            1 for (k, v) in committed_scoreboard.items() if k[0] == i
        ) + sum(1 for (k, v) in working_scoreboard.items() if k[0] == i)

        expected_packet_count = sum(
            1 for (k, v) in committed_scoreboard.items() if k[1] == i
        ) + sum(1 for (k, v) in working_scoreboard.items() if k[1] == i)

        received_packet_count = sum(
            1 for (k, v) in committed_scoreboard.items() if k[1] == i
        )

        missing = expected_packet_count - received_packet_count

        # 2. Applied text padding variables to dynamically space the values
        print(
            f" {i:<{w_id}} | {transmitted_packet_count:<{w_tx}} | {expected_packet_count:<{w_exp}} | {received_packet_count:<{w_rx}} | {missing:<{w_missing}} |"
        )


async def reset_dut(dut):
    await FallingEdge(dut.clk)
    await ReadWrite()
    dut.reset.value = 1
    await RisingEdge(dut.clk)
    await ReadWrite()
    dut.reset.value = 0


async def drive_l2_frame_into_router_core(uplink_data_port, clk, l2_frame):
    for byte in l2_frame:
        await FallingEdge(clk)
        await ReadWrite()
        uplink_data_port.value = byte
        await RisingEdge(clk)


async def listen_for_expected_l3_packet_on_router_core_downlink(
    router_core, clk, l3_packet
):
    curr_byte_count = 0
    cycle_count = 0
    while curr_byte_count < len(l3_packet) and cycle_count != MAX_STALL_CYLCES:
        # print(f"RECEIVED BYTE: {curr_byte_count}")
        await FallingEdge(clk)
        await ReadOnly()
        while (
            router_core.downlink.s_axis_tx_tvalid.value != 1
            and cycle_count != MAX_STALL_CYLCES
        ):
            await FallingEdge(clk)
            await ReadOnly()
            # print(f"REQUEST_MATRIX: {src_router_core.crossbar_arbiters_request_matrix.value}")
            cycle_count += 1
        assert_with_message(
            "router_core.downlink.s_axis_tx_tdata",
            router_core.downlink.s_axis_tx_tdata.value,
            l3_packet[curr_byte_count],
        )
        curr_byte_count += 1


async def listen_for_scoreboard_l3_packet_on_router_core_downlink(
    sat_id,
    router_core,
    working_scoreboard: Scoreboard,
    committed_scoreboard: Scoreboard,
    listen_length_cycles,
):
    cycle_count = 0
    bytes_read = 0
    l3_packet_received = []
    l3_packet_length = 0
    src_sat = 0
    dest_sat = 0
    while cycle_count != listen_length_cycles:
        cycle_count += 1
        await FallingEdge(router_core.clk)
        await ReadOnly()
        if (
            not router_core.downlink.s_axis_tx_tvalid.value
            or not router_core.downlink.s_axis_tx_tready.value
        ):
            continue
        byte_in = router_core.downlink.s_axis_tx_tdata.value.to_unsigned()
        # read header bytes
        if bytes_read == L3_SRC_SAT_SIZE_BYTES - 1:
            # src_sat
            src_sat = byte_in
        elif bytes_read == L3_DEST_SAT_SIZE_BYTES + L3_SRC_SAT_SIZE_BYTES - 1:
            # dest_sat
            dest_sat = byte_in
            assert_with_message(
                name=f"SAT {sat_id} received a packet meant for SAT {dest_sat}",
                actual=dest_sat == sat_id,
                expected=True,
            )
        elif (
            bytes_read
            == L3_TTL_SIZE_BYTES + L3_DEST_SAT_SIZE_BYTES + L3_SRC_SAT_SIZE_BYTES - 1
        ):
            pass
            # TTL (don't care)
        elif (
            bytes_read
            == L3_TTL_SIZE_BYTES + L3_DEST_SAT_SIZE_BYTES + L3_SRC_SAT_SIZE_BYTES
        ):
            # Payload Length Byte 1
            l3_packet_length = byte_in
        elif (
            bytes_read
            == L3_PAYLOAD_LENGTH_SIZE_BYTES
            + L3_TTL_SIZE_BYTES
            + L3_DEST_SAT_SIZE_BYTES
            + L3_SRC_SAT_SIZE_BYTES
            - 1
        ):
            # Payload Length Byte 2
            l3_packet_length = byte_in << 8 | l3_packet_length
        else:
            # Read payload bytes:
            if bytes_read == l3_packet_length + L3_HEADER_SIZE_BYTES - 1:
                # End of Packet, reset bytes_read, append last byte and check for existance and equality within scoreboard
                l3_packet_received.append(byte_in)
                l3_packet_running_sum = sum(l3_packet_received)
                assert_with_message(
                    name=f"SAT {sat_id} received a L3 Packet that was NOT tagged in the scoreboard",
                    actual=(src_sat, dest_sat, l3_packet_running_sum)
                    not in working_scoreboard,
                    expected=False,
                )  # current packet was not destined for current SAT or not tagged in the scoreboard, FAIL
                assert_with_message(
                    name=f"{sat_id}'s received L3 Packet did not match the value tagged in the scoreboard",
                    actual=working_scoreboard[
                        (src_sat, dest_sat, l3_packet_running_sum)
                    ].l3_packet
                    == l3_packet_received,
                    expected=True,
                )
                print(f"Received key {src_sat}, {dest_sat}, {l3_packet_running_sum}")
                temp = copy.deepcopy(
                    working_scoreboard[(src_sat, dest_sat, l3_packet_running_sum)]
                )
                temp.receive_timestamp_ns = cocotb.utils.get_sim_time(unit="ns")
                del working_scoreboard[(src_sat, dest_sat, l3_packet_running_sum)]
                committed_scoreboard[(src_sat, dest_sat, l3_packet_running_sum)] = temp
                l3_packet_received = []
                src_sat = 0
                dest_sat = 0
                l3_packet_length = 0
                bytes_read = 0
                continue
        l3_packet_received.append(byte_in)
        bytes_read += 1


# DIRECTED TESTS (A)
# Test A.1
# @cocotb.test
async def single_packet_send_and_receive_test(dut):
    cocotb.start_soon(Clock(dut.clk, TEST_CLK_PERIOD_US, "us").start())
    for _ in range(RUNS):
        await reset_dut(dut)
        src_sat = random.randint(0, (TOTAL_SATS) - 1)
        dest_sat = random.randint(0, (TOTAL_SATS) - 1)
        dut._log.info(f"SENDING FROM {src_sat} to {dest_sat}")
        l3_packet_desc, l3_packet = generate_l3_packet_and_desc_pair(
            src_sat=src_sat, dest_sat=dest_sat
        )
        l2_frame = generate_l2_frame(l3_packet=l3_packet)
        dest_sat = int(unpack_desc(l3_packet_desc)["dest_sat"])
        cocotb.start_soon(
            drive_l2_frame_into_router_core(
                clk=dut.clk,
                l2_frame=l2_frame,
                uplink_data_port=getattr(dut, f"sat_{src_sat}_uplink_data"),
            )
        )
        await listen_for_expected_l3_packet_on_router_core_downlink(
            router_core=getattr(dut, f"sat_{dest_sat}"),
            clk=dut.clk,
            l3_packet=l3_packet,
        )
        dut._log.info(f"SUCESSFULLY RECEIVED AT {dest_sat}")


# Constrained Random Verification Testing (B)
async def transmit(dut, sat_id, packet_count, working_scoreboard):
    for _ in range(packet_count):
        await wait_cycles(
            dut.clk, random.randint(4, 10)
        )  # wait anywhere between 4 and 10 cycles (20us, 50ns), 4 cycles to allow CRC flushing from 4 cycle deep delay pipeline
        src_sat = sat_id
        dest_sat = random.randint(0, (TOTAL_SATS) - 1)
        _, l3_packet = generate_l3_packet_and_desc_pair(
            src_sat=src_sat, dest_sat=dest_sat
        )
        l2_frame = generate_l2_frame(l3_packet=l3_packet)
        # dest_sat = int(unpack_desc(l3_packet_desc)["dest_sat"])
        await drive_l2_frame_into_router_core(
            clk=dut.clk,
            l2_frame=l2_frame,
            uplink_data_port=getattr(dut, f"sat_{sat_id}_uplink_data"),
        )
        l3_packet_running_sum = sum(l3_packet)
        print(f"STORED_KEY: {src_sat}, {dest_sat}, {l3_packet_running_sum}")
        working_scoreboard[(src_sat, dest_sat, l3_packet_running_sum)] = (
            ScoreboardValue(
                l3_packet=l3_packet,
                ingest_timestamp_ns=cocotb.utils.get_sim_time(unit="ns"),
            )
        )


async def receive(sat_id, router_core, working_scoreboard, committed_scoreboard):
    await listen_for_scoreboard_l3_packet_on_router_core_downlink(
        sat_id=sat_id,
        router_core=router_core,
        working_scoreboard=working_scoreboard,
        committed_scoreboard=committed_scoreboard,
        listen_length_cycles=MAX_STALL_CYLCES,
    )


# Test B.1
@cocotb.test
async def constrained_random_satellite_network_scoreboard(dut):
    dut._log.setLevel(logging.DEBUG)
    current_seed = cocotb.RANDOM_SEED
    dut._log.debug(f"Seeding with {current_seed}")
    cocotb.start_soon(Clock(dut.clk, TEST_CLK_PERIOD_US, "us").start())
    await reset_dut(dut=dut)
    working_scoreboard.clear()
    committed_scoreboard.clear()
    for i in range(TOTAL_SATS):
        cocotb.start_soon(
            transmit(
                dut=dut,
                sat_id=i,
                packet_count=100,
                working_scoreboard=working_scoreboard,
            )
        )
        cocotb.start_soon(
            receive(
                sat_id=i,
                router_core=getattr(dut, f"sat_{i}"),
                working_scoreboard=working_scoreboard,
                committed_scoreboard=committed_scoreboard,
            )
        )
    await wait_cycles(dut.clk, MAX_STALL_CYLCES)
    scoreboard_analysis(
        working_scoreboard=working_scoreboard, committed_scoreboard=committed_scoreboard
    )
