
#include "ADC.h"

void ADC_init()
{		
	///Begin ADCSRA
	ADCSRA =
		(1 << ADEN) | // ADC Enable
		(0 << ADSC) | // ADC Start Conversion
		(1 << ADATE)| // ADC Auto Trigger Enable
		(1 << ADIE) | // ADC Interrupt Enable
		
		// division factor set to 32
		(1 << ADPS2)|
		(0 << ADPS1)|
		(1 << ADPS0);
		///End ADCSRA
		
	///Begin ADMUX
	ADMUX =
		// AREF, Internal Vref turned off.
		(0 << REFS0) |
		(0 << REFS1) |

		// Set right adjusting.
		(0 << ADLAR) |
		
		// Get input from ADC4.
		(0 << MUX4)  |
		(0 << MUX3)  |
		(1 << MUX2)  |
		(0 << MUX1)  |
		(0 << MUX0)  ;
		///End ADMUX
		
	///Begin SFIOR
	SFIOR =
		// Set timer0 overflow interrupt.
		(1 << ADTS2) |
		(0 << ADTS1) |
		(0 << ADTS0) ;
	///End SFIOR
}