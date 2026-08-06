#include <avr/io.h>
#include "ControlElectricity.h"
#include <stdint.h> 

void PutElectricity(volatile uint8_t *PORT_ID, uint8_t PIN_ID) {
  *PORT_ID |= (1 << PIN_ID); 
}

void RemoveElectricity(volatile uint8_t *PORT_ID, uint8_t PIN_ID) {
  *PORT_ID &= ~(1 << PIN_ID); 
}

void InvertElectricity(volatile uint8_t *PORT_ID, uint8_t PIN_ID) {
  *PORT_ID ^= (1 << PIN_ID); 
}