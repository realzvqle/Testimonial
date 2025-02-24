#include "driver/ramfb/ramfb.h"
#include "graphicsabs/graphicsabs.h"
#include "mockscheduler/mockscheduler.h"
#include "text/text.h"
#include "time/timer.h"
#include "boot/boot.h"






static uint8_t SimulateLoadingWait(){
    // Simulates a Loading Screen Wait, Around 20s (since i have nothing to load so far
    static bool init = false;
    static int beginning;
    if(init == false){
        beginning = KiGetMilliseconds();
        init = true;
    }
    if(KiGetMilliseconds() - beginning >= 20000){
        KiEndBootScreen();
        COLOR background = RGB(0, 0, 0);
        COLOR color = RGB(255, 255, 255);
        KiClearBackground(&background);
        KiDrawText(10, 10, "System Loaded", 1, &color);
        return 0;
    }
    else return 1;
    
}

void KiEntry() {
    KiSetupGraphicsDisplay();
    KiChangeFrameBufferSize(800, 600);
    
    KiCreateTask(KiStartBootScreen);
    KiCreateTask(SimulateLoadingWait);
    KiBeginSchedular();
}




