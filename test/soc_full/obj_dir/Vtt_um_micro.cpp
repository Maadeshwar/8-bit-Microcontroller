// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtt_um_micro__pch.h"

//============================================================
// Constructors

Vtt_um_micro::Vtt_um_micro(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtt_um_micro__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst_n{vlSymsp->TOP.rst_n}
    , ui_in{vlSymsp->TOP.ui_in}
    , uo_out{vlSymsp->TOP.uo_out}
    , uio_in{vlSymsp->TOP.uio_in}
    , uio_out{vlSymsp->TOP.uio_out}
    , uio_oe{vlSymsp->TOP.uio_oe}
    , ena{vlSymsp->TOP.ena}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtt_um_micro::Vtt_um_micro(const char* _vcname__)
    : Vtt_um_micro(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtt_um_micro::~Vtt_um_micro() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtt_um_micro___024root___eval_debug_assertions(Vtt_um_micro___024root* vlSelf);
#endif  // VL_DEBUG
void Vtt_um_micro___024root___eval_static(Vtt_um_micro___024root* vlSelf);
void Vtt_um_micro___024root___eval_initial(Vtt_um_micro___024root* vlSelf);
void Vtt_um_micro___024root___eval_settle(Vtt_um_micro___024root* vlSelf);
void Vtt_um_micro___024root___eval(Vtt_um_micro___024root* vlSelf);

void Vtt_um_micro::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtt_um_micro::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtt_um_micro___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtt_um_micro___024root___eval_static(&(vlSymsp->TOP));
        Vtt_um_micro___024root___eval_initial(&(vlSymsp->TOP));
        Vtt_um_micro___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtt_um_micro___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtt_um_micro::eventsPending() { return false; }

uint64_t Vtt_um_micro::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vtt_um_micro::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtt_um_micro___024root___eval_final(Vtt_um_micro___024root* vlSelf);

VL_ATTR_COLD void Vtt_um_micro::final() {
    Vtt_um_micro___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtt_um_micro::hierName() const { return vlSymsp->name(); }
const char* Vtt_um_micro::modelName() const { return "Vtt_um_micro"; }
unsigned Vtt_um_micro::threads() const { return 1; }
void Vtt_um_micro::prepareClone() const { contextp()->prepareClone(); }
void Vtt_um_micro::atClone() const {
    contextp()->threadPoolpOnClone();
}
