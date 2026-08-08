#include "LEDElectricityModule.h" 
#include "Modules/utils/ControlElectricity.h" 
#include "util/delay.h"
#include <stdint.h>
#include <avr/io.h>


int ReturnLEDElectricityStatus(volatile uint8_t *PORT_CHECK_ID, uint8_t PIN_ID) {
  int IsTurnedOn = 1; 

  if (*PORT_CHECK_ID & (1 << PIN_ID)) {
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

void TASK_LED(void) {
   
  if (TimesPressedVAR < 0 || TimesPressedVAR >= 3) {
    return; 
  }

  volatile uint8_t *CHOSEN_PORT = LEDS[TimesPressedVAR].PORT;
  uint8_t CHOSEN_PIN = LEDS[TimesPressedVAR].PIN;

  REACTORS[TimesPressedVAR](CHOSEN_PORT, CHOSEN_PIN);

}