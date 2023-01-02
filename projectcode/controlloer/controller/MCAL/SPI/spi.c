/*
 * spi.c
 *
 * Created: 9/14/2022 11:59:46 AM
 *  Author: bedoa
 */ 

#include "spi.h"

void SPIInit(void){
#if SPI_ENABLE == ENABLE
	SET_BIT(SPCR,SPE);
#else 
	CLR_BIT(SPCR,SPE);
#endif
	
#if SPI_RANK == SPI_MASTER	
	SET_BIT(SPCR,MSTR);
#elif SPI_RANK == SPI_SLAVE
	CLR_BIT(SPCR,MSTR);
#endif

#if SPI_DORD == SPI_MSB_FIRST
	CLR_BIT(SPCR,DORD);
#else
	SET_BIT(SPCR,DORD);
#endif

#if SPI_CLKPHA_MODE == SPI_CLKPHA_SAMPLE
	CLR_BIT(SPCR,CPHA);
#else
	SET_BIT(SPCR,CPHA);
#endif

#if SPI_CLKPOL == SPI_CLKPOL_RAISING
	CLR_BIT(SPCR,CPOL);
#else 
	SET_BIT(SPCR,CPOL);
#endif

#if SPI_CLKRATE == SPI_CLKRATE_DIV4
	CLR_BIT(SPCR,SPR0);
	CLR_BIT(SPCR,SPR1);
	CLR_BIT(SPSR,SPI2X);
#elif SPI_CLKRATE == SPI_CLKRATE_DIV16
	SET_BIT(SPCR,SPR0);
	CLR_BIT(SPCR,SPR1);
	CLR_BIT(SPSR,SPI2X);
#elif SPI_CLKRATE == SPI_CLKRATE_DIV64
	CLR_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPR1);
	CLR_BIT(SPSR,SPI2X);
#elif SPI_CLKRATE == SPI_CLKRATE_DIV128
	SET_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPR1);
	CLR_BIT(SPSR,SPI2X);
#elif SPI_CLKRATE == SPI_CLKRATE_X2_DIV2
	CLR_BIT(SPCR,SPR0);
	CLR_BIT(SPCR,SPR1);
	SET_BIT(SPSR,SPI2X);
#elif SPI_CLKRATE == SPI_CLKRATE_X2_DIV8
	SET_BIT(SPCR,SPR0);
	CLR_BIT(SPCR,SPR1);
	SET_BIT(SPSR,SPI2X);
#elif SPI_CLKRATE == SPI_CLKRATE_X2_DIV32
	CLR_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPR1);
	SET_BIT(SPSR,SPI2X);
#elif SPI_CLKRATE == SPI_CLKRATE_X2_DIV64
	SET_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPR1);
	SET_BIT(SPSR,SPI2X);
#endif


}


unsigned char SPITransceive(unsigned char data){
	
	SPDR = data;
	while(GET_BIT(SPSR,SPIF) == 0 );
	data = SPDR;
	return data;
}

void SPI_MasterInit(void)
{
	/* Set MOSI and SCK output, all others input */
	DDRB = (1<<PB4)|(1<<PB5)|(1<<PB7);
	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}
void SPI_MasterTransmit(char cData)
{
	
	
	/* Start transmission */
	SPDR = cData;
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)))
	;
	
}
