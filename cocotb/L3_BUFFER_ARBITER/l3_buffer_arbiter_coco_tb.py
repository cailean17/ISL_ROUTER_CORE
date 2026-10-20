from __future__ import annotations

import random

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import FallingEdge, ReadOnly, ReadWrite, RisingEdge

from CONSTANTS.constants import NUM_LINKS, TEST_CLK_PERIOD_US
from UTILS.utils import (
    assert_with_message,
    generate_l3_packet_and_desc_pair,
    pack_desc,
    wait_cycles,
)

l3_buffer_table = {}
RUNS = 100


def generate_l3_buffer_table():
    l3_buffer_table.clear()
    for i in range(100 * NUM_LINKS * NUM_LINKS):
        l3_packet_desc, l3_packet = generate_l3_packet_and_desc_pair()
        l3_buffer_table[l3_packet_desc] = {
            "packet": l3_packet,
            "link_adapter_egress_id": random.randint(0, NUM_LINKS - 1),
        }


async def reset_dut(dut):
    await FallingEdge(dut.clk)
    await ReadWrite()
    dut.reset.value = 1
    await RisingEdge(dut.clk)
    await ReadOnly()
    assert_with_message("dut.rr_ptr", dut.l3_buffer_arbiter.rr_ptr.value, 0)
    assert_with_message(
        "dut.servicing_l3_buffer_read",
        dut.l3_buffer_arbiter.servicing_l3_buffer_read.value,
        0,
    )
    await FallingEdge(dut.clk)
    await ReadWrite()
    dut.reset.value = 0
    generate_l3_buffer_table()


# simulated driving of tx_cmd axi interface for link_adapter_tx_if link_adapter_egress [NUM_LINKS]
async def drive_link_adapter_egress_tx_cmd_axi_interface(
    clk, link_adapter_egress, valid, packet_desc=None
):
    await FallingEdge(clk)
    if valid:
        await ReadWrite()
        link_adapter_egress.m_axis_tx_cmd_tdata.value = packet_desc
        link_adapter_egress.m_axis_tx_cmd_tvalid.value = 1
        while True:
            await RisingEdge(clk)
            if link_adapter_egress.m_axis_tx_cmd_tready.value == 1:
                break
        await FallingEdge(clk)
        await ReadWrite()
        link_adapter_egress.m_axis_tx_cmd_tvalid.value = 0
        link_adapter_egress.m_axis_tx_cmd_tdata.value = 0
    else:
        await ReadWrite()
        link_adapter_egress.m_axis_tx_cmd_tdata.value = pack_desc(buffer_id=0)
        link_adapter_egress.m_axis_tx_cmd_tvalid.value = 0


async def constrained_random_drive_l3_buffer_tx_cmd_axi_interface(clk, l3_buffer):
    await wait_cycles(clk=clk, n=random.randint(0, 10))
    await FallingEdge(clk)
    await ReadWrite()
    l3_buffer.s_axis_tx_cmd_tready.value = 1
    while True:
        await RisingEdge(clk)
        if l3_buffer.s_axis_tx_cmd_tvalid.value == 1:
            break
    await FallingEdge(clk)
    await ReadWrite()
    l3_buffer.s_axis_tx_cmd_tready.value = 0


async def drive_l3_buffer_tx_axi_interface(clk, l3_packet_desc, l3_buffer):
    entry = l3_buffer_table.get(l3_packet_desc)
    if entry == None:
        print(f"ERROR: L3 PACKET NOT FOUND WITH DESC {l3_packet_desc}")
        assert False
    l3_packet = entry["packet"]
    current_byte_idx = 0
    while current_byte_idx < len(l3_packet):
        await FallingEdge(clk)
        await ReadWrite()
        l3_buffer.m_axis_tx_tdata.value = l3_packet[current_byte_idx]
        l3_buffer.m_axis_tx_tvalid.value = 1
        l3_buffer.m_axis_tx_tlast.value = int(current_byte_idx == len(l3_packet) - 1)
        await RisingEdge(clk)
        if l3_buffer.m_axis_tx_tvalid.value and l3_buffer.m_axis_tx_tready.value:
            current_byte_idx += 1
    await FallingEdge(clk)
    await ReadWrite()
    l3_buffer.m_axis_tx_tdata.value = 0
    l3_buffer.m_axis_tx_tvalid.value = 0


