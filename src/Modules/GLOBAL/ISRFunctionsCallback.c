#include "ISRFunctionsCallback.h"
#define LED_BEATS 31250   
#define BUZZER_BEATS 16

void LED_CALLBACK() {

   if (TimesPressedVAR < 0 || TimesPressedVAR >= 3) {
      return; 
   }

  volatile uint8_t *CHOSEN_PORT = LEDS[TimesPressedVAR].PORT;    
  uint8_t CHOSEN_PIN = LEDS[TimesPressedVAR].PIN;
  REACTORS[TimesPressedVAR](CHOSEN_PORT, CHOSEN_PIN); 
  OCR1A += LED_BEATS;

}

void BUZZER_CALLBACK() {
    InvertElectricity(&PORTD, PD6); 
    OCR1B += BUZZER_BEATS; 
}