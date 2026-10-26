from __future__ import annotations

import random

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import FallingEdge, ReadOnly, RisingEdge

from CONSTANTS.constants import (
    L3_PAYLOAD_MAX_SIZE_BYTES,
    LINK_ADAPTER_RX_STALL,
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
    dut.ISERDES_in.value = 0
    dut.s_axis_tready.value = 1

    await RisingEdge(dut.clk)
    await ReadOnly()

    for name in (
        "d1",
        "d2",
        "d3",
        "d4",
        "d5",
        "v1",
        "v2",
        "v3",
        "v4",
        "v5",
        "byte_ctr_crc_in",
        "latched_L3_packet_size",
    ):
        assert_with_message(
            f"dut.{name}",
            getattr(dut, name).value,
            0,
        )
    assert_with_message("dut.valid_crc_flag", dut.valid_crc_flag.value, 1)
    assert_with_message(
        "dut.current_link_adapter_rx_state",
        dut.current_link_adapter_rx_state.value,
        LINK_ADAPTER_RX_STALL,
    )
    assert_with_message("dut.s_axis_tvalid", dut.s_axis_tvalid.value, 0)
    assert_with_message("dut.s_axis_tlast", dut.s_axis_tlast.value, 0)
    assert_with_message("dut.s_axis_tuser", dut.s_axis_tuser.value, 0)

    await FallingEdge(dut.clk)
    dut.reset.value = 0


async def simulated_phy_ISERDES_drive_l2_frame(dut, l2_frame):
    """
    Transmit an L2 frame, one byte per clock cycle.
    """
    for byte in l2_frame:
        await FallingEdge(dut.clk)
        dut.ISERDES_in.value = int(byte) & 0xFF

    await FallingEdge(dut.clk)
    dut.ISERDES_in.value = 0


async def monitor_l3_output(
    dut,
    expected_packet,
    timeout_cycles,
):
    """
    Capture L3 bytes until tlast is asserted.

    Returns:
        (observed_packet, tuser_on_last_byte)
    """
    expected = [int(byte) & 0xFF for byte in expected_packet]
    observed = []

    for _ in range(timeout_cycles):
        await RisingEdge(dut.clk)
        valid = dut.s_axis_tvalid.value
        last = dut.s_axis_tlast.value
        user = dut.s_axis_tuser.value

        if valid:
            observed.append(dut.s_axis_tdata.value.to_unsigned())

            if last:
                assert observed == expected, (
                    f"L3 packet mismatch.\n"
                    f"Expected {len(expected)} bytes: {expected!r}\n"
                    f"Observed {len(observed)} bytes: {observed!r}"
                )

                return user

    raise AssertionError(
        f"Timed out waiting for tlast. "
        f"Received {len(observed)} bytes; expected {len(expected)}."
    )


async def run_single_frame_test(
    dut,
    payload_length=None,
    corrupt_crc=False,
    seed=None,
):
    if seed is not None:
        random.seed(seed)

    _, l3_packet = generate_l3_packet_and_desc_pair(
        l3_packet_payload_length=payload_length
    )

    expected_packet = [int(byte) & 0xFF for byte in l3_packet]

    l2_frame = list(generate_l2_frame(l3_packet=l3_packet))

    if corrupt_crc:
        l2_frame[-1] ^= 0x01

    monitor_task = cocotb.start_soon(
        monitor_l3_output(
            dut=dut,
            expected_packet=expected_packet,
            timeout_cycles=len(l2_frame) + 32,
        )
    )

    await simulated_phy_ISERDES_drive_l2_frame(dut, l2_frame)

    tuser = await monitor_task

    expected_tuser = int(corrupt_crc)
    assert tuser == expected_tuser, (
        f"Expected tuser={expected_tuser}, observed {tuser}. "
        f"CRC corrupted={corrupt_crc}"
    )

    # Allow the RX FSM to return to STALL before the next frame.
    await wait_cycles(dut.clk, 3)


@cocotb.test
async def drive_single_l3_packet_with_one_byte_payload_test(dut):
    cocotb.start_soon(Clock(dut.clk, TEST_CLK_PERIOD_US, unit="us").start())
    await reset_dut(dut)

    await run_single_frame_test(
        dut,
        payload_length=1,
    )


@cocotb.test
async def drive_single_l3_packet_with_max_payload_test(dut):
    cocotb.start_soon(Clock(dut.clk, TEST_CLK_PERIOD_US, unit="us").start())
    await reset_dut(dut)

    await run_single_frame_test(
        dut,
        payload_length=L3_PAYLOAD_MAX_SIZE_BYTES,
    )


@cocotb.test
async def drive_stress_test_l3_packets_with_max_payload_test(dut):
    packet_count = 100

    cocotb.start_soon(Clock(dut.clk, TEST_CLK_PERIOD_US, unit="us").start())
    await reset_dut(dut)

    for _ in range(packet_count):
        await run_single_frame_test(
            dut,
            payload_length=L3_PAYLOAD_MAX_SIZE_BYTES,
        )


@cocotb.test
async def drive_stress_test_l3_packets_with_randomized_payload_test(dut):
    packet_count = 100

    cocotb.start_soon(Clock(dut.clk, TEST_CLK_PERIOD_US, unit="us").start())
    await reset_dut(dut)

    for _ in range(packet_count):
        payload_length = random.randint(
            1,
            L3_PAYLOAD_MAX_SIZE_BYTES,
        )

        await run_single_frame_test(
            dut,
            payload_length=payload_length,
        )


@cocotb.test
async def drive_corrupted_crc_test(dut):
    cocotb.start_soon(Clock(dut.clk, TEST_CLK_PERIOD_US, unit="us").start())
    await reset_dut(dut)

    await run_single_frame_test(
        dut,
        payload_length=32,
        corrupt_crc=True,
    )
