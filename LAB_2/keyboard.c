#include "keyboard.h"

void keypad_init()
{
	DDRC  = 0xF0;
	PORTC = 0x0F;
}

int keypad_getkey()
{
	for (int row = 0; row < 4; row++)
	{
		DDRC = (0x80 >> row);
		
		for(int col = 0; col < 4; col++)
			if(!(PINC & (0x08 >> col)))
				return (col*4 + row);
	}
	return 0xFF;
}