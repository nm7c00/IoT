/**
  * Device: 
  * arduino uno r3
  *
  * Description:
  * This project just turns the built in led light on
  * for one second and off for another second... forever.
  *
  * First the data direction Data Direction Register 
  * (DDRB) needs to be told if its receiving input (0) 
  * or giving output (1).  We want it to send output to
  * the built in led light on the arduino board which is
  * attached to pb5 (so we want to set bit num 5 to 1 
  * instead of 0);  Knowing this, we want to set DDRB
  * (0x24) from 0000 0000 to 0010 0000 then we want to set 
  * PORTB from 0000 0000 (led off) to 0010 0000 (led on).
  *
  * Note that bits in a byte are numbered like an array 
  * (7-0) instead of (8-1).
  */

#include <util/delay.h>

// single byte pointer to 0x24 (DDRB)
#define ddrb *((volatile unsigned char*) 0x24)

// single byte pointer to 0x25 (PORTB) 
#define portb *((volatile unsigned char*) 0x25)

int 
main(void)
{
	ddrb = 32;

	while (1)
	{
		portb = 32;

		_delay_ms(1000);

		portb = 0;

		_delay_ms(1000);
	}

	return 0;
}
