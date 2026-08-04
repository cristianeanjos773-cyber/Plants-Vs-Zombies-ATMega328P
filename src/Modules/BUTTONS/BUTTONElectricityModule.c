#include "BUTTONElectricityModule.h"
#include "Modules/LED/LEDElectricityModule.h"
#include "Modules/utils/ControlDDR.h"
#include "Modules/utils/ControlElectricity.h" 
#include "Modules/SERIAL_FOLDER/USART_DRIVE.h"
#include <avr/io.h> 
#include <stdio.h>
#include <util/delay.h>
#include <stdint.h>

uint8_t ReturnButtonElectricityStatus(int PIN_ID) {
  
  if (!(PIND & (1 << PIN_ID))) {
                                                                                            
   _delay_ms(15); 

    if (!(PIND & (1 << PIN_ID))) {
      return 1; 
    }

  }

  return 0; 

}

void (*REACTORS[])() = {
  BlinkLED, 
  PutElectricity,   
  BlinkLED, 
}   ;

LED_PINS LEDS[3] = {
  {&PORTD, PD3},
  {&PORTD, PD4},
  {&PORTD, PD7},
}   ; 

// PD3 = Green, PD4 = Yellow (reminder)



void OnButtonPressedEvent(void) { 
  
  SetPinAsOutput(PD3);
  SetPinAsOutput(PD4); 
  SetPinAsOutput(PD7);

  static uint8_t IsButtonPressed; 

  IsButtonPressed = ReturnButtonElectricityStatus(PD5);
  static uint8_t ButtonLastState = 0; 
  static int TimesPressedVAR = -1; 

  if (IsButtonPressed == 1 && !ButtonLastState) {
    TimesPressedVAR++;
    USART_SEND('A'); 
  }

  ButtonLastState = IsButtonPressed; 

  if (TimesPressedVAR >= 3) {
    TimesPressedVAR = 0;
    TURN_OFF_ALL_LEDS(LEDS, 3); 
    return;  
  }

  uint8_t CHOSEN_PIN = LEDS[TimesPressedVAR].PIN; 
  
  
  REACTORS[TimesPressedVAR](CHOSEN_PIN);
  

}