def validate_idled_link_adapter_egress_tx_axi_interface(link_adapter_egress):
    assert_with_message(
        f"{link_adapter_egress}.s_axis_tx_tvalid",
        link_adapter_egress.s_axis_tx_tvalid.value,
        0,
    )
    assert_with_message(
        f"{link_adapter_egress}.s_axis_tx_tdata",
        link_adapter_egress.s_axis_tx_tdata.value,
        0,
    )
    assert_with_message(
        f"{link_adapter_egress}.s_axis_tx_tlast",
        link_adapter_egress.s_axis_tx_tlast.value,
        0,
    )


async def constrained_random_drive_link_adapter_egress_tx_axi_interface(
    clk, link_adapter_egress_array, accepted_link_adapter_egress_id, l3_packet
):
    await wait_cycles(clk=clk, n=random.randint(0, 10))
    await FallingEdge(clk)
    await ReadWrite()
    link_adapter_egress_array[
        accepted_link_adapter_egress_id
    ].s_axis_tx_tready.value = 1
    current_byte_idx = 0
    while current_byte_idx < len(l3_packet):
        await RisingEdge(clk)
        # assert that the accepted link_adapter_egress recevies the packet byte
        if (
            link_adapter_egress_array[
                accepted_link_adapter_egress_id
            ].s_axis_tx_tvalid.value
            == 1
        ):
            assert_with_message(
                "dut.link_adapter_egress.s_axis_tx_tdata",
                link_adapter_egress_array[
                    accepted_link_adapter_egress_id
                ].s_axis_tx_tdata.value,
                l3_packet[current_byte_idx],
            )
            current_byte_idx += 1
        # assert that the other link_adapter_egresses are idled
        for i, itf in enumerate(link_adapter_egress_array):
            if i == accepted_link_adapter_egress_id:
                continue
            validate_idled_link_adapter_egress_tx_axi_interface(itf)
    await FallingEdge(clk)
    await ReadWrite()
    link_adapter_egress_array[
        accepted_link_adapter_egress_id
    ].s_axis_tx_tready.value = 0


def determine_winining_idx(request_matrix, previously_granted_idx):
    for i in range(1, NUM_LINKS + 1):
        testing_idx = (previously_granted_idx + i) % NUM_LINKS
        if request_matrix & 1 << (testing_idx) == 1 << testing_idx:
            return testing_idx

    return None


async def validate_grant(dut, previously_granted_idx):
    """Checks that the L3 buffer receives the packet_desc advertised on the expected granted link_adapter_egress's
    "tx_cmd" axi interface. On acceptance, starts the "tx" Axi Stream for Transmitting Packet"""
    await RisingEdge(dut.clk)
    await ReadOnly()
    expected_granted_idx = determine_winining_idx(
        request_matrix=dut.request_matrix.value.to_unsigned(),
        previously_granted_idx=previously_granted_idx,
    )
    if expected_granted_idx == None:
        # no requests pending
        assert_with_message("dut.grant_active", dut.grant_active.value, 0)
        assert_with_message(
            "dut.l3_buffer.s_axis_tx_cmd_tdata",
            dut.l3_buffer.s_axis_tx_cmd_tdata.value.to_unsigned(),
            0,
        )
    else:
        # requests pending
        while not dut.grant_active.value:
            await RisingEdge(dut.clk)
            await ReadOnly()
        granted_packet_desc = dut.link_adapter_egress[
            expected_granted_idx
        ].m_axis_tx_cmd_tdata.value.to_unsigned()
        assert_with_message("dut.grant_active", dut.grant_active.value, 1)
        assert_with_message(
            "dut.granted_idx", dut.granted_idx.value, expected_granted_idx
        )
        assert_with_message(
            "dut.l3_buffer.s_axis_tx_cmd_tdata",
            dut.l3_buffer.s_axis_tx_cmd_tdata.value.to_unsigned(),
            granted_packet_desc,
        )
        await constrained_random_drive_l3_buffer_tx_cmd_axi_interface(
            clk=dut.clk, l3_buffer=dut.l3_buffer
        )
        cocotb.start_soon(
            drive_l3_buffer_tx_axi_interface(
                clk=dut.clk, l3_buffer=dut.l3_buffer, l3_packet_desc=granted_packet_desc
            )
        )
    return expected_granted_idx


