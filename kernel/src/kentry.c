#include "driver/uart/uart.h"



static volatile int cont = 1;


void KiEntry() {
    // while(1){
    //     if(KiUartGetChar() == 'w')  KiUartPrint("Hi\n");
    // }
    //KiEntry();
    cont = *((volatile int *)0xffffffffffffffffull);
    KiUartPrint("Hu");
}