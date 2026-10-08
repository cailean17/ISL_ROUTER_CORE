from __future__ import annotations

import random
import zlib

import cocotb
from cocotb.clock import Clock
from cocotb.task import Task
from cocotb.triggers import FallingEdge, ReadOnly, ReadWrite, RisingEdge

from CONSTANTS.constants import (
    L2_CRC_SIZE_BYTES,
    L2_PAYLOAD_LENGTH_SIZE_BYTES,
    L2_SOF_VAL,
    L2_TYPE_FLAGS_SIZE_BYTES,
    L3_DEST_SAT_SIZE_BYTES,
    L3_HEADER_SIZE_BYTES,
    L3_PAYLOAD_MAX_SIZE_BYTES,
    L3_SRC_SAT_SIZE_BYTES,
    L3_TTL_SIZE_BYTES,
    LINK_ADAPTER_TX_ASSEMBLE,
    LINK_ADAPTER_TX_CRC_SHIFT,
    LINK_ADAPTER_TX_FETCH,
    LINK_ADAPTER_TX_SHIFT,
    LINK_ADAPTER_TX_STALL,
    TEST_CLK_PERIOD_US,
)
from UTILS.utils import generate_l3_packet


async def reset_dut(dut):
    await FallingEdge(dut.clk)
    dut.reset.value = 1
    await RisingEdge(dut.clk)
    await ReadOnly()
    assert dut.fifo_ring_write_ptr.value == 0, "FIFO RING WRITE POINTER FAILED TO RESET"
    assert dut.fifo_ring_top_ptr.value == 0, "FIFO RING TOP POINTER FAILED TO RESET"
    assert dut.fifo_ring_size.value == 0, "FIFO RING SIZE FAILED TO RESET"
    assert dut.current_link_adapter_state.value == LINK_ADAPTER_TX_STALL, (
        f"FSM FAILED TO RESET, actual: {dut.current_link_adapter_state.value}, expected: STALL:0"
    )
    assert dut.L2_frame_shift_reg.value == 0, "L2_FRAME_SHIFT_REG FAILED TO RESET"
    assert dut.byte_ctr_shift.value == 0, "BYTE_CTR_SHIFT FAILED TO RESET"
    assert dut.byte_ctr_crc_shift.value == 0, "BYTE_CTR_CRC_SHIFT FAILED TO RESET"
    assert dut.pop_fifo.value == 0, "POP_FIFO FAILED TO RESET"
    assert dut.latched_L3_packet_size.value == 0, (
        "LATCHED_L3_PACKET_SIZE FAILED TO RESET"
    )
    assert dut.OSERDES_out.value == 0, "OSERDES_OUT FAILED TO RESET"
    await FallingEdge(dut.clk)
    dut.reset.value = 0


async def send_l3_packet(
    dut, src_sat, dest_sat, ttl, payload_length, seed_byte=0x00, index=0
):
    """**Description:** Drive one L3 packet into the TX link adapter with AXI handshaking\n
    **Returns:** a Tuple of (l3_packet, l3_packet_size, l3_packet_byte_list"""
    l3_packet_byte_list, l3_packet_size = generate_l3_packet(
        src_sat, dest_sat, ttl, payload_length, seed_byte
    )
    l3_packet = int.from_bytes(bytes(l3_packet_byte_list), byteorder="little")
    dut.tx_packet.value = l3_packet
    dut.packet_valid.value = 1
    while True:
        await RisingEdge(dut.clk)
        await ReadWrite()
        if dut.packet_ready.value == 1:
            break
    assert dut.fifo_ring_write_ptr.value == (index + 1) % 8, (
        f"FIFO RING WRITE POINTER: actual: {dut.fifo_ring_write_ptr.value}, expected: 1"
    )
    dut.packet_valid.value = 0
    return (
        l3_packet,
        l3_packet_size,
        l3_packet_byte_list,
    )


