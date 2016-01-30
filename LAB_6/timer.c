#include <avr/io.h>
#include "timer.h"
#include "utils.h"

///Begin timer.init
void timer_init()
{
	// Set timer0 with 1024 prescaler.
	TCCR0 =
		(1 << CS02) |
		(0 << CS01) |
		(1 << CS00) ;
	
	// Enable overflow interrupt.
	SET_1(TIMSK, TOIE0);
	
	// Set counter to 0.
	TCNT0 = 0;
}
///End timer.init
