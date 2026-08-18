#include "TASK_SCHEDULER.h"
#include <avr/interrupt.h>

TASK_CONFIG TASK_SYSTEMS[TOTAL_TASKS] = {
    {TASK_BUTTON_LED, 1000, 0, 0},
    {ON_BUTTON_PRESSED, 20, 0, 0}, 
    {BUZZER_TASK, 16, 0, 0}, 
    {LIGHT_SENSOR_TASK, 6000, 0, 0}, 
    {USART_TASK, 200, 0, 0}, 
    {TASK_LED_WARN_COMMUNICATION_STATUS, 1000, 0, 0}, 
    {DISTANCE_SENSOR_TASK, 100, 0, 0}, 
}; 



void SCHEDULER_INIT(void) {

    TCCR1B = 0;
    TCCR1B |= (1 << WGM12);
    OCR1A = 62;
    TIMSK1 |= (1 << OCIE1A);
    TCCR1B |= (1 << CS12);
    sei(); 
    
}

ISR(TIMER1_COMPA_vect) {
    for (uint8_t i = 0; i < TOTAL_TASKS; i++) {
        TASK_SYSTEMS[i].TIMER_COUNTER++; 

        if (TASK_SYSTEMS[i].TIMER_COUNTER >= TASK_SYSTEMS[i].TASK_TIME) {
            TASK_SYSTEMS[i].TIMER_COUNTER = 0; 
            TASK_SYSTEMS[i].READY_TO_EXECUTE = 1; 
        }

    }
}

void SCHEDULER_RUN(void) {
    for (uint8_t i = 0; i < TOTAL_TASKS; i++) {
        if (TASK_SYSTEMS[i].READY_TO_EXECUTE == 1) {
            TASK_SYSTEMS[i].TASK_FUNCTION(); 
            TASK_SYSTEMS[i].READY_TO_EXECUTE = 0;
        }
    }
}