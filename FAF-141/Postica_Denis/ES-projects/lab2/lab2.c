#include "led.h"
#include "uart_studio.h"
#include "button.h"
#include <avr/delay.h>


int main() {
	
	init();
	initLed();
	
	while(1) {
		_delay_ms(100);
		if(DDRC == 00000000) {
			ledOn();
			_delay_ms(5000);
			DDRC = (1<<DDC5);
		} else {
			ledOff();
		}			
	}
	
	
	return 0;
}
