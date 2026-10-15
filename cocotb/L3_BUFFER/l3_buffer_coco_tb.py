from __future__ import annotations

import copy
import json
import logging
import random
from cmath import inf
from typing import Dict, List

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import (
    FallingEdge,
    ReadOnly,
    RisingEdge,
    Timer,
)

from CONSTANTS.constants import (
    L3_PAYLOAD_MAX_SIZE_BYTES,
    RX_L3_BUFFER_DEPTH_BYTES,
    RX_L3_DESC_BUFFER_DEPTH,
    TEST_CLK_PERIOD_US,
)
from UTILS.utils import (
    assert_with_message,
    generate_l3_packet,
    pack_desc,
    wait_cycles,
)


async def reset_dut(dut):
    await FallingEdge(dut.clk)
    dut.reset.value = 1
    await RisingEdge(dut.clk)
    await ReadOnly()
    assert_with_message("dut.latched_drop", dut.latched_drop.value, 0)
    assert_with_message("dut.pkt_buffer_wr_ptr", dut.pkt_buffer_wr_ptr.value, 0)
    assert_with_message(
        "dut.pkt_buffer_prev_wr_ptr", dut.pkt_buffer_prev_wr_ptr.value, 0
    )
    assert_with_message(
        "dut.pkt_buffer_curr_pkt_len_bytes", dut.pkt_buffer_curr_pkt_len_bytes.value, 0
    )
    assert_with_message("dut.pkt_buffer_bytes_used", dut.pkt_buffer_bytes_used.value, 0)
    assert_with_message("dut.descriptor_rd", dut.descriptor_rd.value, 0)
    assert_with_message("dut.servicing_buffer_read", dut.servicing_buffer_read.value, 0)
    assert_with_message("dut.pkt_buffer_rd_ptr", dut.pkt_buffer_rd_ptr.value, 0)
    assert_with_message("dut.m_axis_tx_tvalid", dut.m_axis_tx_tvalid.value, 0)
    assert_with_message(
        "dut.pkt_desc_buffer_wr_ptr", dut.pkt_desc_buffer_wr_ptr.value, 0
    )
    assert_with_message(
        "dut.pkt_desc_buffer_rd_ptr", dut.pkt_desc_buffer_rd_ptr.value, 0
    )
    assert_with_message(
        "dut.pkt_desc_buffer_retire_ptr", dut.pkt_desc_buffer_retire_ptr.value, 0
    )
    assert_with_message(
        "dut.pkt_desc_buffer_ready_to_retire",
        dut.pkt_desc_buffer_ready_to_retire.value,
        0,
    )
    assert_with_message("dut.unretired_cnt", dut.unretired_cnt.value, 0)
    assert_with_message("dut.pending_cnt", dut.pending_cnt.value, 0)
    await FallingEdge(dut.clk)
    dut.reset.value = 0


# Simulated AXI Interface Drivers
async def drive_link_adapter_rx_to_l3_buffer_axi_master(
    clk, axi_data, axi_valid, axi_last, axi_user, payload, user_sideband, dut_commit
):
    n = len(payload)
    payload_dropped = False
    for i in range(n):
        await FallingEdge(clk)
        axi_data.value = payload[i]
        axi_valid.value = 1
        axi_last.value = 0
        axi_user.value = 0
        axi_last.value = i == n - 1
        axi_user.value = user_sideband if i == n - 1 else 0
        if i == n - 1:
            await ReadOnly()
            payload_dropped = not bool(
                dut_commit.value
            )  # dut raises commit flag on successful packet ingestion
    await FallingEdge(clk)
    axi_valid.value = 0
    axi_last.value = 0
    axi_user.value = 0
    return payload_dropped


async def drive_tx_to_l3_buffer_axi_master(
    clk, axi_data, axi_valid, axi_ready, pkt_desc
):
    await FallingEdge(clk)
    axi_data.value = pkt_desc
    axi_valid.value = 1
    while True:
        await RisingEdge(clk)
        if axi_ready.value == 1:
            break
    await FallingEdge(clk)
    axi_valid.value = 0


