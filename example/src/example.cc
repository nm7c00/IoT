/**
 * Name: example.cc
 * 
 * Hardware: arduino uno r3 (atmega328p)
 *
 * Desc:
 *		This project demonstrates how to use arduino hardware registers for both input and output. 
 *
 *		You press a button, an led turns on.  That's it.  The comments are an attempt to make this program
 *		accessible to anyone regardless of experience.   
 *
 *		I chose to replace avr-libc's io.h with my own atmega328p.h.  avr/io.h's job is to detect hardware 
 *		and load the correct header;  Replacing avr/io.h with a hardware specific header is more novel than 
 *		it is useful.  iom328p.h (the header that would've been included if I used avr/io.h) and atmel's data 
 *		sheet for the ATmega328P are what guided me.   
 *
 *		This project has two moving parts.  Data direction registers and the physical io pins on the 
 *		arduino.  As the name would imply, data direction registers dictate the direction the data is 
 *		flowing on the physical pin (is it an output port or an input pin??).  If it is outputting power, 
 *		it is referred to as a PORT.  If it is receiving input, it is referred to as a PIN.  Pins, ports 
 *		and ddr's come in sets of eight, so naturally, they are controlled with single byte integers  
 *		where a value of 1 means output and a value of 0 means input. 
 *
 *		If DDRD bit 2 is set to 0, you can check for input by seeing whether PIND bit 2 holds a value of 
 *		0 (nothing is happening) or 1 (actively recieving input).  You can try messing with PORTD bit 2, 
 *		but it won't do anything because the ddr that controls it (DDRD bit 2) is set to input.
 *
 *		If DDRD bit 2 is set to 1, you can tell it to give output by setting PORTD bit 2 from 0 to 1.  
 *		Again, you can mess with PIND bit 2 all you want, but it wont do anything because it's data 
 *		direction register is set to 1 (output).
 *
 *		Bytes are indexed 7-0.  So bit shifting 1 << 5 would go from 0000 0000 to 0010 0000.  The decimal 
 *		value held at this address would go from 0 to 32.  Setting the whole thing as a decimal number or 
 *		hex ' *((volatile byte*) 0xPORTx_address) = 0x20; ' is fine, but keep in mind that it sets the whole byte.
 */


#include <util/delay.h>
#include "includes/atmega328p.h"
#include "includes/checkButton.h"


int main(void)
{
	 // Set bit 2 on DDRD to from 0/input (default) to 1/output.
	 // PORTD2 is now a potential power source for the led circuit. 
	DDRD = DDRD | (1 << 2);

	// Because all memeory defaults to 0, all ddrs are preconfigured to 
	// receive input.  All I have to do is plug a wire from the button 
	// to a pin and check the pin's value to see the circuit is completed.  
	// In this case, PIND3 is being used. 

	while (1) 
	{
		// Without a couple of delays, the microcontroller would loop as fast as it physically can.
		// This is both imperceivable and almost hilariously unnecessary considering the task.
		_delay_ms(500);


		// If the button is being pressed, turn on the led.
		if (checkButton())
			PORTD = PORTD | (1 << 2); 

		// Else, turn off the led.
		else 
			PORTD = PORTD & ~(1 << 2);
	}

	// This return is only here to keep the compiler happy.  This train don't stop, choo choo. 
	return 0;
}
