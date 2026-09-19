// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtt_um_micro.h for the primary calling header

#include "Vtt_um_micro__pch.h"
#include "Vtt_um_micro__Syms.h"
#include "Vtt_um_micro___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtt_um_micro___024root___dump_triggers__ico(Vtt_um_micro___024root* vlSelf);
#endif  // VL_DEBUG

void Vtt_um_micro___024root___eval_triggers__ico(Vtt_um_micro___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_micro___024root___eval_triggers__ico\n"); );
    Vtt_um_micro__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.setBit(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtt_um_micro___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vtt_um_micro___024root___ico_sequent__TOP__0(Vtt_um_micro___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_micro___024root___ico_sequent__TOP__0\n"); );
    Vtt_um_micro__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tt_um_micro__DOT__core__DOT__next_state 
        = vlSelfRef.tt_um_micro__DOT__core__DOT__state;
    if ((0U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__state))) {
        if ((0U == (IData)(vlSelfRef.ui_in))) {
            vlSelfRef.tt_um_micro__DOT__core__DOT__next_state = 0U;
            ++(vlSymsp->__Vcoverage[15]);
        } else {
            ++(vlSymsp->__Vcoverage[16]);
            vlSelfRef.tt_um_micro__DOT__core__DOT__next_state = 1U;
        }
        ++(vlSymsp->__Vcoverage[17]);
    } else if ((1U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__state))) {
        ++(vlSymsp->__Vcoverage[18]);
        vlSelfRef.tt_um_micro__DOT__core__DOT__next_state = 2U;
    } else if ((2U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__state))) {
        ++(vlSymsp->__Vcoverage[19]);
        vlSelfRef.tt_um_micro__DOT__core__DOT__next_state = 0U;
    } else {
        ++(vlSymsp->__Vcoverage[20]);
        vlSelfRef.tt_um_micro__DOT__core__DOT__next_state = 0U;
    }
    ++(vlSymsp->__Vcoverage[21]);
    vlSelfRef.tt_um_micro__DOT__core__DOT__data_rdata = 0U;
    if ((7U >= (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) {
        vlSelfRef.tt_um_micro__DOT__core__DOT__data_rdata 
            = vlSelfRef.tt_um_micro__DOT__core__DOT__ram
            [(7U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))];
        ++(vlSymsp->__Vcoverage[8]);
    } else {
        if (((((((((0x20U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand)) 
                   | (0x21U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) 
                  | (0x22U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) 
                 | (0x23U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) 
                | (0x25U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) 
               | (0x26U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) 
              | (0x28U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) 
             | (0x29U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand)))) {
            if ((0x20U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) {
                ++(vlSymsp->__Vcoverage[0]);
                vlSelfRef.tt_um_micro__DOT__core__DOT__data_rdata 
                    = (0x1fU & (IData)(vlSelfRef.uio_in));
            } else if ((0x21U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) {
                ++(vlSymsp->__Vcoverage[1]);
                vlSelfRef.tt_um_micro__DOT__core__DOT__data_rdata 
                    = vlSelfRef.tt_um_micro__DOT__core__DOT__gpio_dir;
            } else if ((0x22U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) {
                ++(vlSymsp->__Vcoverage[2]);
                vlSelfRef.tt_um_micro__DOT__core__DOT__data_rdata 
                    = vlSelfRef.tt_um_micro__DOT__core__DOT__timer;
            } else if ((0x23U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) {
                ++(vlSymsp->__Vcoverage[3]);
                vlSelfRef.tt_um_micro__DOT__core__DOT__data_rdata 
                    = vlSelfRef.tt_um_micro__DOT__core__DOT__rx_data;
            } else if ((0x25U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) {
                ++(vlSymsp->__Vcoverage[4]);
                vlSelfRef.tt_um_micro__DOT__core__DOT__data_rdata 
                    = (((0U != (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__tx_inst__DOT__state)) 
                        << 1U) | (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__rx_ready));
            } else if ((0x26U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) {
                ++(vlSymsp->__Vcoverage[5]);
                vlSelfRef.tt_um_micro__DOT__core__DOT__data_rdata 
                    = vlSelfRef.tt_um_micro__DOT__core__DOT__pwm_duty;
            } else if ((0x28U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) {
                ++(vlSymsp->__Vcoverage[6]);
                vlSelfRef.tt_um_micro__DOT__core__DOT__data_rdata 
                    = (0xffU & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__baud_div));
            } else {
                ++(vlSymsp->__Vcoverage[7]);
                vlSelfRef.tt_um_micro__DOT__core__DOT__data_rdata 
                    = (0xffU & ((IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__baud_div) 
                                >> 8U));
            }
        }
        ++(vlSymsp->__Vcoverage[9]);
    }
    ++(vlSymsp->__Vcoverage[10]);
    vlSelfRef.tt_um_micro__DOT__core__DOT__alu_add 
        = (0x1ffU & ((IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__acc) 
                     + (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__data_rdata)));
    vlSelfRef.tt_um_micro__DOT__core__DOT__alu_sub 
        = (0x1ffU & ((IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__acc) 
                     - (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__data_rdata)));
    vlSelfRef.tt_um_micro__DOT__core__DOT__alu_and 
        = ((IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__acc) 
           & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__data_rdata));
    vlSelfRef.tt_um_micro__DOT__core__DOT__alu_or = 
        ((IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__acc) 
         | (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__data_rdata));
    vlSelfRef.tt_um_micro__DOT__core__DOT__alu_xor 
        = ((IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__acc) 
           ^ (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__data_rdata));
    vlSelfRef.tt_um_micro__DOT__core__DOT__alu_shl 
        = (0xffU & ((IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__acc) 
                    << (7U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__data_rdata))));
    vlSelfRef.tt_um_micro__DOT__core__DOT__alu_shr 
        = (0xffU & ((IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__acc) 
                    >> (7U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__data_rdata))));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtt_um_micro___024root___dump_triggers__act(Vtt_um_micro___024root* vlSelf);
#endif  // VL_DEBUG

void Vtt_um_micro___024root___eval_triggers__act(Vtt_um_micro___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_micro___024root___eval_triggers__act\n"); );
    Vtt_um_micro__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((~ (IData)(vlSelfRef.rst_n)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0)));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtt_um_micro___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vtt_um_micro___024root___nba_sequent__TOP__0(Vtt_um_micro___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_micro___024root___nba_sequent__TOP__0\n"); );
    Vtt_um_micro__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vdly__uo_out;
    __Vdly__uo_out = 0;
    CData/*7:0*/ __Vdly__tt_um_micro__DOT__core__DOT__ir;
    __Vdly__tt_um_micro__DOT__core__DOT__ir = 0;
    CData/*7:0*/ __Vdly__tt_um_micro__DOT__core__DOT__operand;
    __Vdly__tt_um_micro__DOT__core__DOT__operand = 0;
    CData/*7:0*/ __Vdly__tt_um_micro__DOT__core__DOT__acc;
    __Vdly__tt_um_micro__DOT__core__DOT__acc = 0;
    CData/*0:0*/ __Vdly__tt_um_micro__DOT__core__DOT__flag_z;
    __Vdly__tt_um_micro__DOT__core__DOT__flag_z = 0;
    SData/*15:0*/ __Vdly__tt_um_micro__DOT__core__DOT__tx_inst__DOT__clk_count;
    __Vdly__tt_um_micro__DOT__core__DOT__tx_inst__DOT__clk_count = 0;
    CData/*1:0*/ __Vdly__tt_um_micro__DOT__core__DOT__tx_inst__DOT__state;
    __Vdly__tt_um_micro__DOT__core__DOT__tx_inst__DOT__state = 0;
    SData/*15:0*/ __Vdly__tt_um_micro__DOT__core__DOT__rx_inst__DOT__clk_count;
    __Vdly__tt_um_micro__DOT__core__DOT__rx_inst__DOT__clk_count = 0;
    CData/*1:0*/ __Vdly__tt_um_micro__DOT__core__DOT__rx_inst__DOT__state;
    __Vdly__tt_um_micro__DOT__core__DOT__rx_inst__DOT__state = 0;
    CData/*7:0*/ __VdlyVal__tt_um_micro__DOT__core__DOT__ram__v0;
    __VdlyVal__tt_um_micro__DOT__core__DOT__ram__v0 = 0;
    CData/*2:0*/ __VdlyDim0__tt_um_micro__DOT__core__DOT__ram__v0;
    __VdlyDim0__tt_um_micro__DOT__core__DOT__ram__v0 = 0;
    CData/*0:0*/ __VdlySet__tt_um_micro__DOT__core__DOT__ram__v0;
    __VdlySet__tt_um_micro__DOT__core__DOT__ram__v0 = 0;
    CData/*0:0*/ __VdlySet__tt_um_micro__DOT__core__DOT__ram__v1;
    __VdlySet__tt_um_micro__DOT__core__DOT__ram__v1 = 0;
    CData/*0:0*/ __VdlySet__tt_um_micro__DOT__core__DOT__ram__v2;
    __VdlySet__tt_um_micro__DOT__core__DOT__ram__v2 = 0;
    CData/*0:0*/ __VdlySet__tt_um_micro__DOT__core__DOT__ram__v3;
    __VdlySet__tt_um_micro__DOT__core__DOT__ram__v3 = 0;
    CData/*0:0*/ __VdlySet__tt_um_micro__DOT__core__DOT__ram__v4;
    __VdlySet__tt_um_micro__DOT__core__DOT__ram__v4 = 0;
    CData/*0:0*/ __VdlySet__tt_um_micro__DOT__core__DOT__ram__v5;
    __VdlySet__tt_um_micro__DOT__core__DOT__ram__v5 = 0;
    CData/*0:0*/ __VdlySet__tt_um_micro__DOT__core__DOT__ram__v6;
    __VdlySet__tt_um_micro__DOT__core__DOT__ram__v6 = 0;
    CData/*0:0*/ __VdlySet__tt_um_micro__DOT__core__DOT__ram__v7;
    __VdlySet__tt_um_micro__DOT__core__DOT__ram__v7 = 0;
    CData/*0:0*/ __VdlySet__tt_um_micro__DOT__core__DOT__ram__v8;
    __VdlySet__tt_um_micro__DOT__core__DOT__ram__v8 = 0;
    // Body
    __Vdly__uo_out = vlSelfRef.uo_out;
    __Vdly__tt_um_micro__DOT__core__DOT__ir = vlSelfRef.tt_um_micro__DOT__core__DOT__ir;
    __Vdly__tt_um_micro__DOT__core__DOT__flag_z = vlSelfRef.tt_um_micro__DOT__core__DOT__flag_z;
    __Vdly__tt_um_micro__DOT__core__DOT__acc = vlSelfRef.tt_um_micro__DOT__core__DOT__acc;
    __Vdly__tt_um_micro__DOT__core__DOT__operand = vlSelfRef.tt_um_micro__DOT__core__DOT__operand;
    __VdlySet__tt_um_micro__DOT__core__DOT__ram__v0 = 0U;
    __VdlySet__tt_um_micro__DOT__core__DOT__ram__v1 = 0U;
    __VdlySet__tt_um_micro__DOT__core__DOT__ram__v2 = 0U;
    __VdlySet__tt_um_micro__DOT__core__DOT__ram__v3 = 0U;
    __VdlySet__tt_um_micro__DOT__core__DOT__ram__v4 = 0U;
    __VdlySet__tt_um_micro__DOT__core__DOT__ram__v5 = 0U;
    __VdlySet__tt_um_micro__DOT__core__DOT__ram__v6 = 0U;
    __VdlySet__tt_um_micro__DOT__core__DOT__ram__v7 = 0U;
    __VdlySet__tt_um_micro__DOT__core__DOT__ram__v8 = 0U;
    __Vdly__tt_um_micro__DOT__core__DOT__tx_inst__DOT__clk_count 
        = vlSelfRef.tt_um_micro__DOT__core__DOT__tx_inst__DOT__clk_count;
    __Vdly__tt_um_micro__DOT__core__DOT__tx_inst__DOT__state 
        = vlSelfRef.tt_um_micro__DOT__core__DOT__tx_inst__DOT__state;
    __Vdly__tt_um_micro__DOT__core__DOT__rx_inst__DOT__clk_count 
        = vlSelfRef.tt_um_micro__DOT__core__DOT__rx_inst__DOT__clk_count;
    __Vdly__tt_um_micro__DOT__core__DOT__rx_inst__DOT__state 
        = vlSelfRef.tt_um_micro__DOT__core__DOT__rx_inst__DOT__state;
    if (vlSelfRef.rst_n) {
        if ((2U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__tx_inst__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__tx_inst__DOT__state))) {
                vlSelfRef.tt_um_micro__DOT__core__DOT__uart_tx_pin = 1U;
                if (((IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__tx_inst__DOT__clk_count) 
                     != (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__baud_div))) {
                    __Vdly__tt_um_micro__DOT__core__DOT__tx_inst__DOT__clk_count 
                        = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__tx_inst__DOT__clk_count)));
                    ++(vlSymsp->__Vcoverage[77]);
                } else {
                    ++(vlSymsp->__Vcoverage[78]);
                    __Vdly__tt_um_micro__DOT__core__DOT__tx_inst__DOT__clk_count = 0U;
                    __Vdly__tt_um_micro__DOT__core__DOT__tx_inst__DOT__state = 0U;
                }
                ++(vlSymsp->__Vcoverage[79]);
            } else {
                vlSelfRef.tt_um_micro__DOT__core__DOT__uart_tx_pin 
                    = (1U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__tx_inst__DOT__tx_data_reg));
                if (((IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__tx_inst__DOT__clk_count) 
                     != (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__baud_div))) {
                    ++(vlSymsp->__Vcoverage[74]);
                    __Vdly__tt_um_micro__DOT__core__DOT__tx_inst__DOT__clk_count 
                        = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__tx_inst__DOT__clk_count)));
                } else {
                    __Vdly__tt_um_micro__DOT__core__DOT__tx_inst__DOT__clk_count = 0U;
                    vlSelfRef.tt_um_micro__DOT__core__DOT__tx_inst__DOT__tx_data_reg 
                        = (0x7fU & ((IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__tx_inst__DOT__tx_data_reg) 
                                    >> 1U));
                    if ((7U > (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__tx_inst__DOT__bit_index))) {
                        ++(vlSymsp->__Vcoverage[72]);
                        vlSelfRef.tt_um_micro__DOT__core__DOT__tx_inst__DOT__bit_index 
                            = (7U & ((IData)(1U) + (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__tx_inst__DOT__bit_index)));
                    } else {
                        ++(vlSymsp->__Vcoverage[73]);
                        vlSelfRef.tt_um_micro__DOT__core__DOT__tx_inst__DOT__bit_index = 0U;
                        __Vdly__tt_um_micro__DOT__core__DOT__tx_inst__DOT__state = 3U;
                    }
                    ++(vlSymsp->__Vcoverage[75]);
                }
                ++(vlSymsp->__Vcoverage[76]);
            }
        } else if ((1U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__tx_inst__DOT__state))) {
            vlSelfRef.tt_um_micro__DOT__core__DOT__uart_tx_pin = 0U;
            if (((IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__tx_inst__DOT__clk_count) 
                 != (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__baud_div))) {
                ++(vlSymsp->__Vcoverage[69]);
                __Vdly__tt_um_micro__DOT__core__DOT__tx_inst__DOT__clk_count 
                    = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__tx_inst__DOT__clk_count)));
            } else {
                ++(vlSymsp->__Vcoverage[70]);
                __Vdly__tt_um_micro__DOT__core__DOT__tx_inst__DOT__clk_count = 0U;
                __Vdly__tt_um_micro__DOT__core__DOT__tx_inst__DOT__state = 2U;
            }
            ++(vlSymsp->__Vcoverage[71]);
        } else {
            vlSelfRef.tt_um_micro__DOT__core__DOT__uart_tx_pin = 1U;
            if (vlSelfRef.tt_um_micro__DOT__core__DOT__tx_start) {
                ++(vlSymsp->__Vcoverage[66]);
                vlSelfRef.tt_um_micro__DOT__core__DOT__tx_inst__DOT__tx_data_reg 
                    = vlSelfRef.tt_um_micro__DOT__core__DOT__acc;
                __Vdly__tt_um_micro__DOT__core__DOT__tx_inst__DOT__state = 1U;
            } else {
                ++(vlSymsp->__Vcoverage[67]);
            }
            ++(vlSymsp->__Vcoverage[68]);
        }
        ++(vlSymsp->__Vcoverage[82]);
    } else {
        ++(vlSymsp->__Vcoverage[81]);
        __Vdly__tt_um_micro__DOT__core__DOT__tx_inst__DOT__clk_count = 0U;
        vlSelfRef.tt_um_micro__DOT__core__DOT__tx_inst__DOT__bit_index = 0U;
        vlSelfRef.tt_um_micro__DOT__core__DOT__tx_inst__DOT__tx_data_reg = 0U;
        __Vdly__tt_um_micro__DOT__core__DOT__tx_inst__DOT__state = 0U;
        vlSelfRef.tt_um_micro__DOT__core__DOT__uart_tx_pin = 1U;
    }
    ++(vlSymsp->__Vcoverage[83]);
    if (vlSelfRef.rst_n) {
        if (vlSelfRef.tt_um_micro__DOT__core__DOT__rx_clear) {
            ++(vlSymsp->__Vcoverage[87]);
            vlSelfRef.tt_um_micro__DOT__core__DOT__rx_ready = 0U;
        } else {
            ++(vlSymsp->__Vcoverage[88]);
        }
        if ((2U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__rx_inst__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__rx_inst__DOT__state))) {
                if (((IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__rx_inst__DOT__clk_count) 
                     != (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__baud_div))) {
                    ++(vlSymsp->__Vcoverage[104]);
                    __Vdly__tt_um_micro__DOT__core__DOT__rx_inst__DOT__clk_count 
                        = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__rx_inst__DOT__clk_count)));
                } else {
                    __Vdly__tt_um_micro__DOT__core__DOT__rx_inst__DOT__clk_count = 0U;
                    if (vlSelfRef.tt_um_micro__DOT__core__DOT__rx_inst__DOT__rx_r2) {
                        ++(vlSymsp->__Vcoverage[102]);
                        vlSelfRef.tt_um_micro__DOT__core__DOT__rx_ready = 1U;
                    } else {
                        ++(vlSymsp->__Vcoverage[103]);
                    }
                    __Vdly__tt_um_micro__DOT__core__DOT__rx_inst__DOT__state = 0U;
                    ++(vlSymsp->__Vcoverage[105]);
                }
                ++(vlSymsp->__Vcoverage[106]);
            } else {
                if (((IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__rx_inst__DOT__clk_count) 
                     != (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__baud_div))) {
                    ++(vlSymsp->__Vcoverage[99]);
                    __Vdly__tt_um_micro__DOT__core__DOT__rx_inst__DOT__clk_count 
                        = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__rx_inst__DOT__clk_count)));
                } else {
                    __Vdly__tt_um_micro__DOT__core__DOT__rx_inst__DOT__clk_count = 0U;
                    vlSelfRef.tt_um_micro__DOT__core__DOT__rx_data 
                        = (((IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__rx_inst__DOT__rx_r2) 
                            << 7U) | (0x7fU & ((IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__rx_data) 
                                               >> 1U)));
                    if ((7U > (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__rx_inst__DOT__bit_index))) {
                        ++(vlSymsp->__Vcoverage[97]);
                        vlSelfRef.tt_um_micro__DOT__core__DOT__rx_inst__DOT__bit_index 
                            = (7U & ((IData)(1U) + (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__rx_inst__DOT__bit_index)));
                    } else {
                        ++(vlSymsp->__Vcoverage[98]);
                        vlSelfRef.tt_um_micro__DOT__core__DOT__rx_inst__DOT__bit_index = 0U;
                        __Vdly__tt_um_micro__DOT__core__DOT__rx_inst__DOT__state = 3U;
                    }
                    ++(vlSymsp->__Vcoverage[100]);
                }
                ++(vlSymsp->__Vcoverage[101]);
            }
        } else if ((1U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__rx_inst__DOT__state))) {
            if (((IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__rx_inst__DOT__clk_count) 
                 == (0xffffU & VL_SHIFTR_III(16,16,32, (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__baud_div), 1U)))) {
                __Vdly__tt_um_micro__DOT__core__DOT__rx_inst__DOT__clk_count = 0U;
                if (vlSelfRef.tt_um_micro__DOT__core__DOT__rx_inst__DOT__rx_r2) {
                    ++(vlSymsp->__Vcoverage[93]);
                    __Vdly__tt_um_micro__DOT__core__DOT__rx_inst__DOT__state = 0U;
                } else {
                    ++(vlSymsp->__Vcoverage[92]);
                    __Vdly__tt_um_micro__DOT__core__DOT__rx_inst__DOT__state = 2U;
                }
                ++(vlSymsp->__Vcoverage[94]);
            } else {
                ++(vlSymsp->__Vcoverage[95]);
                __Vdly__tt_um_micro__DOT__core__DOT__rx_inst__DOT__clk_count 
                    = (0xffffU & ((IData)(1U) + (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__rx_inst__DOT__clk_count)));
            }
            ++(vlSymsp->__Vcoverage[96]);
        } else {
            if (vlSelfRef.tt_um_micro__DOT__core__DOT__rx_inst__DOT__rx_r2) {
                ++(vlSymsp->__Vcoverage[90]);
            } else {
                ++(vlSymsp->__Vcoverage[89]);
                __Vdly__tt_um_micro__DOT__core__DOT__rx_inst__DOT__state = 1U;
            }
            ++(vlSymsp->__Vcoverage[91]);
        }
        ++(vlSymsp->__Vcoverage[109]);
    } else {
        ++(vlSymsp->__Vcoverage[108]);
        __Vdly__tt_um_micro__DOT__core__DOT__rx_inst__DOT__clk_count = 0U;
        vlSelfRef.tt_um_micro__DOT__core__DOT__rx_inst__DOT__bit_index = 0U;
        vlSelfRef.tt_um_micro__DOT__core__DOT__rx_data = 0U;
        __Vdly__tt_um_micro__DOT__core__DOT__rx_inst__DOT__state = 0U;
        vlSelfRef.tt_um_micro__DOT__core__DOT__rx_ready = 0U;
    }
    ++(vlSymsp->__Vcoverage[110]);
    vlSelfRef.tt_um_micro__DOT__core__DOT__tx_inst__DOT__clk_count 
        = __Vdly__tt_um_micro__DOT__core__DOT__tx_inst__DOT__clk_count;
    vlSelfRef.tt_um_micro__DOT__core__DOT__tx_inst__DOT__state 
        = __Vdly__tt_um_micro__DOT__core__DOT__tx_inst__DOT__state;
    vlSelfRef.tt_um_micro__DOT__core__DOT__rx_inst__DOT__clk_count 
        = __Vdly__tt_um_micro__DOT__core__DOT__rx_inst__DOT__clk_count;
    vlSelfRef.tt_um_micro__DOT__core__DOT__rx_inst__DOT__state 
        = __Vdly__tt_um_micro__DOT__core__DOT__rx_inst__DOT__state;
    if (vlSelfRef.rst_n) {
        ++(vlSymsp->__Vcoverage[85]);
        vlSelfRef.tt_um_micro__DOT__core__DOT__rx_inst__DOT__rx_r2 
            = vlSelfRef.tt_um_micro__DOT__core__DOT__rx_inst__DOT__rx_r1;
        vlSelfRef.tt_um_micro__DOT__core__DOT__rx_inst__DOT__rx_r1 
            = (1U & ((IData)(vlSelfRef.uio_in) >> 6U));
    } else {
        ++(vlSymsp->__Vcoverage[84]);
        vlSelfRef.tt_um_micro__DOT__core__DOT__rx_inst__DOT__rx_r1 = 1U;
        vlSelfRef.tt_um_micro__DOT__core__DOT__rx_inst__DOT__rx_r2 = 1U;
    }
    ++(vlSymsp->__Vcoverage[86]);
    if (vlSelfRef.rst_n) {
        if (vlSelfRef.ena) {
            vlSelfRef.tt_um_micro__DOT__core__DOT__timer 
                = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__timer)));
            vlSelfRef.tt_um_micro__DOT__core__DOT__pwm_counter 
                = (0xffU & ((IData)(1U) + (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__pwm_counter)));
            vlSelfRef.tt_um_micro__DOT__core__DOT__tx_start = 0U;
            vlSelfRef.tt_um_micro__DOT__core__DOT__rx_clear = 0U;
            if ((0U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__state))) {
                __Vdly__uo_out = (0xffU & ((IData)(1U) 
                                           + (IData)(vlSelfRef.uo_out)));
                ++(vlSymsp->__Vcoverage[23]);
                __Vdly__tt_um_micro__DOT__core__DOT__ir 
                    = vlSelfRef.ui_in;
            } else if ((1U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__state))) {
                ++(vlSymsp->__Vcoverage[24]);
                __Vdly__uo_out = (0xffU & ((IData)(1U) 
                                           + (IData)(vlSelfRef.uo_out)));
                __Vdly__tt_um_micro__DOT__core__DOT__operand 
                    = vlSelfRef.ui_in;
            } else if ((2U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__state))) {
                if ((0x80U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__ir))) {
                    ++(vlSymsp->__Vcoverage[59]);
                } else if ((0x40U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__ir))) {
                    ++(vlSymsp->__Vcoverage[59]);
                } else if ((0x20U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__ir))) {
                    ++(vlSymsp->__Vcoverage[59]);
                } else if ((0x10U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__ir))) {
                    if ((8U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__ir))) {
                        ++(vlSymsp->__Vcoverage[59]);
                    } else if ((4U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__ir))) {
                        ++(vlSymsp->__Vcoverage[59]);
                    } else if ((2U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__ir))) {
                        ++(vlSymsp->__Vcoverage[59]);
                    } else if ((1U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__ir))) {
                        ++(vlSymsp->__Vcoverage[59]);
                    } else {
                        if (vlSelfRef.tt_um_micro__DOT__core__DOT__flag_c) {
                            ++(vlSymsp->__Vcoverage[56]);
                            __Vdly__uo_out = vlSelfRef.tt_um_micro__DOT__core__DOT__operand;
                        } else {
                            ++(vlSymsp->__Vcoverage[57]);
                        }
                        ++(vlSymsp->__Vcoverage[58]);
                    }
                } else if ((8U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__ir))) {
                    if ((4U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__ir))) {
                        if ((2U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__ir))) {
                            if ((1U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__ir))) {
                                if (vlSelfRef.tt_um_micro__DOT__core__DOT__flag_z) {
                                    ++(vlSymsp->__Vcoverage[54]);
                                } else {
                                    ++(vlSymsp->__Vcoverage[53]);
                                    __Vdly__uo_out 
                                        = vlSelfRef.tt_um_micro__DOT__core__DOT__operand;
                                }
                                ++(vlSymsp->__Vcoverage[55]);
                            } else {
                                ++(vlSymsp->__Vcoverage[52]);
                                __Vdly__uo_out = vlSelfRef.tt_um_micro__DOT__core__DOT__ret_addr;
                            }
                        } else if ((1U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__ir))) {
                            ++(vlSymsp->__Vcoverage[51]);
                            __Vdly__uo_out = vlSelfRef.tt_um_micro__DOT__core__DOT__operand;
                            vlSelfRef.tt_um_micro__DOT__core__DOT__ret_addr 
                                = vlSelfRef.uo_out;
                        } else {
                            ++(vlSymsp->__Vcoverage[50]);
                            __Vdly__tt_um_micro__DOT__core__DOT__acc 
                                = vlSelfRef.tt_um_micro__DOT__core__DOT__alu_shr;
                            __Vdly__tt_um_micro__DOT__core__DOT__flag_z 
                                = (0U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__alu_shr));
                            vlSelfRef.tt_um_micro__DOT__core__DOT__flag_c = 0U;
                        }
                    } else if ((2U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__ir))) {
                        if ((1U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__ir))) {
                            ++(vlSymsp->__Vcoverage[49]);
                            __Vdly__tt_um_micro__DOT__core__DOT__acc 
                                = vlSelfRef.tt_um_micro__DOT__core__DOT__alu_shl;
                            __Vdly__tt_um_micro__DOT__core__DOT__flag_z 
                                = (0U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__alu_shl));
                            vlSelfRef.tt_um_micro__DOT__core__DOT__flag_c = 0U;
                        } else {
                            ++(vlSymsp->__Vcoverage[48]);
                            __Vdly__tt_um_micro__DOT__core__DOT__acc 
                                = vlSelfRef.tt_um_micro__DOT__core__DOT__alu_xor;
                            __Vdly__tt_um_micro__DOT__core__DOT__flag_z 
                                = (0U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__alu_xor));
                            vlSelfRef.tt_um_micro__DOT__core__DOT__flag_c = 0U;
                        }
                    } else if ((1U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__ir))) {
                        ++(vlSymsp->__Vcoverage[47]);
                        __Vdly__tt_um_micro__DOT__core__DOT__acc 
                            = vlSelfRef.tt_um_micro__DOT__core__DOT__alu_or;
                        __Vdly__tt_um_micro__DOT__core__DOT__flag_z 
                            = (0U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__alu_or));
                        vlSelfRef.tt_um_micro__DOT__core__DOT__flag_c = 0U;
                    } else {
                        ++(vlSymsp->__Vcoverage[46]);
                        __Vdly__tt_um_micro__DOT__core__DOT__acc 
                            = vlSelfRef.tt_um_micro__DOT__core__DOT__alu_and;
                        __Vdly__tt_um_micro__DOT__core__DOT__flag_z 
                            = (0U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__alu_and));
                        vlSelfRef.tt_um_micro__DOT__core__DOT__flag_c = 0U;
                    }
                } else if ((4U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__ir))) {
                    if ((2U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__ir))) {
                        if ((1U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__ir))) {
                            if (vlSelfRef.tt_um_micro__DOT__core__DOT__flag_z) {
                                ++(vlSymsp->__Vcoverage[43]);
                                __Vdly__uo_out = vlSelfRef.tt_um_micro__DOT__core__DOT__operand;
                            } else {
                                ++(vlSymsp->__Vcoverage[44]);
                            }
                            ++(vlSymsp->__Vcoverage[45]);
                        } else {
                            ++(vlSymsp->__Vcoverage[42]);
                            __Vdly__uo_out = vlSelfRef.tt_um_micro__DOT__core__DOT__operand;
                        }
                    } else if ((1U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__ir))) {
                        ++(vlSymsp->__Vcoverage[41]);
                        vlSelfRef.tt_um_micro__DOT__core__DOT__flag_c 
                            = (1U & ((IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__alu_sub) 
                                     >> 8U));
                        __Vdly__tt_um_micro__DOT__core__DOT__acc 
                            = (0xffU & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__alu_sub));
                        __Vdly__tt_um_micro__DOT__core__DOT__flag_z 
                            = (0U == (0xffU & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__alu_sub)));
                    } else {
                        ++(vlSymsp->__Vcoverage[40]);
                        vlSelfRef.tt_um_micro__DOT__core__DOT__flag_c 
                            = (1U & ((IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__alu_add) 
                                     >> 8U));
                        __Vdly__tt_um_micro__DOT__core__DOT__acc 
                            = (0xffU & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__alu_add));
                        __Vdly__tt_um_micro__DOT__core__DOT__flag_z 
                            = (0U == (0xffU & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__alu_add)));
                    }
                } else if ((2U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__ir))) {
                    if ((1U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__ir))) {
                        if ((7U >= (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) {
                            ++(vlSymsp->__Vcoverage[37]);
                            __VdlyVal__tt_um_micro__DOT__core__DOT__ram__v0 
                                = vlSelfRef.tt_um_micro__DOT__core__DOT__acc;
                            __VdlyDim0__tt_um_micro__DOT__core__DOT__ram__v0 
                                = (7U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand));
                            __VdlySet__tt_um_micro__DOT__core__DOT__ram__v0 = 1U;
                        } else {
                            if ((0x20U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) {
                                ++(vlSymsp->__Vcoverage[29]);
                                vlSelfRef.tt_um_micro__DOT__core__DOT__gpio_out 
                                    = (0x1fU & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__acc));
                            } else if ((0x21U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) {
                                ++(vlSymsp->__Vcoverage[30]);
                                vlSelfRef.tt_um_micro__DOT__core__DOT__gpio_dir 
                                    = (0x1fU & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__acc));
                            } else if ((0x22U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) {
                                ++(vlSymsp->__Vcoverage[31]);
                                vlSelfRef.tt_um_micro__DOT__core__DOT__timer = 0U;
                            } else if ((0x24U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) {
                                ++(vlSymsp->__Vcoverage[32]);
                                vlSelfRef.tt_um_micro__DOT__core__DOT__tx_start = 1U;
                            } else if ((0x26U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) {
                                ++(vlSymsp->__Vcoverage[33]);
                                vlSelfRef.tt_um_micro__DOT__core__DOT__pwm_duty 
                                    = vlSelfRef.tt_um_micro__DOT__core__DOT__acc;
                            } else if ((0x28U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) {
                                ++(vlSymsp->__Vcoverage[34]);
                                vlSelfRef.tt_um_micro__DOT__core__DOT__baud_div 
                                    = ((0xff00U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__baud_div)) 
                                       | (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__acc));
                            } else if ((0x29U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) {
                                ++(vlSymsp->__Vcoverage[35]);
                                vlSelfRef.tt_um_micro__DOT__core__DOT__baud_div 
                                    = ((0xffU & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__baud_div)) 
                                       | ((IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__acc) 
                                          << 8U));
                            } else {
                                ++(vlSymsp->__Vcoverage[36]);
                            }
                            ++(vlSymsp->__Vcoverage[38]);
                        }
                        ++(vlSymsp->__Vcoverage[39]);
                    } else {
                        __Vdly__tt_um_micro__DOT__core__DOT__acc 
                            = vlSelfRef.tt_um_micro__DOT__core__DOT__data_rdata;
                        __Vdly__tt_um_micro__DOT__core__DOT__flag_z 
                            = (0U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__data_rdata));
                        vlSelfRef.tt_um_micro__DOT__core__DOT__flag_c = 0U;
                        if ((0x23U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) {
                            ++(vlSymsp->__Vcoverage[26]);
                            vlSelfRef.tt_um_micro__DOT__core__DOT__rx_clear = 1U;
                        } else {
                            ++(vlSymsp->__Vcoverage[27]);
                        }
                        ++(vlSymsp->__Vcoverage[28]);
                    }
                } else if ((1U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__ir))) {
                    ++(vlSymsp->__Vcoverage[25]);
                    __Vdly__tt_um_micro__DOT__core__DOT__acc 
                        = vlSelfRef.tt_um_micro__DOT__core__DOT__operand;
                    vlSelfRef.tt_um_micro__DOT__core__DOT__flag_c = 0U;
                    __Vdly__tt_um_micro__DOT__core__DOT__flag_z 
                        = (0U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand));
                } else {
                    ++(vlSymsp->__Vcoverage[59]);
                }
                ++(vlSymsp->__Vcoverage[60]);
            } else {
                ++(vlSymsp->__Vcoverage[61]);
            }
            ++(vlSymsp->__Vcoverage[62]);
        } else {
            ++(vlSymsp->__Vcoverage[63]);
        }
    } else {
        __Vdly__uo_out = 0U;
        vlSelfRef.tt_um_micro__DOT__core__DOT__timer = 0U;
        vlSelfRef.tt_um_micro__DOT__core__DOT__pwm_counter = 0U;
        ++(vlSymsp->__Vcoverage[22]);
        __Vdly__tt_um_micro__DOT__core__DOT__acc = 0U;
        __Vdly__tt_um_micro__DOT__core__DOT__ir = 0U;
        __Vdly__tt_um_micro__DOT__core__DOT__operand = 0U;
        vlSelfRef.tt_um_micro__DOT__core__DOT__ret_addr = 0U;
        __Vdly__tt_um_micro__DOT__core__DOT__flag_z = 0U;
        vlSelfRef.tt_um_micro__DOT__core__DOT__flag_c = 0U;
        vlSelfRef.tt_um_micro__DOT__core__DOT__baud_div = 0x1b2U;
        vlSelfRef.tt_um_micro__DOT__core__DOT__gpio_out = 0U;
        vlSelfRef.tt_um_micro__DOT__core__DOT__gpio_dir = 0U;
        vlSelfRef.tt_um_micro__DOT__core__DOT__pwm_duty = 0U;
        vlSelfRef.tt_um_micro__DOT__core__DOT__tx_start = 0U;
        vlSelfRef.tt_um_micro__DOT__core__DOT__rx_clear = 0U;
        __VdlySet__tt_um_micro__DOT__core__DOT__ram__v1 = 1U;
        ++(vlSymsp->__Vcoverage[22]);
        vlSelfRef.tt_um_micro__DOT__core__DOT__timer = 0U;
        vlSelfRef.tt_um_micro__DOT__core__DOT__pwm_counter = 0U;
        __VdlySet__tt_um_micro__DOT__core__DOT__ram__v2 = 1U;
        ++(vlSymsp->__Vcoverage[22]);
        __Vdly__tt_um_micro__DOT__core__DOT__acc = 0U;
        __Vdly__tt_um_micro__DOT__core__DOT__ir = 0U;
        __Vdly__tt_um_micro__DOT__core__DOT__operand = 0U;
        vlSelfRef.tt_um_micro__DOT__core__DOT__ret_addr = 0U;
        __Vdly__tt_um_micro__DOT__core__DOT__flag_z = 0U;
        vlSelfRef.tt_um_micro__DOT__core__DOT__flag_c = 0U;
        vlSelfRef.tt_um_micro__DOT__core__DOT__baud_div = 0x1b2U;
        vlSelfRef.tt_um_micro__DOT__core__DOT__gpio_out = 0U;
        vlSelfRef.tt_um_micro__DOT__core__DOT__gpio_dir = 0U;
        vlSelfRef.tt_um_micro__DOT__core__DOT__pwm_duty = 0U;
        vlSelfRef.tt_um_micro__DOT__core__DOT__tx_start = 0U;
        vlSelfRef.tt_um_micro__DOT__core__DOT__rx_clear = 0U;
        __VdlySet__tt_um_micro__DOT__core__DOT__ram__v3 = 1U;
        ++(vlSymsp->__Vcoverage[22]);
        __VdlySet__tt_um_micro__DOT__core__DOT__ram__v4 = 1U;
        ++(vlSymsp->__Vcoverage[22]);
        __VdlySet__tt_um_micro__DOT__core__DOT__ram__v5 = 1U;
        ++(vlSymsp->__Vcoverage[22]);
        __VdlySet__tt_um_micro__DOT__core__DOT__ram__v6 = 1U;
        ++(vlSymsp->__Vcoverage[22]);
        __VdlySet__tt_um_micro__DOT__core__DOT__ram__v7 = 1U;
        ++(vlSymsp->__Vcoverage[22]);
        __VdlySet__tt_um_micro__DOT__core__DOT__ram__v8 = 1U;
        ++(vlSymsp->__Vcoverage[64]);
    }
    ++(vlSymsp->__Vcoverage[65]);
    vlSelfRef.uo_out = __Vdly__uo_out;
    vlSelfRef.tt_um_micro__DOT__core__DOT__ir = __Vdly__tt_um_micro__DOT__core__DOT__ir;
    vlSelfRef.tt_um_micro__DOT__core__DOT__flag_z = __Vdly__tt_um_micro__DOT__core__DOT__flag_z;
    vlSelfRef.tt_um_micro__DOT__core__DOT__acc = __Vdly__tt_um_micro__DOT__core__DOT__acc;
    vlSelfRef.tt_um_micro__DOT__core__DOT__operand 
        = __Vdly__tt_um_micro__DOT__core__DOT__operand;
    if (__VdlySet__tt_um_micro__DOT__core__DOT__ram__v0) {
        vlSelfRef.tt_um_micro__DOT__core__DOT__ram[__VdlyDim0__tt_um_micro__DOT__core__DOT__ram__v0] 
            = __VdlyVal__tt_um_micro__DOT__core__DOT__ram__v0;
    }
    if (__VdlySet__tt_um_micro__DOT__core__DOT__ram__v1) {
        vlSelfRef.tt_um_micro__DOT__core__DOT__ram[0U] = 0U;
    }
    if (__VdlySet__tt_um_micro__DOT__core__DOT__ram__v2) {
        vlSelfRef.tt_um_micro__DOT__core__DOT__ram[1U] = 0U;
    }
    if (__VdlySet__tt_um_micro__DOT__core__DOT__ram__v3) {
        vlSelfRef.tt_um_micro__DOT__core__DOT__ram[2U] = 0U;
    }
    if (__VdlySet__tt_um_micro__DOT__core__DOT__ram__v4) {
        vlSelfRef.tt_um_micro__DOT__core__DOT__ram[3U] = 0U;
    }
    if (__VdlySet__tt_um_micro__DOT__core__DOT__ram__v5) {
        vlSelfRef.tt_um_micro__DOT__core__DOT__ram[4U] = 0U;
    }
    if (__VdlySet__tt_um_micro__DOT__core__DOT__ram__v6) {
        vlSelfRef.tt_um_micro__DOT__core__DOT__ram[5U] = 0U;
    }
    if (__VdlySet__tt_um_micro__DOT__core__DOT__ram__v7) {
        vlSelfRef.tt_um_micro__DOT__core__DOT__ram[6U] = 0U;
    }
    if (__VdlySet__tt_um_micro__DOT__core__DOT__ram__v8) {
        vlSelfRef.tt_um_micro__DOT__core__DOT__ram[7U] = 0U;
    }
    if (vlSelfRef.rst_n) {
        if (vlSelfRef.ena) {
            ++(vlSymsp->__Vcoverage[11]);
            vlSelfRef.tt_um_micro__DOT__core__DOT__state 
                = vlSelfRef.tt_um_micro__DOT__core__DOT__next_state;
        } else {
            ++(vlSymsp->__Vcoverage[12]);
        }
    } else {
        ++(vlSymsp->__Vcoverage[13]);
        vlSelfRef.tt_um_micro__DOT__core__DOT__state = 0U;
    }
    ++(vlSymsp->__Vcoverage[14]);
    vlSelfRef.uio_oe = (0xa0U | (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__gpio_dir));
    vlSelfRef.uio_out = ((((IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__pwm_counter) 
                           < (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__pwm_duty)) 
                          << 7U) | (((IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__uart_tx_pin) 
                                     << 5U) | (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__gpio_out)));
    vlSelfRef.tt_um_micro__DOT__core__DOT__data_rdata = 0U;
    if ((7U >= (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) {
        vlSelfRef.tt_um_micro__DOT__core__DOT__data_rdata 
            = vlSelfRef.tt_um_micro__DOT__core__DOT__ram
            [(7U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))];
        ++(vlSymsp->__Vcoverage[8]);
    } else {
        if (((((((((0x20U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand)) 
                   | (0x21U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) 
                  | (0x22U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) 
                 | (0x23U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) 
                | (0x25U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) 
               | (0x26U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) 
              | (0x28U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) 
             | (0x29U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand)))) {
            if ((0x20U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) {
                ++(vlSymsp->__Vcoverage[0]);
                vlSelfRef.tt_um_micro__DOT__core__DOT__data_rdata 
                    = (0x1fU & (IData)(vlSelfRef.uio_in));
            } else if ((0x21U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) {
                ++(vlSymsp->__Vcoverage[1]);
                vlSelfRef.tt_um_micro__DOT__core__DOT__data_rdata 
                    = vlSelfRef.tt_um_micro__DOT__core__DOT__gpio_dir;
            } else if ((0x22U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) {
                ++(vlSymsp->__Vcoverage[2]);
                vlSelfRef.tt_um_micro__DOT__core__DOT__data_rdata 
                    = vlSelfRef.tt_um_micro__DOT__core__DOT__timer;
            } else if ((0x23U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) {
                ++(vlSymsp->__Vcoverage[3]);
                vlSelfRef.tt_um_micro__DOT__core__DOT__data_rdata 
                    = vlSelfRef.tt_um_micro__DOT__core__DOT__rx_data;
            } else if ((0x25U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) {
                ++(vlSymsp->__Vcoverage[4]);
                vlSelfRef.tt_um_micro__DOT__core__DOT__data_rdata 
                    = (((0U != (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__tx_inst__DOT__state)) 
                        << 1U) | (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__rx_ready));
            } else if ((0x26U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) {
                ++(vlSymsp->__Vcoverage[5]);
                vlSelfRef.tt_um_micro__DOT__core__DOT__data_rdata 
                    = vlSelfRef.tt_um_micro__DOT__core__DOT__pwm_duty;
            } else if ((0x28U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__operand))) {
                ++(vlSymsp->__Vcoverage[6]);
                vlSelfRef.tt_um_micro__DOT__core__DOT__data_rdata 
                    = (0xffU & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__baud_div));
            } else {
                ++(vlSymsp->__Vcoverage[7]);
                vlSelfRef.tt_um_micro__DOT__core__DOT__data_rdata 
                    = (0xffU & ((IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__baud_div) 
                                >> 8U));
            }
        }
        ++(vlSymsp->__Vcoverage[9]);
    }
    ++(vlSymsp->__Vcoverage[10]);
    vlSelfRef.tt_um_micro__DOT__core__DOT__alu_add 
        = (0x1ffU & ((IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__acc) 
                     + (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__data_rdata)));
    vlSelfRef.tt_um_micro__DOT__core__DOT__alu_sub 
        = (0x1ffU & ((IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__acc) 
                     - (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__data_rdata)));
    vlSelfRef.tt_um_micro__DOT__core__DOT__alu_and 
        = ((IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__acc) 
           & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__data_rdata));
    vlSelfRef.tt_um_micro__DOT__core__DOT__alu_or = 
        ((IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__acc) 
         | (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__data_rdata));
    vlSelfRef.tt_um_micro__DOT__core__DOT__alu_xor 
        = ((IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__acc) 
           ^ (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__data_rdata));
    vlSelfRef.tt_um_micro__DOT__core__DOT__alu_shl 
        = (0xffU & ((IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__acc) 
                    << (7U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__data_rdata))));
    vlSelfRef.tt_um_micro__DOT__core__DOT__alu_shr 
        = (0xffU & ((IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__acc) 
                    >> (7U & (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__data_rdata))));
    vlSelfRef.tt_um_micro__DOT__core__DOT__next_state 
        = vlSelfRef.tt_um_micro__DOT__core__DOT__state;
    if ((0U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__state))) {
        if ((0U == (IData)(vlSelfRef.ui_in))) {
            vlSelfRef.tt_um_micro__DOT__core__DOT__next_state = 0U;
            ++(vlSymsp->__Vcoverage[15]);
        } else {
            ++(vlSymsp->__Vcoverage[16]);
            vlSelfRef.tt_um_micro__DOT__core__DOT__next_state = 1U;
        }
        ++(vlSymsp->__Vcoverage[17]);
    } else if ((1U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__state))) {
        ++(vlSymsp->__Vcoverage[18]);
        vlSelfRef.tt_um_micro__DOT__core__DOT__next_state = 2U;
    } else if ((2U == (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__state))) {
        ++(vlSymsp->__Vcoverage[19]);
        vlSelfRef.tt_um_micro__DOT__core__DOT__next_state = 0U;
    } else {
        ++(vlSymsp->__Vcoverage[20]);
        vlSelfRef.tt_um_micro__DOT__core__DOT__next_state = 0U;
    }
    ++(vlSymsp->__Vcoverage[21]);
}
