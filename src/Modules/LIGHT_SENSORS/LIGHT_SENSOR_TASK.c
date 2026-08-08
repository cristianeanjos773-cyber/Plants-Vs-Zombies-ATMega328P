#include "LIGHT_SENSOR_TASK.h"

void LIGHT_SENSOR_INIT(void) {
    
    ADMUX |= (1 << REFS0);
    
    ADCSRA |= (1 << ADEN);  
    ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

}

uint16_t LIGHT_SENSOR_READ(uint8_t ANALOG_CANAL) {
    
    if (ANALOG_CANAL > 7) {
        ANALOG_CANAL = 7;  
    } else if (ANALOG_CANAL < 0) {
        ANALOG_CANAL = 1;
    }

    ADMUX = (ADMUX & 0xF10) | ANALOG_CANAL;
    ADCSRA |= (1 << ADSC); 

    return ADC; 

}