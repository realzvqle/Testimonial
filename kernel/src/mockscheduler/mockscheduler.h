#ifndef MOCKSCHEDULER_H_INCLUDED
#define MOCKSCHEDULER_H_INCLUDED




#include <stdint.h>
#include <stdbool.h>


#define INFINITE -1

typedef struct _TASK {
    uint8_t (*TaskEntryPoint) (void); 
    int timelimit;
    int currenttime;
    bool isfreed;
} TASK;


uint16_t KiCreateTask(uint8_t (*TaskEntryPoint) (void), int timelimit);
void KiBeginSchedular();


#endif