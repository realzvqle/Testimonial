#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED






#include <stdint.h>


/*

    This File is for Struct Defines that should be used if you're
    making your own graphics driver for the kernel (such as RGB for example)

*/

typedef struct _COLOR {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} COLOR;









#endif