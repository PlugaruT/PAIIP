#ifndef LM20_H_
#define LM20_H_

#include <math.h>
#include <avr/io.h>
#include <ctype.h>
char volatile choose_model = 'C';
#include "lcd.h"

void LM20_init ()
{
	/// Begin ADCSRA
	ADCSRA =
	(1 << ADEN ) | // ADC Enable
	(0 << ADSC ) | // ADC Start Conversion
	(1 << ADATE )| // ADC Auto Trigger Enable
	(1 << ADIE ) | // ADC Interrupt Enable
	// division factor set to 32
	(1 << ADPS2 )|
	(0 << ADPS1 )|
	(1 << ADPS0 );
	/// End ADCSRA
	/// Begin ADMUX
	ADMUX =
	// AREF , Internal Vref turned off .
	(0 << REFS0 ) |
	(0 << REFS1 ) |
	// Set right adjusting .
	(0 << ADLAR ) |
	// Get input from ADC4 .
	(0 << MUX4 ) |
	(0 << MUX3 ) |
	(1 << MUX2 ) |
	(0 << MUX1 ) |
	(0 << MUX0 ) ;
	/// End ADMUX
	/// Begin SFIOR
	SFIOR =
	// Set timer0 overflow interrupt .
	(1 << ADTS2 ) |
	(0 << ADTS1 ) |
	(0 << ADTS0 ) ;
	/// End SFIOR
};

void LM20_setTemperature ( char Temp_model )
{
	Temp_model = toupper ( Temp_model );
	if ( Temp_model == 'C' || Temp_model == 'K' || Temp_model == 'F')
	choose_model = Temp_model ;
};

float LM20_Kelvin( float x )
{
	return x + 273.15 ;
};

float LM20_Fahrenheit( float x )
{
	return x * 1.8 + 32.0 ;
};

void LM20_printData ()
{
	char buffer[10];
	float temperature = roundf((382 - (float)ADC) / 2.4);
	switch ( choose_model )
	{
	case 'K':
		temperature = LM20_Kelvin(temperature);
		lcd_clrscr();
		lcd_gotoxy(0, 1);
		lcd_puts("Kelvin");
		break ;
	case 'F':
		temperature = LM20_Fahrenheit(temperature);
		lcd_clrscr();
		lcd_gotoxy(0, 1);
		lcd_puts("Fahrenheit");
		break ;
	default:
		lcd_clrscr();
		lcd_gotoxy(0, 1);
		lcd_puts("Celsius");
		break;
	}
	lcd_gotoxy(0, 0);
	itoa((int)temperature, buffer, 10);
	lcd_puts(buffer);
};

#endif /* LM20_H_ */