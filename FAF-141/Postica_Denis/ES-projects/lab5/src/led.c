#include "led.h"
#include <stdlib.h>

Led* LED_create(GPIO *connection){
	Led *led = malloc(sizeof(Led));
	led->connection = connection;
	LED_init(led);

	return led;
}

void LED_init(Led *device){
	GPIO_set_mode(device->connection, GPIO_MODE_OUTPUT);
}

void LED_on(Led *device){
	GPIO_write(device->connection, GPIO_HIGH);
}

void LED_off(Led *device){
	GPIO_write(device->connection, GPIO_LOW);
}
