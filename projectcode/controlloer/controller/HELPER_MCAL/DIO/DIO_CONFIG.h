/*
 * DIO_CONFIG.h
 *
 * Created: 7/29/2022 8:06:07 AM
 *  Author: bedoa
 */ 


#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_
/*void DIO_INIT(void);*/

void DIO_INIT_PIN(DIO_PinCFG pincfg);
void DIO_INIT_GROUP(uint8 PinsCount,DIO_PinCFG array[]);
void DIO_INIT_PORT(DIO_PortCFG portcfg);
#endif /* DIO_CONFIG_H_ */