#include "debug/debug.h"
#include "driver/uart/uart.h"

void Hi(char* s, ...){

}

void KiEntry() {
    // will immedietely create an exception for some reason    
    //KiUartPrintF("Hi");
    //KiDebugUartPrint("Hi");
    //KiDumpRegisters();
    Hi("s");
}