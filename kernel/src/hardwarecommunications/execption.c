#include <stdint.h>
#include "../driver/uart/uart.h"
#include "../debug/debug.h"


void KiExceptionHandler(InterruptFrame* frame){
    //KiUartPrintF("Exception! x0: %d", frame->x0);
    KiUartPrint("\n!! Exception Occured, Dumping Register Information !!\n\n");

    KiPrintRegisterData(frame);
    while(1){continue;}
}