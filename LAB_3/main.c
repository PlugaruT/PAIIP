/*
 * GccLAB_1.c
 *
 * Created: 08-Oct-2015 09:51:04 AM
 *  Author: Tudor
 */ 
#define F_CPU 8000000UL 
#define minTemp 0UL
#define maxTemp 60UL
#define maxADC 382UL
#define minADC 238UL

#include "serial.h"
#include "lm20.h"
#include "lcd.h"
#include <util/delay.h>

int main(void)
{
	int ADCvalue = 0;
	int tempc = 0;
	float param0 = 2.4;
	int param = 382;
	char buffer[10];
	int tempf = 0;
		
	serial_init(51);
	LM20_init();
	lcd_init(LCD_DISP_ON);
	int count = 1;
	while(1)
	{
		ADCvalue = LM20_GetTemp();
		//tempc = (param - ADCvalue) / param0;
		tempc = (((((long)(ADCvalue - minADC) * (maxTemp - minTemp)) / (maxADC - minADC) ) + minTemp)) / 10;
		itoa(tempc, buffer, 10);
		tempf = tempc * 1.8 + 32;
		lcd_clrscr();
		lcd_puts(buffer);
		lcd_puts(" Celsius");
		itoa(ADCvalue, buffer, 10);
		lcd_gotoxy(0 ,1);
		lcd_puts(buffer);
		lcd_puts(" Fahrenheit");
		_delay_ms(50);
	}
}