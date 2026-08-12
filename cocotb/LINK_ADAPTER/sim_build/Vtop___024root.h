// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_cov.h"
#include "verilated_covergroup.h"
class Vtop_packets_and_frames;


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final {
  public:
    // CELLS
    Vtop_packets_and_frames* __PVT__packets_and_frames;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(reset,0,0);
        VL_IN8(packet_valid,0,0);
        VL_OUT8(packet_ready,0,0);
        VL_OUT8(OSERDES_out,7,0);
        CData/*0:0*/ link_adapter_tx__DOT__clk;
        CData/*0:0*/ link_adapter_tx__DOT__reset;
        CData/*0:0*/ link_adapter_tx__DOT__packet_valid;
        CData/*0:0*/ link_adapter_tx__DOT__packet_ready;
        CData/*7:0*/ link_adapter_tx__DOT__OSERDES_out;
        CData/*2:0*/ link_adapter_tx__DOT__current_link_adapter_state;
        CData/*2:0*/ link_adapter_tx__DOT__next_link_adapter_state;
        CData/*2:0*/ link_adapter_tx__DOT__fifo_ring_write_ptr;
        CData/*2:0*/ link_adapter_tx__DOT__fifo_ring_top_ptr;
        CData/*3:0*/ link_adapter_tx__DOT__fifo_ring_size;
        CData/*0:0*/ link_adapter_tx__DOT__fifo_full;
        CData/*0:0*/ link_adapter_tx__DOT__fifo_empty;
        CData/*2:0*/ link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr;
        CData/*0:0*/ link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_en;
        CData/*2:0*/ link_adapter_tx__DOT__fifo_ring_buffer_port_b_addr;
        CData/*0:0*/ link_adapter_tx__DOT__fifo_ring_buffer_port_b_w_en;
        CData/*0:0*/ link_adapter_tx__DOT__push_fifo;
        CData/*0:0*/ link_adapter_tx__DOT__pop_fifo;
        CData/*1:0*/ link_adapter_tx__DOT__byte_ctr_crc_shift;
        CData/*7:0*/ link_adapter_tx__DOT__crc_byte_output;
        CData/*7:0*/ link_adapter_tx__DOT__crc_calc_input;
        CData/*0:0*/ link_adapter_tx__DOT__crc_calc_en;
        CData/*0:0*/ link_adapter_tx__DOT__crc_reset;
        CData/*0:0*/ link_adapter_tx__DOT____Vtogcov__clk;
        CData/*0:0*/ link_adapter_tx__DOT____Vtogcov__reset;
        CData/*0:0*/ link_adapter_tx__DOT____Vtogcov__packet_valid;
        CData/*0:0*/ link_adapter_tx__DOT____Vtogcov__packet_ready;
        CData/*7:0*/ link_adapter_tx__DOT____Vtogcov__OSERDES_out;
        CData/*2:0*/ link_adapter_tx__DOT____Vtogcov__current_link_adapter_state;
        CData/*2:0*/ link_adapter_tx__DOT____Vtogcov__next_link_adapter_state;
        CData/*2:0*/ link_adapter_tx__DOT____Vtogcov__fifo_ring_write_ptr;
        CData/*2:0*/ link_adapter_tx__DOT____Vtogcov__fifo_ring_top_ptr;
        CData/*3:0*/ link_adapter_tx__DOT____Vtogcov__fifo_ring_size;
        CData/*0:0*/ link_adapter_tx__DOT____Vtogcov__fifo_full;
        CData/*0:0*/ link_adapter_tx__DOT____Vtogcov__fifo_empty;
        CData/*2:0*/ link_adapter_tx__DOT____Vtogcov__fifo_ring_buffer_port_a_addr;
        CData/*0:0*/ link_adapter_tx__DOT____Vtogcov__fifo_ring_buffer_port_a_rd_en;
        CData/*2:0*/ link_adapter_tx__DOT____Vtogcov__fifo_ring_buffer_port_b_addr;
        CData/*0:0*/ link_adapter_tx__DOT____Vtogcov__fifo_ring_buffer_port_b_w_en;
        CData/*0:0*/ link_adapter_tx__DOT____Vtogcov__push_fifo;
        CData/*0:0*/ link_adapter_tx__DOT____Vtogcov__pop_fifo;
        CData/*1:0*/ link_adapter_tx__DOT____Vtogcov__byte_ctr_crc_shift;
        CData/*7:0*/ link_adapter_tx__DOT____Vtogcov__crc_byte_output;
        CData/*7:0*/ link_adapter_tx__DOT____Vtogcov__crc_calc_input;
        CData/*0:0*/ link_adapter_tx__DOT____Vtogcov__crc_calc_en;
        CData/*0:0*/ link_adapter_tx__DOT____Vtogcov__crc_reset;
        CData/*7:0*/ link_adapter_tx__DOT__CRC_CALC__DOT__message;
        CData/*0:0*/ link_adapter_tx__DOT__CRC_CALC__DOT__reset;
        CData/*0:0*/ link_adapter_tx__DOT__CRC_CALC__DOT__enable;
        CData/*0:0*/ link_adapter_tx__DOT__CRC_CALC__DOT__clk;
        CData/*7:0*/ link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__message;
        CData/*0:0*/ link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__reset;
        CData/*0:0*/ link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__enable;
        CData/*0:0*/ link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__clk;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VstlPhaseResult;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __VicoPhaseResult;
        CData/*0:0*/ __Vtrigprevexpr___TOP__link_adapter_tx__DOT__clk__0;
    };
    struct {
        CData/*0:0*/ __Vtrigprevexpr___TOP__link_adapter_tx__DOT__CRC_CALC__DOT__clk__0;
        CData/*0:0*/ __VactPhaseResult;
        CData/*0:0*/ __VnbaPhaseResult;
        SData/*8:0*/ link_adapter_tx__DOT__byte_ctr_shift;
        SData/*15:0*/ link_adapter_tx__DOT__latched_L3_packet_size;
        SData/*15:0*/ link_adapter_tx__DOT__curr_L3_packet_size;
        SData/*8:0*/ link_adapter_tx__DOT____Vtogcov__byte_ctr_shift;
        SData/*15:0*/ link_adapter_tx__DOT____Vtogcov__latched_L3_packet_size;
        SData/*15:0*/ link_adapter_tx__DOT____Vtogcov__curr_L3_packet_size;
        VL_INW(tx_packet,2047,0,64);
        VlWide<64>/*2047:0*/ link_adapter_tx__DOT__tx_packet;
        VlWide<64>/*2047:0*/ link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data;
        VlWide<64>/*2047:0*/ link_adapter_tx__DOT__fifo_ring_buffer_port_b_w_data;
        VlWide<65>/*2079:0*/ link_adapter_tx__DOT__L2_frame_shift_reg;
        IData/*31:0*/ link_adapter_tx__DOT__crc_calc_output;
        IData/*31:0*/ link_adapter_tx__DOT____Vtogcov__crc_calc_output;
        IData/*31:0*/ link_adapter_tx__DOT__CRC_CALC__DOT__CRC_REG;
        IData/*31:0*/ link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__CRC_REG;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<VlWide<64>/*2047:0*/, 8> link_adapter_tx__DOT__fifo_ring_buffer;
        VlUnpacked<IData/*31:0*/, 256> link_adapter_tx__DOT__CRC_CALC__DOT__PRECOMPUTED_CRC;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    };

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;
    uint32_t __Vcoverage[442]{};

    // PARAMETERS
    static constexpr IData/*31:0*/ link_adapter_tx__DOT__PACKET_COUNT = 8U;
    static constexpr IData/*31:0*/ link_adapter_tx__DOT__CRC_CALC__DOT__POLY = 0xedb88320U;
    static constexpr IData/*31:0*/ link_adapter_tx__DOT__CRC_CALC__DOT__MESSAGE_SLICE_SIZE_BITS = 8U;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* namep);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
    void __vlCoverInsert(uint32_t* countp, bool enable, bool localCounter, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp, const char* linescovp,
        const char* fsmVarp, const char* fsmFromp, const char* fsmTop, const char* fsmTagp);
    void __vlCoverToggleInsert(int begin, int end, bool ranged, uint32_t* countp, bool enable, bool localCounter, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp);
};


#endif  // guard
