/*
 * File Name --> DCMotor.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HAL
 * Brief	 --> Provides API and available configuration options for Buzzer peripheral.
 * */

#ifndef HAL_DCMOTOR_DCMOTOR_H_
#define HAL_DCMOTOR_DCMOTOR_H_

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
typedef struct DCMotor_Cfg{
	u8 PINId;
	u8 TimerInstanceId;
	u8 GPIOInstanceId;

	u8 GPIO_ClockWise;
	u8 PIN_ClockWise;

	u8 GPIO_CounterClockWise;
	u8 PIN_CounterClockWise;

	u8 Channel;
	u8 SpeedInPercentage;
	u16 AutoReloadValue;
	u16 Prescaler;
}DCMotor_Cfg;
/*
==================================================
  End   Section --> ServoMotor Configurations
==================================================
 */
/* @brief  --> This function configures Button based on configuration passed through DCMotor_Cfg struct.
 * @param  Arg_Config_cpcLServoMotor --> struct that have configured parameters.
 * @retval --> None.
 * */
void DCMotor_Config_v(DCMotor_Cfg const * const Arg_Config_cpcLDCMotor);

/* @brief  --> This function updates configuration of ServoMotor based on configuration passed through DCMotor_Cfg struct.
 * @param  Arg_Config_cpcLServoMotor --> struct that have new-configured parameters.
 * @retval --> None.
 * */
void DCMotor_ChangeSpeed_v(DCMotor_Cfg const * const Arg_Config_cpcLDCMotor);

void DCMotor_StopMotor_v(DCMotor_Cfg const * const Arg_Config_cpcLDCMotor);

void DCMotor_SetDirectionToClockWise_v(DCMotor_Cfg const * const Arg_Config_cpcLDCMotor);
void DCMotor_SetDirectionToCounterClockWise_v(DCMotor_Cfg const * const Arg_Config_cpcLDCMotor);

#endif /* HAL_DCMOTOR_DCMOTOR_H_ */
