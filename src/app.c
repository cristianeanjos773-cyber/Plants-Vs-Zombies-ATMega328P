#include "app.h"


void APP_SET_PINS() {
  
  SetPinAsInput(&DDRB, PB0);
  SetPinAsInput(&DDRB, PB2);
  SetPinAsOutput(&DDRB, PB1); 

  SetPinAsOutput(&DDRD, PD5);  
  SetPinAsOutput(&DDRD, PD4);

  SetPinAsOutput(&DDRD, PD2);
  SetPinAsOutput(&DDRD, PD6); 
  SetPinAsOutput(&DDRD, PD3); 
  
  PutElectricity(&PORTB, PB0);


}

void APP_INIT() {
  APP_SET_PINS(); 
  SCHEDULER_INIT();
  LIGHT_SENSOR_INIT();   
  USART_INIT(); 
  BUZZER_DEFINE_TASK(BUZZER_FAST_BIP, 0, BUZZER_MODE_BIP);
  BUZZER_DEFINE_TASK(BUZZER_FAST_BIP, 1, BUZZER_MODE_BIP); 
}

void APP_TASK() {
  SCHEDULER_RUN();
}