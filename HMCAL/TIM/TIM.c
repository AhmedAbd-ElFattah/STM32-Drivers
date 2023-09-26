/*
 * File Name --> TIM.c
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> TIM driver implementation.
 * */


/*
==================================================
  Start Section --> File Includes
==================================================
 */
#include "TIM.h"
#include "TIM_defs.h"
#include "TIM_Private.h"
#include "HMCAL/RCC/RCC.h"
#include "HMCAL/GPIO/GPIO.h"
#include "LMCAL/SYSTICK/SYSTICK.h"
#include "LIB/utils.h"
/*
==================================================
  End   Section --> File Includes
==================================================
 */


/*
==================================================
  Start Section --> Macro to map Instance Id with it's physical address.
==================================================
 */
#define TIM_ID(id) ((volatile TIM_MemMap*const)(GCS_TIM_InstanceIdMapping_u32[((id)-1)]))
/*
==================================================
  End   Section --> Macro to map Instance Id with it's physical address.
==================================================
 */


/*
==================================================
  Start Section --> Functions implementation.
==================================================
 */

void TIM_Config_v(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg){
	GPIO_Cfg L_TIMGPIOCfg_GPIO_Cfg;
	L_TIMGPIOCfg_GPIO_Cfg.InstanceId = Arg_conf_cpcTIM_Cfg->GPIOInstanceId;
	L_TIMGPIOCfg_GPIO_Cfg.Mode = GPIO_MODE_ALTERNATE_FUNCTION;
	L_TIMGPIOCfg_GPIO_Cfg.PINs = Arg_conf_cpcTIM_Cfg->GPIOPins;
	L_TIMGPIOCfg_GPIO_Cfg.OutputSpeed = GPIO_OUTPUT_SPEED_HIGH;
	L_TIMGPIOCfg_GPIO_Cfg.OutputType = GPIO_OUTPUT_TYPE_PUSH_PULL;
	L_TIMGPIOCfg_GPIO_Cfg.PullUpPullDownResistor = GPIO_RESISTOR_NO_PULL;

	/*Mapping Pins*/
	u8 L_TIMMappingPins[] = {
			TIM1_MAP_PIN,
			TIM2_MAP_PIN,
			TIM3_MAP_PIN,
			TIM4_MAP_PIN,
			TIM5_MAP_PIN,
			0, // TIM6 hasn't pins on GPIO.
			0, // TIM7 hasn't pins on GPIO.
			TIM8_MAP_PIN,
			TIM9_MAP_PIN,
			TIM10_MAP_PIN,
			TIM11_MAP_PIN,
			TIM12_MAP_PIN,
			TIM13_MAP_PIN,
			TIM14_MAP_PIN,
	};

	for (u8 L_i_u8 = 0; L_i_u8<16; L_i_u8++){
		if (STD_TRUE == GET_BIT(Arg_conf_cpcTIM_Cfg->GPIOPins, L_i_u8)){
			GPIO_MapGPIOPIN_v(&L_TIMGPIOCfg_GPIO_Cfg,
					L_i_u8,
					L_TIMMappingPins[Arg_conf_cpcTIM_Cfg->InstanceId-1]);
		}
	}

	GPIO_Config_v(&L_TIMGPIOCfg_GPIO_Cfg);



	/*
	 * To reduce the headache on user of enabling clock of the used peripheral.
	 * It 's automatically enabled before configuring the peripheral.
	 * */

	RCC_EnableClock_v(
			RCC_GetPeripheralBus_u8((u32)TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)),
			RCC_GetRCCTimerBit_u8(Arg_conf_cpcTIM_Cfg->InstanceId));


	/*
	 * To optimize code size and execution time.
	 * These variables are defined by their corresponding register reset value,
	 * and set/clear only bits that differ from reset value.
	 * */
	u32 L_CR1_Reg_Val_u32 	= TIM_CR1_RESET_VALUE;
	u32 L_CR2_Reg_Val_u32 	= TIM_CR2_RESET_VALUE;
	u32 L_SMCR_Reg_Val_u32	= TIM_SMCR_RESET_VALUE;
	u32 L_DIER_Reg_Val_u32	= TIM_DIER_RESET_VALUE;
	u32 L_SR_Reg_Val_u32	= TIM_SR_RESET_VALUE;
	u32 L_EGR_Reg_Val_u32 	= TIM_EGR_RESET_VALUE;
	u32 L_CCMR1_Reg_Val_u32 = TIM_CCMR1_RESET_VALUE;
	u32 L_CCMR2_Reg_Val_u32 = TIM_CCMR2_RESET_VALUE;
	u32 L_CCER_Reg_Val_u32 	= TIM_CCER_RESET_VALUE;
	u32 L_CNT_Reg_Val_u32 	= TIM_CNT_RESET_VALUE;
	u32 L_PSC_Reg_Val_u32 	= TIM_PSC_RESET_VALUE;
	u32 L_ARR_Reg_Val_u32 	= TIM_ARR_RESET_VALUE;
	u32 L_RCR_Reg_Val_u32 	= TIM_RCR_RESET_VALUE;
	u32 L_BDTR_Reg_Val_u32	= TIM_BDTR_RESET_VALUE;
	u32 L_DCR_Reg_Val_u32	= TIM_DCR_RESET_VALUE;
	u32 L_DMAR_Reg_Val_u32	= TIM_DMAR_RESET_VALUE;

	switch (Arg_conf_cpcTIM_Cfg->Preload){
	case TIM_PRELOAD_NOT_BUFFERED:

		break;
	case TIM_PRELOAD_BUFFERED:
		SET_BIT(L_CR1_Reg_Val_u32, TIM_CR1_ARPE);
		break;
	default :
		break;
	}

	switch (Arg_conf_cpcTIM_Cfg->OnePulseMode){
	case TIM_ONE_PULSE_DISABLE:

		break;

	case TIM_ONE_PULSE_ENABLE:
		SET_BIT(L_CR1_Reg_Val_u32, TIM_CR1_OPM);
		break;
	default :
		break;

	}

	switch (Arg_conf_cpcTIM_Cfg->MasterMode){
	case TIM_MASTER_MODE_DISABLE:

		break;
	case TIM_MASTER_MODE_RESET:

		break;
	case TIM_MASTER_MODE_ENABLE:
		SET_BIT(L_CR2_Reg_Val_u32, TIM_CR2_MMS_0);

		break;
	case TIM_MASTER_MODE_UPDATE:

		SET_BIT(L_CR2_Reg_Val_u32, TIM_CR2_MMS_1);

		break;
	default:
		break;
	}

	/*Channel Mode Configurations*/
	L_CCMR1_Reg_Val_u32 = (Arg_conf_cpcTIM_Cfg->Channel1Mode | (Arg_conf_cpcTIM_Cfg->Channel2Mode << 8));
	L_CCMR2_Reg_Val_u32 = (Arg_conf_cpcTIM_Cfg->Channel3Mode | (Arg_conf_cpcTIM_Cfg->Channel4Mode << 8));


	/*Channel 1 output configurations*/
	if (STD_FALSE != (Arg_conf_cpcTIM_Cfg->ActiveChannels & TIM_ACTIVE_CHANNELS_CH1_OUT)){
		SET_BIT(L_CCER_Reg_Val_u32, TIM_CCER_CC1E);
	}
	else{

	}

	/*Channel 2 output configurations*/
	if (STD_FALSE != (Arg_conf_cpcTIM_Cfg->ActiveChannels & TIM_ACTIVE_CHANNELS_CH2_OUT)){
		SET_BIT(L_CCER_Reg_Val_u32, TIM_CCER_CC2E);
	}
	else{

	}

	/*Channel 3 output configurations*/
	if (STD_FALSE != (Arg_conf_cpcTIM_Cfg->ActiveChannels & TIM_ACTIVE_CHANNELS_CH3_OUT)){
		SET_BIT(L_CCER_Reg_Val_u32, TIM_CCER_CC3E);
	}
	else{

	}

	/*Channel 4 output configurations*/
	if (STD_FALSE != (Arg_conf_cpcTIM_Cfg->ActiveChannels & TIM_ACTIVE_CHANNELS_CH4_OUT)){
		SET_BIT(L_CCER_Reg_Val_u32, TIM_CCER_CC4E);
	}
	else{

	}

	TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->CR1 = L_CR1_Reg_Val_u32;
	TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->CR2 = L_CR2_Reg_Val_u32;

	TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->CCR1 = Arg_conf_cpcTIM_Cfg->Channel1CaptureCompare;
	TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->CCR2 = Arg_conf_cpcTIM_Cfg->Channel2CaptureCompare;
	TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->CCR3 = Arg_conf_cpcTIM_Cfg->Channel3CaptureCompare;
	TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->CCR4 = Arg_conf_cpcTIM_Cfg->Channel4CaptureCompare;

	TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->SMCR = L_SMCR_Reg_Val_u32;
	TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->DIER = L_DIER_Reg_Val_u32;
	TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->SR   = L_SR_Reg_Val_u32;


	TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->EGR = L_EGR_Reg_Val_u32;
	TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->CCMR1 = L_CCMR1_Reg_Val_u32;
	TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->CCMR2 = L_CCMR2_Reg_Val_u32;
	TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->CCER = L_CCER_Reg_Val_u32;
	TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->CNT = L_CNT_Reg_Val_u32;
	TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->PSC = L_PSC_Reg_Val_u32;
	TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->ARR = L_ARR_Reg_Val_u32;
	TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->RCR = L_RCR_Reg_Val_u32;
	TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->BDTR = L_BDTR_Reg_Val_u32;
	TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->DCR = L_DCR_Reg_Val_u32;
	TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->DMAR = L_DMAR_Reg_Val_u32;

	TIM_SetAutoReloadValue_v(Arg_conf_cpcTIM_Cfg, Arg_conf_cpcTIM_Cfg->AutoReloadValue);
	TIM_SetPrescalerValue_v(Arg_conf_cpcTIM_Cfg, Arg_conf_cpcTIM_Cfg->Prescaler);
	TIM_ResetCounter_v(Arg_conf_cpcTIM_Cfg);

}
void TIM_SetAutoReloadValue_v(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg, u16 Arg_Value_u16){
	TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->ARR = Arg_Value_u16;
}

