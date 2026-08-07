#include "BUTTONElectricityModule.h"
#include "Modules/LED/LEDElectricityModule.h"
#include "Modules/utils/ControlDDR.h"
#include "Modules/utils/ControlElectricity.h" 
#include "Modules/SERIAL_FOLDER/USART_DRIVE.h"
#include "Modules/utils/Buzzer_Logic.h"
#include "Modules/utils/TimerInterruptLogic.h"
#include <avr/io.h>
#include <avr/interrupt.h> 
#include <stdio.h>

#include <util/delay.h>
#include <stdint.h>

volatile int TimesPressedVAR = -1; 


uint8_t ReturnButtonElectricityStatus(int PIN_ID) {
  
  if (!(PIND & (1 << PIN_ID))) {
                                                                                            
   _delay_ms(15); 

    if (!(PIND & (1 << PIN_ID))) {
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
  {&PORTB, PB5},
  {&PORTD, PD4},
  {&PORTD, PD5},
}   ; 

ISR(TIMER1_COMPA_vect) {
  volatile uint8_t *CHOSEN_PORT = LEDS[TimesPressedVAR].PORT;    
  uint8_t CHOSEN_PIN = LEDS[TimesPressedVAR].PIN;
  REACTORS[TimesPressedVAR](CHOSEN_PORT, CHOSEN_PIN); 
  InvertElectricity(&PORTD, PD6); 
}

void OnButtonPressedEvent(void) { 
  
  static uint8_t IsButtonPressed; 
  static uint8_t ButtonLastState = 0; 

  IsButtonPressed = ReturnButtonElectricityStatus(PD7);
 
  if (IsButtonPressed == 1 && !ButtonLastState) {
    
    TimesPressedVAR++;
    
    if (TimesPressedVAR >= 3) {
      TimesPressedVAR = -1;
      TURN_OFF_ALL_LEDS(LEDS, 3);
      ButtonLastState = IsButtonPressed; 
    } 
    
    else { 
      USART_SEND('A');
    }

  }
  BUZZER_STOP(); 
  ButtonLastState = IsButtonPressed; 
}