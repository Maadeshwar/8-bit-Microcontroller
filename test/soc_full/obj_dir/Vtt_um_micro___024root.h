// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtt_um_micro.h for the primary calling header

#ifndef VERILATED_VTT_UM_MICRO___024ROOT_H_
#define VERILATED_VTT_UM_MICRO___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_cov.h"


class Vtt_um_micro__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtt_um_micro___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(ui_in,7,0);
    VL_OUT8(uo_out,7,0);
    VL_IN8(uio_in,7,0);
    VL_OUT8(uio_out,7,0);
    VL_OUT8(uio_oe,7,0);
    VL_IN8(ena,0,0);
    CData/*7:0*/ tt_um_micro__DOT__core__DOT__acc;
    CData/*7:0*/ tt_um_micro__DOT__core__DOT__ir;
    CData/*7:0*/ tt_um_micro__DOT__core__DOT__operand;
    CData/*7:0*/ tt_um_micro__DOT__core__DOT__ret_addr;
    CData/*1:0*/ tt_um_micro__DOT__core__DOT__state;
    CData/*7:0*/ tt_um_micro__DOT__core__DOT__timer;
    CData/*4:0*/ tt_um_micro__DOT__core__DOT__gpio_out;
    CData/*4:0*/ tt_um_micro__DOT__core__DOT__gpio_dir;
    CData/*7:0*/ tt_um_micro__DOT__core__DOT__pwm_duty;
    CData/*7:0*/ tt_um_micro__DOT__core__DOT__pwm_counter;
    CData/*0:0*/ tt_um_micro__DOT__core__DOT__flag_z;
    CData/*0:0*/ tt_um_micro__DOT__core__DOT__flag_c;
    CData/*0:0*/ tt_um_micro__DOT__core__DOT__tx_start;
    CData/*0:0*/ tt_um_micro__DOT__core__DOT__rx_ready;
    CData/*7:0*/ tt_um_micro__DOT__core__DOT__rx_data;
    CData/*0:0*/ tt_um_micro__DOT__core__DOT__rx_clear;
    CData/*0:0*/ tt_um_micro__DOT__core__DOT__uart_tx_pin;
    CData/*7:0*/ tt_um_micro__DOT__core__DOT__data_rdata;
    CData/*1:0*/ tt_um_micro__DOT__core__DOT__next_state;
    CData/*7:0*/ tt_um_micro__DOT__core__DOT__alu_and;
    CData/*7:0*/ tt_um_micro__DOT__core__DOT__alu_or;
    CData/*7:0*/ tt_um_micro__DOT__core__DOT__alu_xor;
    CData/*7:0*/ tt_um_micro__DOT__core__DOT__alu_shl;
    CData/*7:0*/ tt_um_micro__DOT__core__DOT__alu_shr;
    CData/*1:0*/ tt_um_micro__DOT__core__DOT__tx_inst__DOT__state;
    CData/*2:0*/ tt_um_micro__DOT__core__DOT__tx_inst__DOT__bit_index;
    CData/*7:0*/ tt_um_micro__DOT__core__DOT__tx_inst__DOT__tx_data_reg;
    CData/*1:0*/ tt_um_micro__DOT__core__DOT__rx_inst__DOT__state;
    CData/*2:0*/ tt_um_micro__DOT__core__DOT__rx_inst__DOT__bit_index;
    CData/*0:0*/ tt_um_micro__DOT__core__DOT__rx_inst__DOT__rx_r1;
    CData/*0:0*/ tt_um_micro__DOT__core__DOT__rx_inst__DOT__rx_r2;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ tt_um_micro__DOT__core__DOT__baud_div;
    SData/*8:0*/ tt_um_micro__DOT__core__DOT__alu_add;
    SData/*8:0*/ tt_um_micro__DOT__core__DOT__alu_sub;
    SData/*15:0*/ tt_um_micro__DOT__core__DOT__tx_inst__DOT__clk_count;
    SData/*15:0*/ tt_um_micro__DOT__core__DOT__rx_inst__DOT__clk_count;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 8> tt_um_micro__DOT__core__DOT__ram;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtt_um_micro__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtt_um_micro___024root(Vtt_um_micro__Syms* symsp, const char* v__name);
    ~Vtt_um_micro___024root();
    VL_UNCOPYABLE(Vtt_um_micro___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
    void __vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
        const char* hierp, const char* pagep, const char* commentp, const char* linescovp);
};


#endif  // guard
