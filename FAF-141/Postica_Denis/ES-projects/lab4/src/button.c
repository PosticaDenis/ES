#include "button.h"


void initButton1() {
	DDRC &= ~(1 << PORTC2) ;
}

void initButton2() {
	DDRC &= ~(1 << PORTC3) ;
}

int button1Pressed() {
	return PINC & (1<<PORTC2);
}

int button2Pressed() {
	return PINC & (1<<PORTC3);
}
