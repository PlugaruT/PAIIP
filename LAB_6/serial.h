#ifndef SERIAL_H_
#define SERIAL_H_

#include <stdint.h>
#include <avr/io.h>
#include <stdio.h>

void serial_init(uint16_t);
char serial_getchar();
void serial_putchar(char);

#endif /* SERIAL_H_ */

