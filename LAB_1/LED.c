/*
 * LED.c
 *
 * Created: 17.09.2015 12:55:07
 *  Author: Tudor
 */ 

#include "LED.h"

//initialize LED
void LED_init()
{
	DDRC |= 1; //In position 0 will be 1
	PORTC &= !1;
}

//turn on LED
void LED_on()
{
	//set PIN0 of PORTC = 1
	PORTC ^= 1;
}

void LED_off()
{
	//set PIN0 of PORTC = 0
	PORTC &= !1;
}