#include <avr/io.h> 
#include <avr/interrupt.h>
#include "USART_DRIVE.h"
#include "ON_SERIAL_MESSAGE.h"
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

volatile uint8_t TXHead = 0; 
volatile uint8_t TXTail = 0;

volatile uint8_t RXHead = 0; 
volatile uint8_t RXTail = 0; 


ISR(USART_RX_vect) {
    char SERIAL_MESSAGE = UDR0; 
    RX_BUFFER[RXHead] = SERIAL_MESSAGE;
    RXHead = (RXHead + 1) % BUFFER_SIZE;
}

ISR(USART_UDRE_vect) {
    if (TXHead != TXTail) {
        UDR0 = TX_BUFFER[TXTail]; 
        TXTail = (TXTail + 1) % BUFFER_SIZE; 
    } else {
        UCSR0B &= ~(1 << UDRIE0);
    }
}

char USART_READ() {
    
    if (RXHead == RXTail) {
        return 0; 
    }

    char MESSAGE = RX_BUFFER[RXTail];
    RXTail = (RXTail + 1) % BUFFER_SIZE;  
    ON_SERIAL_MESSAGE(MESSAGE); 
    return MESSAGE; 

}

void USART_SEND(char MESSAGE) {
    
    if (UCSR0A & (1 << UDRE0)) {
        UDR0 = MESSAGE;
        return;
    }
    
    TX_BUFFER[TXHead] = MESSAGE;
    TXHead = (TXHead + 1) % BUFFER_SIZE;
    UCSR0B |= (1 << UDRIE0); 

}

void USART_INIT() {
    int baud = 9600; 
    uint16_t UBRR_VAL = (F_CPU / (16UL * baud)) - 1;
    UBRR0 = UBRR_VAL;
    UCSR0C |= (1 << UCSZ00) | (1 << UCSZ01);
    SETUP_RECEIVER_AND_SENDER(); 
    sei();  
}