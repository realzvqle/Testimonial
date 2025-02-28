#include "ticks.h"
#include "../time/timer.h"
#include "../runtimelib.h"
#include "../driver/uart/uart.h"

static uint64_t currenttick = 0;
static uint64_t prevtick = 0;
static uint64_t TPS = 0;
static uint64_t TPSCount = 0;


static float prevdtime = 0;
static float curdtime = 0;


uint64_t KiGetCurrentTick(){
    return currenttick;
}

uint8_t KiCalculateTicksPerSecond(){
    static bool init = false;
    static int prevtime; 
    if(init == false){
        prevtime = KiGetTimerValue();
        init = true;
    }
    TPSCount++; 
    if(KiGetTimerValue() - prevtime >= 1){
        prevtick = currenttick;
        prevtime = KiGetTimerValue();
        TPS = TPSCount;
        char buffer[512];
        RtlIntegerToAscii(TPS, buffer);
        KiUartPrint(buffer);
        KiUartPrint("\n");
        TPSCount = 0;
    }
    return 1;
}

uint64_t KiGetTicksPerSecond(){
    return TPS;
}


uint8_t KiCalculateTickDT(){ 
    // crashs when you run this, idk why
    //prevdtime = curdtime;
    //curdtime = (double)KiGetCurrentTick();
    return 1;
}

double KiGetTickDT(){
    return curdtime - prevdtime;
}

uint8_t KiUpdateTicks(){
    currenttick++;
    KiSleepMicro(1);
    return 1;
}