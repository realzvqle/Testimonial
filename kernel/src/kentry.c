#include "driver/ramfb/ramfb.h"
#include "driver/uart/uart.h"



void KiEntry() {
    RamFbSetupFramebuffer();
    RamFbChangeFramebufferSize(800,600);

    COLOR color = RGB(255, 0, 0);
    RamFbDrawRect(10, 10, 10, 10, &color);
}