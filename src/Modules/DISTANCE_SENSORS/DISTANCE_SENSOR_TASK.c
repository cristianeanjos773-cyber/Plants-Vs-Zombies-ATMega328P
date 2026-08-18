#include "DISTANCE_SENSOR_TASK.h"

void DISTANCE_SENSOR_TASK(void) {
    uint8_t DISTANCE_CM = DISTANCE_SENSOR_MEASURE_CM();
    TURN_ON_TIMER1_REGISTERS();  
    USART_SAFE_SEND(&DISTANCE_CM, ); 
}

uint8_t DISTANCE_SENSOR_MEASURE_CM(void) {

    static uint8_t CURRENT_STATE = TRIGGER_ACTIVATED; 
    static uint16_t START_TIME = 0; 

    switch(CURRENT_STATE) {

        case TRIGGER_ACTIVATED: 
            PutElectricity(&PORTB, PB2);
            PutElectricity(&PORTD, PD2); 
            RemoveElectricity(&PORTB, PB1);
            START_TIME = TCNT1;  
            CURRENT_STATE = ECHO_ACTIVATED;
            return 0;
        break; 
        
        case ECHO_ACTIVATED:

            if (PINB & (1 << PB2)) {
                return 0; 
            }
            
            
            CURRENT_STATE = TRIGGER_ACTIVATED; 
            PutElectricity(&PORTB, PB1); 
            RemoveElectricity(&PORTD, PB2); 
            
            uint16_t END_TIME = TCNT2; 
            uint16_t ELAPSED_TIME =  END_TIME - START_TIME; 
            
            uint8_t DISTANCE_CM = (uint32_t) ELAPSED_TIME / 58;

            return DISTANCE_CM; 

        break;

    }

    return 0; 

}