#include "app.h"
#include "Modules/BUTTONS/BUTTONElectricityModule.h"
#include "Modules/LED/LEDElectricityModule.h" 
#include "Modules/utils/Buzzer_Logic.h"
#include "Modules/utils/ControlDDR.h"
#include "Modules/utils/ControlElectricity.h"
#include "Modules/SERIAL_FOLDER/USART_DRIVE.h"
#include "Modules/GLOBAL/ISRFunctionsCallback.h"
#include <avr/io.h>
#include <util/delay.h>

void APP_SET_PINS() {
  SetPinAsInput(&DDRD, PD7); 
  SetPinAsOutput(&DDRD, PD3); 
  SetPinAsOutput(&DDRD, PD5);
  SetPinAsOutput(&DDRD, PD6); 
  SetPinAsOutput(&DDRD, PD4);
  SetPinAsOutput(&DDRB, PB3); 
}

void APP_INIT() {
  APP_SET_PINS(); 
  CONFIGUE_INTTERUPTION_TIME();
  USART_INIT(); 
}

void APP_TASK() {
  OnButtonPressedEvent(); 
}