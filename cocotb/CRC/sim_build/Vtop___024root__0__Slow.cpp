// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__CRC__DOT__clk__0 
        = vlSelfRef.CRC__DOT__clk;
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_initial__TOP
        VL_READMEM_N(true, 32, 256, 0, "../../utils/CRC_TABLE.mem"s
                     ,  &(vlSelfRef.CRC__DOT__PRECOMPUTED_CRC)
                     , 0, ~0ULL);
        ++(vlSelf->__Vcoverage[86]);
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
            VL_FATAL_MT("../../RTL/CRC.sv", 3, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
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
                {
                    // Inlined CFunc: _stl_sequent__TOP__0
                    if ((0U != (vlSelfRef.CRC__DOT__CRC_REG 
                                ^ vlSelfRef.CRC__DOT____Vtogcov__CRC_REG))) {
                        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 22, vlSelfRef.CRC__DOT__CRC_REG, vlSelfRef.CRC__DOT____Vtogcov__CRC_REG);
                        vlSelfRef.CRC__DOT____Vtogcov__CRC_REG 
                            = vlSelfRef.CRC__DOT__CRC_REG;
                    }
                    vlSelfRef.CRC_REG = vlSelfRef.CRC__DOT__CRC_REG;
                    vlSelfRef.CRC__DOT__message = vlSelfRef.message;
                    vlSelfRef.CRC__DOT__reset = vlSelfRef.reset;
                    vlSelfRef.CRC__DOT__enable = vlSelfRef.enable;
                    vlSelfRef.CRC__DOT__clk = vlSelfRef.clk;
                    if ((0U != ((IData)(vlSelfRef.CRC__DOT__message) 
                                ^ (IData)(vlSelfRef.CRC__DOT____Vtogcov__message)))) {
                        VL_COV_TOGGLE_CHG_ST_I(8, vlSelf->__Vcoverage + 0, vlSelfRef.CRC__DOT__message, vlSelfRef.CRC__DOT____Vtogcov__message);
                        vlSelfRef.CRC__DOT____Vtogcov__message 
                            = vlSelfRef.CRC__DOT__message;
                    }
                    if (((IData)(vlSelfRef.CRC__DOT__reset) 
                         ^ (IData)(vlSelfRef.CRC__DOT____Vtogcov__reset))) {
                        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 16, vlSelfRef.CRC__DOT__reset, vlSelfRef.CRC__DOT____Vtogcov__reset);
                        vlSelfRef.CRC__DOT____Vtogcov__reset 
                            = vlSelfRef.CRC__DOT__reset;
                    }
                    if (((IData)(vlSelfRef.CRC__DOT__enable) 
                         ^ (IData)(vlSelfRef.CRC__DOT____Vtogcov__enable))) {
                        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 18, vlSelfRef.CRC__DOT__enable, vlSelfRef.CRC__DOT____Vtogcov__enable);
                        vlSelfRef.CRC__DOT____Vtogcov__enable 
                            = vlSelfRef.CRC__DOT__enable;
                    }
                    if (((IData)(vlSelfRef.CRC__DOT__clk) 
                         ^ (IData)(vlSelfRef.CRC__DOT____Vtogcov__clk))) {
                        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 20, vlSelfRef.CRC__DOT__clk, vlSelfRef.CRC__DOT____Vtogcov__clk);
                        vlSelfRef.CRC__DOT____Vtogcov__clk 
                            = vlSelfRef.CRC__DOT__clk;
                    }
                }
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
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge CRC.clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->message = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11263761559013077561ull);
    vlSelf->reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9928399931838511862ull);
    vlSelf->enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11030669854614834172ull);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->CRC_REG = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3171558983897846972ull);
    vlSelf->CRC__DOT__message = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 474999728741526880ull);
    vlSelf->CRC__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 70506076951675497ull);
    vlSelf->CRC__DOT__enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2559343537056574633ull);
    vlSelf->CRC__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2995971452563873744ull);
    vlSelf->CRC__DOT__CRC_REG = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 559568080967612542ull);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->CRC__DOT__PRECOMPUTED_CRC[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16559389817985437832ull);
    }
    vlSelf->CRC__DOT____Vtogcov__message = 0;
    vlSelf->CRC__DOT____Vtogcov__reset = 0;
    vlSelf->CRC__DOT____Vtogcov__enable = 0;
    vlSelf->CRC__DOT____Vtogcov__clk = 0;
    vlSelf->CRC__DOT____Vtogcov__CRC_REG = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__CRC__DOT__clk__0 = 0;
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
    vlSelf->__vlCoverToggleInsert(0, 7, 1, vlSelf->__Vcoverage + 0, first, true, "../../RTL/CRC.sv", 4, 41, ".CRC", "v_toggle/CRC", "message");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, vlSelf->__Vcoverage + 16, first, true, "../../RTL/CRC.sv", 5, 11, ".CRC", "v_toggle/CRC", "reset");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, vlSelf->__Vcoverage + 18, first, true, "../../RTL/CRC.sv", 6, 11, ".CRC", "v_toggle/CRC", "enable");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, vlSelf->__Vcoverage + 20, first, true, "../../RTL/CRC.sv", 7, 11, ".CRC", "v_toggle/CRC", "clk");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, vlSelf->__Vcoverage + 22, first, true, "../../RTL/CRC.sv", 8, 23, ".CRC", "v_toggle/CRC", "CRC_REG");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 86, first, true, "../../RTL/CRC.sv", 13, 1, ".CRC", "v_line/CRC", "block", "13-14", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 86, first, false, "../../RTL/CRC.sv", 13, 1, ".CRC", "v_line/CRC", "block", "13-14", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 87, first, true, "../../RTL/CRC.sv", 22, 14, ".CRC", "v_line/CRC", "if", "22-23", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 87, first, false, "../../RTL/CRC.sv", 22, 14, ".CRC", "v_line/CRC", "if", "22-23", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 88, first, true, "../../RTL/CRC.sv", 22, 15, ".CRC", "v_line/CRC", "else", "24-25", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 88, first, false, "../../RTL/CRC.sv", 22, 15, ".CRC", "v_line/CRC", "else", "24-25", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 89, first, true, "../../RTL/CRC.sv", 19, 5, ".CRC", "v_line/CRC", "elsif", "19,21", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 89, first, false, "../../RTL/CRC.sv", 19, 5, ".CRC", "v_line/CRC", "elsif", "19,21", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 90, first, true, "../../RTL/CRC.sv", 18, 1, ".CRC", "v_line/CRC", "block", "18", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 90, first, false, "../../RTL/CRC.sv", 18, 1, ".CRC", "v_line/CRC", "block", "18", "", "", "", "");
}