async def check_l2_frame(dut, l3_packet, l3_packet_size, l3_packet_byte_list):
    """Verify the full L2 frame (header, payload, CRC) is correctly assembled and shifted out."""

    # Only try STALL->FETCH if we're not already in FETCH (e.g. from the previous
    # frame's CRC_SHIFT -> FETCH transition if ring buffer has pending packets).
    if dut.current_link_adapter_state.value != LINK_ADAPTER_TX_FETCH:
        await RisingEdge(dut.clk)
        await ReadOnly()
        assert dut.current_link_adapter_state.value == LINK_ADAPTER_TX_FETCH, (
            f"CURRENT LINK ADAPTER STATE: actual: {dut.current_link_adapter_state.value}, expected: 1 (FETCH)"
        )

    # FETCH -> ASSEMBLE
    await RisingEdge(dut.clk)
    await ReadOnly()
    assert dut.current_link_adapter_state.value == LINK_ADAPTER_TX_ASSEMBLE, (
        f"CURRENT LINK ADAPTER STATE: actual: {dut.current_link_adapter_state.value}, expected: 2 (ASSEMBLE)"
    )
    assert dut.fifo_ring_buffer_port_a_rd_data.value == l3_packet, (
        f"FIFO RING BUFFER BRAM RD DATA: actual: {hex(dut.fifo_ring_buffer_port_a_rd_data.value)}, "
        f"expected: {hex(l3_packet)}"
    )

    # ASSEMBLE -> SHIFT
    await RisingEdge(dut.clk)
    await ReadOnly()
    l2_frame_without_crc_byte_list = (
        [L2_SOF_VAL]
        + ([0] * L2_TYPE_FLAGS_SIZE_BYTES)
        + list(
            l3_packet_size.to_bytes(L2_PAYLOAD_LENGTH_SIZE_BYTES, byteorder="little")
        )
        + l3_packet_byte_list
    )
    l2_frame_without_crc = int.from_bytes(
        bytes(l2_frame_without_crc_byte_list), byteorder="little"
    )

    assert dut.current_link_adapter_state.value == LINK_ADAPTER_TX_SHIFT, (
        f"CURRENT LINK ADAPTER STATE: actual: {dut.current_link_adapter_state.value}, expected: 3 (SHIFT)"
    )
    assert dut.L2_frame_shift_reg.value == l2_frame_without_crc, (
        f"L2_FRAME_SHIFT_REG: actual: {hex(dut.L2_frame_shift_reg.value)}, "
        f"expected: {hex(l2_frame_without_crc)}"
    )

    # SHIFT LOOP
    for i in range(len(l2_frame_without_crc_byte_list) - 1):
        await RisingEdge(dut.clk)
        await ReadOnly()
        assert dut.current_link_adapter_state.value == LINK_ADAPTER_TX_SHIFT, (
            f"CURRENT LINK ADAPTER STATE: actual: {dut.current_link_adapter_state.value}, expected: 3 (SHIFT)"
        )
        assert dut.byte_ctr_shift.value.to_unsigned() == (i + 1), (
            f"BYTE_CTR_SHIFT, actual: {dut.byte_ctr_shift.value}, expected: {i + 1}"
        )
        assert dut.OSERDES_out.value == l2_frame_without_crc_byte_list[i], (
            f"OSERDES_out: actual: {hex(dut.OSERDES_out.value)}, "
            f"expected: {hex(l2_frame_without_crc_byte_list[i])}"
        )

    # SHIFT -> CRC_SHIFT (last SHIFT byte lands here)
    await RisingEdge(dut.clk)
    await ReadOnly()
    last_shift_byte = l2_frame_without_crc_byte_list[-1]
    assert dut.current_link_adapter_state.value == LINK_ADAPTER_TX_CRC_SHIFT, (
        f"CURRENT LINK ADAPTER STATE: actual: {dut.current_link_adapter_state.value}, expected: 4 (CRC_SHIFT)"
    )
    assert dut.OSERDES_out.value == last_shift_byte, (
        f"OSERDES_out: actual: {hex(dut.OSERDES_out.value)}, expected: {hex(last_shift_byte)}"
    )

    # CRC_SHIFT LOOP (DUT excludes SOF byte from CRC calculation)
    expected_crc = zlib.crc32(bytes(l2_frame_without_crc_byte_list[1:])).to_bytes(
        L2_CRC_SIZE_BYTES, "little"
    )
    for i in range(L2_CRC_SIZE_BYTES - 1):
        await RisingEdge(dut.clk)
        await ReadOnly()
        assert dut.current_link_adapter_state.value == LINK_ADAPTER_TX_CRC_SHIFT, (
            f"CURRENT LINK ADAPTER STATE: actual: {dut.current_link_adapter_state.value}, expected: 4 (CRC_SHIFT)"
        )
        assert dut.byte_ctr_crc_shift.value.to_unsigned() == (i + 1), (
            f"BYTE_CTR_CRC_SHIFT, actual: {dut.byte_ctr_crc_shift.value}, expected: {i + 1}"
        )
        assert dut.OSERDES_out.value == expected_crc[i], (
            f"OSERDES_out: actual: {hex(dut.OSERDES_out.value)}, expected: {hex(expected_crc[i])}"
        )

    # CRC_SHIFT -> STALL (last CRC byte lands here) or CRC_SHIFT -> FETCH (if ring buffer is not empty)
    await RisingEdge(dut.clk)
    await ReadOnly()
    if dut.fifo_ring_size.value:
        assert dut.current_link_adapter_state.value == LINK_ADAPTER_TX_FETCH, (
            f"CURRENT LINK ADAPTER STATE: actual: {dut.current_link_adapter_state.value}, expected: 1 (FETCH)"
        )
    else:
        assert dut.current_link_adapter_state.value == LINK_ADAPTER_TX_STALL, (
            f"CURRENT LINK ADAPTER STATE: actual: {dut.current_link_adapter_state.value}, expected: 0 (STALL)"
        )
    assert dut.OSERDES_out.value == expected_crc[-1], (
        f"OSERDES_out: actual: {hex(dut.OSERDES_out.value)}, expected: {hex(expected_crc[-1])}"
    )


