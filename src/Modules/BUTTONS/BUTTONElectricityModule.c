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
  {&PORTD, PD3},
  {&PORTD, PD3},
}   ; 

void OnButtonPressedEvent(void) { 
  
  static uint8_t IsButtonPressed; 
  static uint8_t ButtonLastState = 0; 
  static int TimesPressedVAR = -1; 

  IsButtonPressed = ReturnButtonElectricityStatus(PD7);
 
  if (IsButtonPressed == 1 && !ButtonLastState) {
    
    TimesPressedVAR++;
    
    if (TimesPressedVAR >= 3) {
      TimesPressedVAR = 0;
      TURN_OFF_ALL_LEDS(LEDS, 3);
      ButtonLastState = IsButtonPressed; 
    } 
    
    else {
      uint8_t CHOSEN_PIN = LEDS[TimesPressedVAR].PIN; 
      REACTORS[TimesPressedVAR](CHOSEN_PIN); 
      PutElectricity(PD3); 
      PutElectricity(PD4); 
      USART_SEND('A');
    }

  }
  
  ButtonLastState = IsButtonPressed; 

}