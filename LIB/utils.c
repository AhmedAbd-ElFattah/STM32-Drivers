/*
 * File Name --> utils.c
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> LIB
 * Brief	 --> Implementation utilization functions.
 * */

/*
==================================================
  Start Section --> File Includes
==================================================
 */
#include "utils.h"
#include "LMCAL/SYSTICK/SYSTICK.h"
#include "LMCAL/SCB/SCB.h"
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
void Utils_TimeoutChecker_Init(
		Utils_TimeoutChecker *Arg_Tout_Utils_TimeoutChecker,
		u32 Arg_TimeoutValueInmS_u32
){

	Arg_Tout_Utils_TimeoutChecker->PreciseDelayValue=SYSTICK_GetPreciseCurrentTicksInMilliSeconds_f32();
	Arg_Tout_Utils_TimeoutChecker->PreciseDelayValue+=(f32)Arg_TimeoutValueInmS_u32;
	Arg_Tout_Utils_TimeoutChecker->TimeoutValueInMilliSeconds = Arg_TimeoutValueInmS_u32;

}

u8 Utils_IsTimeoutOccurred_u8(Utils_TimeoutChecker *Arg_Tout_Utils_TimeoutChecker){
	if (STD_MAX_DELAY == Arg_Tout_Utils_TimeoutChecker->TimeoutValueInMilliSeconds){
		return STD_FALSE;
	}
	if(SYSTICK_GetPreciseCurrentTicksInMilliSeconds_f32() > Arg_Tout_Utils_TimeoutChecker->PreciseDelayValue){
		/*Timeout Occur*/
		return STD_TRUE;
	}
	return STD_FALSE;
}

void Utils_SoftwareReset_v(void){
	SCB_SWReset();
}
/*
==================================================
  End   Section --> Implementation
==================================================
 */
