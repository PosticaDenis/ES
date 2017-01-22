//********************************************************
// ******** 4X4 MATRIX KEY-BOARD INTERFACING ***********
//********************************************************
//********************************************************

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

//****** LCD Functions declaration ******** //
void LCD_init(void);
void LCD_WriteCommand (unsigned char Command);
void LCD_WriteData (unsigned char Data);

void LCD_DisplayString (char row, char column, char *string);
void LCD_Cursor(char row, char column);

#define ENABLE_LCD     	        PORTD |= 0x80
#define DISABLE_LCD       	    PORTD &= ~0x80
#define SET_LCD_DATA      	    PORTD |= 0x20
#define SET_LCD_CMD       	    PORTD &= ~0x20
#define KB_PORT_OUT 			PORTB
#define KB_PORT_IN				PINB

//************************

void port_init(void)
{
 DDRA  = 0x00;
 PORTA = 0x00;
 DDRB  = 0x0f;		//Key-board port, higer nibble - input, lower nibble - output
 PORTB = 0xff;		//pull-up enabled for higher nibble
 DDRC  = 0xff;
 PORTC = 0x00; 
 DDRD  = 0xf0;
 PORTD = 0x00;
}


//call this routine to initialize all peripherals
void init_devices(void)
{
 port_init();
 LCD_init(); 
 
 MCUCR = 0x00;
 TIMSK = 0x00; //timer interrupt sources
 } 

//****************** MAIN FUNCTION *******************

 int main(void)
{
   unsigned char upperNibble, keyCode, keyPressed, i;
   init_devices();
   
   LCD_DisplayString (1,1,"   WELCOME    ");
   LCD_WriteCommand(0xc0);	   //moving LCD cursor to second row
   
   while(1)
   {
        upperNibble = 0xff;
		
		for(i=0; i<4; i++)
	    {
		 _delay_ms(1);
		 KB_PORT_OUT = ~(0x01 << i);
		 _delay_ms(1);  		  	 		  //delay for port o/p settling
		 upperNibble = KB_PORT_IN | 0x0f;
		 
		 if (upperNibble != 0xff)
		 {
		   _delay_ms(20); 		  		 //key debouncing delay
	       upperNibble = KB_PORT_IN | 0x0f;
		   if(upperNibble == 0xff) goto OUT;
		   
		   keyCode = (upperNibble & 0xf0) | (0x0f & ~(0x01 << i));
		   
		   while (upperNibble != 0xff)
		     upperNibble = KB_PORT_IN | 0x0f;
		   
		   _delay_ms(20);   			   //key debouncing delay
		   
		   switch (keyCode)			   //generating key characetr to display on LCD
		   {
		   	case (0xee): keyPressed = '0'; 
				 		 break;
			case (0xed): keyPressed = '1';
				 		 break;
			case (0xeb): keyPressed = '2'; 
			   			 break;
			case (0xe7): keyPressed = '3'; 
				 		 break;
			case (0xde): keyPressed = '4'; 
				 		 break;
			case (0xdd): keyPressed = '5'; 
				 		 break;
			case (0xdb): keyPressed = '6'; 
				 		 break;
			case (0xd7): keyPressed = '7'; 
				 		 break;
			case (0xbe): keyPressed = '8'; 
				 		 break;
			case (0xbd): keyPressed = '9'; 
				 		 break;
			case (0xbb): keyPressed = 'A'; 
				 		 break;
			case (0xb7): keyPressed = 'B'; 
				 		 break;
			case (0x7e): keyPressed = 'C'; 
				 		 break;
			case (0x7d): keyPressed = 'D'; 
				 		 break;
			case (0x7b): keyPressed = 'E'; 
				 		 break;
			case (0x77): keyPressed = 'F'; 
				 		 break;
			default	   : keyPressed = 'X';
			}//end of switch
			
			LCD_WriteData(keyPressed);	
			
		   OUT:;
		  }//end of if
		}//end of for
	}//end of while(1)	 
	
	return 0;    
}//end of main()


//***********************************************************************
//***********************   LCD Functions   ***************************** 
//***********************************************************************

// ********************************* 
// *** Initialize the LCD driver *** 
// ********************************* 
void LCD_init(void)
{
	_delay_ms(100); 					 // wait for 100ms
	
	//SET_LCD_WRITE ;					 // Set LCD in write mode
	
	LCD_WriteCommand (0x38);		 // 8 data lines
	LCD_WriteCommand (0x08);		 // display off
	LCD_WriteCommand (0x01);		 // clear LCD memory
	_delay_ms (10);	 				 // 10ms delay after clearing LCD
	LCD_WriteCommand (0x06);		 // cursor setting
	LCD_WriteCommand (0x0f);		 // display ON
}


// ********************************************** 
// *** Write a command instruction to the LCD *** 
// ********************************************** 
void LCD_WriteCommand (unsigned char Command)
{

	SET_LCD_CMD;				// Set LCD in command mode

	PORTC = Command;			// Load data to port

	ENABLE_LCD;	   				// Write data to LCD

	asm("nop");					
	asm("nop");
	
	DISABLE_LCD;	   			// Disable LCD 
	
	_delay_ms(1);				// wait for 1ms
}


// ***************************************** 
// *** Write one byte of data to the LCD *** 
// ***************************************** 
void LCD_WriteData (unsigned char Data)
{
	SET_LCD_DATA;					// Set LCD in data mode

	PORTC = Data;					// Load data to port

	ENABLE_LCD;	   				 	// Write data to LCD

	asm("nop");
	asm("nop");

	DISABLE_LCD;	   				 // Disable LCD
	
	_delay_ms(1);					 // wait for 1ms
}


// ********************************************************************* 
// *** Display a string at the specified row and column, from FLASH **** 
// ********************************************************************* 
void LCD_DisplayString (char row, char column, char *string)
{
	LCD_Cursor (row, column);
	while (*string)
		LCD_WriteData(*string++);
}


// *************************************************** 
// *** Position the LCD cursor at "row", "column". *** 
// *************************************************** 
void LCD_Cursor (char row, char column)
{
	switch (row) 
	{
		case 1: LCD_WriteCommand (0x80 + column - 1); break;
		case 2: LCD_WriteCommand (0xc0 + column - 1); break;
		default: break;
	}
}

//******** CC DHARMANI  *********  www.dharmanitech.com *********
