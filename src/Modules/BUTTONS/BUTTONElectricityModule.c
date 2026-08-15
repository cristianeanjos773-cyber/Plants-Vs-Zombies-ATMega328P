#include "BUTTONElectricityModule.h"

#include "Modules/LED/LEDElectricityModule.h"
#include "Modules/utils/ControlDDR.h"
#include "Modules/utils/ControlElectricity.h" 

#include "Modules/SERIAL_FOLDER/USART_DRIVE.h"
#include "Modules/BUZZERS/BUZZER_TASK.h"
#include "Modules/SERIAL_FOLDER/USART_TASK.h"
#include "Modules/GLOBAL/GLOBAL_TYPES.h"

#include <avr/io.h>
#include <avr/interrupt.h> 
#include <stdio.h>
#include <util/delay.h>
#include <stdint.h>

volatile int TimesPressedVAR = -1; 

uint8_t CHECK_BUTTON_PHYSICAL_STATS(int PIN_ID) {
  
  if (!(PINB & (1 << PIN_ID))) {
                                                                                            
   _delay_ms(15); 

    if (!(PINB & (1 << PIN_ID))) {
      
      while (!(PINB & (1 << PIN_ID))) {}

      _delay_ms(15); 

      return 1; 

    }

  }

  return 0; 

}

void (*REACTORS[])(volatile uint8_t *PORT_ID, uint8_t PIN_ID) = {
  InvertElectricity, 
  PutElectricity,   
  InvertElectricity, 
}   ;

LED_PINS LEDS[3] = {
  {&PORTD, PD5},
  {&PORTD, PD3},
  {&PORTD, PD5},
}   ; 



void ON_BUTTON_PRESSED(void) { 
  
  static uint8_t IsButtonPressed; 
  static uint8_t ButtonLastState = 0; 
  
  IsButtonPressed = CHECK_BUTTON_PHYSICAL_STATS(PB4);
 
  if (IsButtonPressed == 1 && !ButtonLastState) {

    TimesPressedVAR++;
    
    if (TimesPressedVAR >= 3) {
      TimesPressedVAR = -1;
      TURN_OFF_ALL_LEDS(LEDS, 3);
      BUZZER_DEFINE_TASK(BUZZER_FAST_BIP, 0, BUZZER_MODE_BIP);    
    }

    else { 
      char message = 'B'; 
      
      BUZZER_DEFINE_TASK(BUZZER_FAST_BIP, 1, BUZZER_MODE_BIP);    
      USART_SAFE_SEND(&message, LETTER_MODE);
      InvertElectricity(&PORTD, PD6); 
    }  

  }

  ButtonLastState = IsButtonPressed; 

}