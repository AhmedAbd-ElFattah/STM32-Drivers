/*
 * File Name --> SevenSegmentModule56D330.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HAL
 * Brief	 --> Provides API and available configuration options for SevenSegment peripheral.
 * */


#ifndef HAL_SEVENSEGMENT_MODULE56D330_SEVENSEGMENTMODULE56D330_H_
#define HAL_SEVENSEGMENT_MODULE56D330_SEVENSEGMENTMODULE56D330_H_

/*
==================================================
  Start Section --> File Includes
==================================================
 */
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "HMCAL/GPIO/GPIO.h"
#include "SevenSegmentModule56D330_Private.h"
/*
==================================================
  End   Section --> File Includes
==================================================
 */

/*
==================================================
  Start Section --> Seven segment Configurations
==================================================
 */
typedef struct SevenSegmentModule56D330_Cfg{
	u8 ChipSelectGPIOInstanceId;
	u8 ChipSelectGPIOPin;

	u8 ClockGPIOInstanceId;
	u8 ClockGPIOGPIOPin;

	u8 DataInputGPIOInstanceId;
	u8 DataInputGPIOPin;
}SevenSegmentModule56D330_Cfg;
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

/* @brief  --> This function configures Seven Segment module based on configuration passed through SevenSegmentModule56D330_Cfg struct.
 * @param  Arg_Config_pSSM_Cfg --> struct that have configured parameters.
 * @retval --> None.
 * */
void SevenSegmentModule_Config_v(SevenSegmentModule56D330_Cfg * const Arg_Config_pSSM_Cfg);

/* @brief  --> This function configures Seven Segment module based on configuration passed through SevenSegmentModule56D330_Cfg struct.
 * @param  Arg_Config_pSSM_Cfg --> struct that have configured parameters.
 * @param  Arg_DispNum_u8 --> Pass display number.
 * @param  Arg_Number_u16 --> Number the you need to display on display number in Arg_DispNum_u8.
 * @retval --> None.
 * */
void SevenSegmentModule_DisplayNumber_v(SevenSegmentModule56D330_Cfg * const Arg_Config_pSSM_Cfg, u8 Arg_DispNum_u8, u16 Arg_Number_u16);
/*
==================================================
  End Section --> APIs
==================================================
*/

#endif /* HAL_SEVENSEGMENT_SEVENSEGMENT_H_ */
