/*
 * lm20.c
 *
 * Created: 08.10.2015 09:04:16
 *  Author: Tudor
 */ 

#include "adc.h"
#include <avr/io.h>

void LM20_init()
{
	ADC_init();
}

int LM20_GetTemp()
{
	return ADC_GetData(3);
}

