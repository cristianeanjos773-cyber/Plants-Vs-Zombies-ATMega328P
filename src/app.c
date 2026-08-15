#include "app.h"


void APP_SET_PINS() {
  SetPinAsInput(&DDRB, PB4); // THIS SHOULD BE A BUTTON 
  PutElectricity(&PORTB, PB4); 
  SetPinAsOutput(&DDRD, PD5); // THIS AND PD3 SHOULD BE LEDS 
  SetPinAsOutput(&DDRD, PD6); // THIS MUST BE A BUZZER 
  SetPinAsOutput(&DDRD, PD3);
}

void APP_INIT() {
  APP_SET_PINS(); 
  SCHEDULER_INIT();
  LIGHT_SENSOR_INIT();   
  USART_INIT(); 
}

void APP_TASK() {
  SCHEDULER_RUN();
}