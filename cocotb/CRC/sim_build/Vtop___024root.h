// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_cov.h"
#include "verilated_covergroup.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(message,7,0);
    VL_IN8(reset,0,0);
    VL_IN8(enable,0,0);
    CData/*7:0*/ CRC__DOT__message;
    CData/*0:0*/ CRC__DOT__reset;
    CData/*0:0*/ CRC__DOT__enable;
    CData/*0:0*/ CRC__DOT__clk;
    CData/*7:0*/ CRC__DOT____Vtogcov__message;
    CData/*0:0*/ CRC__DOT____Vtogcov__reset;
    CData/*0:0*/ CRC__DOT____Vtogcov__enable;
    CData/*0:0*/ CRC__DOT____Vtogcov__clk;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VstlPhaseResult;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VicoPhaseResult;
    CData/*0:0*/ __Vtrigprevexpr___TOP__CRC__DOT__clk__0;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    VL_OUT(CRC_REG,31,0);
    IData/*31:0*/ CRC__DOT__CRC_REG;
    IData/*31:0*/ CRC__DOT____Vtogcov__CRC_REG;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 256> CRC__DOT__PRECOMPUTED_CRC;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;
    uint32_t __Vcoverage[91]{};

    // PARAMETERS
    static constexpr IData/*31:0*/ CRC__DOT__POLY = 0xedb88320U;
    static constexpr IData/*31:0*/ CRC__DOT__MESSAGE_SLICE_SIZE_BITS = 8U;

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
