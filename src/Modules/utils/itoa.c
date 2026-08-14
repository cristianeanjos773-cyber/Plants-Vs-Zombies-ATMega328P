#include "itoa.h"


void ITOA(uint16_t VALUE, char *STRING) {
    int8_t i = 4; 
    
    STRING[5] = '\0'; 

    while ((VALUE > 0 || i == 4) && i >= 0) {
        STRING[i] = (VALUE % 10) + '0'; 
        VALUE /= 10;                 
        i--;
    }

    while (i >= 0) {
        STRING[i] = '0';
        i--;
    }

}
