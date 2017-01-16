#include "button.h"


void initButtonOne() {
	DDRC &= ~(1 << PORTC0) ;
}

void initButtonTwo() {
	DDRC &= ~(1 << PORTC1) ;
}

int isButtonOnePressed() {
	return PINC & (1<<PORTC0);
}

int isButtonTwoPressed() {
	return PINC & (1<<PORTC1);
}
