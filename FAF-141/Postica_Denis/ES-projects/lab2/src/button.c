#include "button.h"

void init() {
	DDRA &= ~(1 << PORTA0) ;   /* sets direction of DDRB to in (0).*/
}

int isPressed() {

	return PINA & (1<<PORTA0); /* returns the value of PORTA0*/
}
