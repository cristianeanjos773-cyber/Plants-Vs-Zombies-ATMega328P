#pragma once 
#include "stdint.h" 
#include "avr/io.h"
#include "USART_TASK.h"
#include "Modules/GLOBAL/GLOBAL_TYPES.h"
 
/*
Purpose: this will be a moduule that will take care of retrying to send again the failed USART message incase of fails 
*/

#define LETTER_MODE 0 
#define STRING_MODE 1 
#define MAX_ATTEMPTS 5 

void USART_SAFE_SEND(const char *message, uint8_t mode); 
void MANAGE_RETRIES(void); 
USART_SENDERS DEFINE_CHOSEN_SEND(uint8_t USART_SEND_MODE); 
void ENQUEUE_MESSAGE(char MESSAGE_TO_ENQUEUE); 
void DEQUEUE_MESSAGE(void); 
void USART_SEND_STRING_WRAPPER(char *MESSAGE);
void USART_SEND_LETTER_WRAPPER(const char *MESSAGE);
