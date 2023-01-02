/*
 * LCD8.h
 *
 * Created: 7/31/2022 1:44:21 PM
 *  Author: bedoa
 */ 


#ifndef LCD8_H_
#define LCD8_H_

void LCD_INIT8(DIO_PORT dataport,DIO_Channel ctrlpins[]);
void LCD_CMD8(DIO_PORT dataport,DIO_Channel ctrlpins[],char cmd);
void LCD_PRINT_CHAR8(DIO_PORT dataport,DIO_Channel ctrlpins[],char letter);




#endif /* LCD8_H_ */