#include <avr/io.h>
#include "button.h"
#include "lm20.h"
#include "lcd.h"
#include <avr/delay.h>



int main(void) {
	
	initButtonOne();
	initButtonTwo();
	initLM();
	uart_stdio_Init();
	
	//Initialize LCD module
   LCDInit(LS_BLINK|LS_ULINE);

   //Clear the screen
   LCDClear();

	
    while(1) {
		_delay_ms(1000);
		
		if(isButtonOnePressed()) {
			if(isButtonTwoPressed()) {
				LCDClear();
				LCDWriteString("Fahrenheit:");
				LCDWriteIntXY(1, 1, convertCelsiusToFahrenheit(getTemp()),3);
				printf("Fahrenheit: %d\n", convertCelsiusToFahrenheit(getTemp()));
			}else {
				LCDClear();
				LCDWriteString("Kelvin:");
				LCDWriteIntXY(1, 1, convertCelsiusToKelvin(getTemp()),3);
				printf("Kelvin: %d\n", convertCelsiusToKelvin(getTemp()));
			}			
			
		} else {
			LCDClear();
			LCDWriteString("Celsius:");
			LCDWriteIntXY(1, 1, getTemp(),3);
			printf("Celsius : %d\n", getTemp());
		}						
    }
}
