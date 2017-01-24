#include <util/delay.h>  //delay header
#include "led.h"

char PORT[8] = {1,2,4,8,16,32,64,128};

void ledInit(void) {

	DDRB = 0xFF; //PORTB as output
    DDRA = 0xFF; //PORTA as output
}

void ledGoLeft(char leftArrow[]) {

	for(int x=17;x>0;x--) // there are 142 values in the set of ALPHA to display 'CIRCUIT DIGEST', then shift them after each loop execution
        {
            for(int a=0;a<20;a++) //show each character 20 times before shifting a column
                {
                    
                    for (int i=0;i<8;i++)
                    {
                        PORTB = ~PORT[i];    //ground the PORTC pin
                        PORTA = leftArrow[i+x];  //power the PORTA 
                        _delay_ms(0.5);
                        PORTB = PORT[i];     //clear pin after 1msec
                    }
                    
                }
    	}

}

void ledGoRight(char rightArrow[]) {

	for(int x=0;x<18;x++) // there are 142 values in the set of ALPHA to display 'CIRCUIT DIGEST', then shift them after each loop execution
        {
            for(int a=0;a<20;a++) //show each character 20 times before shifting a column
                {
                    
                    for (int i=0;i<8;i++)
                    {
                        PORTB = ~PORT[i];    //ground the PORTC pin
                        PORTA = rightArrow[i+x];  //power the PORTA 
                        _delay_ms(0.5);
                        PORTB = PORT[i];     //clear pin after 1msec
                    }
                    
                }
    	}

}
