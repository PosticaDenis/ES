#include "drivers/car_2wd.h"
#include <stdlib.h>

Car* CAR_create(Motor *leftMotor,Motor *rightMotor){
	Car *descriptor = malloc(sizeof(Car));
	descriptor->leftMotor = leftMotor;
	descriptor->rightMotor = rightMotor;

	return descriptor;
}

void CAR_start(Car *descriptor){
	MOTOR_start(descriptor->leftMotor);
	MOTOR_start(descriptor->rightMotor);
}

void CAR_stop(Car *descriptor){
	MOTOR_stop(descriptor->leftMotor);
	MOTOR_stop(descriptor->rightMotor);
}

void CAR_left(Car *descriptor){
	MOTOR_set_speed(descriptor->leftMotor,descriptor->leftMotor->speed-1);
	MOTOR_set_speed(descriptor->rightMotor,descriptor->rightMotor->speed+1);
}

void CAR_right(Car *descriptor){
	MOTOR_set_speed(descriptor->rightMotor,descriptor->rightMotor->speed-1);
	MOTOR_set_speed(descriptor->leftMotor,descriptor->leftMotor->speed+1);
}

void CAR_forward(Car *descriptor){
	CAR_calibrate_speed(descriptor,1);
	MOTOR_set_direction(descriptor->leftMotor,MOTOR_DIRECTION_RIGHT);
	MOTOR_set_direction(descriptor->rightMotor,MOTOR_DIRECTION_RIGHT);
}

void CAR_backward(Car *descriptor){
	CAR_calibrate_speed(descriptor,1);
	MOTOR_set_direction(descriptor->leftMotor,MOTOR_DIRECTION_LEFT);
	MOTOR_set_direction(descriptor->rightMotor,MOTOR_DIRECTION_LEFT);
}

void CAR_brake(Car *descriptor){
	MOTOR_brake(descriptor->leftMotor);
	MOTOR_brake(descriptor->rightMotor);
}

void CAR_calibrate_speed(Car *descriptor,uint8_t increment){
	int new_speed = (descriptor->leftMotor->speed + descriptor->rightMotor->speed) / 2 + increment;
	MOTOR_set_speed(descriptor->leftMotor,new_speed);
	MOTOR_set_speed(descriptor->rightMotor,new_speed);
}
