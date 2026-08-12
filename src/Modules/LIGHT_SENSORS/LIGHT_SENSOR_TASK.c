#include "LIGHT_SENSOR_TASK.h"
#include "Modules/utils/itoa.h"

void LIGHT_SENSOR_INIT(void) {
    
    ADMUX |= (1 << REFS0);
    
    ADCSRA |= (1 << ADEN);  
    ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
    DIDR0 |= (1 << ADC0D);

}

void LIGHT_SENSOR_TASK(void) {
    char ADC_STRING_BUFFER[5]; 
    uint16_t ADC_BYTE = LIGHT_SENSOR_READ(ANALOG_PIN_0);  

    ITOA(ADC_BYTE, ADC_STRING_BUFFER);
    
    USART_SEND_STRING(ADC_STRING_BUFFER); 

}

uint16_t LIGHT_SENSOR_READ(uint8_t ANALOG_CANAL) {
    
    if (ANALOG_CANAL > 7) {
        ANALOG_CANAL = 7;  
    } 

    ADMUX = (ADMUX & 0xF0) | ANALOG_CANAL;
    ADCSRA |= (1 << ADSC); 

    while (ADCSRA & (1 << ADSC)); 

    return ADC; 

}

