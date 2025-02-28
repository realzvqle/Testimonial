#include "debug/debug.h"
#include "driver/ramfb/ramfb.h"
#include "driver/uart/uart.h"
#include "graphicsabs/graphicsabs.h"
#include "mockscheduler/mockscheduler.h"
#include "mockscheduler/ticks.h"
#include "text/text.h"
#include "time/timer.h"
#include "boot/boot.h"
#include "runtimelib.h"



uint16_t otherstuff = 0;

static uint8_t SimulateLoadingWait(){
    // Simulates a Loading Screen Wait, Around 20s (since i have nothing to load so far
    static bool init = false;
    static int beginning;
    if(init == false){
        beginning = KiGetMilliseconds();
        init = true;
    }
    COLOR background = RGB(0, 0, 0);
    if(KiGetMilliseconds() - beginning >= 20000){
        KiEndBootScreen();
        COLOR background = RGB(0, 0, 0);
        COLOR color = RGB(255, 255, 255);
        KiSetBackground(&background);
       
        KiDrawText(10, 10, "System Loaded", 1, &color);
        
        return 0;
    }
    else return 1;
    
}

uint8_t StimulateTick(){
    //KiUartPrint("hi!");
    static int i = 0;
    static int j = 0;
    COLOR color = {10, 100, 200};
    KiDrawRect(i, j, 10, 10, &color);
    if(i < 100) i++;
    else i = 0;
    if(j < 100) j++;
    else j = 0;
    return 1;
}

uint8_t StimulateTick2(){
    //KiUartPrint("poo!");
    // static int i = 0;
    // static int j = 0;
    // COLOR color = {10, 200, 200};
    // KiDrawRect(i, j, 90, 90, &color);
    // if(i < 100) i++;
    // else i = 0;
    // if(j < 100) j++;
    // else j = 0;
    // return 1;
    // char buffer[512];
    // //RtlIntegerToAscii(KiGetTickDT(), buffer);
    // KiUartPrint(buffer);
    // KiUartPrint("\n");
    return 1;
}


uint8_t LagMachine(){
    KiSleep(1);
    return 1;
}


void KiEntry() {
    int result = KiSetupGraphicsDisplay();
    if(result == 1){
        KiDumpRegisters();
        KiUartPrint("\n\n!! FAILURE TO SETUP GRAPHICS DRIVER !!\n\n");
        while(1){continue;}
    }
    KiChangeFrameBufferSize(800, 600);
    // KiCreateTask(KiStartBootScreen, INFINITE);
    // KiCreateTask(SimulateLoadingWait, INFINITE);
    KiCreateTask(KiCalculateTicksPerSecond, INFINITE);
    KiCreateTask(KiUpdateTicks, INFINITE);
    KiCreateTask(KiCalculateTickDT, INFINITE);
    KiCreateTask(KiClearScreen, INFINITE);
    KiCreateTask(StimulateTick, INFINITE);
    KiCreateTask(StimulateTick2, INFINITE);
    //KiCreateTask(LagMachine, INFINITE);
    KiBeginSchedular();
}




