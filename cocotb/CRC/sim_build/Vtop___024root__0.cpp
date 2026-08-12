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
                {
                    // Inlined CFunc: _ico_sequent__TOP__0
                    if ((0U != (vlSelfRef.CRC__DOT__CRC_REG 
                                ^ vlSelfRef.CRC__DOT____Vtogcov__CRC_REG))) {
                        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 22, vlSelfRef.CRC__DOT__CRC_REG, vlSelfRef.CRC__DOT____Vtogcov__CRC_REG);
                        vlSelfRef.CRC__DOT____Vtogcov__CRC_REG 
                            = vlSelfRef.CRC__DOT__CRC_REG;
                    }
                    vlSelfRef.CRC_REG = vlSelfRef.CRC__DOT__CRC_REG;
                    vlSelfRef.CRC__DOT__clk = vlSelfRef.clk;
                    vlSelfRef.CRC__DOT__message = vlSelfRef.message;
                    vlSelfRef.CRC__DOT__reset = vlSelfRef.reset;
                    vlSelfRef.CRC__DOT__enable = vlSelfRef.enable;
                    if (((IData)(vlSelfRef.CRC__DOT__clk) 
                         ^ (IData)(vlSelfRef.CRC__DOT____Vtogcov__clk))) {
                        VL_COV_TOGGLE_CHG_ST_I(1, vlSelf->__Vcoverage + 20, vlSelfRef.CRC__DOT__clk, vlSelfRef.CRC__DOT____Vtogcov__clk);
                        vlSelfRef.CRC__DOT____Vtogcov__clk 
                            = vlSelfRef.CRC__DOT__clk;
                    }
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
                }
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
                                                        ((IData)(vlSelfRef.CRC__DOT__clk) 
                                                         & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__CRC__DOT__clk__0)))));
        vlSelfRef.__Vtrigprevexpr___TOP__CRC__DOT__clk__0 
            = vlSelfRef.CRC__DOT__clk;
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
                {
                    // Inlined CFunc: _nba_sequent__TOP__0
                    IData/*31:0*/ __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__0___Vdly__CRC__DOT__CRC_REG;
                    __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__0___Vdly__CRC__DOT__CRC_REG = 0;
                    __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__0___Vdly__CRC__DOT__CRC_REG 
                        = vlSelfRef.CRC__DOT__CRC_REG;
                    if (vlSelfRef.CRC__DOT__reset) {
                        ++(vlSelf->__Vcoverage[89]);
                        __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__0___Vdly__CRC__DOT__CRC_REG = 0xffffffffU;
                    } else if (vlSelfRef.CRC__DOT__enable) {
                        __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__0___Vdly__CRC__DOT__CRC_REG 
                            = ((vlSelfRef.CRC__DOT__CRC_REG 
                                >> 8U) ^ vlSelfRef.CRC__DOT__PRECOMPUTED_CRC
                               [(0x000000ffU & (vlSelfRef.CRC__DOT__CRC_REG 
                                                ^ (IData)(vlSelfRef.CRC__DOT__message)))]);
                        ++(vlSelf->__Vcoverage[87]);
                    } else {
                        __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__0___Vdly__CRC__DOT__CRC_REG 
                            = vlSelfRef.CRC__DOT__CRC_REG;
                        ++(vlSelf->__Vcoverage[88]);
                    }
                    ++(vlSelf->__Vcoverage[90]);
                    vlSelfRef.CRC__DOT__CRC_REG = __Vinline_0__eval_nba___Vinline_0__nba_sequent__TOP__0___Vdly__CRC__DOT__CRC_REG;
                    if ((0U != (vlSelfRef.CRC__DOT__CRC_REG 
                                ^ vlSelfRef.CRC__DOT____Vtogcov__CRC_REG))) {
                        VL_COV_TOGGLE_CHG_ST_I(32, vlSelf->__Vcoverage + 22, vlSelfRef.CRC__DOT__CRC_REG, vlSelfRef.CRC__DOT____Vtogcov__CRC_REG);
                        vlSelfRef.CRC__DOT____Vtogcov__CRC_REG 
                            = vlSelfRef.CRC__DOT__CRC_REG;
                    }
                    vlSelfRef.CRC_REG = vlSelfRef.CRC__DOT__CRC_REG;
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
            VL_FATAL_MT("../../RTL/CRC.sv", 3, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 10000 tries");
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
            VL_FATAL_MT("../../RTL/CRC.sv", 3, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("../../RTL/CRC.sv", 3, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
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
    if (VL_UNLIKELY(((vlSelfRef.reset & 0xfeU)))) {
        Verilated::overWidthError("reset");
    }
    if (VL_UNLIKELY(((vlSelfRef.enable & 0xfeU)))) {
        Verilated::overWidthError("enable");
    }
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
}
#endif  // VL_DEBUG
