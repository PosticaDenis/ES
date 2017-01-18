#include "led.h"

void initLed() {
	DDRB |= (1 << PORTB1); /* sets value of DDRB to out */
}

void ledOn() {
	PORTB |= (1 << PORTB1); /* sets value 1 for PORTB1 */
}

void ledOff() {
	PORTB &= ~(1 << PORTB1);/* sets value 0 for PORTB1 */
}
