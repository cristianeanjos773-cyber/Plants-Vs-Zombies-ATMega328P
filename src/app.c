#include "app.h"
#include "Modules/BUTTONS/BUTTONElectricityModule.h"
#include "Modules/LED/LEDElectricityModule.h" 
#include "Modules/utils/ControlDDR.h"
#include "Modules/utils/ControlElectricity.h"
#include "Modules/SERIAL_FOLDER/USART_DRIVE.h"

void APP_SET_PINS() {
  SetPinAsInput(PD7); 
  PutElectricity(PD7);
  SetPinAsOutput(PD3); 
  SetPinAsOutput(PD4); 
}

void APP_INIT() {
  APP_SET_PINS(); 
  USART_INIT(); 
}

void APP_TASK() {
  OnButtonPressedEvent(); 
}