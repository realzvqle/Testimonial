#include "qemu.h"
#include "../../runtimelib.h"
#include "../mmio.h"
#include "../uart/uart.h"

#define QEMU_CFG_FILE_DIR        0x19

#define QEMU_CFG_DMA_CTL_ERROR   0x01
#define QEMU_CFG_DMA_CTL_READ    0x02
#define QEMU_CFG_DMA_CTL_SKIP    0x04
#define QEMU_CFG_DMA_CTL_SELECT  0x08
#define QEMU_CFG_DMA_CTL_WRITE   0x10

#define BASE_ADDR 0x09020000
#define BASE_ADDR_SELECTOR 0x9020008
#define BASE_ADDR_DATA 0x09020000
#define BASE_ADDR_ADDR 0x9020010

typedef struct {
    uint32_t control;
    uint32_t length;
    uint64_t address;
} __attribute__((__packed__)) QemuCfgDmaAccess;


typedef struct _QemuCfgFile {
    uint32_t  size;       
    uint16_t  select;      
    uint16_t  reserved;
    char name[56];
} QemuCfgFile;

typedef union _FwCfgSigRead {
    uint32_t theInt;
    char bytes[sizeof(int)];
} FwCfgSigRead;

static volatile uint16_t *baseaddrsel = (uint16_t*)0x9020008;



bool QemuCfgDmaTransfer(void* address, uint32_t length, uint32_t control){
    QemuCfgDmaAccess access = {.address = KiBSwap64((uint64_t)address), .length = KiBSwap32(length), .control = KiBSwap32(control)};
    if(length == 0){
        return false;
    }
    __asm__("ISB");
    KiWriteBSwap64(BASE_ADDR_ADDR, (uint64_t)&access);
    while(KiBSwap32(access.control) & ~QEMU_CFG_DMA_CTL_ERROR);
    return true;
}

bool QemuCfgRead(void* buf, int len){
    return QemuCfgDmaTransfer(buf, len, QEMU_CFG_DMA_CTL_READ);
}

bool QemuCfgReadEntry(void* buf, int e, int len){
    uint32_t control = (e<<16) | QEMU_CFG_DMA_CTL_SELECT | QEMU_CFG_DMA_CTL_READ;
    return QemuCfgDmaTransfer(buf, len, control);
}

bool QemuCfgWriteEntry(void* buf, uint32_t e, uint32_t len){
    uint32_t control = (e<<16) | QEMU_CFG_DMA_CTL_SELECT | QEMU_CFG_DMA_CTL_WRITE;
    return QemuCfgDmaTransfer(buf, len, control);
}

int QemuCfgFindFile(char* filename){
    uint32_t count, e, select;
    QemuCfgReadEntry(&count, QEMU_CFG_FILE_DIR, sizeof(count));
    count = KiBSwap32(count);
    
    for(select = 0, e = 0; e < count; e++){
        QemuCfgFile QemuFile;
        QemuCfgRead(&QemuFile, sizeof(QemuFile));
        if(RtlStringCompare(QemuFile.name, filename)){
            select = KiBSwap16(QemuFile.select);
        }
    }
    return select;
    
}

int QemuCfgPrintAllFiles(){
    uint32_t count, e, select;
    QemuCfgReadEntry(&count, QEMU_CFG_FILE_DIR, sizeof(count));
    count = KiBSwap32(count);
    KiUartPutChar('\n');
    for(select = 0, e = 0; e < count; e++){
        QemuCfgFile QemuFile;
        QemuCfgRead(&QemuFile, sizeof(QemuFile));
        // if(KiCompareMemoryString(QemuFile.name, filename, 10) == 0){
        //     select = KiBSwap16(QemuFile.select);
        // }
        KiUartPrint(QemuFile.name);
        KiUartPutChar('\n');
    }
    return select;
}

int QemuCheckCfgDma(){
    KiWrite16(baseaddrsel, 0x0000);
    FwCfgSigRead cfg_sig_read;
    cfg_sig_read.theInt = *((volatile uint16_t*)BASE_ADDR_DATA);
    if (cfg_sig_read.bytes[0] == 'Q' && cfg_sig_read.bytes[1] == 'E' && cfg_sig_read.bytes[2] == 'M' && cfg_sig_read.bytes[3] == 'U') {
        if (KiReadBSWap64(BASE_ADDR_ADDR) == 0x51454d5520434647) {
            return 1;
        }
    } 
    return 0;
}