@cocotb.test
async def drive_single_l3_packet_with_one_byte_payload_test(dut):
    cocotb.start_soon(Clock(dut.clk, TEST_CLK_PERIOD_US, "us").start())
    await reset_dut(dut)
    l3_packet, l3_packet_size, l3_packet_byte_list = await send_l3_packet(
        dut, src_sat=0x0A, dest_sat=0x0B, ttl=5, payload_length=1, seed_byte=0xBB
    )
    await check_l2_frame(dut, l3_packet, l3_packet_size, l3_packet_byte_list)


@cocotb.test
async def drive_single_l3_packet_with_max_payload_test(dut):
    cocotb.start_soon(Clock(dut.clk, TEST_CLK_PERIOD_US, "us").start())
    await reset_dut(dut)
    l3_packet, l3_packet_size, l3_packet_byte_list = await send_l3_packet(
        dut, src_sat=0x0A, dest_sat=0x0B, ttl=5, payload_length=250, seed_byte=0x00
    )
    await check_l2_frame(dut, l3_packet, l3_packet_size, l3_packet_byte_list)


@cocotb.test
async def drive_single_l3_packet_with_random_payload_test(dut):
    cocotb.start_soon(Clock(dut.clk, TEST_CLK_PERIOD_US, "us").start())
    await reset_dut(dut)
    l3_packet, l3_packet_size, l3_packet_byte_list = await send_l3_packet(
        dut,
        src_sat=0x0A,
        dest_sat=0x0B,
        ttl=5,
        payload_length=random.randint(0, L3_PAYLOAD_MAX_SIZE_BYTES),
        seed_byte=random.randint(0, 0xFF),
    )
    await check_l2_frame(dut, l3_packet, l3_packet_size, l3_packet_byte_list)


@cocotb.test
async def drive_ring_buffer_to_hold_max_l3_packets_with_random_payload_test(dut):
    cocotb.start_soon(Clock(dut.clk, TEST_CLK_PERIOD_US, "us").start())
    await reset_dut(dut)
    packets_sent = []

    async def check_all_frames_in_order():
        for i, (l3_packet, l3_packet_size, l3_packet_byte_list) in enumerate(
            packets_sent
        ):
            await check_l2_frame(dut, l3_packet, l3_packet_size, l3_packet_byte_list)

    frame_checks_in_flight: Task | None = None
    for i in range(0, 9):
        packets_sent.append(
            await send_l3_packet(
                dut,
                src_sat=0x0A,
                dest_sat=0x0B,
                ttl=5,
                payload_length=random.randint(0, L3_PAYLOAD_MAX_SIZE_BYTES),
                seed_byte=random.randint(0, 0xFF),
                index=i,
            )
        )
        if frame_checks_in_flight == None:
            frame_checks_in_flight = cocotb.start_soon(check_all_frames_in_order())
    await frame_checks_in_flight
