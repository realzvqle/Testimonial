#include "driver/uart/uart.h"
static volatile int cont = 1;


void KiEntry() {
    // will immedietely create an exception for some reason    
    KiUartPrintF("Hi");
}