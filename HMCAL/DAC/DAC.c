/*
 * File Name --> DAC.c
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> DAC driver implementation.
 * */



/*
==================================================
  Start Section --> File Includes
==================================================
 */
#include "DAC.h"
#include "DAC_defs.h"
#include "DAC_Private.h"
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
#define DAC_ID(id) ((volatile DAC_MemMap*const)(GCS_DAC_InstanceIdMapping_u32[((id)-1)]))
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

void DAC_Config_v(DAC_Cfg const * const Arg_conf_cpcDAC_Cfg){
	GPIO_Cfg L_GPIO_GPIO_Cfg = {0};
	L_GPIO_GPIO_Cfg.Mode = GPIO_MODE_ANALOG;
	L_GPIO_GPIO_Cfg.OutputSpeed = GPIO_OUTPUT_SPEED_LOW;
	L_GPIO_GPIO_Cfg.OutputType = GPIO_OUTPUT_TYPE_PUSH_PULL;
	L_GPIO_GPIO_Cfg.PullUpPullDownResistor = GPIO_RESISTOR_NO_PULL;
	L_GPIO_GPIO_Cfg.PINs = Arg_conf_cpcDAC_Cfg->GPIOPins;
	L_GPIO_GPIO_Cfg.InstanceId = Arg_conf_cpcDAC_Cfg->GPIOInstanceId;
	GPIO_Config_v(&L_GPIO_GPIO_Cfg);
	/*Reset Section*/
	switch(Arg_conf_cpcDAC_Cfg->Channel){
	case DAC_CHANNEL_1:
		DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->CR 		&=(0xFFFF0000);
		DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->SWTRIGR 	&=(0b10);
		DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->DHR12R1  = 0;
		DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->DHR12L1  = 0;
		DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->DHR8R1  	= 0;
		DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->DHR12RD  &=(0xFFFF0000);
		DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->DHR12LD  &=(0xFFFF0000);
		DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->DHR8RD   &=(0xFF00);
		DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->DOR1  	= 0;
		/*Write to clear pending flag.*/
		SET_BIT(DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->SR, DAC_SR_DMAUDR1);
		/*Reset bit*/
		CLEAR_BIT(DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->SR, DAC_SR_DMAUDR1);

		break;

	case DAC_CHANNEL_2:
		DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->CR 		&=(0x0000FFFF);
		DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->SWTRIGR 	&=(0b01);
		DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->DHR12R2  = 0;
		DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->DHR12L2  = 0;
		DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->DHR8R2  	= 0;
		DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->DHR12RD  &=(0x0000FFFF);
		DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->DHR12LD  &=(0x0000FFFF);
		DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->DHR8RD   &=(0x00FF);
		DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->DOR2  	= 0;
		/*Write to clear pending flag.*/
		SET_BIT(DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->SR, DAC_SR_DMAUDR2);
		/*Reset bit*/
		CLEAR_BIT(DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->SR, DAC_SR_DMAUDR2);
		break;
	}

	RCC_EnableClock_v(
			RCC_GetPeripheralBus_u8((u32)DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)),
			RCC_GetRCCDACBit_u8(Arg_conf_cpcDAC_Cfg->InstanceId));

	switch(Arg_conf_cpcDAC_Cfg->Channel){
	case DAC_CHANNEL_1:
		/*Wave Generation configurations section.*/
		switch (Arg_conf_cpcDAC_Cfg->WaveGeneration){
		case DAC_WAVE_GENERATION_DISABLE:
			CLEAR_BIT(DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->CR, DAC_CR_WAVE1_0);
			CLEAR_BIT(DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->CR, DAC_CR_WAVE1_1);
			break;
		case DAC_WAVE_GENERATION_NOISE:
			SET_BIT(DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->CR, DAC_CR_WAVE1_0);
			CLEAR_BIT(DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->CR, DAC_CR_WAVE1_1);
			break;
		case DAC_WAVE_GENERATION_TRIANGLE:
			CLEAR_BIT(DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->CR, DAC_CR_WAVE1_0);
			SET_BIT(DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->CR, DAC_CR_WAVE1_1);
			break;
		}

		/*Buffer configurations section.*/
		switch (Arg_conf_cpcDAC_Cfg->Buffer){
		case DAC_BUFFER_DISABLE:
			CLEAR_BIT(DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->CR, DAC_CR_BOFF1);
			break;
		case DAC_BUFFER_ENABLE:
			SET_BIT(DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->CR, DAC_CR_BOFF1);
			break;
		}
		/*DMA configurations section.*/
		switch(Arg_conf_cpcDAC_Cfg->DMA){
		case DAC_DMA_DISABLE:
			CLEAR_BIT(DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->CR, DAC_CR_DMAEN1);
			break;
		case DAC_DMA_ENABLE:
			SET_BIT(DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->CR, DAC_CR_DMAEN1);
			break;
		}
		/*Amplitude Divisor configurations section.*/
		DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->CR |= (Arg_conf_cpcDAC_Cfg->AmplitudeDivideBy)<<8;

		/*Trigger configurations section.*/
		if (Arg_conf_cpcDAC_Cfg->Trigger){
			SET_BIT(DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->CR,DAC_CR_TEN1);
			DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->CR |= (Arg_conf_cpcDAC_Cfg->Trigger-1)<<3;
		}
		break;/**/

		case DAC_CHANNEL_2:
			/*Wave Generation configurations section.*/
			switch (Arg_conf_cpcDAC_Cfg->WaveGeneration){
			case DAC_WAVE_GENERATION_DISABLE:
				CLEAR_BIT(DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->CR, DAC_CR_WAVE2_0);
				CLEAR_BIT(DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->CR, DAC_CR_WAVE2_1);
				break;
			case DAC_WAVE_GENERATION_NOISE:
				SET_BIT(DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->CR, DAC_CR_WAVE2_0);
				CLEAR_BIT(DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->CR, DAC_CR_WAVE2_1);
				break;
			case DAC_WAVE_GENERATION_TRIANGLE:
				CLEAR_BIT(DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->CR, DAC_CR_WAVE2_0);
				SET_BIT(DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->CR, DAC_CR_WAVE2_1);
				break;
			}

			/*Buffer configurations section.*/
			switch (Arg_conf_cpcDAC_Cfg->Buffer){
			case DAC_BUFFER_DISABLE:
				CLEAR_BIT(DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->CR, DAC_CR_BOFF2);
				break;
			case DAC_BUFFER_ENABLE:
				SET_BIT(DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->CR, DAC_CR_BOFF2);
				break;
			}
			/*DMA configurations section.*/
			switch(Arg_conf_cpcDAC_Cfg->DMA){
			case DAC_DMA_DISABLE:
				CLEAR_BIT(DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->CR, DAC_CR_DMAEN2);
				break;
			case DAC_DMA_ENABLE:
				SET_BIT(DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->CR, DAC_CR_DMAEN2);
				break;
			}
			/*Amplitude Divisor configurations section.*/
			DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->CR |= (Arg_conf_cpcDAC_Cfg->AmplitudeDivideBy)<<24;

			/*Trigger configurations section.*/
			if (Arg_conf_cpcDAC_Cfg->Trigger){
				SET_BIT(DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->CR,DAC_CR_TEN2);
				DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->CR |= (Arg_conf_cpcDAC_Cfg->Trigger-1)<<19;
			}
			break;/**/
	}

}

