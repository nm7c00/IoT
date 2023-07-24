#include <avr/io.h>
#include "includes/checkButton.h"

int checkButton()
{
	if((PIND & BUTTON_PRESSED) == BUTTON_PRESSED)
		return 1;
	else
		return 0;
		
}
