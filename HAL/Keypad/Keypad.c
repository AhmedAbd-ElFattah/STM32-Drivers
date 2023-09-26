/*
 * File Name --> Keypad.c
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HAL
 * Brief	 --> Keypad driver implementation.
 * */
/*
==================================================
  Start Section --> File Includes
==================================================
 */
#include "LIB/Delay/Delay.h"
#include "Keypad.h"
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
void Keypad_Config_v(Keypad_Cfg const * const Arg_Config_cpcLKeypad){
	/*Configure Rows as output.*/
	GPIO_Cfg L_KeypadRows_GPIO_Cfg = {0};
	L_KeypadRows_GPIO_Cfg.InstanceId = Arg_Config_cpcLKeypad->RowsGPIOInstanceId;
	L_KeypadRows_GPIO_Cfg.Mode = GPIO_MODE_OUTPUT;
	L_KeypadRows_GPIO_Cfg.OutputSpeed = GPIO_OUTPUT_SPEED_LOW;
	L_KeypadRows_GPIO_Cfg.OutputType = GPIO_OUTPUT_TYPE_PUSH_PULL;
	L_KeypadRows_GPIO_Cfg.PullUpPullDownResistor = Arg_Config_cpcLKeypad->PullUpDownMode;
	for (u8 L_ri_u8=0; L_ri_u8 < Arg_Config_cpcLKeypad->Rows_Number; L_ri_u8++){
		SET_BIT(L_KeypadRows_GPIO_Cfg.PINs, Arg_Config_cpcLKeypad->RowsPins[L_ri_u8]);
	}

	/*Configure Cols as input.*/
	GPIO_Cfg L_KeypadCols_GPIO_Cfg = {0};
	L_KeypadCols_GPIO_Cfg.InstanceId = Arg_Config_cpcLKeypad->ColsGPIOInstanceId;
	L_KeypadCols_GPIO_Cfg.Mode = GPIO_MODE_INPUT;
	L_KeypadCols_GPIO_Cfg.OutputSpeed = GPIO_OUTPUT_SPEED_LOW;
	L_KeypadCols_GPIO_Cfg.OutputType = GPIO_OUTPUT_TYPE_PUSH_PULL;
	L_KeypadCols_GPIO_Cfg.PullUpPullDownResistor = Arg_Config_cpcLKeypad->PullUpDownMode;

	for (u8 L_ci_u8=0; L_ci_u8 < Arg_Config_cpcLKeypad->Cols_Number; L_ci_u8++){
		SET_BIT(L_KeypadCols_GPIO_Cfg.PINs, Arg_Config_cpcLKeypad->ColsPins[L_ci_u8]);
	}

	GPIO_Config_v(&L_KeypadRows_GPIO_Cfg);
	GPIO_Config_v(&L_KeypadCols_GPIO_Cfg);

}

void Keypad_ReadKeys_v(Keypad_Cfg const * const Arg_Config_cpcLKeypad, Bool *const Arg_OutputArr_pcBool){
	GPIO_Cfg L_KeypadRows_GPIO_Cfg = {0};
	L_KeypadRows_GPIO_Cfg.InstanceId = Arg_Config_cpcLKeypad->RowsGPIOInstanceId;
	L_KeypadRows_GPIO_Cfg.PullUpPullDownResistor = Arg_Config_cpcLKeypad->PullUpDownMode;
	for (u8 L_ri_u8=0; L_ri_u8 < Arg_Config_cpcLKeypad->Rows_Number; L_ri_u8++){
		SET_BIT(L_KeypadRows_GPIO_Cfg.PINs, Arg_Config_cpcLKeypad->RowsPins[L_ri_u8]);
	}


	GPIO_Cfg L_KeypadCols_GPIO_Cfg = {0};
	L_KeypadCols_GPIO_Cfg.InstanceId = Arg_Config_cpcLKeypad->ColsGPIOInstanceId;
	L_KeypadCols_GPIO_Cfg.PullUpPullDownResistor = Arg_Config_cpcLKeypad->PullUpDownMode;

	for (u8 L_ci_u8=0; L_ci_u8 < Arg_Config_cpcLKeypad->Cols_Number; L_ci_u8++){
		SET_BIT(L_KeypadCols_GPIO_Cfg.PINs, Arg_Config_cpcLKeypad->ColsPins[L_ci_u8]);
	}


	for (u8 L_ri_u8=0; L_ri_u8 < Arg_Config_cpcLKeypad->Rows_Number; L_ri_u8++){
		/*Set row pin --> high*/
		GPIO_PinWrite_v(&L_KeypadRows_GPIO_Cfg, Arg_Config_cpcLKeypad->RowsPins[L_ri_u8], STD_HIGH);
		Delay_DelayInMilliSecondsBlocking_v(1);
		for (u8 L_ci_u8=0; L_ci_u8 < Arg_Config_cpcLKeypad->Cols_Number; L_ci_u8++){
			if (GPIO_PinRead_u8(&L_KeypadCols_GPIO_Cfg, Arg_Config_cpcLKeypad->ColsPins[L_ci_u8])){
				*((Arg_OutputArr_pcBool+L_ri_u8*Arg_Config_cpcLKeypad->Cols_Number) + L_ci_u8) = STD_TRUE;
//				Arg_OutputArr_pcBool[L_ri_u8][L_ci_u8] = STD_TRUE;
			}
			else{
				*((Arg_OutputArr_pcBool+L_ri_u8*Arg_Config_cpcLKeypad->Cols_Number) + L_ci_u8) = STD_FALSE;
//				Arg_OutputArr_pcBool[L_ri_u8][L_ci_u8] = STD_FALSE;
			}
		}

		/*Set row pin --> LOW*/
		GPIO_PinWrite_v(&L_KeypadRows_GPIO_Cfg, Arg_Config_cpcLKeypad->RowsPins[L_ri_u8], STD_LOW);
		Delay_DelayInMilliSecondsBlocking_v(1);

	}

}
