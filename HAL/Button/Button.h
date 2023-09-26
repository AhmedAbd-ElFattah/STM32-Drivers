/*
 * File Name --> Button.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HAL
 * Brief	 --> Provides API and available configuration options for Button peripheral.
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
  Start Section --> Button Configurations available options
==================================================
 */

/*@ref Pull_up_or_Pull_down_Resistor*/
/* Pull Up/Down resistor */
#define 		Button_RESISTOR_NO_PULL     0
#define 		Button_RESISTOR_PULL_UP     1
#define 		Button_RESISTOR_PULL_DOWN   2

/*
==================================================
  End Section --> Button Configurations available options
==================================================
 */


/*
==================================================
  Start Section --> Button Configurations
==================================================
*/
typedef struct Button_Cfg{
	u8 GPIOInstanceId;
	u8 PullUpPullDownResistor;
	u16 Pin;
}Button_Cfg;
/*
==================================================
  End   Section --> Button Configurations
==================================================
*/


/*
==================================================
  Start Section --> APIs
==================================================
*/

/* @brief  --> This function configures Button based on configuration passed through Button_Cfg struct.
 * @param  Arg_Config_pLButton_Cfg --> struct that have configured parameters.
 * @retval --> None.
 * */
void Button_Config_v(Button_Cfg *Arg_Config_pLButton_Cfg);

/* @brief  --> This function resets configure of Button based on configuration passed through Button_Cfg struct.
 * @param  Arg_Config_pLButton_Cfg --> struct that have configured parameters.
 * @retval --> None.
 * */
void Button_Reset_v(Button_Cfg *Arg_Config_pLButton_Cfg);

/* @brief  --> This function reads button reading.
 * @param  Arg_Config_pLButton_Cfg --> struct that have configured parameters.
 * @retval --> None.
 * */
u16 Button_GetReading_u16(Button_Cfg *Arg_Config_pLButton_Cfg);

/* @brief  --> This function reads pin of specific button.
 * @param  Arg_Config_pLButton_Cfg --> struct that have configured parameters.
 * @param  Arg_Pin_u8 --> Pin that you need to get it's reading.
 * @retval --> Reading of pins.
 * */
Bool Button_GetPinReading_Bool(Button_Cfg *Arg_Config_pLButton_Cfg, u8 Arg_Pin_u8);

/* @brief  --> This function checks whether button is ressed or released regardless of Pull Up/Down Resistor mode.
 * @param  Arg_Config_pLButton_Cfg --> struct that have configured parameters.
 * @param  Arg_Pin_u8 --> Pin connected to button that you need to check about it.
 * @retval --> Is button is pressed ?
 * */
Bool Button_IsPressed_Bool(Button_Cfg *Arg_Config_pLButton_Cfg, u8 Arg_Pin_u8);

/*
==================================================
  End Section --> APIs
==================================================
*/
#endif /* HAL_LED_LED_H_ */
