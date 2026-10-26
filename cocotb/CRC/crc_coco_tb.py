import random
import zlib

from cocotb.clock import Clock
from cocotb.triggers import FallingEdge, NextTimeStep, ReadOnly, RisingEdge
from CONSTANTS.constants import L2_MAX_SIZE_BYTES, TEST_CLK_PERIOD_US

import cocotb

# CRC-32/ISO-HDLC: IEEE 802.3 REVERSED POLY: 0xEDB88320


async def reset_dut(dut):
    # reset
    await FallingEdge(dut.clk)
    dut.reset.value = 1
    await RisingEdge(dut.clk)
    await ReadOnly()
    assert dut.crc_output.value == 0xFFFFFFFF, (
        f"Got {hex(dut.crc_output.value)}, expected 0xFFFFFFFF"
    )
    await FallingEdge(dut.clk)
    dut.reset.value = 0


@cocotb.test()
async def crc_random_frame_correctness_test(dut):
    FRAMES_UNDER_TEST = 10
    cocotb.start_soon(Clock(dut.clk, TEST_CLK_PERIOD_US, "us").start())
    await reset_dut(dut)
    dut.enable.value = 1

    # drive randomely generated L2 Frames
    frame = []
    for j in range(0, FRAMES_UNDER_TEST):
        for i in range(0, L2_MAX_SIZE_BYTES - 1):
            byte = random.randint(0, 0xFF)
            dut.message.value = byte
            frame.append(byte)
            await RisingEdge(dut.clk)
            await ReadOnly()
            # dut._log.info(f"DRIVING dut.mesage: {hex(byte)}")
            intermediate_dut_reflected_crc = (
                dut.crc_output.value.to_unsigned() ^ 0xFFFFFFFF
            )
            expected_intermediate_crc_val = zlib.crc32(bytes(frame))
            assert intermediate_dut_reflected_crc == expected_intermediate_crc_val, (
                f"INTERMEDIATE CRC CHECK FAILED: Got {hex(intermediate_dut_reflected_crc)}, expected {hex(expected_intermediate_crc_val)}"
            )
            await NextTimeStep()
        await ReadOnly()
        expected_crc_val = zlib.crc32(bytes(frame))
        dut_reflected_crc = dut.crc_output.value.to_unsigned() ^ 0xFFFFFFFF
        assert dut_reflected_crc == expected_crc_val, (
            f"FINAL FRAME CRC CHECK FAILED: Got {hex(dut_reflected_crc)}, expected {hex(expected_crc_val)}"
        )
        frame = []
        await reset_dut(dut)


@cocotb.test()
async def crc_test_enable_gating(dut):
    cocotb.start_soon(Clock(dut.clk, TEST_CLK_PERIOD_US, "us").start())
    await reset_dut(dut)
    dut.enable.value = 0
    for i in range(0, L2_MAX_SIZE_BYTES - 1):
        byte = random.randint(0, 0xFF)
        dut.message.value = byte
        await RisingEdge(dut.clk)
        await ReadOnly()
        assert dut.crc_output.value == 0xFFFFFFFF, (
            f"Got {hex(dut.crc_output.value)}, expected 0xFFFFFFFF"
        )
        await NextTimeStep()
