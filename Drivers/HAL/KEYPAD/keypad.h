#include "../../SERVICE/std_type.h"
#include "../../SERVICE/bit_math.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../../HAL/LCD/LCD_int.h"

u8 keys[4][4] = {
	{'/', '9', '8', '7'},
	{'x', '6', '5', '4'},
	{'-', '3', '2', '1'},
	{'+', '=', '0', 'C'}
};


void keypad_init(u8 port);

void keypad_keyPressed(u8 port);