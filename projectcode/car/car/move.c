/*
 * move.c
 *
 * Created: 9/15/2022 2:42:56 PM
 *  Author: bedoa
 */ 
#include "MCAL/DIO/DIO.h"
#include "MCAL/DIO/DIO_CONFIG.h"
#include "MCAL/DIO/DIO_TYPES.h"


#define stop 0b00000000
#define forward 0b00000001
#define backward 0b00001000
#define forward_left 0b00000011
#define forward_right 0b00000101
#define rotate 0b00000110
#define backward_left 0b00001010
#define backward_right 0b00001100

void move(char movement){
	switch(movement){
		case backward:
			DIOWritePin(DIO_PIND_0,HIGH);
			DIOWritePin(DIO_PIND_2,HIGH);
			break;
		case forward:
			DIOWritePin(DIO_PIND_1,HIGH);
			DIOWritePin(DIO_PIND_3,HIGH);
			break;
		case rotate:
			DIOWritePin(DIO_PIND_0,HIGH);
			DIOWritePin(DIO_PIND_3,HIGH);
			break;
		case stop:
			DIOWritePin(DIO_PIND_0,LOW);
			DIOWritePin(DIO_PIND_1,LOW);
			DIOWritePin(DIO_PIND_2,LOW);
			DIOWritePin(DIO_PIND_3,LOW);
			break;
		
	}
}