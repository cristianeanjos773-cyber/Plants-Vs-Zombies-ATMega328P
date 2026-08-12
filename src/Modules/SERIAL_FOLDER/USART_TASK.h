#pragma once 
#include "stdint.h"
#include "avr/io.h"
#include "USART_DRIVE.h"

void USART_TASK(void); 
char COMMUNICATION_RESULT();
void USART_TASK_INIT(); 
void COMMUNICATION_ERROR_HANDLER(void); 