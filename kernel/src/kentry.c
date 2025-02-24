#include "driver/ramfb/ramfb.h"
#include "mockscheduler/mockscheduler.h"
#include "text/text.h"
#include "time/rng/rng.h"
#include "time/timer.h"
#include "driver/uart/uart.h"
#include "boot/boot.h"






static uint8_t SimulateLoadingWait(){
    // Simulates a Loading Screen Wait, Around 10s (since i have nothing to load so far
    static bool init = false;
    static int beginning;
    if(init == false){
        beginning = KiGetMilliseconds();
        init = true;
    }
    if(KiGetMilliseconds() - beginning >= 10000){
        KiEndBootScreen();
        COLOR color = RGB(0, 0, 0);
        KiDrawText(10, 10, "System Loaded", 1, &color);
        return 0;
    }
    else return 1;
    
}

void KiEntry() {
    RamFbSetupFramebuffer();
    RamFbChangeFramebufferSize(800,600);

    
    KiCreateTask(KiStartBootScreen);
    KiCreateTask(SimulateLoadingWait);
    KiBeginSchedular();
}




