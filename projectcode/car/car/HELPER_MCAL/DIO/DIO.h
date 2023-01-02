/*
 * DIO.h
 *
 * Created: 7/29/2022 1:47:22 PM
 *  Author: bedoa
 */ 


#ifndef DIO_H_
#define DIO_H_
#include <avr/io.h>
#include "DIO_TYPES.h"

void DIOWritePin(DIO_Channel channel, DIO_State state);
DIO_State DIOReadPin(DIO_Channel channel);
void DIOWritePort(DIO_PORT PORT,uint8 VALUE);
uint8 DIOReadPort(DIO_PORT PORT);
void DIOWriteGroup(uint8 PinsCount,DIO_Channel pins[], uint8 value);


#endif /* DIO_H_ */