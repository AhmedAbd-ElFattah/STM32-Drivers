/*
 * File Name --> ServoMotor.c
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HAL
 * Brief	 --> ServoMotor driver implementation.
 * */
/*
==================================================
  Start Section --> File Includes
==================================================
 */
#include "LIB/Delay/Delay.h"
#include "HMCAL/TIM/TIM.h"
#include "ServoMotor.h"
/*
==================================================
  End   Section --> File Includes
==================================================
 */


/*
==================================================
  Start Section --> Functions implementation.
==================================================
 */
void ServoMotor_Config_v(ServoMotor_Cfg const * const Arg_Config_cpcLServoMotor){
	TIM_Cfg L_ServoMotorTIM_Cfg = {0};

	L_ServoMotorTIM_Cfg.InstanceId = Arg_Config_cpcLServoMotor->TimerInstanceId;
	u16 L_PWM_u16 = Arg_Config_cpcLServoMotor->AngleMappingFunction(Arg_Config_cpcLServoMotor->Angle);
	switch (Arg_Config_cpcLServoMotor->Channel){
	case 1:
		L_ServoMotorTIM_Cfg.ActiveChannels |= TIM_ACTIVE_CHANNELS_CH1_OUT;
		L_ServoMotorTIM_Cfg.Channel1Mode = TIM_CHANNEL_MODE_OUTPUT_PWM_ACTIVE_HIGH;
		L_ServoMotorTIM_Cfg.Channel1CaptureCompare = L_PWM_u16;
		break;
	case 2:
		L_ServoMotorTIM_Cfg.ActiveChannels |= TIM_ACTIVE_CHANNELS_CH2_OUT;
		L_ServoMotorTIM_Cfg.Channel2Mode = TIM_CHANNEL_MODE_OUTPUT_PWM_ACTIVE_HIGH;
		L_ServoMotorTIM_Cfg.Channel2CaptureCompare = L_PWM_u16;
		break;
	case 3:
		L_ServoMotorTIM_Cfg.ActiveChannels |= TIM_ACTIVE_CHANNELS_CH3_OUT;
		L_ServoMotorTIM_Cfg.Channel3Mode = TIM_CHANNEL_MODE_OUTPUT_PWM_ACTIVE_HIGH;
		L_ServoMotorTIM_Cfg.Channel3CaptureCompare = L_PWM_u16;
		break;
	case 4:
		L_ServoMotorTIM_Cfg.ActiveChannels |= TIM_ACTIVE_CHANNELS_CH4_OUT;
		L_ServoMotorTIM_Cfg.Channel4Mode = TIM_CHANNEL_MODE_OUTPUT_PWM_ACTIVE_HIGH;
		L_ServoMotorTIM_Cfg.Channel4CaptureCompare = L_PWM_u16;
		break;

	}

	L_ServoMotorTIM_Cfg.AutoReloadValue = Arg_Config_cpcLServoMotor->AutoReloadValue;

	L_ServoMotorTIM_Cfg.Prescaler = Arg_Config_cpcLServoMotor->Prescaler;
	L_ServoMotorTIM_Cfg.GPIOInstanceId = Arg_Config_cpcLServoMotor->GPIOInstanceId;
	SET_BIT(L_ServoMotorTIM_Cfg.GPIOPins, Arg_Config_cpcLServoMotor->PINId);
	/*Apply timer configurations.*/
	TIM_Config_v(&L_ServoMotorTIM_Cfg);
	TIM_StartTimer_v(&L_ServoMotorTIM_Cfg);
}

void ServoMotor_ChangeFrequencyAndAngle_v(ServoMotor_Cfg const * const Arg_Config_cpcLServoMotor){
	TIM_Cfg L_ServoMotorTIM_Cfg = {0};

	L_ServoMotorTIM_Cfg.InstanceId = Arg_Config_cpcLServoMotor->TimerInstanceId;
	u16 L_PWM_u16 = Arg_Config_cpcLServoMotor->AngleMappingFunction(Arg_Config_cpcLServoMotor->Angle);
	switch (Arg_Config_cpcLServoMotor->Channel){
	case 1:
		L_ServoMotorTIM_Cfg.ActiveChannels |= TIM_ACTIVE_CHANNELS_CH1_OUT;
		L_ServoMotorTIM_Cfg.Channel1Mode = TIM_CHANNEL_MODE_OUTPUT_PWM_ACTIVE_HIGH;
		L_ServoMotorTIM_Cfg.Channel1CaptureCompare = L_PWM_u16;
		break;
	case 2:
		L_ServoMotorTIM_Cfg.ActiveChannels |= TIM_ACTIVE_CHANNELS_CH2_OUT;
		L_ServoMotorTIM_Cfg.Channel2Mode = TIM_CHANNEL_MODE_OUTPUT_PWM_ACTIVE_HIGH;
		L_ServoMotorTIM_Cfg.Channel2CaptureCompare = L_PWM_u16;
		break;
	case 3:
		L_ServoMotorTIM_Cfg.ActiveChannels |= TIM_ACTIVE_CHANNELS_CH3_OUT;
		L_ServoMotorTIM_Cfg.Channel3Mode = TIM_CHANNEL_MODE_OUTPUT_PWM_ACTIVE_HIGH;
		L_ServoMotorTIM_Cfg.Channel3CaptureCompare = L_PWM_u16;
		break;
	case 4:
		L_ServoMotorTIM_Cfg.ActiveChannels |= TIM_ACTIVE_CHANNELS_CH4_OUT;
		L_ServoMotorTIM_Cfg.Channel4Mode = TIM_CHANNEL_MODE_OUTPUT_PWM_ACTIVE_HIGH;
		L_ServoMotorTIM_Cfg.Channel4CaptureCompare = L_PWM_u16;
		break;

	}

	L_ServoMotorTIM_Cfg.AutoReloadValue = Arg_Config_cpcLServoMotor->AutoReloadValue;
	L_ServoMotorTIM_Cfg.Prescaler = Arg_Config_cpcLServoMotor->Prescaler;
	L_ServoMotorTIM_Cfg.GPIOInstanceId = Arg_Config_cpcLServoMotor->GPIOInstanceId;
	SET_BIT(L_ServoMotorTIM_Cfg.GPIOPins, Arg_Config_cpcLServoMotor->PINId);

	TIM_StopTimer_v(&L_ServoMotorTIM_Cfg);
	/*Apply timer configurations.*/
	TIM_Config_v(&L_ServoMotorTIM_Cfg);
	TIM_StartTimer_v(&L_ServoMotorTIM_Cfg);

}
/*
==================================================
  End Section --> Functions implementation.
==================================================
 */
