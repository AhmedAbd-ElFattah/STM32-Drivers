/*
 * File Name --> ADC.c
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> ADC driver implementation.
 * */



/*
==================================================
  Start Section --> File Includes
==================================================
 */
#include "ADC.h"
#include "ADC_defs.h"
#include "ADC_Private.h"
#include "HMCAL/GPIO/GPIO.h"
#include "HMCAL/RCC/RCC.h"
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
#define ADC_ID(id) ((volatile ADC_MemMap*const)(GCS_ADC_InstanceIdMapping_u32[((id)-1)]))
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
void ADC_Config_v(ADC_Cfg const * const Arg_conf_cpcADC_Cfg){

	GPIO_Cfg L_GPIO_GPIO_Cfg = {0};
	L_GPIO_GPIO_Cfg.Mode = GPIO_MODE_ANALOG;
	L_GPIO_GPIO_Cfg.OutputSpeed = GPIO_OUTPUT_SPEED_LOW;
	L_GPIO_GPIO_Cfg.OutputType = GPIO_OUTPUT_TYPE_PUSH_PULL;
	L_GPIO_GPIO_Cfg.PullUpPullDownResistor = GPIO_RESISTOR_NO_PULL;

	u8 L_InstanceId_u8, L_PINId_u8;
	for (u8 Local_i_u8 = 0; Local_i_u8 < Arg_conf_cpcADC_Cfg->ConversionLength;Local_i_u8++){
		L_InstanceId_u8 = (Arg_conf_cpcADC_Cfg->ConversionChannels[Local_i_u8]>>16)&0xFF;

		L_PINId_u8 = (1<<((Arg_conf_cpcADC_Cfg->ConversionChannels[Local_i_u8]>>8)&0xFF));
		L_GPIO_GPIO_Cfg.PINs = L_PINId_u8;
		L_GPIO_GPIO_Cfg.InstanceId = L_InstanceId_u8;
		GPIO_Config_v(&L_GPIO_GPIO_Cfg);
	}

	RCC_EnableClock_v(
			RCC_GetPeripheralBus_u8((u32)ADC_ID(Arg_conf_cpcADC_Cfg->InstanceId)),
			RCC_GetRCCADCBit_u8(Arg_conf_cpcADC_Cfg->InstanceId));



	u32 L_SR_Reg_Val_u32  = ADC_SR_RESET_VALUE;
	u32 L_CR1_Reg_Val_u32 = ADC_CR1_RESET_VALUE;
	u32 L_CR2_Reg_Val_u32 = ADC_CR2_RESET_VALUE;
	u32 L_SMPR1_Reg_Val_u32 = ADC_SMPR1_RESET_VALUE;
	u32 L_SMPR2_Reg_Val_u32 = ADC_SMPR2_RESET_VALUE;
	u32 L_JOFR1_Reg_Val_u32 = ADC_JOFR1_RESET_VALUE;
	u32 L_JOFR2_Reg_Val_u32 = ADC_JOFR2_RESET_VALUE;
	u32 L_JOFR3_Reg_Val_u32 = ADC_JOFR3_RESET_VALUE;
	u32 L_JOFR4_Reg_Val_u32 = ADC_JOFR4_RESET_VALUE;
	u32 L_HTR_Reg_Val_u32   = ADC_HTR_RESET_VALUE;
	u32 L_LTR_Reg_Val_u32   = ADC_LTR_RESET_VALUE;
	u32 L_SQR1_Reg_Val_u32  = ADC_SQR1_RESET_VALUE;
	u32 L_SQR2_Reg_Val_u32  = ADC_SQR2_RESET_VALUE;
	u32 L_SQR3_Reg_Val_u32  = ADC_SQR3_RESET_VALUE;
	u32 L_JSQR_Reg_Val_u32  = ADC_JSQR_RESET_VALUE;
	u32 L_JDR1_Reg_Val_u32  = ADC_JDR1_RESET_VALUE;
	u32 L_JDR2_Reg_Val_u32  = ADC_JDR2_RESET_VALUE;
	u32 L_JDR3_Reg_Val_u32  = ADC_JDR3_RESET_VALUE;
	u32 L_JDR4_Reg_Val_u32  = ADC_JDR4_RESET_VALUE;



	/*Resolution*/
	switch(Arg_conf_cpcADC_Cfg->Resolution){
	case ADC_RES_12_BIT:

		break;
	case ADC_RES_10_BIT:
		SET_BIT(L_CR1_Reg_Val_u32, ADC_CR1_RES_0);

		break;
	case ADC_RES_8_BIT:

		SET_BIT(L_CR1_Reg_Val_u32, ADC_CR1_RES_1);
		break;
	case ADC_RES_6_BIT:
		SET_BIT(L_CR1_Reg_Val_u32, ADC_CR1_RES_0);
		SET_BIT(L_CR1_Reg_Val_u32, ADC_CR1_RES_1);
		break;
	default:
		/*Error*/
		break;

	}
	/*Continuous*/
	if (Arg_conf_cpcADC_Cfg->ConversionLength > 1){
		SET_BIT(L_CR1_Reg_Val_u32, ADC_CR1_SCAN);
	}
	else{

	}
	//		switch (Arg_config_ADC_Configurations->ContinuousScanEnable){
	//		case ADC_CONT_SCAN_DISABLE:
	//			CLEAR_BIT(L_CR1_Reg_Val_u32, ADC_CR1_SCAN);
	//			break;
	//		case ADC_CONT_SCAN_ENABLE:
	//			SET_BIT(L_CR1_Reg_Val_u32, ADC_CR1_SCAN);
	//			break;
	//		default:
	//			Local_error_u16 = STD_ERROR;
	//		}

	/*External Event*/
	switch(Arg_conf_cpcADC_Cfg->ExternalTriggerDetection){
	case ADC_EXT_TRIG_DETECT_DISABLED:

		break;
	case ADC_EXT_TRIG_DETECT_RISING_EDGE:
		SET_BIT(L_CR2_Reg_Val_u32, ADC_CR2_EXTEN_0);

		break;
	case ADC_EXT_TRIG_DETECT_FALLING_EDGE:

		SET_BIT(L_CR2_Reg_Val_u32, ADC_CR2_EXTEN_1);
		break;
	case ADC_EXT_TRIG_DETECT_BOTH_EDGES:
		SET_BIT(L_CR2_Reg_Val_u32, ADC_CR2_EXTEN_0);
		SET_BIT(L_CR2_Reg_Val_u32, ADC_CR2_EXTEN_1);
		break;

	}
	/*DMA*/
	switch(Arg_conf_cpcADC_Cfg->DMA){
	case ADC_DMA_DISABLE:


		break;
	case ADC_DMA_ENABLE:
		SET_BIT(L_CR2_Reg_Val_u32, ADC_CR2_DDS);
		SET_BIT(L_CR2_Reg_Val_u32, ADC_CR2_DMA);
		break;
	}

	/*Sample Time*/
	switch (Arg_conf_cpcADC_Cfg->SampleTime){
	case ADC_SAMPLE_TIME_3_CYCLES:


		break;

	case ADC_SAMPLE_TIME_15_CYCLES:
		SET_BIT(L_SMPR1_Reg_Val_u32, ADC_SMPR1_SMP10_0);


		break;

	case ADC_SAMPLE_TIME_28_CYCLES:

		SET_BIT(L_SMPR1_Reg_Val_u32, ADC_SMPR1_SMP10_1);

		break;

	case ADC_SAMPLE_TIME_56_CYCLES:
		SET_BIT(L_SMPR1_Reg_Val_u32, ADC_SMPR1_SMP10_0);
		SET_BIT(L_SMPR1_Reg_Val_u32, ADC_SMPR1_SMP10_1);

		break;

	case ADC_SAMPLE_TIME_84_CYCLES:

		SET_BIT(L_SMPR1_Reg_Val_u32, ADC_SMPR1_SMP10_2);
		break;

	case ADC_SAMPLE_TIME_112_CYCLES:
		SET_BIT(L_SMPR1_Reg_Val_u32, ADC_SMPR1_SMP10_0);

		SET_BIT(L_SMPR1_Reg_Val_u32, ADC_SMPR1_SMP10_2);
		break;

	case ADC_SAMPLE_TIME_144_CYCLES:

		SET_BIT(L_SMPR1_Reg_Val_u32, ADC_SMPR1_SMP10_1);
		SET_BIT(L_SMPR1_Reg_Val_u32, ADC_SMPR1_SMP10_2);
		break;

	case ADC_SAMPLE_TIME_480_CYCLES:
		SET_BIT(L_SMPR1_Reg_Val_u32, ADC_SMPR1_SMP10_0);
		SET_BIT(L_SMPR1_Reg_Val_u32, ADC_SMPR1_SMP10_1);
		SET_BIT(L_SMPR1_Reg_Val_u32, ADC_SMPR1_SMP10_2);
		break;
	}

	/*RegularEventTrigger*/
	switch (Arg_conf_cpcADC_Cfg->RegularEventTrigger){
	case ADC_REG_EVENT_TRIG_TIM1_CC1:

		break;
	case ADC_REG_EVENT_TRIG_TIM1_CC2:
		SET_BIT(L_CR2_Reg_Val_u32,ADC_CR2_EXTSEL_0);

		break;
	case ADC_REG_EVENT_TRIG_TIM1_CC3:

		SET_BIT(L_CR2_Reg_Val_u32,ADC_CR2_EXTSEL_1);

		break;
	case ADC_REG_EVENT_TRIG_TIM2_CC2:
		SET_BIT(L_CR2_Reg_Val_u32,ADC_CR2_EXTSEL_0);
		SET_BIT(L_CR2_Reg_Val_u32,ADC_CR2_EXTSEL_1);
;
		break;
	case ADC_REG_EVENT_TRIG_TIM2_CC3:
		SET_BIT(L_CR2_Reg_Val_u32,ADC_CR2_EXTSEL_2);

		break;
	case ADC_REG_EVENT_TRIG_TIM2_CC4:
		SET_BIT(L_CR2_Reg_Val_u32,ADC_CR2_EXTSEL_0);

		SET_BIT(L_CR2_Reg_Val_u32,ADC_CR2_EXTSEL_2);

		break;
	case ADC_REG_EVENT_TRIG_TIM2_TRGO:

		SET_BIT(L_CR2_Reg_Val_u32,ADC_CR2_EXTSEL_1);
		SET_BIT(L_CR2_Reg_Val_u32,ADC_CR2_EXTSEL_2);

		break;
	case ADC_REG_EVENT_TRIG_TIM3_CC1:
		SET_BIT(L_CR2_Reg_Val_u32,ADC_CR2_EXTSEL_0);
		SET_BIT(L_CR2_Reg_Val_u32,ADC_CR2_EXTSEL_1);
		SET_BIT(L_CR2_Reg_Val_u32,ADC_CR2_EXTSEL_2);

		break;
	case ADC_REG_EVENT_TRIG_TIM3_TRGO:

		SET_BIT(L_CR2_Reg_Val_u32,ADC_CR2_EXTSEL_3);
		break;
	case ADC_REG_EVENT_TRIG_TIM4_CC4:
		SET_BIT(L_CR2_Reg_Val_u32,ADC_CR2_EXTSEL_0);

		SET_BIT(L_CR2_Reg_Val_u32,ADC_CR2_EXTSEL_3);
		break;
	case ADC_REG_EVENT_TRIG_TIM5_CC1:

		SET_BIT(L_CR2_Reg_Val_u32,ADC_CR2_EXTSEL_1);

		SET_BIT(L_CR2_Reg_Val_u32,ADC_CR2_EXTSEL_3);
		break;
	case ADC_REG_EVENT_TRIG_TIM5_CC2:
		SET_BIT(L_CR2_Reg_Val_u32,ADC_CR2_EXTSEL_0);
		SET_BIT(L_CR2_Reg_Val_u32,ADC_CR2_EXTSEL_1);

		SET_BIT(L_CR2_Reg_Val_u32,ADC_CR2_EXTSEL_3);
		break;
	case ADC_REG_EVENT_TRIG_TIM5_CC3:

		SET_BIT(L_CR2_Reg_Val_u32,ADC_CR2_EXTSEL_2);
		SET_BIT(L_CR2_Reg_Val_u32,ADC_CR2_EXTSEL_3);
		break;
	case ADC_REG_EVENT_TRIG_TIM8_CC1:
		SET_BIT(L_CR2_Reg_Val_u32,ADC_CR2_EXTSEL_0);

		SET_BIT(L_CR2_Reg_Val_u32,ADC_CR2_EXTSEL_2);
		SET_BIT(L_CR2_Reg_Val_u32,ADC_CR2_EXTSEL_3);
		break;
	case ADC_REG_EVENT_TRIG_TIM8_TRGO:

		SET_BIT(L_CR2_Reg_Val_u32,ADC_CR2_EXTSEL_1);
		SET_BIT(L_CR2_Reg_Val_u32,ADC_CR2_EXTSEL_2);
		SET_BIT(L_CR2_Reg_Val_u32,ADC_CR2_EXTSEL_3);
		break;
	case ADC_REG_EVENT_TRIG_EXTI_LINE11:
		SET_BIT(L_CR2_Reg_Val_u32,ADC_CR2_EXTSEL_0);
		SET_BIT(L_CR2_Reg_Val_u32,ADC_CR2_EXTSEL_1);
		SET_BIT(L_CR2_Reg_Val_u32,ADC_CR2_EXTSEL_2);
		SET_BIT(L_CR2_Reg_Val_u32,ADC_CR2_EXTSEL_3);
		break;
	default:
		break;

	}

	switch (Arg_conf_cpcADC_Cfg->ConversionMode){
	case ADC_CONV_MODE_SINGLE:

		break;
	case ADC_CONV_MODE_CONTINUOUS:
		SET_BIT(L_CR2_Reg_Val_u32,ADC_CR2_CONT);
		break;
	}

	/*Regular Sequence*/

	for (u8 Local_i_u8 = 0; Local_i_u8 < Arg_conf_cpcADC_Cfg->ConversionLength;Local_i_u8++){
		if (Local_i_u8 < 6){

			L_SQR3_Reg_Val_u32 |= (Arg_conf_cpcADC_Cfg->ConversionChannels[Local_i_u8]&0xFF)<<(5*Local_i_u8);
		}
		else if(Local_i_u8 < 12){
			L_SQR2_Reg_Val_u32 |= (Arg_conf_cpcADC_Cfg->ConversionChannels[Local_i_u8]&0xFF)<<(5*(Local_i_u8-6));
		}
		else{
			L_SQR1_Reg_Val_u32 |= (Arg_conf_cpcADC_Cfg->ConversionChannels[Local_i_u8]&0xFF)<<(5*(Local_i_u8-12));
		}
	}
	L_SQR1_Reg_Val_u32 |= (Arg_conf_cpcADC_Cfg->ConversionLength-1) <<20;



	ADC_ID(Arg_conf_cpcADC_Cfg->InstanceId)->SR    = L_SR_Reg_Val_u32;
	ADC_ID(Arg_conf_cpcADC_Cfg->InstanceId)->CR1   = L_CR1_Reg_Val_u32;
	ADC_ID(Arg_conf_cpcADC_Cfg->InstanceId)->CR2   = L_CR2_Reg_Val_u32;
	ADC_ID(Arg_conf_cpcADC_Cfg->InstanceId)->SMPR1 = L_SMPR1_Reg_Val_u32;
	ADC_ID(Arg_conf_cpcADC_Cfg->InstanceId)->SMPR2 = L_SMPR2_Reg_Val_u32;
	ADC_ID(Arg_conf_cpcADC_Cfg->InstanceId)->JOFR1 = L_JOFR1_Reg_Val_u32;
	ADC_ID(Arg_conf_cpcADC_Cfg->InstanceId)->JOFR2 = L_JOFR2_Reg_Val_u32;
	ADC_ID(Arg_conf_cpcADC_Cfg->InstanceId)->JOFR3 = L_JOFR3_Reg_Val_u32;
	ADC_ID(Arg_conf_cpcADC_Cfg->InstanceId)->JOFR4 = L_JOFR4_Reg_Val_u32;
	ADC_ID(Arg_conf_cpcADC_Cfg->InstanceId)->HTR   = L_HTR_Reg_Val_u32;
	ADC_ID(Arg_conf_cpcADC_Cfg->InstanceId)->LTR   = L_LTR_Reg_Val_u32;
	ADC_ID(Arg_conf_cpcADC_Cfg->InstanceId)->SQR1  = L_SQR1_Reg_Val_u32;
	ADC_ID(Arg_conf_cpcADC_Cfg->InstanceId)->SQR2  = L_SQR2_Reg_Val_u32;
	ADC_ID(Arg_conf_cpcADC_Cfg->InstanceId)->SQR3  = L_SQR3_Reg_Val_u32;
	ADC_ID(Arg_conf_cpcADC_Cfg->InstanceId)->JSQR  = L_JSQR_Reg_Val_u32;
	ADC_ID(Arg_conf_cpcADC_Cfg->InstanceId)->JDR1  = L_JDR1_Reg_Val_u32;
	ADC_ID(Arg_conf_cpcADC_Cfg->InstanceId)->JDR2  = L_JDR2_Reg_Val_u32;
	ADC_ID(Arg_conf_cpcADC_Cfg->InstanceId)->JDR3  = L_JDR3_Reg_Val_u32;
	ADC_ID(Arg_conf_cpcADC_Cfg->InstanceId)->JDR4  = L_JDR4_Reg_Val_u32;
	ADC_ID(Arg_conf_cpcADC_Cfg->InstanceId)->DR    = ADC_DR_RESET_VALUE;

}


