/*
 * File Name --> SevenSegment.c
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HAL
 * Brief	 --> Seven Segment driver implementation.
 * */
/*
==================================================
  Start Section --> File Includes
==================================================
 */
#include "SevenSegment.h"
#include "LIB/utils.h"
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
void SevenSegment_Config_v(SevenSegment_Cfg * const Arg_Config_pSevenSegment_Cfg){

	GPIO_Cfg L_led_GPIO_Cfg = {0};
	L_led_GPIO_Cfg.InstanceId = Arg_Config_pSevenSegment_Cfg->GPIOInstanceId;
	L_led_GPIO_Cfg.Mode = GPIO_MODE_OUTPUT;
	L_led_GPIO_Cfg.OutputSpeed = GPIO_OUTPUT_SPEED_LOW;
	L_led_GPIO_Cfg.OutputType = GPIO_OUTPUT_TYPE_PUSH_PULL;

	for (u8 L_i_u8 = 0 ; L_i_u8 < SEVEN_SEG_TOTAL_PINS ; L_i_u8++){
		SET_BIT(L_led_GPIO_Cfg.PINs, Arg_Config_pSevenSegment_Cfg->PinsArr[L_i_u8]);
	}
	L_led_GPIO_Cfg.PullUpPullDownResistor = GPIO_RESISTOR_NO_PULL;
	GPIO_Config_v(&L_led_GPIO_Cfg);
}

void SevenSegment_DisplayValue_v(SevenSegment_Cfg * const Arg_Config_pSevenSegment_Cfg, const u8 Arg_DispVal_u8){
	if (Arg_DispVal_u8 >= 10){
		return ;
	}

	static const u8 LS_SevenSegmentPinsState_u8[] = {
			SEVEN_SEG_VAL_0,
			SEVEN_SEG_VAL_1,
			SEVEN_SEG_VAL_2,
			SEVEN_SEG_VAL_3,
			SEVEN_SEG_VAL_4,
			SEVEN_SEG_VAL_5,
			SEVEN_SEG_VAL_6,
			SEVEN_SEG_VAL_7,
			SEVEN_SEG_VAL_8,
			SEVEN_SEG_VAL_9};

	GPIO_Cfg L_SevenSegment_GPIO_Cfg;
	L_SevenSegment_GPIO_Cfg.InstanceId = Arg_Config_pSevenSegment_Cfg->GPIOInstanceId;

	if (COMMON_MODE_CATHODE == Arg_Config_pSevenSegment_Cfg->CommonMode){
		for (u8 L_i_u8=0 ; L_i_u8 < SEVEN_SEG_TOTAL_PINS; L_i_u8++){
			if (STD_HIGH == GET_BIT(LS_SevenSegmentPinsState_u8[Arg_DispVal_u8], L_i_u8)){
				GPIO_PinWrite_v(&L_SevenSegment_GPIO_Cfg, Arg_Config_pSevenSegment_Cfg->PinsArr[L_i_u8], STD_HIGH);
			}
			else{
				GPIO_PinWrite_v(&L_SevenSegment_GPIO_Cfg, Arg_Config_pSevenSegment_Cfg->PinsArr[L_i_u8], STD_LOW);
			}
		}
	}

	if (COMMON_MODE_ANODE == Arg_Config_pSevenSegment_Cfg->CommonMode){
		for (u8 L_i_u8=0 ; L_i_u8 < SEVEN_SEG_TOTAL_PINS; L_i_u8++){
			if (STD_LOW == GET_BIT(LS_SevenSegmentPinsState_u8[Arg_DispVal_u8], L_i_u8)){
				GPIO_PinWrite_v(&L_SevenSegment_GPIO_Cfg, Arg_Config_pSevenSegment_Cfg->PinsArr[L_i_u8], STD_HIGH);
			}
			else{
				GPIO_PinWrite_v(&L_SevenSegment_GPIO_Cfg, Arg_Config_pSevenSegment_Cfg->PinsArr[L_i_u8], STD_LOW);
			}
		}
	}

}

void SevenSegment_TurnOFFDisplay_v(SevenSegment_Cfg * const Arg_Config_pSevenSegment_Cfg){
	GPIO_Cfg L_SevenSegment_GPIO_Cfg;
	L_SevenSegment_GPIO_Cfg.InstanceId = Arg_Config_pSevenSegment_Cfg->GPIOInstanceId;
	for (u8 L_i_u8=0 ; L_i_u8 < SEVEN_SEG_TOTAL_PINS; L_i_u8++){
		GPIO_PinWrite_v(&L_SevenSegment_GPIO_Cfg, Arg_Config_pSevenSegment_Cfg->PinsArr[L_i_u8], STD_LOW);
	}
}

/*
==================================================
  End Section --> Functions implementation.
==================================================
 */
