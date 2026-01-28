// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_top.h for the primary calling header

#include "Vtb_top__pch.h"
#include "Vtb_top___024root.h"

VL_ATTR_COLD void Vtb_top___024root___eval_static(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtb_top___024root___eval_initial(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = vlSelf->reset;
}

VL_ATTR_COLD void Vtb_top___024root___eval_final(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_top___024root___dump_triggers__stl(Vtb_top___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_top___024root___eval_phase__stl(Vtb_top___024root* vlSelf);

VL_ATTR_COLD void Vtb_top___024root___eval_settle(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtb_top___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("tb/tb_top.sv", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_top___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_top___024root___dump_triggers__stl(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

extern const VlUnpacked<CData/*1:0*/, 8> Vtb_top__ConstPool__TABLE_h7c15befd_0;
extern const VlUnpacked<CData/*0:0*/, 8> Vtb_top__ConstPool__TABLE_h3501fe4c_0;
extern const VlUnpacked<CData/*0:0*/, 8> Vtb_top__ConstPool__TABLE_h5c6a37b8_0;
extern const VlUnpacked<CData/*0:0*/, 8> Vtb_top__ConstPool__TABLE_h96aa6e1a_0;
extern const VlUnpacked<SData/*15:0*/, 8> Vtb_top__ConstPool__TABLE_h320a7e6b_0;
extern const VlUnpacked<IData/*31:0*/, 8> Vtb_top__ConstPool__TABLE_h28b3396b_0;

VL_ATTR_COLD void Vtb_top___024root___stl_sequent__TOP__0(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___stl_sequent__TOP__0\n"); );
    // Init
    CData/*2:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
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

VL_ATTR_COLD void Vtb_top___024root___eval_stl(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtb_top___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void Vtb_top___024root___eval_triggers__stl(Vtb_top___024root* vlSelf);

VL_ATTR_COLD bool Vtb_top___024root___eval_phase__stl(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_top___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb_top___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_top___024root___dump_triggers__act(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk or negedge reset)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_top___024root___dump_triggers__nba(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk or negedge reset)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_top___024root___ctor_var_reset(Vtb_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_top___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__u_master__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->tb_top__DOT__u_master__DOT__next_state = VL_RAND_RESET_I(2);
    vlSelf->tb_top__DOT__u_master__DOT__write_r = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__u_master__DOT__valid_r = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__u_master__DOT__read_r = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__u_master__DOT__addr_r = VL_RAND_RESET_I(16);
    vlSelf->tb_top__DOT__u_master__DOT__write_data_r = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__u_slave__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->tb_top__DOT__u_slave__DOT__next_state = VL_RAND_RESET_I(2);
    vlSelf->tb_top__DOT__u_slave__DOT__ready_r = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__u_slave__DOT__ready_next = VL_RAND_RESET_I(1);
    vlSelf->tb_top__DOT__u_slave__DOT__read_data_r = VL_RAND_RESET_I(32);
    vlSelf->tb_top__DOT__u_slave__DOT__read_data_next = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
