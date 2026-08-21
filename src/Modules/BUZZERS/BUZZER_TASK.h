#pragma once
#include "Modules/utils/ControlElectricity.h"
#include "Modules/BUTTONS/BUTTONElectricityModule.h"
#include "Modules/SERIAL_FOLDER/USART_DRIVE.h"
#include "Modules/GLOBAL/GLOBAL_TYPES.h"
#include "Modules/GLOBAL/PINS_DEFINITIONS.h"
#include <avr/io.h>

extern volatile uint8_t TimesPressedVAR; 

void BUZZER_TASK(void); 
void BUZZER_PLAY(void); 

void BUZZER_STOP(void); 
void BUZZER_BIP(void); 
void BUZZER_HIGH_PITCH(void); 

void BUZZER_DEFINE_TASK(const BUZZER_TASK_CONFIG *BUZZER_CONFIG, uint8_t BUZZER_ENABLED_STATUS, BUZZER_MODE_ENUM BUZZER_PLAY_MODE); 
