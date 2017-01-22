/*
 * pwm.c
 *
 *  Created on: Dec 25, 2016
 *      Author: Maxian Nicu
 */

#include <avr/io.h>
#include "drivers/pwm.h"
#include "utils.h"

void pwm_0_set(uint8_t time_on){
	// set timer0 for fast pwm
	bit_set_1(&TCCR0,WGM00);
	bit_set_1(&TCCR0,WGM01);

	// set clear on compare match and set on top
	bit_set_1(&TCCR0,COM01);

	// set prescaler 256
	bit_set_1(&TCCR0,CS02);

	bit_set_1(&DDRB,PB3);

	// set compare value
	OCR0 = time_on;

	// reset counter
	TCNT0 = 0;
}

void pwm_2_set(uint8_t time_on){

	// set timer2 for fast pwm
	bit_set_1(&TCCR2,WGM20);
	bit_set_1(&TCCR2,WGM21);

	// set clear on compare match and set on top
	bit_set_1(&TCCR2,COM21);

	// set prescaler 256
	bit_set_1(&TCCR2,CS21);
	bit_set_1(&TCCR2,CS22);

	bit_set_1(&DDRD,PD7);

	// set compare value
	OCR2 = time_on;

	// reset counter
	TCNT2 = 0;
}
