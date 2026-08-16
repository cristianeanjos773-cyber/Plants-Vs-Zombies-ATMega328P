#pragma once
#include "GLOBAL_TYPES.h"
#include "Modules/LED/LEDElectricityModule.h"
#include <avr/io.h>
#include "Modules/BUTTONS/BUTTONElectricityModule.h"
#include "Modules/BUZZERS/BUZZER_TASK.h"
#include "Modules/LIGHT_SENSORS/LIGHT_SENSOR_TASK.h"
#include "Modules/SERIAL_FOLDER/USART_TASK.h"
#define TOTAL_TASKS 6 

extern TASK_CONFIG TASK_SYSTEMS[TOTAL_TASKS]; 

void SCHEDULER_INIT(void);
void SCHEDULER_RUN(void);  
