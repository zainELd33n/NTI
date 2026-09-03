#ifndef BIT_MATH_H
#define BIT_MATH_H

#define Set_bit(Reg, BIT_NUM)    ((Reg) |=  (1 << (BIT_NUM)))
#define Clr_bit(Reg, BIT_NUM)    ((Reg) &= ~(1 << (BIT_NUM)))
#define Tog_bit(Reg, BIT_NUM)    ((Reg) ^=  (1 << (BIT_NUM)))
#define Get_bit(Reg, BIT_NUM)    (((Reg) >> (BIT_NUM)) & 1)

#endif