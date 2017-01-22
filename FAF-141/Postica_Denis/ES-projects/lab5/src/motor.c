#include "drivers/motor.h"
#include <stdlib.h>
#define MAX_PWM_VALUE 255

Motor* MOTOR_create(HBridge *hbridge,void (*pwm)(uint8_t)){
	Motor *descriptor = malloc(sizeof(Motor));
	descriptor->hbridge = hbridge;
	descriptor->speed = 0;
	descriptor->pwm = pwm;

	HBRIDGE_init(hbridge);

	return descriptor;
}

void MOTOR_start(Motor *descriptor){
	MOTOR_reset_speed(descriptor);
}

void MOTOR_stop(Motor *descriptor){
	descriptor->pwm(0);
}

void MOTOR_set_direction(Motor *descriptor,Motor_Direction direction){
	switch(direction){
	case MOTOR_DIRECTION_LEFT:
		HBRIDGE_set_operation(descriptor->hbridge,HBRIDGE_OPERATION_LEFT);
		break;
	case MOTOR_DIRECTION_RIGHT:
		HBRIDGE_set_operation(descriptor->hbridge,HBRIDGE_OPERATION_RIGHT);
		break;
	}
	MOTOR_reset_speed(descriptor);
}

void MOTOR_brake(Motor *descriptor){
	HBRIDGE_set_operation(descriptor->hbridge,HBRIDGE_OPERATION_BREAK);
	descriptor->pwm(MAX_PWM_VALUE);
}

void MOTOR_set_speed(Motor *descriptor,uint8_t speed){
	if(speed < 0)
		speed = 0;
	if(speed > 100)
		speed = 100;
	descriptor->speed = speed;
	MOTOR_reset_speed(descriptor);
}

void MOTOR_reset_speed(Motor *descriptor){
	uint8_t convertedSpeed = descriptor->speed*MAX_PWM_VALUE/100;
	descriptor->pwm(convertedSpeed);
}
