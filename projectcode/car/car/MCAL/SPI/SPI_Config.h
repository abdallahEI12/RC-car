/*
 * SPI_Config.h
 *
 * Created: 9/14/2022 8:34:42 PM
 *  Author: bedoa
 */ 

#include "../DIO/DIO_TYPES.h"
#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/*
 *master or slave
 *Clock Polarity
 *Clock Phase
 *Clock Prescaler
 *MSB or LSB first
*/

#define SPI_ENABLE ENABLE

/* SPI Chip rank */
#define SPI_MASTER 1
#define SPI_SLAVE  0

#define SPI_RANK SPI_SLAVE


/* SPI data order */
#define SPI_MSB_FIRST 0
#define SPI_LSB_FIRST 1

#define SPI_DORD SPI_MSB_FIRST

/* SPI Clock phase */

#define SPI_CLKPHA_SAMPLE 0
#define SPI_CLKPHA_SETUP 1

#define SPI_CLKPHA_MODE SPI_CLKPHA_SAMPLE

/* SPI Clock polarity */
#define SPI_CLKPOL_RAISING 0
#define SPI_CLKPOL_FALLING 1

#define SPI_CLKPOL SPI_CLKPOL_RAISING
/* select Clock rate */
#define SPI_CLKRATE_DIV4 0
#define SPI_CLKRATE_DIV16 1
#define SPI_CLKRATE_DIV64 2
#define SPI_CLKRATE_DIV128 3
#define SPI_CLKRATE_X2_DIV2 4
#define SPI_CLKRATE_X2_DIV8 5
#define SPI_CLKRATE_X2_DIV32 6
#define SPI_CLKRATE_X2_DIV64 7

#define SPI_CLKRATE SPI_CLKRATE_DIV4




#endif /* SPI_CONFIG_H_ */