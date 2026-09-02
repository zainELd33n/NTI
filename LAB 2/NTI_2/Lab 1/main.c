/*
 * NTI_2.c
 *
 * Created: 9/2/2026 6:56:54 PM
 * Author : Zain
 */ 

#include <avr/io.h>
#include "Drivers/SERVICE/std_type.h"
#include "Drivers/SERVICE/bit_math.h"

int main(void)
{
	DDRA = 0b00000010;
	
    while (1)
    {
		if(GET_BIT(PINA, 0) == 0){
			PORTA = 0b00000010;
		} else {
			PORTA = 0b00000000;	
		}	
    }
}

