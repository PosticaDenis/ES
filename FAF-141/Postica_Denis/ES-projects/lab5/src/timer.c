#include "timer.h"

// initialize timer, interrupt and variable
void timer0_init()
{
    // set up timer with prescaler = 256
    TCCR0 |= (1 << CS02);
  
    // initialize counter
    TCNT0 = 0;
  
    // enable overflow interrupt
    TIMSK |= (1 << TOIE0);
  
    // enable global interrupts
    sei();
  
    // initialize overflow counter variable
    tot_overflow = 0;
}
