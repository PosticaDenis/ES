#include "uart_stdio.h"
#include <avr/delay.h>

int count = 0;

void main(void) {
	uart_stdio_Init();

	while(1) {
		_delay_ms(1000);      /* pauses program for 1 second */
		count = count + 1;    /* increases the value of the counter */
		printf("%d\n", count);/* prints the value of the counter */
	}
	
	
}
