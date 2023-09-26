/*
 * File Name --> InterruptHandlers.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 -->
 * */

#ifndef HMCAL_INTERRUPT_INTERRUPTHANDLERS_H_
#define HMCAL_INTERRUPT_INTERRUPTHANDLERS_H_




/*
==================================================
  Start Section --> File Includes
==================================================
 */
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "STM32_Drivers_Configurations/Driver_Config.h"
#include "LMCAL/NVIC/NVIC.h"
#include "HMCAL/TIM/TIM.h"
#include "HMCAL/SPI/SPI.h"
#include "HMCAL/USART/USART.h"

/*
==================================================
  End   Section --> File Includes
==================================================
 */
void InterruptHandler_Init_v(void);
void InterruptHandler_SetEXTIxCallback_void(u8 Arg_GPIOInstanceId_u8, u8 Arg_PinNumber_u8,void (*Arg_FunctionCallback_v)(void) );
void InterruptHandler_SetDMACallback_v(u8 Arg_DMAInstanceId_u8, u8 Arg_StreamNumber_u8,u8 Arg_InterruptFagNum_u8, void (*Arg_FunctionCallback_v)(void));
void InterruptHandler_SetUSARTCallback_v(u8 Arg_USARTInstanceId_u8, u8 Arg_InterruptType_u8, void (*Arg_FunctionCallback_v)(void) );
/*
==================================================
  Start Section --> Macro Declaration
==================================================
 */

/*
==================================================
  End   Section --> Macro Declaration
==================================================
 */





/*
==================================================
  Start Section --> Function Declaration
==================================================
 */
#if CONFIG_USE_SVC_INTERUPT == 1
void InterruptHandler_SetSVCCallback_void(void (*Arg_FunctionCallback_void)() );
#endif



/*
==================================================
  End   Section --> Function Declaration
==================================================
 */
#endif /* HMCAL_INTERRUPT_INTERRUPTHANDLERS_H_ */
