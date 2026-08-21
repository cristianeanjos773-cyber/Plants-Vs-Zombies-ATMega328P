#pragma once

#include "Modules/BUTTONS/BUTTONElectricityModule.h"
#include "Modules/LED/LEDElectricityModule.h" 
#include "Modules/LIGHT_SENSORS/LIGHT_SENSOR_TASK.h"

#include "Modules/utils/ControlDDR.h"
#include "Modules/utils/ControlElectricity.h"

#include "Modules/SERIAL_FOLDER/USART_DRIVE.h"

#include "Modules/GLOBAL/ISRFunctionsCallback.h"
#include "Modules/GLOBAL/TASK_SCHEDULER.h"
#include "Modules/GLOBAL/PINS_DEFINITIONS.h"

#include <avr/io.h>
#include <util/delay.h>

#include "Modules/GLOBAL/GLOBAL_TYPES.h"


void APP_INIT(); 
void APP_TASK(); 
void APP_SET_PINS(); 