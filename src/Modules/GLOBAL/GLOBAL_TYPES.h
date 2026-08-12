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
} TASK_CONFIG   ;

typedef enum {
    FAST_BUZZER_SPEED = 61,
    NORMAL_BUZZER_SPEED = 150, 
    SLOW_BUZZER_SPEED = 200, 
} BUZZER_SPEED_ENUM ; 

typedef enum {
    BUZZER_MODE_BIP,
    BUZZER_MODE_HIGH_PITCH, 
} BUZZER_MODE_ENUM  ;

typedef void (*USART_SENDERS)(char *MESSAGE); 


typedef struct {
    BUZZER_SPEED_ENUM BUZZER_SPEED; 
    BUZZER_MODE_ENUM BUZZER_MODE;
} BUZZER_TASK_CONFIG    ;
