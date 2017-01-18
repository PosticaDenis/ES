#ifndef LM20_H_
#define LM20_H_

#include "adc.h"

void initLM();
int getTemp();
int convertCelsiusToKelvin(int temp);



#endif /* LM20_H_ */
