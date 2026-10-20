import zlib

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import FallingEdge, NextTimeStep, ReadOnly, ReadWrite, RisingEdge

from CONSTANTS.constants import (
    L2_CRC_SIZE_BYTES,
    L2_PAYLOAD_LENGTH_SIZE_BYTES,
    L2_SOF_VAL,
    L2_TYPE_FLAGS_SIZE_BYTES,
    LINK_ADAPTER_RX_ACQUIRE_LENGTH,
    LINK_ADAPTER_RX_CRC,
    LINK_ADAPTER_RX_DISASSEMBLE,
    LINK_ADAPTER_RX_RECONSTRUCT,
    LINK_ADAPTER_RX_STALL,
    TEST_CLK_PERIOD_US,
)
from UTILS.utils import assert_with_message, generate_l2_frame


async def reset_dut(dut):
    await FallingEdge(dut.clk)
    dut.reset.value = 1
    await RisingEdge(dut.clk)
    await ReadOnly()
    assert_with_message(
        "dut.fifo_ring_write_ptr.value", dut.fifo_ring_write_ptr.value, 0
    )
    assert_with_message("dut.fifo_ring_top_ptr.value", dut.fifo_ring_top_ptr.value, 0)
    assert_with_message("dut.fifo_ring_size.value", dut.fifo_ring_size.value, 0)
    assert_with_message(
        "dut.current_link_adapter_rx_state.value",
        dut.current_link_adapter_rx_state.value,
        LINK_ADAPTER_RX_STALL,
    )
    assert_with_message("dut.received_L3_packet.value", dut.received_L3_packet.value, 0)
    assert_with_message("dut.received_crc.value", dut.received_crc.value, 0)
    assert_with_message("dut.byte_ctr_in.value", dut.byte_ctr_in.value, 0)
    assert_with_message("dut.byte_ctr_crc_in.value", dut.byte_ctr_crc_in.value, 0)
    assert_with_message("dut.push_fifo.value", dut.push_fifo.value, 0)
    assert_with_message(
        "dut.latched_L3_packet_size.value", dut.latched_L3_packet_size.value, 0
    )
    await FallingEdge(dut.clk)
    dut.reset.value = 0


async def send_and_verify_L2_frame(dut, l2_frame):
    offset = 0
    # SOF FRAME
    await ReadWrite()
    dut.ISERDES_in.value = l2_frame[0]
    await ReadOnly()
    assert_with_message("dut.sof_detected.value", dut.sof_detected.value, 1)
    await RisingEdge(dut.clk)
    await ReadOnly()
    assert_with_message(
        "dut.current_link_adapter_rx_state.value",
        dut.current_link_adapter_rx_state.value,
        LINK_ADAPTER_RX_DISASSEMBLE,
    )
    offset += 1

    # TYPE AND FLAGS
    await NextTimeStep()
    for i in range(0, L2_TYPE_FLAGS_SIZE_BYTES):
        await ReadWrite()
        assert_with_message(
            "dut.current_link_adapter_rx_state.value",
            dut.current_link_adapter_rx_state.value,
            LINK_ADAPTER_RX_DISASSEMBLE,
        )
        dut.ISERDES_in.value = l2_frame[offset + i]
        await RisingEdge(dut.clk)
        await ReadWrite()
        assert_with_message("dut.byte_ctr_in.value", dut.byte_ctr_in.value, offset + i)
    offset += L2_TYPE_FLAGS_SIZE_BYTES

    # Payload Length
    await NextTimeStep()
    payload_length = (
        int.from_bytes(
            bytes(l2_frame[offset : offset + L2_PAYLOAD_LENGTH_SIZE_BYTES]),
            byteorder="little",
        ),
    )
    for i in range(0, L2_PAYLOAD_LENGTH_SIZE_BYTES):
        await ReadWrite()
        assert_with_message(
            "dut.current_link_adapter_rx_state.value",
            dut.current_link_adapter_rx_state.value,
            LINK_ADAPTER_RX_ACQUIRE_LENGTH,
        )
        dut.ISERDES_in.value = l2_frame[offset + i]
        await RisingEdge(dut.clk)
        await ReadWrite()
        assert_with_message("dut.byte_ctr_in.value", dut.byte_ctr_in.value, offset + i)
    assert_with_message(
        "dut.latched_L3_packet_size.value",
        dut.latched_L3_packet_size.value,
        payload_length[0],
    )
    offset += L2_PAYLOAD_LENGTH_SIZE_BYTES

    # L3_PACKET_PAYLOAD
    for i in range(0, payload_length[0]):
        await ReadWrite()
        assert_with_message(
            "dut.current_link_adapter_rx_state.value",
            dut.current_link_adapter_rx_state.value,
            LINK_ADAPTER_RX_RECONSTRUCT,
        )
        dut.ISERDES_in.value = l2_frame[offset + i]
        await RisingEdge(dut.clk)
        await ReadWrite()
        assert_with_message("dut.byte_ctr_in.value", dut.byte_ctr_in.value, offset + i)
    l3_packet = int.from_bytes(
        bytes(l2_frame[offset : offset + payload_length[0]]), byteorder="little"
    )
    assert_with_message(
        "dut.received_L3_packet", dut.received_L3_packet.value, l3_packet
    )
    offset += payload_length[0]

    # CRC
    for i in range(0, L2_CRC_SIZE_BYTES):
        await ReadWrite()
        assert_with_message(
            "dut.current_link_adapter_rx_state.value",
            dut.current_link_adapter_rx_state.value,
            LINK_ADAPTER_RX_CRC,
        )
        dut.ISERDES_in.value = l2_frame[offset + i]
        await RisingEdge(dut.clk)
        await ReadWrite()
        assert_with_message(
            "dut.byte_ctr_crc_in.value", dut.byte_ctr_crc_in.value, (i + 1) % 4
        )
    expected_crc = zlib.crc32(bytes(l2_frame[1:])).to_bytes(L2_CRC_SIZE_BYTES, "little")


@cocotb.test
async def single_l2_frame_one_byte_payload(dut):
    cocotb.start_soon(Clock(dut.clk, TEST_CLK_PERIOD_US, "us").start())
    await reset_dut(dut)
    l2_frame = generate_l2_frame(0x0A, 0x0B, 0x05, 1)
    await send_and_verify_L2_frame(dut, l2_frame)
