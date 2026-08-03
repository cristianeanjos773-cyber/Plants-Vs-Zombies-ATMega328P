#include <avr/io.h>
#include "ControlElectricity.h"

void PutElectricity(int PIND_ID) {
  PORTD |= (1 << PIND_ID); 
}

void RemoveElectricity(int PIN_ID) {
  PORTD &= ~(1 << PIN_ID); 
}