#include "app.h"

#include "Modules/BUTTONS/BUTTONElectricityModule.h"
#include "Modules/LED/LEDElectricityModule.h" 

#include "Modules/utils/ControlDDR.h"
#include "Modules/utils/ControlElectricity.h"

#include "Modules/SERIAL_FOLDER/USART_DRIVE.h"

#include "Modules/GLOBAL/ISRFunctionsCallback.h"
#include "Modules/GLOBAL/TASK_SCHEDULER.h"

#include <avr/io.h>
#include <util/delay.h>

void APP_SET_PINS() {
  SetPinAsInput(&DDRB, PB4); // THIS SHOULD BE A BUTTON 
  PutElectricity(&PORTB, PB4); 
  SetPinAsOutput(&DDRD, PD5); // THIS AND PD4 SHOULD BE LEDS 
  SetPinAsOutput(&DDRD, PD6); // THIS MUST BE A BUZZER 
  SetPinAsOutput(&DDRD, PD4);
}

void APP_INIT() {
  APP_SET_PINS(); 
  SCHEDULER_INIT();  
  USART_INIT(); 
}

void APP_TASK() {
  SCHEDULER_RUN();  
}