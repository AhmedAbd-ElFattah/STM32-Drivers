/*
 * File Name --> SYSTICK.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> LMCAL
 * Brief	 --> Provides API and available configuration options for Systick peripheral.
 * */

#ifndef LMCAL_SYSTICK_SYSTICK_H_
#define LMCAL_SYSTICK_SYSTICK_H_

/*
==================================================
  Start Section --> File Includes
==================================================
 */
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "SYSTICK_defs.h"
#include "STM32_Drivers_Configurations/Driver_Config.h"
#include "HMCAL/RCC/RCC.h"
#include "SYSTICK_Private.h"
/*
==================================================
  End   Section --> File Includes
==================================================
 */



/*
==================================================
  Start Section --> Data Type Declaration
==================================================
 */

#define 		SYSTICK    	((volatile SYSTICK_MemMap*)(SYSTICK_BASE_ADDRESS))

/*
==================================================
  End   Section --> Data Type Declaration
==================================================
 */


/*
==================================================
  Start Section --> APIs
==================================================
 */
void SYSTICK_Init_v(void);

u32 SYSTICK_GetCurrentTicks_u32(void);

f32 SYSTICK_GetPreciseCurrentTicksInMilliSeconds_f32(void);
/*
==================================================
  End   Section --> APIs
==================================================
 */
#endif /* LMCAL_SYSTICK_SYSTICK_H_ */
