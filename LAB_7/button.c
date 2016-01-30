#include <avr/io.h>
#include "button.h"
#include "FreeRTOS.h"
void vButtonInit(void)
{
    // Set SWITCH_IP as input pin
    DDR_SWITCH_IP &= ~(1<<BIT_SWITCH_IP);
    // Enable pull-up on SWITCH_IP
    PORT_SWITCH_IP |= (1<<BIT_SWITCH_IP);	
}
char xButtonGetStatus(void)
{
	        // See if switch is pressed
        if((PIN_SWITCH_IP&(1<<BIT_SWITCH_IP)) == 0)
        {
           return pdTRUE;
        }
        else
        {
           return pdFALSE;
        }
}