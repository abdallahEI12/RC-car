/*
 * EXINT.c
 *
 * Created: 8/4/2022 1:35:09 PM
 *  Author: bedoa
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "../../BIT_MATH.h"
#include "../DIO/DIO.h"
#include "../DIO/DIO_TYPES.h"

void (*ptoint0)(void);
void (*ptoint1)(void);
void (*ptoint2)(void);


void INT_INIT(EXINTCFG cfg){
	switch (cfg.interrupt){
		
		case EXINT0:
			if(cfg.state == enabled){
				SET_BIT(GICR,INT0);
				
				switch (cfg.trigger){
					case Low_Level:
						CLR_BIT(MCUCR,ISC00);
						CLR_BIT(MCUCR,ISC01);
						break;
						
					case Any:
						SET_BIT(MCUCR,ISC00);
						CLR_BIT(MCUCR,ISC01);
						break;
						
					case Falling_Edge:
						CLR_BIT(MCUCR,ISC00);
						SET_BIT(MCUCR,ISC01);
						break;
						
					case Raising_Edge:
					def0:
						SET_BIT(MCUCR,ISC00);
						SET_BIT(MCUCR,ISC01);
						break;
						
				default:
					goto def0;
					
				}
			}
			else if(cfg.state == disabled)
			{
				CLR_BIT(GICR,INT0);
			}
			break;
			
		case EXINT1:
			if(cfg.state == enabled){
				
				SET_BIT(GICR,INT1);
				
				switch (cfg.trigger){
					
					case Low_Level:
						CLR_BIT(MCUCR,ISC10);
						CLR_BIT(MCUCR,ISC11);
						break;
						
					case Any:
						SET_BIT(MCUCR,ISC10);
						CLR_BIT(MCUCR,ISC11);
						break;
						
					case Falling_Edge:
						CLR_BIT(MCUCR,ISC10);
						SET_BIT(MCUCR,ISC11);
						break;
						
					case Raising_Edge:
					def1:
						SET_BIT(MCUCR,ISC10);
						SET_BIT(MCUCR,ISC11);
						break;
				default:
					goto def1;
					
				}
			}
			else if(cfg.state == disabled)
			{
				CLR_BIT(GICR,INT1);
			}
			break;
		case EXINT2:
			if(cfg.state == enabled){
				SET_BIT(GICR,INT2);
				
				
				switch (cfg.trigger){
					case Falling_Edge:
						CLR_BIT(MCUCSR,ISC2);
						break;
					case Raising_Edge:
					def2:
						SET_BIT(MCUCSR,ISC2);
						break;
				default:
					goto def2;
											
				}
			}
			else if(cfg.state == disabled)
			{
				CLR_BIT(GICR,INT1);
			}
			break;
	default:
		break;		
	}
}


void INIT_GI(EXINT_STATE state){
	if (state == enabled){
		SET_BIT(SREG,7);
	}
	else
	{
		CLR_BIT(SREG,7);
	}
}

void intcallback(EXINTS interrupt,void(*ptof)(void)){
	if(interrupt == EXINT0)
	{
		ptoint0 = ptof;
	}
	else if(interrupt == EXINT1)
	{
		ptoint1 = ptof;
	}
	else if (interrupt == EXINT2)
	{
		ptoint2 = ptof;
	}
	
}

ISR(INT0_vect)
{
	
	ptoint0();
}

ISR(INT1_vect){
	
	ptoint1();
}

ISR(INT2_vect)
{
	
	ptoint2();
}