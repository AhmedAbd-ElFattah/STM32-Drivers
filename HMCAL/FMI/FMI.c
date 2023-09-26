/*
 * File Name --> FMI.c
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> FMI driver implementation.
 * */


/*
==================================================
  Start Section --> File Includes
==================================================
*/
#include "FMI_defs.h"
#include "FMI_Private.h"
#include "FMI.h"
/*
==================================================
  End   Section --> File Includes
==================================================
*/

/*
==================================================
  Start Section --> Macro to map Instance Id with it's physical address.
==================================================
 */
#define FMI_ID(id) ((volatile FMI_MemMap*const)(GCS_FMI_InstanceIdMapping_u32[((id)-1)]))
/*
==================================================
  End   Section --> Macro to map Instance Id with it's physical address.
==================================================
 */

/*
==================================================
  Start Section --> Functions implementation.
==================================================
*/
void FMI_FlashWriteU8Data_v(const u32 Arg_Address_Cu32, const u16 Arg_Data_Cu8){
	/*Wait till flash is not busy.*/
	while(STD_TRUE == GET_BIT(FMI_ID(1)->SR, FMI_SR_BSY)){

	}

	/*Unlock Flash Register using KEYR*/
	if (STD_TRUE == GET_BIT(FMI_ID(1)->CR, FMI_CR_LOCK)){
		FMI_ID(1)->KEYR = FMI_FPEC_KEY1;
		FMI_ID(1)->KEYR = FMI_FPEC_KEY2;
	}
	else{

	}

	/*Select Data Size*/
	CLEAR_BIT(FMI_ID(1)->CR, FMI_CR_PSIZE_0);
	CLEAR_BIT(FMI_ID(1)->CR, FMI_CR_PSIZE_1);

	/*Activate Programming Mode*/
	SET_BIT(FMI_ID(1)->CR, FMI_CR_PG);

	/*Write data on Flash Address*/
	*(( volatile u16*)Arg_Address_Cu32) = Arg_Data_Cu8;

	/*Wait for busy flag.*/
	while(STD_TRUE == GET_BIT(FMI_ID(1)->SR, FMI_SR_BSY)){

	}

	/*Deactivate programming mode.*/
	CLEAR_BIT(FMI_ID(1)->CR, FMI_CR_PG);

}

void FMI_FlashWriteU16Data_v(const u32 Arg_Address_Cu32, const u16 Arg_Data_Cu16){
	/*Wait till flash is not busy.*/
	while(STD_TRUE == GET_BIT(FMI_ID(1)->SR, FMI_SR_BSY)){

	}

	/*Unlock Flash Register using KEYR*/
	if (STD_TRUE == GET_BIT(FMI_ID(1)->CR, FMI_CR_LOCK)){
		FMI_ID(1)->KEYR = FMI_FPEC_KEY1;
		FMI_ID(1)->KEYR = FMI_FPEC_KEY2;
	}
	else{

	}

	/*Select Data Size*/
	SET_BIT(FMI_ID(1)->CR, FMI_CR_PSIZE_0);
	CLEAR_BIT(FMI_ID(1)->CR, FMI_CR_PSIZE_1);

	/*Activate Programming Mode*/
	SET_BIT(FMI_ID(1)->CR, FMI_CR_PG);

	/*Write data on Flash Address*/
	*(( volatile u16*)Arg_Address_Cu32) = Arg_Data_Cu16;

	/*Wait for busy flag.*/
	while(STD_TRUE == GET_BIT(FMI_ID(1)->SR, FMI_SR_BSY)){

	}

	/*Deactivate programming mode.*/
	CLEAR_BIT(FMI_ID(1)->CR, FMI_CR_PG);

}

void FMI_FlashWriteU32Data_v(const u32 Arg_Address_Cu32, const u32 Arg_Data_Cu32){
	/*Wait till flash is not busy.*/
	while(STD_TRUE == GET_BIT(FMI_ID(1)->SR, FMI_SR_BSY)){

	}

	/*Unlock Flash Register using KEYR*/
	if (STD_TRUE == GET_BIT(FMI_ID(1)->CR, FMI_CR_LOCK)){
		FMI_ID(1)->KEYR = FMI_FPEC_KEY1;
		FMI_ID(1)->KEYR = FMI_FPEC_KEY2;
	}
	else{

	}

	/*Select Data Size*/
	CLEAR_BIT(FMI_ID(1)->CR, FMI_CR_PSIZE_0);
	SET_BIT(FMI_ID(1)->CR, FMI_CR_PSIZE_1);

	/*Activate Programming Mode*/
	SET_BIT(FMI_ID(1)->CR, FMI_CR_PG);

	/*Write data on Flash Address*/
	*(( volatile u32*)Arg_Address_Cu32) = Arg_Data_Cu32;

	/*Wait for busy flag.*/
	while(STD_TRUE == GET_BIT(FMI_ID(1)->SR, FMI_SR_BSY)){

	}

	/*Deactivate programming mode.*/
	CLEAR_BIT(FMI_ID(1)->CR, FMI_CR_PG);
}

void FMI_EraseFlashSector_v(const u16 Arg_SectorNumber_Cu16)
{
	/*Wait till flash is not busy.*/
	while(STD_TRUE == GET_BIT(FMI_ID(1)->SR, FMI_SR_BSY)){

	}

	/*Unlock Flash Register using KEYR*/
	if (STD_TRUE == GET_BIT(FMI_ID(1)->CR, FMI_CR_LOCK)){
		FMI_ID(1)->KEYR = FMI_FPEC_KEY1;
		FMI_ID(1)->KEYR = FMI_FPEC_KEY2;
	}
	else{

	}
	/*Select sector number to erase.*/
	FMI_ID(1)->CR &=~(0b1111u<<3);
	FMI_ID(1)->CR |= (Arg_SectorNumber_Cu16<<3);

	/*Select Erase operation.*/
	SET_BIT(FMI_ID(1)->CR, FMI_CR_SER);

	/*Start Erase operation.*/
	SET_BIT(FMI_ID(1)->CR, FMI_CR_STRT);

	/*Wait till flash is not busy.*/
	while(STD_TRUE == GET_BIT(FMI_ID(1)->SR, FMI_SR_BSY)){

	}

	/*Clear EOP flag.*/
	SET_BIT(FMI_ID(1)->SR, FMI_SR_EOP);

	/*Deactivate Erase operation.*/
	CLEAR_BIT(FMI_ID(1)->CR, FMI_CR_SER);

}
/*
==================================================
  End   Section --> Functions implementation.
==================================================
*/
