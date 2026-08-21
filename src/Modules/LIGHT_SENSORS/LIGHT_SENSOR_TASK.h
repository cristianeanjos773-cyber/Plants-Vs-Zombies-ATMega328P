#pragma once 
#include "stdint.h"

#include <avr/io.h>

#include "Modules/utils/ControlElectricity.h"
#include "Modules/SERIAL_FOLDER/USART_DRIVE.h"
#include "Modules/GLOBAL/PINS_DEFINITIONS.h"



void LIGHT_SENSOR_INIT(void);
void LIGHT_SENSOR_TASK(void);  
uint16_t LIGHT_SENSOR_READ(uint8_t ANALOG_CANAL); 