# Directed Simple Tests (A)
# Test A.1
@cocotb.test
async def single_request_arbitration_test(dut):
    RUNS = 100
    curr_run = 0
    cocotb.start_soon(Clock(dut.clk, TEST_CLK_PERIOD_US, "us").start())
    await reset_dut(dut)
    previously_granted_idx = NUM_LINKS - 1
    while curr_run < RUNS:
        requesting_l3_buffer_idx = random.randint(0, NUM_LINKS - 1)
        for j in range(NUM_LINKS):
            await RisingEdge(dut.clk)
            await ReadWrite()
            dut.l3_buffer_arbiter.rr_ptr.value = j
            entries_picked = []
            for i in range(NUM_LINKS):
                packets_in_buffer_per_egress = list(
                    filter(
                        lambda x: x[1]["link_adapter_egress_id"] == i,
                        l3_buffer_table.items(),
                    )
                )
                picked_entry = random.choice(packets_in_buffer_per_egress)
                picked_packet_desc = picked_entry[0]
                cocotb.start_soon(
                    drive_link_adapter_egress_tx_cmd_axi_interface(
                        clk=dut.clk,
                        link_adapter_egress=dut.link_adapter_egress[i],
                        valid=(i == requesting_l3_buffer_idx),
                        packet_desc=picked_packet_desc,
                    )
                )
                entries_picked.append(picked_entry)
            result = await validate_grant(
                dut=dut, previously_granted_idx=previously_granted_idx
            )
            if result is not None:
                previously_granted_idx = result
                await constrained_random_drive_link_adapter_egress_tx_axi_interface(
                    clk=dut.clk,
                    link_adapter_egress_array=dut.link_adapter_egress,
                    accepted_link_adapter_egress_id=result,
                    l3_packet=entries_picked[result][1]["packet"],
                )
                l3_buffer_table.pop(entries_picked[result][0])
        curr_run += 1


# Test A.2
@cocotb.test
async def max_request_arbitration_test(dut):
    RUNS = 100
    curr_run = 0
    cocotb.start_soon(Clock(dut.clk, TEST_CLK_PERIOD_US, "us").start())
    await reset_dut(dut)
    previously_granted_idx = NUM_LINKS - 1
    while curr_run < RUNS:
        await RisingEdge(dut.clk)
        # generate_l3_buffer_table()
        entries_picked = []
        for i in range(NUM_LINKS):
            packets_in_buffer_per_egress = list(
                filter(
                    lambda x: x[1]["link_adapter_egress_id"] == i,
                    l3_buffer_table.items(),
                )
            )
            picked_entry = random.choice(packets_in_buffer_per_egress)
            picked_packet_desc = picked_entry[0]
            cocotb.start_soon(
                drive_link_adapter_egress_tx_cmd_axi_interface(
                    clk=dut.clk,
                    link_adapter_egress=dut.link_adapter_egress[i],
                    valid=1,
                    packet_desc=picked_packet_desc,
                )
            )
            entries_picked.append(picked_entry)
        result = await validate_grant(
            dut=dut, previously_granted_idx=previously_granted_idx
        )
        if result is not None:
            previously_granted_idx = result
            await constrained_random_drive_link_adapter_egress_tx_axi_interface(
                clk=dut.clk,
                link_adapter_egress_array=dut.link_adapter_egress,
                accepted_link_adapter_egress_id=result,
                l3_packet=entries_picked[result][1]["packet"],
            )
            l3_buffer_table.pop(entries_picked[result][0])
        curr_run += 1


# Constrained Random Verification
# Test B.1
@cocotb.test
async def constrained_random_request_arbitration_test(dut):
    RUNS = 100
    curr_run = 0
    cocotb.start_soon(Clock(dut.clk, TEST_CLK_PERIOD_US, "us").start())
    await reset_dut(dut)
    previously_granted_idx = NUM_LINKS - 1
    while curr_run < RUNS:
        await RisingEdge(dut.clk)
        generate_l3_buffer_table()
        entries_picked = []
        for i in range(NUM_LINKS):
            packets_in_buffer_per_egress = list(
                filter(
                    lambda x: x[1]["link_adapter_egress_id"] == i,
                    l3_buffer_table.items(),
                )
            )
            picked_entry = random.choice(packets_in_buffer_per_egress)
            picked_packet_desc = picked_entry[0]
            valid = random.randint(0, 1)
            cocotb.start_soon(
                drive_link_adapter_egress_tx_cmd_axi_interface(
                    clk=dut.clk,
                    link_adapter_egress=dut.link_adapter_egress[i],
                    valid=valid,
                    packet_desc=picked_packet_desc,
                )
            )
            entries_picked.append(picked_entry)
        result = await validate_grant(
            dut=dut, previously_granted_idx=previously_granted_idx
        )
        if result is not None:
            previously_granted_idx = result
            await constrained_random_drive_link_adapter_egress_tx_axi_interface(
                clk=dut.clk,
                link_adapter_egress_array=dut.link_adapter_egress,
                accepted_link_adapter_egress_id=result,
                l3_packet=entries_picked[result][1]["packet"],
            )
            l3_buffer_table.pop(entries_picked[result][0])
        curr_run += 1
