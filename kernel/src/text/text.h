#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED







#include <stdint.h>
#include <stdbool.h>
#include "../graphicsabs/graphics.h"




void KiDrawText(int x, int y, char* s, int size, COLOR* color);
void KiDrawTextRandomized(int x, int y, char* s, int size, COLOR* color);

#endif