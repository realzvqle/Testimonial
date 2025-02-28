#ifndef TICKS_H_INCLUDED
#define TICKS_H_INCLUDED







#include <stdint.h>
#include <stdbool.h>

uint64_t KiGetCurrentTick();
uint8_t KiUpdateTicks();
uint8_t KiCalculateTicksPerSecond();
uint64_t KiGetTicksPerSecond();
uint8_t KiCalculateTickDT();
double KiGetTickDT();
#endif