void DAC_EnableDAC_v(DAC_Cfg const * const Arg_conf_cpcDAC_Cfg){
	switch(Arg_conf_cpcDAC_Cfg->Channel){
	case DAC_CHANNEL_1:
		SET_BIT(DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->CR, DAC_CR_EN1);
		break;

	case DAC_CHANNEL_2:
		SET_BIT(DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->CR, DAC_CR_EN2);
		break;
	}
}

void DAC_DisableDAC_v(DAC_Cfg const * const Arg_conf_cpcDAC_Cfg){
	switch(Arg_conf_cpcDAC_Cfg->Channel){
	case DAC_CHANNEL_1:
		CLEAR_BIT(DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->CR, DAC_CR_EN1);
		break;

	case DAC_CHANNEL_2:
		CLEAR_BIT(DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->CR, DAC_CR_EN2);
		break;
	}
}


void DAC_SetOutputValue_v(DAC_Cfg const * const Arg_conf_cpcDAC_Cfg, u16 Arg_OutputValue_u16){
	switch(Arg_conf_cpcDAC_Cfg->Channel){
	case DAC_CHANNEL_1:
		DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->DHR12R1 = Arg_OutputValue_u16;
		break;

	case DAC_CHANNEL_2:
		DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->DHR12R2 = Arg_OutputValue_u16;
		break;
	}
}

void DAC_SoftwareTrigger_v(DAC_Cfg const * const Arg_conf_cpcDAC_Cfg){
	switch(Arg_conf_cpcDAC_Cfg->Channel){
	case DAC_CHANNEL_1:
		SET_BIT(DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->SWTRIGR, DAC_SWTRIGR_SWTRIG1);
		break;

	case DAC_CHANNEL_2:
		SET_BIT(DAC_ID(Arg_conf_cpcDAC_Cfg->InstanceId)->SWTRIGR, DAC_SWTRIGR_SWTRIG2);
		break;
	}
}


u32 DAC_GetAddressForDMA_u32(DAC_Cfg const * const Arg_conf_cpcDAC_Cfg){
	u8 L_Channel_u8 = Arg_conf_cpcDAC_Cfg->Channel;
	u32 L_DACAddress_u32;

	switch(L_Channel_u8){
	case DAC_CHANNEL_1:
		L_DACAddress_u32 = (u32)&DAC_ID(1)->DHR12R1;
		break;

	case DAC_CHANNEL_2:
		L_DACAddress_u32 = (u32)&DAC_ID(1)->DHR12R2;
		break;

	default:
		break;
	}

	return L_DACAddress_u32;
}
/*
==================================================
  End   Section --> Functions implementation.
==================================================
 */

