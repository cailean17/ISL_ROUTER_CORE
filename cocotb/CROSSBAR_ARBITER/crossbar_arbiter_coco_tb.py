from __future__ import annotations

import random

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import FallingEdge, ReadOnly, RisingEdge

from CONSTANTS.constants import NUM_LINKS, TEST_CLK_PERIOD_US
from UTILS.utils import (
    assert_with_message,
    pack_desc,
    set_packed_bit,
    wait_cycles,
)


async def reset_dut(dut):
    await FallingEdge(dut.clk)
    dut.reset.value = 1
    await RisingEdge(dut.clk)
    await ReadOnly()
    assert_with_message("dut.rr_ptr", dut.crossbar_arbiter.rr_ptr.value, 0)
    await FallingEdge(dut.clk)
    dut.reset.value = 0


# simulated driving of pkt_desc_axi interface for l3_buffer_if l3_buffers [NUM_LINKS]
# holds all signals to 0 execpt m_axis_pkt_desc_*
# crv generation of packet_desc
async def constrained_random_drive_l3_buffer_packet_desc_axi_interface(
    clk, l3_buffer_if, valid
):
    await FallingEdge(clk)
    if valid:
        l3_buffer_if.m_axis_pkt_desc_tdata.value = pack_desc(buffer_id=0)
        l3_buffer_if.m_axis_pkt_desc_tvalid.value = 1
        while True:
            await RisingEdge(clk)
            if l3_buffer_if.m_axis_pkt_desc_tready.value == 1:
                break
        await FallingEdge(clk)
        l3_buffer_if.m_axis_pkt_desc_tvalid.value = 0
    else:
        l3_buffer_if.m_axis_pkt_desc_tdata.value = pack_desc(buffer_id=0)
        l3_buffer_if.m_axis_pkt_desc_tvalid.value = 0


async def constrained_random_drive_link_adapter_egress_axi_interface(
    clk, link_adapter_egress
):
    await wait_cycles(clk=clk, n=random.randint(0, 10))
    await FallingEdge(clk)
    link_adapter_egress.s_axis_router_cmd_tready.value = 1
    while True:
        await RisingEdge(clk)
        if link_adapter_egress.s_axis_router_cmd_tvalid.value == 1:
            break
    await FallingEdge(clk)
    link_adapter_egress.s_axis_router_cmd_tready.value = 0


async def validate_grant(dut, expected_granted_idx):
    while not dut.grant_active.value:
        await RisingEdge(dut.clk)
    await ReadOnly()
    assert_with_message(
        "dut.link_adapter_egress.s_axis_router_cmd_tvalid",
        dut.link_adapter_egress.s_axis_router_cmd_tvalid.value,
        1,
    )
    assert_with_message("dut.granted_idx", dut.granted_idx.value, expected_granted_idx)
    assert_with_message(
        "dut.link_adapter_egress.s_axis_router_cmd_tdata",
        dut.link_adapter_egress.s_axis_router_cmd_tdata.value.to_unsigned(),
        dut.l3_buffers[expected_granted_idx].m_axis_pkt_desc_tdata.value.to_unsigned()
        | expected_granted_idx,  # TODO: FIX THIS HARDCODE OR. DONE TO ADD IN THE MODIFIED PACKET DESC WITH BUFFER ID
    )
    await constrained_random_drive_link_adapter_egress_axi_interface(
        clk=dut.clk, link_adapter_egress=dut.link_adapter_egress
    )


# Directed Simple Tests (A)
# Test A.1
@cocotb.test
async def single_request_arbitration_test(dut):
    cocotb.start_soon(Clock(dut.clk, TEST_CLK_PERIOD_US, "us").start())
    await reset_dut(dut)
    requesting_l3_buffer_idx = random.randint(0, NUM_LINKS - 1)
    for i in range(NUM_LINKS):
        cocotb.start_soon(
            constrained_random_drive_l3_buffer_packet_desc_axi_interface(
                clk=dut.clk,
                l3_buffer_if=dut.l3_buffers[i],
                valid=i == requesting_l3_buffer_idx,
            )
        )
    set_packed_bit(dut.request_matrix, requesting_l3_buffer_idx, 1)
    await validate_grant(dut, expected_granted_idx=requesting_l3_buffer_idx)


# Test A.2
@cocotb.test
async def max_request_arbitration_test(dut):
    RUNS = 100
    curr_run = 0
    cocotb.start_soon(Clock(dut.clk, TEST_CLK_PERIOD_US, "us").start())
    await reset_dut(dut)
    idx_to_be_accepted = 0
    while curr_run <= RUNS:
        print(curr_run)
        curr_request_matrix = [0] * NUM_LINKS
        for i in range(NUM_LINKS):
            cocotb.start_soon(
                constrained_random_drive_l3_buffer_packet_desc_axi_interface(
                    clk=dut.clk, l3_buffer_if=dut.l3_buffers[i], valid=1
                )
            )
            curr_request_matrix[i] = 1
        curr_request_matrix = "".join(str(b) for b in curr_request_matrix)
        dut.request_matrix.value = curr_request_matrix
        await FallingEdge(dut.clk)
        await validate_grant(dut, expected_granted_idx=idx_to_be_accepted)
        idx_to_be_accepted = (idx_to_be_accepted + 1) % NUM_LINKS
        curr_run += 1


# Constrained Random Verification + Scoreboarding (B)
