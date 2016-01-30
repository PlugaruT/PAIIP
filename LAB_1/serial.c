/*
 * serial.c
 *
 * Created: 10-Sep-2015 10:17:45 AM
 *  Author: Tudor
 */ 

#include "serial.h"

//setup a buffer which is valid for stdio operations
static FILE mystdio = FDEV_SETUP_STREAM(serial_putchar, serial_getchar, _FDEV_SETUP_RW);

//Initialize USART 
void serial_init(uint16_t ubrr) {
	stdout = &mystdio;
	stdin = &mystdio;
	
	// Set baud rate
	UBRRH = (uint8_t)(ubrr>>8);
	UBRRL = (uint8_t)ubrr;
	// Enable receiver and transmitter
	UCSRB = (1<<RXEN)|(1<<TXEN);
	// Set frame format: 8data, 1stop bit
	UCSRC = (1<<URSEL)|(3<<UCSZ0);
}


void serial_putchar(char data) {
	// Wait for empty transmit buffer
	while ( !(UCSRA & (_BV(UDRE))) );
	// Start transmission
	UDR = data;
}

char serial_getchar(void)
{
	// Wait for incoming data
	while ( !(UCSRA & (_BV(RXC))) );
	// Return the data
	return UDR;
}

