#include "led.h"
#include "uart_studio.h"
#include "button.h"
#include <avr/delay.h>


int main() {
	
	init();
	initLed();
	
	while(1) {
		if(isPressed()) {
			ledOn();
		} else {
			ledOff();
		}			
	}
	
	
	return 0;
}
