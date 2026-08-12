// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__link_adapter_tx__DOT__clk__0 
        = vlSelfRef.link_adapter_tx__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__link_adapter_tx__DOT__CRC_CALC__DOT__clk__0 
        = vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__clk;
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_initial__TOP
        CData/*2:0*/ __Vinline_0__eval_initial__TOP___Vfsmcov_prev_link_adapter_tx__DOT__current_link_adapter_state__0;
        __Vinline_0__eval_initial__TOP___Vfsmcov_prev_link_adapter_tx__DOT__current_link_adapter_state__0 = 0;
        __Vinline_0__eval_initial__TOP___Vfsmcov_prev_link_adapter_tx__DOT__current_link_adapter_state__0 
            = vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state;
        VL_READMEM_N(true, 32, 256, 0, "../../utils/CRC_TABLE.mem"s
                     ,  &(vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__PRECOMPUTED_CRC)
                     , 0, ~0ULL);
        ++(vlSelf->__Vcoverage[427]);
    }
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("../../RTL/link_adapter_tx.sv", 3, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vtop___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__stl\n"); );
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

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__stl
        vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                          & vlSelfRef.__VstlTriggered[0U]) 
                                         | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtop___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_stl
            if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
                Vtop___024root___ico_sequent__TOP__0(vlSelf);
            }
        }
    }
    return (__VstlExecute);
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge link_adapter_tx.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge link_adapter_tx.CRC_CALC.clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9928399931838511862ull);
    VL_SCOPED_RAND_RESET_W(2048, vlSelf->tx_packet, __VscopeHash, 14143953429914395052ull);
    vlSelf->packet_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11199598501789723583ull);
    vlSelf->packet_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5186237060029080834ull);
    vlSelf->OSERDES_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16554979592166927230ull);
    vlSelf->link_adapter_tx__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9099824208271854920ull);
    vlSelf->link_adapter_tx__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1234958678529255164ull);
    VL_SCOPED_RAND_RESET_W(2048, vlSelf->link_adapter_tx__DOT__tx_packet, __VscopeHash, 13413046899960622010ull);
    vlSelf->link_adapter_tx__DOT__packet_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4671982801677147935ull);
    vlSelf->link_adapter_tx__DOT__packet_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17986767487653472780ull);
    vlSelf->link_adapter_tx__DOT__OSERDES_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1306614498066071868ull);
    vlSelf->link_adapter_tx__DOT__current_link_adapter_state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3296175908876219472ull);
    vlSelf->link_adapter_tx__DOT__next_link_adapter_state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 8801619499182121236ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(2048, vlSelf->link_adapter_tx__DOT__fifo_ring_buffer[__Vi0], __VscopeHash, 12521797851964654415ull);
    }
    vlSelf->link_adapter_tx__DOT__fifo_ring_write_ptr = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5296300183368269314ull);
    vlSelf->link_adapter_tx__DOT__fifo_ring_top_ptr = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 11750374356436772852ull);
    vlSelf->link_adapter_tx__DOT__fifo_ring_size = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13811842521953607244ull);
    vlSelf->link_adapter_tx__DOT__fifo_full = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11846067980309462676ull);
    vlSelf->link_adapter_tx__DOT__fifo_empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13818600492523991630ull);
    vlSelf->link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 12400522556315746218ull);
    vlSelf->link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16151814944112590984ull);
    VL_SCOPED_RAND_RESET_W(2048, vlSelf->link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data, __VscopeHash, 9587121825352063958ull);
    vlSelf->link_adapter_tx__DOT__fifo_ring_buffer_port_b_addr = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1216715759967206321ull);
    vlSelf->link_adapter_tx__DOT__fifo_ring_buffer_port_b_w_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10300406630202729711ull);
    VL_SCOPED_RAND_RESET_W(2048, vlSelf->link_adapter_tx__DOT__fifo_ring_buffer_port_b_w_data, __VscopeHash, 18442634651185368346ull);
    vlSelf->link_adapter_tx__DOT__push_fifo = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8077548746396433549ull);
    vlSelf->link_adapter_tx__DOT__pop_fifo = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2721033744591052377ull);
    VL_SCOPED_RAND_RESET_W(2080, vlSelf->link_adapter_tx__DOT__L2_frame_shift_reg, __VscopeHash, 10158811886928330337ull);
    vlSelf->link_adapter_tx__DOT__byte_ctr_shift = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 2893539037984802754ull);
    vlSelf->link_adapter_tx__DOT__byte_ctr_crc_shift = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12418460045986292111ull);
    vlSelf->link_adapter_tx__DOT__latched_L3_packet_size = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3389066307089226750ull);
    vlSelf->link_adapter_tx__DOT__curr_L3_packet_size = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15829067497130129717ull);
    vlSelf->link_adapter_tx__DOT__crc_calc_output = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1234019034220017195ull);
    vlSelf->link_adapter_tx__DOT__crc_byte_output = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15269187837062713487ull);
    vlSelf->link_adapter_tx__DOT__crc_calc_input = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6161829957017412008ull);
    vlSelf->link_adapter_tx__DOT__crc_calc_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11290260113077332393ull);
    vlSelf->link_adapter_tx__DOT__crc_reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7243925424649234034ull);
    vlSelf->link_adapter_tx__DOT____Vtogcov__clk = 0;
    vlSelf->link_adapter_tx__DOT____Vtogcov__reset = 0;
    vlSelf->link_adapter_tx__DOT____Vtogcov__packet_valid = 0;
    vlSelf->link_adapter_tx__DOT____Vtogcov__packet_ready = 0;
    vlSelf->link_adapter_tx__DOT____Vtogcov__OSERDES_out = 0;
    vlSelf->link_adapter_tx__DOT____Vtogcov__current_link_adapter_state = 0;
    vlSelf->link_adapter_tx__DOT____Vtogcov__next_link_adapter_state = 0;
    vlSelf->link_adapter_tx__DOT____Vtogcov__fifo_ring_write_ptr = 0;
    vlSelf->link_adapter_tx__DOT____Vtogcov__fifo_ring_top_ptr = 0;
    vlSelf->link_adapter_tx__DOT____Vtogcov__fifo_ring_size = 0;
    vlSelf->link_adapter_tx__DOT____Vtogcov__fifo_full = 0;
    vlSelf->link_adapter_tx__DOT____Vtogcov__fifo_empty = 0;
    vlSelf->link_adapter_tx__DOT____Vtogcov__fifo_ring_buffer_port_a_addr = 0;
    vlSelf->link_adapter_tx__DOT____Vtogcov__fifo_ring_buffer_port_a_rd_en = 0;
    vlSelf->link_adapter_tx__DOT____Vtogcov__fifo_ring_buffer_port_b_addr = 0;
    vlSelf->link_adapter_tx__DOT____Vtogcov__fifo_ring_buffer_port_b_w_en = 0;
    vlSelf->link_adapter_tx__DOT____Vtogcov__push_fifo = 0;
    vlSelf->link_adapter_tx__DOT____Vtogcov__pop_fifo = 0;
    vlSelf->link_adapter_tx__DOT____Vtogcov__byte_ctr_shift = 0;
    vlSelf->link_adapter_tx__DOT____Vtogcov__byte_ctr_crc_shift = 0;
    vlSelf->link_adapter_tx__DOT____Vtogcov__latched_L3_packet_size = 0;
    vlSelf->link_adapter_tx__DOT____Vtogcov__curr_L3_packet_size = 0;
    vlSelf->link_adapter_tx__DOT____Vtogcov__crc_calc_output = 0;
    vlSelf->link_adapter_tx__DOT____Vtogcov__crc_byte_output = 0;
    vlSelf->link_adapter_tx__DOT____Vtogcov__crc_calc_input = 0;
    vlSelf->link_adapter_tx__DOT____Vtogcov__crc_calc_en = 0;
    vlSelf->link_adapter_tx__DOT____Vtogcov__crc_reset = 0;
    vlSelf->link_adapter_tx__DOT__CRC_CALC__DOT__message = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8933300971793638336ull);
    vlSelf->link_adapter_tx__DOT__CRC_CALC__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7468255391376528846ull);
    vlSelf->link_adapter_tx__DOT__CRC_CALC__DOT__enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13791397067362533441ull);
    vlSelf->link_adapter_tx__DOT__CRC_CALC__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 129392170732473912ull);
    vlSelf->link_adapter_tx__DOT__CRC_CALC__DOT__CRC_REG = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8467451604440226846ull);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->link_adapter_tx__DOT__CRC_CALC__DOT__PRECOMPUTED_CRC[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3059396277588485658ull);
    }
    vlSelf->link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__message = 0;
    vlSelf->link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__reset = 0;
    vlSelf->link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__enable = 0;
    vlSelf->link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__clk = 0;
    vlSelf->link_adapter_tx__DOT__CRC_CALC__DOT____Vtogcov__CRC_REG = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__link_adapter_tx__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__link_adapter_tx__DOT__CRC_CALC__DOT__clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}

