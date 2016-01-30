#ifndef TIMER_H_
#define TIMER_H_

#include <avr/io.h>

void timer_init ()
{
	// Set timer0 with 1024 prescaler .
	TCCR0 = (1 << CS02 )|(0 << CS01 )|(1 << CS00 ) ;
	// Enable overflow interrupt .
	TIMSK |= 1 << TOIE0;
	// Set counter to 0.
	TCNT0 = 0;
}

#endif