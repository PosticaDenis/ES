#include "timer.h"
  
// TIMER0 overflow interrupt service routine
// called whenever TCNT0 overflows
ISR(TIMER0_OVF_vect)
{
    // keep a track of number of overflows
    tot_overflow++;
}
  
int main(void)
{
    // connect led to pin PC0
    DDRA |= (1 << 0);
  
    // initialize timer
     timer0_init();
  
    // loop forever
    while(1)
    {
        // check if no. of overflows = 12
        if (tot_overflow >= 12)  // NOTE: '>=' is used
        {
            // check if the timer count reaches 53
            if (TCNT0 >= 53)
            {
                PORTA ^= (1 << PINA0);    // toggles the led
                TCNT0 = 0;            // reset counter
                tot_overflow = 0;     // reset overflow counter
            }
        }
    }
}
