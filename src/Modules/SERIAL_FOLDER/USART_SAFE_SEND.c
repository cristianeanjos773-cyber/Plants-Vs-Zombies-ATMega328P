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

    static uint8_t IS_BUSY = 0; 
    
    if (CURRENT_FAILED_MESSAGE == COMMUNICATION_NULL_RESULT) {
        return; 
    }

    char RESULT = COMMUNICATION_RESULT(); 

    if (IS_BUSY) {
        ENQUEUE_MESSAGE(CURRENT_FAILED_MESSAGE);    
    } 
        
    else {
       DEQUEUE_MESSAGE(); 
    }

    if (RESULT == COMMUNICATION_ERROR) { 
        CURRENT_FAILED_MESSAGE = FAILED_MESSAGE_BUFFER[Index_Out]; 
        EXECUTE_SEND(CURRENT_FAILED_MESSAGE, 0);
        IS_BUSY = 1;  
        ATTEMPTS++;
    } 

    else if (RESULT == COMMUNICATION_SUCCESS) {
        IS_BUSY = 0; 
        ATTEMPTS = 0; 
        CURRENT_FAILED_MESSAGE = COMMUNICATION_NULL_RESULT; 
        return;  
    }

}

USART_SENDERS DEFINE_CHOSEN_SEND(uint8_t USART_SEND_MODE) {
    
    if (USART_SEND_MODE > 1 ) {
        USART_SEND_MODE = 0; 
    }  

    return MAPPED_WRAPPERS[USART_SEND_MODE]; 

} 

void EXECUTE_SEND(char message, uint8_t mode) {
    USART_SENDERS WISHED_SEND_MODE = DEFINE_CHOSEN_SEND(mode);
    static char payload[2];

    payload[0] = message; 
    payload[1] = '\0' ;
    
    WISHED_SEND_MODE(payload);
}