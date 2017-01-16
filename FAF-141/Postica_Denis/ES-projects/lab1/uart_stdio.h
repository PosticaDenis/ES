#ifndef _UART_STDIO_H_
#define _UART_STDIO_H
	
#include <stdio.h>
#include <stdint.h>
#include <stdio.h>
#include <avr/io.h>
	
	void uart_stdio_Init(void);
	int uart_stdio_PutChar(char c, FILE *stream);

#endif
