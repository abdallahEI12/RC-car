/*
 * usart.h
 *
 * Created: 8/24/2022 7:54:16 PM
 *  Author: bedoa
 */ 


#ifndef USART_H_
#define USART_H_
void usartinit(unsigned int baud);
void USART_Init( unsigned int baud );
void usartsend(char* data);
unsigned char usartrecvchar(void);



#endif /* USART_H_ */