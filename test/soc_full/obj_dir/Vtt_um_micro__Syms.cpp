// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtt_um_micro__pch.h"
#include "Vtt_um_micro.h"
#include "Vtt_um_micro___024root.h"

// FUNCTIONS
Vtt_um_micro__Syms::~Vtt_um_micro__Syms()
{
}

Vtt_um_micro__Syms::Vtt_um_micro__Syms(VerilatedContext* contextp, const char* namep, Vtt_um_micro* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(69);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
