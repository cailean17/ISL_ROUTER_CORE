from __future__ import annotations

import random

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import FallingEdge, NextTimeStep, ReadOnly, ReadWrite, RisingEdge

from CONSTANTS.constants import NUM_LINKS, TEST_CLK_PERIOD_US
from UTILS.utils import (
    assert_with_message,
    pack_desc,
    wait_cycles,
)


async def reset_dut(dut):
    await FallingEdge(dut.clk)
    await ReadWrite()
    dut.reset.value = 1
    await RisingEdge(dut.clk)
    await ReadOnly()
    assert_with_message("dut.rr_ptr", dut.crossbar_arbiter.rr_ptr.value, 0)
    await FallingEdge(dut.clk)
    await ReadWrite()
    dut.reset.value = 0


# simulated driving of pkt_desc_axi interface for l3_buffer_if l3_buffers [NUM_LINKS]
# holds all signals to 0 execpt m_axis_pkt_desc_*
# crv generation of packet_desc
async def constrained_random_drive_l3_buffer_packet_desc_axi_interface(
    clk, l3_buffer_if, valid
):
    await FallingEdge(clk)
    if valid:
        await ReadWrite()
        l3_buffer_if.m_axis_pkt_desc_tdata.value = pack_desc(buffer_id=0)
        l3_buffer_if.m_axis_pkt_desc_tvalid.value = 1
        # print(
        #     f"time={cocotb.utils.get_sim_time('ns')} "
        #     f"buffer={l3_buffer_if._name} tvalid=1"
        # )
        while True:
            await RisingEdge(clk)
            if l3_buffer_if.m_axis_pkt_desc_tready.value == 1:
                break
        await FallingEdge(clk)
        await ReadWrite()
        l3_buffer_if.m_axis_pkt_desc_tvalid.value = 0
    else:
        await ReadWrite()
        l3_buffer_if.m_axis_pkt_desc_tdata.value = pack_desc(buffer_id=0)
        l3_buffer_if.m_axis_pkt_desc_tvalid.value = 0
        # print(
        #     f"time={cocotb.utils.get_sim_time('ns')} "
        #     f"buffer={l3_buffer_if._name} tvalid=0"
        # )


async def constrained_random_drive_link_adapter_egress_axi_interface(
    clk, link_adapter_egress
):
    await wait_cycles(clk=clk, n=random.randint(0, 10))
    await FallingEdge(clk)
    await ReadWrite()
    link_adapter_egress.s_axis_router_cmd_tready.value = 1
    while True:
        await RisingEdge(clk)
        if link_adapter_egress.s_axis_router_cmd_tvalid.value == 1:
            break
    await FallingEdge(clk)
    await ReadWrite()
    link_adapter_egress.s_axis_router_cmd_tready.value = 0


def determine_winining_idx(request_matrix, previously_granted_idx):
    for i in range(1, NUM_LINKS + 1):
        testing_idx = (previously_granted_idx + i) % NUM_LINKS
        if request_matrix & 1 << (testing_idx) == 1 << testing_idx:
            return testing_idx

    return None


async def validate_grant(dut, previously_granted_idx):
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
            "dut.granted_idx",
            dut.granted_idx.value,
            (previously_granted_idx + 1) % NUM_LINKS,
        )
        assert_with_message(
            "dut.link_adapter_egress.s_axis_router_cmd_tdata",
            dut.link_adapter_egress.s_axis_router_cmd_tdata.value.to_unsigned(),
            0,
        )
    else:
        # requests pending
        while not dut.grant_active.value:
            await RisingEdge(dut.clk)
            await ReadOnly()
        assert_with_message(
            "dut.link_adapter_egress.s_axis_router_cmd_tvalid",
            dut.link_adapter_egress.s_axis_router_cmd_tvalid.value,
            1,
        )
        assert_with_message(
            "dut.granted_idx", dut.granted_idx.value, expected_granted_idx
        )
        assert_with_message(
            "dut.link_adapter_egress.s_axis_router_cmd_tdata",
            dut.link_adapter_egress.s_axis_router_cmd_tdata.value.to_unsigned(),
            dut.l3_buffers[
                expected_granted_idx
            ].m_axis_pkt_desc_tdata.value.to_unsigned()
            | expected_granted_idx,  # TODO: FIX THIS HARDCODE OR. DONE TO ADD IN THE MODIFIED PACKET DESC WITH BUFFER ID
        )
        await constrained_random_drive_link_adapter_egress_axi_interface(
            clk=dut.clk, link_adapter_egress=dut.link_adapter_egress
        )
    return (
        expected_granted_idx
        if expected_granted_idx is not None
        else previously_granted_idx
    )


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
            dut.crossbar_arbiter.rr_ptr.value = j
            for i in range(NUM_LINKS):
                cocotb.start_soon(
                    constrained_random_drive_l3_buffer_packet_desc_axi_interface(
                        clk=dut.clk,
                        l3_buffer_if=dut.l3_buffers[i],
                        valid=i == requesting_l3_buffer_idx,
                    )
                )
            await validate_grant(dut=dut, previously_granted_idx=previously_granted_idx)
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
        for i in range(NUM_LINKS):
            cocotb.start_soon(
                constrained_random_drive_l3_buffer_packet_desc_axi_interface(
                    clk=dut.clk, l3_buffer_if=dut.l3_buffers[i], valid=1
                )
            )
        previously_granted_idx = await validate_grant(
            dut=dut, previously_granted_idx=previously_granted_idx
        )
        curr_run += 1


# Full Constrained Random Verification (B)
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
        for i in range(NUM_LINKS):
            request_valid = random.randint(0, 1)
            cocotb.start_soon(
                constrained_random_drive_l3_buffer_packet_desc_axi_interface(
                    clk=dut.clk, l3_buffer_if=dut.l3_buffers[i], valid=request_valid
                )
            )
        previously_granted_idx = await validate_grant(
            dut=dut, previously_granted_idx=previously_granted_idx
        )
        curr_run += 1
