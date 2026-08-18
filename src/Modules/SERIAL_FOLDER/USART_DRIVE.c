#include <avr/io.h> 
#include <avr/interrupt.h>
#include "USART_DRIVE.h"
#define BUFFER_SIZE 64   

void SETUP_RECEIVER_AND_SENDER() {
    
    if ((UCSR0B & (1 << TXEN0)) && (UCSR0B & (1 << RXEN0))) {
        return;
    }

    UCSR0B |= (1 << TXEN0) | (1 << RXEN0);
    UCSR0B |= (1 << RXCIE0);  

}

volatile char TX_BUFFER[BUFFER_SIZE]; 
volatile char RX_BUFFER[BUFFER_SIZE]; 

volatile uint8_t TX_index_in = 0; 
volatile uint8_t TX_index_out = 0;

volatile uint8_t RX_index_in = 0; 
volatile uint8_t RX_index_out = 0; 


ISR(USART_RX_vect) {
    char SERIAL_MESSAGE = UDR0; 
    RX_BUFFER[RX_index_in] = SERIAL_MESSAGE;
    RX_index_in = (RX_index_in + 1) % BUFFER_SIZE;
}
 
ISR(USART_UDRE_vect) {
    if (TX_index_in != TX_index_out) {
        UDR0 = TX_BUFFER[TX_index_out]; 
        TX_index_out = (TX_index_out + 1) % BUFFER_SIZE; 
    } else {
        UCSR0B &= ~(1 << UDRIE0);
    }
}

char USART_READ() {

    if (RX_index_in == RX_index_out) {
        return 0; 
    }

    
    char MESSAGE = RX_BUFFER[RX_index_out];
    ON_SERIAL_MESSAGE(MESSAGE); 
    RX_index_out = (RX_index_out + 1) % BUFFER_SIZE;  
    return MESSAGE; 

}

void USART_SEND(char MESSAGE) {
    TX_BUFFER[TX_index_in] = MESSAGE;
    TX_index_in = (TX_index_in + 1) % BUFFER_SIZE;
    UCSR0B |= (1 << UDRIE0); 
}

void USART_SEND_STRING(const char *MESSAGE) {
    while (*MESSAGE != '\0') {
        USART_SEND(*MESSAGE); 
        MESSAGE++;
    }
}

void USART_INIT() {
    int baud = 9600; 
    uint16_t UBRR_VAL = (F_CPU / (16UL * baud)) - 1;
    UBRR0 = UBRR_VAL;
    UCSR0C |= (1 << UCSZ00) | (1 << UCSZ01);
    SETUP_RECEIVER_AND_SENDER(); 
    sei();  
}