#pragma once 
#include "stdint.h"

#include <avr/io.h>

#include "Modules/utils/ControlElectricity.h"
#include "Modules/SERIAL_FOLDER/USART_DRIVE.h"

#define ANALOG_PIN_0 0 // ANALOG PIN 0 MUST BE WHERE THE LIGHT SENSOR IS. 

void LIGHT_SENSOR_INIT(void);
void LIGHT_SENSOR_TASK(void);  
uint16_t LIGHT_SENSOR_READ(uint8_t ANALOG_CANAL); 