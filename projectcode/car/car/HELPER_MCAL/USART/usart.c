/*
 * usart.c
 *
 * Created: 8/24/2022 7:53:58 PM
 *  Author: bedoa
 */ 

#include "../../BIT_MATH.h"
#include "../DIO/DIO.h"
#include "../../helpers.h"
#include "../DIO/DIO_TYPES.h"
#include "../DIO/DIO_CONFIG.h"
#include <avr/io.h>
void usartinit(unsigned int baud){
	
/******** set baud rate ********/
/*******************************/

	//Use UBRR register
	CLR_BIT(UBRRH,URSEL);
	//copy the baud rate to UBRR register
	UBRRH = (unsigned char) baud >> 8;
	UBRRL = (unsigned char) baud;
	
/******** enable receiver transmitter ********/
/*********************************************/
	//enable receiver
	SET_BIT(UCSRB,RXEN);
	//enable transmitter
	SET_BIT(UCSRB,TXEN);
	
	
/******** set frame format ********/
/**********************************/
	//use UCSRC register
	SET_BIT(UCSRC,URSEL);
	//use Asynchronous mode
	CLR_BIT(UCSRC,UMSEL);
	//turn off parity mode
	CLR_BIT(UCSRC,UPM0);
	CLR_BIT(UCSRC,UPM1);
	//use one stop bit
	CLR_BIT(UCSRC,USBS);
	//use 8 bit frame
	SET_BIT(UCSRC,UCSZ0);
	SET_BIT(UCSRC,UCSZ1);
	CLR_BIT(UCSRC,UCSZ2);
}

void USART_Init( unsigned int baud )
{
	/* Set baud rate */
	UBRRH = (unsigned char)(baud>>8);
	UBRRL = (unsigned char)baud;
	/* Enable receiver and transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8data, 2stop bit */
	UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
}


void usartsendchar(unsigned char data){
	//wait until UDR is empty 
	while(!GET_BIT(UCSRA,UDRE));
	//send data 
	UDR = data;

}

unsigned char usartrecvchar(void)
{
	//wait until UDR is empty
	while(!GET_BIT(UCSRA,RXC));
	
	// return the read data
	return UDR;
}


void usartsend(char* data){
	int length = get_strlen(data);
	for(int i = 0; i < length; i++)
	{
		usartsendchar(data[i]);
	}
}