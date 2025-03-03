#include "ticks.h"
#include "../time/timer.h"


static uint64_t currenttick = 0;



uint64_t KiGetCurrentTick(){
    return currenttick;
}


void KiUpdateTicks(){
    static uint64_t prevtime = 0;
    static bool init = false;
    if(init == false){
        prevtime = KiGetMilliseconds();
        init = true;
    }
    if(KiGetMilliseconds() - prevtime > 100){
        currenttick++;
        prevtime = KiGetMilliseconds();
    }
}