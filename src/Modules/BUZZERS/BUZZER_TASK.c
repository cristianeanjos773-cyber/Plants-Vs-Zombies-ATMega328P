/*
The reason why im making a ltieral wrapper for invert electricity is because the task scheduler needs a function to control 
instead of a generic function like Inverelectricity 
all functions require void, invert electricity does not require void 
*/
#include "BUZZER_TASK.h" 

void BUZZER_TASK(void) {
   static uint8_t BUZZER_PLAYING = 0; 
   
   if (TimesPressedVAR < 0 || TimesPressedVAR >= 3) {
    return; 
   }

   if (!BUZZER_PLAYING) {
        BUZZER_PLAYING = 1; 
        BUZZER_PLAY(); 
   } else {
        BUZZER_PLAYING = 0;
        BUZZER_STOP();  
   }

}

void BUZZER_PLAY(void) {
    TCCR0A |= (1 << WGM01) | (1 << COM0A0); 
    TCCR0B |= (1 << CS01) | (1 << CS00); 
    OCR0A = 70; 
 }

void BUZZER_STOP(void) {
    TCCR0A = 0; 
    TCCR0B = 0; 
    RemoveElectricity(&PORTD, PD6); 
}