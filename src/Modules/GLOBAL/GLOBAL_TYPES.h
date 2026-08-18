#pragma once
#include <stdint.h> 
/*
Purpose: to store all types AND Enuums inside of this module. 
*/

typedef struct { /*This will be the type of the requested quests*/
    void(*TASK_FUNCTION)(void); 
    volatile uint16_t TASK_TIME; // how much time this task should run  
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

typedef enum {
    TRIGGER_ACTIVATED, 
    ECHO_ACTIVATED, 
} DISTANCE_TASK_ENUM ; 

typedef void (*USART_SENDERS)(const char *MESSAGE); 

typedef struct {
    BUZZER_SPEED_ENUM BUZZER_SPEED; 
    BUZZER_MODE_ENUM BUZZER_MODE;
} BUZZER_TASK_CONFIG    ;

static const BUZZER_TASK_CONFIG BUZZER_FAST_BIP[1] = {
  {.BUZZER_SPEED = FAST_BUZZER_SPEED},
}   ; 

static const BUZZER_TASK_CONFIG BUZZER_MID_BIP[1] = {
    {.BUZZER_SPEED = NORMAL_BUZZER_SPEED}
}; 

static const BUZZER_TASK_CONFIG BUZZER_SLOW_BIP[1] = {
    {.BUZZER_SPEED = SLOW_BUZZER_SPEED} 
}; 
