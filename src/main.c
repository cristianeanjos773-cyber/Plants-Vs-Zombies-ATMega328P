#include <avr/io.h>
#include <util/delay.h>
#include "Modules/BUTTONS/BUTTONElectricityModule.h"
#include "Modules/LED/LEDElectricityModule.h" 
#include "Modules/utils/ControlDDR.h"
#include "Modules/utils/ControlElectricity.h"
#include "Modules/SERIAL_FOLDER/USART_DRIVE.h"

int main(void) {
  
  SetPinAsInput(PD5); 
  PutElectricity(PD5); 
  USART_INIT(); 

  while (1) { 
    OnButtonPressedEvent(); 
  }
  
}   
