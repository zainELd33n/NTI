#include "../../SERVICE/std_type.h"
#include "../../SERVICE/bit_math.h"
#include "../../MCAL/DIO/DIO_int.h"

#include "Sev_Seg_int.h"
#include "Sev_Seg_config.h"

u8 SevSeg_Numbers[10] = {
	0x3F, // 0
	0x06, // 1
	0x5B, // 2
	0x4F, // 3
	0x66, // 4
	0x6D, // 5
	0x7D, // 6
	0x07, // 7
	0x7F, // 8
	0x6F  // 9
};

void SevSegment_SetValue(u8 Num)
{
	if (Num < 10)
	{
		DIO_SetPortValue(SEV_SEG_PORT, SevSeg_Numbers[Num]);
	}
}