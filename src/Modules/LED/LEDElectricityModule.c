#include "LEDElectricityModule.h"

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

void TASK_BUTTON_LED(void) {
   
  if (TimesPressedVAR < 0 || TimesPressedVAR >= 3) {
    return; 
  }

  volatile uint8_t *CHOSEN_PORT = LEDS[TimesPressedVAR].PORT;
  uint8_t CHOSEN_PIN = LEDS[TimesPressedVAR].PIN;

  REACTORS[TimesPressedVAR](CHOSEN_PORT, CHOSEN_PIN);

}

void TASK_LED_WARN_COMMUNICATION_STATUS() {
  char Result = GET_RESULT(); 

  if (Result == COMMUNICATION_SUCCESS) {

    PutElectricity(&PORTD, PD5);
  } 

  else if (Result == COMMUNICATION_ERROR) {
    TASK_SYSTEMS[5].TASK_TIME = LED_BLINK_ERROR_TIME;
    BUZZER_DEFINE_TASK(BUZZER_FAST_BIP, 1, BUZZER_MODE_HIGH_PITCH); 
    InvertElectricity(&PORTD, PD5); 
  }

  else {
    TASK_SYSTEMS[5].TASK_TIME = LED_BLINK_NULL_TIME;
    BUZZER_DEFINE_TASK(BUZZER_MID_BIP, 0, BUZZER_MODE_BIP); 
    BUZZER_DEFINE_TASK(BUZZER_MID_BIP, 1, BUZZER_MODE_BIP);   
    InvertElectricity(&PORTD, PD5); 
  }

}