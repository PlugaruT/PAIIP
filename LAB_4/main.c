#include "serial.h"
#include "LM20.h"
#include <stdint.h>
#include <stdio.h>
#include "timer.h"
#include <avr/interrupt.h>
#include "lcd.h"

unsigned int count = 0;
unsigned int printOnEvery = 15;

ISR ( ADC_vect )
{
	count = ( count + 1) % printOnEvery ;
	if ( count == 0)
	LM20_printData ();
}

// Without defining ISR(TIMER0_OVF_vect), the ISR ( ADC_vect ) won't be able to work .
ISR ( TIMER0_OVF_vect ){}

int main ()
{
	serial_init(51) ;
	LM20_init();
	timer_init();
	lcd_init(LCD_DISP_ON);
	sei();
	while(1)
	{			
		unsigned char ch = serial_getchar();
		LM20_setTemperature(ch);	
	}
return 0;
}
