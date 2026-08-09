#include "itoa.h"


void ITOA(uint16_t VALUE, char *STRING) {
    int8_t i = 3; 
    
    STRING[4] = '\0'; 

    while ((VALUE > 0 || i == 3) && i >= 0) {
        STRING[i] = (VALUE % 10) + '0'; 
        VALUE /= 10;                 
        i--;
    }

    while (i >= 0) {
        STRING[i] = ' ';
        i--;
    }

}
