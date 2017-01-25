#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "L293.h"
#include "button.h"



int main(void)
{
	L293_init();
	initButton1();
	initButton2();


	  while(1) {

		  if(button1Pressed() && button2Pressed()) {
			  stopMotor();
		  } 
		  
		  else if(button1Pressed()) {
			  motorLeft();
		  } 

		  else if(button2Pressed()) {
			  motorRight();
		  }

		  else {
		      freeMotor();
		  }

	  }
}
