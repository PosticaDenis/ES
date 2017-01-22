#ifndef L293_H
#define L293_H

#include "gpio.h"

typedef struct HBridge {
	GPIO *en;
	GPIO *in1;
	GPIO *in2;
} HBridge;

typedef enum HBridge_Operation {
	HBRIDGE_OPERATION_LEFT,
	HBRIDGE_OPERATION_RIGHT,
	HBRIDGE_OPERATION_BREAK
} HBridge_Operation;

HBridge* HBRIDGE_create(GPIO *en,GPIO *in1,GPIO *in2);
void HBRIDGE_init(HBridge *descriptor);
void HBRIDGE_enable(HBridge *descriptor);
void HBRIDGE_disable(HBridge *descriptor);
void HBRIDGE_set_operation(HBridge *descriptor,HBridge_Operation operation);

#endif
