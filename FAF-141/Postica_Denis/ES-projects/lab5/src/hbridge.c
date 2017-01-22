#include <drivers/hbridge.h>
#include "utils.h"
#include <stdlib.h>

HBridge* HBRIDGE_create(GPIO *en,GPIO *in1,GPIO *in2){
	HBridge *descriptor = malloc(sizeof(HBridge));
	descriptor->en = en;
	descriptor->in1 = in1;
	descriptor->in2 = in2;

	return descriptor;
}

void HBRIDGE_init(HBridge *descriptor){
	GPIO_set_mode(descriptor->en,GPIO_MODE_OUTPUT);
	GPIO_set_mode(descriptor->in1,GPIO_MODE_OUTPUT);
	GPIO_set_mode(descriptor->in2,GPIO_MODE_OUTPUT);
}

void HBRIDGE_enable(HBridge *descriptor){
	GPIO_write(descriptor->en,GPIO_HIGH);
}

void HBRIDGE_disable(HBridge *descriptor){
	GPIO_write(descriptor->en,GPIO_LOW);
}

void HBRIDGE_set_operation(HBridge *descriptor,HBridge_Operation operation){
	uint8_t in1 = 0;
	uint8_t in2 = 0;
	switch(operation){
	case HBRIDGE_OPERATION_LEFT:
		in1 = 1;
		break;
	case HBRIDGE_OPERATION_RIGHT:
		in2 = 1;
		break;
	case HBRIDGE_OPERATION_BREAK:
		in1 = 1;
		in2 = 1;
		break;
	}

	GPIO_write(descriptor->in1,in1 ? GPIO_HIGH : GPIO_LOW);
	GPIO_write(descriptor->in2,in2 ? GPIO_HIGH : GPIO_LOW);
}
