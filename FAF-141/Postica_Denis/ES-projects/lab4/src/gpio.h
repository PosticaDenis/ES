#ifndef GPIO_H
#define GPIO_H
#include "stdint.h"

typedef struct GPIO {
	uint8_t volatile *ddr;
	uint8_t volatile *port;
	uint8_t volatile *pin;
	uint8_t id;
} GPIO;

typedef enum GPIO_Mode {
	GPIO_MODE_OUTPUT,
	GPIO_MODE_INPUT
} GPIO_Mode;

typedef enum GPIO_Value {
	GPIO_LOW,
	GPIO_HIGH = 1
} GPIO_Value;

GPIO* GPIO_create(uint8_t volatile *ddr,uint8_t volatile *port,uint8_t volatile *pin,uint8_t id);

void GPIO_set_mode(GPIO *descriptor,GPIO_Mode mode);

void GPIO_write(GPIO *descriptor,GPIO_Value value);

GPIO_Value GPIO_read(GPIO *descriptor);

#endif
