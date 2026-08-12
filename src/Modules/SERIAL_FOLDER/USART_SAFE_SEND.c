#include "USART_SAFE_SEND.h"
#define BUFFER_SIZE 12 

static char CURRENT_FAILED_MESSAGE = COMMUNICATION_NULL_RESULT; 
static uint16_t ATTEMPTS = 0; 

static char FAILED_MESSAGE_BUFFER[BUFFER_SIZE]; 

static uint8_t Index_In = 0; 
static uint8_t Index_Out = 0; 

void USART_SAFE_SEND(char FAILED_MESSAGE) {
    
    if (CURRENT_FAILED_MESSAGE == COMMUNICATION_NULL_RESULT) {
        CURRENT_FAILED_MESSAGE = FAILED_MESSAGE;
        USART_SEND(CURRENT_FAILED_MESSAGE);
        ATTEMPTS = 1;   
    }

}

void USART_SEND_STRING_WRAPPER(char *MESSAGE) {
    USART_SEND(MESSAGE[0]); 
}

void USART_SEND_LETTER_WRAPPER(char *MESSAGE) {
    USART_SEND_STRING(MESSAGE); 
}

static const USART_SENDERS MAPPED_WRAPPERS[] = {
    USART_SEND_LETTER_WRAPPER, 
    USART_SEND_STRING_WRAPPER 
}; 

void MANAGE_RETRIES(void) {

    static uint8_t IS_BUSY = 0; 
    
    if (CURRENT_FAILED_MESSAGE == COMMUNICATION_NULL_RESULT) {
        return; 
    }

    char RESULT = COMMUNICATION_RESULT(); 

    if (Index_Out == Index_In) {
        return; 
    }

    if (IS_BUSY) {
        FAILED_MESSAGE_BUFFER[Index_Out] = CURRENT_FAILED_MESSAGE; 
        Index_Out = (Index_Out + 1) % BUFFER_SIZE;       
    } 
    
    else {
        CURRENT_FAILED_MESSAGE = FAILED_MESSAGE_BUFFER[Index_In];
        Index_In = (Index_In + 1) % BUFFER_SIZE;  
    }

    if (RESULT == COMMUNICATION_ERROR) {
        USART_SEND(CURRENT_FAILED_MESSAGE);
        IS_BUSY = 1;  
        ATTEMPTS++;
    } 

    else {
        ATTEMPTS = 0; 
        CURRENT_FAILED_MESSAGE = COMMUNICATION_NULL_RESULT; 
        return;  
    }


}

USART_SENDERS DEFINE_CHOSEN_SEND(CHOSEN_SEND_FUNCTION) {
    return CHOSEN_SEND_FUNCTION; 
} 