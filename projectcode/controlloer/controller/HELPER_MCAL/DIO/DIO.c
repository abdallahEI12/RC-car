/*
 * DIO.c
 *
 * Created: 7/29/2022 8:12:33 AM
 *  Author: bedoa
 */ 
#include <avr/io.h>
#include "DIO_TYPES.h"
#include "DIO.h"
#include "../../BIT_MATH.h"


/*                           WRITE TO DIO                         */
/* ****************** ******************* *********************** */
void DIOWritePin(DIO_Channel channel, DIO_State state)
{
	DIO_PORT port = channel / 8;
	DIO_PIN pin = channel % 8;
	switch (port){
		case DIO_PORTA:
			if(state == HIGH){
				SET_BIT(PORTA,pin);
			}
			else{
				CLR_BIT(PORTA,pin);
			}
			break;
		case DIO_PORTB:
			if(state == HIGH){
				SET_BIT(PORTB,pin);
			}
			else{
				CLR_BIT(PORTB,pin);
			}
			break;
		case DIO_PORTC:
			if(state == HIGH){
				SET_BIT(PORTC,pin);
			}
			else{
				CLR_BIT(PORTC,pin);
			}
			break;
		case DIO_PORTD:
			if(state == HIGH){
				SET_BIT(PORTD,pin);
			}
			else{
				CLR_BIT(PORTD,pin);
			}
			break;
	default:
		break;
	}
}

void DIOWritePort(DIO_PORT PORT, uint8 VALUE){
	switch (PORT){
		case DIO_PORTA:
			PORTA = VALUE;
			break;
		case DIO_PORTB:
			PORTB = VALUE;
			break;
		case DIO_PORTC:
			PORTC = VALUE;
			break;
		case DIO_PORTD:
			PORTD = VALUE;
			break;
	default:
		break;
	}
}
void DIOWriteGroup(uint8 PinsCount,DIO_Channel pins[], uint8 value){
	
	for(int i = 0;i <PinsCount; i++)
	{
		DIOWritePin(pins[i],GET_BIT(value,i));
	}
}

/*                           READ FROM DIO                        */
/* ****************** ******************* *********************** */

DIO_State DIOReadPin(DIO_Channel channel){
	DIO_PORT port = channel /8;
	DIO_PIN pin = channel % 8;
	switch (port){
		case DIO_PORTA:
			return GET_BIT(PINA,pin);
			
		case DIO_PORTB:
			return GET_BIT(PINB,pin);
			
		case DIO_PORTC:
			return GET_BIT(PINC,pin);
			
		case DIO_PORTD:
			return GET_BIT(PIND,pin);
			
	default:
		return LOW;
		
	}
}

uint8 DIOReadPort(DIO_PORT PORT){
	switch (PORT){
		case DIO_PORTA:
			return PINA;
		case DIO_PORTB:
			return PINB;
		case DIO_PORTC:
			return PINC;	
		case DIO_PORTD:
			return PIND;
		default:
			return 0x00;
	}
	
}