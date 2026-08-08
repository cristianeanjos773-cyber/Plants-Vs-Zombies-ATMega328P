#pragma once 
#include "stdint.h"
#include <avr/io.h>

void LIGHT_SENSOR_INIT();
uint16_t LIGHT_SENSOR_READ(uint8_t ANALOG_CANAL); 