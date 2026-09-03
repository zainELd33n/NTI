#include "../../SERVICE/std_type.h"
#include "../../SERVICE/bit_math.h"
#include "../../MCAL/DIO/DIO_int.h"


#define ROW0 0
#define ROW1 1


void LCD_init();

void LCD_sendChar(u8 data);

void LCD_sendCommand(u8 command);

void LCD_sendString(u8 *str);

void LCD_goToXY(u8 x, u8 y);

void LCD_sendNum(s32 num);