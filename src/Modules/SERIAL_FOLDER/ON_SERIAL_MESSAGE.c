#include "ON_SERIAL_MESSAGE.h"

void ON_SERIAL_MESSAGE(char MESSAGE) {
    
    if (MESSAGE == 'K') {
        PutElectricity(&PORTD, PD2);
    }
        
    else if (MESSAGE == 'J') {
        RemoveElectricity(&PORTD, PD2); 
    }
    
}