/*
 * ADC.h
 *
 * Created: 8/6/2022 9:14:22 PM
 *  Author: bedoa
 */ 


#include <avr/io.h>
#include "../../BIT_MATH.h"
#include "../DIO/DIO_TYPES.h"

#ifndef ADC_H_
#define ADC_H_
void initadc(ADCVREF vref,ADCprescaler prescaler);
uint16 readadc(ADCChannel channel);




#endif /* ADC_H_ */