#ifndef  ControlElectricity_H
#define ControlElectricity_H
#include <stdint.h>

static inline void RemoveElectricity(volatile uint8_t *PORT_ID, uint8_t PIN_ID); 
static inline void PutElectricity(volatile uint8_t *PORT_ID, uint8_t PIN_ID);
static inline void InvertElectricity(volatile uint8_t *PORT_ID, uint8_t PIN_ID); 

#endif 