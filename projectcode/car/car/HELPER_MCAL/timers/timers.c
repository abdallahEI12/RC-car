/*
 * timers.c
 *
 * Created: 8/9/2022 6:14:20 PM
 *  Author: bedoa
 */ 
#include <avr/io.h>
#include "../DIO/DIO_TYPES.h"
#include "../../BIT_MATH.h"

void timerinit(void){
	//initialize the timer
	TCNT0 = 0;
	
	//select mode of operation for the timer
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
	
	// set a Prescaler for the timer
	SET_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	
}