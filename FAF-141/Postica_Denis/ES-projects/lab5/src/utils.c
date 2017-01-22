#include "utils.h"

void bit_set_1(volatile uint8_t *ref,uint8_t bit){
	*ref |= 1 << bit;
}

void bit_set_0(volatile uint8_t *ref,uint8_t bit){
	*ref = ~((~(*ref)) | (1 << bit));
}

int8_t bit_is_1(volatile uint8_t *ref,uint8_t bit){
	return (*ref) & (1 << bit);
}

int8_t bit_is_0(volatile uint8_t *ref,uint8_t bit){
	return (~(*ref)) & (1 << bit);
}

void bit_toggle(volatile uint8_t *ref,uint8_t bit){
	*ref ^= (1 << bit);
}
