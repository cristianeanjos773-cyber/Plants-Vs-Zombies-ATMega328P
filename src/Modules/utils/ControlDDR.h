#ifndef ControlDDR_H  
#define ControlDDR_H
#include <stdint.h> 

void SetPinAsOutput(volatile uint8_t *DDR_ID,  uint8_t PIN_ID);
void SetPinAsInput(volatile uint8_t *DDR_ID, uint8_t PIN_ID); 

#endif 