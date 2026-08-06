#include <avr/io.h>
#include <util/delay.h>
#include "app.h"

int main(void) {
  
  APP_INIT(); 

  while (1) { 
    APP_TASK(); 
  }

  return 0; 

}   
