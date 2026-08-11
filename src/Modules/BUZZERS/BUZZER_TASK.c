/*
* The reason why im making a ltieral wrapper for invert electricity is because the task scheduler needs a function to control 
* instead of a generic function like Inverelectricity 
* all functions require void, invert electricity does not require void 
*/

#include "BUZZER_TASK.h" 

static uint8_t BUZZER_PLAY_TIME = 0; 
static uint8_t BUZZER_ENABLED = 0; 
static BUZZER_MODE_ENUM BUZZER_MODE = BUZZER_MODE_HIGH_PITCH; 

void BUZZER_TASK(void) {   
    
    if (!BUZZER_ENABLED) {
        return; 
    }

   if (BUZZER_MODE == BUZZER_MODE_HIGH_PITCH) { 
    BUZZER_HIGH_PITCH(); 
   } else if (BUZZER_MODE == BUZZER_MODE_BIP) {
    BUZZER_BIP(); 
   }

}

void BUZZER_HIGH_PITCH(void) {
   static uint8_t BUZZER_PLAYING = 0; 
   
    if (!BUZZER_PLAYING) {
        BUZZER_PLAYING = 1;
        BUZZER_PLAY(); 
    } else {
        BUZZER_PLAYING = 0;
        BUZZER_STOP();  
    }

}

void BUZZER_BIP(void) {
   static uint8_t BIP_TIME = 0; 
   static uint8_t MAX_BIP_TIME = 10;  

   if (BIP_TIME == 0) {
      BUZZER_PLAY(); 
    }

    BIP_TIME++; 

    if (BIP_TIME == MAX_BIP_TIME) {
      BUZZER_STOP();
      BUZZER_ENABLED = 0; 
      BIP_TIME = 0;  
    }
}

void BUZZER_PLAY(void) {
    TCCR0A |= (1 << WGM01) | (1 << COM0A0); 
    TCCR0B |= (1 << CS01) | (1 << CS00); 
    OCR0A = BUZZER_PLAY_TIME; 
}

void BUZZER_STOP(void) {
    TCCR0A = 0; 
    TCCR0B = 0; 
    RemoveElectricity(&PORTD, PD6); 
}

void BUZZER_DEFINE_TASK(const BUZZER_TASK_CONFIG *BUZZER_CONFIG, uint8_t BUZZER_ENABLED_STATUS, BUZZER_MODE_ENUM BUZZER_PLAY_MODE) {   
    BUZZER_PLAY_TIME = (uint8_t)BUZZER_CONFIG->BUZZER_SPEED; 
    BUZZER_ENABLED = BUZZER_ENABLED_STATUS;
    BUZZER_MODE = BUZZER_PLAY_MODE;   
}