#include <avr/io.h>

#include "L293.h"
#include "pwm.h"

#define IN1 2
#define IN2 3

void L293_init()
{
	PWM_init();
	
	//SET_1(DDRD, IN1, IN2);
	DDRD = (1 << 2) | (1 << 3);
	L293_stop();
}

void L293_setPow(unsigned int power)
{
	PWM_set(power);
}

void L293_clockwise()
{
	//SET_1(PORTD, IN1);
	PORTD = (1 << 2) | (0 << 3);
	//SET_0(PORTD, IN2);
}

void L293_antiClockwise()
{
	//SET_0(PORTD, IN1);
	PORTD = (0 << 2) | (1 << 3);
	//SET_1(PORTD, IN2);
}

void L293_stop()
{
	//SET_1(PORTD, IN1, IN2);
	PORTD = (1 << 2) | (1 << 3);
}

void L293_free()
{
	//SET_0(PORTD, IN1, IN2);
	PORTD = (0 << 2) | (0 << 3);
}
