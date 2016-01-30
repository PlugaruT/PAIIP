#include <avr/io.h>
#include "pwm.h"

void PWM_init()
{
	// We'll use pin OC1B
	// Setting timer 1.
	
	// Non-inverting mode
	//Set OC1A/OC1B on compare match (Set output to high level)
	// TCCR1A = (1 << COM1B1) | (0 << COM1B0);

	
	// // Fast PWM, 10-bit
	
	// // Prescaling 64
	// // it doesn't really matter but 64 is good
	// // because it's easier to see on the oscilloscope
	// // and the motor seems to work better	
	// // Set OC1B pin as output
	TCCR1A = (1 << COM1B1)  | (0 << COM1B0) | (1 << WGM11) | (1 << WGM10); // mode of the generation (positive or negtive) and resolution
	TCCR1B = (0 << CS12)	| (1 << CS11) 	| (1 << CS10) | (0 << WGM13) | (1 << WGM12); // speed progression of timer
	DDRD  |= (1 << 4); // PIN4 is for output
	
}

void PWM_set (unsigned int val)
{
	if (val > PWM_IT_TOP)
	val = PWM_IT_TOP;
	
	OCR1B = val;
}
