#include "uart.h"

FILE uart_output = FDEV_SETUP_STREAM(UART_write, NULL, _FDEV_SETUP_WRITE);
FILE uart_input = FDEV_SETUP_STREAM(NULL, UART_read, _FDEV_SETUP_READ);

void UART_init(void)
{
	stdout = &uart_output;
	stdin = &uart_input;

	#if F_CPU < 2000000UL && defined(U2X)
	  UCSRA = _BV(U2X);             /* improve baud rate error by using 2x clk */
	  UBRRL = (F_CPU / (8UL * UART_BAUD)) - 1;
	#else
	  UBRRL = (F_CPU / (16UL * UART_BAUD)) - 1;
	#endif
	  UCSRB = _BV(TXEN) | _BV(RXEN); /* tx/rx enable */
}

int UART_write(char c, FILE *stream)
{
	if (c == '\n')
		UART_write('\r', stream);
	
	while (~UCSRA & (1 << UDRE));
	UDR = c;


	return 0;
}

char UART_read()
{
   //Wait untill a data is available
   while(!(UCSRA & (1<<RXC)))
   {
      //Do nothing
   }

   //Now USART has got data from host
   //and is available is buffer

   return UDR;
}

