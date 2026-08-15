#include "LIGHT_SENSOR_TASK.h"
#include "Modules/SERIAL_FOLDER/USART_TASK.h"
#include "Modules/SERIAL_FOLDER/USART_TASK_MESSAGES.h" 
#include "Modules/utils/itoa.h" 

void LIGHT_SENSOR_INIT(void) {
    
    ADMUX |= (1 << REFS0);
    
    ADCSRA |= (1 << ADEN);  
    ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
    DIDR0 |= (1 << ADC0D);

}

void LIGHT_SENSOR_TASK(void) {
    char ADC_STRING_BUFFER[6]; 
    uint16_t ADC_BYTE = LIGHT_SENSOR_READ(ANALOG_PIN_0);  

    uint8_t MOST_MEANINGFUL_BYTE = (ADC_BYTE >> 8) & 0xFF; 
    uint8_t LEAST_MEANINGFUL_BYTE = ADC_BYTE & 0xFF;        
    
    //ITOA(ADC_BYTE, ADC_STRING_BUFFER);
    //USART_SEND_STRING(ADC_STRING_BUFFER); 

    /*
    *When lain iwakura ATmega328P bot reads the character 'L' coming, it will expect the next sequence of incoming bytes in the Serial port to be 
    *The 10 bits light message 
    */

    USART_SEND(LIGHT_MESSAGE); 
    USART_SEND(MOST_MEANINGFUL_BYTE); 
    USART_SEND(LEAST_MEANINGFUL_BYTE); 

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

