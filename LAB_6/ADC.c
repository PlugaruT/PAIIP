#include "ADC.h"
#include "utils.h"

void ADC_init()
{
	ADCSRA =	
		(1 << ADEN) | // ADC enable
		(1 << ADSC) | // ADC Start Conversion
		(0 << ADATE)| // ADC Auto Trigger Enable
		(0 << ADIE) | // ADC Interrupt Enable
		
		// division factor set to 32
		(1 << ADPS0)|
		(0 << ADPS1)|
		(1 << ADPS2);
		
		
	ADMUX =
		// AREF, Internal Vref turned off
		(0 << REFS0)|
		(0 << REFS1)|

		(0 << ADLAR); // Set right adjusting
}

int ADC_getData(uchar channel)
{
	// set first 3 bits of admux to the first 3 bits from channel
	ADMUX = (ADMUX & 0b11111000) | (channel & 0b00000111);

	// start conversion
	ADCSRA |= M(ADSC);

	// wait for conversion to finish
	while (AT(ADCSRA, ADSC))
		;

	// get data from adc
	int data = ADC;

	return data;
}

