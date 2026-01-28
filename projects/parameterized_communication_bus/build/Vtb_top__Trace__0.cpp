// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_top__Syms.h"


void Vtb_top___024root__trace_chg_0_sub_0(Vtb_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root__trace_chg_0\n"); );
    // Init
    Vtb_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_top___024root*>(voidSelf);
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtb_top___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_top___024root__trace_chg_0_sub_0(Vtb_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+0,(vlSelf->tb_top__DOT__u_master__DOT__state),2);
        bufp->chgCData(oldp+1,(vlSelf->tb_top__DOT__u_master__DOT__next_state),2);
        bufp->chgBit(oldp+2,(vlSelf->tb_top__DOT__u_master__DOT__write_r));
        bufp->chgBit(oldp+3,(vlSelf->tb_top__DOT__u_master__DOT__valid_r));
        bufp->chgBit(oldp+4,(vlSelf->tb_top__DOT__u_master__DOT__read_r));
        bufp->chgSData(oldp+5,(vlSelf->tb_top__DOT__u_master__DOT__addr_r),16);
        bufp->chgIData(oldp+6,(vlSelf->tb_top__DOT__u_master__DOT__write_data_r),32);
        bufp->chgCData(oldp+7,(vlSelf->tb_top__DOT__u_slave__DOT__state),2);
        bufp->chgCData(oldp+8,(vlSelf->tb_top__DOT__u_slave__DOT__next_state),2);
        bufp->chgBit(oldp+9,(vlSelf->tb_top__DOT__u_slave__DOT__ready_r));
        bufp->chgBit(oldp+10,(vlSelf->tb_top__DOT__u_slave__DOT__ready_next));
        bufp->chgIData(oldp+11,(vlSelf->tb_top__DOT__u_slave__DOT__read_data_r),32);
        bufp->chgIData(oldp+12,(vlSelf->tb_top__DOT__u_slave__DOT__read_data_next),32);
    }
    bufp->chgBit(oldp+13,(vlSelf->clk));
    bufp->chgBit(oldp+14,(vlSelf->reset));
}

void Vtb_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root__trace_cleanup\n"); );
    // Init
    Vtb_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_top___024root*>(voidSelf);
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
