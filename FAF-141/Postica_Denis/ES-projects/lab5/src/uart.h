#ifndef _UART_H
#define _UART_H

#define UART_BAUD 9600
#define F_CPU 1000000UL

#include <stdio.h>
#include <avr/io.h>

void UART_init(void);
int	UART_write(char c, FILE *stream);
char UART_read();

#endif
