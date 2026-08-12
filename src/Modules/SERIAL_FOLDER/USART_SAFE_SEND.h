#pragma once 
#include "stdint.h" 
#include "avr/io.h"
#include "USART_TASK.h"
#include "Modules/GLOBAL/GLOBAL_TYPES.h"
 
/*
Purpose: this will be a moduule that will take care of retrying to send again the failed USART message incase of fails 
*/


void USART_SAFE_SEND(char FAILED_MESSAGE); 
void MANAGE_RETRIES(void); 
USART_SENDERS DEFINE_CHOSEN_SEND(CHOSEN_SEND_FUNCTION); 
void USART_SEND_STRING_WRAPPER(char *MESSAGE);
void USART_SEND_LETTER_WRAPPER(char *MESSAGE);