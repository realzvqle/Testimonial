#include "debug/debug.h"
#include "driver/ramfb/ramfb.h"
#include "driver/uart/uart.h"
#include "graphicsabs/graphicsabs.h"
#include "mockscheduler/mockscheduler.h"
#include "mockscheduler/ticks.h"
#include "text/text.h"
#include "time/timer.h"
#include "boot/boot.h"




static uint8_t SimulateLoadingWait(){
    // Simulates a Loading Screen Wait, Around 100 ticks (since i have nothing to load so far)
    static bool init = false;
    static int beginning;
    if(init == false){
        beginning = KiGetCurrentTick();
        init = true;
    }
    COLOR background = RGB(0, 0, 0);
    if(KiGetCurrentTick() - beginning >= 100){
        KiEndBootScreen();
        COLOR background = RGB(0, 0, 0);
        COLOR color = RGB(255, 255, 255);
        KiSetBackground(&background);
       
        KiDrawText(10, 10, "System Loaded", 1, &color);
        
        return 0;
    }
    else return 1;
    
}




void KiEntry() {
    int result = KiSetupGraphicsDisplay();
    if(result == 1){
        KiDumpRegisters();
        KiUartPrint("\n\n!! FAILURE TO SETUP GRAPHICS DRIVER !!\n\n");
        while(1){continue;}
    }
    KiChangeFrameBufferSize(800, 600);
    KiCreateTask(KiStartBootScreen, INFINITE);
    KiCreateTask(SimulateLoadingWait, INFINITE);
    
    KiBeginSchedular();
}




