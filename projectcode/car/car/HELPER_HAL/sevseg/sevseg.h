/*
 * _7seg.h
 *
 * Created: 7/30/2022 11:06:13 AM
 *  Author: bedoa
 */ 


#ifndef sevseg_H_
#define sevseg_H_
void sivseg_init(DIO_Channel pins[4]);
void sivseg_display(DIO_Channel pins[4], uint8 value);



#endif /* 7SEG_H_ */