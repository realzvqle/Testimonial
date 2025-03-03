#ifndef TICKS_H_INCLUDED
#define TICKS_H_INCLUDED







#include <stdint.h>
#include <stdbool.h>

uint64_t KiGetCurrentTick();
void KiUpdateTicks();
#endif