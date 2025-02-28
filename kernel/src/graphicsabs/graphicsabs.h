#ifndef GRAPHICSABS_H_INCLUDED
#define GRAPHICSABS_H_INCLUDED







#include <stdbool.h>
#include <stdint.h>

#include "graphics.h"



int KiSetupGraphicsDisplay();
void KiDrawRect(int x, int y, int height, int width, COLOR *color);
void KiSetBackground(COLOR *color);
void KiDrawRectRandomized(int x, int y, int height, int width, COLOR *color);
void KiSetBackgroundRandomized(COLOR *color);
void KiChangePixel(int x, int y, COLOR *color);
uint16_t KiGetFrameBufferWidth();
uint16_t KiGetFrameBufferHeight();
void KiChangeFrameBufferWidth(uint16_t width);
void KiChangeFrameBufferHeight(uint16_t height);
void KiChangeFrameBufferSize(uint16_t width, uint16_t height);
COLOR RGB(uint8_t r, uint8_t g, uint8_t b);
uint8_t KiClearScreen();
#endif