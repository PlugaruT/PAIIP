/*
 * GccLAB_1.c
 *
 * Created: 10-Sep-2015 09:51:04 AM
 *  Author: Tudor
 */ 

#include "serial.h"
#include "LED.h"

int main(void)
{
	char ch;
	serial_init(51);
	LED_init();
	
	while(1)
	{
		//print messages on the screen
		printf("Press 1 to turn LED on. \r");
		printf("Press 0 to turn LED off. \r\r");
		//get the input char from keyboard
		ch = serial_getchar();
		
		switch(ch)
		{
			case '0':
				//turn off LED
				printf("LED off!\r");
				LED_off();
				break;
			case '1':
				//turn on LED
				printf("LED on!\r");
				LED_on();
				break;
			default:
				printf("Wrong key!\r");
				break;
		}
	}
}