#pragma once 
#define USART_DRIVE_H 
#define F_CPU 16000000UL
#include <avr/io.h> 
#include <avr/interrupt.h>
#include "ON_SERIAL_MESSAGE.h"

#define SINGLE_LETTER_MODE 0 
#define STRING_MODE 1 

void USART_INIT(); 
void SETUP_RECEIVER_AND_SENDER(); 
void USART_SEND(char MESSAGE); 
void USART_SEND_STRING(const char *MESSAGE); 
char USART_READ(); 