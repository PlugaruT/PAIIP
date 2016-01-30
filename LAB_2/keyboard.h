/*
 * keyboard.h
 *
 * Created: 24.09.2015 10:15:12
 *  Author: Tudor
 */ 

#include <avr/io.h>

#ifndef KEYBOARD_H_
#define KEYBOARD_H_

void keypad_init();
int keypad_getkey();




#endif /* KEYBOARD_H_ */