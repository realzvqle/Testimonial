#ifndef QEMU_H_INCLUDED
#define QEMU_H_INCLUDED







#include <stdint.h>
#include <stdbool.h>



bool QemuCfgDmaTransfer(void* address, uint32_t length, uint32_t control);
bool QemuCfgRead(void* buf, int len);
bool QemuCfgReadEntry(void* buf, int e, int len);
bool QemuCfgWriteEntry(void* buf, uint32_t e, uint32_t len);
int QemuCfgFindFile(char* filename);
int QemuCheckCfgDma();
int QemuCfgPrintAllFiles();
#endif