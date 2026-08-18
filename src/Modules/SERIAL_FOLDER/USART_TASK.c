#include "USART_TASK.h"

static char Result = COMMUNICATION_NULL_RESULT; 

void USART_TASK(void) {
    COMMUNICATION_RESULT(); 
    COMMUNICATION_ERROR_HANDLER(); 
    MANAGE_RETRIES(); 
}

void COMMUNICATION_ERROR_HANDLER(void) {
    
    if (Result == COMMUNICATION_ERROR) { 
        USART_SEND(Result); // the function USART_TASK() is ran by the task scheduler each 200 ms, so it will call this function if the condition is met 
        Result = COMMUNICATION_NULL_RESULT;     
    }

}

char COMMUNICATION_RESULT(void) {

    char RECEIVED_CHAR = USART_READ(); 

    if (!RECEIVED_CHAR ||  RECEIVED_CHAR == COMMUNICATION_NULL_RESULT) {
        return Result; 
    }

    switch (RECEIVED_CHAR) { 
        
        case COMMUNICATION_SUCCESS:
            PutElectricity(&PORTD, PD3); 
            Result = COMMUNICATION_SUCCESS; 
            return COMMUNICATION_SUCCESS;     
        
        case COMMUNICATION_ERROR: 
            Result = COMMUNICATION_ERROR; 
            return COMMUNICATION_ERROR; 
    
    default:
        Result = 'N';
        return COMMUNICATION_NULL_RESULT;  
    }

}

// this function is here so other archives can read it without needing to make the Result variable non static 
char GET_RESULT() { 
    return Result;
}