#ifndef RAMFB_H_INCLUDED
#define RAMFB_H_INCLUDED










#include <stdint.h>
#include "../../graphicsabs/graphics.h"


typedef struct _FRAMEBUFFER {
    uint64_t fb_addr;
    uint32_t fb_width;
    uint32_t fb_height;
    uint32_t fb_bpp;

    uint32_t fb_stride;
    uint32_t fb_size;
} FRAMEBUFFER;



int RamFbSetupFramebuffer();
void RamFbWriteRGB256Pixel(uint16_t x, uint16_t y, COLOR* color);
void RamFbDrawRect(int x, int y, int height, int width, COLOR* color);
COLOR RGB(uint8_t r, uint8_t g, uint8_t b);
void RamFbChangeFramebufferWidth(uint16_t width);
void RamFbChangeFramebufferHeight(uint16_t height);
void RamFbChangeFramebufferSize(uint16_t width, uint16_t height);
uint16_t RamFbGetFrameBufferWidth();
uint16_t RamFbGetFrameBufferHeight();
void RamFbWriteRGB256Pixel(uint16_t x, uint16_t y, COLOR* color);
void RamFbDrawRect(int x, int y, int height, int width, COLOR* color);
void RamFbDrawRectRandomized(int x, int y, int height, int width, COLOR* color);
void RamFbSetBackgroundRandomized(COLOR* color);
#endif