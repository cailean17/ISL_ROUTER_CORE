from __future__ import annotations

import random

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import FallingEdge, ReadOnly, ReadWrite, RisingEdge

from CONSTANTS.constants import NUM_LINKS, TOTAL_SATS, TEST_CLK_PERIOD_US
from UTILS.utils import (
    assert_with_message,
    generate_l3_packet_and_desc_pair,
    generate_l2_frame,
    pack_desc,
    unpack_desc,
    wait_cycles,
)



async def reset_dut(dut):
    await FallingEdge(dut.clk)
    await ReadWrite()
    dut.reset.value = 1
    await RisingEdge(dut.clk)
    await ReadWrite()
    dut.reset.value = 0

async def drive_l2_frame_into_router_core(laser_link_ingress_if, laser_link_ingress_idx, clk, l2_frame):
    for byte in l2_frame:
        print(f"INGRESSED BYTE {byte}")
        await FallingEdge(clk)
        await ReadWrite()
        laser_link_ingress_if[laser_link_ingress_idx].data.value = byte
        await RisingEdge(clk)

async def sink_expected_l2_frame_into_router_core(router_core, src_router_core, clk, l3_packet):
    curr_byte_count = 0
    while curr_byte_count < len(l3_packet):
        print(f"RECEIVED BYTE: {curr_byte_count}")
        await FallingEdge(clk)
        await ReadOnly()
        while router_core.downlink.s_axis_tx_tvalid.value != 1:
            await FallingEdge(clk)
            await ReadOnly()
            print(f"REQUEST_MATRIX: {router_core.crossbar_arbiters_request_matrix.value}")
        assert_with_message("router_core.downlink.s_axis_tx_tdata", router_core.downlink.s_axis_tx_tdata.value, l3_packet[curr_byte_count] )  
        curr_byte_count += 1

# DIRECTED TESTS (A)

# Test A.1
@cocotb.test
async def single_packet_send_and_receive_test(dut):
    cocotb.start_soon(Clock(dut.clk, TEST_CLK_PERIOD_US, "us").start())
    await reset_dut(dut)
    src_sat = random.randint(0,(TOTAL_SATS)-1)
    dest_sat = random.randint(0,(TOTAL_SATS)-1)
    print(f"SENDING FROM {src_sat} to {dest_sat}")
    ingress_id_into_src_sat = random.randint(0, NUM_LINKS-1)
    l3_packet_desc, l3_packet = generate_l3_packet_and_desc_pair(src_sat=src_sat, dest_sat=dest_sat)
    l2_frame = generate_l2_frame(l3_packet=l3_packet) 
    dest_sat = int(unpack_desc(l3_packet_desc)["dest_sat"])
    cocotb.start_soon(
        drive_l2_frame_into_router_core(laser_link_ingress_if=getattr(dut, f"sat_{src_sat}_ingress"), laser_link_ingress_idx=ingress_id_into_src_sat, clk=dut.clk, l2_frame=l2_frame
        )
    )
    await sink_expected_l2_frame_into_router_core(src_router_core= getattr(dut, f"sat_{src_sat}"), router_core=getattr(dut, f"sat_{dest_sat}"), clk=dut.clk, l3_packet=l3_packet)
