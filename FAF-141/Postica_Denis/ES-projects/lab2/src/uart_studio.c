#include "uart_studio.h"
#define UART_BAUD 9600

FILE uart_output = FDEV_SETUP_STREAM(uart_stdio_PutChar, NULL, _FDEV_SETUP_WRITE);

int uart_stdio_PutChar(char c, FILE *stream) {

  if (c == '\a') {
      fputs("*ring*\n", stderr);
      return 0;
    }

  if (c == '\n')
    uart_stdio_PutChar('\r', stream);
  while(~UCSRA & (1 << UDRE));
  UDR = c;

  return 0;
}


void uart_stdio_Init(void) {
	#if F_CPU < 2000000UL && defined(U2X)
	  UCSRA = _BV(U2X);             /* improve baud rate error by using 2x clk */
	  UBRRL = (F_CPU / (8UL * UART_BAUD)) - 1;
	#else
	  UBRRL = (F_CPU / (16UL * UART_BAUD)) - 1;
	#endif
	  UCSRB = _BV(TXEN) | _BV(RXEN); /* tx/rx enable */

	  stdout = &uart_output;
}
