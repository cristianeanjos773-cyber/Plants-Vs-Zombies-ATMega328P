#pragma once 
#include "stdint.h"

#include <avr/io.h>

#include "Modules/utils/ControlElectricity.h"

#include "Modules/SERIAL_FOLDER/USART_DRIVE.h"
#include "Modules/SERIAL_FOLDER/USART_SAFE_SEND.h" 

#include "Modules/SERIAL_FOLDER/USART_TASK_MESSAGES.h" 

#include "Modules/GLOBAL/GLOBAL_TYPES.h"

void DISTANCE_SENSOR_TASK(void); 
uint8_t DISTANCE_SENSOR_MEASURE_CM(void);  

static inline void TURN_ON_TIMER1_REGISTERS(void) {
    TCCR2A = 0;
    TCCR2B &= ~((1 << CS22) | (1 << CS21) | (1 << CS20));
    TCCR2B |= (1 << CS21) | (1 << CS20);
}
