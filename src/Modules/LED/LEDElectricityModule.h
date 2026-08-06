#ifndef LEDElectricityModule_H
#define LEDElectricityModule_H
#include <stdint.h>

typedef struct {
  volatile uint8_t *PORT; 
  uint8_t PIN; 
} LED_PINS; 

void TURN_OFF_ALL_LEDS(LED_PINS LED_ARRAY[], int ARRAY_AMOUNT); 
void BlinkLED(volatile uint8_t *PORT_ID, uint8_t PIN_ID); 
int ReturnLEDElectricityStatus(int PIN_ID); 

#endif 