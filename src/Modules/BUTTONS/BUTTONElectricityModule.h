#ifndef BUTTONElectricityModule_H
#define BUTTONElectricityModule_H 

#include "stdint.h"

#include "Modules/GLOBAL/PINS_DEFINITIONS.h"
#include "Modules/BUZZERS/BUZZER_TASK.h"
// #include "Modules/LIGHT_SENSORS/LIGHT_SENSOR_TASK.h"


uint8_t CHECK_BUTTON_PHYSICAL_STATS(uint8_t PIN_ID);
void ON_BUTTON_PRESSED(void); 

#endif 