#ifndef MOTOR_H
#define MOTOR_H
#include "hbridge.h"
#include <stdint.h>

typedef enum MOTOR_Direction {
	MOTOR_DIRECTION_LEFT,
	MOTOR_DIRECTION_RIGHT,
} Motor_Direction;

typedef struct Motor {
	HBridge *hbridge;
	uint8_t speed;
	void (*pwm)(uint8_t);
} Motor;

Motor* MOTOR_create(HBridge *descriptor,void (*pwm)(uint8_t));

void MOTOR_start(Motor *descriptor);

void MOTOR_stop(Motor *descriptor);

void MOTOR_set_direction(Motor *descriptor,Motor_Direction direction);

void MOTOR_set_speed(Motor *descriptor,uint8_t speed);

void MOTOR_reset_speed(Motor *descriptor);

void MOTOR_brake(Motor *descriptor);

#endif
