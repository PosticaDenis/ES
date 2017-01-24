#include <avr/io.h>
#include <avr/interrupt.h>
  
// global variable to count the number of overflows
volatile uint8_t tot_overflow;
  
// initialize timer, interrupt and variable
void timer0_init();
