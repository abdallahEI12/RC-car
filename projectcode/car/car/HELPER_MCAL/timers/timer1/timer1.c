/*
 * timer1.c
 *
 * Created: 8/15/2022 3:26:40 PM
 *  Author: bedoa
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "../../../BIT_MATH.h"
int ctr = 0;
void normalwgm(void){
	
	//choose normal mode of operation
	CLR_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
	//choose normal port operation
	CLR_BIT(TCCR1A,COM1A0);
	CLR_BIT(TCCR1A,COM1A1);
	CLR_BIT(TCCR1A,COM1B0);
	CLR_BIT(TCCR1A,COM1B1);
	//set prescaler
	SET_BIT(TCCR1B,CS10);
	CLR_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
	//enable timer over flow interrupt
	SET_BIT(TIMSK,TOIE1);
	SET_BIT(SREG,7);
	TCNT1 = 0X0000;
}

void ctcwgm(void){
	//choose CTC mode of operation
	CLR_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
	//choose to toggle OC1A on compare match
	SET_BIT(TCCR1A,COM1A0);
	CLR_BIT(TCCR1A,COM1A1);
	//choose normal port operation ON OC1b
	CLR_BIT(TCCR1A,COM1B0);
	CLR_BIT(TCCR1A,COM1B1);
	//set prescaler TO NO PRESCALER
	SET_BIT(TCCR1B,CS10);
	CLR_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
	//ENABLE compare match b interrupt
	SET_BIT(TIMSK,OCIE1B);
	sei();
	
	OCR1A = 10000;
	OCR1B = 0;
	TCNT1 = 0X0000;
	
}

ISR(TIMER1_COMPB_vect)
{
	//optain quadrble fequency at PORTA PIN 0
	TOGGLE_BIT(PORTA,1);
	ctr++;
	if(ctr%4 == 0)
	{
		OCR1B = 2500;
	}
	else if(ctr%4 == 1)
	{
		OCR1B = 5000;
	}
	else if (ctr%4 ==2)
	{
		OCR1B  = 7500;
	}
	else if(ctr%4 == 3)
	{
		OCR1B = 0;
	}
}
