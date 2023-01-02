/*
 * LCD.h
 *
 * Created: 7/31/2022 9:49:46 AM
 *  Author: bedoa
 */ 


#ifndef LCD_H_
#define LCD_H_

void LCD_CMD(DIO_Channel lcdpins[], char cmd);
void LCD_INIT(DIO_Channel lcdpins[]);
void LCD_PRINT_CHAR(DIO_Channel lcdpins[], char letter);

void LCD_PRINT_STR(DIO_Channel lcdpins[],char* data);
void curpos(DIO_Channel lcdpins[],unsigned char x_position, unsigned char y_position);

#endif /* LCD_H_ */