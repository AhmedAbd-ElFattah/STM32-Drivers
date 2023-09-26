/*
 * File Name --> Buzzer.c
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HAL
 * Brief	 --> Buzzer driver implementation.
 * */
/*
==================================================
  Start Section --> File Includes
==================================================
 */
#include "LIB/Delay/Delay.h"
#include "HMCAL/TIM/TIM.h"
#include "Buzzer.h"
/*
==================================================
  End   Section --> File Includes
==================================================
 */


/*
==================================================
  Start Section --> Functions implementation.
==================================================
 */
void Buzzer_Config_v(Buzzer_Cfg const * const Arg_Config_cpcLBuzzer){
	TIM_Cfg L_BuzzerTIM_Cfg = {0};

	L_BuzzerTIM_Cfg.InstanceId = Arg_Config_cpcLBuzzer->TimerInstanceId;
	switch (Arg_Config_cpcLBuzzer->Channel){
	case 1:
		L_BuzzerTIM_Cfg.ActiveChannels |= TIM_ACTIVE_CHANNELS_CH1_OUT;
		L_BuzzerTIM_Cfg.Channel1Mode = TIM_CHANNEL_MODE_OUTPUT_PWM_ACTIVE_HIGH;
		L_BuzzerTIM_Cfg.Channel1CaptureCompare = Arg_Config_cpcLBuzzer->AutoReloadValue*Arg_Config_cpcLBuzzer->PWM/100;
		break;
	case 2:
		L_BuzzerTIM_Cfg.ActiveChannels |= TIM_ACTIVE_CHANNELS_CH2_OUT;
		L_BuzzerTIM_Cfg.Channel2Mode = TIM_CHANNEL_MODE_OUTPUT_PWM_ACTIVE_HIGH;
		L_BuzzerTIM_Cfg.Channel2CaptureCompare = Arg_Config_cpcLBuzzer->AutoReloadValue*Arg_Config_cpcLBuzzer->PWM/100;
		break;
	case 3:
		L_BuzzerTIM_Cfg.ActiveChannels |= TIM_ACTIVE_CHANNELS_CH3_OUT;
		L_BuzzerTIM_Cfg.Channel3Mode = TIM_CHANNEL_MODE_OUTPUT_PWM_ACTIVE_HIGH;
		L_BuzzerTIM_Cfg.Channel3CaptureCompare = Arg_Config_cpcLBuzzer->AutoReloadValue*Arg_Config_cpcLBuzzer->PWM/100;
		break;
	case 4:
		L_BuzzerTIM_Cfg.ActiveChannels |= TIM_ACTIVE_CHANNELS_CH4_OUT;
		L_BuzzerTIM_Cfg.Channel4Mode = TIM_CHANNEL_MODE_OUTPUT_PWM_ACTIVE_HIGH;
		L_BuzzerTIM_Cfg.Channel4CaptureCompare = Arg_Config_cpcLBuzzer->AutoReloadValue*Arg_Config_cpcLBuzzer->PWM/100;
		break;

	}

	L_BuzzerTIM_Cfg.AutoReloadValue = Arg_Config_cpcLBuzzer->AutoReloadValue;
	L_BuzzerTIM_Cfg.Prescaler = Arg_Config_cpcLBuzzer->Prescaler;
	L_BuzzerTIM_Cfg.GPIOInstanceId = Arg_Config_cpcLBuzzer->GPIOInstanceId;
	SET_BIT(L_BuzzerTIM_Cfg.GPIOPins, Arg_Config_cpcLBuzzer->PINId);
	/*Apply timer configurations.*/
	TIM_Config_v(&L_BuzzerTIM_Cfg);
	TIM_StartTimer_v(&L_BuzzerTIM_Cfg);
}

void Buzzer_ChangeFrequencyAndPWM_v(Buzzer_Cfg const * const Arg_Config_cpcLBuzzer){
	TIM_Cfg L_BuzzerTIM_Cfg = {0};

	L_BuzzerTIM_Cfg.InstanceId = Arg_Config_cpcLBuzzer->TimerInstanceId;
	TIM_SetPrescalerValue_v(&L_BuzzerTIM_Cfg, Arg_Config_cpcLBuzzer->Prescaler);
	TIM_SetAutoReloadValue_v(&L_BuzzerTIM_Cfg, Arg_Config_cpcLBuzzer->AutoReloadValue);
	switch (Arg_Config_cpcLBuzzer->Channel){
	case 1:
		L_BuzzerTIM_Cfg.Channel1CaptureCompare = Arg_Config_cpcLBuzzer->AutoReloadValue*Arg_Config_cpcLBuzzer->PWM/100;
		break;
	case 2:
		L_BuzzerTIM_Cfg.Channel2CaptureCompare = Arg_Config_cpcLBuzzer->AutoReloadValue*Arg_Config_cpcLBuzzer->PWM/100;
		break;
	case 3:
		L_BuzzerTIM_Cfg.Channel3CaptureCompare = Arg_Config_cpcLBuzzer->AutoReloadValue*Arg_Config_cpcLBuzzer->PWM/100;
		break;
	case 4:
		L_BuzzerTIM_Cfg.Channel4CaptureCompare = Arg_Config_cpcLBuzzer->AutoReloadValue*Arg_Config_cpcLBuzzer->PWM/100;
		break;

	}

}
/*
==================================================
  End Section --> Functions implementation.
==================================================
 */
