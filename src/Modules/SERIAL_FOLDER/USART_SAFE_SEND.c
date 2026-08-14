#include "USART_SAFE_SEND.h"
#define BUFFER_SIZE 12 

static char CURRENT_FAILED_MESSAGE = COMMUNICATION_NULL_RESULT; 
static uint16_t ATTEMPTS = 0; 

static char FAILED_MESSAGE_BUFFER[BUFFER_SIZE]; 

static uint8_t Index_In = 0; 
static uint8_t Index_Out = 0; 



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

void ENQUEUE_MESSAGE(char MESSAGE_TO_ENQUEUE) {
       
    uint8_t Next_Index_In = (Index_In + 1) % BUFFER_SIZE;  
    
    if (Next_Index_In == Index_Out) {
        return; 
    }

    FAILED_MESSAGE_BUFFER[Index_In] = MESSAGE_TO_ENQUEUE; 
    Index_In = Next_Index_In; 
    
}

void DEQUEUE_MESSAGE() {

    if (Index_Out == Index_In) {
        return; 
    }

    uint8_t Next_Index_Out = (Index_Out + 1) % BUFFER_SIZE; 

    CURRENT_FAILED_MESSAGE = FAILED_MESSAGE_BUFFER[Index_Out];
    Index_Out = Next_Index_Out; 

    return; 

} 

void MANAGE_RETRIES(void) {


    if (CURRENT_FAILED_MESSAGE == COMMUNICATION_NULL_RESULT) {
        DEQUEUE_MESSAGE(); 

        if (CURRENT_FAILED_MESSAGE == COMMUNICATION_NULL_RESULT) {
            return; 
        }

        ATTEMPTS = 1;
        USART_SAFE_SEND(CURRENT_FAILED_MESSAGE, LETTER_MODE);
    }

    char RESULT = COMMUNICATION_RESULT(); 

    if (RESULT == COMMUNICATION_SUCCESS) {
        ATTEMPTS = 0; 
        CURRENT_FAILED_MESSAGE = COMMUNICATION_NULL_RESULT; 
    }

    else if (RESULT == COMMUNICATION_ERROR) {
        
        ATTEMPTS++;

        if (ATTEMPTS > MAX_ATTEMPTS) {
            CURRENT_FAILED_MESSAGE = COMMUNICATION_NULL_RESULT;
            ATTEMPTS = 0; 
        } 
        
        else {
            USART_SAFE_SEND(CURRENT_FAILED_MESSAGE, LETTER_MODE);  
        }

    }

}

USART_SENDERS DEFINE_CHOSEN_SEND(uint8_t USART_SEND_MODE) {
    
    if (USART_SEND_MODE > 1 ) {
        USART_SEND_MODE = 0; 
    }  

    return MAPPED_WRAPPERS[USART_SEND_MODE]; 

} 

void USART_SAFE_SEND(const char *message, uint8_t mode) {
    USART_SENDERS WISHED_SEND_MODE = DEFINE_CHOSEN_SEND(mode);
    WISHED_SEND_MODE(message);
}