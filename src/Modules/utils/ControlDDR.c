#include "ControlDDR.h"
#include <avr/io.h> 

void SetPinAsOutput(int PIN_ID) {
  DDRD |= (1 << PIN_ID);  
}

void SetPinAsInput(int PIN_ID) {
    DDRD &= ~(1 << PIN_ID);  
}