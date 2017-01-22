#ifndef LED_H_
#define LED_H_
#include <avr/io.h>
#include "gpio.h"

typedef struct Led {
	GPIO *connection;
} Led;

Led* LED_create(GPIO *connection);
void LED_init(Led *device);
void LED_on(Led *device);
void LED_off(Led *device);

#endif /* LED_H_ */
