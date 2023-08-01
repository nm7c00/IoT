/**
 * Name: main.c
 * 
 * Hardware: atmega 328p which trivially resides on an Arduino uno r3
 * 
 * Date: 7/31/23
 *
 * Desc:
 *		This program demonstrates how to send serial data (half duplex usart rs-232) from the tx pin of an atmega 328p.   I think
 * 		it would be more effective to supply the reader with the documentation I referred to rather than trying to explain what each 
 * 		line is doing and why. 
 * 
 *		Here is a high level overview of the steps involved 
 * 			0 configure the usart settings (baud rate, frame format)
 * 			1 turn on the rx/tx pins
 * 			2 write data to a buffer.  
 * 		There are different sized buffers ranging from 5 - 9 bits.  I am using the 8 bit buffer.  
 * 
 * 		On the receiving end was my raspberry pi 4 b, running raspbian.  To use a pi, you need to enable your serial ports with 'sudo raspi-config'.
 * 		Configure
 */

// The magical data sheet 
// https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf#page=8&zoom=100,45,234



#include <util/delay.h>
#include <avr/io.h>
#include <stdint.h>

#define NULL 0x0
#define FOSC 1843200 // Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

typedef unsigned char byte;

void USART_Init(byte ubrr);
void USART_Transmit(byte data);



void main(void)
{
	USART_Init(MYUBRR);

	byte data[] = "hello world";
	uint8_t i = 0;
	
	while (data[i] != NULL)
		USART_Transmit(data[i]);
}



void USART_Init(byte ubrr)
{
    /* Set baud rate */                             
    UBRR0H = (byte)(ubrr>>8);                       
    UBRR0L = (byte)ubrr;                            

	/* Set frame format: 8 bit data segments, 2 stop bits */ 
	//UCSR0C = (1<<USBS0)|(3<<UCSZ00);
	UCSR0C = (3<<UCSZ00);
	                                                                
	/* Enable transmitter only */
	UCSR0B = (1<<TXEN0);
}
		
void USART_Transmit(byte data)
{
    /* Wait for empty transmit buffer */
    while ( !(UCSR0A & (1<<UDRE0)) );
	
    /* Put data into buffer, data is sent via magic and possibly some form of alchemy */
    UDR0 = data;
}