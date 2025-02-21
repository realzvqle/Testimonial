#include "debug.h"
#include "../runtimelib.h"
#include "../driver/uart/uart.h"









void KiManualCallPrintDumpedRegisters(InterruptFrame* frame){
    KiUartPrint("\n\n!!! MANUAL REGISTER DUMP !!!\n\n");
    KiPrintRegisterData(frame);
}