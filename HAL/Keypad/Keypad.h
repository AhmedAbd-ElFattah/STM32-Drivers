/*
 * File Name --> Keypad.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HAL
 * Brief	 --> Provides API and available configuration options for Keypad4x4 peripheral.
 * */

#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_

/*
==================================================
  Start Section --> File Includes
==================================================
 */
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "HMCAL/GPIO/GPIO.h"
#include "Keypad_Private.h"
/*
==================================================
  End   Section --> File Includes
==================================================
 */

/*
==================================================
  Start Section --> Keypad Configurations available options
==================================================
 */

/*@ref Pull_up_or_Pull_down_Resistor*/
/* Pull Up/Down resistor */
#define 		Keypad_RESISTOR_NO_PULL     0
#define 		Keypad_RESISTOR_PULL_UP     1
#define 		Keypad_RESISTOR_PULL_DOWN   2

/*
==================================================
  End Section --> Keypad Configurations available options
==================================================
 */

/*
==================================================
  Start Section --> Keypad Configurations
==================================================
 */
typedef struct Keypad_Cfg{
	u8 PullUpDownMode;
	u8 RowsGPIOInstanceId;
	u8 ColsGPIOInstanceId;

	u8 Rows_Number;
	u8 Cols_Number;

	u8 *RowsPins;
	u8 *ColsPins;


}Keypad_Cfg;
/*
==================================================
  End   Section --> Keypad Configurations
==================================================
 */


/*
==================================================
  Start Section --> APIs
==================================================
*/

/* @brief  --> This function configures Button based on configuration passed through Keypad_Cfg struct.
 * @param  Arg_Config_cpcLKeypad --> struct that have configured parameters.
 * @retval --> None.
 * */
void Keypad_Config_v(Keypad_Cfg const * const Arg_Config_cpcLKeypad);

/* @brief  --> Read keypad values.
 * @param  Arg_Config_cpcLKeypad --> struct that have configured parameters.
 * @param  Arg_OutputArr_pcBool --> pointer to 2-D array of returned statis of key key on keypad
 * @retval --> None.
 * */
void Keypad_ReadKeys_v(Keypad_Cfg const * const Arg_Config_cpcLKeypad, Bool *const Arg_OutputArr_pcBool);
#endif /* HAL_KEYPAD_KEYPAD_H_ */
