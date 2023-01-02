/*
 * delay.c
 *
 * Created: 8/11/2022 4:34:42 PM
 *  Author: bedoa
 */
#include <avr/io.h> 
#include "../../BIT_MATH.h"
#include "../DIO/DIO.h"
#include <math.h>
#define F_CPU 16000000


void s_delay(int seconds){
	unsigned int i = 0;
	TCCR0 = 0b00000101;
	while(1)
	{
		while(GET_BIT(TIFR,TOV0) == 0);
		i++;
		if(i== seconds * 61)
		{
			break;
		}	
	}	
}


	
