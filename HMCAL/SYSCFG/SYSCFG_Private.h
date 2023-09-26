/*
 * File Name --> SYSCFG_Private.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> SYSCFG driver private info like addresses.
 * */

#ifndef HMCAL_SYSCFG_SYSCFG_PRIVATE_H_
#define HMCAL_SYSCFG_SYSCFG_PRIVATE_H_

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
#define 		SYSCFG_BASE_ADDRESS            		0x40013800
/*
==================================================
  End   Section --> Define peripheral addresses.
==================================================
*/

/*
==================================================
  Start Section --> Reset values.
==================================================
 */
#define SYSCFG_MEMRMP_RESET_VALUE			0x0000
#define SYSCFG_PMC_RESET_VALUE				0x0000
#define SYSCFG_EXTICR_RESET_VALUE			0x0000
#define SYSCFG_CMPCR_RESET_VALUE			0x0000
#define SYSCFG_CFGR_RESET_VALUE				0x0000
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
	/*SYSCFG memory remap register.*/
	volatile u32 MEMRMP;
	/*SYSCFG peripheral mode configuration register.*/
	volatile u32 PMC;
	/*SYSCFG external interrupt configuration register.*/
	volatile u32 EXTICR[4];
	volatile u32 RESERVED_0[2];
	/*SYSCFG memory remap register.*/
	volatile u32 CMPCR;
}SYSCFG_MemMap;
/*
==================================================
  End Section --> Peripheral register mapping.
==================================================
*/

/*
==================================================
  Start Section --> Define peripheral with it's address.
==================================================
 */
#define 		SYSCFG		((volatile SYSCFG_MemMap* const)(SYSCFG_BASE_ADDRESS))

/*
==================================================
  End Section --> Define peripheral with it's address.
==================================================
 */

#endif /* HMCAL_SYSCFG_SYSCFG_PRIVATE_H_ */
