// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtt_um_micro.h for the primary calling header

#include "Vtt_um_micro__pch.h"
#include "Vtt_um_micro__Syms.h"
#include "Vtt_um_micro___024root.h"

void Vtt_um_micro___024root___ctor_var_reset(Vtt_um_micro___024root* vlSelf);

Vtt_um_micro___024root::Vtt_um_micro___024root(Vtt_um_micro__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtt_um_micro___024root___ctor_var_reset(this);
}

void Vtt_um_micro___024root___configure_coverage(Vtt_um_micro___024root* vlSelf, bool first);

void Vtt_um_micro___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
    Vtt_um_micro___024root___configure_coverage(this, first);
}

Vtt_um_micro___024root::~Vtt_um_micro___024root() {
}

// Coverage
void Vtt_um_micro___024root::__vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
    const char* hierp, const char* pagep, const char* commentp, const char* linescovp) {
    uint32_t* count32p = countp;
    static uint32_t fake_zero_count = 0;
    std::string fullhier = std::string{VerilatedModule::name()} + hierp;
    if (!fullhier.empty() && fullhier[0] == '.') fullhier = fullhier.substr(1);
    if (!enable) count32p = &fake_zero_count;
    *count32p = 0;
    VL_COVER_INSERT(vlSymsp->_vm_contextp__->coveragep(), VerilatedModule::name(), count32p,  "filename",filenamep,  "lineno",lineno,  "column",column,
        "hier",fullhier,  "page",pagep,  "comment",commentp,  (linescovp[0] ? "linescov" : ""), linescovp);
}
