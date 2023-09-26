/*
 * File Name --> FMI_Private.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> FMI driver private info like addresses.
 * */

#ifndef HMCAL_FMI_FMI_PRIVATE_H_
#define HMCAL_FMI_FMI_PRIVATE_H_

/*
==================================================
  Start Section --> File Includes
==================================================
*/
#include "LIB/STD_TYPES.h"
/*
==================================================
  End   Section --> File Includes
==================================================
*/

/*
==================================================
  Start Section --> Define peripheral addresses.
==================================================
*/
#define			FMI_BASE_ADDRESS		0x40023C00
/*
==================================================
  End   Section --> Define peripheral addresses.
==================================================
*/

/*
==================================================
  Start Section --> Macro Declaration
==================================================
*/
#define			FMI_FPEC_KEY1				0x45670123u
#define			FMI_FPEC_KEY2				0xCDEF89ABu

#define			FMI_OPTKEY1					0x08192A3Bu
#define			FMI_OPTKEY2					0x4C5D6E7Fu

/*
==================================================
  End   Section --> Macro Declaration
==================================================
*/

/*
==================================================
  Start Section --> Reset values.
==================================================
*/
#define FMI_ACR_RESET_VALUE				0x00
#define FMI_KEYR_RESET_VALUE			0x00
#define FMI_OPTKEYR_RESET_VALUE			0x00
#define FMI_SR_RESET_VALUE				0x00
#define FMI_CR_RESET_VALUE				0x80000000
#define FMI_OPTCR_RESET_VALUE			0x0FFFAAED

/*
==================================================
  End Section --> Reset values.
==================================================
*/

/*
==================================================
  Start Section --> Peripheral register mapping.
==================================================
*/
typedef struct {
	/*Flash access control register (FLASH_ACR)*/
	volatile u32 ACR;
	/*Flash key register (FLASH_KEYR)*/
	volatile u32 KEYR;
	/*Flash option key register (FLASH_OPTKEYR)*/
	volatile u32 OPTKEYR;
	/*Flash status register (FLASH_SR)*/
	volatile u32 SR;
	/*Flash control register (FLASH_CR)*/
	volatile u32 CR;
	/*Flash option control register (FLASH_OPTCR)*/
	volatile u32 OPTCR;
}FMI_MemMap;
/*
==================================================
  End   Section --> Peripheral register mapping.
==================================================
*/

/*
==================================================
  Start Section --> Define peripheral with it's address.
==================================================
*/

const static u32 GCS_FMI_InstanceIdMapping_u32[]={
		FMI_BASE_ADDRESS,
};
/*
==================================================
  End Section --> Define peripheral with it's address.
==================================================
*/

#endif /* HMCAL_FMI_FMI_PRIVATE_H_ */
