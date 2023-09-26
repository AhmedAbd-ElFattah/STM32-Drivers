/*
 * File Name --> SYSTICK.c
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> LMCAL
 * Brief	 --> SYSTICK driver implementation.
 * */


/*
==================================================
  Start Section --> File Includes
==================================================
 */
#include "SYSTICK.h"
/*
==================================================
  End   Section --> File Includes
==================================================
 */

/*
==================================================
  Start Section --> Function Implementation
==================================================
 */
static u32 StaticGlobal_Ticks_u32 = 0;

#if (CONFIG_USE_RTOS==CONFIG_NO_RTOS)

void SysTick_Handler(void){
	StaticGlobal_Ticks_u32++;
}
#endif

f32 SYSTICK_GetPreciseCurrentTicksInMilliSeconds_f32(void){
	return (f32)(SYSTICK_GetCurrentTicks_u32()/CONFIG_TICK_TIME_IN_MilliSeconds) + (f32)(SYSTICK->CVR)/((f32)SYSTICK->RVR);
}

u32 SYSTICK_GetCurrentTicks_u32(void){
	return StaticGlobal_Ticks_u32;
}



void SYSTICK_Init_v(void){
#if CONFIG_SYSTICK_USE_EXTERNAL_CLOCK
	CLEAR_BIT(SYSTICK->CSR, SYSTICK_CSR_CLKSOURCE);
#else
	SET_BIT(SYSTICK->CSR, SYSTICK_CSR_CLKSOURCE);
#endif

	f32 Local_MaxTickTime = 0xffffff / (RCC_GetCortexSystemTimerFrequency_f32()*1000000);
	if (CONFIG_TICK_TIME_IN_MilliSeconds > Local_MaxTickTime){
		while(1){
			/*
			 * COnfigured value of CONFIG_TICK_TIME_IN_MilliSeconds can't be achieved, please change frequency of systick.
			 * */
		}
	}

	/*Set Systick Reload Value*/
	SYSTICK->RVR = (RCC_GetCortexSystemTimerFrequency_f32()*1000*CONFIG_TICK_TIME_IN_MilliSeconds)-1;
	/*Enable SYSTICK Interrupt*/
	SET_BIT(SYSTICK->CSR, SYSTICK_CSR_TICKINT);
	/*Enable SYSTICK*/
	SET_BIT(SYSTICK->CSR, SYSTICK_CSR_ENABLE);


}
/*
==================================================
  End   Section --> Function Implementation
==================================================
 */
