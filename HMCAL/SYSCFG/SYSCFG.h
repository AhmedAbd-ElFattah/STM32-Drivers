/*
 * File Name --> SYSCFG.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> Provides API and available configuration options for SYSCFG peripheral.
 * */

#ifndef HMCAL_SYSCFG_SYSCFG_H_
#define HMCAL_SYSCFG_SYSCFG_H_



/*
==================================================
  Start Section --> File Includes
==================================================
*/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "HMCAL/Interrupt/InterruptHandlers.h"
#include "SYSCFG_Private.h"
/*
==================================================
  End   Section --> File Includes
==================================================
*/


/*
==================================================
  Start Section --> EXTI Configurations
==================================================
*/
#define SYSCFG_EXTI_GPIOA			0
#define SYSCFG_EXTI_GPIOB			1
#define SYSCFG_EXTI_GPIOC			2
#define SYSCFG_EXTI_GPIOD			3
#define SYSCFG_EXTI_GPIOE			4
#define SYSCFG_EXTI_GPIOF			5
#define SYSCFG_EXTI_GPIOG			6
#define SYSCFG_EXTI_GPIOH			7
#define SYSCFG_EXTI_GPIOI			8


/*
==================================================
  End   Section --> EXTI Configurations
==================================================
*/



/*
==================================================
  Start Section --> APIs
==================================================
*/
void SYSCFG_EXTIConfig_v(u8 Arg_GPIO_u8, u8 Arg_EXTIPinNum_u8);
u8 SYSCFG_GetActiveGPIO_u8(u8 Arg_LineNumber_u8);

/*
==================================================
  End   Section --> APIs
==================================================
*/
#endif /* HMCAL_SYSCFG_SYSCFG_H_ */