async def drive_l3_buffer_to_router_axi_slave(clk, axi_ready, axi_valid):
    await FallingEdge(clk)
    axi_ready.value = 1
    while True:
        await RisingEdge(clk)
        if axi_valid.value == 1:
            break
    await FallingEdge(clk)
    axi_ready.value = 0


async def collect_and_verify_tx_packet(dut, l3_packet, l3_packet_len):
    max_clock_cycle_wait = 1000
    clock_cycles_waiting = 0
    byte_index = 0
    await FallingEdge(dut.clk)
    dut.m_axis_tx_tready.value = 1
    while dut.m_axis_tx_tlast != 0 and clock_cycles_waiting < max_clock_cycle_wait:
        await RisingEdge(dut.clk)
        if dut.m_axis_tx_tvalid.value == 1:
            clock_cycles_waiting = 0
            assert_with_message(
                "dut.m_axis_tx_tdata", dut.m_axis_tx_tdata.value, l3_packet[byte_index]
            )
            byte_index += 1
        else:
            await FallingEdge(dut.clk)
            clock_cycles_waiting += 1
    assert_with_message(
        "Failed to receive full l3 packet",
        actual=byte_index,
        expected=l3_packet_len,
    )


# Directed Simple Tests (A)
# Test A.1
@cocotb.test
async def ingest_one_valid_random_payload_l3_packet(dut):
    cocotb.start_soon(Clock(dut.clk, TEST_CLK_PERIOD_US, "us").start())
    await reset_dut(dut)
    src_sat = random.randint(0, 0xFF)
    dest_sat = random.randint(0, 0xFF)
    ttl = random.randint(0, 0xFF)
    payload_length = random.randint(0, L3_PAYLOAD_MAX_SIZE_BYTES)
    seed_byte = random.randint(0, 0xFF)
    l3_packet, l3_packet_len = generate_l3_packet(
        src_sat=src_sat,
        dest_sat=dest_sat,
        ttl=ttl,
        payload_length=payload_length,
        seed_byte=seed_byte,
    )

    await drive_link_adapter_rx_to_l3_buffer_axi_master(
        clk=dut.clk,
        axi_data=dut.s_axis_rx_tdata,
        axi_valid=dut.s_axis_rx_tvalid,
        axi_user=dut.s_axis_rx_tuser,
        axi_last=dut.s_axis_rx_tlast,
        payload=l3_packet,
        user_sideband=0,
        dut_commit=dut.commit,
    )

    assert_with_message(
        "dut.pkt_buffer_wr_ptr", dut.pkt_buffer_wr_ptr.value, l3_packet_len
    )
    assert_with_message(
        "dut.pkt_buffer_bytes_used", dut.pkt_buffer_bytes_used.value, l3_packet_len
    )
    assert_with_message(
        "dut.m_axis_pkt_desc_tdata",
        dut.m_axis_pkt_desc_tdata.value,
        pack_desc(start_ptr=0, desc_id=0, length=l3_packet_len, dest_sat=dest_sat),
    )
    assert_with_message(
        "dut.m_axis_pkt_desc_tvalid", dut.m_axis_pkt_desc_tvalid.value, 1
    )


