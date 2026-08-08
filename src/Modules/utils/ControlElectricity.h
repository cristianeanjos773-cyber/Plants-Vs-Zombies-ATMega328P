#ifndef  ControlElectricity_H
#define ControlElectricity_H
#include <stdint.h>

void RemoveElectricity(volatile uint8_t *PORT_ID, uint8_t PIN_ID); 
void PutElectricity(volatile uint8_t *PORT_ID, uint8_t PIN_ID);
void InvertElectricity(volatile uint8_t *PORT_ID, uint8_t PIN_ID); 

#endif 