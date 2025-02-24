#include "../qemu/qemu.h"
#include "../mmio.h"
#include "ramfb.h"
#include "../../time/timer.h"
#include "../../time/rng/rng.h"

#define fourcc_code(a, b, c, d) ((uint32_t)(a) | ((uint32_t)(b) << 8) | \
                                 ((uint32_t)(c) << 16) | ((uint32_t)(d) << 24))


#define DRM_FORMAT_RGB565       fourcc_code('R', 'G', '1', '6')
#define DRM_FORMAT_RGB888       fourcc_code('R', 'G', '2', '4') 
#define DRM_FORMAT_XRGB8888     fourcc_code('X', 'R', '2', '4') 




struct __attribute__((__packed__)) RAMFBCfg {
    uint64_t addr;
    uint32_t fourcc;
    uint32_t flags;
    uint32_t width;
    uint32_t height;
    uint32_t stride;
};



FRAMEBUFFER fb;


static uint16_t fbwidth = 100;
static uint16_t fbheight = 100;


int RamFbSetupFramebuffer(){
    extern uint64_t stack_beginning;
    uint64_t start = (uint64_t)&stack_beginning;
    uint64_t width = fbwidth;
    uint64_t height = fbheight;
    uint32_t bpp = 4;
    uint32_t stride = bpp * width;

    fb = (FRAMEBUFFER){
        .fb_addr = start,
        .fb_width = width,
        .fb_height = height,
        .fb_bpp = bpp,
        .fb_stride = stride,
        .fb_size = stride * height
    };
    uint32_t select = QemuCfgFindFile("etc/ramfb");
    if(select == 0){
        return 1;
    }
    struct RAMFBCfg cfg = {
        .addr = KiBSwap64(fb.fb_addr),
        .fourcc = KiBSwap32(DRM_FORMAT_XRGB8888),
        .flags = KiBSwap32(0),
        .width = KiBSwap32(fb.fb_width),
        .height = KiBSwap32(fb.fb_height),
        .stride = KiBSwap32(fb.fb_stride)
    };
    QemuCfgWriteEntry(&cfg, select, sizeof(cfg));
    return 0;
}


void RamFbWriteRGB256Pixel(uint16_t x, uint16_t y, COLOR* color) {
    uint8_t pixelcolor[] = {color->b, color->g, color->r};
    KiCopyMemory((void*)fb.fb_addr + ((y * fb.fb_stride) + (x * fb.fb_bpp)), &pixelcolor, 4);
}


void RamFbDrawRect(int x, int y, int height, int width, COLOR* color){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            RamFbWriteRGB256Pixel(x + j, y + i, color);
        }
    }
    
        
}

void RamFbDrawRectRandomized(int x, int y, int height, int width, COLOR* color){
    RamFbWriteRGB256Pixel(KiGenerateRandomValueWithinRange(KiGetCounterValue(), x, x + width), 
        KiGenerateRandomValueWithinRange(KiGetCounterValue(), y, y + height), color);
}

void RamFbSetBackgroundRandomized(COLOR* color){
    RamFbWriteRGB256Pixel(KiGenerateRandomValueWithinRange(KiGetCounterValue(), 0, RamFbGetFrameBufferWidth()), 
        KiGenerateRandomValueWithinRange(KiGetCounterValue(), 0, RamFbGetFrameBufferHeight()), color);
}


void RamFbChangeFramebufferWidth(uint16_t width){
    fbwidth = width;
    RamFbSetupFramebuffer();
}




void RamFbChangeFramebufferHeight(uint16_t height){
    fbheight = height;
    RamFbSetupFramebuffer();
}


void RamFbChangeFramebufferSize(uint16_t width, uint16_t height){
    fbwidth = width;
    fbheight = height;
    RamFbSetupFramebuffer();
}

uint16_t RamFbGetFrameBufferWidth(){
    return fbwidth;
}

uint16_t RamFbGetFrameBufferHeight(){
    return fbheight;
}

