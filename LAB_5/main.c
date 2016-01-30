#define F_CPU 8000000ul
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "L293.h"
#include "ADC.h"
#include "timer0.h"

///Begin ISRs
ISR(ADC_vect)
{
	int adcData = (ADC * 2) - 1024;
	
	// Generally it's to check exact equality to 0
	// but in this case there is no problem
	if (adcData == 0) {
		L293_stop();
	}
	else if (adcData < 0) {
		L293_antiClockwise();
		L293_setPow(-adcData);
	}
	else {
		L293_clockwise();
		L293_setPow(adcData);
	}
}

ISR(TIMER0_OVF_vect)
{}


int main(void)
{
	L293_init();
	timer0_init();
	ADC_init();	
	sei();
	
    while(1)
		;
}