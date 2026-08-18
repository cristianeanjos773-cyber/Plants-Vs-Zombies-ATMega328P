#include "ControlDDR.h"
#include <avr/io.h> 

static inline void SetPinAsOutput(volatile uint8_t *DDR_ID, uint8_t PIN_ID) {
 *DDR_ID |= (1 << PIN_ID);  
}

static inline void SetPinAsInput(volatile uint8_t *DDR_ID, uint8_t PIN_ID) {
  *DDR_ID &= ~(1 << PIN_ID);  
}