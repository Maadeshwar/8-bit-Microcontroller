// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtt_um_micro.h for the primary calling header

#include "Vtt_um_micro__pch.h"
#include "Vtt_um_micro__Syms.h"
#include "Vtt_um_micro___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtt_um_micro___024root___dump_triggers__stl(Vtt_um_micro___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtt_um_micro___024root___eval_triggers__stl(Vtt_um_micro___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_micro___024root___eval_triggers__stl\n"); );
    Vtt_um_micro__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtt_um_micro___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

VL_ATTR_COLD void Vtt_um_micro___024root___stl_sequent__TOP__0(Vtt_um_micro___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_micro___024root___stl_sequent__TOP__0\n"); );
    Vtt_um_micro__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.uio_oe = (0xa0U | (IData)(vlSelfRef.tt_um_micro__DOT__core__DOT__gpio_dir));
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
}

VL_ATTR_COLD void Vtt_um_micro___024root___configure_coverage(Vtt_um_micro___024root* vlSelf, bool first) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtt_um_micro___024root___configure_coverage\n"); );
    Vtt_um_micro__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    (void)first;  // Prevent unused variable warning
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "../../src/cpu_core.v", 91, 22, ".tt_um_micro.core", "v_line/cpu_core", "case", "91");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[1]), first, "../../src/cpu_core.v", 92, 22, ".tt_um_micro.core", "v_line/cpu_core", "case", "92");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[2]), first, "../../src/cpu_core.v", 93, 22, ".tt_um_micro.core", "v_line/cpu_core", "case", "93");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[3]), first, "../../src/cpu_core.v", 94, 22, ".tt_um_micro.core", "v_line/cpu_core", "case", "94");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[4]), first, "../../src/cpu_core.v", 95, 22, ".tt_um_micro.core", "v_line/cpu_core", "case", "95");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[5]), first, "../../src/cpu_core.v", 96, 22, ".tt_um_micro.core", "v_line/cpu_core", "case", "96");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6]), first, "../../src/cpu_core.v", 97, 22, ".tt_um_micro.core", "v_line/cpu_core", "case", "97");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[7]), first, "../../src/cpu_core.v", 98, 22, ".tt_um_micro.core", "v_line/cpu_core", "case", "98");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[8]), first, "../../src/cpu_core.v", 87, 9, ".tt_um_micro.core", "v_branch/cpu_core", "if", "87-88");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[9]), first, "../../src/cpu_core.v", 87, 10, ".tt_um_micro.core", "v_branch/cpu_core", "else", "89-90");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[10]), first, "../../src/cpu_core.v", 85, 5, ".tt_um_micro.core", "v_line/cpu_core", "block", "85-86");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[11]), first, "../../src/cpu_core.v", 126, 18, ".tt_um_micro.core", "v_branch/cpu_core", "if", "126-127");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[12]), first, "../../src/cpu_core.v", 126, 19, ".tt_um_micro.core", "v_branch/cpu_core", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[13]), first, "../../src/cpu_core.v", 124, 9, ".tt_um_micro.core", "v_line/cpu_core", "elsif", "124-125");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[14]), first, "../../src/cpu_core.v", 122, 5, ".tt_um_micro.core", "v_line/cpu_core", "block", "122");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[15]), first, "../../src/cpu_core.v", 136, 17, ".tt_um_micro.core", "v_branch/cpu_core", "if", "136-137");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[16]), first, "../../src/cpu_core.v", 136, 18, ".tt_um_micro.core", "v_branch/cpu_core", "else", "139");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[17]), first, "../../src/cpu_core.v", 135, 18, ".tt_um_micro.core", "v_line/cpu_core", "case", "135");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[18]), first, "../../src/cpu_core.v", 141, 21, ".tt_um_micro.core", "v_line/cpu_core", "case", "141-142");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[19]), first, "../../src/cpu_core.v", 144, 17, ".tt_um_micro.core", "v_line/cpu_core", "case", "144-145");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[20]), first, "../../src/cpu_core.v", 147, 13, ".tt_um_micro.core", "v_line/cpu_core", "case", "147");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[21]), first, "../../src/cpu_core.v", 132, 5, ".tt_um_micro.core", "v_line/cpu_core", "block", "132-134");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[22]), first, "../../src/cpu_core.v", 169, 13, ".tt_um_micro.core", "v_line/cpu_core", "block", "169");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[23]), first, "../../src/cpu_core.v", 192, 22, ".tt_um_micro.core", "v_line/cpu_core", "case", "192-194");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[24]), first, "../../src/cpu_core.v", 197, 25, ".tt_um_micro.core", "v_line/cpu_core", "case", "197-199");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[25]), first, "../../src/cpu_core.v", 204, 30, ".tt_um_micro.core", "v_line/cpu_core", "case", "204-207");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[26]), first, "../../src/cpu_core.v", 214, 29, ".tt_um_micro.core", "v_branch/cpu_core", "if", "214");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[27]), first, "../../src/cpu_core.v", 214, 30, ".tt_um_micro.core", "v_branch/cpu_core", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[28]), first, "../../src/cpu_core.v", 210, 30, ".tt_um_micro.core", "v_line/cpu_core", "case", "210-213");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[29]), first, "../../src/cpu_core.v", 222, 42, ".tt_um_micro.core", "v_line/cpu_core", "case", "222");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[30]), first, "../../src/cpu_core.v", 223, 42, ".tt_um_micro.core", "v_line/cpu_core", "case", "223");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[31]), first, "../../src/cpu_core.v", 224, 42, ".tt_um_micro.core", "v_line/cpu_core", "case", "224");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[32]), first, "../../src/cpu_core.v", 225, 42, ".tt_um_micro.core", "v_line/cpu_core", "case", "225-226");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[33]), first, "../../src/cpu_core.v", 228, 42, ".tt_um_micro.core", "v_line/cpu_core", "case", "228");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[34]), first, "../../src/cpu_core.v", 229, 42, ".tt_um_micro.core", "v_line/cpu_core", "case", "229");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[35]), first, "../../src/cpu_core.v", 230, 42, ".tt_um_micro.core", "v_line/cpu_core", "case", "230");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[36]), first, "../../src/cpu_core.v", 231, 37, ".tt_um_micro.core", "v_line/cpu_core", "case", "231");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[37]), first, "../../src/cpu_core.v", 218, 29, ".tt_um_micro.core", "v_branch/cpu_core", "if", "218-219");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[38]), first, "../../src/cpu_core.v", 218, 30, ".tt_um_micro.core", "v_branch/cpu_core", "else", "220-221");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[39]), first, "../../src/cpu_core.v", 217, 30, ".tt_um_micro.core", "v_line/cpu_core", "case", "217");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[40]), first, "../../src/cpu_core.v", 236, 30, ".tt_um_micro.core", "v_line/cpu_core", "case", "236-238");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[41]), first, "../../src/cpu_core.v", 240, 30, ".tt_um_micro.core", "v_line/cpu_core", "case", "240-242");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[42]), first, "../../src/cpu_core.v", 244, 30, ".tt_um_micro.core", "v_line/cpu_core", "case", "244");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[43]), first, "../../src/cpu_core.v", 245, 32, ".tt_um_micro.core", "v_branch/cpu_core", "if", "245");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[44]), first, "../../src/cpu_core.v", 245, 33, ".tt_um_micro.core", "v_branch/cpu_core", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[45]), first, "../../src/cpu_core.v", 245, 30, ".tt_um_micro.core", "v_line/cpu_core", "case", "245");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[46]), first, "../../src/cpu_core.v", 247, 30, ".tt_um_micro.core", "v_line/cpu_core", "case", "247-250");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[47]), first, "../../src/cpu_core.v", 252, 30, ".tt_um_micro.core", "v_line/cpu_core", "case", "252-255");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[48]), first, "../../src/cpu_core.v", 257, 30, ".tt_um_micro.core", "v_line/cpu_core", "case", "257-260");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[49]), first, "../../src/cpu_core.v", 263, 30, ".tt_um_micro.core", "v_line/cpu_core", "case", "263-266");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[50]), first, "../../src/cpu_core.v", 268, 30, ".tt_um_micro.core", "v_line/cpu_core", "case", "268-271");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[51]), first, "../../src/cpu_core.v", 274, 30, ".tt_um_micro.core", "v_line/cpu_core", "case", "274-276");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[52]), first, "../../src/cpu_core.v", 278, 30, ".tt_um_micro.core", "v_line/cpu_core", "case", "278");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[53]), first, "../../src/cpu_core.v", 280, 32, ".tt_um_micro.core", "v_branch/cpu_core", "if", "280");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[54]), first, "../../src/cpu_core.v", 280, 33, ".tt_um_micro.core", "v_branch/cpu_core", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[55]), first, "../../src/cpu_core.v", 280, 30, ".tt_um_micro.core", "v_line/cpu_core", "case", "280");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[56]), first, "../../src/cpu_core.v", 281, 32, ".tt_um_micro.core", "v_branch/cpu_core", "if", "281");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[57]), first, "../../src/cpu_core.v", 281, 33, ".tt_um_micro.core", "v_branch/cpu_core", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[58]), first, "../../src/cpu_core.v", 281, 30, ".tt_um_micro.core", "v_line/cpu_core", "case", "281");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[59]), first, "../../src/cpu_core.v", 283, 25, ".tt_um_micro.core", "v_line/cpu_core", "case", "283");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[60]), first, "../../src/cpu_core.v", 202, 21, ".tt_um_micro.core", "v_line/cpu_core", "case", "202-203");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[61]), first, "../../src/cpu_core.v", 287, 17, ".tt_um_micro.core", "v_line/cpu_core", "case", "287");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[62]), first, "../../src/cpu_core.v", 184, 18, ".tt_um_micro.core", "v_branch/cpu_core", "if", "184-186,188-189,191");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[63]), first, "../../src/cpu_core.v", 184, 19, ".tt_um_micro.core", "v_branch/cpu_core", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[64]), first, "../../src/cpu_core.v", 153, 9, ".tt_um_micro.core", "v_line/cpu_core", "elsif", "153-183");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[65]), first, "../../src/cpu_core.v", 152, 5, ".tt_um_micro.core", "v_line/cpu_core", "block", "152");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[66]), first, "../../src/uart.v", 42, 21, ".tt_um_micro.core.tx_inst", "v_branch/uart_tx", "if", "42-44");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[67]), first, "../../src/uart.v", 42, 22, ".tt_um_micro.core.tx_inst", "v_branch/uart_tx", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[68]), first, "../../src/uart.v", 38, 21, ".tt_um_micro.core.tx_inst", "v_line/uart_tx", "case", "38-39");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[69]), first, "../../src/uart.v", 50, 21, ".tt_um_micro.core.tx_inst", "v_branch/uart_tx", "if", "50-51");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[70]), first, "../../src/uart.v", 50, 22, ".tt_um_micro.core.tx_inst", "v_branch/uart_tx", "else", "52-54");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[71]), first, "../../src/uart.v", 48, 22, ".tt_um_micro.core.tx_inst", "v_line/uart_tx", "case", "48-49");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[72]), first, "../../src/uart.v", 65, 25, ".tt_um_micro.core.tx_inst", "v_branch/uart_tx", "if", "65-66");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[73]), first, "../../src/uart.v", 65, 26, ".tt_um_micro.core.tx_inst", "v_branch/uart_tx", "else", "67-69");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[74]), first, "../../src/uart.v", 60, 21, ".tt_um_micro.core.tx_inst", "v_branch/uart_tx", "if", "60-61");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[75]), first, "../../src/uart.v", 60, 22, ".tt_um_micro.core.tx_inst", "v_branch/uart_tx", "else", "62-64");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[76]), first, "../../src/uart.v", 58, 21, ".tt_um_micro.core.tx_inst", "v_line/uart_tx", "case", "58-59");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[77]), first, "../../src/uart.v", 76, 21, ".tt_um_micro.core.tx_inst", "v_branch/uart_tx", "if", "76-77");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[78]), first, "../../src/uart.v", 76, 22, ".tt_um_micro.core.tx_inst", "v_branch/uart_tx", "else", "78-80");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[79]), first, "../../src/uart.v", 74, 24, ".tt_um_micro.core.tx_inst", "v_line/uart_tx", "case", "74-75");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[80]), first, "../../src/uart.v", 84, 17, ".tt_um_micro.core.tx_inst", "v_line/uart_tx", "case", "84");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[81]), first, "../../src/uart.v", 30, 9, ".tt_um_micro.core.tx_inst", "v_branch/uart_tx", "if", "30-35");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[82]), first, "../../src/uart.v", 30, 10, ".tt_um_micro.core.tx_inst", "v_branch/uart_tx", "else", "36-37");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[83]), first, "../../src/uart.v", 29, 5, ".tt_um_micro.core.tx_inst", "v_line/uart_tx", "block", "29");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[84]), first, "../../src/uart.v", 115, 9, ".tt_um_micro.core.rx_inst", "v_branch/uart_rx", "if", "115-117");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[85]), first, "../../src/uart.v", 115, 10, ".tt_um_micro.core.rx_inst", "v_branch/uart_rx", "else", "118-120");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[86]), first, "../../src/uart.v", 114, 5, ".tt_um_micro.core.rx_inst", "v_line/uart_rx", "block", "114");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[87]), first, "../../src/uart.v", 133, 13, ".tt_um_micro.core.rx_inst", "v_branch/uart_rx", "if", "133");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[88]), first, "../../src/uart.v", 133, 14, ".tt_um_micro.core.rx_inst", "v_branch/uart_rx", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[89]), first, "../../src/uart.v", 140, 21, ".tt_um_micro.core.rx_inst", "v_branch/uart_rx", "if", "140-141");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[90]), first, "../../src/uart.v", 140, 22, ".tt_um_micro.core.rx_inst", "v_branch/uart_rx", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[91]), first, "../../src/uart.v", 136, 21, ".tt_um_micro.core.rx_inst", "v_line/uart_rx", "case", "136");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[92]), first, "../../src/uart.v", 150, 25, ".tt_um_micro.core.rx_inst", "v_branch/uart_rx", "if", "150-151");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[93]), first, "../../src/uart.v", 150, 26, ".tt_um_micro.core.rx_inst", "v_branch/uart_rx", "else", "152-153");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[94]), first, "../../src/uart.v", 147, 21, ".tt_um_micro.core.rx_inst", "v_branch/uart_rx", "if", "147-148");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[95]), first, "../../src/uart.v", 147, 22, ".tt_um_micro.core.rx_inst", "v_branch/uart_rx", "else", "155-156");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[96]), first, "../../src/uart.v", 146, 22, ".tt_um_micro.core.rx_inst", "v_line/uart_rx", "case", "146");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[97]), first, "../../src/uart.v", 167, 25, ".tt_um_micro.core.rx_inst", "v_branch/uart_rx", "if", "167-168");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[98]), first, "../../src/uart.v", 167, 26, ".tt_um_micro.core.rx_inst", "v_branch/uart_rx", "else", "169-171");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[99]), first, "../../src/uart.v", 162, 21, ".tt_um_micro.core.rx_inst", "v_branch/uart_rx", "if", "162-163");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[100]), first, "../../src/uart.v", 162, 22, ".tt_um_micro.core.rx_inst", "v_branch/uart_rx", "else", "164-166");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[101]), first, "../../src/uart.v", 161, 21, ".tt_um_micro.core.rx_inst", "v_line/uart_rx", "case", "161");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[102]), first, "../../src/uart.v", 181, 25, ".tt_um_micro.core.rx_inst", "v_branch/uart_rx", "if", "181");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[103]), first, "../../src/uart.v", 181, 26, ".tt_um_micro.core.rx_inst", "v_branch/uart_rx", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[104]), first, "../../src/uart.v", 177, 21, ".tt_um_micro.core.rx_inst", "v_branch/uart_rx", "if", "177-178");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[105]), first, "../../src/uart.v", 177, 22, ".tt_um_micro.core.rx_inst", "v_branch/uart_rx", "else", "179,182-183");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[106]), first, "../../src/uart.v", 176, 24, ".tt_um_micro.core.rx_inst", "v_line/uart_rx", "case", "176");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[107]), first, "../../src/uart.v", 187, 17, ".tt_um_micro.core.rx_inst", "v_line/uart_rx", "case", "187");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[108]), first, "../../src/uart.v", 125, 9, ".tt_um_micro.core.rx_inst", "v_branch/uart_rx", "if", "125-130");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[109]), first, "../../src/uart.v", 125, 10, ".tt_um_micro.core.rx_inst", "v_branch/uart_rx", "else", "131,135");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[110]), first, "../../src/uart.v", 124, 5, ".tt_um_micro.core.rx_inst", "v_line/uart_rx", "block", "124");
}
