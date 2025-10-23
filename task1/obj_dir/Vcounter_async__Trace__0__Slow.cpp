// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vcounter_async__Syms.h"


VL_ATTR_COLD void Vcounter_async___024root__trace_init_sub__TOP__0(Vcounter_async___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vcounter_async__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter_async___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+1,"clk", false,-1);
    tracep->declBit(c+2,"rst", false,-1);
    tracep->declBit(c+3,"en", false,-1);
    tracep->declBus(c+4,"count", false,-1, 7,0);
    tracep->pushNamePrefix("counter_async ");
    tracep->declBus(c+5,"WIDTH", false,-1, 31,0);
    tracep->declBit(c+1,"clk", false,-1);
    tracep->declBit(c+2,"rst", false,-1);
    tracep->declBit(c+3,"en", false,-1);
    tracep->declBus(c+4,"count", false,-1, 7,0);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vcounter_async___024root__trace_init_top(Vcounter_async___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vcounter_async__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter_async___024root__trace_init_top\n"); );
    // Body
    Vcounter_async___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vcounter_async___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vcounter_async___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vcounter_async___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vcounter_async___024root__trace_register(Vcounter_async___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vcounter_async__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter_async___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vcounter_async___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vcounter_async___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vcounter_async___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vcounter_async___024root__trace_full_sub_0(Vcounter_async___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vcounter_async___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter_async___024root__trace_full_top_0\n"); );
    // Init
    Vcounter_async___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vcounter_async___024root*>(voidSelf);
    Vcounter_async__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vcounter_async___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vcounter_async___024root__trace_full_sub_0(Vcounter_async___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vcounter_async__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcounter_async___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->clk));
    bufp->fullBit(oldp+2,(vlSelf->rst));
    bufp->fullBit(oldp+3,(vlSelf->en));
    bufp->fullCData(oldp+4,(vlSelf->count),8);
    bufp->fullIData(oldp+5,(8U),32);
}
