#pragma once 

#include "Modules/BUTTONS/BUTTONElectricityModule.h"
#include "Modules/utils/ControlElectricity.h"
#include "Modules/LED/LEDElectricityModule.h"
#include <avr/io.h>
#include <stdint.h> 

extern volatile int TimesPressedVAR; 
extern LED_PINS LEDS[]; 
extern void (*REACTORS[])(volatile uint8_t *PORT_ID, uint8_t PIN_ID);

void LED_CALLBACK();
void BUZZER_CALLBACK(); 