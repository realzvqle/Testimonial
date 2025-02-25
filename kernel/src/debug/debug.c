#include "debug.h"
#include "../runtimelib.h"
//#include "../driver/uart/uart.h"


extern void KiDumpRegisters();



void KiPrintRegisterData(InterruptFrame* frame){
    RtlUartPrintUnsigned64Integer("X0: ", frame->x0);
    RtlUartPrintUnsigned64Integer("X1: ", frame->x1);
    RtlUartPrintUnsigned64Integer("X2: ", frame->x2);
    RtlUartPrintUnsigned64Integer("X3: ", frame->x3);
    RtlUartPrintUnsigned64Integer("X4: ", frame->x4);
    RtlUartPrintUnsigned64Integer("X5: ", frame->x5);
    RtlUartPrintUnsigned64Integer("X6: ", frame->x6);
    RtlUartPrintUnsigned64Integer("X7: ", frame->x7);
    RtlUartPrintUnsigned64Integer("X8: ", frame->x8);
    RtlUartPrintUnsigned64Integer("X9: ", frame->x9);
    RtlUartPrintUnsigned64Integer("X10: ", frame->x10);
    RtlUartPrintUnsigned64Integer("X11: ", frame->x11);
    RtlUartPrintUnsigned64Integer("X12: ", frame->x12);
    RtlUartPrintUnsigned64Integer("X13: ", frame->x13);
    RtlUartPrintUnsigned64Integer("X14: ", frame->x14);
    RtlUartPrintUnsigned64Integer("X15: ", frame->x15);
    RtlUartPrintUnsigned64Integer("X16: ", frame->x16);
    RtlUartPrintUnsigned64Integer("X17: ", frame->x17);
    RtlUartPrintUnsigned64Integer("X18: ", frame->x18);
    RtlUartPrintUnsigned64Integer("FP: ", frame->fp);
    RtlUartPrintUnsigned64Integer("LR: ", frame->lr);
    RtlUartPrintUnsigned64Integer("XZR: ", frame->xzr);
    RtlUartPrintUnsigned64Integer("ESR: ", frame->esr);
    RtlUartPrintUnsigned64Integer("FAR: ", frame->far);
}


void KiManualCallPrintDumpedRegisters(InterruptFrame* frame){
    //KiUartPrint("\n\n!!! MANUAL REGISTER DUMP !!!\n\n");
    KiPrintRegisterData(frame);
}