void ADC_StartSoftwareConversion_v(ADC_Cfg const * const Arg_conf_cpcADC_Cfg){
	SET_BIT(ADC_ID(Arg_conf_cpcADC_Cfg->InstanceId)->CR2, ADC_CR2_SWSTART);
}
void ADC_StopSoftwareConversion_v(ADC_Cfg const * const Arg_conf_cpcADC_Cfg){
	SET_BIT(ADC_ID(Arg_conf_cpcADC_Cfg->InstanceId)->CR2, ADC_CR2_SWSTART);
}

void ADC_EnableADC_v(ADC_Cfg const * const Arg_conf_cpcADC_Cfg){
	SET_BIT(ADC_ID(Arg_conf_cpcADC_Cfg->InstanceId)->CR2, ADC_CR2_ADON);
}
void ADC_DisableADC_v(ADC_Cfg const * const Arg_conf_cpcADC_Cfg){
	CLEAR_BIT(ADC_ID(Arg_conf_cpcADC_Cfg->InstanceId)->CR2, ADC_CR2_ADON);
}
u16 ADC_GetReading_u16(ADC_Cfg const * const Arg_conf_cpcADC_Cfg){
	while (!GET_BIT(ADC_ID(Arg_conf_cpcADC_Cfg->InstanceId)->SR, ADC_SR_EOC));
	u16 Local_Reading_u16 = ADC_ID(Arg_conf_cpcADC_Cfg->InstanceId)->DR;
	CLEAR_BIT(ADC_ID(Arg_conf_cpcADC_Cfg->InstanceId)->SR, ADC_SR_EOC);
	return Local_Reading_u16;
}

u32 ADC_GetAdressForDMA_u32(ADC_Cfg const * const Arg_conf_cpcADC_Cfg){
	return (u32)&ADC_ID(Arg_conf_cpcADC_Cfg->InstanceId)->DR;
}
/*
==================================================
  End   Section --> Functions implementation.
==================================================
 */

