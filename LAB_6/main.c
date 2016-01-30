#include <avr/io.h>
#include <avr/interrupt.h>
#include "pwm.h"
#include "ADC.h"
#include "serial.h"
#include "timer.h"

// PID variables and constants
float Kp = 0.3;
float Ki = 0.4;
float Kd = 0.2;

float pwmNow = 0;
float pwmOld = 0;

const float pwmMin = 0.0;
const float pwmMax = 1023.0;

float errNow = 0;
float errOld = 0;
float errOld2 = 0;


ISR(TIMER0_OVF_vect)
{
	// Get ADC data from ADC pin 0 and 1
	float desiredValue = (float) ADC_getData(0);
	float actualValue = (float) ADC_getData(1);
	
	// Calculate error
	errNow = desiredValue - actualValue;
	
	pwmNow = pwmOld + 
		// Proportional
		Kp*(errNow - errOld) + 
		// Integral
		Ki*(errNow + errOld)/2 + 
		// Derivative
		Kd*(errNow - 2 * errOld + errOld2);
	
	// Check if it's in bounds
	if (pwmNow < pwmMin)
		pwmNow = pwmMin;
	else if (pwmNow > pwmMax)
		pwmNow = pwmMax;
	
	// Save old values
	errOld2 = errOld;
	errOld = errNow;
	pwmOld = pwmNow;
	
	// Set new PWM
	PWM_set(flRound(pwmNow));
	
	// Print for debugging purposes
	printf("pwmNow=%4d; desired=%4d; actual=%4d;\r\n", 
		flRound(pwmNow / 10.23), 
		flRound(desiredValue / 10.23), 
		flRound(actualValue / 10.23)
		);
}

void init()
{
	PWM_init();
	ADC_init();
	serial_init(51);
	timer_init();
	
	sei();
}

int main(void)
{
	init();
	
    while(1)
		;
}