# Test A.2
@cocotb.test
async def ingest_one_valid_max_payload_l3_packet(dut):
    cocotb.start_soon(Clock(dut.clk, TEST_CLK_PERIOD_US, "us").start())
    await reset_dut(dut)
    l3_packet, l3_packet_len = generate_l3_packet(
        src_sat=0x01,
        dest_sat=0x03,
        ttl=0x03,
        payload_length=L3_PAYLOAD_MAX_SIZE_BYTES,
        seed_byte=random.randint(0, 0xFF),
    )

    await drive_link_adapter_rx_to_l3_buffer_axi_master(
        clk=dut.clk,
        axi_data=dut.s_axis_rx_tdata,
        axi_valid=dut.s_axis_rx_tvalid,
        axi_user=dut.s_axis_rx_tuser,
        axi_last=dut.s_axis_rx_tlast,
        payload=l3_packet,
        user_sideband=0,
        dut_commit=dut.commit,
    )

    assert_with_message(
        "dut.pkt_buffer_wr_ptr", dut.pkt_buffer_wr_ptr.value, l3_packet_len
    )
    assert_with_message(
        "dut.pkt_buffer_bytes_used", dut.pkt_buffer_bytes_used.value, l3_packet_len
    )
    assert_with_message(
        "dut.m_axis_pkt_desc_tdata",
        dut.m_axis_pkt_desc_tdata.value,
        pack_desc(start_ptr=0, desc_id=0, length=l3_packet_len, dest_sat=0x03),
    )
    assert_with_message(
        "dut.m_axis_pkt_desc_tvalid", dut.m_axis_pkt_desc_tvalid.value, 1
    )


# Test A.3
@cocotb.test
async def sequential_ingest_and_service_scoreboard(dut):
    runs = 100
    cocotb.start_soon(Clock(dut.clk, TEST_CLK_PERIOD_US, "us").start())
    await reset_dut(dut)
    total_bytes = 0
    for i in range(runs):
        src_sat = random.randint(0, 0xFF)
        dest_sat = random.randint(0, 0xFF)
        ttl = random.randint(0, 0xFF)
        payload_length = random.randint(0, L3_PAYLOAD_MAX_SIZE_BYTES)
        seed_byte = random.randint(0, 0xFF)
        l3_packet, l3_packet_len = generate_l3_packet(
            src_sat=src_sat,
            dest_sat=dest_sat,
            ttl=ttl,
            payload_length=payload_length,
            seed_byte=seed_byte,
        )

        # Phase 1 - Ingest: Ingest and Store L3 Packet from Link Adapter RX in L3 Buffer
        await drive_link_adapter_rx_to_l3_buffer_axi_master(
            clk=dut.clk,
            axi_data=dut.s_axis_rx_tdata,
            axi_valid=dut.s_axis_rx_tvalid,
            axi_user=dut.s_axis_rx_tuser,
            axi_last=dut.s_axis_rx_tlast,
            payload=l3_packet,
            user_sideband=0,
            dut_commit=dut.commit,
        )
        pkt_desc = pack_desc(
            start_ptr=total_bytes % RX_L3_BUFFER_DEPTH_BYTES,
            desc_id=i % RX_L3_DESC_BUFFER_DEPTH,
            length=l3_packet_len,
            dest_sat=dest_sat,
        )

        # Phase 2 - Advertise : Handshake and transmit L3 packet descriptor to router core

        # (Check 3.2.1): Confirm that the L3 buffer is advertising the new L3 packet descriptor to router core
        assert_with_message(
            "dut.m_axis_pkt_desc_tdata", dut.m_axis_pkt_desc_tdata.value, pkt_desc
        )
        assert_with_message(
            "dut.m_axis_pkt_desc_tvalid", dut.m_axis_pkt_desc_tvalid.value, 1
        )

        await drive_l3_buffer_to_router_axi_slave(
            clk=dut.clk,
            axi_ready=dut.m_axis_pkt_desc_tready,
            axi_valid=dut.m_axis_pkt_desc_tvalid,
        )

        # (Check 3.2.2): Confirm that the L3 buffer is no longer advertising a packet descriptor to router core
        assert_with_message(
            "dut.m_axis_pkt_desc_tvalid", dut.m_axis_pkt_desc_tvalid.value, 0
        )

        # Phase 3 - Service:
        await drive_tx_to_l3_buffer_axi_master(
            clk=dut.clk,
            axi_data=dut.s_axis_tx_cmd_tdata,
            axi_valid=dut.s_axis_tx_cmd_tvalid,
            axi_ready=dut.s_axis_tx_cmd_tready,
            pkt_desc=pkt_desc,
        )
        assert_with_message("dut.descriptor_rd", dut.descriptor_rd.value, pkt_desc)
        await collect_and_verify_tx_packet(
            dut=dut, l3_packet=l3_packet, l3_packet_len=l3_packet_len
        )

        total_bytes += l3_packet_len


