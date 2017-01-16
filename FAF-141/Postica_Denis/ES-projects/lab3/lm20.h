/*
 * lm20.h
 *
 * Created: 10/4/2016 11:39:29 PM
 *  Author: schid
 */ 

#ifndef LM20_H_
#define LM20_H_

#include "adc.h"

void initLM();
int getTemp();
int convertCelsiusToKelvin(int temp);



#endif /* LM20_H_ */