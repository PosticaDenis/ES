#include <avr/io.h>

#include "L293.h"


void L293_init() {
	DDRC = 0b11111111;

}


void motorRight()
{
	PORTC = 0b00000010;
}

void motorLeft()
{
	 PORTC = 0b00000001;
}

void stopMotor()
{
	PORTC = 0b00000011;
}

void freeMotor()
{
	PORTC = 0b00000000;
}




