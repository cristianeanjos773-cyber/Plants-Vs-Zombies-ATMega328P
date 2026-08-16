#ifndef LEDElectricityModule_H
#define LEDElectricityModule_H

#include "Modules/BUTTONS/BUTTONElectricityModule.h"
#include <stdint.h>
#include "LEDElectricityModule.h" 
#include "Modules/utils/ControlElectricity.h" 
#include "Modules/SERIAL_FOLDER/USART_TASK.h"
#include "util/delay.h"
#include <stdint.h>
#include <avr/io.h>

typedef struct {
  volatile uint8_t *PORT; 
  uint8_t PIN; 
} LED_PINS; 

extern volatile uint8_t TimesPressedVAR; 
extern LED_PINS LEDS[]; 
extern void (*REACTORS[3])(volatile uint8_t *PORT_ID, uint8_t PIN_ID); 


void TURN_OFF_ALL_LEDS(LED_PINS LED_ARRAY[], int ARRAY_AMOUNT); 
void TASK_BUTTON_LED(); 
void TASK_LED_WARN_COMMUNICATION_STATUS(void);
int ReturnLEDElectricityStatus(volatile uint8_t *PORT_CHECK_ID, uint8_t PIN_ID); 

#endif 