# Constrained Random Verification Testing (B)


# Scoreboard Value:
class ScoreboardValue:
    def __init__(
        self, l3_packet: list[int], ingest_timestamp_ns: float, packet_dropped: bool
    ):  # noqa: FA102
        self.l3_packet = l3_packet
        self.descriptor_advertised = False
        self.l3_packet_len = len(l3_packet)
        self.ingest_timestamp_ns = ingest_timestamp_ns
        self.service_timestamp_ns = None
        self.packet_dropped = packet_dropped


Scoreboard = Dict[int, ScoreboardValue]
FinalState = List[ScoreboardValue]
scoreboard: Scoreboard = {}
final_state: FinalState = []


def verify_final_state(final_state: FinalState, dut):
    max_packet_latency = 0
    min_packet_latency = float(inf)
    avg_packet_latency = 0
    count = 0
    sum = 0
    for v in final_state:
        delta_ns = v.service_timestamp_ns - v.ingest_timestamp_ns
        max_packet_latency = max(max_packet_latency, delta_ns)
        min_packet_latency = min(min_packet_latency, delta_ns)
        sum += delta_ns
        count += 1
    avg_packet_latency = sum / count
    assert_with_message("dut.pending_cnt", dut.pending_cnt.value, 0)
    assert_with_message("dut.unretired_cnt", dut.unretired_cnt.value, 0)
    return {
        "max_packet_latency_ns": max_packet_latency,
        "min_packet_latency_ns": min_packet_latency,
        "avg_packet_latency_ns": avg_packet_latency,
        "total_packets_transmitted": count,
    }


# Coroutines for L3-buffer Constrained Random Verification Scoreboarding:
# Phase 1 - Ingest : Attemp to ingest and Store L3 Packet from Link Adapter RX in L3 Buffer
async def ingest(dut, count, scoreboard: Scoreboard, seed):
    total_bytes = 0
    rng = random.Random(seed + 1)
    i = 0
    while i < count:
        await wait_cycles(clk=dut.clk, n=rng.randint(0, 50))
        src_sat = rng.randint(0, 0xFF)
        dest_sat = rng.randint(0, 0xFF)
        ttl = rng.randint(0, 0xFF)
        payload_length = rng.randint(0, L3_PAYLOAD_MAX_SIZE_BYTES)
        seed_byte = rng.randint(0, 0xFF)
        invalidate_packet = rng.randint(0, 1)
        l3_packet, l3_packet_len = generate_l3_packet(
            src_sat=src_sat,
            dest_sat=dest_sat,
            ttl=ttl,
            payload_length=payload_length,
            seed_byte=seed_byte,
        )

        pkt_desc = pack_desc(
            start_ptr=total_bytes % RX_L3_BUFFER_DEPTH_BYTES,
            desc_id=i % RX_L3_DESC_BUFFER_DEPTH,
            length=l3_packet_len,
            dest_sat=dest_sat,
        )

        packet_dropped = await drive_link_adapter_rx_to_l3_buffer_axi_master(
            clk=dut.clk,
            axi_data=dut.s_axis_rx_tdata,
            axi_valid=dut.s_axis_rx_tvalid,
            axi_user=dut.s_axis_rx_tuser,
            axi_last=dut.s_axis_rx_tlast,
            payload=l3_packet,
            user_sideband=invalidate_packet,
            dut_commit=dut.commit,
        )
        if not packet_dropped:
            i += 1
            total_bytes += l3_packet_len
            scoreboard[pkt_desc] = ScoreboardValue(
                l3_packet=l3_packet,
                ingest_timestamp_ns=cocotb.utils.get_sim_time(unit="ns"),
                packet_dropped=packet_dropped,
            )


