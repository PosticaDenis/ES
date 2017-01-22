#include "led.h"
#include "uart_studio.h"
#include "button.h"
#include <avr/delay.h>


int main() {
	
	init();
	initLed();
	
	while(1) {
		_delay_ms(100);
		if(isPressed()) {
			ledOn();
		} else {
			ledOff();
		}			
	}
	
	
	return 0;
}
