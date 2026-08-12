// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    bufp->chgBit(oldp+0,(vlSelfRef.clk));
    bufp->chgBit(oldp+1,(vlSelfRef.reset));
    bufp->chgWData(oldp+2,(vlSelfRef.tx_packet),2048);
    bufp->chgBit(oldp+66,(vlSelfRef.packet_valid));
    bufp->chgBit(oldp+67,(vlSelfRef.packet_ready));
    bufp->chgCData(oldp+68,(vlSelfRef.OSERDES_out),8);
    bufp->chgBit(oldp+69,(vlSelfRef.link_adapter_tx__DOT__clk));
    bufp->chgBit(oldp+70,(vlSelfRef.link_adapter_tx__DOT__reset));
    bufp->chgWData(oldp+71,(vlSelfRef.link_adapter_tx__DOT__tx_packet),2048);
    bufp->chgBit(oldp+135,(vlSelfRef.link_adapter_tx__DOT__packet_valid));
    bufp->chgBit(oldp+136,(vlSelfRef.link_adapter_tx__DOT__packet_ready));
    bufp->chgCData(oldp+137,(vlSelfRef.link_adapter_tx__DOT__OSERDES_out),8);
    bufp->chgCData(oldp+138,(vlSelfRef.link_adapter_tx__DOT__current_link_adapter_state),3);
    bufp->chgCData(oldp+139,(vlSelfRef.link_adapter_tx__DOT__next_link_adapter_state),3);
    bufp->chgCData(oldp+140,(vlSelfRef.link_adapter_tx__DOT__fifo_ring_write_ptr),3);
    bufp->chgCData(oldp+141,(vlSelfRef.link_adapter_tx__DOT__fifo_ring_top_ptr),3);
    bufp->chgCData(oldp+142,(vlSelfRef.link_adapter_tx__DOT__fifo_ring_size),4);
    bufp->chgBit(oldp+143,(vlSelfRef.link_adapter_tx__DOT__fifo_full));
    bufp->chgBit(oldp+144,(vlSelfRef.link_adapter_tx__DOT__fifo_empty));
    bufp->chgCData(oldp+145,(vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_addr),3);
    bufp->chgBit(oldp+146,(vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_en));
    bufp->chgWData(oldp+147,(vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_a_rd_data),2048);
    bufp->chgCData(oldp+211,(vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_b_addr),3);
    bufp->chgBit(oldp+212,(vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_b_w_en));
    bufp->chgWData(oldp+213,(vlSelfRef.link_adapter_tx__DOT__fifo_ring_buffer_port_b_w_data),2048);
    bufp->chgBit(oldp+277,(vlSelfRef.link_adapter_tx__DOT__push_fifo));
    bufp->chgBit(oldp+278,(vlSelfRef.link_adapter_tx__DOT__pop_fifo));
    bufp->chgWData(oldp+279,(vlSelfRef.link_adapter_tx__DOT__L2_frame_shift_reg),2080);
    bufp->chgSData(oldp+344,(vlSelfRef.link_adapter_tx__DOT__byte_ctr_shift),9);
    bufp->chgCData(oldp+345,(vlSelfRef.link_adapter_tx__DOT__byte_ctr_crc_shift),2);
    bufp->chgSData(oldp+346,(vlSelfRef.link_adapter_tx__DOT__latched_L3_packet_size),16);
    bufp->chgSData(oldp+347,(vlSelfRef.link_adapter_tx__DOT__curr_L3_packet_size),16);
    bufp->chgIData(oldp+348,(vlSelfRef.link_adapter_tx__DOT__crc_calc_output),32);
    bufp->chgCData(oldp+349,(vlSelfRef.link_adapter_tx__DOT__crc_byte_output),8);
    bufp->chgCData(oldp+350,(vlSelfRef.link_adapter_tx__DOT__crc_calc_input),8);
    bufp->chgBit(oldp+351,(vlSelfRef.link_adapter_tx__DOT__crc_calc_en));
    bufp->chgBit(oldp+352,(vlSelfRef.link_adapter_tx__DOT__crc_reset));
    bufp->chgCData(oldp+353,(vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__message),8);
    bufp->chgBit(oldp+354,(vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__reset));
    bufp->chgBit(oldp+355,(vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__enable));
    bufp->chgBit(oldp+356,(vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__clk));
    bufp->chgIData(oldp+357,(vlSelfRef.link_adapter_tx__DOT__CRC_CALC__DOT__CRC_REG),32);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Locals
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
