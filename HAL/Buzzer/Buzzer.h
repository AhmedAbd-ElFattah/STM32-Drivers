/*
 * File Name --> Buzzer.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HAL
 * Brief	 --> Provides API and available configuration options for Buzzer peripheral.
 * */

#ifndef HAL_BUZZER_BUZZER_H_
#define HAL_BUZZER_BUZZER_H_

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
  Start Section --> Buzzer Configurations
==================================================
 */
typedef struct Buzzer_Cfg{
	u8 PINId;
	u8 TimerInstanceId;
	u8 GPIOInstanceId;
	u8 Channel;
	u8 PWM;
	u16 AutoReloadValue;
	u16 Prescaler;

}Buzzer_Cfg;
/*
==================================================
  End   Section --> Buzzer Configurations
==================================================
 */
/* @brief  --> This function configures Button based on configuration passed through Buzzer_Cfg struct.
 * @param  Arg_Config_cpcLBuzzer --> struct that have configured parameters.
 * @retval --> None.
 * */
void Buzzer_Config_v(Buzzer_Cfg const * const Arg_Config_cpcLBuzzer);

/* @brief  --> This function updates configuration of Buzzer based on configuration passed through Buzzer_Cfg struct.
 * @param  Arg_Config_cpcLBuzzer --> struct that have new-configured parameters.
 * @retval --> None.
 * */
void Buzzer_ChangeFrequencyAndPWM_v(Buzzer_Cfg const * const Arg_Config_cpcLBuzzer);
#endif /* HAL_BUZZER_BUZZER_H_ */
