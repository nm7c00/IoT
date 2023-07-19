/**
  * test.c
  * 
  *
  * Hardware: 
  *	arduino uno r3
  *
  * Description:
  * This project just turns the built in led light on for one second and off for 
  * another second... forever.
  *
  * DDRB (location 0x25) is a single byte (hence the unsigned char) register 
  * location.  DDR stands for Data Direction Register.  When a bit in the 
  * register is set to 0, the register will recieve input; setting a bit
  * to 1 will tell the hardware to treat it as an output register. 
  * Setting bit 5 to 1 (true) on DDRB will let us turn the led on and off
  * on portb5.
  *
  * PORTB (location 0x24) is another single byte register location.  Port B 
  * bit 5 is the port that controls LED_BUILTIN (the built in led next to 
  * your tx and rx led's).  Setting bit 5 on PORTB from 0 to 1 will turn on 
  * the led.  
  *
  * Note that bits in a byte are numbered like an array (7-0).
  *
  * There are multiple ways to set a bit in a byte.  A polite way would
  * probably be 'ddrb = ddrb | (1 << 5);' because that wouldn't interfere
  * with any of the other bits in the byte.  I've chosed to just use decimal 
  * numbers because I don't care about any of the other bits, infact I want 
  * them to be set to 0 if they aren't. 
  *
  * Using avr-libc (<avr/io.h>) is probably better because it automatically 
  * detects the hardware then loads the correct header (in my case it was 
  * /usr/lib/avr/include/avr/iom328p.h) which sets macros (PORTB, DDRB, 
  * etc...) to the correct address locations.
  */

#include <util/delay.h>

#define ddrb  *((volatile unsigned char*) 0x24)
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
