#include "gpio.h"
#include <stdlib.h>
#include "utils.h"

GPIO* GPIO_create(uint8_t volatile *ddr,uint8_t volatile *port,uint8_t volatile *pin,uint8_t id){
	GPIO *descriptor = malloc(sizeof(GPIO));
	descriptor->ddr = ddr;
	descriptor->port = port;
	descriptor->pin = pin;
	descriptor->id = id;

	return descriptor;
}

void GPIO_set_mode(GPIO *descriptor,GPIO_Mode mode){
	switch(mode){
	case GPIO_MODE_INPUT:
		bit_set_0(descriptor->ddr,descriptor->id);
		bit_set_1(descriptor->port,descriptor->id);
		break;

	case GPIO_MODE_OUTPUT:
		bit_set_1(descriptor->ddr,descriptor->id);
		break;
	}
}

void GPIO_write(GPIO *descriptor,GPIO_Value value){
	if(value == GPIO_LOW){
		bit_set_0(descriptor->port,descriptor->id);
	} else {
		bit_set_1(descriptor->port,descriptor->id);
	}
}

GPIO_Value GPIO_read(GPIO *descriptor){
	uint8_t value = (*descriptor->pin) & (1 << descriptor->id);

	return value == 0 ? GPIO_LOW : GPIO_HIGH;
}
