#include "Buzzer_Logic.h"
#include <util/delay.h>
#include "Modules/utils/ControlElectricity.h"
#include <avr/io.h>

void BUZZER_START() {
    TCCR2A  = (1 << COM2B0) | (1 << WGM21); 
    OCR2A = 70; 
    TCCR2B  = (1<< CS22) | (1 << CS21); 
}

void BUZZER_STOP() {
    TCCR2B  = 0; 
    RemoveElectricity(&PORTB, PB3);
}