u16 TIM_GetAutoReloadValue_u16(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg){
	return TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->ARR;
}

void TIM_SetPrescalerValue_v(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg, u16 Arg_Value_u16){
	TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->PSC = Arg_Value_u16;
}

u16 TIM_GetPrescalerValue_u16(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg){
	return TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->PSC;
}

void TIM_SetCounterValue_v(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg, u16 Arg_Value_u16){
	TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->CNT = Arg_Value_u16;
}



void TIM_SetOutputCompare1Value_v(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg, u16 Arg_Value_u16){
	TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->CCR1 = Arg_Value_u16;
}

u16 TIM_GetOutputCompare1Value_u16(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg){
	return TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->CCR1;
}

void TIM_SetOutputCompare2Value_v(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg, u16 Arg_Value_u16){
	TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->CCR2 = Arg_Value_u16;
}

u16 TIM_GetOutputCompare2Value_u16(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg){
	return TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->CCR2;
}

void TIM_SetOutputCompare3Value_v(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg, u16 Arg_Value_u16){
	TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->CCR3 = Arg_Value_u16;
}

u16 TIM_GetOutputCompare3Value_u16(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg){
	return TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->CCR3;
}

void TIM_SetOutputCompare4Value_v(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg, u16 Arg_Value_u16){
	TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->CCR4 = Arg_Value_u16;
}

u16 TIM_GetOutputCompare4Value_u16(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg){
	return TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->CCR4;
}


u16 TIM_GetCounterValue_u16(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg){
	return TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->CNT;
}

void TIM_ResetCounter_v(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg){
	TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->CNT = 0;
}
void TIM_StartTimer_v(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg){

	while (STD_FALSE == GET_BIT(TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->CR1, TIM_CR1_CEN)){
		SET_BIT(TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->CR1, TIM_CR1_CEN);
	}

}
void TIM_StopTimer_v(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg){
	CLEAR_BIT(TIM_ID(Arg_conf_cpcTIM_Cfg->InstanceId)->CR1, TIM_CR1_CEN);
}
/*
==================================================
  End Section --> Functions implementation.
==================================================
 */
