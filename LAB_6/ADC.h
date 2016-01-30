#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>
#include <avr/io.h>
#include <stdio.h>

#include "utils.h"


void ADC_init();
int ADC_getData(uchar channel);

#endif /* ADC_H_ */