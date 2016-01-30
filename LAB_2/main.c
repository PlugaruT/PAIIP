/*
* LAB_2.c
*
* Created: 24.09.2015 09:51:58
*  Author: Tudor
*/
#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include "lcd.h"
#include "keyboard.h"
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

const char keys[16] = {
	'+', '=', '0', 'C', '-', '3', '2', '1',	'x', '6', '5', '4', '/', '9', '8', '7',
};


int main(void)
{
	lcd_init(LCD_DISP_ON);
	keypad_init();
	
	int key = 0xFF;
	
	while(1)
	{
		key = keypad_getkey();
		
		if(key != 0xFF)
		{
			if (keys[key] == 'C')
			{
				lcd_clrscr();				
			}
			else
			{
				lcd_putc(keys[key]);
				while (keypad_getkey() != 0xFF); // wait till key is not pressed
			}
		}
	}
}