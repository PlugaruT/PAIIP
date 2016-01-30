#include "serial.h"
#include "utils.h"

static FILE mystdout = FDEV_SETUP_STREAM(serial_putchar, serial_getchar, _FDEV_SETUP_RW);

void serial_init( uint16_t ubrr) {
	// Set baud rate
	stdout = &mystdout;
	stdin = &mystdout;
		
	UBRRH = (uint8_t)(ubrr>>8);
	UBRRL = (uint8_t)ubrr;
	
	// Enable receiver and transmitter
	UCSRB = M(RXEN, TXEN);
	// Set frame format: 8data, 1stop bit
	UCSRC = M(URSEL)|(3<<UCSZ0);
}

void serial_putchar(char data) {
	// Wait for empty transmit buffer
	while ( !(UCSRA & (_BV(UDRE))) );
	// Start transmission
	UDR = data;
}

char serial_getchar(void) {
	// Wait for incoming data
	while ( !(UCSRA & (_BV(RXC))) );
	// Return the data
	return UDR;
}

