/*
 * ADC.c
 *
 * Created: 8/6/2022 9:14:09 PM
 *  Author: bedoa
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include "../../BIT_MATH.h"
#include "../DIO/DIO_TYPES.h"
#include <util/delay.h>

void initadc(ADCVREF vref,ADCprescaler prescaler){
	//set the VREF
	ADMUX = (ADMUX & 0b0011111) | (vref << 6);
	//set Pre-scaler with division factor Fclk/128
	ADCSRA = (ADCSRA &0b11111000 )| prescaler;
	//enable adc
	SET_BIT(ADCSRA,ADEN);
	
}
uint16 readadc(ADCChannel channel){
	
	//select channel
	ADMUX = (ADMUX & 0b11111000) | channel;
	//start conversion
	SET_BIT(ADCSRA,ADSC);
	// wait until conversion is complete and data registers are updated ==> ADIF bit is set
	while(GET_BIT(ADCSRA,ADIF) == 0);
	//clear the interrupt flag bit ,, and yes it is cleared by setting it -_-
	SET_BIT(ADCSRA,ADIF);
	//return the value read from the ADC
	return ADC;
}



