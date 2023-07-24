/**
 * Name: Example.cc
 * 
 * Hardware: arduino uno r3 (atmega328p)
 *
 * Desc:
 *		This project demonstrates how to use hardware registers for both input and output. 
 */


#include <util/delay.h>
#include "includes/atmega328p.h"
#include "includes/checkButton.h"


int main(void)
{
	// set bit 2 on ddrd to from 0/input (default) to 1/output 
	DDRD = DDRD | (1 << 2);

	// bit 3 is used to detect button input, all bits default to zero so 
	// I don't have to set anything 

	while (1) 
	{
		_delay_ms(500);


		// if checkButton() returns 1 (true), set portd's bit 2 to 1 (output)
		if (checkButton())
			PORTD = PORTD | (1 << 2); 

		// if checkButton() returns 0 (false), set portd's bit 2 to 0 (input), but because 
		// ddrd bit 2 is set to output, 0 on portd bit 2 means no output/no power)
		else 
			PORTD = PORTD & ~(1 << 2);


		_delay_ms(500);
	}

	return 0;
}
