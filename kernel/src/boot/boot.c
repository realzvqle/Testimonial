#include "boot.h"
#include "../graphicsabs/graphicsabs.h"
#include "../time/rng/rng.h"
#include "../time/timer.h"

static bool isLoaded = false;



uint8_t KiStartBootScreen(){
    static COLOR background;
    static COLOR rect;
    static uint16_t y = 0; 
    static uint16_t x = 0;
    static bool init = false;
    if(init == false){
        background = RGB(KiGenerateRandomValueWithinRange(KiGetCounterValue(), 0, 255), KiGenerateRandomValueWithinRange(KiGetCounterValue(), 0, 255), KiGenerateRandomValueWithinRange(KiGetCounterValue(), 0, 255));
        rect = RGB(KiGenerateRandomValueWithinRange(KiGetCounterValue(), 0, 255), KiGenerateRandomValueWithinRange(KiGetCounterValue(), 0, 255), KiGenerateRandomValueWithinRange(KiGetCounterValue(), 0, 255));
        init = true;
    }
    
    
    KiSetBackgroundRandomized(&background);
    KiDrawRectRandomized(x, y, 30, 30, &rect);
    x++;
    y++;
    if(x == KiGetFrameBufferWidth() - 1) x=0;
    if(y == KiGetFrameBufferHeight() - 1) y=0;
    if(isLoaded == false) return 1;
    else return 0;
}

void KiEndBootScreen(){
    isLoaded = true;
}