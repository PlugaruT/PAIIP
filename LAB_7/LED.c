#include <avr/io.h>
#include "LED.h"
void vLEDInit(void)
{
// Set LED_O as output pin
    DDR_LED_O |= (1 << BIT_LED_O);
}
void vLEDToggle(void)
{
   //Toggle LED
   PORT_LED_O ^= (1 << BIT_LED_O);	
}

void vLEDInit1(void)
{
	// Set LED_O as output pin
	DDR_LED_O |= (1 << 4);
}
void vLEDToggle1(void)
{
	//Toggle LED
	PORT_LED_O ^= (1 << 4);
}

