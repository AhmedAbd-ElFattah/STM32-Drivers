/*
 * File Name --> SevenSegment.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HAL
 * Brief	 --> Provides API and available configuration options for SevenSegment peripheral.
 * */


#ifndef HAL_SEVENSEGMENT_SEVENSEGMENT_H_
#define HAL_SEVENSEGMENT_SEVENSEGMENT_H_

/*
==================================================
  Start Section --> File Includes
==================================================
 */
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "HMCAL/GPIO/GPIO.h"
#include "SevenSegment_Private.h"
/*
==================================================
  End   Section --> File Includes
==================================================
 */

/*
==================================================
  Start Section --> Seven segment Configurations available options
==================================================
 */

/*@ref SevenSegment_CommonMode*/
#define COMMON_MODE_ANODE	0
#define COMMON_MODE_CATHODE	1


/*
==================================================
  End Section --> Seven segment Configurations available options
==================================================
 */

/*
==================================================
  Start Section --> Seven segment Configurations
==================================================
 */
typedef struct SevenSegment_Cfg{
	u8 GPIOInstanceId;
	/*This parameter take a value of @ref SevenSegment_CommonMode*/
	u8 CommonMode;
	union {
		struct{
			u8 PIN_A;
			u8 PIN_B;
			u8 PIN_C;
			u8 PIN_D;
			u8 PIN_E;
			u8 PIN_F;
			u8 PIN_G;
			u8 PIN_DP;
		};
		u8 PinsArr[SEVEN_SEG_TOTAL_PINS];
	};
}SevenSegment_Cfg;
/*
==================================================
  End   Section --> Seven segment Configurations
==================================================
 */

/*
==================================================
  Start Section --> APIs
==================================================
*/

/* @brief  --> This function configures Seven Segment based on configuration passed through SevenSegment_Cfg struct.
 * @param  Arg_Config_pSevenSegment_Cfg --> struct that have configured parameters.
 * @retval --> None.
 * */
void SevenSegment_Config_v(SevenSegment_Cfg * const Arg_Config_pSevenSegment_Cfg);

/* @brief  --> This function displays number on Seven Segment.
 * @param  Arg_Config_pSevenSegment_Cfg --> struct that have configured parameters.
 * @param  Arg_DispVal_u8 --> Value that will be displayed on sevensegment.
 * @retval --> None.
 * */
void SevenSegment_DisplayValue_v(SevenSegment_Cfg * const Arg_Config_pSevenSegment_Cfg, const u8 Arg_DispVal_u8);

/* @brief  --> This function turns off seven segment.
 * @param  Arg_Config_pSevenSegment_Cfg --> struct that have configured parameters.
 * @retval --> None.
 * */
void SevenSegment_TurnOFFDisplay_v(SevenSegment_Cfg * const Arg_Config_pSevenSegment_Cfg);

/*
==================================================
  End Section --> APIs
==================================================
*/

#endif /* HAL_SEVENSEGMENT_SEVENSEGMENT_H_ */
