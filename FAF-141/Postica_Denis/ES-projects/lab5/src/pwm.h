#ifndef PWM_H
#define PWM_H

#include <stdint.h>

/**
 * Sets first 8bit timer for PWM with phase
 */
void pwm_0_set(uint8_t time_on);

/**
 * Sets second 8bit timer for PWM with phase
 */
void pwm_2_set(uint8_t time_on);

#endif
