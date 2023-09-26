/*
 * File Name --> Button.c
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HAL
 * Brief	 --> Button driver implementation.
 * */
/*
==================================================
  Start Section --> File Includes
==================================================
 */
#include "Button.h"
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


void Button_Config_v(Button_Cfg *Arg_Config_pLButton_Cfg){

	GPIO_Cfg L_button_GPIO_Cfg = {0};
	L_button_GPIO_Cfg.InstanceId = Arg_Config_pLButton_Cfg->GPIOInstanceId;
	L_button_GPIO_Cfg.Mode = GPIO_MODE_INPUT;
	L_button_GPIO_Cfg.OutputSpeed = GPIO_OUTPUT_SPEED_LOW;
	L_button_GPIO_Cfg.OutputType = GPIO_OUTPUT_TYPE_PUSH_PULL;
	L_button_GPIO_Cfg.PINs = Arg_Config_pLButton_Cfg->Pin;
	L_button_GPIO_Cfg.PullUpPullDownResistor = Arg_Config_pLButton_Cfg->PullUpPullDownResistor;
	GPIO_Config_v(&L_button_GPIO_Cfg);
}

void Button_Reset_v(Button_Cfg *Arg_Config_pLButton_Cfg){
	GPIO_Cfg L_button_GPIO_Cfg = {0};
	L_button_GPIO_Cfg.InstanceId = Arg_Config_pLButton_Cfg->GPIOInstanceId;
	L_button_GPIO_Cfg.Mode = GPIO_MODE_OUTPUT;
	L_button_GPIO_Cfg.OutputSpeed = GPIO_OUTPUT_SPEED_LOW;
	L_button_GPIO_Cfg.OutputType = GPIO_OUTPUT_TYPE_PUSH_PULL;
	L_button_GPIO_Cfg.PINs = Arg_Config_pLButton_Cfg->Pin;
	L_button_GPIO_Cfg.PullUpPullDownResistor = GPIO_RESISTOR_NO_PULL;
	GPIO_Reset_v(&L_button_GPIO_Cfg);
}

u16 Button_GetReading_u16(Button_Cfg *Arg_Config_pLButton_Cfg){
	GPIO_Cfg L_button_GPIO_Cfg = {0};
	L_button_GPIO_Cfg.InstanceId = Arg_Config_pLButton_Cfg->GPIOInstanceId;
	L_button_GPIO_Cfg.PINs = Arg_Config_pLButton_Cfg->Pin;
	L_button_GPIO_Cfg.PullUpPullDownResistor = Arg_Config_pLButton_Cfg->PullUpPullDownResistor;

	return GPIO_PORTMaskedRead_u16(&L_button_GPIO_Cfg);
}

Bool Button_GetPinReading_Bool(Button_Cfg *Arg_Config_pLButton_Cfg, u8 Arg_Pin_u8){
	GPIO_Cfg L_button_GPIO_Cfg = {0};
	L_button_GPIO_Cfg.InstanceId = Arg_Config_pLButton_Cfg->GPIOInstanceId;
	L_button_GPIO_Cfg.PINs = Arg_Config_pLButton_Cfg->Pin;
	L_button_GPIO_Cfg.PullUpPullDownResistor = Arg_Config_pLButton_Cfg->PullUpPullDownResistor;

	return GPIO_PinRead_u8(&L_button_GPIO_Cfg, Arg_Pin_u8) == STD_TRUE;
}

Bool Button_IsPressed_Bool(Button_Cfg *Arg_Config_pLButton_Cfg, u8 Arg_Pin_u8){
	GPIO_Cfg L_button_GPIO_Cfg = {0};
	L_button_GPIO_Cfg.InstanceId = Arg_Config_pLButton_Cfg->GPIOInstanceId;
	L_button_GPIO_Cfg.PINs = Arg_Config_pLButton_Cfg->Pin;
	L_button_GPIO_Cfg.PullUpPullDownResistor = Arg_Config_pLButton_Cfg->PullUpPullDownResistor;

	u8 L_Reading_u8 = GPIO_PinRead_u8(&L_button_GPIO_Cfg, Arg_Pin_u8);
	Bool L_Pressed_Bool = STD_FALSE;
	if ((STD_TRUE == L_Reading_u8) && (Arg_Config_pLButton_Cfg->PullUpPullDownResistor != Button_RESISTOR_PULL_UP)){
		L_Pressed_Bool = STD_TRUE;
	}
	if ((STD_FALSE == L_Reading_u8) && (Arg_Config_pLButton_Cfg->PullUpPullDownResistor == Button_RESISTOR_PULL_UP)){
		L_Pressed_Bool = STD_TRUE;
	}
	return  L_Pressed_Bool ;
}

/*
==================================================
  End Section --> Functions implementation.
==================================================
 */

