#include "utils.h"

void strcpylen( char * to, char * from, uchar len ) {
	while ( len-- ) {
		to[ len ] = from[ len ];
	}
}

void nops( int num ) {
	while ( num-- )
		asm( "nop" );
}

float getKelvinFromCelsius(float celsius)
{
	return celsius + 273.15f;
}

float getFahrenheitFromCelsius(float celsius)
{
	return celsius * 1.8 + 32.0;
}

int flRound(float flNum)
{
	int retNum = (int)flNum;
	float afterPoint = flNum - (float)retNum;
	
	if (afterPoint > 0.5)
		retNum ++;
		
	return retNum;
}