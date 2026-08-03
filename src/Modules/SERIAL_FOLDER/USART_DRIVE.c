#include <avr/io.h> 
#include <avr/interrupt.h>
#include "USART_DRIVE.h"

void SETUP_RECEIVER_AND_SENDER() {

    if ((UCSR0B & (1 << TXEN0)) && (UCSR0B & (1 << RXEN0))) {
        return;
    }

    UCSR0B |= (1 << TXEN0) | (1 << RXEN0);
    UCSR0B |= (1 << RXCIE0);  

}

volatile char SERIAL_MESSAGE; 

ISR(USART_RX_vect) {
    SERIAL_MESSAGE = UDR0; 
}

void USART_SEND() {}

void USART_INIT() {
    int baud = 9600; 
    uint16_t UBRR_VAL = (F_CPU / (16UL * baud)) - 1;
    UBRR0 = UBRR_VAL;
    UCSR0C = (1 << UCSZ00) | (1 << UCSZ01);
    SETUP_RECEIVER_AND_SENDER(); 
    sei();  
}