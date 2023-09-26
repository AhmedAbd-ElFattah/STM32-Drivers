/*
 * File Name --> CRC.c
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> LIB
 * Brief	 --> Implementation for CRC.
 * */

/*
==================================================
  Start Section --> File Includes
==================================================
 */
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "CRC.h"
/*
==================================================
  End   Section --> File Includes
==================================================
 */


/*
==================================================
  Start Section --> Function implementation
==================================================
 */
u8 CRC_CalculateCRC8_u8(
		u8 *Arg_data_u8,
		u32 Arg_Length_u32,
		u8 Arg_Polynomial_u8,
		u8 Arg_CRCInitialValue_u8,
		u8 Arg_FinalXORValue_u8,
		u8 Arg_ReverseInput_u8,
		u8 Arg_ReverseOutput_u8)
{

	u8 Local_CRC_u8 = Arg_CRCInitialValue_u8;
	u8 Local_Mask_u8 = 0xFF;  // 8-bit mask

	if (Arg_ReverseInput_u8) {
		for (u32 Local_i_u32 = 0; Local_i_u32 < Arg_Length_u32; Local_i_u32++) {
			u8 Local_Byte_u8 = Arg_data_u8[Local_i_u32];
			for (u32 Local_j_u32 = 0; Local_j_u32 < 8; Local_j_u32++) {
				Local_CRC_u8 = (Local_CRC_u8 >> 1) | ((Local_Byte_u8 & 0x01) << 7);
				Local_Byte_u8 >>= 1;
			}
		}
	}


	for (u32 Local_i_u32 = 0; Local_i_u32 < Arg_Length_u32; Local_i_u32++) {
		if (Arg_ReverseInput_u8){
			u8 idx = (Arg_Length_u32-1) - Local_i_u32;
			u8 temp = Arg_data_u8[idx];
			Local_CRC_u8 ^= temp;
		}
		else{
			Local_CRC_u8 ^= Arg_data_u8[Local_i_u32];
		}

		for (u32 Local_j_u32 = 0; Local_j_u32 < 8; Local_j_u32++) {
			if (Local_CRC_u8 & 0x80) {
				Local_CRC_u8 = ((Local_CRC_u8 << 1) ^ Arg_Polynomial_u8) & Local_Mask_u8;
			}
			else {
				Local_CRC_u8 = (Local_CRC_u8 << 1) & Local_Mask_u8;
			}
		}
	}

	if (Arg_ReverseOutput_u8) {
		u8 Local_Reversed_u8 = 0;
		for (u32 Local_i_u32 = 0; Local_i_u32 < 8; Local_i_u32++){
			Local_Reversed_u8 |= (( Local_CRC_u8 >> Local_i_u32 ) &0x01 ) <<(7-Local_i_u32);
		}
		Local_CRC_u8 = Local_Reversed_u8;
	}

	return Local_CRC_u8 ^ Arg_FinalXORValue_u8;
}

/*
==================================================
  End   Section --> Function implementation
==================================================
 */

