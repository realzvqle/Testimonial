#include "mockscheduler.h"


/*


    MOCK SCHEDULER, NOT READY FOR PRODUCTTION



*/


static TASK task[512];
static uint16_t taskamount = 0;

uint16_t KiCreateTask(uint8_t (*TaskEntryPoint) (void)){
    task[taskamount].TaskEntryPoint = TaskEntryPoint;
    taskamount++;
    return taskamount - 1;
}



void KiBeginSchedular(){
    while(1){
        for(int i = 0; i < taskamount; i++){
            uint8_t result = task[i].TaskEntryPoint();
            switch(result){
                case 1:
                    break;
                default:
                    taskamount--;
                    break;
            }
        }
        //KiSleepMi(500);
    }
    
}



