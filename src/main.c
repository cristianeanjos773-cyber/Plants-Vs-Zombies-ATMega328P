#include <avr/io.h>
#include <util/delay.h>
#include "Modules/BUTTONS/BUTTONElectricityModule.h"
#include "Modules/LED/LEDElectricityModule.h" 
#include "Modules/utils/ControlDDR.h"
#include "Modules/utils/ControlElectricity.h"

int main(void) {
  SetPinAsInput(PD5); 
  PutElectricity(PD5); 
  while (1) { 
    OnButtonPressedEvent(); 
  }
  
}   
