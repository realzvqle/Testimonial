#include "timer.h"
#include "../driver/mmio.h"



static volatile uint32_t *timermem = (uint32_t *) 0x09010000; 


uint32_t KiGetTimerValue() {
    return KiRead32(timermem);  
}

uint64_t KiGetCounterValue() {
    uint64_t value;
    asm volatile("mrs %0, cntvct_el0" : "=r" (value));
    return value;
}

uint64_t KiGetCounterFrequency() {
    uint64_t freq;
    asm volatile("mrs %0, cntfrq_el0" : "=r" (freq));
    return freq;
}

uint64_t KiGetMicroseconds() {
    uint64_t counter = KiGetCounterValue();
    uint64_t frequency = KiGetCounterFrequency();
    
    return (counter * 1000000) / frequency;
}

uint64_t KiGetMilliseconds() {
    uint64_t counter = KiGetCounterValue();
    uint64_t frequency = KiGetCounterFrequency();
    
    return (counter * 1000) / frequency;
}

// double KiGetMillisecondsDouble() {
//     double counter = KiGetCounterValue();
//     double frequency = KiGetCounterFrequency();
    
//     return (counter * 1000) / frequency;
// }

void KiSleep(uint32_t seconds) {
    uint32_t start_time = KiGetTimerValue();
    uint32_t target_time = start_time + seconds;
    while (KiGetTimerValue() < target_time) {
        continue;  
    }
}

void KiSleepMi(uint32_t milliseconds) {
    uint64_t start_time = KiGetCounterValue();
    uint64_t freq = KiGetCounterFrequency();  
    
    uint64_t target_ticks = (milliseconds * freq) / 1000;  
    uint64_t target_time = start_time + target_ticks;

    while (KiGetCounterValue() < target_time) {
        continue;  
    }
}



void KiSleepMicro(uint32_t microseconds) {
    uint64_t start_time = KiGetCounterValue();
    uint64_t freq = KiGetCounterFrequency();  
    
    uint64_t target_ticks = (microseconds * freq) / 1000000;  
    uint64_t target_time = start_time + target_ticks;

    while (KiGetCounterValue() < target_time) {
        continue;  
    }
}

uint32_t KiGetElapsedMicroseconds(uint64_t start_time) {
    uint64_t end_time = KiGetCounterValue();
    uint64_t elapsed_ticks = end_time - start_time;
    uint64_t freq = KiGetCounterFrequency();
    uint32_t elapsed_microseconds = (elapsed_ticks * 1000000) / freq;
    return elapsed_microseconds;
}


// static double prevtime;
// static double curtime;

// uint8_t KiCalculateDeltaTime(){ 
//     prevtime = curtime;
//     curtime = KiGetMillisecondsDouble();
//     return 1;
// }

// double KiGetDeltaTime(){
//     return curtime - prevtime;
// }