#include "USART_TASK.h"

#define COMMUNICATION_SUCCESS 'S'
#define COMMUNICATION_ERROR 'E'
#define COMMUNICATION_NULL_RESULT 'N'

static char Result = COMMUNICATION_NULL_RESULT; 

void USART_TASK(void) {
    COMMUNICATION_RESULT(); 
    COMMUNICATION_ERROR_HANDLER(); 
}



void COMMUNICATION_ERROR_HANDLER(void) {
    
    if (Result == COMMUNICATION_ERROR) { 
        USART_SEND(Result); // the function USART_TASK() is ran by the task scheduler each 200 ms, so it will call this function if the condition is met 
        Result = COMMUNICATION_NULL_RESULT; 
    }

}

char COMMUNICATION_RESULT(void) {

    Result = USART_READ(); 

    switch (Result) { 
        
        case COMMUNICATION_SUCCESS:
            return COMMUNICATION_SUCCESS;     
        
        case COMMUNICATION_ERROR: 
            return COMMUNICATION_ERROR; 
        
        case COMMUNICATION_NULL_RESULT:
            return COMMUNICATION_NULL_RESULT; 

    
    default:
        Result = 'N';
        return COMMUNICATION_NULL_RESULT;  
    }

}