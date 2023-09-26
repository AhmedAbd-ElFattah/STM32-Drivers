/*
 * File Name --> DCMotor.c
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HAL
 * Brief	 --> DCMotor driver implementation.
 * */
/*
==================================================
  Start Section --> File Includes
==================================================
 */
#include <HAL/DCMotor/DCMotor.h>
#include "LIB/Delay/Delay.h"
#include "HMCAL/TIM/TIM.h"
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
void DCMotor_Config_v(DCMotor_Cfg const * const Arg_Config_cpcLDCMotor){
	TIM_Cfg L_DCMotorTIM_Cfg = {0};

	L_DCMotorTIM_Cfg.InstanceId = Arg_Config_cpcLDCMotor->TimerInstanceId;

	u16 L_PWM_u16 = Arg_Config_cpcLDCMotor->AutoReloadValue * Arg_Config_cpcLDCMotor->SpeedInPercentage/100;
	switch (Arg_Config_cpcLDCMotor->Channel){
	case 1:
		L_DCMotorTIM_Cfg.ActiveChannels |= TIM_ACTIVE_CHANNELS_CH1_OUT;
		L_DCMotorTIM_Cfg.Channel1Mode = TIM_CHANNEL_MODE_OUTPUT_PWM_ACTIVE_HIGH;
		L_DCMotorTIM_Cfg.Channel1CaptureCompare = L_PWM_u16;
		break;
	case 2:
		L_DCMotorTIM_Cfg.ActiveChannels |= TIM_ACTIVE_CHANNELS_CH2_OUT;
		L_DCMotorTIM_Cfg.Channel2Mode = TIM_CHANNEL_MODE_OUTPUT_PWM_ACTIVE_HIGH;
		L_DCMotorTIM_Cfg.Channel2CaptureCompare = L_PWM_u16;
		break;
	case 3:
		L_DCMotorTIM_Cfg.ActiveChannels |= TIM_ACTIVE_CHANNELS_CH3_OUT;
		L_DCMotorTIM_Cfg.Channel3Mode = TIM_CHANNEL_MODE_OUTPUT_PWM_ACTIVE_HIGH;
		L_DCMotorTIM_Cfg.Channel3CaptureCompare = L_PWM_u16;
		break;
	case 4:
		L_DCMotorTIM_Cfg.ActiveChannels |= TIM_ACTIVE_CHANNELS_CH4_OUT;
		L_DCMotorTIM_Cfg.Channel4Mode = TIM_CHANNEL_MODE_OUTPUT_PWM_ACTIVE_HIGH;
		L_DCMotorTIM_Cfg.Channel4CaptureCompare = L_PWM_u16;
		break;

	}

	L_DCMotorTIM_Cfg.AutoReloadValue = Arg_Config_cpcLDCMotor->AutoReloadValue;

	L_DCMotorTIM_Cfg.Prescaler = Arg_Config_cpcLDCMotor->Prescaler;
	L_DCMotorTIM_Cfg.GPIOInstanceId = Arg_Config_cpcLDCMotor->GPIOInstanceId;
	SET_BIT(L_DCMotorTIM_Cfg.GPIOPins, Arg_Config_cpcLDCMotor->PINId);
	/*Apply timer configurations.*/
	TIM_Config_v(&L_DCMotorTIM_Cfg);
	TIM_StartTimer_v(&L_DCMotorTIM_Cfg);

	/*Configure GPIO Direction Pins*/
	GPIO_Cfg L_DCMotorDirectionPins_GPIO_Cfg;
	L_DCMotorDirectionPins_GPIO_Cfg.InstanceId = Arg_Config_cpcLDCMotor->GPIO_ClockWise;
	L_DCMotorDirectionPins_GPIO_Cfg.Mode = GPIO_MODE_OUTPUT;
	L_DCMotorDirectionPins_GPIO_Cfg.OutputSpeed = GPIO_OUTPUT_SPEED_LOW;
	L_DCMotorDirectionPins_GPIO_Cfg.OutputType = GPIO_OUTPUT_TYPE_PUSH_PULL;
	L_DCMotorDirectionPins_GPIO_Cfg.PINs = Arg_Config_cpcLDCMotor->PIN_ClockWise;
	L_DCMotorDirectionPins_GPIO_Cfg.PullUpPullDownResistor = GPIO_RESISTOR_NO_PULL;
	GPIO_Config_v(&L_DCMotorDirectionPins_GPIO_Cfg);

	L_DCMotorDirectionPins_GPIO_Cfg.InstanceId = Arg_Config_cpcLDCMotor->GPIO_CounterClockWise;
	L_DCMotorDirectionPins_GPIO_Cfg.PINs = Arg_Config_cpcLDCMotor->PIN_CounterClockWise;
	GPIO_Config_v(&L_DCMotorDirectionPins_GPIO_Cfg);
}

