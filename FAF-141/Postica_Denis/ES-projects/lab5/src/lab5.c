#include "task.h"
#include "task_scheduler.h"
#include "utils.h"
#include <avr/io.h>
#include "uart.h"
#include "button.h"
#include "led.h"

int val = 0;

Task toggleRedLedTask;
Task toggleBlueLedTask;
Task checkButtonTask;
Button *button;
Led *redLed;
Led *blueLed;

void toggle_red_led(){
	bit_toggle(redLed->connection->port,redLed->connection->id);
}

void toggle_blue_led(){
	bit_toggle(blueLed->connection->port,blueLed->connection->id);
}

void check_button(){
	if(BUTTON_pressed(button)){
		toggleRedLedTask.enabled = 1;
		toggleBlueLedTask.enabled = 0;
		printf("Button pressed\n");
	} else {
		toggleRedLedTask.enabled = 0;
		toggleBlueLedTask.enabled = 1;
		printf("Button released\n");
	}
}

void init(){
	toggleRedLedTask.delay = 0;
	toggleRedLedTask.enabled = 1;
	toggleRedLedTask.interval = 300;
	toggleRedLedTask.handler = &toggle_red_led;

	toggleBlueLedTask.delay = 0;
	toggleBlueLedTask.enabled = 1;
	toggleBlueLedTask.interval = 600;
	toggleBlueLedTask.handler = &toggle_blue_led;

	checkButtonTask.delay = 0;
	checkButtonTask.enabled = 1;
	checkButtonTask.interval = 50;
	checkButtonTask.handler = &check_button;

	button = BUTTON_create(GPIO_create(&DDRB, &PORTB, &PINB, 0));
	redLed = LED_create(GPIO_create(&DDRB, &PORTB, &PINB, 3));
	blueLed = LED_create(GPIO_create(&DDRB, &PORTB, &PINB, 7));
}

int main(){
	UART_init();
	init();
	TASK_SCHEDULER_start();

	TASK_SCHEDULER_add(&toggleRedLedTask);
	TASK_SCHEDULER_add(&checkButtonTask);
	TASK_SCHEDULER_add(&toggleBlueLedTask);

	while(1){}

	return 0;
}
