// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup top module instance
    , TOP{this, namep}
{
    // Check resources
    Verilated::stackCheck(2411);
    // Setup sub module instances
    TOP__packets_and_frames.ctor(this, "packets_and_frames");
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__packets_and_frames = &TOP__packets_and_frames;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__packets_and_frames.__Vconfigure(true);
    // Setup scopes
    __Vscopep_TOP = new VerilatedScope{this, "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER};
    __Vscopep_link_adapter_tx = new VerilatedScope{this, "link_adapter_tx", "link_adapter_tx", "link_adapter_tx", -9, VerilatedScope::SCOPE_MODULE};
    __Vscopep_link_adapter_tx__CRC_CALC = new VerilatedScope{this, "link_adapter_tx.CRC_CALC", "CRC_CALC", "CRC", -9, VerilatedScope::SCOPE_MODULE};
    __Vscopep_packets_and_frames = new VerilatedScope{this, "packets_and_frames", "packets_and_frames", "packets_and_frames", -9, VerilatedScope::SCOPE_PACKAGE};
    // Set up scope hierarchy
    __Vhier.add(0, __Vscopep_link_adapter_tx);
    __Vhier.add(0, __Vscopep_packets_and_frames);
    __Vhier.add(__Vscopep_link_adapter_tx, __Vscopep_link_adapter_tx__CRC_CALC);
    // Setup export functions - final: 0
    // Setup export functions - final: 1
    // Setup public variables
    __Vscopep_TOP->varInsert("OSERDES_out", &(TOP.OSERDES_out), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_TOP->varInsert("clk", &(TOP.clk), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW|VLVF_NET, 0, 0);
    __Vscopep_TOP->varInsert("packet_ready", &(TOP.packet_ready), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_TOP->varInsert("packet_valid", &(TOP.packet_valid), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW|VLVF_NET, 0, 0);
    __Vscopep_TOP->varInsert("reset", &(TOP.reset), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW|VLVF_NET, 0, 0);
    __Vscopep_TOP->varInsert("tx_packet", &(TOP.tx_packet), false, VLVT_WDATA, VLVD_IN|VLVF_PUB_RW|VLVF_NET, 0, 1 ,2047,0);
    __Vscopep_link_adapter_tx->varInsert("L2_frame_shift_reg", &(TOP.link_adapter_tx__DOT__L2_frame_shift_reg), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2079,0);
    __Vscopep_link_adapter_tx->varInsert("OSERDES_out", &(TOP.link_adapter_tx__DOT__OSERDES_out), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_link_adapter_tx->varInsert("PACKET_COUNT", const_cast<void*>(static_cast<const void*>(&(TOP.link_adapter_tx__DOT__PACKET_COUNT))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_link_adapter_tx->varInsert("byte_ctr_crc_shift", &(TOP.link_adapter_tx__DOT__byte_ctr_crc_shift), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_link_adapter_tx->varInsert("byte_ctr_shift", &(TOP.link_adapter_tx__DOT__byte_ctr_shift), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,8,0);
    __Vscopep_link_adapter_tx->varInsert("clk", &(TOP.link_adapter_tx__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_NET, 0, 0);
    __Vscopep_link_adapter_tx->varInsert("crc_byte_output", &(TOP.link_adapter_tx__DOT__crc_byte_output), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_link_adapter_tx->varInsert("crc_calc_en", &(TOP.link_adapter_tx__DOT__crc_calc_en), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_link_adapter_tx->varInsert("crc_calc_input", &(TOP.link_adapter_tx__DOT__crc_calc_input), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY|VLVF_NET, 0, 1 ,7,0);
    __Vscopep_link_adapter_tx->varInsert("crc_calc_output", &(TOP.link_adapter_tx__DOT__crc_calc_output), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_link_adapter_tx->varInsert("crc_reset", &(TOP.link_adapter_tx__DOT__crc_reset), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY|VLVF_NET, 0, 0);
    __Vscopep_link_adapter_tx->varInsert("curr_L3_packet_size", &(TOP.link_adapter_tx__DOT__curr_L3_packet_size), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_link_adapter_tx->varInsert("current_link_adapter_state", &(TOP.link_adapter_tx__DOT__current_link_adapter_state), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_link_adapter_tx->varInsert("fifo_empty", &(TOP.link_adapter_tx__DOT__fifo_empty), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY|VLVF_NET, 0, 0);
    __Vscopep_link_adapter_tx->varInsert("fifo_full", &(TOP.link_adapter_tx__DOT__fifo_full), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY|VLVF_NET, 0, 0);
    __Vscopep_link_adapter_tx->varInsert("fifo_ring_buffer", &(TOP.link_adapter_tx__DOT__fifo_ring_buffer), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW, 1, 1 ,0,7 ,2047,0);
    __Vscopep_link_adapter_tx->varInsert("fifo_ring_buffer_port_a_addr", &(TOP.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_link_adapter_tx->varInsert("fifo_ring_buffer_port_a_rd_data", &(TOP.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2047,0);
    __Vscopep_link_adapter_tx->varInsert("fifo_ring_buffer_port_a_rd_en", &(TOP.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_en), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_link_adapter_tx->varInsert("fifo_ring_buffer_port_b_addr", &(TOP.link_adapter_tx__DOT__fifo_ring_buffer_port_b_addr), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_link_adapter_tx->varInsert("fifo_ring_buffer_port_b_w_data", &(TOP.link_adapter_tx__DOT__fifo_ring_buffer_port_b_w_data), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2047,0);
    __Vscopep_link_adapter_tx->varInsert("fifo_ring_buffer_port_b_w_en", &(TOP.link_adapter_tx__DOT__fifo_ring_buffer_port_b_w_en), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_link_adapter_tx->varInsert("fifo_ring_size", &(TOP.link_adapter_tx__DOT__fifo_ring_size), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_link_adapter_tx->varInsert("fifo_ring_top_ptr", &(TOP.link_adapter_tx__DOT__fifo_ring_top_ptr), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_link_adapter_tx->varInsert("fifo_ring_write_ptr", &(TOP.link_adapter_tx__DOT__fifo_ring_write_ptr), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_link_adapter_tx->varInsert("latched_L3_packet_size", &(TOP.link_adapter_tx__DOT__latched_L3_packet_size), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_link_adapter_tx->varInsert("next_link_adapter_state", &(TOP.link_adapter_tx__DOT__next_link_adapter_state), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_link_adapter_tx->varInsert("packet_ready", &(TOP.link_adapter_tx__DOT__packet_ready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_link_adapter_tx->varInsert("packet_valid", &(TOP.link_adapter_tx__DOT__packet_valid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_NET, 0, 0);
    __Vscopep_link_adapter_tx->varInsert("pop_fifo", &(TOP.link_adapter_tx__DOT__pop_fifo), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY|VLVF_NET, 0, 0);
    __Vscopep_link_adapter_tx->varInsert("push_fifo", &(TOP.link_adapter_tx__DOT__push_fifo), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY|VLVF_NET, 0, 0);
    __Vscopep_link_adapter_tx->varInsert("reset", &(TOP.link_adapter_tx__DOT__reset), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_NET, 0, 0);
    __Vscopep_link_adapter_tx->varInsert("tx_packet", &(TOP.link_adapter_tx__DOT__tx_packet), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW|VLVF_NET, 0, 1 ,2047,0);
    __Vscopep_link_adapter_tx__CRC_CALC->varInsert("CRC_REG", &(TOP.link_adapter_tx__DOT__CRC_CALC__DOT__CRC_REG), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_link_adapter_tx__CRC_CALC->varInsert("MESSAGE_SLICE_SIZE_BITS", const_cast<void*>(static_cast<const void*>(&(TOP.link_adapter_tx__DOT__CRC_CALC__DOT__MESSAGE_SLICE_SIZE_BITS))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_link_adapter_tx__CRC_CALC->varInsert("POLY", const_cast<void*>(static_cast<const void*>(&(TOP.link_adapter_tx__DOT__CRC_CALC__DOT__POLY))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_link_adapter_tx__CRC_CALC->varInsert("PRECOMPUTED_CRC", &(TOP.link_adapter_tx__DOT__CRC_CALC__DOT__PRECOMPUTED_CRC), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 1, 1 ,0,255 ,31,0);
    __Vscopep_link_adapter_tx__CRC_CALC->varInsert("clk", &(TOP.link_adapter_tx__DOT__CRC_CALC__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_link_adapter_tx__CRC_CALC->varInsert("enable", &(TOP.link_adapter_tx__DOT__CRC_CALC__DOT__enable), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_link_adapter_tx__CRC_CALC->varInsert("message", &(TOP.link_adapter_tx__DOT__CRC_CALC__DOT__message), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_link_adapter_tx__CRC_CALC->varInsert("reset", &(TOP.link_adapter_tx__DOT__CRC_CALC__DOT__reset), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_packets_and_frames->varInsert("L2_CRC_SIZE_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP__packets_and_frames.L2_CRC_SIZE_BYTES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_packets_and_frames->varInsert("L2_FLAGS_LSB", const_cast<void*>(static_cast<const void*>(&(TOP__packets_and_frames.L2_FLAGS_LSB))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_packets_and_frames->varInsert("L2_FLAGS_MSB", const_cast<void*>(static_cast<const void*>(&(TOP__packets_and_frames.L2_FLAGS_MSB))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_packets_and_frames->varInsert("L2_L3_PACKET_LSB", const_cast<void*>(static_cast<const void*>(&(TOP__packets_and_frames.L2_L3_PACKET_LSB))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_packets_and_frames->varInsert("L2_MAX_SIZE_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP__packets_and_frames.L2_MAX_SIZE_BYTES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_packets_and_frames->varInsert("L2_PAYLOAD_LENGTH_LSB", const_cast<void*>(static_cast<const void*>(&(TOP__packets_and_frames.L2_PAYLOAD_LENGTH_LSB))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_packets_and_frames->varInsert("L2_PAYLOAD_LENGTH_MSB", const_cast<void*>(static_cast<const void*>(&(TOP__packets_and_frames.L2_PAYLOAD_LENGTH_MSB))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_packets_and_frames->varInsert("L2_PAYLOAD_LENGTH_SIZE_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP__packets_and_frames.L2_PAYLOAD_LENGTH_SIZE_BYTES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_packets_and_frames->varInsert("L2_SOF_LSB", const_cast<void*>(static_cast<const void*>(&(TOP__packets_and_frames.L2_SOF_LSB))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_packets_and_frames->varInsert("L2_SOF_MSB", const_cast<void*>(static_cast<const void*>(&(TOP__packets_and_frames.L2_SOF_MSB))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_packets_and_frames->varInsert("L2_SOF_SIZE_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP__packets_and_frames.L2_SOF_SIZE_BYTES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_packets_and_frames->varInsert("L2_SOF_VAL", const_cast<void*>(static_cast<const void*>(&(TOP__packets_and_frames.L2_SOF_VAL))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_packets_and_frames->varInsert("L2_TYPE_FLAGS_SIZE_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP__packets_and_frames.L2_TYPE_FLAGS_SIZE_BYTES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_packets_and_frames->varInsert("L2_TYPE_LSB", const_cast<void*>(static_cast<const void*>(&(TOP__packets_and_frames.L2_TYPE_LSB))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_packets_and_frames->varInsert("L2_TYPE_MSB", const_cast<void*>(static_cast<const void*>(&(TOP__packets_and_frames.L2_TYPE_MSB))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_packets_and_frames->varInsert("L3_DEST_SAT_LSB", const_cast<void*>(static_cast<const void*>(&(TOP__packets_and_frames.L3_DEST_SAT_LSB))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_packets_and_frames->varInsert("L3_DEST_SAT_MSB", const_cast<void*>(static_cast<const void*>(&(TOP__packets_and_frames.L3_DEST_SAT_MSB))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_packets_and_frames->varInsert("L3_DEST_SAT_SIZE_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP__packets_and_frames.L3_DEST_SAT_SIZE_BYTES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_packets_and_frames->varInsert("L3_HEADER_SIZE_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP__packets_and_frames.L3_HEADER_SIZE_BYTES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_packets_and_frames->varInsert("L3_MAX_SIZE_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP__packets_and_frames.L3_MAX_SIZE_BYTES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_packets_and_frames->varInsert("L3_PAYLOAD_LENGTH_LSB", const_cast<void*>(static_cast<const void*>(&(TOP__packets_and_frames.L3_PAYLOAD_LENGTH_LSB))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_packets_and_frames->varInsert("L3_PAYLOAD_LENGTH_MSB", const_cast<void*>(static_cast<const void*>(&(TOP__packets_and_frames.L3_PAYLOAD_LENGTH_MSB))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_packets_and_frames->varInsert("L3_PAYLOAD_LENGTH_SIZE_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP__packets_and_frames.L3_PAYLOAD_LENGTH_SIZE_BYTES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_packets_and_frames->varInsert("L3_PAYLOAD_LSB", const_cast<void*>(static_cast<const void*>(&(TOP__packets_and_frames.L3_PAYLOAD_LSB))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_packets_and_frames->varInsert("L3_PAYLOAD_MAX_SIZE_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP__packets_and_frames.L3_PAYLOAD_MAX_SIZE_BYTES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_packets_and_frames->varInsert("L3_RESERVED_LENGTH_SIZE_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP__packets_and_frames.L3_RESERVED_LENGTH_SIZE_BYTES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_packets_and_frames->varInsert("L3_SRC_SAT_LSB", const_cast<void*>(static_cast<const void*>(&(TOP__packets_and_frames.L3_SRC_SAT_LSB))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_packets_and_frames->varInsert("L3_SRC_SAT_MSB", const_cast<void*>(static_cast<const void*>(&(TOP__packets_and_frames.L3_SRC_SAT_MSB))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_packets_and_frames->varInsert("L3_SRC_SAT_SIZE_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP__packets_and_frames.L3_SRC_SAT_SIZE_BYTES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_packets_and_frames->varInsert("L3_TTL_LSB", const_cast<void*>(static_cast<const void*>(&(TOP__packets_and_frames.L3_TTL_LSB))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_packets_and_frames->varInsert("L3_TTL_MSB", const_cast<void*>(static_cast<const void*>(&(TOP__packets_and_frames.L3_TTL_MSB))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_packets_and_frames->varInsert("L3_TTL_SIZE_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP__packets_and_frames.L3_TTL_SIZE_BYTES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
}

Vtop__Syms::~Vtop__Syms() {
    // Tear down scope hierarchy
    __Vhier.remove(0, __Vscopep_link_adapter_tx);
    __Vhier.remove(0, __Vscopep_packets_and_frames);
    __Vhier.remove(__Vscopep_link_adapter_tx, __Vscopep_link_adapter_tx__CRC_CALC);
    // Clear keys from hierarchy map after values have been removed
    __Vhier.clear();
    // Tear down scopes
    VL_DO_CLEAR(delete __Vscopep_TOP, __Vscopep_TOP = nullptr);
    VL_DO_CLEAR(delete __Vscopep_link_adapter_tx, __Vscopep_link_adapter_tx = nullptr);
    VL_DO_CLEAR(delete __Vscopep_link_adapter_tx__CRC_CALC, __Vscopep_link_adapter_tx__CRC_CALC = nullptr);
    VL_DO_CLEAR(delete __Vscopep_packets_and_frames, __Vscopep_packets_and_frames = nullptr);
    // Tear down sub module instances
    TOP__packets_and_frames.dtor();
}
