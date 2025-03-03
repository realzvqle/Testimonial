#include "mockscheduler.h"
#include "../time/timer.h"
#include <stdint.h>
#include "../driver/uart/uart.h"
#include "ticks.h"
/*


    MOCK SCHEDULER, NOT READY FOR PRODUCTTION



*/


static TASK task[512];
static uint16_t taskamount = 0;


struct TIDRETURN{
    uint16_t tid;
    bool shouldincrement;
};

struct TIDRETURN KiGetFreedTID(){
    for(int i = 0; i < taskamount; i++){
        if(task[taskamount].isfreed == true){
            KiUartPrint("USING PREVIOUS TASK TID");
            struct TIDRETURN tidr = {taskamount, false};
            return tidr;
        }
    }
    //KiUartPrint("H");
    struct TIDRETURN tidr = {taskamount, true};
    return tidr;
}


uint16_t KiCreateTask(uint8_t (*TaskEntryPoint) (void), int timelimit){
    struct TIDRETURN tidr = KiGetFreedTID();
    task[tidr.tid].TaskEntryPoint = TaskEntryPoint;
    task[tidr.tid].timelimit = timelimit;
    task[tidr.tid].isfreed = false;
    if(tidr.shouldincrement == true) taskamount++;
    return tidr.tid;
}



void KiBeginSchedular(){
    while(1){
        KiUpdateTicks();
        for(int i = 0; i < taskamount; i++){
            if(task[i].isfreed == true) continue;
            if(task[i].timelimit == -1) goto SKIPTIMECHECK;
            if(task[i].currenttime < 1){
                task[i].currenttime = 1;
            } else if(task[i].currenttime >= task[i].timelimit){
                task[i].isfreed = true;
                continue;
            } else task[i].currenttime++;
            SKIPTIMECHECK:{}
            uint8_t result = task[i].TaskEntryPoint();
            switch(result){
                case 1:
                    break;
                default:
                    task[i].isfreed = true;
                    break;
            }
        }
    }
    
}



