/*
 * File Name --> Delay.c
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> LIB
 * Brief	 --> Implementation for Delay functions.
 * */


/*
==================================================
  Start Section --> File Includes
==================================================
*/
#include "Delay.h"
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

void Delay_DelayInMilliSecondsBlocking_v(u32 Arg_DelayValueInMilliSeconds_u32){
	f32 Local_PreciseDelayValue;
	Local_PreciseDelayValue = SYSTICK_GetPreciseCurrentTicksInMilliSeconds_f32()+(f32)Arg_DelayValueInMilliSeconds_u32;
	f32 Local_PreciseTickValue;
	while (1){
		Local_PreciseTickValue = SYSTICK_GetPreciseCurrentTicksInMilliSeconds_f32();
		if (Local_PreciseTickValue > Local_PreciseDelayValue){
			break;
		}
	}
}

void Delay_DelayInSecondsBlocking_v(u32 Arg_DelayValueInSeconds_u32, u32 Arg_DelayValueInMilliSeconds_u32){
	if (0 != Arg_DelayValueInMilliSeconds_u32){
		Delay_DelayInMilliSecondsBlocking_v(Arg_DelayValueInMilliSeconds_u32);
	}
	for (u32 Local_i_u32 = 0; Local_i_u32 <Arg_DelayValueInSeconds_u32; Local_i_u32++){
		Delay_DelayInMilliSecondsBlocking_v(1000);
	}
}

/*
==================================================
  End   Section --> Implementation
==================================================
*/
