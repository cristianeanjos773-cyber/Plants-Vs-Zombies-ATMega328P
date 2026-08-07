#pragma once
#include <stdint.h> 
/*
Purpose: to store all types inside of this module. 
*/

typedef struct { /*This will be the type of the requested quests*/
    void(*TASK_FUNCTION)(void); 
    uint8_t TASK_TIME; 
    uint8_t TIMER_COUNTER; 
    uint8_t READY_TO_EXECUTE;
} TASK_CONFIG;
