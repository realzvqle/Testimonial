#include "graphicsabs.h"
#include "../driver/ramfb/ramfb.h"


/*

    If you want to add your own Graphics Driver make sure to replace the stock RamFb ones here
    with the specifics of your choosing.

    This is to make writing different graphics drivers easier for everyone involved

*/


int KiSetupGraphicsDisplay(){
    // In Here you put ALL your initialization code for your Graphics Driver
    // For Example, for the RamFB driver I Run RamFbSetupFramebuffer to Begin
    // Also, Make Sure it returns an integer for status testing

    return RamFbSetupFramebuffer();
}


void KiDrawRect(int x, int y, int height, int width, COLOR *color){
    RamFbDrawRect(x, y, height, width, color);
}


void KiClearBackground(COLOR *color){
    RamFbClearBackground(color);
}


void KiDrawRectRandomized(int x, int y, int height, int width, COLOR *color){
    RamFbDrawRectRandomized(x, y, height, width, color);
}


void KiSetBackgroundRandomized(COLOR *color){
    RamFbSetBackgroundRandomized(color);
}


void KiChangePixel(int x, int y, COLOR *color){
    RamFbWriteRGB256Pixel(x, y, color);
}


uint16_t KiGetFrameBufferWidth(){
    return RamFbGetFrameBufferWidth();
}


uint16_t KiGetFrameBufferHeight(){
    return RamFbGetFrameBufferHeight();
}


void KiChangeFrameBufferWidth(uint16_t width){
    RamFbChangeFramebufferWidth(width);
}


void KiChangeFrameBufferHeight(uint16_t height){
    RamFbChangeFramebufferHeight(height);
}


void KiChangeFrameBufferSize(uint16_t width, uint16_t height){
    RamFbChangeFramebufferSize(width, height);
}


COLOR RGB(uint8_t r, uint8_t g, uint8_t b){
    COLOR color = {r, g, b};
    return color;
}

