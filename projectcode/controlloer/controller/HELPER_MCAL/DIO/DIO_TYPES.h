/*
 * std_types.h
 *
 * Created: 2/9/2022 8:23:19 PM
 *  Author: erwien
 */ 


#include <avr/io.h>
#include  "../../BIT_MATH.h"

#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_
typedef unsigned char uint8;
typedef unsigned short int uint16;
typedef unsigned long int unit32;

typedef signed char sint8;
typedef signed short int sint16;
typedef signed long int sint32;
typedef float float32;

#define DISABLE 0
#define ENABLE  1

typedef enum
{
	LOW = 0,
	HIGH = !(LOW)
}DIO_State;

typedef enum
{
	PORTHIGH = 0xFF,
	PORTLOW = !(PORTHIGH)
}DIO_PortState;

typedef enum{
	PORT_OUTPUT = 0xFF,
	PORT_INPUT = !(PORT_OUTPUT)
}DIO_PortDIR;

typedef enum{
	INPUT,
	OUTPUT
}DIO_DIR;

typedef enum{
	DIO_PORTA,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD
}DIO_PORT;
typedef enum{
	DIO_PIN0,
	DIO_PIN1,
	DIO_PIN2,
	DIO_PIN3,
	DIO_PIN4,
	DIO_PIN5,
	DIO_PIN6,
	DIO_PIN7
}DIO_PIN;



typedef enum{
	//PORT A
	DIO_PINA_0,
	DIO_PINA_1,
	DIO_PINA_2,
	DIO_PINA_3,
	DIO_PINA_4,
	DIO_PINA_5,
	DIO_PINA_6,
	DIO_PINA_7,
	//PORTB
	DIO_PINB_0,
	DIO_PINB_1,
	DIO_PINB_2,
	DIO_PINB_3,
	DIO_PINB_4,
	DIO_PINB_5,
	DIO_PINB_6,
	DIO_PINB_7,
	//PORTC
	DIO_PINC_0,
	DIO_PINC_1,
	DIO_PINC_2,
	DIO_PINC_3,
	DIO_PINC_4,
	DIO_PINC_5,
	DIO_PINC_6,
	DIO_PINC_7,
	//PORTD
	DIO_PIND_0,
	DIO_PIND_1,
	DIO_PIND_2,
	DIO_PIND_3,
	DIO_PIND_4,
	DIO_PIND_5,
	DIO_PIND_6,
	DIO_PIND_7,
	
}DIO_Channel;

typedef struct{
	DIO_PORT Port;
	DIO_PortDIR PortDirection;

}DIO_PortCFG;

typedef struct{
	DIO_Channel Pin;
	DIO_DIR PinDirection;

}DIO_PinCFG;

typedef enum{
	EXINT0,
	EXINT1,
	EXINT2
}EXINTS;
typedef enum{
	Low_Level,
	Any,
	Falling_Edge,
	Raising_Edge
}TRIGGER;

typedef enum{
	disabled,
	enabled
}EXINT_STATE;

typedef struct{
	EXINTS interrupt;
	EXINT_STATE state;
	TRIGGER trigger;
}EXINTCFG;

typedef enum{
	adc_channel_0,
	adc_channel_1,
	adc_channel_2,
	adc_channel_3,
	adc_channel_4,
	adc_channel_5,
	adc_channel_6,
	adc_channel_7
}ADCChannel;
typedef enum{
	AREF,
	AVCC,
	Reserved,
	INT256V,
}ADCVREF;

typedef enum{
	def,
	by2,
	by4,
	by8,
	by16,
	by32,
	by46,
	by128
	}ADCprescaler;



#endif /* STD_TYPES_H_ */