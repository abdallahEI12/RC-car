/*
 * spi.h
 *
 * Created: 9/14/2022 12:00:44 PM
 *  Author: bedoa
 */ 


#ifndef SPI_H_
#define SPI_H_
#include "../DIO/DIO_TYPES.h"
#include "../../BIT_MATH.h"
#include "avr/io.h"
#include "SPI_Config.h"
#include "../DIO/DIO.h"
#include <avr/interrupt.h>

void SPIInit(void);
unsigned char SPITransceive(unsigned char data);
void SPI_SlaveInit(void);
char SPI_SlaveReceive(void);


#endif /* SPI_H_ */