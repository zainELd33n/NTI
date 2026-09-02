/*
 * NTI_2.c
 *
 * Created: 9/2/2026 6:56:54 PM
 * Author : Zain
 */ 

#include <avr/io.h>
#include "Drivers/SERVICE/std_type.h"
#include "Drivers/SERVICE/bit_math.h"
#include "Drivers/MCAL/DIO/DIO_int.h"

int main(void)
{
	DIO_SetPortDirection(DIO_PORTA, INPUT);
    DIO_SetPortValue(DIO_PORTA, 0xFF);
	DIO_SetPortDirection(DIO_PORTC, 0xFF);
	
    while (1)
    {
		u8 s1 = DIO_GetPinValue(DIO_PORTA, PIN0);
		u8 s2 = DIO_GetPinValue(DIO_PORTA, PIN1);
		u8 s3 = DIO_GetPinValue(DIO_PORTA, PIN2);
		u8 s8 = DIO_GetPinValue(DIO_PORTA, PIN7);
		
		if (s8 == 0) {
			DIO_SetPinValue(DIO_PORTC, PIN0, 1);
			DIO_SetPinValue(DIO_PORTC, PIN1, 1);
			DIO_SetPinValue(DIO_PORTC, PIN2, 1);
		} else {
			DIO_SetPinValue(DIO_PORTC, PIN0, !s1);
			DIO_SetPinValue(DIO_PORTC, PIN1, !s2);
			DIO_SetPinValue(DIO_PORTC, PIN2, !s3);
		}
		
	}
}

