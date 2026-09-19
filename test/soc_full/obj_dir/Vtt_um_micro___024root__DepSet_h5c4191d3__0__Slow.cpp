// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtt_um_micro.h for the primary calling header

#include "Vtt_um_micro__pch.h"
#include "Vtt_um_micro___024root.h"

VL_ATTR_COLD void Vtt_um_micro___024root___eval_static(Vtt_um_micro___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_micro___024root___eval_static\n"); );
    Vtt_um_micro__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
}

VL_ATTR_COLD void Vtt_um_micro___024root___eval_initial(Vtt_um_micro___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_micro___024root___eval_initial\n"); );
    Vtt_um_micro__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtt_um_micro___024root___eval_final(Vtt_um_micro___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_micro___024root___eval_final\n"); );
    Vtt_um_micro__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtt_um_micro___024root___dump_triggers__stl(Vtt_um_micro___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtt_um_micro___024root___eval_phase__stl(Vtt_um_micro___024root* vlSelf);

VL_ATTR_COLD void Vtt_um_micro___024root___eval_settle(Vtt_um_micro___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_micro___024root___eval_settle\n"); );
    Vtt_um_micro__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtt_um_micro___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("../../src/tt_um_micro.v", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtt_um_micro___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtt_um_micro___024root___dump_triggers__stl(Vtt_um_micro___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_micro___024root___dump_triggers__stl\n"); );
    Vtt_um_micro__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtt_um_micro___024root___stl_sequent__TOP__0(Vtt_um_micro___024root* vlSelf);

VL_ATTR_COLD void Vtt_um_micro___024root___eval_stl(Vtt_um_micro___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_micro___024root___eval_stl\n"); );
    Vtt_um_micro__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtt_um_micro___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtt_um_micro___024root___eval_triggers__stl(Vtt_um_micro___024root* vlSelf);

VL_ATTR_COLD bool Vtt_um_micro___024root___eval_phase__stl(Vtt_um_micro___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_micro___024root___eval_phase__stl\n"); );
    Vtt_um_micro__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtt_um_micro___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtt_um_micro___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtt_um_micro___024root___dump_triggers__ico(Vtt_um_micro___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_micro___024root___dump_triggers__ico\n"); );
    Vtt_um_micro__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtt_um_micro___024root___dump_triggers__act(Vtt_um_micro___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_micro___024root___dump_triggers__act\n"); );
    Vtt_um_micro__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtt_um_micro___024root___dump_triggers__nba(Vtt_um_micro___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_micro___024root___dump_triggers__nba\n"); );
    Vtt_um_micro__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtt_um_micro___024root___ctor_var_reset(Vtt_um_micro___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_micro___024root___ctor_var_reset\n"); );
    Vtt_um_micro__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->ui_in = VL_RAND_RESET_I(8);
    vlSelf->uo_out = VL_RAND_RESET_I(8);
    vlSelf->uio_in = VL_RAND_RESET_I(8);
    vlSelf->uio_out = VL_RAND_RESET_I(8);
    vlSelf->uio_oe = VL_RAND_RESET_I(8);
    vlSelf->ena = VL_RAND_RESET_I(1);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst_n = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tt_um_micro__DOT__core__DOT__ram[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->tt_um_micro__DOT__core__DOT__acc = VL_RAND_RESET_I(8);
    vlSelf->tt_um_micro__DOT__core__DOT__ir = VL_RAND_RESET_I(8);
    vlSelf->tt_um_micro__DOT__core__DOT__operand = VL_RAND_RESET_I(8);
    vlSelf->tt_um_micro__DOT__core__DOT__ret_addr = VL_RAND_RESET_I(8);
    vlSelf->tt_um_micro__DOT__core__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->tt_um_micro__DOT__core__DOT__timer = VL_RAND_RESET_I(8);
    vlSelf->tt_um_micro__DOT__core__DOT__baud_div = VL_RAND_RESET_I(16);
    vlSelf->tt_um_micro__DOT__core__DOT__gpio_out = VL_RAND_RESET_I(5);
    vlSelf->tt_um_micro__DOT__core__DOT__gpio_dir = VL_RAND_RESET_I(5);
    vlSelf->tt_um_micro__DOT__core__DOT__pwm_duty = VL_RAND_RESET_I(8);
    vlSelf->tt_um_micro__DOT__core__DOT__pwm_counter = VL_RAND_RESET_I(8);
    vlSelf->tt_um_micro__DOT__core__DOT__flag_z = VL_RAND_RESET_I(1);
    vlSelf->tt_um_micro__DOT__core__DOT__flag_c = VL_RAND_RESET_I(1);
    vlSelf->tt_um_micro__DOT__core__DOT__tx_start = VL_RAND_RESET_I(1);
    vlSelf->tt_um_micro__DOT__core__DOT__rx_ready = VL_RAND_RESET_I(1);
    vlSelf->tt_um_micro__DOT__core__DOT__rx_data = VL_RAND_RESET_I(8);
    vlSelf->tt_um_micro__DOT__core__DOT__rx_clear = VL_RAND_RESET_I(1);
    vlSelf->tt_um_micro__DOT__core__DOT__uart_tx_pin = VL_RAND_RESET_I(1);
    vlSelf->tt_um_micro__DOT__core__DOT__data_rdata = VL_RAND_RESET_I(8);
    vlSelf->tt_um_micro__DOT__core__DOT__next_state = VL_RAND_RESET_I(2);
    vlSelf->tt_um_micro__DOT__core__DOT__alu_add = VL_RAND_RESET_I(9);
    vlSelf->tt_um_micro__DOT__core__DOT__alu_sub = VL_RAND_RESET_I(9);
    vlSelf->tt_um_micro__DOT__core__DOT__alu_and = VL_RAND_RESET_I(8);
    vlSelf->tt_um_micro__DOT__core__DOT__alu_or = VL_RAND_RESET_I(8);
    vlSelf->tt_um_micro__DOT__core__DOT__alu_xor = VL_RAND_RESET_I(8);
    vlSelf->tt_um_micro__DOT__core__DOT__alu_shl = VL_RAND_RESET_I(8);
    vlSelf->tt_um_micro__DOT__core__DOT__alu_shr = VL_RAND_RESET_I(8);
    vlSelf->tt_um_micro__DOT__core__DOT__tx_inst__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->tt_um_micro__DOT__core__DOT__tx_inst__DOT__clk_count = VL_RAND_RESET_I(16);
    vlSelf->tt_um_micro__DOT__core__DOT__tx_inst__DOT__bit_index = VL_RAND_RESET_I(3);
    vlSelf->tt_um_micro__DOT__core__DOT__tx_inst__DOT__tx_data_reg = VL_RAND_RESET_I(8);
    vlSelf->tt_um_micro__DOT__core__DOT__rx_inst__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->tt_um_micro__DOT__core__DOT__rx_inst__DOT__clk_count = VL_RAND_RESET_I(16);
    vlSelf->tt_um_micro__DOT__core__DOT__rx_inst__DOT__bit_index = VL_RAND_RESET_I(3);
    vlSelf->tt_um_micro__DOT__core__DOT__rx_inst__DOT__rx_r1 = VL_RAND_RESET_I(1);
    vlSelf->tt_um_micro__DOT__core__DOT__rx_inst__DOT__rx_r2 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = VL_RAND_RESET_I(1);
}
