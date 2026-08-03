#include "BUTTONReactors.h"
#include "Modules/LED/LEDElectricityModule.h"
#include "Modules/utils/ControlElectricity.h"
#include <avr/io.h> 

void PressedOnce() {
    BlinkLED(PD3); 
}

void PressedTwice() {
    PutElectricity(PD4); 
} 

void PressedThreeTimes() {
    BlinkLED(PD7); 
}