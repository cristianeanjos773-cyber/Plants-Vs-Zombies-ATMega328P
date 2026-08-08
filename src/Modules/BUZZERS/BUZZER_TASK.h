#pragma once
#include "Modules/utils/ControlElectricity.h"
#include "Modules/BUTTONS/BUTTONElectricityModule.h"
#include <avr/io.h>

extern volatile int TimesPressedVAR; 

void BUZZER_TASK(void); 
void BUZZER_PLAY(void); 
void BUZZER_STOP(void); 
