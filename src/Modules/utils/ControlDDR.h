#ifndef ControlDDR_H  
#define ControlDDR_H
#include <stdint.h> 

static inline void SetPinAsOutput(volatile uint8_t *DDR_ID,  uint8_t PIN_ID);
static inline void  SetPinAsInput(volatile uint8_t *DDR_ID, uint8_t PIN_ID); 

#endif 