/**
 * Name: main.c
 * 
 * Hardware: atmega 328p which trivially resides on an Arduino uno r3
 * 
 * Date: 7/31/23
 *
 * Desc:
 *		Aside from a precalculated baurd rate, this code is pretty much a copy paste of the uart example code from atmel's atmega 328p data sheet.
 */

// The magical data sheet 
// https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf#page=8&zoom=100,45,234


#include <stdint.h>
#include <util/delay.h>
#include <avr/io.h>

#define NULL 0x0
#define BAUD_RATE_9600_BPS 103

typedef uint8_t byte;

void UART_Init(byte ubrr);
void UART_Transmit(byte data);



void main(void)
{
	UART_Init(BAUD_RATE_9600_BPS);

	byte data[] = "a";				// this line works but 
	//byte data[] = "abcdef\r\n";   // these two commented lines do not 
	//byte data[] = "abc";
	uint8_t i = 0;
	
	while(1)
	{
		while (data[i] != NULL)
		{
			UART_Transmit(data[i]);
			i++;
		}

		i = 0;
	}
}



void UART_Init(byte ubrr)
{
    /* Set baud rate */                             
    UBRR0H = (ubrr>>8);                       
    UBRR0L = (byte)ubrr;                            

	/* Set frame format: 8 bit data segments, 1 stop bit */ 
	UCSR0C = (3<<UCSZ00);
	                                                                
	/* Enable transmitter only */
	UCSR0B = (1<<TXEN0);
}
		
void UART_Transmit(byte data)
{
    /* Wait for empty transmit buffer */
    while ( !(UCSR0A & (1<<UDRE0)) )
		;
	
    /* Put data into buffer, data is sent via magic and possibly some form of alchemy */
    UDR0 = data;
}
