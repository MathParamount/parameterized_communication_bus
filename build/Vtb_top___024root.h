// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_top.h for the primary calling header

#ifndef VERILATED_VTB_TOP___024ROOT_H_
#define VERILATED_VTB_TOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtb_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_top___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    CData/*1:0*/ tb_top__DOT__u_master__DOT__state;
    CData/*1:0*/ tb_top__DOT__u_master__DOT__next_state;
    CData/*0:0*/ tb_top__DOT__u_master__DOT__write_r;
    CData/*0:0*/ tb_top__DOT__u_master__DOT__valid_r;
    CData/*0:0*/ tb_top__DOT__u_master__DOT__read_r;
    CData/*1:0*/ tb_top__DOT__u_slave__DOT__state;
    CData/*1:0*/ tb_top__DOT__u_slave__DOT__next_state;
    CData/*0:0*/ tb_top__DOT__u_slave__DOT__ready_r;
    CData/*0:0*/ tb_top__DOT__u_slave__DOT__ready_next;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__reset__0;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ tb_top__DOT__u_master__DOT__addr_r;
    IData/*31:0*/ tb_top__DOT__u_master__DOT__write_data_r;
    IData/*31:0*/ tb_top__DOT__u_slave__DOT__read_data_r;
    IData/*31:0*/ tb_top__DOT__u_slave__DOT__read_data_next;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_top___024root(Vtb_top__Syms* symsp, const char* v__name);
    ~Vtb_top___024root();
    VL_UNCOPYABLE(Vtb_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
