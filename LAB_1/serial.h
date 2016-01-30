/*
 * serial.h
 *
 * Created: 10-Sep-2015 10:19:56 AM
 *  Author: Tudor
 */ 

#ifndef SERIAL_H_
#define SERIAL_H_

#include <stdint.h>
#include <stdio.h>
#include <avr/io.h>

void serial_init(uint16_t ubrr);
char serial_getchar(void);
void serial_putchar(char data);


#endif /* SERIAL_H_ */