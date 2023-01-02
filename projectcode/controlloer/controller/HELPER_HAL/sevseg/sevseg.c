/*
 * _7seg.c
 *
 * Created: 7/30/2022 11:05:58 AM
 *  Author: bedoa
 */ 
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/DIO/DIO_CONFIG.h"
#include "../../MCAL/DIO/DIO_TYPES.h"

void sivseg_init(DIO_Channel pins[]){
	DIO_PinCFG pinscfg[4];
	
	for(int i = 0; i < 4; i++)
	{
		pinscfg[i].Pin = pins[i];
		pinscfg[i].PinDirection = OUTPUT;
	}
	DIO_INIT_GROUP(4,pinscfg);
}

void sivseg_display(DIO_Channel pins[], uint8 value){	
	DIOWriteGroup(4,pins, value);
}
		



