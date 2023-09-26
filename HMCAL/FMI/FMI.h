/*
 * File Name --> FMI.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> Provides API and available configuration options for FMI peripheral.
 * */

#ifndef HMCAL_FMI_FMI_H_
#define HMCAL_FMI_FMI_H_
/*
==================================================
  Start Section --> File Includes
==================================================
*/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
/*
==================================================
  End   Section --> File Includes
==================================================
*/

/*
==================================================
  Start Section --> APIs
==================================================
*/

/* @brief  --> This function writes 1-byte value on flash.
 * for e.g to write 0xAB on Flash address 0x08000000
 * FMI_FlashWriteU8Data_v(0x08000000, 0xAB);
 * @param  Arg_Address_Cu32 --> address that you want to write on.
 * @param  Arg_Data_Cu8 --> data that you write on address given in param  Arg_Address_Cu32.
 * @retval --> None.
 * */
void FMI_FlashWriteU8Data_v(const u32 Arg_Address_Cu32, const u16 Arg_Data_Cu8);

/* @brief  --> This function writes 2-bytes value on flash.
 * for e.g to write 0xABCD on Flash address 0x08000000
 * FMI_FlashWriteU16Data_v(0x08000000, 0xABCD);
 * @param  Arg_Address_Cu32 --> address that you want to write on.
 * @param  Arg_Data_u16 --> data that you write on address given in param  Arg_Address_Cu32.
 * @retval --> None.
 * */
void FMI_FlashWriteU16Data_v(const u32 Arg_Address_Cu32, const u16 Arg_Data_Cu16);

/* @brief  --> This function writes 4-bytes value on flash.
 * for e.g to write 0xABCD1234 on Flash address 0x08000000
 * FMI_FlashWriteU32Data_v(0x08000000, 0xABCD1234);
 * @param  Arg_Address_Cu32 --> Dddress that you want to write on.
 * @param  Arg_Data_u16 --> Data that you write on address given in param  Arg_Address_Cu32.
 * @retval --> None.
 * */
void FMI_FlashWriteU32Data_v(const u32 Arg_Address_Cu32, const u32 Arg_Data_Cu32);


/* @brief  --> This function erases specific section of flash.
 * for e.g to erase sector number 1
 * FMI_EraseFlashSector_v(1);
 * @param  Arg_SectorNumber_u8 --> input sector number that you want to erase
 * @retval --> None.
 * */
void FMI_EraseFlashSector_v(const u16 Arg_SectorNumber_Cu16);
/*
==================================================
  End   Section --> APIs
==================================================
*/
#endif /* HMCAL_FMI_FMI_H_ */
