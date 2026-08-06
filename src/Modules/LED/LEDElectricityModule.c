#include "LEDElectricityModule.h" 
#include "Modules/utils/ControlElectricity.h" 
#include "util/delay.h"
#include <avr/io.h>


int ReturnLEDElectricityStatus(int PIN_ID) {
  int IsTurnedOn = 1; 

  if (PIND & (1 << PIN_ID)) {
      IsTurnedOn = 1;
      return IsTurnedOn; 
  } else {
        IsTurnedOn = 0; 
        return IsTurnedOn;    
      }

}

void TURN_OFF_ALL_LEDS(LED_PINS LED_ARRAY[], int ARRAY_AMOUNT) {
  for (uint8_t i = 0; i < ARRAY_AMOUNT; i++) {
    *LED_ARRAY[i].PORT &= ~(1 << LED_ARRAY[i].PIN); 
  }
} 


void BlinkLED(volatile uint8_t *PORT_ID, uint8_t PIN_ID) {
  
  PutElectricity(PORT_ID, PIN_ID); 

  _delay_ms(500); 

  RemoveElectricity(PORT_ID, PIN_ID); 

  _delay_ms(500);
  
}