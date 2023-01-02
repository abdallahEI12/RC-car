/*
 * CFile1.c
 *
 * Created: 7/29/2022 8:04:54 AM
 *  Author: bedoa
 */

#include <avr/io.h>
#include "DIO_TYPES.h"

void DIO_INIT_PIN(DIO_PinCFG pincfg){
	DIO_PORT port = (int)(pincfg.Pin / 8);
	DIO_PIN channel = pincfg.Pin % 8;
	if(port == DIO_PORTA)
	{
		if(pincfg.PinDirection == OUTPUT)
		{
			SET_BIT(DDRA,channel);
		}
		else{
			CLR_BIT(DDRA,channel);
		}
	}
	else if(port == DIO_PORTB)
	{
		if(pincfg.PinDirection == OUTPUT)
		{
			SET_BIT(DDRB,channel);
		}
		else{
			CLR_BIT(DDRB,channel);
		}
	}
	else if(port == DIO_PORTC)
	{
		if(pincfg.PinDirection == OUTPUT)
		{
			SET_BIT(DDRC,channel);
		}
		else{
			CLR_BIT(DDRC,channel);
		}
	}
	else if(port == DIO_PORTD)
	{
		if(pincfg.PinDirection == OUTPUT)
		{
			SET_BIT(DDRD,channel);
		}
		else{
			CLR_BIT(DDRD,channel);
		}
	}
}

void DIO_INIT_PORT(DIO_PortCFG portcfg){
	switch (portcfg.Port){
		case DIO_PORTA:
			DDRA = portcfg.PortDirection;
			return;
		case DIO_PORTB:
			DDRB = portcfg.PortDirection;
			return;
		case DIO_PORTC:
			DDRC = portcfg.PortDirection;
			return;
		case DIO_PORTD:
			DDRD = portcfg.PortDirection;
			return;
		default:
			return;		
	}
}

void DIO_INIT_GROUP(uint8 PinsCount,DIO_PinCFG array[])
{
	for(int i = 0;i <PinsCount; i++){
		DIO_INIT_PIN(array[i]);
	}
}