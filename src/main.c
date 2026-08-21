#include <avr/io.h>
#include <util/delay.h>
#include "app.h"

int main(void) {
  
  APP_INIT(); 

  while (1) { 
    PutElectricity(&PORTD, PD6); 
    RemoveElectricity(&PORTD, PD6);    
    APP_TASK(); 
  }

  return 0; 

}   
