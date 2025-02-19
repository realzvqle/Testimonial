#include <stdint.h>
#include "driver/uart/uart.h"
#include "runtimelib.h"
typedef struct _InterruptFrame {
    uint64_t x0;
    uint64_t x1;
    uint64_t x2;
    uint64_t x3;
    uint64_t x4;
    uint64_t x5;
    uint64_t x6;
    uint64_t x7;
    uint64_t x8;
    uint64_t x9;
    uint64_t x10;
    uint64_t x11;
    uint64_t x12;
    uint64_t x13;
    uint64_t x14;
    uint64_t x15;
    uint64_t x16;
    uint64_t x17;
    uint64_t x18;
    uint64_t fp;
    uint64_t lr;
    uint64_t xzr;
    uint64_t esr;
    uint64_t far;
} InterruptFrame;


static inline void UartPrintUnsigned64Integer(char* prev, uint64_t integer){
    KiUartPrint(prev);
    char buffer[512];
    RtlIntegerToAscii(integer, buffer);
    KiUartPrint(buffer);
    KiUartPrint("\n");
}

void KiExceptionHandler(InterruptFrame* frame){
    //KiUartPrintF("Exception! x0: %d", frame->x0);
    KiUartPrint("\n!! Exception Occured, Dumping Register Information !!\n\n");

    UartPrintUnsigned64Integer("X0: ", frame->x0);
    UartPrintUnsigned64Integer("X1: ", frame->x1);
    UartPrintUnsigned64Integer("X2: ", frame->x2);
    UartPrintUnsigned64Integer("X3: ", frame->x3);
    UartPrintUnsigned64Integer("X4: ", frame->x4);
    UartPrintUnsigned64Integer("X5: ", frame->x5);
    UartPrintUnsigned64Integer("X6: ", frame->x6);
    UartPrintUnsigned64Integer("X7: ", frame->x7);
    UartPrintUnsigned64Integer("X8: ", frame->x8);
    UartPrintUnsigned64Integer("X9: ", frame->x9);
    UartPrintUnsigned64Integer("X10: ", frame->x10);
    UartPrintUnsigned64Integer("X11: ", frame->x11);
    UartPrintUnsigned64Integer("X12: ", frame->x12);
    UartPrintUnsigned64Integer("X13: ", frame->x13);
    UartPrintUnsigned64Integer("X14: ", frame->x14);
    UartPrintUnsigned64Integer("X15: ", frame->x15);
    UartPrintUnsigned64Integer("X16: ", frame->x16);
    UartPrintUnsigned64Integer("X17: ", frame->x17);
    UartPrintUnsigned64Integer("X18: ", frame->x18);
    UartPrintUnsigned64Integer("FP: ", frame->fp);
    UartPrintUnsigned64Integer("LR: ", frame->lr);
    UartPrintUnsigned64Integer("XZR: ", frame->xzr);
    UartPrintUnsigned64Integer("ESR: ", frame->esr);
    UartPrintUnsigned64Integer("FAR: ", frame->far);
    while(1){continue;}
}