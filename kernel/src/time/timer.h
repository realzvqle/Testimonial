#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED





#include <stdint.h>
#include <stdbool.h>


void KiSleep(uint32_t seconds);
uint32_t KiGetTimerValue();
uint64_t KiGetCounterValue();
uint64_t KiGetCounterFrequency();
void KiSleepMi(uint32_t milliseconds);
void KiSleepMicro(uint32_t microseconds);
uint32_t KiGetElapsedMicroseconds(uint64_t start_time);
uint64_t KiGetMicroseconds();
uint64_t KiGetMilliseconds();
#endif