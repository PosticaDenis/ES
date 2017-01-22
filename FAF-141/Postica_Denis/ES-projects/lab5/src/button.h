#ifndef BUTTON_H_
#define BUTTON_H_
#include <avr/io.h>
#include "gpio.h"

typedef struct Button {
	GPIO *connection;
} Button;

Button* BUTTON_create(GPIO *connection);
void BUTTON_init(Button *device);
char BUTTON_pressed(Button *device);

#endif /* BUTTON_H_ */
