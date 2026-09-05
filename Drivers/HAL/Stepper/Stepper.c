#define F_CPU 1000000UL
#include "../../SERVICE/std_type.h"
#include "../../MCAL/DIO/DIO_int.h"
#include <util/delay.h>

void Stepper_half_clkWise(u8 port) {
	u8 half_step_sequence[8] = {
		0b00000011,
		0b00000010,
		0b00000110,
		0b00000100,
		0b00001100,
		0b00001000,
		0b00001001,
		0b00000001
	};
	
	DIO_SetPortDirection(port, OUTPUT);
	
	for (u8 i = 0; i < 8; i++)
	{
		DIO_SetPortValue(port, half_step_sequence[i]);
		_delay_ms(1000);
	}
	DIO_SetPortValue(port, 0b00000011);
}

void Stepper_half_anticlkWise(u8 port) {
	u8 half_step_sequence[8] = {
		0b00000011,
		0b00000010,
		0b00000110,
		0b00000100,
		0b00001100,
		0b00001000,
		0b00001001,
		0b00000001
	};
	
	DIO_SetPortDirection(port, OUTPUT);
	
	for (s8 i = 7; i >= 0; i--)
	{
		DIO_SetPortValue(port, half_step_sequence[i]);
		_delay_ms(1000);
	}
	DIO_SetPortValue(port, 0b00000011);
}

void Stepper_full_clkWise(u8 port) {
	u8 half_step_sequence[8] = {
		0b00000011,
		0b00000110,
		0b00001100,
		0b00001001,
		0b00000011
	};
	
	DIO_SetPortDirection(port, OUTPUT);
	
	for (u8 i = 0; i < 5; i++)
	{
		DIO_SetPortValue(port, half_step_sequence[i]);
		_delay_ms(1000);
	}
}

void Stepper_full_anticlkWise(u8 port) {
	u8 half_step_sequence[8] = {
		0b00000011,
		0b00000110,
		0b00001100,
		0b00001001,
		0b00000011
	};
	
	DIO_SetPortDirection(port, OUTPUT);
	
	for (s8 i = 5; i >= 0; i--)
	{
		DIO_SetPortValue(port, half_step_sequence[i]);
		_delay_ms(1000);
	}
}