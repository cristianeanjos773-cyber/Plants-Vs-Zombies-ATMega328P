#include "ON_SERIAL_MESSAGE.h"

void ON_SERIAL_MESSAGE(char MESSAGE) {
    
    if (MESSAGE == 'K') {
        PutElectricity(&PORTD, BOT_CONTROLLED_LED);
    }
        
    else if (MESSAGE == 'J') {
        RemoveElectricity(&PORTD, BOT_CONTROLLED_LED); 
    }
    
}