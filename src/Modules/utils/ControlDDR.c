#include "ControlDDR.h"
#include <avr/io.h> 

void SetPinAsOutput(volatile uint8_t *DDR_ID, uint8_t PIN_ID) {
 *DDR_ID |= (1 << PIN_ID);  
}

void SetPinAsInput(volatile uint8_t *DDR_ID, uint8_t PIN_ID) {
  *DDR_ID &= ~(1 << PIN_ID);  
}