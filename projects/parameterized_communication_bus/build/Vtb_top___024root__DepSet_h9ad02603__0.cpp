// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_top.h for the primary calling header

#include "Vtb_top__pch.h"
#include "Vtb_top___024root.h"

void Vtb_top___024root___eval_act(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_act\n"); );
}

extern const VlUnpacked<CData/*1:0*/, 8> Vtb_top__ConstPool__TABLE_h7c15befd_0;
extern const VlUnpacked<CData/*0:0*/, 8> Vtb_top__ConstPool__TABLE_h3501fe4c_0;
extern const VlUnpacked<CData/*0:0*/, 8> Vtb_top__ConstPool__TABLE_h5c6a37b8_0;
extern const VlUnpacked<CData/*0:0*/, 8> Vtb_top__ConstPool__TABLE_h96aa6e1a_0;
extern const VlUnpacked<SData/*15:0*/, 8> Vtb_top__ConstPool__TABLE_h320a7e6b_0;
extern const VlUnpacked<IData/*31:0*/, 8> Vtb_top__ConstPool__TABLE_h28b3396b_0;

VL_INLINE_OPT void Vtb_top___024root___nba_sequent__TOP__0(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*2:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    if (vlSelf->reset) {
        vlSelf->tb_top__DOT__u_slave__DOT__read_data_r 
            = vlSelf->tb_top__DOT__u_slave__DOT__read_data_next;
        vlSelf->tb_top__DOT__u_slave__DOT__state = vlSelf->tb_top__DOT__u_slave__DOT__next_state;
        vlSelf->tb_top__DOT__u_master__DOT__state = vlSelf->tb_top__DOT__u_master__DOT__next_state;
    } else {
        vlSelf->tb_top__DOT__u_slave__DOT__read_data_r = 0U;
        vlSelf->tb_top__DOT__u_slave__DOT__state = 0U;
        vlSelf->tb_top__DOT__u_master__DOT__state = 0U;
    }
    vlSelf->tb_top__DOT__u_slave__DOT__ready_r = ((IData)(vlSelf->reset) 
                                                  && (IData)(vlSelf->tb_top__DOT__u_slave__DOT__ready_next));
    vlSelf->tb_top__DOT__u_slave__DOT__ready_next = 0U;
    __Vtableidx1 = (((IData)(vlSelf->tb_top__DOT__u_slave__DOT__ready_r) 
                     << 2U) | (IData)(vlSelf->tb_top__DOT__u_master__DOT__state));
    vlSelf->tb_top__DOT__u_master__DOT__next_state 
        = Vtb_top__ConstPool__TABLE_h7c15befd_0[__Vtableidx1];
    vlSelf->tb_top__DOT__u_master__DOT__valid_r = Vtb_top__ConstPool__TABLE_h3501fe4c_0
        [__Vtableidx1];
    vlSelf->tb_top__DOT__u_master__DOT__read_r = Vtb_top__ConstPool__TABLE_h5c6a37b8_0
        [__Vtableidx1];
    vlSelf->tb_top__DOT__u_master__DOT__write_r = Vtb_top__ConstPool__TABLE_h96aa6e1a_0
        [__Vtableidx1];
    vlSelf->tb_top__DOT__u_master__DOT__addr_r = Vtb_top__ConstPool__TABLE_h320a7e6b_0
        [__Vtableidx1];
    vlSelf->tb_top__DOT__u_master__DOT__write_data_r 
        = Vtb_top__ConstPool__TABLE_h28b3396b_0[__Vtableidx1];
    vlSelf->tb_top__DOT__u_slave__DOT__next_state = vlSelf->tb_top__DOT__u_slave__DOT__state;
    if ((0U == (IData)(vlSelf->tb_top__DOT__u_slave__DOT__state))) {
        if (vlSelf->tb_top__DOT__u_master__DOT__valid_r) {
            vlSelf->tb_top__DOT__u_slave__DOT__next_state = 1U;
        }
    } else {
        vlSelf->tb_top__DOT__u_slave__DOT__next_state 
            = ((1U == (IData)(vlSelf->tb_top__DOT__u_slave__DOT__state))
                ? 2U : 0U);
    }
    vlSelf->tb_top__DOT__u_slave__DOT__read_data_next 
        = vlSelf->tb_top__DOT__u_slave__DOT__read_data_r;
    if ((0U != (IData)(vlSelf->tb_top__DOT__u_slave__DOT__state))) {
        if ((1U == (IData)(vlSelf->tb_top__DOT__u_slave__DOT__state))) {
            vlSelf->tb_top__DOT__u_slave__DOT__ready_next = 1U;
            vlSelf->tb_top__DOT__u_slave__DOT__read_data_next 
                = ((IData)(vlSelf->tb_top__DOT__u_master__DOT__read_r)
                    ? 0xcafebabeU : vlSelf->tb_top__DOT__u_slave__DOT__read_data_r);
        } else if ((2U == (IData)(vlSelf->tb_top__DOT__u_slave__DOT__state))) {
            vlSelf->tb_top__DOT__u_slave__DOT__ready_next = 0U;
        }
    }
}

void Vtb_top___024root___eval_nba(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_top___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vtb_top___024root___eval_triggers__act(Vtb_top___024root* vlSelf);

bool Vtb_top___024root___eval_phase__act(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_top___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtb_top___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_top___024root___eval_phase__nba(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_top___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_top___024root___dump_triggers__nba(Vtb_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_top___024root___dump_triggers__act(Vtb_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_top___024root___eval(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb_top___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb/tb_top.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb_top___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb/tb_top.sv", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtb_top___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtb_top___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_top___024root___eval_debug_assertions(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
