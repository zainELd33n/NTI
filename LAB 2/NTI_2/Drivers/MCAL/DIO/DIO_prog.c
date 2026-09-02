#include "../../SERVICE/bit_math.h"
#include "../../SERVICE/std_type.h"

#include "DIO_int.h"
#include "DIO_private.h"
#include "DIO_config.h"

void DIO_SetPinDirection(u8 port, u8 pin, u8 direction)
{
	if (direction == PIN_OUTPUT)
	{
		switch (port)
		{
			case DIO_PORTA: Set_bit(DDRA_REG, pin); break;
			case DIO_PORTB: Set_bit(DDRB_REG, pin); break;
			case DIO_PORTC: Set_bit(DDRC_REG, pin); break;
			case DIO_PORTD: Set_bit(DDRD_REG, pin); break;
		}
	}
	else if (direction == PIN_INPUT)
	{
		switch (port)
		{
			case DIO_PORTA: Clr_bit(DDRA_REG, pin); break;
			case DIO_PORTB: Clr_bit(DDRB_REG, pin); break;
			case DIO_PORTC: Clr_bit(DDRC_REG, pin); break;
			case DIO_PORTD: Clr_bit(DDRD_REG, pin); break;
		}
	}
}

void DIO_SetPinValue(u8 port, u8 pin, u8 value)
{
	if (value == PIN_HIGH)
	{
		switch (port)
		{
			case DIO_PORTA: Set_bit(PORTA_REG, pin); break;
			case DIO_PORTB: Set_bit(PORTB_REG, pin); break;
			case DIO_PORTC: Set_bit(PORTC_REG, pin); break;
			case DIO_PORTD: Set_bit(PORTD_REG, pin); break;
		}
	}
	else if (value == PIN_LOW)
	{
		switch (port)
		{
			case DIO_PORTA: Clr_bit(PORTA_REG, pin); break;
			case DIO_PORTB: Clr_bit(PORTB_REG, pin); break;
			case DIO_PORTC: Clr_bit(PORTC_REG, pin); break;
			case DIO_PORTD: Clr_bit(PORTD_REG, pin); break;
		}
	}
}

u8 DIO_GetPinValue(u8 port, u8 pin)
{
	u8 pin_state = 0;

	switch (port)
	{
		case DIO_PORTA: pin_state = Get_bit(PINA_REG, pin); break;
		case DIO_PORTB: pin_state = Get_bit(PINB_REG, pin); break;
		case DIO_PORTC: pin_state = Get_bit(PINC_REG, pin); break;
		case DIO_PORTD: pin_state = Get_bit(PIND_REG, pin); break;
	}

	return pin_state;
}

void DIO_TogglePinValue(u8 port, u8 pin)
{
	switch (port)
	{
		case DIO_PORTA: Tog_bit(PORTA_REG, pin); break;
		case DIO_PORTB: Tog_bit(PORTB_REG, pin); break;
		case DIO_PORTC: Tog_bit(PORTC_REG, pin); break;
		case DIO_PORTD: Tog_bit(PORTD_REG, pin); break;
	}
}

void DIO_SetPortDirection(u8 port, u8 direction)
{
	switch (port)
	{
		case DIO_PORTA: DDRA_REG = direction; break;
		case DIO_PORTB: DDRB_REG = direction; break;
		case DIO_PORTC: DDRC_REG = direction; break;
		case DIO_PORTD: DDRD_REG = direction; break;
	}
}

void DIO_SetPortValue(u8 port, u8 value)
{
	switch (port)
	{
		case DIO_PORTA: PORTA_REG = value; break;
		case DIO_PORTB: PORTB_REG = value; break;
		case DIO_PORTC: PORTC_REG = value; break;
		case DIO_PORTD: PORTD_REG = value; break;
	}
}