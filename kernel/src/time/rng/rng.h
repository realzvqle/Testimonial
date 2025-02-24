#ifndef RNG_H_INCLUDED
#define RNG_H_INCLUDED




#include <stdint.h>
#include <stdbool.h>




uint32_t KiGenerateRandomValue(uint32_t seed);
uint32_t KiGenerateRandomValueWithinRange(uint32_t seed, uint32_t min, uint32_t max);

#endif