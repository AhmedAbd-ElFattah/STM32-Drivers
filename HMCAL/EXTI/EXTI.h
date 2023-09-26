/*
 * File Name --> EXTI.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> Provides API and available configuration options for EXTI peripheral.
 * */

#ifndef HMCAL_EXTI_EXTI_H_
#define HMCAL_EXTI_EXTI_H_

/*
==================================================
  Start Section --> File Includes
==================================================
*/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

/*
==================================================
  End   Section --> File Includes
==================================================
*/

/*
==================================================
  Start Section --> EXTI Configurations available options
==================================================
*/

/*@ref EXTI_Edge*/
#define 		EXTI_EDGE_NO_EDGE_DETECTION				0
#define 		EXTI_EDGE_RISING_EDGE_DETECTION         1
#define 		EXTI_EDGE_FALLING_EDGE_DETECTION        2
#define 		EXTI_EDGE_BOTH_EDGES_DETECTION          3
/*
==================================================
  End Section --> EXTI Configurations available options
==================================================
*/

/*
==================================================
  Start Section --> EXTI Configurations.
==================================================
*/
typedef struct EXTI_Configurations{
	/*This parameter take a value of @ref EXTI_Edge*/
	u8 Edge;
	/*This parameter can be the value of GPIO instance for example
	 * If you want to configure interrupt in GPIOA, This parameter will take the value 'A'*/
	u8 GPIOInstanceId;
	/*This parameter can be the value of assigned pins for GPIO instance
	 * using the following pattern
	 * PIN_x_MASK | PIN_y_MASK | PIN_z_MASK
	 * where x, y, and z are the values of selected pins
	 * for example if you want to configure Pin A0, A3, A10
	 * This parameter will take
	 * PIN_0_MASK | PIN_3_MASK | PIN_10_MASK
	 * */
	u32 PINs;
}EXTI_Cfg;
/*
==================================================
  End Section --> EXTI Configurations.
==================================================
*/
/*
==================================================
  Start Section --> APIs
==================================================
*/

void EXTI_Config_v(EXTI_Cfg const * const Arg_conf_cpcEXTI_Cfg);
Bool EXTI_CheckInterrupt_Bool(u8 Arg_PinNumber_u8);
void EXTI_ClearInterrupt_v(u8 Arg_PinNumber_u8);

/*
==================================================
  End Section --> APIs
==================================================
*/
#endif /* HMCAL_EXTI_EXTI_H_ */
