/*
 * File Name --> SYSTICK_Private.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> LMCAL
 * Brief	 --> SYSTICK driver private info like addresses.
 * */

#ifndef LMCAL_SYSTICK_SYSTICK_PRIVATE_H_
#define LMCAL_SYSTICK_SYSTICK_PRIVATE_H_

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
#define			SYSTICK_BASE_ADDRESS		0xE000E010
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
	u32 CSR;
	u32 RVR;
	u32 CVR;
	u32 CALIB;
}SYSTICK_MemMap;

/*
==================================================
  End Section -->   Peripheral register structure.
==================================================
 */



#endif /* LMCAL_SYSTICK_SYSTICK_PRIVATE_H_ */
