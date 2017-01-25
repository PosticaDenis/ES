#include "button.h"

void buttonInit() {
	DDRC &= ~(1 << PORTC0) ;   /* sets direction of DDRC to in (0).*/
}

int buttonIsPressed() {

	return PINC & (1<<PORTC0); /* returns the value of PORTC0*/
}
