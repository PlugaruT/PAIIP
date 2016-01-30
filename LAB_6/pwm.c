#include <avr/io.h>
#include "utils.h"
#include "pwm.h"

void PWM_init()
{	
	// Setting timer 1.
	// Non-inverting mode
	SET_1(TCCR1A, COM1B1);
	SET_0(TCCR1A, COM1B0);
	
	// Fast PWM, 10-bit
	SET_0(TCCR1B, WGM13);
	SET_1(TCCR1B, WGM12);
	SET_1(TCCR1A, WGM11);
	SET_1(TCCR1A, WGM10);
		
	// Prescaling 64
	// it doesn't really matter but 64 is good
	// because it's easier to see on the oscilloscope
	// and the motor seems to work better
	SET_0(TCCR1B, CS12);
	SET_1(TCCR1B, CS11);
	SET_1(TCCR1B, CS10);
	
	// Set OC1B pin as output
	SET_1(DDRD, 4);
}

// From 0 to 1023
void PWM_set (unsigned int val)
{	
	if (val > PWM_IT_TOP)
		val = PWM_IT_TOP;
		
	OCR1B = val;	
}
