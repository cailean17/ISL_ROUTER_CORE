from __future__ import annotations

import random

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import FallingEdge, ReadOnly, ReadWrite, RisingEdge

from CONSTANTS.constants import (
    L3_PAYLOAD_MAX_SIZE_BYTES,
    LINK_ADAPTER_TX_ASSEMBLE,
    LINK_ADAPTER_TX_CRC,
    LINK_ADAPTER_TX_FETCH,
    LINK_ADAPTER_TX_STALL,
    LINK_ADAPTER_TX_TRANSMIT,
    TEST_CLK_PERIOD_US,
)
from UTILS.utils import (
    assert_with_message,
    generate_l2_frame,
    generate_l3_packet_and_desc_pair,
    wait_cycles,
)


async def reset_dut(dut):
    await FallingEdge(dut.clk)
    dut.reset.value = 1
    await RisingEdge(dut.clk)
    await ReadOnly()
    assert_with_message("dut.crc_reset", dut.crc_reset.value, 1)
    assert_with_message(
        "dut.current_link_adapter_state",
        dut.current_link_adapter_state.value,
        LINK_ADAPTER_TX_STALL,
    )
    assert_with_message("dut.byte_ctr_shift", dut.byte_ctr_shift.value, 0)
    assert_with_message("dut.byte_ctr_crc_shift", dut.byte_ctr_crc_shift.value, 0)
    assert_with_message("dut.latched_descriptor", dut.latched_descriptor.value, 0)
    assert_with_message("dut.OSERDES_out", dut.OSERDES_out.value, 0)
    await FallingEdge(dut.clk)
    dut.reset.value = 0


async def simulated_router_drive_l3_packet_descriptor(dut, l3_packet_desc=None):
    await FallingEdge(dut.clk)
    await ReadWrite()
    dut.s_axis_router_cmd_tdata.value = l3_packet_desc
    dut.s_axis_router_cmd_tvalid.value = 1
    while True:
        await RisingEdge(dut.clk)
        if dut.s_axis_router_cmd_tready.value == 1:
            break
    await FallingEdge(dut.clk)
    await ReadWrite()
    dut.s_axis_router_cmd_tvalid.value = 0
    dut.s_axis_router_cmd_tdata.value = 0
    assert_with_message(
        "dut.current_link_adapter_state",
        dut.current_link_adapter_state.value,
        LINK_ADAPTER_TX_FETCH,
    )


async def simulated_l3_buffer_receive_packet_descriptor(dut):
    await wait_cycles(dut.clk, random.randint(0, 100))
    await FallingEdge(dut.clk)
    await ReadWrite()
    dut.m_axis_tx_cmd_tready.value = 1
    while True:
        await RisingEdge(dut.clk)
        if dut.m_axis_tx_cmd_tvalid.value == 1:
            break
    await FallingEdge(dut.clk)
    await ReadWrite()
    dut.m_axis_tx_cmd_tready.value = 0
    assert_with_message(
        "dut.current_link_adapter_state",
        dut.current_link_adapter_state.value,
        LINK_ADAPTER_TX_ASSEMBLE,
    )


async def simulated_l3_buffer_stream_l3_packet(dut, l3_packet):
    bytes_sent = 0
    for byte in l3_packet:
        await FallingEdge(dut.clk)
        await ReadWrite()
        dut.s_axis_tx_tdata.value = byte
        dut.s_axis_tx_tvalid.value = 1
        if bytes_sent == len(l3_packet) - 1:
            dut.s_axis_tx_tlast.value = 1
        while True:
            await RisingEdge(dut.clk)
            if dut.s_axis_tx_tready.value == 1:
                break
        bytes_sent += 1
    await FallingEdge(dut.clk)
    await ReadWrite()
    dut.s_axis_tx_tdata.value = 0
    dut.s_axis_tx_tvalid.value = 0
    dut.s_axis_tx_tlast.value = 0


