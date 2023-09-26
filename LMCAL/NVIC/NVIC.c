/*
 * File Name --> NVIC.c
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> LMCAL
 * Brief	 --> NVIC driver implementation.
 * */
/*
==================================================
  Start Section --> File Includes
==================================================
*/
#include "LMCAL/NVIC/NVIC.h"
#include "LMCAL/NVIC/NVIC_Private.h"
/*
==================================================
  End   Section --> File Includes
==================================================
*/


/*
==================================================
  Start Section --> Implementation
==================================================
*/
void NVIC_EnableInterrupt_v(u8 Arg_InterruptNumber_u8){
	SET_BIT(NVIC->ISER[Arg_InterruptNumber_u8/32], Arg_InterruptNumber_u8%32);
}

void NVIC_DisableInterrupt_v(u8 Arg_InterruptNumber_u8){
	SET_BIT(NVIC->ICER[Arg_InterruptNumber_u8/32], Arg_InterruptNumber_u8%32);

}

void NVIC_SetPendingInterrupt_v(u8 Arg_InterruptNumber_u8){
	SET_BIT(NVIC->ISPR[Arg_InterruptNumber_u8/32], Arg_InterruptNumber_u8%32);

}

void NVIC_ClearPendingInterrupt_v(u8 Arg_InterruptNumber_u8){
	SET_BIT(NVIC->ICPR[Arg_InterruptNumber_u8/32], Arg_InterruptNumber_u8%32);

}

u8 NVIC_InterruptIsActive_u8(u8 Arg_InterruptNumber_u8){
	/*Return 1 if interrupt is active or active and pending.*/
	return GET_BIT(NVIC->ICPR[Arg_InterruptNumber_u8/32], Arg_InterruptNumber_u8%32);
}

u8 NVIC_InterruptIsEnabled_u8(u8 Arg_InterruptNumber_u8){
	return GET_BIT(NVIC->ISER[Arg_InterruptNumber_u8/32], Arg_InterruptNumber_u8%32);

}

u8 NVIC_InterruptIsPending_u8(u8 Arg_InterruptNumber_u8){
	return GET_BIT(NVIC->ISPR[Arg_InterruptNumber_u8/32], Arg_InterruptNumber_u8%32);
}

void NVIC_InterruptTrigger_v(u8 Arg_InterruptNumber_u8){
	NVIC->STIR = Arg_InterruptNumber_u8;

}
/*
==================================================
  End Section --> Implementation
==================================================
*/
