#include "button.h"
#include "led.h"

char rightArrow[]={
	0,0,0,0,0,0,0,0,
    0,0b00011000, 0b00111100, 0b01111110, 0b11111111, 0b00111100, 0b00111100, 0b00111100, 0b00111100,
	0,0,0,0,0,0,0,0

    };

char leftArrow[]={
	0,0,0,0,0,0,0,0,
    0,0b00111100, 0b00111100, 0b00111100, 0b00111100, 0b11111111, 0b01111110, 0b00111100, 0b00011000,
	0,0,0,0,0,0,0,0

    };

int main(void)
{
	ledInit();
	buttonInit();
    
    while(1)
    {
        if (buttonIsPressed()) {

        	ledGoRight(rightArrow); }
		
		else {

			ledGoLeft(leftArrow);	
		}         
    }
}
