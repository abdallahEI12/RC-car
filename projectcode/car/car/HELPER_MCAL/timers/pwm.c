/*
 * pwm.c
 *
 * Created: 8/12/2022 1:43:22 AM
 *  Author: bedoa
 */ 
#include <avr/io.h>
#include "../../BIT_MATH.h"
#include "../DIO/DIO.h"
#include <math.h>
#define F_CPU 16000000
void oc0pwmgenerator(float Foc0,char percentage){
	float percent = (float)percentage / 100;
	//toggle 0.01s
	
	int ctr = 0;
	
	//set prescaler
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
	
	//CTC MODE
	SET_BIT(TCCR0,WGM01);
	CLR_BIT(TCCR0,WGM00);
	//normal port operation on oc0
	CLR_BIT(TCCR0,COM00);
	CLR_BIT(TCCR0,COM01);
	//generate 50 hz ==> 20ms T
	float temp = F_CPU/(64*Foc0*20);
	OCR0 = (int)temp;
	int T_total = 20;
	int T_On = percent * (float) T_total;
	//int T_Off = T_total- T_On;
	TCNT0 = 0x0;
	while(1)
	{
		while(GET_BIT(TIFR,OCF0) == 0);
		ctr++;
		SET_BIT(TIFR,OCF0);
		if(ctr <= T_On)
		{
			SET_BIT(PORTB,PINB3);
		}
		else if(ctr < T_total)
		{
			CLR_BIT(PORTB,PINB3);
		}
		else
		{
			ctr = 0;
		}
	}
}

void oc0fastpwm(void)
{
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	
	SET_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	
	//float power = 20;
	//float temp = round(((100-power)/100) * 256);
	OCR0 = 201;
	TCNT0 = 0x00;
}

void oc0pcpwm(void)
{
	SET_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
	
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	
	SET_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	
	//float power = 20;
	//float temp = round(((100-power)/100) * 256);
	OCR0 = 201;
	TCNT0 = 0x00;
}