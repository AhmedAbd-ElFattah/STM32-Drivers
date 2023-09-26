/*
 * File Name --> NVIC.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> LMCAL
 * Brief	 --> Provides API and available configuration options for NVIC peripheral.
 * */

#ifndef LMCAL_NVIC_NVIC_H_
#define LMCAL_NVIC_NVIC_H_


/*
==================================================
  Start Section --> File Includes
==================================================
*/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "NVIC_defs.h"
#include "NVIC_Private.h"
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
#define 	NVIC		((volatile NVIC_Memory_map*)NVIC_BASE_ADDRESS)
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
void NVIC_EnableInterrupt_v(u8 Arg_InterruptNumber_u8);

void NVIC_DisableInterrupt_v(u8 Arg_InterruptNumber_u8);

void NVIC_SetPendingInterrupt_v(u8 Arg_InterruptNumber_u8);

void NVIC_ClearPendingInterrupt_v(u8 Arg_InterruptNumber_u8);

u8 NVIC_InterruptIsActive_u8(u8 Arg_InterruptNumber_u8);

u8 NVIC_InterruptIsEnabled_u8(u8 Arg_InterruptNumber_u8);

u8 NVIC_InterruptIsPending_u8(u8 Arg_InterruptNumber_u8);

void NVIC_InterruptTrigger_v(u8 Arg_InterruptNumber_u8);
/*
==================================================
  End   Section --> Function Declaration
==================================================
*/
#endif /* LMCAL_NVIC_NVIC_H_ */
