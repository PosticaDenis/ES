#ifndef _UART_STDIO_H
#define _UART_STDIO_H

#define UART_BAUD 9600
#define F_CPU 8000000UL

#include <stdio.h>
#include <avr/io.h>

void uart_stdio_Init(void);

int	uart_PutChar(char c, FILE *stream);
char uart_ReadChar();
#endif
