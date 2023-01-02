/*
 * LCD8.c
 *
 * Created: 7/31/2022 1:44:03 PM
 *  Author: bedoa
 */ 
#define F_CPU 8000000UL
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/DIO/DIO_CONFIG.h"
#include "../../MCAL/DIO/DIO_TYPES.h"
#include <util/delay.h>

void LCD_CMD8(DIO_PORT dataport,DIO_Channel ctrlpins[],char cmd){
	DIOWritePort(dataport,cmd);
	DIOWritePin(ctrlpins[0],LOW);
	DIOWritePin(ctrlpins[1],LOW);
	DIOWritePin(ctrlpins[2],HIGH);
	_delay_ms(2);
	DIOWritePin(ctrlpins[2],LOW);
}

void LCD_INIT8(DIO_PORT dataport,DIO_Channel ctrlpins[]){
	DIO_PortCFG dataportcfg = {dataport,PORT_OUTPUT};
	DIO_INIT_PORT(dataportcfg);
	
	DIO_PinCFG ctrlpinscfg[3];
	for(int i = 0; i < 3; i++)
	{
	 ctrlpinscfg[i].Pin = ctrlpins[i];
	 ctrlpinscfg[i].PinDirection = OUTPUT;
	}
	DIO_INIT_GROUP(3,ctrlpinscfg);
	
	
	DIOWritePin(ctrlpins[0],LOW);
	_delay_ms(2);
	LCD_CMD8(dataport,ctrlpins ,0x38); //Initialize the LCD in 16X2 8-bit mode
	_delay_ms(2);
	LCD_CMD8(dataport,ctrlpins ,0x0C); //Initialize the LCD in 16X2 8-bit mode
	_delay_ms(2);
	LCD_CMD8(dataport,ctrlpins ,0x01); //clear the screen
	_delay_ms(2);
	LCD_CMD8(dataport,ctrlpins ,0x02); //return to home position
	_delay_ms(2);
	LCD_CMD8(dataport,ctrlpins ,0x06); //increment the position of the cursor with each character being written
	_delay_ms(2);
	LCD_CMD8(dataport,ctrlpins ,0x80); //Go to first line 0-position
	_delay_ms(2);
}

void LCD_PRINT_CHAR8(DIO_PORT dataport,DIO_Channel ctrlpins[],char letter){
	DIOWritePort(dataport,letter);
	_delay_ms(2);
	DIOWritePin(ctrlpins[0],HIGH);
	DIOWritePin(ctrlpins[1],LOW);
	DIOWritePin(ctrlpins[2],HIGH);
	_delay_ms(2);
	DIOWritePin(ctrlpins[2],LOW);
}