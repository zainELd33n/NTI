#include "keypad.h"

void keypad_init(u8 port) {
	DIO_SetPinDirection(port, PIN0, OUTPUT); DIO_SetPinValue(port, PIN0, PIN_HIGH);
	DIO_SetPinDirection(port, PIN1, OUTPUT); DIO_SetPinValue(port, PIN1, PIN_HIGH);
	DIO_SetPinDirection(port, PIN2, OUTPUT); DIO_SetPinValue(port, PIN2, PIN_HIGH);
	DIO_SetPinDirection(port, PIN3, OUTPUT); DIO_SetPinValue(port, PIN3, PIN_HIGH);

	DIO_SetPinDirection(port, PIN4, INPUT);  DIO_SetPinValue(port, PIN4, PIN_HIGH);
	DIO_SetPinDirection(port, PIN5, INPUT);  DIO_SetPinValue(port, PIN5, PIN_HIGH);
	DIO_SetPinDirection(port, PIN6, INPUT);  DIO_SetPinValue(port, PIN6, PIN_HIGH);
	DIO_SetPinDirection(port, PIN7, INPUT);  DIO_SetPinValue(port, PIN7, PIN_HIGH);
}

void keypad_keyPressed(u8 port){
	
	u8 row[4] = {PIN0, PIN1, PIN2, PIN3};
	u8 pressedKey = 0;
	
	for (u8 i = 0; i < 4; i++) {
		DIO_SetPinValue(port, row[i], 0);
		if(DIO_GetPinValue(port, PIN4) == PIN_LOW){
			pressedKey = keys[i][3];
			if (pressedKey == keys[3][3])
			{
				LCD_sendCommand(0x01);
			}else LCD_sendChar(pressedKey);
			
			while (DIO_GetPinValue(port, PIN4) == PIN_LOW);
		}
		if(DIO_GetPinValue(port, PIN5) == PIN_LOW){
			pressedKey = keys[i][2];
			LCD_sendChar(pressedKey);
			while (DIO_GetPinValue(port, PIN5) == PIN_LOW);
		}
		if(DIO_GetPinValue(port, PIN6) == PIN_LOW){
			pressedKey = keys[i][1];
			LCD_sendChar(pressedKey);
			while (DIO_GetPinValue(port, PIN6) == PIN_LOW);
		}
		if(DIO_GetPinValue(port, PIN7) == PIN_LOW){
			pressedKey = keys[i][0];
			LCD_sendChar(pressedKey);
			while (DIO_GetPinValue(port, PIN7) == PIN_LOW);
		}
		DIO_SetPinValue(port, row[i], PIN_HIGH);
	}
}

