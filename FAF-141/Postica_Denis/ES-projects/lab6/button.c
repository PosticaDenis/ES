#include "button.h"

void init() {
	DDRC &= ~(1 << PORTC5) ;
}

int isPressed() {
	return PINC & (1<<PORTC5);
}