async def monitor_l2_frame_transmission(dut, l3_packet):
    l2_frame = generate_l2_frame(l3_packet)
    byte_idx = 0
    while byte_idx < len(l2_frame):
        await RisingEdge(dut.clk)
        handshake = dut.s_axis_tx_tvalid.value == 1 and dut.s_axis_tx_tready.value == 1
        if (
            (
                dut.current_link_adapter_state.value == LINK_ADAPTER_TX_ASSEMBLE
                and (
                    dut.next_link_adapter_state.value == LINK_ADAPTER_TX_ASSEMBLE
                    or dut.next_link_adapter_state.value == LINK_ADAPTER_TX_TRANSMIT
                )
            )
            or (
                dut.current_link_adapter_state.value == LINK_ADAPTER_TX_CRC
                and (
                    dut.next_link_adapter_state.value == LINK_ADAPTER_TX_CRC
                    or dut.next_link_adapter_state.value == LINK_ADAPTER_TX_STALL
                )
            )
            or handshake
        ):
            await ReadOnly()
            assert_with_message(
                "dut.OSERDES_out", dut.OSERDES_out.value, l2_frame[byte_idx]
            )
            byte_idx += 1


@cocotb.test
async def drive_single_l3_packet_with_one_byte_payload_test(dut):
    cocotb.start_soon(Clock(dut.clk, TEST_CLK_PERIOD_US, "us").start())
    await reset_dut(dut)
    l3_packet_desc, l3_packet = generate_l3_packet_and_desc_pair(
        l3_packet_payload_length=1
    )
    await simulated_router_drive_l3_packet_descriptor(
        dut=dut, l3_packet_desc=l3_packet_desc
    )
    await simulated_l3_buffer_receive_packet_descriptor(dut=dut)
    cocotb.start_soon(
        simulated_l3_buffer_stream_l3_packet(dut=dut, l3_packet=l3_packet)
    )
    await monitor_l2_frame_transmission(dut=dut, l3_packet=l3_packet)


@cocotb.test
async def drive_single_l3_packet_with_max_payload_test(dut):
    cocotb.start_soon(Clock(dut.clk, TEST_CLK_PERIOD_US, "us").start())
    await reset_dut(dut)
    l3_packet_desc, l3_packet = generate_l3_packet_and_desc_pair(
        l3_packet_payload_length=L3_PAYLOAD_MAX_SIZE_BYTES
    )
    await simulated_router_drive_l3_packet_descriptor(
        dut=dut, l3_packet_desc=l3_packet_desc
    )
    await simulated_l3_buffer_receive_packet_descriptor(dut=dut)
    cocotb.start_soon(
        simulated_l3_buffer_stream_l3_packet(dut=dut, l3_packet=l3_packet)
    )
    await monitor_l2_frame_transmission(dut=dut, l3_packet=l3_packet)


@cocotb.test
async def drive_stress_test_l3_packets_with_max_payload_test(dut):
    PACKET_COUNT = 100
    packet_count = 0
    cocotb.start_soon(Clock(dut.clk, TEST_CLK_PERIOD_US, "us").start())
    await reset_dut(dut)
    while packet_count < PACKET_COUNT:
        l3_packet_desc, l3_packet = generate_l3_packet_and_desc_pair(
            l3_packet_payload_length=L3_PAYLOAD_MAX_SIZE_BYTES
        )
        await simulated_router_drive_l3_packet_descriptor(
            dut=dut, l3_packet_desc=l3_packet_desc
        )
        await simulated_l3_buffer_receive_packet_descriptor(dut=dut)
        cocotb.start_soon(
            simulated_l3_buffer_stream_l3_packet(dut=dut, l3_packet=l3_packet)
        )
        await monitor_l2_frame_transmission(dut=dut, l3_packet=l3_packet)
        packet_count += 1


@cocotb.test
async def drive_stress_test_l3_packets_with_randomized_payload_test(dut):
    PACKET_COUNT = 100
    packet_count = 0
    cocotb.start_soon(Clock(dut.clk, TEST_CLK_PERIOD_US, "us").start())
    await reset_dut(dut)
    while packet_count < PACKET_COUNT:
        l3_packet_desc, l3_packet = generate_l3_packet_and_desc_pair()
        await simulated_router_drive_l3_packet_descriptor(
            dut=dut, l3_packet_desc=l3_packet_desc
        )
        await simulated_l3_buffer_receive_packet_descriptor(dut=dut)
        cocotb.start_soon(
            simulated_l3_buffer_stream_l3_packet(dut=dut, l3_packet=l3_packet)
        )
        await monitor_l2_frame_transmission(dut=dut, l3_packet=l3_packet)
        packet_count += 1
