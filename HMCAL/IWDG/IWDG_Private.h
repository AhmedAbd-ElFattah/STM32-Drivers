/*
 * File Name --> IWDG_Private.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> IWDG driver private info like addresses.
 * */

#ifndef HMCAL_IWDG_IWDG_PRIVATE_H_
#define HMCAL_IWDG_IWDG_PRIVATE_H_

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
  Start Section --> Peripherals base addresses.
==================================================
*/
#define 		IWDG_BASE_ADDRESS		0x40003000

/*
==================================================
  End   Section --> Peripherals base addresses.
==================================================
*/

/*
==================================================
  Start Section --> Reset values.
==================================================
*/
#define IWDG_KR_RESET_VALUE					0x00
#define IWDG_PR_RESET_VALUE					0x00
#define IWDG_RLR_RESET_VALUE				0x00000FFF
#define IWDG_SR_RESET_VALUE					0x00
/*
==================================================
  End Section --> Reset values.
==================================================
*/

/*
==================================================
  Start Section --> Macro definition.
==================================================
*/
#define	IWDG_ENABLE_ACCESS	0x5555
#define IWDG_START_KEY		0xCCCC
#define IWDG_REFRESH_KEY	0xAAAA
/*
==================================================
  End Section --> Macro definition.
==================================================
*/


/*
==================================================
  Start Section --> Peripheral register mapping.
==================================================
*/
typedef struct {
	/*Key register.*/
	volatile u32 KR;
	/*Prescaler register.*/
	volatile u32 PR;
	/*Reload Register.*/
	volatile u32 RLR;
	/*Status Register*/
	volatile u32 SR;
}IWDG_MemMap;
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

#define IWDG	((volatile IWDG_MemMap* const)(IWDG_BASE_ADDRESS))
/*
==================================================
  End Section --> Define peripheral with it's address.
==================================================
*/


#endif /* HMCAL_IWDG_IWDG_PRIVATE_H_ */
