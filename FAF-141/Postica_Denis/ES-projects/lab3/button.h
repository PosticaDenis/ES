/*
 * button.h
 *
 * Created: 10/4/2016 11:39:16 PM
 *  Author: schid
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include <avr/io.h>

void initButtonOne();
void initButtonTwo();
int isButtonOnePressed();
int isButtonTwoPressed();




#endif /* BUTTON_H_ */