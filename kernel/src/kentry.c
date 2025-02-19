#include "driver/uart/uart.h"



void KiEntry() {
    // will immedietely create an exception for some reason    
    KiUartPrintF("Hi");
}