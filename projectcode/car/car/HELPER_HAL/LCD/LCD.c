/*
 * LCD.c
 *
 * Created: 7/31/2022 9:50:00 AM
 *  Author: bedoa
 */ 
#define F_CPU 8000000
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/DIO/DIO_CONFIG.h"
#include "../../MCAL/DIO/DIO_TYPES.h"
#include "../../helpers.h"
#include <util/delay.h>

void LCD_CMD(DIO_Channel lcdpins[], char cmd){
	
	DIOWritePin(lcdpins[4],LOW);
	DIOWritePin(lcdpins[5],LOW);

	DIOWriteGroup(4,lcdpins, ((cmd & 0xf0) >> 4));
	DIOWritePin(lcdpins[6],HIGH);
	_delay_ms(2);
	DIOWritePin(lcdpins[6],LOW);
	

	DIOWriteGroup(4,lcdpins,(cmd & 0x0f));
	DIOWritePin(lcdpins[6],HIGH);
	_delay_ms(2);
	DIOWritePin(lcdpins[6],LOW);
		
}

void LCD_INIT(DIO_Channel lcdpins[]){
	
	
	DIO_PinCFG LCDPinscfg[7];

	for(int i = 0;i < 7;i++)
	{
		LCDPinscfg[i].Pin = lcdpins[i];
		LCDPinscfg[i].PinDirection = OUTPUT;
	}
	
	DIO_INIT_GROUP(7,LCDPinscfg);

	
	DIOWritePin(lcdpins[5],LOW);
	_delay_ms(2); //LCD Power On Delay
	
	
	LCD_CMD(lcdpins,0x33);
	LCD_CMD(lcdpins,0x32);
	LCD_CMD(lcdpins,0x28);//select 4 bit mode 5*7 dots
	
	LCD_CMD(lcdpins,0x0F);//Display On, Cursor On
	
	LCD_CMD(lcdpins,0x01);//Clear Display
	
	LCD_CMD(lcdpins,0x02);//return to home position
	
	LCD_CMD(lcdpins,0x06);//Entry Mode Increment Cursor To Right
	
	LCD_CMD(lcdpins,0x80);//Go to first line 0-position
	
	

}


void LCD_PRINT_CHAR(DIO_Channel lcdpins[], char letter){
	DIOWritePin(lcdpins[4],HIGH);
	DIOWritePin(lcdpins[5],LOW);

	DIOWriteGroup(4,lcdpins, ((letter & 0xf0) >> 4));
	DIOWritePin(lcdpins[6],HIGH);
	_delay_ms(2);
	DIOWritePin(lcdpins[6],LOW);
	

	DIOWriteGroup(4,lcdpins,(letter & 0x0f));
	DIOWritePin(lcdpins[6],HIGH);
	_delay_ms(2);
	DIOWritePin(lcdpins[6],LOW);
	
}

void LCD_PRINT_STR(DIO_Channel lcdpins[],char* data){
	for(int i = 0,length = get_strlen(data);i < length;i++)
	{
		LCD_PRINT_CHAR(lcdpins,*(data+i));
	}
}

void curpos(DIO_Channel lcdpins[],unsigned char x_position, unsigned char y_position)
{
	int position = 0;
	if (x_position == 1)
	{
		position = 0x80;
	}
	else if (x_position == 2)
	{
		position = 0xC0;
	}
	if (y_position >=0 || y_position <=15)
	{
		position += y_position;
	}
	LCD_CMD(lcdpins,position);
}