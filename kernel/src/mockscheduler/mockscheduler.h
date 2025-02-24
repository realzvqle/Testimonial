#ifndef MOCKSCHEDULER_H_INCLUDED
#define MOCKSCHEDULER_H_INCLUDED




#include <stdint.h>
#include <stdbool.h>



typedef struct _TASK {
    uint8_t (*TaskEntryPoint) (void); 
} TASK;


uint16_t KiCreateTask(uint8_t (*TaskEntryPoint) (void));
void KiBeginSchedular();


#endif