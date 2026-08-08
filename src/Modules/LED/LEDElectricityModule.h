#ifndef LEDElectricityModule_H
#define LEDElectricityModule_H
#include "Modules/BUTTONS/BUTTONElectricityModule.h"
#include <stdint.h>

typedef struct {
  volatile uint8_t *PORT; 
  uint8_t PIN; 
} LED_PINS; 

extern volatile int TimesPressedVAR; 
extern LED_PINS LEDS[]; 
extern void (*REACTORS[3])(volatile uint8_t *PORT_ID, uint8_t PIN_ID); 

void TURN_OFF_ALL_LEDS(LED_PINS LED_ARRAY[], int ARRAY_AMOUNT); 
void TASK_LED(); 
int ReturnLEDElectricityStatus(volatile uint8_t *PORT_CHECK_ID, uint8_t PIN_ID); 

#endif 