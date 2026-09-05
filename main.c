/*
 * NTI 3.c
 *
 * Created: 9/3/2026 6:40:49 PM
 * Author : Zain
 */ 
#define F_CPU 1000000
#include <avr/io.h>
#include "../../Drivers/HAL/LCD/LCD_int.h"
#include "../../Drivers/MCAL/DIO/DIO_int.h"
#include "../../Drivers/SERVICE/std_type.h"
#include "Drivers/HAL/Stepper/Stepper.h"
#include <util/delay.h>

/* Stepper motor 
int main() {
	//Stepper_half_clkWise(DIO_PORTC);
	//Stepper_half_anticlkWise(DIO_PORTC);
	//Stepper_full_clkWise(DIO_PORTC);
	Stepper_full_anticlkWise(DIO_PORTC);
	while(1) 
	{
		
	}
}
*/

/* H-bridge code
int main() {
	DIO_SetPinDirection(DIO_PORTB, PIN0, OUTPUT);
	DIO_SetPinDirection(DIO_PORTB, PIN1, OUTPUT);
	DIO_SetPinDirection(DIO_PORTB, PIN2, OUTPUT);
	DIO_SetPinDirection(DIO_PORTB, PIN3, OUTPUT);
	DIO_SetPortValue(DIO_PORTB, PIN_LOW);
	
	while(1)
	{
		DIO_SetPinValue(DIO_PORTB, PIN0, PIN_HIGH);
		DIO_SetPinValue(DIO_PORTB, PIN1, PIN_HIGH);
		DIO_SetPinValue(DIO_PORTB, PIN2, PIN_LOW);
		DIO_SetPinValue(DIO_PORTB, PIN3, PIN_LOW);
		_delay_ms(3000);
		
		DIO_SetPinValue(DIO_PORTB, PIN0, PIN_LOW);
		DIO_SetPinValue(DIO_PORTB, PIN1, PIN_LOW);
		_delay_ms(700);
		
		DIO_SetPinValue(DIO_PORTB, PIN2, PIN_HIGH);
		DIO_SetPinValue(DIO_PORTB, PIN3, PIN_HIGH);
		DIO_SetPinValue(DIO_PORTB, PIN0, PIN_LOW);
		DIO_SetPinValue(DIO_PORTB, PIN1, PIN_LOW);
		_delay_ms(3000);
		
		DIO_SetPinValue(DIO_PORTB, PIN2, PIN_LOW);
		DIO_SetPinValue(DIO_PORTB, PIN3, PIN_LOW);
		_delay_ms(700);
	}
}
*/

/* Electronic switch controlling a motor
int main()
{
	
	DIO_SetPinDirection(DIO_PORTB, PIN0, OUTPUT);
    while (1) 
    {
		DIO_SetPinValue(DIO_PORTB, PIN0, PIN_HIGH);
		_delay_ms(1000);
		DIO_SetPinValue(DIO_PORTB, PIN0, PIN_LOW);
		_delay_ms(1000);
    }
}

*/

/* keypad testing
	s16 num1 = 0, num2 = 0, result = 0;
	u8 op = 0;
	
	LCD_init();
	keypad_init(DIO_PORTA);
 
	LCD_sendNum(123);
	LCD_goToXY(1, 3);
	LCD_sendString("ZainELdeen");
*/