/*
 * File Name --> SCB_Private.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> LMCAL
 * Brief	 --> System Control Block driver defines.
 * */
#ifndef LMCAL_SCB_SCB_PRIVATE_H_
#define LMCAL_SCB_SCB_PRIVATE_H_

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
#define			SCB_BASE_ADDRESS		0xE000ED00
/*
==================================================
  End   Section --> Define peripheral addresses.
==================================================
 */

/*
==================================================
  Start Section --> Peripheral register structure.
==================================================
 */

typedef struct {
	u32 CPUID;
	u32 ICSR;
	u32 VTOR;
	u32 AIRCR;
	u32 SCR;
	u32 CCR;
	u32 SHPR1;
	u32 SHPR2;
	u32 SHPR3;
	u32 SHCSR;
	u32 CFSR;
	u32 HFSR;
	u32 DFSR;
	u32 MMAR;
	u32 BFAR;
	u32 AFSR;
}SCB_MemMap;

/*
==================================================
  End Section -->   Peripheral register structure.
==================================================
 */

#endif /* LMCAL_SCB_SCB_PRIVATE_H_ */