void DCMotor_ChangeSpeed_v(DCMotor_Cfg const * const Arg_Config_cpcLDCMotor){
	TIM_Cfg L_DCMotorTIM_Cfg = {0};

	L_DCMotorTIM_Cfg.InstanceId = Arg_Config_cpcLDCMotor->TimerInstanceId;
	u16 L_Speed_u16 = Arg_Config_cpcLDCMotor->AutoReloadValue * Arg_Config_cpcLDCMotor->SpeedInPercentage/100;
	TIM_StopTimer_v(&L_DCMotorTIM_Cfg);
	switch (Arg_Config_cpcLDCMotor->Channel){
	case 1:
		TIM_SetOutputCompare1Value_v(&L_DCMotorTIM_Cfg, L_Speed_u16);
		break;
	case 2:
		TIM_SetOutputCompare1Value_v(&L_DCMotorTIM_Cfg, L_Speed_u16);
		break;
	case 3:
		TIM_SetOutputCompare1Value_v(&L_DCMotorTIM_Cfg, L_Speed_u16);
		break;
	case 4:
		TIM_SetOutputCompare1Value_v(&L_DCMotorTIM_Cfg, L_Speed_u16);
		break;
	}
	TIM_StartTimer_v(&L_DCMotorTIM_Cfg);

}

void DCMotor_StopMotor_v(DCMotor_Cfg const * const Arg_Config_cpcLDCMotor){
	TIM_Cfg L_DCMotorTIM_Cfg = {0};

	L_DCMotorTIM_Cfg.InstanceId = Arg_Config_cpcLDCMotor->TimerInstanceId;
	u16 L_Speed_u16 = 0;
	TIM_StopTimer_v(&L_DCMotorTIM_Cfg);
	switch (Arg_Config_cpcLDCMotor->Channel){
	case 1:
		TIM_SetOutputCompare1Value_v(&L_DCMotorTIM_Cfg, L_Speed_u16);
		break;
	case 2:
		TIM_SetOutputCompare1Value_v(&L_DCMotorTIM_Cfg, L_Speed_u16);
		break;
	case 3:
		TIM_SetOutputCompare1Value_v(&L_DCMotorTIM_Cfg, L_Speed_u16);
		break;
	case 4:
		TIM_SetOutputCompare1Value_v(&L_DCMotorTIM_Cfg, L_Speed_u16);
		break;
	}
	TIM_StartTimer_v(&L_DCMotorTIM_Cfg);

	GPIO_Cfg L_DC_Direction_GPIO_Cfg;
	L_DC_Direction_GPIO_Cfg.InstanceId = Arg_Config_cpcLDCMotor->GPIO_ClockWise;
	L_DC_Direction_GPIO_Cfg.PINs = Arg_Config_cpcLDCMotor->PIN_ClockWise;
	GPIO_PORTMaskedWrite_v(&L_DC_Direction_GPIO_Cfg, 0x00);

	L_DC_Direction_GPIO_Cfg.InstanceId = Arg_Config_cpcLDCMotor->GPIO_CounterClockWise;
	L_DC_Direction_GPIO_Cfg.PINs = Arg_Config_cpcLDCMotor->PIN_CounterClockWise;
	GPIO_PORTMaskedWrite_v(&L_DC_Direction_GPIO_Cfg, 0x00);
}

void DCMotor_SetDirectionToClockWise_v(DCMotor_Cfg const * const Arg_Config_cpcLDCMotor){
	GPIO_Cfg L_DC_Direction_GPIO_Cfg;
	L_DC_Direction_GPIO_Cfg.InstanceId = Arg_Config_cpcLDCMotor->GPIO_ClockWise;
	L_DC_Direction_GPIO_Cfg.PINs = Arg_Config_cpcLDCMotor->PIN_ClockWise;
	GPIO_PORTMaskedWrite_v(&L_DC_Direction_GPIO_Cfg, 0xFFFF);

	L_DC_Direction_GPIO_Cfg.InstanceId = Arg_Config_cpcLDCMotor->GPIO_CounterClockWise;
	L_DC_Direction_GPIO_Cfg.PINs = Arg_Config_cpcLDCMotor->PIN_CounterClockWise;
	GPIO_PORTMaskedWrite_v(&L_DC_Direction_GPIO_Cfg, 0x00);

}

void DCMotor_SetDirectionToCounterClockWise_v(DCMotor_Cfg const * const Arg_Config_cpcLDCMotor){
	GPIO_Cfg L_DC_Direction_GPIO_Cfg;
	L_DC_Direction_GPIO_Cfg.InstanceId = Arg_Config_cpcLDCMotor->GPIO_ClockWise;
	L_DC_Direction_GPIO_Cfg.PINs = Arg_Config_cpcLDCMotor->PIN_ClockWise;
	GPIO_PORTMaskedWrite_v(&L_DC_Direction_GPIO_Cfg, 0x00);

	L_DC_Direction_GPIO_Cfg.InstanceId = Arg_Config_cpcLDCMotor->GPIO_CounterClockWise;
	L_DC_Direction_GPIO_Cfg.PINs = Arg_Config_cpcLDCMotor->PIN_CounterClockWise;
	GPIO_PORTMaskedWrite_v(&L_DC_Direction_GPIO_Cfg, 0xFFFF);
}
/*
==================================================
  End Section --> Functions implementation.
==================================================
 */
