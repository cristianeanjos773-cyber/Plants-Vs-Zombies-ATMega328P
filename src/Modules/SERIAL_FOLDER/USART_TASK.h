#pragma once 
#include "stdint.h"
#include "avr/io.h"
#include "USART_DRIVE.h"
#include "USART_SAFE_SEND.h"

#define COMMUNICATION_SUCCESS 'S'
#define COMMUNICATION_ERROR 'E'
#define COMMUNICATION_NULL_RESULT 'N'


void USART_TASK(void); 
char COMMUNICATION_RESULT(void);
void COMMUNICATION_ERROR_HANDLER(void); 
char GET_RESULT(); 