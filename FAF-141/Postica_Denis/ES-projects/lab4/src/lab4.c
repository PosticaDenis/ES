#include <avr/io.h>
#include <avr/delay.h>
#include "hbridge.h"
#include "uart_stdio.h"
#include "pwm.h"
#include "gpio.h"
#include "motor.h"
#include "car_2wd.h"

Car *car;

void create(){

	HBridge *leftHBridge = HBRIDGE_create(
			GPIO_create(&DDRB,&PORTB,&PINB,3),
			GPIO_create(&DDRB,&PORTB,&PINB,2),
			GPIO_create(&DDRB,&PORTB,&PINB,1)
			);
	Motor *leftMotor = MOTOR_create(leftHBridge,&pwm_0_set);
	
	HBridge *rightHBridge = HBRIDGE_create(
			GPIO_create(&DDRD,&PORTD,&PIND,7),
			GPIO_create(&DDRD,&PORTD,&PIND,5),
			GPIO_create(&DDRD,&PORTD,&PIND,6)
			);
	Motor *rightMotor = MOTOR_create(rightHBridge,&pwm_2_set);

	car = CAR_create(leftMotor,rightMotor);
}

int main() {
	uart_stdio_Init();

	char key;
	create();

	while(1){
		printf("\nEnter command:");
		key = getchar();

		switch(key){
		case 'a' :
			CAR_left(car);
			break;
		case 'w':
			CAR_forward(car);
			break;
		case 'd':
			CAR_right(car);
			break;
		case 's':
			CAR_backward(car);
			break;
		case 'p':
			CAR_start(car);
			break;
		case 'l':
			CAR_stop(car);
			break;
		}
	}

	return 0;
}
