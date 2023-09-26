/*
 * File Name --> ServoMotor.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HAL
 * Brief	 --> Provides API and available configuration options for Buzzer peripheral.
 * */

#ifndef HAL_SERVOMOTOR_SERVOMOTOR_H_
#define HAL_SERVOMOTOR_SERVOMOTOR_H_

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
  Start Section --> ServoMotor Configurations
==================================================
 */
typedef struct ServoMotor_Cfg{
	u8 PINId;
	u8 TimerInstanceId;
	u8 GPIOInstanceId;
	u8 Channel;
	u8 Angle;
	u16 AutoReloadValue;
	u16 Prescaler;
	u16 (*AngleMappingFunction)(u16);
}ServoMotor_Cfg;
/*
==================================================
  End   Section --> ServoMotor Configurations
==================================================
 */
/* @brief  --> This function configures Button based on configuration passed through ServoMotor_Cfg struct.
 * @param  Arg_Config_cpcLServoMotor --> struct that have configured parameters.
 * @retval --> None.
 * */
void ServoMotor_Config_v(ServoMotor_Cfg const * const Arg_Config_cpcLServoMotor);

/* @brief  --> This function updates configuration of ServoMotor based on configuration passed through ServoMotor_Cfg struct.
 * @param  Arg_Config_cpcLServoMotor --> struct that have new-configured parameters.
 * @retval --> None.
 * */
void ServoMotor_ChangeFrequencyAndAngle_v(ServoMotor_Cfg const * const Arg_Config_cpcLServoMotor);

#endif /* HAL_SERVOMOTOR_SERVOMOTOR_H_ */
