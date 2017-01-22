#include "button.h"
#include "utils.h"
#include <stdlib.h>

Button* BUTTON_create(GPIO *connection){
	Button *button = malloc(sizeof(Button));
	button->connection = connection;
	BUTTON_init(button);

	return button;
}

void BUTTON_init(Button *device){
	GPIO_set_mode(device->connection, GPIO_MODE_INPUT);
}

char BUTTON_pressed(Button *device){
	return !GPIO_read(device->connection);
}
