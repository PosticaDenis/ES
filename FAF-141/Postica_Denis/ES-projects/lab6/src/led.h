#ifndef LED_H_
#define LED_H_
#include <avr/io.h>

char PORT[8];

void ledInit();
void ledGoLeft(char leftArrow[]);
void ledGoRight(char rightArrow[]);

#endif /* LED_H_ */
