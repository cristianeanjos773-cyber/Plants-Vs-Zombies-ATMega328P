#include "TimerInterruptLogic.h"
#define LED_BEATS 31250   
#define BUZZER_BEATS 16

void CONFIGUE_INTTERUPTION_TIME(){
    //uint16_t MAX_NUMBER = 65535; 
    
    TCCR1A = 0;
    TCCR1B = 0; 

    TCCR1B |= (1 << WGM12);
    OCR1A = LED_BEATS;
    OCR1B = BUZZER_BEATS; 
    TIMSK1 |= (1 << OCIE1A) | (1 << OCIE1B); 
    TCCR1B |= (1 << CS12);

    sei(); 
}