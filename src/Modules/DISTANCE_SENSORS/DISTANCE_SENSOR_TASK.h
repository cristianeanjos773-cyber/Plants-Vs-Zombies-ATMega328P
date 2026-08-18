#pragma once 
#include "stdint.h"

#include <avr/io.h>

#include "Modules/utils/ControlElectricity.h"
#include "Modules/SERIAL_FOLDER/USART_DRIVE.h"

void DISTANCE_SENSOR_TASK(void); 
void DISTANCE_SENSOR_MEASURE_MICROSSECONDS(void);
void DISTANCE_SENSOR_MEASURE_CM(void);  