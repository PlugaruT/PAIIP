#ifndef SERIAL_H_
#define SERIAL_H_

#include <stdint.h>
#include <avr/io.h>
#include <stdio.h>

void serial_putchar(char data) {
	// Wait for empty transmit buffer
	while ( !(UCSRA & (_BV(UDRE))) );
	// Start transmission
	UDR = data;
};

char serial_getchar(void) {
	// Wait for incoming data
	while ( !(UCSRA & (_BV(RXC))) );
	// Return the data
	return UDR;
};

void serial_init( uint16_t ubrr) {
	
	static FILE mystdout = FDEV_SETUP_STREAM(serial_putchar, serial_getchar, _FDEV_SETUP_RW);
	// Set baud rate
	stdout = &mystdout;
	stdin = &mystdout;
	
	UBRRH = (uint8_t)(ubrr>>8);
	UBRRL = (uint8_t)ubrr;
	// Enable receiver and transmitter
	UCSRB = (1<<RXEN)|(1<<TXEN);
	// Set frame format: 8data, 1stop bit
	UCSRC = (1<<URSEL)|(3<<UCSZ0);
};

#endif /* SERIAL_H_ */

