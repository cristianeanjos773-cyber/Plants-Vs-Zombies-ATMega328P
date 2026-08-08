#pragma once
#include "GLOBAL_TYPES.h"
#include "Modules/LED/LEDElectricityModule.h"
#include <avr/io.h>
#include "Modules/BUTTONS/BUTTONElectricityModule.h"
#include "Modules/BUZZERS/BUZZER_TASK.h"

void SCHEDULER_INIT(void);
void SCHEDULER_RUN(void);  
