#include "driver/uart/uart.h"


void KiEntry() {
    while(1){
        if(KiUartGetChar() == 'w')  KiUartPrint("Hi\n");
    }
}