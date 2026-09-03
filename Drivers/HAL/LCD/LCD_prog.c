#define F_CPU 1000000
#include "LCD_int.h"
#include "../../SERVICE/std_type.h"
#include "../../SERVICE/bit_math.h"
#include "../../MCAL/DIO/DIO_int.h"
#include <util/delay.h>
#include <stdlib.h>


void LCD_sendCommand(u8 command) {
	DIO_SetPinValue(DIO_PORTD, PIN0, PIN_LOW);

	DIO_SetPinValue(DIO_PORTD, PIN1, PIN_LOW);

	DIO_SetPortValue(DIO_PORTC, command);
	
	DIO_SetPinValue(DIO_PORTD, PIN2, PIN_HIGH);
	_delay_us(2);
	
	DIO_SetPinValue(DIO_PORTD, PIN2, PIN_LOW);
}

void LCD_init(void) {
	DIO_SetPortDirection(DIO_PORTC, OUTPUT);
	DIO_SetPinDirection(DIO_PORTD, PIN0, OUTPUT);
	DIO_SetPinDirection(DIO_PORTD, PIN1, OUTPUT);
	DIO_SetPinDirection(DIO_PORTD, PIN2, OUTPUT);
	_delay_ms(50);
	
	LCD_sendCommand(0x38);
	_delay_us(40);
	
	LCD_sendCommand(0x0C);
	_delay_us(40);
	
	LCD_sendCommand(0x01);
	_delay_ms(2);
	
	LCD_sendCommand(0x06);
}

void LCD_sendChar(u8 data) {
	DIO_SetPinValue(DIO_PORTD, PIN0, PIN_HIGH);
	DIO_SetPinValue(DIO_PORTD, PIN1, PIN_LOW);
	
	DIO_SetPortValue(DIO_PORTC, data);
	
	DIO_SetPinValue(DIO_PORTD, PIN2, PIN_HIGH);
	_delay_us(2);
	DIO_SetPinValue(DIO_PORTD, PIN2, PIN_LOW);
	
	_delay_us(50);
}

void LCD_sendString(u8 *str) {
	while (*str != '\0')
	{
		LCD_sendChar(*str);
		str++;
	}
}

void LCD_sendNum(s32 num) {
	u8 buffer[12];
	
	itoa(num, buffer, 10);
	
	LCD_sendString((u8*)buffer);
}

void LCD_goToXY(u8 x, u8 y) {
	u8 final = 0;
	if(x == 0) x = 0x00;
	if(x == 1) x = 0x40;
	if(y < 16) {
		final = x + (y - 1);
		LCD_sendCommand(0x80 + final);
	}
	
}