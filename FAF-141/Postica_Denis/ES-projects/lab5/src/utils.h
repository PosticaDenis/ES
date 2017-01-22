#ifndef UTILS_H
#define UTILS_H
#include <stdint.h>

void bit_set_1(volatile uint8_t *ref,uint8_t bit);

void bit_set_0(volatile uint8_t *ref,uint8_t bit);

int8_t bit_is_1(volatile uint8_t *ref,uint8_t bit);

int8_t bit_is_0(volatile uint8_t *ref,uint8_t bit);

void bit_toggle(volatile uint8_t *ref,uint8_t bit);

#endif
