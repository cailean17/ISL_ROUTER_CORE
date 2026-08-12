// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__ico\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_0;
    __VdfgRegularize_h6e95ff9d_0_0 = 0;
    IData/*31:0*/ __Vilp1;
    IData/*31:0*/ __Vilp2;
    // Body
    if ((0U != ((IData)(vlSelfRef.link_adapter_tx__DOT__OSERDES_out) 
                ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__OSERDES_out)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 8, vlSelfRef.link_adapter_tx__DOT__OSERDES_out, vlSelfRef.link_adapter_tx__DOT____Vtogcov__OSERDES_out);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__OSERDES_out 
            = vlSelfRef.link_adapter_tx__DOT__OSERDES_out;
    }
    if ((0U != ((IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state) 
                ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__current_link_adapter_state)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 24, vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state, vlSelfRef.link_adapter_tx__DOT____Vtogcov__current_link_adapter_state);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__current_link_adapter_state 
            = vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state;
    }
    if ((0U != ((IData)(vlSelfRef.link_adapter_tx__DOT__fifo_ring_write_ptr) 
                ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_write_ptr)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 36, vlSelfRef.link_adapter_tx__DOT__fifo_ring_write_ptr, vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_write_ptr);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_write_ptr 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_write_ptr;
    }
    if ((0U != ((IData)(vlSelfRef.link_adapter_tx__DOT__fifo_ring_top_ptr) 
                ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_top_ptr)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 42, vlSelfRef.link_adapter_tx__DOT__fifo_ring_top_ptr, vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_top_ptr);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_top_ptr 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_top_ptr;
    }
    if ((0U != ((IData)(vlSelfRef.link_adapter_tx__DOT__fifo_ring_size) 
                ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_size)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 48, vlSelfRef.link_adapter_tx__DOT__fifo_ring_size, vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_size);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_size 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_size;
    }
    if ((0U != ((IData)(vlSelfRef.link_adapter_tx__DOT__byte_ctr_shift) 
                ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__byte_ctr_shift)))) {
        VL_COV_TOGGLE_CHG_ST_I(9, vlSelf->__Vcoverage + 112, vlSelfRef.link_adapter_tx__DOT__byte_ctr_shift, vlSelfRef.link_adapter_tx__DOT____Vtogcov__byte_ctr_shift);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__byte_ctr_shift 
            = vlSelfRef.link_adapter_tx__DOT__byte_ctr_shift;
    }
    if ((0U != ((IData)(vlSelfRef.link_adapter_tx__DOT__byte_ctr_crc_shift) 
                ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__byte_ctr_crc_shift)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 130, vlSelfRef.link_adapter_tx__DOT__byte_ctr_crc_shift, vlSelfRef.link_adapter_tx__DOT____Vtogcov__byte_ctr_crc_shift);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__byte_ctr_crc_shift 
            = vlSelfRef.link_adapter_tx__DOT__byte_ctr_crc_shift;
    }
    if ((0U != ((IData)(vlSelfRef.link_adapter_tx__DOT__latched_L3_packet_size) 
                ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__latched_L3_packet_size)))) {
        VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 134, vlSelfRef.link_adapter_tx__DOT__latched_L3_packet_size, vlSelfRef.link_adapter_tx__DOT____Vtogcov__latched_L3_packet_size);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__latched_L3_packet_size 
            = vlSelfRef.link_adapter_tx__DOT__latched_L3_packet_size;
    }
    if ((0U != (vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__CRC_REG 
                ^ vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__CRC_REG))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 363, vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__CRC_REG, vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__CRC_REG);
        vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__CRC_REG 
            = vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__CRC_REG;
    }
    vlSelfRef.OSERDES_out = vlSelfRef.link_adapter_tx__DOT__OSERDES_out;
    vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_en 
        = (1U == (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state));
    vlSelfRef.link_adapter_tx__DOT__pop_fifo = (2U 
                                                == (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state));
    __Vilp1 = 0U;
    while ((__Vilp1 <= 0x0000003fU)) {
        vlSelfRef.link_adapter_tx__DOT__tx_packet[__Vilp1] 
            = vlSelfRef.tx_packet[__Vilp1];
        __Vilp1 = ((IData)(1U) + __Vilp1);
    }
    vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_b_addr 
        = vlSelfRef.link_adapter_tx__DOT__fifo_ring_write_ptr;
    vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr 
        = vlSelfRef.link_adapter_tx__DOT__fifo_ring_top_ptr;
    vlSelfRef.link_adapter_tx__DOT__clk = vlSelfRef.clk;
    vlSelfRef.link_adapter_tx__DOT__crc_calc_input 
        = (0x000000ffU & vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[0U]);
    vlSelfRef.link_adapter_tx__DOT__crc_calc_output 
        = vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__CRC_REG;
    vlSelfRef.link_adapter_tx__DOT__fifo_empty = (0U 
                                                  == (IData)(vlSelfRef.link_adapter_tx__DOT__fifo_ring_size));
    vlSelfRef.link_adapter_tx__DOT__curr_L3_packet_size = 0U;
    vlSelfRef.link_adapter_tx__DOT__crc_calc_en = 0U;
    if ((3U == (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state))) {
        vlSelfRef.link_adapter_tx__DOT__curr_L3_packet_size = 0U;
        vlSelfRef.link_adapter_tx__DOT__crc_calc_en 
            = (1U <= (IData)(vlSelfRef.link_adapter_tx__DOT__byte_ctr_shift));
        ++(vlSelf->__Vcoverage[321]);
    } else if ((2U == (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state))) {
        vlSelfRef.link_adapter_tx__DOT__curr_L3_packet_size 
            = (0x0000ffffU & ((IData)(6U) + ((vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[1U] 
                                              << 8U) 
                                             | (vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[0U] 
                                                >> 0x00000018U))));
        vlSelfRef.link_adapter_tx__DOT__crc_calc_en = 0U;
        ++(vlSelf->__Vcoverage[322]);
    } else {
        vlSelfRef.link_adapter_tx__DOT__curr_L3_packet_size = 0U;
        vlSelfRef.link_adapter_tx__DOT__crc_calc_en = 0U;
        ++(vlSelf->__Vcoverage[323]);
    }
    ++(vlSelf->__Vcoverage[324]);
    vlSelfRef.link_adapter_tx__DOT__packet_valid = vlSelfRef.packet_valid;
    vlSelfRef.link_adapter_tx__DOT__fifo_full = (8U 
                                                 == (IData)(vlSelfRef.link_adapter_tx__DOT__fifo_ring_size));
    vlSelfRef.link_adapter_tx__DOT__reset = vlSelfRef.reset;
    if (((IData)(vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_en) 
         ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_buffer_port_a_rd_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 69, vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_en, vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_buffer_port_a_rd_en);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_buffer_port_a_rd_en 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_en;
    }
    if (((IData)(vlSelfRef.link_adapter_tx__DOT__pop_fifo) 
         ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__pop_fifo))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 94, vlSelfRef.link_adapter_tx__DOT__pop_fifo, vlSelfRef.link_adapter_tx__DOT____Vtogcov__pop_fifo);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__pop_fifo 
            = vlSelfRef.link_adapter_tx__DOT__pop_fifo;
    }
    __Vilp2 = 0U;
    while ((__Vilp2 <= 0x0000003fU)) {
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_b_w_data[__Vilp2] 
            = vlSelfRef.link_adapter_tx__DOT__tx_packet
            [__Vilp2];
        __Vilp2 = ((IData)(1U) + __Vilp2);
    }
    if ((0U != ((IData)(vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_b_addr) 
                ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_buffer_port_b_addr)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 74, vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_b_addr, vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_buffer_port_b_addr);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_buffer_port_b_addr 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_b_addr;
    }
    if ((0U != ((IData)(vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr) 
                ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_buffer_port_a_addr)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 63, vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr, vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_buffer_port_a_addr);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_buffer_port_a_addr 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr;
    }
    if (((IData)(vlSelfRef.link_adapter_tx__DOT__clk) 
         ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__clk))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 0, vlSelfRef.link_adapter_tx__DOT__clk, vlSelfRef.link_adapter_tx__DOT____Vtogcov__clk);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__clk 
            = vlSelfRef.link_adapter_tx__DOT__clk;
    }
    vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__clk 
        = vlSelfRef.link_adapter_tx__DOT__clk;
    if ((0U != ((IData)(vlSelfRef.link_adapter_tx__DOT__crc_calc_input) 
                ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__crc_calc_input)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 278, vlSelfRef.link_adapter_tx__DOT__crc_calc_input, vlSelfRef.link_adapter_tx__DOT____Vtogcov__crc_calc_input);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__crc_calc_input 
            = vlSelfRef.link_adapter_tx__DOT__crc_calc_input;
    }
    vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__message 
        = vlSelfRef.link_adapter_tx__DOT__crc_calc_input;
    if ((0U != (vlSelfRef.link_adapter_tx__DOT__crc_calc_output 
                ^ vlSelfRef.link_adapter_tx__DOT____Vtogcov__crc_calc_output))) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 198, vlSelfRef.link_adapter_tx__DOT__crc_calc_output, vlSelfRef.link_adapter_tx__DOT____Vtogcov__crc_calc_output);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__crc_calc_output 
            = vlSelfRef.link_adapter_tx__DOT__crc_calc_output;
    }
    if ((2U & (IData)(vlSelfRef.link_adapter_tx__DOT__byte_ctr_crc_shift))) {
        if ((1U & (IData)(vlSelfRef.link_adapter_tx__DOT__byte_ctr_crc_shift))) {
            vlSelfRef.link_adapter_tx__DOT__crc_byte_output 
                = (0x000000ffU & (~ (vlSelfRef.link_adapter_tx__DOT__crc_calc_output 
                                     >> 0x18U)));
            ++(vlSelf->__Vcoverage[331]);
        } else {
            vlSelfRef.link_adapter_tx__DOT__crc_byte_output 
                = (0x000000ffU & (~ (vlSelfRef.link_adapter_tx__DOT__crc_calc_output 
                                     >> 0x10U)));
            ++(vlSelf->__Vcoverage[330]);
        }
    } else if ((1U & (IData)(vlSelfRef.link_adapter_tx__DOT__byte_ctr_crc_shift))) {
        vlSelfRef.link_adapter_tx__DOT__crc_byte_output 
            = (0x000000ffU & (~ (vlSelfRef.link_adapter_tx__DOT__crc_calc_output 
                                 >> 8U)));
        ++(vlSelf->__Vcoverage[329]);
    } else {
        vlSelfRef.link_adapter_tx__DOT__crc_byte_output 
            = (0x000000ffU & (~ vlSelfRef.link_adapter_tx__DOT__crc_calc_output));
        ++(vlSelf->__Vcoverage[328]);
    }
    ++(vlSelf->__Vcoverage[333]);
    if (((IData)(vlSelfRef.link_adapter_tx__DOT__fifo_empty) 
         ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_empty))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 58, vlSelfRef.link_adapter_tx__DOT__fifo_empty, vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_empty);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_empty 
            = vlSelfRef.link_adapter_tx__DOT__fifo_empty;
    }
    if ((0U != ((IData)(vlSelfRef.link_adapter_tx__DOT__curr_L3_packet_size) 
                ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__curr_L3_packet_size)))) {
        VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 166, vlSelfRef.link_adapter_tx__DOT__curr_L3_packet_size, vlSelfRef.link_adapter_tx__DOT____Vtogcov__curr_L3_packet_size);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__curr_L3_packet_size 
            = vlSelfRef.link_adapter_tx__DOT__curr_L3_packet_size;
    }
    if (((IData)(vlSelfRef.link_adapter_tx__DOT__crc_calc_en) 
         ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__crc_calc_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 294, vlSelfRef.link_adapter_tx__DOT__crc_calc_en, vlSelfRef.link_adapter_tx__DOT____Vtogcov__crc_calc_en);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__crc_calc_en 
            = vlSelfRef.link_adapter_tx__DOT__crc_calc_en;
    }
    vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__enable 
        = vlSelfRef.link_adapter_tx__DOT__crc_calc_en;
    if (((IData)(vlSelfRef.link_adapter_tx__DOT__packet_valid) 
         ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__packet_valid))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 4, vlSelfRef.link_adapter_tx__DOT__packet_valid, vlSelfRef.link_adapter_tx__DOT____Vtogcov__packet_valid);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__packet_valid 
            = vlSelfRef.link_adapter_tx__DOT__packet_valid;
    }
    if (((IData)(vlSelfRef.link_adapter_tx__DOT__fifo_full) 
         ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_full))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 56, vlSelfRef.link_adapter_tx__DOT__fifo_full, vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_full);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_full 
            = vlSelfRef.link_adapter_tx__DOT__fifo_full;
    }
    if ((1U & ((~ (IData)(vlSelfRef.link_adapter_tx__DOT__fifo_full)) 
               & (~ (IData)(vlSelfRef.link_adapter_tx__DOT__reset))))) {
        ++(vlSelf->__Vcoverage[60]);
    }
    if (vlSelfRef.link_adapter_tx__DOT__reset) {
        ++(vlSelf->__Vcoverage[61]);
    }
    if (vlSelfRef.link_adapter_tx__DOT__fifo_full) {
        ++(vlSelf->__Vcoverage[62]);
    }
    if ((1U == (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state))) {
        ++(vlSelf->__Vcoverage[298]);
    }
    if (vlSelfRef.link_adapter_tx__DOT__reset) {
        ++(vlSelf->__Vcoverage[299]);
    }
    if (((~ (IData)(vlSelfRef.link_adapter_tx__DOT__reset)) 
         & (1U != (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state)))) {
        ++(vlSelf->__Vcoverage[300]);
    }
    if (((IData)(vlSelfRef.link_adapter_tx__DOT__reset) 
         ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__reset))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 2, vlSelfRef.link_adapter_tx__DOT__reset, vlSelfRef.link_adapter_tx__DOT____Vtogcov__reset);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__reset 
            = vlSelfRef.link_adapter_tx__DOT__reset;
    }
    vlSelfRef.link_adapter_tx__DOT__next_link_adapter_state 
        = vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state;
    if ((4U & (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state))) {
        if ((2U & (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state))) {
            vlSelfRef.link_adapter_tx__DOT__next_link_adapter_state 
                = vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state;
            ++(vlSelf->__Vcoverage[319]);
        } else if ((1U & (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state))) {
            vlSelfRef.link_adapter_tx__DOT__next_link_adapter_state 
                = vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state;
            ++(vlSelf->__Vcoverage[319]);
        } else {
            if ((3U <= (IData)(vlSelfRef.link_adapter_tx__DOT__byte_ctr_crc_shift))) {
                if (vlSelfRef.link_adapter_tx__DOT__fifo_empty) {
                    vlSelfRef.link_adapter_tx__DOT__next_link_adapter_state = 0U;
                    ++(vlSelf->__Vcoverage[313]);
                } else {
                    vlSelfRef.link_adapter_tx__DOT__next_link_adapter_state = 1U;
                    ++(vlSelf->__Vcoverage[312]);
                }
                if ((1U & (~ (IData)(vlSelfRef.link_adapter_tx__DOT__fifo_empty)))) {
                    ++(vlSelf->__Vcoverage[314]);
                }
                if (vlSelfRef.link_adapter_tx__DOT__fifo_empty) {
                    ++(vlSelf->__Vcoverage[315]);
                }
                ++(vlSelf->__Vcoverage[316]);
            } else {
                vlSelfRef.link_adapter_tx__DOT__next_link_adapter_state = 4U;
                ++(vlSelf->__Vcoverage[317]);
            }
            ++(vlSelf->__Vcoverage[318]);
        }
    } else if ((2U & (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state))) {
        if ((1U & (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state))) {
            if (((IData)(vlSelfRef.link_adapter_tx__DOT__byte_ctr_shift) 
                 >= ((IData)(3U) + (IData)(vlSelfRef.link_adapter_tx__DOT__latched_L3_packet_size)))) {
                vlSelfRef.link_adapter_tx__DOT__next_link_adapter_state = 4U;
                ++(vlSelf->__Vcoverage[309]);
            } else {
                vlSelfRef.link_adapter_tx__DOT__next_link_adapter_state = 3U;
                ++(vlSelf->__Vcoverage[310]);
            }
            ++(vlSelf->__Vcoverage[311]);
        } else {
            vlSelfRef.link_adapter_tx__DOT__next_link_adapter_state = 3U;
            ++(vlSelf->__Vcoverage[308]);
        }
    } else if ((1U & (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state))) {
        vlSelfRef.link_adapter_tx__DOT__next_link_adapter_state = 2U;
        ++(vlSelf->__Vcoverage[307]);
    } else {
        if ((1U & ((~ (IData)(vlSelfRef.link_adapter_tx__DOT__reset)) 
                   & (~ (IData)(vlSelfRef.link_adapter_tx__DOT__fifo_empty))))) {
            vlSelfRef.link_adapter_tx__DOT__next_link_adapter_state = 1U;
            ++(vlSelf->__Vcoverage[301]);
        } else {
            ++(vlSelf->__Vcoverage[302]);
        }
        if ((1U & ((~ (IData)(vlSelfRef.link_adapter_tx__DOT__reset)) 
                   & (~ (IData)(vlSelfRef.link_adapter_tx__DOT__fifo_empty))))) {
            ++(vlSelf->__Vcoverage[303]);
        }
        if (vlSelfRef.link_adapter_tx__DOT__fifo_empty) {
            ++(vlSelf->__Vcoverage[304]);
        }
        if (vlSelfRef.link_adapter_tx__DOT__reset) {
            ++(vlSelf->__Vcoverage[305]);
        }
        ++(vlSelf->__Vcoverage[306]);
    }
    ++(vlSelf->__Vcoverage[320]);
    vlSelfRef.link_adapter_tx__DOT__crc_reset = ((IData)(vlSelfRef.link_adapter_tx__DOT__reset) 
                                                 | (1U 
                                                    == (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state)));
    vlSelfRef.link_adapter_tx__DOT__packet_ready = 
        (1U & (~ ((IData)(vlSelfRef.link_adapter_tx__DOT__reset) 
                  | (IData)(vlSelfRef.link_adapter_tx__DOT__fifo_full))));
    if (((IData)(vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__clk) 
         ^ (IData)(vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__clk))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 361, vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__clk, vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__clk);
        vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__clk 
            = vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__clk;
    }
    if ((0U != ((IData)(vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__message) 
                ^ (IData)(vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__message)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 341, vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__message, vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__message);
        vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__message 
            = vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__message;
    }
    if ((0U != ((IData)(vlSelfRef.link_adapter_tx__DOT__crc_byte_output) 
                ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__crc_byte_output)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 262, vlSelfRef.link_adapter_tx__DOT__crc_byte_output, vlSelfRef.link_adapter_tx__DOT____Vtogcov__crc_byte_output);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__crc_byte_output 
            = vlSelfRef.link_adapter_tx__DOT__crc_byte_output;
    }
    if (((IData)(vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__enable) 
         ^ (IData)(vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__enable))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 359, vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__enable, vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__enable);
        vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__enable 
            = vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__enable;
    }
    if ((0U != ((IData)(vlSelfRef.link_adapter_tx__DOT__next_link_adapter_state) 
                ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__next_link_adapter_state)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 30, vlSelfRef.link_adapter_tx__DOT__next_link_adapter_state, vlSelfRef.link_adapter_tx__DOT____Vtogcov__next_link_adapter_state);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__next_link_adapter_state 
            = vlSelfRef.link_adapter_tx__DOT__next_link_adapter_state;
    }
    if (((IData)(vlSelfRef.link_adapter_tx__DOT__crc_reset) 
         ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__crc_reset))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 296, vlSelfRef.link_adapter_tx__DOT__crc_reset, vlSelfRef.link_adapter_tx__DOT____Vtogcov__crc_reset);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__crc_reset 
            = vlSelfRef.link_adapter_tx__DOT__crc_reset;
    }
    vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__reset 
        = vlSelfRef.link_adapter_tx__DOT__crc_reset;
    if (((IData)(vlSelfRef.link_adapter_tx__DOT__packet_valid) 
         & (IData)(vlSelfRef.link_adapter_tx__DOT__packet_ready))) {
        ++(vlSelf->__Vcoverage[85]);
    }
    if ((1U & (~ (IData)(vlSelfRef.link_adapter_tx__DOT__packet_ready)))) {
        ++(vlSelf->__Vcoverage[86]);
    }
    if ((1U & (~ (IData)(vlSelfRef.link_adapter_tx__DOT__packet_valid)))) {
        ++(vlSelf->__Vcoverage[87]);
    }
    ++(vlSelf->__Vcoverage[88]);
    if (((IData)(vlSelfRef.link_adapter_tx__DOT__packet_valid) 
         & (IData)(vlSelfRef.link_adapter_tx__DOT__packet_ready))) {
        ++(vlSelf->__Vcoverage[91]);
    }
    if ((1U & (~ (IData)(vlSelfRef.link_adapter_tx__DOT__packet_ready)))) {
        ++(vlSelf->__Vcoverage[92]);
    }
    if ((1U & (~ (IData)(vlSelfRef.link_adapter_tx__DOT__packet_valid)))) {
        ++(vlSelf->__Vcoverage[93]);
    }
    if (((IData)(vlSelfRef.link_adapter_tx__DOT__packet_ready) 
         ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__packet_ready))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6, vlSelfRef.link_adapter_tx__DOT__packet_ready, vlSelfRef.link_adapter_tx__DOT____Vtogcov__packet_ready);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__packet_ready 
            = vlSelfRef.link_adapter_tx__DOT__packet_ready;
    }
    vlSelfRef.packet_ready = vlSelfRef.link_adapter_tx__DOT__packet_ready;
    __VdfgRegularize_h6e95ff9d_0_0 = ((IData)(vlSelfRef.link_adapter_tx__DOT__packet_valid) 
                                      & (IData)(vlSelfRef.link_adapter_tx__DOT__packet_ready));
    if (((IData)(vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__reset) 
         ^ (IData)(vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__reset))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 357, vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__reset, vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__reset);
        vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__reset 
            = vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__reset;
    }
    vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_b_w_en 
        = __VdfgRegularize_h6e95ff9d_0_0;
    vlSelfRef.link_adapter_tx__DOT__push_fifo = __VdfgRegularize_h6e95ff9d_0_0;
    if (((IData)(vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_b_w_en) 
         ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_buffer_port_b_w_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 80, vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_b_w_en, vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_buffer_port_b_w_en);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_buffer_port_b_w_en 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_b_w_en;
    }
    if (((IData)(vlSelfRef.link_adapter_tx__DOT__push_fifo) 
         ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__push_fifo))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 89, vlSelfRef.link_adapter_tx__DOT__push_fifo, vlSelfRef.link_adapter_tx__DOT____Vtogcov__push_fifo);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__push_fifo 
            = vlSelfRef.link_adapter_tx__DOT__push_fifo;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__ico
        vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                          & vlSelfRef.__VicoTriggered[0U]) 
                                         | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = Vtop___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        {
            // Inlined CFunc: _eval_ico
            if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
                Vtop___024root___ico_sequent__TOP__0(vlSelf);
            }
        }
    }
    return (__VicoExecute);
}

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