# Phase 2 - Advertise : Handshake and transmit L3 packet descriptor to Router Core
async def advertise(dut, scoreboard: Scoreboard):
    dut.m_axis_pkt_desc_tready.value = 1
    while True:
        await RisingEdge(dut.clk)
        if (
            dut.m_axis_pkt_desc_tvalid.value == 1
            and dut.m_axis_pkt_desc_tready.value == 1
        ):
            pkt_desc = int(dut.m_axis_pkt_desc_tdata.value)
            assert_with_message(
                "dut.m_axis_pkt_desc_tdata in scoreboard", pkt_desc in scoreboard, 1
            )
            assert_with_message(
                f"pkt_desc {pkt_desc:#x} advertised twice: ",
                not scoreboard[pkt_desc].descriptor_advertised,
                1,
            )
            scoreboard[pkt_desc].descriptor_advertised = True


# Phase 3 - Service: Read out L3 Packet from Simulated Link_Adapter_Tx
async def service(
    dut, scoreboard: Scoreboard, final_state: FinalState, expected_packets_count, seed
):
    rng = random.Random(seed + 2)
    packets_serviced = 0
    max_stall_cycles = 10000
    cycles_stalled = 0
    while packets_serviced < expected_packets_count:
        await wait_cycles(dut.clk, n=rng.randint(0, 50))
        if scoreboard:
            ready = [
                (k, v)
                for k, v in scoreboard.items()
                if v.descriptor_advertised and not v.packet_dropped
            ]
            if not ready:
                cycles_stalled += 1
                if cycles_stalled >= max_stall_cycles:
                    break
                await RisingEdge(dut.clk)
                continue
            cycles_stalled = 0
            k, v = rng.choice(ready)  # simulating random router arbitration
            await drive_tx_to_l3_buffer_axi_master(
                clk=dut.clk,
                axi_data=dut.s_axis_tx_cmd_tdata,
                axi_valid=dut.s_axis_tx_cmd_tvalid,
                axi_ready=dut.s_axis_tx_cmd_tready,
                pkt_desc=k,
            )
            assert_with_message("dut.descriptor_rd", dut.descriptor_rd.value, k)
            await collect_and_verify_tx_packet(
                dut=dut, l3_packet=v.l3_packet, l3_packet_len=v.l3_packet_len
            )
            packets_serviced += 1
            new_v = copy.deepcopy(v)
            new_v.service_timestamp_ns = cocotb.utils.get_sim_time(unit="ns")
            final_state.append(new_v)
            del scoreboard[k]
        else:
            await RisingEdge(dut.clk)
            cycles_stalled += 1


# Test B.1
@cocotb.test
async def constrained_random_ingest_and_service_scoreboard(dut, seed=2):
    dut._log.setLevel(logging.DEBUG)
    current_seed = cocotb.RANDOM_SEED
    dut._log.debug(f"Seeding with {current_seed}")
    cocotb.start_soon(Clock(dut.clk, TEST_CLK_PERIOD_US, "us").start())
    await reset_dut(dut=dut)
    scoreboard.clear()
    cocotb.start_soon(
        ingest(dut=dut, scoreboard=scoreboard, count=100, seed=current_seed)
    )
    cocotb.start_soon(advertise(dut=dut, scoreboard=scoreboard))
    await service(
        dut=dut,
        scoreboard=scoreboard,
        final_state=final_state,
        expected_packets_count=100,
        seed=current_seed,
    )
    await wait_cycles(clk=dut.clk, n=RX_L3_DESC_BUFFER_DEPTH)
    # (DESCRIPTOR BUFFER DEPTH (64)) cycles max wait for packet descriptor retiring
    print(json.dumps(verify_final_state(final_state=final_state, dut=dut)))
