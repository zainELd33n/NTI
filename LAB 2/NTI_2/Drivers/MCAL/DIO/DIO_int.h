#include "../../SERVICE/std_type.h"

#ifndef DIO_INT_H
#define DIO_INT_H

#define INPUT               0
#define OUTPUT              1

#define DIO_PORTA           0
#define DIO_PORTB           1
#define DIO_PORTC           2
#define DIO_PORTD           3

#define PIN0            0
#define PIN1            1
#define PIN2            2
#define PIN3            3
#define PIN4            4
#define PIN5            5
#define PIN6            6
#define PIN7            7

#define PIN_INPUT       0
#define PIN_OUTPUT      1

#define PORT_INPUT      0x00
#define PORT_OUTPUT     0xFF

#define PIN_LOW         0
#define PIN_HIGH        1

#define PORT_LOW        0x00
#define PORT_HIGH       0xFF

void DIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction);
void DIO_SetPinValue(u8 Port, u8 Pin, u8 Value);

u8   DIO_GetPinValue(u8 Port, u8 Pin);
void DIO_TogglePinValue(u8 Port, u8 Pin);

void DIO_SetPortDirection(u8 Port, u8 Direction);
void DIO_SetPortValue(u8 Port, u8 Value);

#endif