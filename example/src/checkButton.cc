
/**
 * Name: checkButton.cc
 * 
 * Desc:
 *		This function compares PINB with BUTTON_PRESSED, a macro for (1 << 3).  If they 
 *		hold the same value, the button is currently being pressed.  The function return
 *		is then treated like a bool in main.  When true is returned, the button is being 
 *		pressed.  False means the button is not being pressed. 
 */


#include <avr/io.h>
#include "includes/checkButton.h"


int checkButton()
{
	if((PIND & BUTTON_PRESSED) == BUTTON_PRESSED)
		return 1;
	else
		return 0;
}