VL_ATTR_COLD void Vtop___024root___configure_coverage(Vtop___024root* vlSelf, bool first) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___configure_coverage\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    (void)first;  // Prevent unused variable warning
    vlSelf->__vlCoverToggleInsert(0, 0, 0, vlSelf->__Vcoverage + 0, first, true, "../../RTL/link_adapter_tx.sv", 6, 20, ".link_adapter_tx", "v_toggle/link_adapter_tx", "clk");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, vlSelf->__Vcoverage + 2, first, true, "../../RTL/link_adapter_tx.sv", 7, 20, ".link_adapter_tx", "v_toggle/link_adapter_tx", "reset");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, vlSelf->__Vcoverage + 4, first, true, "../../RTL/link_adapter_tx.sv", 9, 20, ".link_adapter_tx", "v_toggle/link_adapter_tx", "packet_valid");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, vlSelf->__Vcoverage + 6, first, true, "../../RTL/link_adapter_tx.sv", 10, 22, ".link_adapter_tx", "v_toggle/link_adapter_tx", "packet_ready");
    vlSelf->__vlCoverToggleInsert(0, 7, 1, vlSelf->__Vcoverage + 8, first, true, "../../RTL/link_adapter_tx.sv", 11, 26, ".link_adapter_tx", "v_toggle/link_adapter_tx", "OSERDES_out");
    vlSelf->__vlCoverToggleInsert(0, 2, 1, vlSelf->__Vcoverage + 24, first, true, "../../RTL/link_adapter_tx.sv", 14, 31, ".link_adapter_tx", "v_toggle/link_adapter_tx", "current_link_adapter_state");
    vlSelf->__vlCoverToggleInsert(0, 2, 1, vlSelf->__Vcoverage + 30, first, true, "../../RTL/link_adapter_tx.sv", 14, 59, ".link_adapter_tx", "v_toggle/link_adapter_tx", "next_link_adapter_state");
    vlSelf->__vlCoverToggleInsert(0, 2, 1, vlSelf->__Vcoverage + 36, first, true, "../../RTL/link_adapter_tx.sv", 21, 36, ".link_adapter_tx", "v_toggle/link_adapter_tx", "fifo_ring_write_ptr");
    vlSelf->__vlCoverToggleInsert(0, 2, 1, vlSelf->__Vcoverage + 42, first, true, "../../RTL/link_adapter_tx.sv", 21, 57, ".link_adapter_tx", "v_toggle/link_adapter_tx", "fifo_ring_top_ptr");
    vlSelf->__vlCoverToggleInsert(0, 3, 1, vlSelf->__Vcoverage + 48, first, true, "../../RTL/link_adapter_tx.sv", 22, 34, ".link_adapter_tx", "v_toggle/link_adapter_tx", "fifo_ring_size");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, vlSelf->__Vcoverage + 56, first, true, "../../RTL/link_adapter_tx.sv", 23, 10, ".link_adapter_tx", "v_toggle/link_adapter_tx", "fifo_full");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, vlSelf->__Vcoverage + 58, first, true, "../../RTL/link_adapter_tx.sv", 24, 10, ".link_adapter_tx", "v_toggle/link_adapter_tx", "fifo_empty");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 60, first, true, "../../RTL/link_adapter_tx.sv", 25, 38, ".link_adapter_tx", "v_expr/link_adapter_tx", "(fifo_full==0 && reset==0) => 1", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 60, first, false, "../../RTL/link_adapter_tx.sv", 25, 38, ".link_adapter_tx", "v_expr/link_adapter_tx", "(fifo_full==0 && reset==0) => 1", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 61, first, true, "../../RTL/link_adapter_tx.sv", 25, 38, ".link_adapter_tx", "v_expr/link_adapter_tx", "(reset==1) => 0", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 61, first, false, "../../RTL/link_adapter_tx.sv", 25, 38, ".link_adapter_tx", "v_expr/link_adapter_tx", "(reset==1) => 0", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 62, first, true, "../../RTL/link_adapter_tx.sv", 25, 38, ".link_adapter_tx", "v_expr/link_adapter_tx", "(fifo_full==1) => 0", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 62, first, false, "../../RTL/link_adapter_tx.sv", 25, 38, ".link_adapter_tx", "v_expr/link_adapter_tx", "(fifo_full==1) => 0", "", "", "", "", "");
    vlSelf->__vlCoverToggleInsert(0, 2, 1, vlSelf->__Vcoverage + 63, first, true, "../../RTL/link_adapter_tx.sv", 29, 36, ".link_adapter_tx", "v_toggle/link_adapter_tx", "fifo_ring_buffer_port_a_addr");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, vlSelf->__Vcoverage + 69, first, true, "../../RTL/link_adapter_tx.sv", 30, 9, ".link_adapter_tx", "v_toggle/link_adapter_tx", "fifo_ring_buffer_port_a_rd_en");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 71, first, true, "../../RTL/link_adapter_tx.sv", 33, 9, ".link_adapter_tx", "v_branch/link_adapter_tx", "if", "33-34", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 71, first, false, "../../RTL/link_adapter_tx.sv", 33, 9, ".link_adapter_tx", "v_branch/link_adapter_tx", "if", "33-34", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 72, first, true, "../../RTL/link_adapter_tx.sv", 33, 10, ".link_adapter_tx", "v_branch/link_adapter_tx", "else", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 72, first, false, "../../RTL/link_adapter_tx.sv", 33, 10, ".link_adapter_tx", "v_branch/link_adapter_tx", "else", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 73, first, true, "../../RTL/link_adapter_tx.sv", 32, 5, ".link_adapter_tx", "v_line/link_adapter_tx", "block", "32", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 73, first, false, "../../RTL/link_adapter_tx.sv", 32, 5, ".link_adapter_tx", "v_line/link_adapter_tx", "block", "32", "", "", "", "");
    vlSelf->__vlCoverToggleInsert(0, 2, 1, vlSelf->__Vcoverage + 74, first, true, "../../RTL/link_adapter_tx.sv", 39, 37, ".link_adapter_tx", "v_toggle/link_adapter_tx", "fifo_ring_buffer_port_b_addr");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, vlSelf->__Vcoverage + 80, first, true, "../../RTL/link_adapter_tx.sv", 40, 9, ".link_adapter_tx", "v_toggle/link_adapter_tx", "fifo_ring_buffer_port_b_w_en");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 82, first, true, "../../RTL/link_adapter_tx.sv", 43, 9, ".link_adapter_tx", "v_branch/link_adapter_tx", "if", "43-44", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 82, first, false, "../../RTL/link_adapter_tx.sv", 43, 9, ".link_adapter_tx", "v_branch/link_adapter_tx", "if", "43-44", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 83, first, true, "../../RTL/link_adapter_tx.sv", 43, 10, ".link_adapter_tx", "v_branch/link_adapter_tx", "else", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 83, first, false, "../../RTL/link_adapter_tx.sv", 43, 10, ".link_adapter_tx", "v_branch/link_adapter_tx", "else", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 84, first, true, "../../RTL/link_adapter_tx.sv", 42, 5, ".link_adapter_tx", "v_line/link_adapter_tx", "block", "42", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 84, first, false, "../../RTL/link_adapter_tx.sv", 42, 5, ".link_adapter_tx", "v_line/link_adapter_tx", "block", "42", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 85, first, true, "../../RTL/link_adapter_tx.sv", 54, 53, ".link_adapter_tx", "v_expr/link_adapter_tx", "(packet_valid==1 && packet_ready==1) => 1", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 85, first, false, "../../RTL/link_adapter_tx.sv", 54, 53, ".link_adapter_tx", "v_expr/link_adapter_tx", "(packet_valid==1 && packet_ready==1) => 1", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 86, first, true, "../../RTL/link_adapter_tx.sv", 54, 53, ".link_adapter_tx", "v_expr/link_adapter_tx", "(packet_ready==0) => 0", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 86, first, false, "../../RTL/link_adapter_tx.sv", 54, 53, ".link_adapter_tx", "v_expr/link_adapter_tx", "(packet_ready==0) => 0", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 87, first, true, "../../RTL/link_adapter_tx.sv", 54, 53, ".link_adapter_tx", "v_expr/link_adapter_tx", "(packet_valid==0) => 0", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 87, first, false, "../../RTL/link_adapter_tx.sv", 54, 53, ".link_adapter_tx", "v_expr/link_adapter_tx", "(packet_valid==0) => 0", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 88, first, true, "../../RTL/link_adapter_tx.sv", 49, 5, ".link_adapter_tx", "v_line/link_adapter_tx", "block", "49-54", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 88, first, false, "../../RTL/link_adapter_tx.sv", 49, 5, ".link_adapter_tx", "v_line/link_adapter_tx", "block", "49-54", "", "", "", "");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, vlSelf->__Vcoverage + 89, first, true, "../../RTL/link_adapter_tx.sv", 58, 10, ".link_adapter_tx", "v_toggle/link_adapter_tx", "push_fifo");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 91, first, true, "../../RTL/link_adapter_tx.sv", 58, 35, ".link_adapter_tx", "v_expr/link_adapter_tx", "(packet_valid==1 && packet_ready==1) => 1", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 91, first, false, "../../RTL/link_adapter_tx.sv", 58, 35, ".link_adapter_tx", "v_expr/link_adapter_tx", "(packet_valid==1 && packet_ready==1) => 1", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 92, first, true, "../../RTL/link_adapter_tx.sv", 58, 35, ".link_adapter_tx", "v_expr/link_adapter_tx", "(packet_ready==0) => 0", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 92, first, false, "../../RTL/link_adapter_tx.sv", 58, 35, ".link_adapter_tx", "v_expr/link_adapter_tx", "(packet_ready==0) => 0", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 93, first, true, "../../RTL/link_adapter_tx.sv", 58, 35, ".link_adapter_tx", "v_expr/link_adapter_tx", "(packet_valid==0) => 0", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 93, first, false, "../../RTL/link_adapter_tx.sv", 58, 35, ".link_adapter_tx", "v_expr/link_adapter_tx", "(packet_valid==0) => 0", "", "", "", "", "");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, vlSelf->__Vcoverage + 94, first, true, "../../RTL/link_adapter_tx.sv", 59, 10, ".link_adapter_tx", "v_toggle/link_adapter_tx", "pop_fifo");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 96, first, true, "../../RTL/link_adapter_tx.sv", 67, 17, ".link_adapter_tx", "v_branch/link_adapter_tx", "if", "67-68", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 96, first, false, "../../RTL/link_adapter_tx.sv", 67, 17, ".link_adapter_tx", "v_branch/link_adapter_tx", "if", "67-68", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 97, first, true, "../../RTL/link_adapter_tx.sv", 67, 18, ".link_adapter_tx", "v_branch/link_adapter_tx", "else", "69-70", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 97, first, false, "../../RTL/link_adapter_tx.sv", 67, 18, ".link_adapter_tx", "v_branch/link_adapter_tx", "else", "69-70", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 98, first, true, "../../RTL/link_adapter_tx.sv", 66, 13, ".link_adapter_tx", "v_branch/link_adapter_tx", "if", "66", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 98, first, false, "../../RTL/link_adapter_tx.sv", 66, 13, ".link_adapter_tx", "v_branch/link_adapter_tx", "if", "66", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 99, first, true, "../../RTL/link_adapter_tx.sv", 66, 14, ".link_adapter_tx", "v_branch/link_adapter_tx", "else", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 99, first, false, "../../RTL/link_adapter_tx.sv", 66, 14, ".link_adapter_tx", "v_branch/link_adapter_tx", "else", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 100, first, true, "../../RTL/link_adapter_tx.sv", 74, 17, ".link_adapter_tx", "v_branch/link_adapter_tx", "if", "74-75", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 100, first, false, "../../RTL/link_adapter_tx.sv", 74, 17, ".link_adapter_tx", "v_branch/link_adapter_tx", "if", "74-75", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 101, first, true, "../../RTL/link_adapter_tx.sv", 74, 18, ".link_adapter_tx", "v_branch/link_adapter_tx", "else", "76-77", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 101, first, false, "../../RTL/link_adapter_tx.sv", 74, 18, ".link_adapter_tx", "v_branch/link_adapter_tx", "else", "76-77", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 102, first, true, "../../RTL/link_adapter_tx.sv", 73, 13, ".link_adapter_tx", "v_branch/link_adapter_tx", "if", "73", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 102, first, false, "../../RTL/link_adapter_tx.sv", 73, 13, ".link_adapter_tx", "v_branch/link_adapter_tx", "if", "73", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 103, first, true, "../../RTL/link_adapter_tx.sv", 73, 14, ".link_adapter_tx", "v_branch/link_adapter_tx", "else", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 103, first, false, "../../RTL/link_adapter_tx.sv", 73, 14, ".link_adapter_tx", "v_branch/link_adapter_tx", "else", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 104, first, true, "../../RTL/link_adapter_tx.sv", 81, 22, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "81", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 104, first, false, "../../RTL/link_adapter_tx.sv", 81, 22, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "81", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 105, first, true, "../../RTL/link_adapter_tx.sv", 82, 22, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "82", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 105, first, false, "../../RTL/link_adapter_tx.sv", 82, 22, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "82", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 106, first, true, "../../RTL/link_adapter_tx.sv", 83, 22, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "83", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 106, first, false, "../../RTL/link_adapter_tx.sv", 83, 22, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "83", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 107, first, true, "../../RTL/link_adapter_tx.sv", 84, 22, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "84", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 107, first, false, "../../RTL/link_adapter_tx.sv", 84, 22, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "84", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 108, first, true, "../../RTL/link_adapter_tx.sv", 85, 17, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "85", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 108, first, false, "../../RTL/link_adapter_tx.sv", 85, 17, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "85", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 109, first, true, "../../RTL/link_adapter_tx.sv", 61, 9, ".link_adapter_tx", "v_branch/link_adapter_tx", "if", "61-64", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 109, first, false, "../../RTL/link_adapter_tx.sv", 61, 9, ".link_adapter_tx", "v_branch/link_adapter_tx", "if", "61-64", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 110, first, true, "../../RTL/link_adapter_tx.sv", 61, 10, ".link_adapter_tx", "v_branch/link_adapter_tx", "else", "65,80", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 110, first, false, "../../RTL/link_adapter_tx.sv", 61, 10, ".link_adapter_tx", "v_branch/link_adapter_tx", "else", "65,80", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 111, first, true, "../../RTL/link_adapter_tx.sv", 60, 5, ".link_adapter_tx", "v_line/link_adapter_tx", "block", "60", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 111, first, false, "../../RTL/link_adapter_tx.sv", 60, 5, ".link_adapter_tx", "v_line/link_adapter_tx", "block", "60", "", "", "", "");
    vlSelf->__vlCoverToggleInsert(0, 8, 1, vlSelf->__Vcoverage + 112, first, true, "../../RTL/link_adapter_tx.sv", 93, 15, ".link_adapter_tx", "v_toggle/link_adapter_tx", "byte_ctr_shift");
    vlSelf->__vlCoverToggleInsert(0, 1, 1, vlSelf->__Vcoverage + 130, first, true, "../../RTL/link_adapter_tx.sv", 94, 15, ".link_adapter_tx", "v_toggle/link_adapter_tx", "byte_ctr_crc_shift");
    vlSelf->__vlCoverToggleInsert(0, 15, 1, vlSelf->__Vcoverage + 134, first, true, "../../RTL/link_adapter_tx.sv", 95, 51, ".link_adapter_tx", "v_toggle/link_adapter_tx", "latched_L3_packet_size");
    vlSelf->__vlCoverToggleInsert(0, 15, 1, vlSelf->__Vcoverage + 166, first, true, "../../RTL/link_adapter_tx.sv", 96, 51, ".link_adapter_tx", "v_toggle/link_adapter_tx", "curr_L3_packet_size");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, vlSelf->__Vcoverage + 198, first, true, "../../RTL/link_adapter_tx.sv", 97, 41, ".link_adapter_tx", "v_toggle/link_adapter_tx", "crc_calc_output");
    vlSelf->__vlCoverToggleInsert(0, 7, 1, vlSelf->__Vcoverage + 262, first, true, "../../RTL/link_adapter_tx.sv", 98, 15, ".link_adapter_tx", "v_toggle/link_adapter_tx", "crc_byte_output");
    vlSelf->__vlCoverToggleInsert(0, 7, 1, vlSelf->__Vcoverage + 278, first, true, "../../RTL/link_adapter_tx.sv", 99, 16, ".link_adapter_tx", "v_toggle/link_adapter_tx", "crc_calc_input");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, vlSelf->__Vcoverage + 294, first, true, "../../RTL/link_adapter_tx.sv", 100, 9, ".link_adapter_tx", "v_toggle/link_adapter_tx", "crc_calc_en");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, vlSelf->__Vcoverage + 296, first, true, "../../RTL/link_adapter_tx.sv", 101, 10, ".link_adapter_tx", "v_toggle/link_adapter_tx", "crc_reset");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 298, first, true, "../../RTL/link_adapter_tx.sv", 101, 28, ".link_adapter_tx", "v_expr/link_adapter_tx", "((current_link_adapter_state == FETCH)==1) => 1", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 298, first, false, "../../RTL/link_adapter_tx.sv", 101, 28, ".link_adapter_tx", "v_expr/link_adapter_tx", "((current_link_adapter_state == FETCH)==1) => 1", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 299, first, true, "../../RTL/link_adapter_tx.sv", 101, 28, ".link_adapter_tx", "v_expr/link_adapter_tx", "(reset==1) => 1", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 299, first, false, "../../RTL/link_adapter_tx.sv", 101, 28, ".link_adapter_tx", "v_expr/link_adapter_tx", "(reset==1) => 1", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 300, first, true, "../../RTL/link_adapter_tx.sv", 101, 28, ".link_adapter_tx", "v_expr/link_adapter_tx", "(reset==0 && (current_link_adapter_state == FETCH)==0) => 0", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 300, first, false, "../../RTL/link_adapter_tx.sv", 101, 28, ".link_adapter_tx", "v_expr/link_adapter_tx", "(reset==0 && (current_link_adapter_state == FETCH)==0) => 0", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 301, first, true, "../../RTL/link_adapter_tx.sv", 115, 17, ".link_adapter_tx", "v_branch/link_adapter_tx", "if", "115-116", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 301, first, false, "../../RTL/link_adapter_tx.sv", 115, 17, ".link_adapter_tx", "v_branch/link_adapter_tx", "if", "115-116", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 302, first, true, "../../RTL/link_adapter_tx.sv", 115, 18, ".link_adapter_tx", "v_branch/link_adapter_tx", "else", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 302, first, false, "../../RTL/link_adapter_tx.sv", 115, 18, ".link_adapter_tx", "v_branch/link_adapter_tx", "else", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 303, first, true, "../../RTL/link_adapter_tx.sv", 115, 27, ".link_adapter_tx", "v_expr/link_adapter_tx", "(reset==0 && fifo_empty==0) => 1", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 303, first, false, "../../RTL/link_adapter_tx.sv", 115, 27, ".link_adapter_tx", "v_expr/link_adapter_tx", "(reset==0 && fifo_empty==0) => 1", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 304, first, true, "../../RTL/link_adapter_tx.sv", 115, 27, ".link_adapter_tx", "v_expr/link_adapter_tx", "(fifo_empty==1) => 0", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 304, first, false, "../../RTL/link_adapter_tx.sv", 115, 27, ".link_adapter_tx", "v_expr/link_adapter_tx", "(fifo_empty==1) => 0", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 305, first, true, "../../RTL/link_adapter_tx.sv", 115, 27, ".link_adapter_tx", "v_expr/link_adapter_tx", "(reset==1) => 0", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 305, first, false, "../../RTL/link_adapter_tx.sv", 115, 27, ".link_adapter_tx", "v_expr/link_adapter_tx", "(reset==1) => 0", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 306, first, true, "../../RTL/link_adapter_tx.sv", 114, 18, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "114", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 306, first, false, "../../RTL/link_adapter_tx.sv", 114, 18, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "114", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 307, first, true, "../../RTL/link_adapter_tx.sv", 119, 18, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "119-120", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 307, first, false, "../../RTL/link_adapter_tx.sv", 119, 18, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "119-120", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 308, first, true, "../../RTL/link_adapter_tx.sv", 122, 21, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "122-123", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 308, first, false, "../../RTL/link_adapter_tx.sv", 122, 21, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "122-123", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 309, first, true, "../../RTL/link_adapter_tx.sv", 126, 17, ".link_adapter_tx", "v_branch/link_adapter_tx", "if", "126,130-131", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 309, first, false, "../../RTL/link_adapter_tx.sv", 126, 17, ".link_adapter_tx", "v_branch/link_adapter_tx", "if", "126,130-131", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 310, first, true, "../../RTL/link_adapter_tx.sv", 126, 18, ".link_adapter_tx", "v_branch/link_adapter_tx", "else", "132-133", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 310, first, false, "../../RTL/link_adapter_tx.sv", 126, 18, ".link_adapter_tx", "v_branch/link_adapter_tx", "else", "132-133", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 311, first, true, "../../RTL/link_adapter_tx.sv", 125, 18, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "125", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 311, first, false, "../../RTL/link_adapter_tx.sv", 125, 18, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "125", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 312, first, true, "../../RTL/link_adapter_tx.sv", 138, 21, ".link_adapter_tx", "v_branch/link_adapter_tx", "if", "138-139", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 312, first, false, "../../RTL/link_adapter_tx.sv", 138, 21, ".link_adapter_tx", "v_branch/link_adapter_tx", "if", "138-139", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 313, first, true, "../../RTL/link_adapter_tx.sv", 138, 22, ".link_adapter_tx", "v_branch/link_adapter_tx", "else", "140-141", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 313, first, false, "../../RTL/link_adapter_tx.sv", 138, 22, ".link_adapter_tx", "v_branch/link_adapter_tx", "else", "140-141", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 314, first, true, "../../RTL/link_adapter_tx.sv", 138, 24, ".link_adapter_tx", "v_expr/link_adapter_tx", "(fifo_empty==0) => 1", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 314, first, false, "../../RTL/link_adapter_tx.sv", 138, 24, ".link_adapter_tx", "v_expr/link_adapter_tx", "(fifo_empty==0) => 1", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 315, first, true, "../../RTL/link_adapter_tx.sv", 138, 24, ".link_adapter_tx", "v_expr/link_adapter_tx", "(fifo_empty==1) => 0", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 315, first, false, "../../RTL/link_adapter_tx.sv", 138, 24, ".link_adapter_tx", "v_expr/link_adapter_tx", "(fifo_empty==1) => 0", "", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 316, first, true, "../../RTL/link_adapter_tx.sv", 137, 17, ".link_adapter_tx", "v_branch/link_adapter_tx", "if", "137", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 316, first, false, "../../RTL/link_adapter_tx.sv", 137, 17, ".link_adapter_tx", "v_branch/link_adapter_tx", "if", "137", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 317, first, true, "../../RTL/link_adapter_tx.sv", 137, 18, ".link_adapter_tx", "v_branch/link_adapter_tx", "else", "143-144", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 317, first, false, "../../RTL/link_adapter_tx.sv", 137, 18, ".link_adapter_tx", "v_branch/link_adapter_tx", "else", "143-144", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 318, first, true, "../../RTL/link_adapter_tx.sv", 136, 22, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "136", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 318, first, false, "../../RTL/link_adapter_tx.sv", 136, 22, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "136", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 319, first, true, "../../RTL/link_adapter_tx.sv", 147, 13, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "147-148", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 319, first, false, "../../RTL/link_adapter_tx.sv", 147, 13, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "147-148", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 320, first, true, "../../RTL/link_adapter_tx.sv", 111, 5, ".link_adapter_tx", "v_line/link_adapter_tx", "block", "111-113", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 320, first, false, "../../RTL/link_adapter_tx.sv", 111, 5, ".link_adapter_tx", "v_line/link_adapter_tx", "block", "111-113", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 321, first, true, "../../RTL/link_adapter_tx.sv", 158, 18, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "158-160", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 321, first, false, "../../RTL/link_adapter_tx.sv", 158, 18, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "158-160", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 322, first, true, "../../RTL/link_adapter_tx.sv", 162, 21, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "162-166", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 322, first, false, "../../RTL/link_adapter_tx.sv", 162, 21, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "162-166", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 323, first, true, "../../RTL/link_adapter_tx.sv", 168, 13, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "168-170", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 323, first, false, "../../RTL/link_adapter_tx.sv", 168, 13, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "168-170", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 324, first, true, "../../RTL/link_adapter_tx.sv", 154, 5, ".link_adapter_tx", "v_line/link_adapter_tx", "block", "154-157", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 324, first, false, "../../RTL/link_adapter_tx.sv", 154, 5, ".link_adapter_tx", "v_line/link_adapter_tx", "block", "154-157", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 325, first, true, "../../RTL/link_adapter_tx.sv", 177, 9, ".link_adapter_tx", "v_branch/link_adapter_tx", "if", "177-178", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 325, first, false, "../../RTL/link_adapter_tx.sv", 177, 9, ".link_adapter_tx", "v_branch/link_adapter_tx", "if", "177-178", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 326, first, true, "../../RTL/link_adapter_tx.sv", 177, 10, ".link_adapter_tx", "v_branch/link_adapter_tx", "else", "179-180", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 326, first, false, "../../RTL/link_adapter_tx.sv", 177, 10, ".link_adapter_tx", "v_branch/link_adapter_tx", "else", "179-180", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 327, first, true, "../../RTL/link_adapter_tx.sv", 176, 5, ".link_adapter_tx", "v_line/link_adapter_tx", "block", "176", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 327, first, false, "../../RTL/link_adapter_tx.sv", 176, 5, ".link_adapter_tx", "v_line/link_adapter_tx", "block", "176", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 328, first, true, "../../RTL/link_adapter_tx.sv", 187, 17, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "187", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 328, first, false, "../../RTL/link_adapter_tx.sv", 187, 17, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "187", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 329, first, true, "../../RTL/link_adapter_tx.sv", 188, 17, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "188", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 329, first, false, "../../RTL/link_adapter_tx.sv", 188, 17, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "188", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 330, first, true, "../../RTL/link_adapter_tx.sv", 189, 17, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "189", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 330, first, false, "../../RTL/link_adapter_tx.sv", 189, 17, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "189", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 331, first, true, "../../RTL/link_adapter_tx.sv", 190, 17, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "190", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 331, first, false, "../../RTL/link_adapter_tx.sv", 190, 17, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "190", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 332, first, true, "../../RTL/link_adapter_tx.sv", 191, 13, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "191", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 332, first, false, "../../RTL/link_adapter_tx.sv", 191, 13, ".link_adapter_tx", "v_line/link_adapter_tx", "case", "191", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 333, first, true, "../../RTL/link_adapter_tx.sv", 185, 5, ".link_adapter_tx", "v_line/link_adapter_tx", "block", "185-186", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 333, first, false, "../../RTL/link_adapter_tx.sv", 185, 5, ".link_adapter_tx", "v_line/link_adapter_tx", "block", "185-186", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 334, first, true, "../../RTL/link_adapter_tx.sv", 228, 18, ".link_adapter_tx", "v_line/link_adapter_tx", "if", "228-230", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 334, first, false, "../../RTL/link_adapter_tx.sv", 228, 18, ".link_adapter_tx", "v_line/link_adapter_tx", "if", "228-230", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 335, first, true, "../../RTL/link_adapter_tx.sv", 228, 19, ".link_adapter_tx", "v_line/link_adapter_tx", "else", "232-235,237-238", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 335, first, false, "../../RTL/link_adapter_tx.sv", 228, 19, ".link_adapter_tx", "v_line/link_adapter_tx", "else", "232-235,237-238", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 336, first, true, "../../RTL/link_adapter_tx.sv", 223, 18, ".link_adapter_tx", "v_line/link_adapter_tx", "elsif", "223-226", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 336, first, false, "../../RTL/link_adapter_tx.sv", 223, 18, ".link_adapter_tx", "v_line/link_adapter_tx", "elsif", "223-226", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 337, first, true, "../../RTL/link_adapter_tx.sv", 211, 18, ".link_adapter_tx", "v_line/link_adapter_tx", "elsif", "211-216,218-221", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 337, first, false, "../../RTL/link_adapter_tx.sv", 211, 18, ".link_adapter_tx", "v_line/link_adapter_tx", "elsif", "211-216,218-221", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 338, first, true, "../../RTL/link_adapter_tx.sv", 204, 18, ".link_adapter_tx", "v_line/link_adapter_tx", "elsif", "204-207,209-210", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 338, first, false, "../../RTL/link_adapter_tx.sv", 204, 18, ".link_adapter_tx", "v_line/link_adapter_tx", "elsif", "204-207,209-210", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 339, first, true, "../../RTL/link_adapter_tx.sv", 197, 9, ".link_adapter_tx", "v_line/link_adapter_tx", "elsif", "197-200,202-203", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 339, first, false, "../../RTL/link_adapter_tx.sv", 197, 9, ".link_adapter_tx", "v_line/link_adapter_tx", "elsif", "197-200,202-203", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 340, first, true, "../../RTL/link_adapter_tx.sv", 196, 5, ".link_adapter_tx", "v_line/link_adapter_tx", "block", "196", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 340, first, false, "../../RTL/link_adapter_tx.sv", 196, 5, ".link_adapter_tx", "v_line/link_adapter_tx", "block", "196", "", "", "", "");
    vlSelf->__vlCoverToggleInsert(0, 7, 1, vlSelf->__Vcoverage + 341, first, true, "../../RTL/CRC.sv", 4, 41, ".link_adapter_tx.CRC_CALC", "v_toggle/CRC", "message");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, vlSelf->__Vcoverage + 357, first, true, "../../RTL/CRC.sv", 5, 11, ".link_adapter_tx.CRC_CALC", "v_toggle/CRC", "reset");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, vlSelf->__Vcoverage + 359, first, true, "../../RTL/CRC.sv", 6, 11, ".link_adapter_tx.CRC_CALC", "v_toggle/CRC", "enable");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, vlSelf->__Vcoverage + 361, first, true, "../../RTL/CRC.sv", 7, 11, ".link_adapter_tx.CRC_CALC", "v_toggle/CRC", "clk");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, vlSelf->__Vcoverage + 363, first, true, "../../RTL/CRC.sv", 8, 23, ".link_adapter_tx.CRC_CALC", "v_toggle/CRC", "CRC_REG");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 427, first, true, "../../RTL/CRC.sv", 13, 1, ".link_adapter_tx.CRC_CALC", "v_line/CRC", "block", "13-14", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 427, first, false, "../../RTL/CRC.sv", 13, 1, ".link_adapter_tx.CRC_CALC", "v_line/CRC", "block", "13-14", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 428, first, true, "../../RTL/CRC.sv", 22, 14, ".link_adapter_tx.CRC_CALC", "v_line/CRC", "if", "22-23", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 428, first, false, "../../RTL/CRC.sv", 22, 14, ".link_adapter_tx.CRC_CALC", "v_line/CRC", "if", "22-23", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 429, first, true, "../../RTL/CRC.sv", 22, 15, ".link_adapter_tx.CRC_CALC", "v_line/CRC", "else", "24-25", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 429, first, false, "../../RTL/CRC.sv", 22, 15, ".link_adapter_tx.CRC_CALC", "v_line/CRC", "else", "24-25", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 430, first, true, "../../RTL/CRC.sv", 19, 5, ".link_adapter_tx.CRC_CALC", "v_line/CRC", "elsif", "19,21", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 430, first, false, "../../RTL/CRC.sv", 19, 5, ".link_adapter_tx.CRC_CALC", "v_line/CRC", "elsif", "19,21", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 431, first, true, "../../RTL/CRC.sv", 18, 1, ".link_adapter_tx.CRC_CALC", "v_line/CRC", "block", "18", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 431, first, false, "../../RTL/CRC.sv", 18, 1, ".link_adapter_tx.CRC_CALC", "v_line/CRC", "block", "18", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 432, first, true, "../../RTL/link_adapter_tx.sv", 113, 9, ".TOP", "v_fsm_state/$root", "link_adapter_tx.current_link_adapter_state::STALL", "", "link_adapter_tx.current_link_adapter_state", "", "STALL", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 432, first, false, "../../RTL/link_adapter_tx.sv", 113, 9, ".TOP", "v_fsm_state/$root", "link_adapter_tx.current_link_adapter_state::STALL", "", "link_adapter_tx.current_link_adapter_state", "", "STALL", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 433, first, true, "../../RTL/link_adapter_tx.sv", 113, 9, ".TOP", "v_fsm_state/$root", "link_adapter_tx.current_link_adapter_state::FETCH", "", "link_adapter_tx.current_link_adapter_state", "", "FETCH", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 433, first, false, "../../RTL/link_adapter_tx.sv", 113, 9, ".TOP", "v_fsm_state/$root", "link_adapter_tx.current_link_adapter_state::FETCH", "", "link_adapter_tx.current_link_adapter_state", "", "FETCH", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 434, first, true, "../../RTL/link_adapter_tx.sv", 113, 9, ".TOP", "v_fsm_state/$root", "link_adapter_tx.current_link_adapter_state::ASSEMBLE", "", "link_adapter_tx.current_link_adapter_state", "", "ASSEMBLE", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 434, first, false, "../../RTL/link_adapter_tx.sv", 113, 9, ".TOP", "v_fsm_state/$root", "link_adapter_tx.current_link_adapter_state::ASSEMBLE", "", "link_adapter_tx.current_link_adapter_state", "", "ASSEMBLE", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 435, first, true, "../../RTL/link_adapter_tx.sv", 113, 9, ".TOP", "v_fsm_state/$root", "link_adapter_tx.current_link_adapter_state::SHIFT", "", "link_adapter_tx.current_link_adapter_state", "", "SHIFT", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 435, first, false, "../../RTL/link_adapter_tx.sv", 113, 9, ".TOP", "v_fsm_state/$root", "link_adapter_tx.current_link_adapter_state::SHIFT", "", "link_adapter_tx.current_link_adapter_state", "", "SHIFT", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 436, first, true, "../../RTL/link_adapter_tx.sv", 113, 9, ".TOP", "v_fsm_state/$root", "link_adapter_tx.current_link_adapter_state::CRC_SHIFT", "", "link_adapter_tx.current_link_adapter_state", "", "CRC_SHIFT", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 436, first, false, "../../RTL/link_adapter_tx.sv", 113, 9, ".TOP", "v_fsm_state/$root", "link_adapter_tx.current_link_adapter_state::CRC_SHIFT", "", "link_adapter_tx.current_link_adapter_state", "", "CRC_SHIFT", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 437, first, true, "../../RTL/link_adapter_tx.sv", 113, 9, ".TOP", "v_fsm_arc/$root", "link_adapter_tx.current_link_adapter_state::ANY->STALL[reset]", "", "link_adapter_tx.current_link_adapter_state", "ANY", "STALL", "reset");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 437, first, false, "../../RTL/link_adapter_tx.sv", 113, 9, ".TOP", "v_fsm_arc/$root", "link_adapter_tx.current_link_adapter_state::ANY->STALL[reset]", "", "link_adapter_tx.current_link_adapter_state", "ANY", "STALL", "reset");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 438, first, true, "../../RTL/link_adapter_tx.sv", 113, 9, ".TOP", "v_fsm_arc/$root", "link_adapter_tx.current_link_adapter_state::FETCH->ASSEMBLE", "", "link_adapter_tx.current_link_adapter_state", "FETCH", "ASSEMBLE", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 438, first, false, "../../RTL/link_adapter_tx.sv", 113, 9, ".TOP", "v_fsm_arc/$root", "link_adapter_tx.current_link_adapter_state::FETCH->ASSEMBLE", "", "link_adapter_tx.current_link_adapter_state", "FETCH", "ASSEMBLE", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 439, first, true, "../../RTL/link_adapter_tx.sv", 113, 9, ".TOP", "v_fsm_arc/$root", "link_adapter_tx.current_link_adapter_state::ASSEMBLE->SHIFT", "", "link_adapter_tx.current_link_adapter_state", "ASSEMBLE", "SHIFT", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 439, first, false, "../../RTL/link_adapter_tx.sv", 113, 9, ".TOP", "v_fsm_arc/$root", "link_adapter_tx.current_link_adapter_state::ASSEMBLE->SHIFT", "", "link_adapter_tx.current_link_adapter_state", "ASSEMBLE", "SHIFT", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 440, first, true, "../../RTL/link_adapter_tx.sv", 113, 9, ".TOP", "v_fsm_arc/$root", "link_adapter_tx.current_link_adapter_state::SHIFT->CRC_SHIFT", "", "link_adapter_tx.current_link_adapter_state", "SHIFT", "CRC_SHIFT", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 440, first, false, "../../RTL/link_adapter_tx.sv", 113, 9, ".TOP", "v_fsm_arc/$root", "link_adapter_tx.current_link_adapter_state::SHIFT->CRC_SHIFT", "", "link_adapter_tx.current_link_adapter_state", "SHIFT", "CRC_SHIFT", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 441, first, true, "../../RTL/link_adapter_tx.sv", 113, 9, ".TOP", "v_fsm_arc/$root", "link_adapter_tx.current_link_adapter_state::SHIFT->SHIFT", "", "link_adapter_tx.current_link_adapter_state", "SHIFT", "SHIFT", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 441, first, false, "../../RTL/link_adapter_tx.sv", 113, 9, ".TOP", "v_fsm_arc/$root", "link_adapter_tx.current_link_adapter_state::SHIFT->SHIFT", "", "link_adapter_tx.current_link_adapter_state", "SHIFT", "SHIFT", "");
}
