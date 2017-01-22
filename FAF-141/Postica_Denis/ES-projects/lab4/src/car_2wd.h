#ifndef CAR_2WD_H
#define CAR_2WD_H
#include "motor.h"

typedef struct Car {
	Motor *leftMotor;
	Motor *rightMotor;
} Car;

Car* CAR_create(Motor *leftMotor,Motor *rightMotor);

void CAR_start(Car *descriptor);

void CAR_stop(Car *descriptor);

void CAR_left(Car *descriptor);

void CAR_right(Car *descriptor);

void CAR_forward(Car *descriptor);

void CAR_backward(Car *descriptor);

void CAR_brake(Car *descriptor);

void CAR_calibrate_speed(Car *descriptor,uint8_t increment);

#endif
