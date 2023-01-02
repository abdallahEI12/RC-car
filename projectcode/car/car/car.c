/*
 * test_DIO.c
 *
 * Created: 2/9/2022 8:20:19 PM
 * Author : erwien
 */ 

#define F_CPU 16000000UL

#include <util/delay.h>
#include <avr/io.h>
#include "MCAL/DIO/DIO_TYPES.h"
#include "MCAL/DIO/DIO_CONFIG.h"
#include "MCAL/DIO/DIO.h"
#include "MCAL/SPI/spi.h"
#include "move.h"


/*
DIO_Channel lcdpinsarray[]= { 
	 DIO_PINC_0, 
	 DIO_PINC_1,
	 DIO_PINC_2, 
	 DIO_PINC_3, 
	 DIO_PINC_5, 
	 DIO_PINC_6, 
	 DIO_PINC_7 };
*/

DIO_PortCFG OutputPort = {DIO_PORTD,PORT_OUTPUT};
int main(void)
{	
	DIO_INIT_PORT(OutputPort);
	SPI_SlaveInit();
	char movement;
	while(1)
	{	
	 movement = SPI_SlaveReceive();
	 move(movement);
	
	}
}