extern const VlWide<65>/*2079:0*/ Vtop__ConstPool__CONST_h9933206d_0;
extern const VlWide<65>/*2079:0*/ Vtop__ConstPool__CONST_h614f9ca9_0;

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*2:0*/ __Vfsmcov_prev_link_adapter_tx__DOT__current_link_adapter_state__0;
    __Vfsmcov_prev_link_adapter_tx__DOT__current_link_adapter_state__0 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_0;
    __VdfgRegularize_h6e95ff9d_0_0 = 0;
    CData/*2:0*/ __Vdly__link_adapter_tx__DOT__fifo_ring_write_ptr;
    __Vdly__link_adapter_tx__DOT__fifo_ring_write_ptr = 0;
    CData/*2:0*/ __Vdly__link_adapter_tx__DOT__fifo_ring_top_ptr;
    __Vdly__link_adapter_tx__DOT__fifo_ring_top_ptr = 0;
    CData/*3:0*/ __Vdly__link_adapter_tx__DOT__fifo_ring_size;
    __Vdly__link_adapter_tx__DOT__fifo_ring_size = 0;
    VlWide<65>/*2079:0*/ __Vdly__link_adapter_tx__DOT__L2_frame_shift_reg;
    VL_ZERO_W(2080, __Vdly__link_adapter_tx__DOT__L2_frame_shift_reg);
    VlWide<65>/*2079:0*/ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg;
    VL_ZERO_W(2080, __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg);
    SData/*8:0*/ __Vdly__link_adapter_tx__DOT__byte_ctr_shift;
    __Vdly__link_adapter_tx__DOT__byte_ctr_shift = 0;
    CData/*1:0*/ __Vdly__link_adapter_tx__DOT__byte_ctr_crc_shift;
    __Vdly__link_adapter_tx__DOT__byte_ctr_crc_shift = 0;
    VlWide<64>/*2047:0*/ __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0;
    VL_ZERO_W(2048, __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0);
    CData/*2:0*/ __VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0;
    __VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0 = 0;
    CData/*0:0*/ __VdlySet__link_adapter_tx__DOT__fifo_ring_buffer__v0;
    __VdlySet__link_adapter_tx__DOT__fifo_ring_buffer__v0 = 0;
    VlWide<65>/*2079:0*/ __Vtemp_1;
    IData/*31:0*/ __Vilp1;
    IData/*31:0*/ __Vilp2;
    IData/*31:0*/ __Vilp3;
    // Body
    __VdlySet__link_adapter_tx__DOT__fifo_ring_buffer__v0 = 0U;
    __Vdly__link_adapter_tx__DOT__fifo_ring_write_ptr 
        = vlSelfRef.link_adapter_tx__DOT__fifo_ring_write_ptr;
    __Vdly__link_adapter_tx__DOT__fifo_ring_top_ptr 
        = vlSelfRef.link_adapter_tx__DOT__fifo_ring_top_ptr;
    __Vdly__link_adapter_tx__DOT__fifo_ring_size = vlSelfRef.link_adapter_tx__DOT__fifo_ring_size;
    __Vdly__link_adapter_tx__DOT__byte_ctr_crc_shift 
        = vlSelfRef.link_adapter_tx__DOT__byte_ctr_crc_shift;
    __Vdly__link_adapter_tx__DOT__byte_ctr_shift = vlSelfRef.link_adapter_tx__DOT__byte_ctr_shift;
    __Vfsmcov_prev_link_adapter_tx__DOT__current_link_adapter_state__0 
        = vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state;
    if (vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_b_w_en) {
        ++(vlSelf->__Vcoverage[82]);
        __Vilp1 = 0U;
        while ((__Vilp1 <= 0x0000003fU)) {
            __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[__Vilp1] 
                = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_b_w_data
                [__Vilp1];
            __Vilp1 = ((IData)(1U) + __Vilp1);
        }
        __VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_b_addr;
        __VdlySet__link_adapter_tx__DOT__fifo_ring_buffer__v0 = 1U;
    } else {
        ++(vlSelf->__Vcoverage[83]);
    }
    ++(vlSelf->__Vcoverage[84]);
    if (vlSelfRef.link_adapter_tx__DOT__reset) {
        ++(vlSelf->__Vcoverage[109]);
        __Vdly__link_adapter_tx__DOT__fifo_ring_write_ptr = 0U;
        __Vdly__link_adapter_tx__DOT__fifo_ring_top_ptr = 0U;
        __Vdly__link_adapter_tx__DOT__fifo_ring_size = 0U;
    } else {
        if (vlSelfRef.link_adapter_tx__DOT__push_fifo) {
            if ((7U == (IData)(vlSelfRef.link_adapter_tx__DOT__fifo_ring_write_ptr))) {
                ++(vlSelf->__Vcoverage[96]);
                __Vdly__link_adapter_tx__DOT__fifo_ring_write_ptr = 0U;
            } else {
                __Vdly__link_adapter_tx__DOT__fifo_ring_write_ptr 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.link_adapter_tx__DOT__fifo_ring_write_ptr)));
                ++(vlSelf->__Vcoverage[97]);
            }
            ++(vlSelf->__Vcoverage[98]);
        } else {
            ++(vlSelf->__Vcoverage[99]);
        }
        if (vlSelfRef.link_adapter_tx__DOT__pop_fifo) {
            if ((7U == (IData)(vlSelfRef.link_adapter_tx__DOT__fifo_ring_top_ptr))) {
                ++(vlSelf->__Vcoverage[100]);
                __Vdly__link_adapter_tx__DOT__fifo_ring_top_ptr = 0U;
            } else {
                __Vdly__link_adapter_tx__DOT__fifo_ring_top_ptr 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.link_adapter_tx__DOT__fifo_ring_top_ptr)));
                ++(vlSelf->__Vcoverage[101]);
            }
            ++(vlSelf->__Vcoverage[102]);
        } else {
            ++(vlSelf->__Vcoverage[103]);
        }
        if (vlSelfRef.link_adapter_tx__DOT__push_fifo) {
            if (vlSelfRef.link_adapter_tx__DOT__pop_fifo) {
                __Vdly__link_adapter_tx__DOT__fifo_ring_size 
                    = vlSelfRef.link_adapter_tx__DOT__fifo_ring_size;
                ++(vlSelf->__Vcoverage[107]);
            } else {
                __Vdly__link_adapter_tx__DOT__fifo_ring_size 
                    = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.link_adapter_tx__DOT__fifo_ring_size)));
                ++(vlSelf->__Vcoverage[106]);
            }
        } else if (vlSelfRef.link_adapter_tx__DOT__pop_fifo) {
            __Vdly__link_adapter_tx__DOT__fifo_ring_size 
                = (0x0000000fU & ((IData)(vlSelfRef.link_adapter_tx__DOT__fifo_ring_size) 
                                  - (IData)(1U)));
            ++(vlSelf->__Vcoverage[105]);
        } else {
            __Vdly__link_adapter_tx__DOT__fifo_ring_size 
                = vlSelfRef.link_adapter_tx__DOT__fifo_ring_size;
            ++(vlSelf->__Vcoverage[104]);
        }
        ++(vlSelf->__Vcoverage[110]);
    }
    ++(vlSelf->__Vcoverage[111]);
    if (vlSelfRef.link_adapter_tx__DOT__reset) {
        ++(vlSelf->__Vcoverage[339]);
        VL_ASSIGN_W(2080, __Vdly__link_adapter_tx__DOT__L2_frame_shift_reg, Vtop__ConstPool__CONST_h9933206d_0);
        VL_ASSIGN_W(2080, __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg, Vtop__ConstPool__CONST_h614f9ca9_0);
        __Vdly__link_adapter_tx__DOT__byte_ctr_shift = 0U;
        __Vdly__link_adapter_tx__DOT__byte_ctr_crc_shift = 0U;
        vlSelfRef.link_adapter_tx__DOT__latched_L3_packet_size = 0U;
        vlSelfRef.link_adapter_tx__DOT__OSERDES_out = 0U;
    } else if ((1U == (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state))) {
        ++(vlSelf->__Vcoverage[338]);
        VL_ASSIGN_W(2080, __Vdly__link_adapter_tx__DOT__L2_frame_shift_reg, Vtop__ConstPool__CONST_h9933206d_0);
        VL_ASSIGN_W(2080, __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg, Vtop__ConstPool__CONST_h614f9ca9_0);
        __Vdly__link_adapter_tx__DOT__byte_ctr_shift = 0U;
        __Vdly__link_adapter_tx__DOT__byte_ctr_crc_shift = 0U;
        vlSelfRef.link_adapter_tx__DOT__latched_L3_packet_size = 0U;
        vlSelfRef.link_adapter_tx__DOT__OSERDES_out = 0U;
    } else if ((2U == (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state))) {
        ++(vlSelf->__Vcoverage[337]);
        __Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[0U] 
            = (0x000000abU | ((IData)(vlSelfRef.link_adapter_tx__DOT__curr_L3_packet_size) 
                              << 0x00000010U));
        __Vilp2 = 0U;
        while ((__Vilp2 <= 0x0000003fU)) {
            __Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[(__Vilp2 
                                                              + (IData)(1U))] 
                = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data
                [__Vilp2];
            __Vilp2 = ((IData)(1U) + __Vilp2);
        }
        VL_ASSIGN_W(2080, __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg, Vtop__ConstPool__CONST_h614f9ca9_0);
        __Vdly__link_adapter_tx__DOT__byte_ctr_shift = 0U;
        __Vdly__link_adapter_tx__DOT__byte_ctr_crc_shift = 0U;
        vlSelfRef.link_adapter_tx__DOT__latched_L3_packet_size 
            = vlSelfRef.link_adapter_tx__DOT__curr_L3_packet_size;
        vlSelfRef.link_adapter_tx__DOT__OSERDES_out = 0U;
    } else if ((3U == (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state))) {
        __Vdly__link_adapter_tx__DOT__byte_ctr_shift 
            = (0x000001ffU & ((IData)(1U) + (IData)(vlSelfRef.link_adapter_tx__DOT__byte_ctr_shift)));
        ++(vlSelf->__Vcoverage[336]);
        vlSelfRef.link_adapter_tx__DOT__OSERDES_out 
            = (0x000000ffU & vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[0U]);
        VL_SHIFTR_WWI(2080,2080,32, __Vtemp_1, vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg, 8U);
        __Vilp3 = 0U;
        while ((__Vilp3 <= 0x00000040U)) {
            vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[__Vilp3] 
                = __Vtemp_1[__Vilp3];
            __Vilp3 = ((IData)(1U) + __Vilp3);
        }
    } else if ((4U == (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state))) {
        __Vdly__link_adapter_tx__DOT__byte_ctr_crc_shift 
            = (3U & ((IData)(1U) + (IData)(vlSelfRef.link_adapter_tx__DOT__byte_ctr_crc_shift)));
        ++(vlSelf->__Vcoverage[334]);
        vlSelfRef.link_adapter_tx__DOT__OSERDES_out 
            = vlSelfRef.link_adapter_tx__DOT__crc_byte_output;
    } else {
        ++(vlSelf->__Vcoverage[335]);
        VL_ASSIGN_W(2080, __Vdly__link_adapter_tx__DOT__L2_frame_shift_reg, Vtop__ConstPool__CONST_h9933206d_0);
        VL_ASSIGN_W(2080, __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg, Vtop__ConstPool__CONST_h614f9ca9_0);
        __Vdly__link_adapter_tx__DOT__byte_ctr_shift = 0U;
        __Vdly__link_adapter_tx__DOT__byte_ctr_crc_shift = 0U;
        vlSelfRef.link_adapter_tx__DOT__latched_L3_packet_size = 0U;
        vlSelfRef.link_adapter_tx__DOT__OSERDES_out = 0U;
    }
    ++(vlSelf->__Vcoverage[340]);
    vlSelfRef.link_adapter_tx__DOT__fifo_ring_write_ptr 
        = __Vdly__link_adapter_tx__DOT__fifo_ring_write_ptr;
    vlSelfRef.link_adapter_tx__DOT__fifo_ring_top_ptr 
        = __Vdly__link_adapter_tx__DOT__fifo_ring_top_ptr;
    vlSelfRef.link_adapter_tx__DOT__fifo_ring_size 
        = __Vdly__link_adapter_tx__DOT__fifo_ring_size;
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[0U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[0U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[0U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[0U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[0U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[1U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[1U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[1U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[1U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[1U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[2U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[2U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[2U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[2U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[2U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[3U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[3U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[3U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[3U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[3U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[4U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[4U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[4U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[4U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[4U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[5U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[5U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[5U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[5U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[5U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[6U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[6U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[6U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[6U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[6U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[7U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[7U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[7U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[7U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[7U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[8U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[8U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[8U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[8U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[8U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[9U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[9U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[9U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[9U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[9U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[10U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[10U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[10U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[10U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[10U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[11U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[11U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[11U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[11U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[11U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[12U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[12U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[12U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[12U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[12U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[13U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[13U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[13U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[13U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[13U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[14U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[14U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[14U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[14U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[14U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[15U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[15U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[15U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[15U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[15U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[16U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[16U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[16U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[16U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[16U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[17U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[17U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[17U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[17U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[17U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[18U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[18U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[18U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[18U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[18U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[19U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[19U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[19U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[19U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[19U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[20U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[20U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[20U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[20U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[20U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[21U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[21U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[21U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[21U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[21U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[22U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[22U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[22U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[22U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[22U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[23U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[23U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[23U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[23U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[23U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[24U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[24U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[24U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[24U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[24U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[25U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[25U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[25U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[25U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[25U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[26U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[26U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[26U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[26U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[26U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[27U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[27U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[27U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[27U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[27U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[28U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[28U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[28U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[28U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[28U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[29U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[29U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[29U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[29U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[29U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[30U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[30U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[30U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[30U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[30U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[31U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[31U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[31U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[31U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[31U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[32U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[32U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[32U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[32U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[32U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[33U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[33U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[33U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[33U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[33U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[34U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[34U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[34U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[34U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[34U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[35U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[35U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[35U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[35U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[35U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[36U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[36U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[36U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[36U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[36U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[37U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[37U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[37U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[37U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[37U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[38U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[38U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[38U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[38U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[38U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[39U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[39U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[39U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[39U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[39U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[40U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[40U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[40U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[40U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[40U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[41U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[41U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[41U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[41U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[41U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[42U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[42U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[42U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[42U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[42U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[43U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[43U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[43U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[43U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[43U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[44U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[44U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[44U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[44U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[44U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[45U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[45U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[45U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[45U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[45U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[46U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[46U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[46U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[46U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[46U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[47U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[47U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[47U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[47U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[47U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[48U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[48U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[48U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[48U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[48U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[49U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[49U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[49U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[49U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[49U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[50U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[50U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[50U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[50U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[50U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[51U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[51U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[51U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[51U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[51U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[52U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[52U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[52U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[52U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[52U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[53U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[53U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[53U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[53U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[53U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[54U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[54U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[54U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[54U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[54U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[55U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[55U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[55U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[55U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[55U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[56U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[56U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[56U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[56U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[56U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[57U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[57U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[57U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[57U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[57U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[58U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[58U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[58U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[58U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[58U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[59U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[59U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[59U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[59U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[59U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[60U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[60U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[60U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[60U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[60U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[61U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[61U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[61U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[61U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[61U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[62U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[62U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[62U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[62U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[62U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[63U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[63U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[63U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[63U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[63U])));
    vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[64U] 
        = ((__Vdly__link_adapter_tx__DOT__L2_frame_shift_reg[64U] 
            & __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[64U]) 
           | (vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[64U] 
              & (~ __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg[64U])));
    VL_ASSIGN_W(2080, __VdlyMask__link_adapter_tx__DOT__L2_frame_shift_reg, Vtop__ConstPool__CONST_h9933206d_0);
    vlSelfRef.link_adapter_tx__DOT__byte_ctr_crc_shift 
        = __Vdly__link_adapter_tx__DOT__byte_ctr_crc_shift;
    vlSelfRef.link_adapter_tx__DOT__byte_ctr_shift 
        = __Vdly__link_adapter_tx__DOT__byte_ctr_shift;
    if ((0U != ((IData)(vlSelfRef.link_adapter_tx__DOT__fifo_ring_write_ptr) 
                ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_write_ptr)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 36, vlSelfRef.link_adapter_tx__DOT__fifo_ring_write_ptr, vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_write_ptr);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_write_ptr 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_write_ptr;
    }
    vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_b_addr 
        = vlSelfRef.link_adapter_tx__DOT__fifo_ring_write_ptr;
    if ((0U != ((IData)(vlSelfRef.link_adapter_tx__DOT__fifo_ring_top_ptr) 
                ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_top_ptr)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 42, vlSelfRef.link_adapter_tx__DOT__fifo_ring_top_ptr, vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_top_ptr);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_top_ptr 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_top_ptr;
    }
    if ((0U != ((IData)(vlSelfRef.link_adapter_tx__DOT__fifo_ring_size) 
                ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_size)))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSelf->__Vcoverage + 48, vlSelfRef.link_adapter_tx__DOT__fifo_ring_size, vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_size);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_size 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_size;
    }
    vlSelfRef.link_adapter_tx__DOT__fifo_empty = (0U 
                                                  == (IData)(vlSelfRef.link_adapter_tx__DOT__fifo_ring_size));
    vlSelfRef.link_adapter_tx__DOT__fifo_full = (8U 
                                                 == (IData)(vlSelfRef.link_adapter_tx__DOT__fifo_ring_size));
    if ((0U != ((IData)(vlSelfRef.link_adapter_tx__DOT__OSERDES_out) 
                ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__OSERDES_out)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 8, vlSelfRef.link_adapter_tx__DOT__OSERDES_out, vlSelfRef.link_adapter_tx__DOT____Vtogcov__OSERDES_out);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__OSERDES_out 
            = vlSelfRef.link_adapter_tx__DOT__OSERDES_out;
    }
    vlSelfRef.OSERDES_out = vlSelfRef.link_adapter_tx__DOT__OSERDES_out;
    if ((0U != ((IData)(vlSelfRef.link_adapter_tx__DOT__latched_L3_packet_size) 
                ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__latched_L3_packet_size)))) {
        VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 134, vlSelfRef.link_adapter_tx__DOT__latched_L3_packet_size, vlSelfRef.link_adapter_tx__DOT____Vtogcov__latched_L3_packet_size);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__latched_L3_packet_size 
            = vlSelfRef.link_adapter_tx__DOT__latched_L3_packet_size;
    }
    vlSelfRef.link_adapter_tx__DOT__crc_calc_input 
        = (0x000000ffU & vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg[0U]);
    if ((0U != ((IData)(vlSelfRef.link_adapter_tx__DOT__byte_ctr_crc_shift) 
                ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__byte_ctr_crc_shift)))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSelf->__Vcoverage + 130, vlSelfRef.link_adapter_tx__DOT__byte_ctr_crc_shift, vlSelfRef.link_adapter_tx__DOT____Vtogcov__byte_ctr_crc_shift);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__byte_ctr_crc_shift 
            = vlSelfRef.link_adapter_tx__DOT__byte_ctr_crc_shift;
    }
    if ((0U != ((IData)(vlSelfRef.link_adapter_tx__DOT__byte_ctr_shift) 
                ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__byte_ctr_shift)))) {
        VL_COV_TOGGLE_CHG_ST_I(9, vlSelf->__Vcoverage + 112, vlSelfRef.link_adapter_tx__DOT__byte_ctr_shift, vlSelfRef.link_adapter_tx__DOT____Vtogcov__byte_ctr_shift);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__byte_ctr_shift 
            = vlSelfRef.link_adapter_tx__DOT__byte_ctr_shift;
    }
    if (vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_en) {
        ++(vlSelf->__Vcoverage[71]);
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[0U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][0U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[1U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][1U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[2U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][2U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[3U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][3U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[4U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][4U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[5U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][5U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[6U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][6U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[7U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][7U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[8U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][8U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[9U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][9U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[10U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][10U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[11U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][11U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[12U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][12U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[13U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][13U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[14U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][14U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[15U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][15U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[16U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][16U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[17U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][17U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[18U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][18U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[19U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][19U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[20U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][20U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[21U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][21U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[22U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][22U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[23U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][23U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[24U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][24U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[25U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][25U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[26U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][26U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[27U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][27U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[28U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][28U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[29U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][29U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[30U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][30U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[31U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][31U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[32U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][32U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[33U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][33U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[34U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][34U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[35U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][35U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[36U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][36U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[37U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][37U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[38U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][38U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[39U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][39U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[40U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][40U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[41U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][41U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[42U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][42U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[43U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][43U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[44U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][44U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[45U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][45U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[46U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][46U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[47U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][47U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[48U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][48U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[49U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][49U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[50U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][50U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[51U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][51U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[52U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][52U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[53U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][53U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[54U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][54U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[55U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][55U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[56U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][56U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[57U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][57U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[58U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][58U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[59U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][59U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[60U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][60U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[61U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][61U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[62U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][62U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[63U] 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer
            [vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr][63U];
    } else {
        ++(vlSelf->__Vcoverage[72]);
    }
    ++(vlSelf->__Vcoverage[73]);
    if (vlSelfRef.link_adapter_tx__DOT__reset) {
        ++(vlSelf->__Vcoverage[325]);
        vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state = 0U;
    } else {
        ++(vlSelf->__Vcoverage[326]);
        vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state 
            = vlSelfRef.link_adapter_tx__DOT__next_link_adapter_state;
    }
    ++(vlSelf->__Vcoverage[327]);
    if ((0U != ((IData)(vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_b_addr) 
                ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_buffer_port_b_addr)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 74, vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_b_addr, vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_buffer_port_b_addr);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_buffer_port_b_addr 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_b_addr;
    }
    if (((IData)(vlSelfRef.link_adapter_tx__DOT__fifo_empty) 
         ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_empty))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 58, vlSelfRef.link_adapter_tx__DOT__fifo_empty, vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_empty);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_empty 
            = vlSelfRef.link_adapter_tx__DOT__fifo_empty;
    }
    if (((IData)(vlSelfRef.link_adapter_tx__DOT__fifo_full) 
         ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_full))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 56, vlSelfRef.link_adapter_tx__DOT__fifo_full, vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_full);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_full 
            = vlSelfRef.link_adapter_tx__DOT__fifo_full;
    }
    if ((1U & ((~ (IData)(vlSelfRef.link_adapter_tx__DOT__fifo_full)) 
               & (~ (IData)(vlSelfRef.link_adapter_tx__DOT__reset))))) {
        ++(vlSelf->__Vcoverage[60]);
    }
    if (vlSelfRef.link_adapter_tx__DOT__reset) {
        ++(vlSelf->__Vcoverage[61]);
    }
    if (vlSelfRef.link_adapter_tx__DOT__fifo_full) {
        ++(vlSelf->__Vcoverage[62]);
    }
    vlSelfRef.link_adapter_tx__DOT__packet_ready = 
        (1U & (~ ((IData)(vlSelfRef.link_adapter_tx__DOT__reset) 
                  | (IData)(vlSelfRef.link_adapter_tx__DOT__fifo_full))));
    if ((0U != ((IData)(vlSelfRef.link_adapter_tx__DOT__crc_calc_input) 
                ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__crc_calc_input)))) {
        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 278, vlSelfRef.link_adapter_tx__DOT__crc_calc_input, vlSelfRef.link_adapter_tx__DOT____Vtogcov__crc_calc_input);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__crc_calc_input 
            = vlSelfRef.link_adapter_tx__DOT__crc_calc_input;
    }
    if (__VdlySet__link_adapter_tx__DOT__fifo_ring_buffer__v0) {
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][0U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[0U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][1U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[1U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][2U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[2U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][3U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[3U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][4U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[4U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][5U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[5U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][6U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[6U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][7U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[7U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][8U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[8U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][9U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[9U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][10U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[10U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][11U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[11U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][12U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[12U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][13U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[13U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][14U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[14U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][15U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[15U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][16U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[16U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][17U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[17U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][18U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[18U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][19U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[19U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][20U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[20U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][21U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[21U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][22U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[22U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][23U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[23U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][24U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[24U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][25U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[25U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][26U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[26U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][27U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[27U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][28U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[28U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][29U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[29U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][30U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[30U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][31U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[31U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][32U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[32U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][33U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[33U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][34U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[34U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][35U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[35U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][36U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[36U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][37U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[37U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][38U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[38U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][39U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[39U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][40U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[40U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][41U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[41U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][42U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[42U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][43U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[43U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][44U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[44U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][45U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[45U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][46U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[46U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][47U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[47U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][48U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[48U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][49U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[49U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][50U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[50U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][51U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[51U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][52U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[52U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][53U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[53U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][54U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[54U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][55U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[55U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][56U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[56U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][57U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[57U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][58U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[58U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][59U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[59U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][60U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[60U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][61U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[61U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][62U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[62U];
        vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer[__VdlyDim0__link_adapter_tx__DOT__fifo_ring_buffer__v0][63U] 
            = __VdlyVal__link_adapter_tx__DOT__fifo_ring_buffer__v0[63U];
    }
    vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr 
        = vlSelfRef.link_adapter_tx__DOT__fifo_ring_top_ptr;
    if (((IData)(vlSelfRef.link_adapter_tx__DOT__packet_valid) 
         & (IData)(vlSelfRef.link_adapter_tx__DOT__packet_ready))) {
        ++(vlSelf->__Vcoverage[85]);
    }
    if ((1U & (~ (IData)(vlSelfRef.link_adapter_tx__DOT__packet_ready)))) {
        ++(vlSelf->__Vcoverage[86]);
    }
    if ((1U & (~ (IData)(vlSelfRef.link_adapter_tx__DOT__packet_valid)))) {
        ++(vlSelf->__Vcoverage[87]);
    }
    ++(vlSelf->__Vcoverage[88]);
    if (((IData)(vlSelfRef.link_adapter_tx__DOT__packet_valid) 
         & (IData)(vlSelfRef.link_adapter_tx__DOT__packet_ready))) {
        ++(vlSelf->__Vcoverage[91]);
    }
    if ((1U & (~ (IData)(vlSelfRef.link_adapter_tx__DOT__packet_ready)))) {
        ++(vlSelf->__Vcoverage[92]);
    }
    if ((1U & (~ (IData)(vlSelfRef.link_adapter_tx__DOT__packet_valid)))) {
        ++(vlSelf->__Vcoverage[93]);
    }
    if (((IData)(vlSelfRef.link_adapter_tx__DOT__packet_ready) 
         ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__packet_ready))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 6, vlSelfRef.link_adapter_tx__DOT__packet_ready, vlSelfRef.link_adapter_tx__DOT____Vtogcov__packet_ready);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__packet_ready 
            = vlSelfRef.link_adapter_tx__DOT__packet_ready;
    }
    vlSelfRef.packet_ready = vlSelfRef.link_adapter_tx__DOT__packet_ready;
    __VdfgRegularize_h6e95ff9d_0_0 = ((IData)(vlSelfRef.link_adapter_tx__DOT__packet_valid) 
                                      & (IData)(vlSelfRef.link_adapter_tx__DOT__packet_ready));
    if ((0U != ((IData)(vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr) 
                ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_buffer_port_a_addr)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 63, vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr, vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_buffer_port_a_addr);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_buffer_port_a_addr 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr;
    }
    if ((1U == (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state))) {
        ++(vlSelf->__Vcoverage[298]);
    }
    if (vlSelfRef.link_adapter_tx__DOT__reset) {
        ++(vlSelf->__Vcoverage[299]);
    }
    if (((~ (IData)(vlSelfRef.link_adapter_tx__DOT__reset)) 
         & (1U != (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state)))) {
        ++(vlSelf->__Vcoverage[300]);
    }
    if ((0U != ((IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state) 
                ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__current_link_adapter_state)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 24, vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state, vlSelfRef.link_adapter_tx__DOT____Vtogcov__current_link_adapter_state);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__current_link_adapter_state 
            = vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state;
    }
    if (((0U != (IData)(__Vfsmcov_prev_link_adapter_tx__DOT__current_link_adapter_state__0)) 
         && (0U == (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state)))) {
        ++(vlSelf->__Vcoverage[432]);
    }
    if (((1U != (IData)(__Vfsmcov_prev_link_adapter_tx__DOT__current_link_adapter_state__0)) 
         && (1U == (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state)))) {
        ++(vlSelf->__Vcoverage[433]);
    }
    if (((2U != (IData)(__Vfsmcov_prev_link_adapter_tx__DOT__current_link_adapter_state__0)) 
         && (2U == (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state)))) {
        ++(vlSelf->__Vcoverage[434]);
    }
    if (((3U != (IData)(__Vfsmcov_prev_link_adapter_tx__DOT__current_link_adapter_state__0)) 
         && (3U == (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state)))) {
        ++(vlSelf->__Vcoverage[435]);
    }
    if (((4U != (IData)(__Vfsmcov_prev_link_adapter_tx__DOT__current_link_adapter_state__0)) 
         && (4U == (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state)))) {
        ++(vlSelf->__Vcoverage[436]);
    }
    if (((IData)(vlSelfRef.link_adapter_tx__DOT__reset) 
         && (0U == (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state)))) {
        ++(vlSelf->__Vcoverage[437]);
    }
    if (((1U == (IData)(__Vfsmcov_prev_link_adapter_tx__DOT__current_link_adapter_state__0)) 
         && (2U == (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state)))) {
        ++(vlSelf->__Vcoverage[438]);
    }
    if (((2U == (IData)(__Vfsmcov_prev_link_adapter_tx__DOT__current_link_adapter_state__0)) 
         && (3U == (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state)))) {
        ++(vlSelf->__Vcoverage[439]);
    }
    if (((3U == (IData)(__Vfsmcov_prev_link_adapter_tx__DOT__current_link_adapter_state__0)) 
         && (4U == (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state)))) {
        ++(vlSelf->__Vcoverage[440]);
    }
    if (((3U == (IData)(__Vfsmcov_prev_link_adapter_tx__DOT__current_link_adapter_state__0)) 
         && (3U == (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state)))) {
        ++(vlSelf->__Vcoverage[441]);
    }
    vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_en 
        = (1U == (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state));
    vlSelfRef.link_adapter_tx__DOT__pop_fifo = (2U 
                                                == (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state));
    vlSelfRef.link_adapter_tx__DOT__next_link_adapter_state 
        = vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state;
    if ((4U & (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state))) {
        if ((2U & (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state))) {
            vlSelfRef.link_adapter_tx__DOT__next_link_adapter_state 
                = vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state;
            ++(vlSelf->__Vcoverage[319]);
        } else if ((1U & (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state))) {
            vlSelfRef.link_adapter_tx__DOT__next_link_adapter_state 
                = vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state;
            ++(vlSelf->__Vcoverage[319]);
        } else {
            if ((3U <= (IData)(vlSelfRef.link_adapter_tx__DOT__byte_ctr_crc_shift))) {
                if (vlSelfRef.link_adapter_tx__DOT__fifo_empty) {
                    vlSelfRef.link_adapter_tx__DOT__next_link_adapter_state = 0U;
                    ++(vlSelf->__Vcoverage[313]);
                } else {
                    vlSelfRef.link_adapter_tx__DOT__next_link_adapter_state = 1U;
                    ++(vlSelf->__Vcoverage[312]);
                }
                if ((1U & (~ (IData)(vlSelfRef.link_adapter_tx__DOT__fifo_empty)))) {
                    ++(vlSelf->__Vcoverage[314]);
                }
                if (vlSelfRef.link_adapter_tx__DOT__fifo_empty) {
                    ++(vlSelf->__Vcoverage[315]);
                }
                ++(vlSelf->__Vcoverage[316]);
            } else {
                vlSelfRef.link_adapter_tx__DOT__next_link_adapter_state = 4U;
                ++(vlSelf->__Vcoverage[317]);
            }
            ++(vlSelf->__Vcoverage[318]);
        }
    } else if ((2U & (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state))) {
        if ((1U & (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state))) {
            if (((IData)(vlSelfRef.link_adapter_tx__DOT__byte_ctr_shift) 
                 >= ((IData)(3U) + (IData)(vlSelfRef.link_adapter_tx__DOT__latched_L3_packet_size)))) {
                vlSelfRef.link_adapter_tx__DOT__next_link_adapter_state = 4U;
                ++(vlSelf->__Vcoverage[309]);
            } else {
                vlSelfRef.link_adapter_tx__DOT__next_link_adapter_state = 3U;
                ++(vlSelf->__Vcoverage[310]);
            }
            ++(vlSelf->__Vcoverage[311]);
        } else {
            vlSelfRef.link_adapter_tx__DOT__next_link_adapter_state = 3U;
            ++(vlSelf->__Vcoverage[308]);
        }
    } else if ((1U & (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state))) {
        vlSelfRef.link_adapter_tx__DOT__next_link_adapter_state = 2U;
        ++(vlSelf->__Vcoverage[307]);
    } else {
        if ((1U & ((~ (IData)(vlSelfRef.link_adapter_tx__DOT__reset)) 
                   & (~ (IData)(vlSelfRef.link_adapter_tx__DOT__fifo_empty))))) {
            vlSelfRef.link_adapter_tx__DOT__next_link_adapter_state = 1U;
            ++(vlSelf->__Vcoverage[301]);
        } else {
            ++(vlSelf->__Vcoverage[302]);
        }
        if ((1U & ((~ (IData)(vlSelfRef.link_adapter_tx__DOT__reset)) 
                   & (~ (IData)(vlSelfRef.link_adapter_tx__DOT__fifo_empty))))) {
            ++(vlSelf->__Vcoverage[303]);
        }
        if (vlSelfRef.link_adapter_tx__DOT__fifo_empty) {
            ++(vlSelf->__Vcoverage[304]);
        }
        if (vlSelfRef.link_adapter_tx__DOT__reset) {
            ++(vlSelf->__Vcoverage[305]);
        }
        ++(vlSelf->__Vcoverage[306]);
    }
    ++(vlSelf->__Vcoverage[320]);
    vlSelfRef.link_adapter_tx__DOT__crc_reset = ((IData)(vlSelfRef.link_adapter_tx__DOT__reset) 
                                                 | (1U 
                                                    == (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state)));
    vlSelfRef.link_adapter_tx__DOT__curr_L3_packet_size = 0U;
    vlSelfRef.link_adapter_tx__DOT__crc_calc_en = 0U;
    if ((3U == (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state))) {
        vlSelfRef.link_adapter_tx__DOT__curr_L3_packet_size = 0U;
        vlSelfRef.link_adapter_tx__DOT__crc_calc_en 
            = (1U <= (IData)(vlSelfRef.link_adapter_tx__DOT__byte_ctr_shift));
        ++(vlSelf->__Vcoverage[321]);
    } else if ((2U == (IData)(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state))) {
        vlSelfRef.link_adapter_tx__DOT__curr_L3_packet_size 
            = (0x0000ffffU & ((IData)(6U) + ((vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[1U] 
                                              << 8U) 
                                             | (vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data[0U] 
                                                >> 0x00000018U))));
        vlSelfRef.link_adapter_tx__DOT__crc_calc_en = 0U;
        ++(vlSelf->__Vcoverage[322]);
    } else {
        vlSelfRef.link_adapter_tx__DOT__curr_L3_packet_size = 0U;
        vlSelfRef.link_adapter_tx__DOT__crc_calc_en = 0U;
        ++(vlSelf->__Vcoverage[323]);
    }
    ++(vlSelf->__Vcoverage[324]);
    vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_b_w_en 
        = __VdfgRegularize_h6e95ff9d_0_0;
    vlSelfRef.link_adapter_tx__DOT__push_fifo = __VdfgRegularize_h6e95ff9d_0_0;
    if (((IData)(vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_en) 
         ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_buffer_port_a_rd_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 69, vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_en, vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_buffer_port_a_rd_en);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_buffer_port_a_rd_en 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_en;
    }
    if (((IData)(vlSelfRef.link_adapter_tx__DOT__pop_fifo) 
         ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__pop_fifo))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 94, vlSelfRef.link_adapter_tx__DOT__pop_fifo, vlSelfRef.link_adapter_tx__DOT____Vtogcov__pop_fifo);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__pop_fifo 
            = vlSelfRef.link_adapter_tx__DOT__pop_fifo;
    }
    if ((0U != ((IData)(vlSelfRef.link_adapter_tx__DOT__next_link_adapter_state) 
                ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__next_link_adapter_state)))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSelf->__Vcoverage + 30, vlSelfRef.link_adapter_tx__DOT__next_link_adapter_state, vlSelfRef.link_adapter_tx__DOT____Vtogcov__next_link_adapter_state);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__next_link_adapter_state 
            = vlSelfRef.link_adapter_tx__DOT__next_link_adapter_state;
    }
    if (((IData)(vlSelfRef.link_adapter_tx__DOT__crc_reset) 
         ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__crc_reset))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 296, vlSelfRef.link_adapter_tx__DOT__crc_reset, vlSelfRef.link_adapter_tx__DOT____Vtogcov__crc_reset);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__crc_reset 
            = vlSelfRef.link_adapter_tx__DOT__crc_reset;
    }
    if ((0U != ((IData)(vlSelfRef.link_adapter_tx__DOT__curr_L3_packet_size) 
                ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__curr_L3_packet_size)))) {
        VL_COV_TOGGLE_CHG_ST_I(16, vlSelf->__Vcoverage + 166, vlSelfRef.link_adapter_tx__DOT__curr_L3_packet_size, vlSelfRef.link_adapter_tx__DOT____Vtogcov__curr_L3_packet_size);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__curr_L3_packet_size 
            = vlSelfRef.link_adapter_tx__DOT__curr_L3_packet_size;
    }
    if (((IData)(vlSelfRef.link_adapter_tx__DOT__crc_calc_en) 
         ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__crc_calc_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 294, vlSelfRef.link_adapter_tx__DOT__crc_calc_en, vlSelfRef.link_adapter_tx__DOT____Vtogcov__crc_calc_en);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__crc_calc_en 
            = vlSelfRef.link_adapter_tx__DOT__crc_calc_en;
    }
    if (((IData)(vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_b_w_en) 
         ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_buffer_port_b_w_en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 80, vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_b_w_en, vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_buffer_port_b_w_en);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__fifo_ring_buffer_port_b_w_en 
            = vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_b_w_en;
    }
    if (((IData)(vlSelfRef.link_adapter_tx__DOT__push_fifo) 
         ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__push_fifo))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 89, vlSelfRef.link_adapter_tx__DOT__push_fifo, vlSelfRef.link_adapter_tx__DOT____Vtogcov__push_fifo);
        vlSelfRef.link_adapter_tx__DOT____Vtogcov__push_fifo 
            = vlSelfRef.link_adapter_tx__DOT__push_fifo;
    }
}

void Vtop___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                        ((((IData)(vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__clk) 
                                                           & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__link_adapter_tx__DOT__CRC_CALC__DOT__clk__0))) 
                                                          << 1U) 
                                                         | ((IData)(vlSelfRef.link_adapter_tx__DOT__clk) 
                                                            & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__link_adapter_tx__DOT__clk__0))))));
        vlSelfRef.__Vtrigprevexpr___TOP__link_adapter_tx__DOT__clk__0 
            = vlSelfRef.link_adapter_tx__DOT__clk;
        vlSelfRef.__Vtrigprevexpr___TOP__link_adapter_tx__DOT__CRC_CALC__DOT__clk__0 
            = vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__clk;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtop___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vtop___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_nba
            if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
                Vtop___024root___nba_sequent__TOP__0(vlSelf);
            }
            if ((2ULL & vlSelfRef.__VnbaTriggered[0U])) {
                {
                    // Inlined CFunc: _nba_sequent__TOP__1
                    IData/*31:0*/ __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___Vdly__link_adapter_tx__DOT__CRC_CALC__DOT__CRC_REG;
                    __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___Vdly__link_adapter_tx__DOT__CRC_CALC__DOT__CRC_REG = 0;
                    __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___Vdly__link_adapter_tx__DOT__CRC_CALC__DOT__CRC_REG 
                        = vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__CRC_REG;
                    if (vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__reset) {
                        ++(vlSelf->__Vcoverage[430]);
                        __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___Vdly__link_adapter_tx__DOT__CRC_CALC__DOT__CRC_REG = 0xffffffffU;
                    } else if (vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__enable) {
                        __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___Vdly__link_adapter_tx__DOT__CRC_CALC__DOT__CRC_REG 
                            = ((vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__CRC_REG 
                                >> 8U) ^ vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__PRECOMPUTED_CRC
                               [(0x000000ffU & (vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__CRC_REG 
                                                ^ (IData)(vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__message)))]);
                        ++(vlSelf->__Vcoverage[428]);
                    } else {
                        __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___Vdly__link_adapter_tx__DOT__CRC_CALC__DOT__CRC_REG 
                            = vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__CRC_REG;
                        ++(vlSelf->__Vcoverage[429]);
                    }
                    ++(vlSelf->__Vcoverage[431]);
                    vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__CRC_REG 
                        = __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__1___Vdly__link_adapter_tx__DOT__CRC_CALC__DOT__CRC_REG;
                    if ((0U != (vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__CRC_REG 
                                ^ vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__CRC_REG))) {
                        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 363, vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__CRC_REG, vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__CRC_REG);
                        vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__CRC_REG 
                            = vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__CRC_REG;
                    }
                    vlSelfRef.link_adapter_tx__DOT__crc_calc_output 
                        = vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__CRC_REG;
                    if ((0U != (vlSelfRef.link_adapter_tx__DOT__crc_calc_output 
                                ^ vlSelfRef.link_adapter_tx__DOT____Vtogcov__crc_calc_output))) {
                        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 198, vlSelfRef.link_adapter_tx__DOT__crc_calc_output, vlSelfRef.link_adapter_tx__DOT____Vtogcov__crc_calc_output);
                        vlSelfRef.link_adapter_tx__DOT____Vtogcov__crc_calc_output 
                            = vlSelfRef.link_adapter_tx__DOT__crc_calc_output;
                    }
                }
            }
            if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
                {
                    // Inlined CFunc: _nba_sequent__TOP__2
                    vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__reset 
                        = vlSelfRef.link_adapter_tx__DOT__crc_reset;
                    vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__enable 
                        = vlSelfRef.link_adapter_tx__DOT__crc_calc_en;
                    vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__message 
                        = vlSelfRef.link_adapter_tx__DOT__crc_calc_input;
                    if (((IData)(vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__reset) 
                         ^ (IData)(vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__reset))) {
                        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 357, vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__reset, vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__reset);
                        vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__reset 
                            = vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__reset;
                    }
                    if (((IData)(vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__enable) 
                         ^ (IData)(vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__enable))) {
                        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 359, vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__enable, vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__enable);
                        vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__enable 
                            = vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__enable;
                    }
                    if ((0U != ((IData)(vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__message) 
                                ^ (IData)(vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__message)))) {
                        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 341, vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__message, vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__message);
                        vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__message 
                            = vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__message;
                    }
                }
            }
            if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
                {
                    // Inlined CFunc: _nba_comb__TOP__0
                    if ((2U & (IData)(vlSelfRef.link_adapter_tx__DOT__byte_ctr_crc_shift))) {
                        if ((1U & (IData)(vlSelfRef.link_adapter_tx__DOT__byte_ctr_crc_shift))) {
                            vlSelfRef.link_adapter_tx__DOT__crc_byte_output 
                                = (0x000000ffU & (~ 
                                                  (vlSelfRef.link_adapter_tx__DOT__crc_calc_output 
                                                   >> 0x18U)));
                            ++(vlSelf->__Vcoverage[331]);
                        } else {
                            vlSelfRef.link_adapter_tx__DOT__crc_byte_output 
                                = (0x000000ffU & (~ 
                                                  (vlSelfRef.link_adapter_tx__DOT__crc_calc_output 
                                                   >> 0x10U)));
                            ++(vlSelf->__Vcoverage[330]);
                        }
                    } else if ((1U & (IData)(vlSelfRef.link_adapter_tx__DOT__byte_ctr_crc_shift))) {
                        vlSelfRef.link_adapter_tx__DOT__crc_byte_output 
                            = (0x000000ffU & (~ (vlSelfRef.link_adapter_tx__DOT__crc_calc_output 
                                                 >> 8U)));
                        ++(vlSelf->__Vcoverage[329]);
                    } else {
                        vlSelfRef.link_adapter_tx__DOT__crc_byte_output 
                            = (0x000000ffU & (~ vlSelfRef.link_adapter_tx__DOT__crc_calc_output));
                        ++(vlSelf->__Vcoverage[328]);
                    }
                    ++(vlSelf->__Vcoverage[333]);
                    if ((0U != ((IData)(vlSelfRef.link_adapter_tx__DOT__crc_byte_output) 
                                ^ (IData)(vlSelfRef.link_adapter_tx__DOT____Vtogcov__crc_byte_output)))) {
                        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 262, vlSelfRef.link_adapter_tx__DOT__crc_byte_output, vlSelfRef.link_adapter_tx__DOT____Vtogcov__crc_byte_output);
                        vlSelfRef.link_adapter_tx__DOT____Vtogcov__crc_byte_output 
                            = vlSelfRef.link_adapter_tx__DOT__crc_byte_output;
                    }
                }
            }
        }
        Vtop___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("../../RTL/link_adapter_tx.sv", 3, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 10000 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        vlSelfRef.__VicoPhaseResult = Vtop___024root___eval_phase__ico(vlSelf);
        vlSelfRef.__VicoFirstIteration = 0U;
    } while (vlSelfRef.__VicoPhaseResult);
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("../../RTL/link_adapter_tx.sv", 3, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("../../RTL/link_adapter_tx.sv", 3, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactPhaseResult = Vtop___024root___eval_phase__act(vlSelf);
        } while (vlSelfRef.__VactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtop___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.reset & 0xfeU)))) {
        Verilated::overWidthError("reset");
    }
    if (VL_UNLIKELY(((vlSelfRef.packet_valid & 0xfeU)))) {
        Verilated::overWidthError("packet_valid");
    }
}
#endif  // VL_DEBUG
