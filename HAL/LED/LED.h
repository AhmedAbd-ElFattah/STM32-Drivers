/*
 * File Name --> LED.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HAL
 * Brief	 --> Provides API and available configuration options for LED peripheral.
 * */

#ifndef HAL_LED_LED_H_
#define HAL_LED_LED_H_


/*
==================================================
  Start Section --> File Includes
==================================================
*/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "HMCAL/GPIO/GPIO.h"
/*
==================================================
  End   Section --> File Includes
==================================================
*/




/*
==================================================
  Start Section --> LED Configurations
==================================================
*/
typedef struct LED_Cfg{
	u8 GPIOInstanceId;
	u16 Pin;
}LED_Cfg;
/*
==================================================
  End   Section --> LED Configurations
==================================================
*/


/*
==================================================
  Start Section --> APIs
==================================================
*/

/* @brief  --> This function configures LED based on configuration passed through LED_Cfg struct.
 * @param  Arg_Config_pLED_Cfg --> struct that have configured parameters.
 * @retval --> None.
 * */
void LED_Config_v(LED_Cfg *Arg_Config_pLED_Cfg);

/* @brief  --> This function resets LED that have configuration passed through LED_Cfg struct.
 * @param  Arg_Config_pLED_Cfg --> struct that have configured parameters.
 * @retval --> None.
 * */
void LED_Reset_v(LED_Cfg *Arg_Config_pLED_Cfg);

/* @brief  --> This function Turns ON LED that have configuration passed through LED_Cfg struct.
 * @param  Arg_Config_pLED_Cfg --> struct that have configured parameters.
 * @retval --> None.
 * */
void LED_TurnOn_v(LED_Cfg *Arg_Config_pLED_Cfg);

/* @brief  --> This function Turns OFF LED that have configuration passed through LED_Cfg struct.
 * @param  Arg_Config_pLED_Cfg --> struct that have configured parameters.
 * @retval --> None.
 * */
void LED_TurnOFF_v(LED_Cfg *Arg_Config_pLED_Cfg);
/*
==================================================
  End Section --> APIs
==================================================
*/
#endif /* HAL_LED_LED_H_ */
