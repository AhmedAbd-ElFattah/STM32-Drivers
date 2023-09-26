/*
 * File Name --> SYSCFG.c
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> SYSCFG driver implementation.
 * */

/*
==================================================
  Start Section --> File Includes
==================================================
*/
#include "SYSCFG.h"
#include "HMCAL/RCC/RCC.h"
/*
==================================================
  End   Section --> File Includes
==================================================
*/


/*
==================================================
  Start Section --> Functions implementation.
==================================================
*/
void SYSCFG_EXTIConfig_v(u8 Arg_GPIO_u8, u8 Arg_EXTIPinNum_u8){
	RCC_EnableClock_v(RCC_GetPeripheralBus_u8((u32)SYSCFG), RCC_SYSCFG);
	SYSCFG->EXTICR[Arg_EXTIPinNum_u8/4] &= ~((0xF) << ((Arg_EXTIPinNum_u8%4)*4));
	SYSCFG->EXTICR[Arg_EXTIPinNum_u8/4] |= ((Arg_GPIO_u8&0xF) << ((Arg_EXTIPinNum_u8%4)*4));
}

u8 SYSCFG_GetActiveGPIO_u8(u8 Arg_LineNumber_u8){
	u8 L_ActiveGPIO_u8;
	L_ActiveGPIO_u8 = SYSCFG->EXTICR[Arg_LineNumber_u8/4];
	L_ActiveGPIO_u8 >>= ((Arg_LineNumber_u8%4)*4);
	L_ActiveGPIO_u8 &= 0xF;

	return L_ActiveGPIO_u8;
}

/*
==================================================
  End   Section --> Functions implementation.
==================================================
*/

