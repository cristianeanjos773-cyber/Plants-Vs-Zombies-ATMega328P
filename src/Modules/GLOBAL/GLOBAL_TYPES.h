#pragma once
#include <stdint.h> 
/*
Purpose: to store all types inside of this module. 
*/

typedef struct { /*This will be the type of the requested quests*/
    void(*TASK_FUNCTION)(void); 
    uint16_t TASK_TIME; // how much time this task should run  
    uint16_t TIMER_COUNTER; // the count thats gonna increase as time passes
    uint8_t READY_TO_EXECUTE;
} TASK_CONFIG;
