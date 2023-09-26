/*
 * File Name --> SevenSegmentSevenSegmentModule56D330.c
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HAL
 * Brief	 --> Seven Segment Module 56D330 driver implementation.
 * */
/*
==================================================
  Start Section --> File Includes
==================================================
 */
#include "SevenSegmentModule56D330.h"
#include "SevenSegmentModule56D330_Private.h"
#include "LIB/utils.h"
#include "LIB/Delay/Delay.h"
/*
==================================================
  End   Section --> File Includes
==================================================
 */

/*
==================================================
  Start Section --> Static Functions prototype.
==================================================
 */
static void SevenSegmentModule_ApplyCommand_v(SevenSegmentModule56D330_Cfg * const Arg_Config_pSSM_Cfg, u16 Arg_Command_u8, u16 Arg_parameter_u8);
/*
==================================================
  End Section --> Static Functions prototype.
==================================================
 */

/*
==================================================
  Start Section --> Static Functions implementation.
==================================================
 */
void SevenSegmentModule_ApplyCommand_v(SevenSegmentModule56D330_Cfg * const Arg_Config_pSSM_Cfg, u16 Arg_Command_u8, u16 Arg_parameter_u8){
	const u16 L_Data_Cu8 [] = {Arg_Command_u8, Arg_parameter_u8};

	GPIO_Cfg L_ChipSelect_GPIO_Cfg = {0};
	L_ChipSelect_GPIO_Cfg.InstanceId = Arg_Config_pSSM_Cfg->ChipSelectGPIOInstanceId;
	SET_BIT(L_ChipSelect_GPIO_Cfg.PINs, Arg_Config_pSSM_Cfg->ChipSelectGPIOPin);

	GPIO_Cfg L_Clock_GPIO_Cfg = {0};
	L_Clock_GPIO_Cfg.InstanceId = Arg_Config_pSSM_Cfg->ClockGPIOInstanceId;
	SET_BIT(L_Clock_GPIO_Cfg.PINs, Arg_Config_pSSM_Cfg->ClockGPIOGPIOPin);

	GPIO_Cfg L_DataInput_GPIO_Cfg = {0};
	L_DataInput_GPIO_Cfg.InstanceId = Arg_Config_pSSM_Cfg->DataInputGPIOInstanceId;
	SET_BIT(L_DataInput_GPIO_Cfg.PINs, Arg_Config_pSSM_Cfg->DataInputGPIOPin);

	GPIO_PinWrite_v(&L_ChipSelect_GPIO_Cfg, Arg_Config_pSSM_Cfg->ChipSelectGPIOPin, STD_LOW);

	for (u8 L_dataIndex_u8 = 0; L_dataIndex_u8 < 2; L_dataIndex_u8++){

		for (u8 L_i_u8 =0 ; L_i_u8<8 ; L_i_u8++){

			GPIO_PinWrite_v(&L_DataInput_GPIO_Cfg, Arg_Config_pSSM_Cfg->DataInputGPIOPin,  (EBool)(L_Data_Cu8[L_dataIndex_u8]>>(7-L_i_u8)) &0x01);

			GPIO_PinWrite_v(&L_Clock_GPIO_Cfg, Arg_Config_pSSM_Cfg->ClockGPIOGPIOPin, STD_HIGH);
			Delay_DelayInMilliSecondsBlocking_v(1);
			GPIO_PinWrite_v(&L_Clock_GPIO_Cfg, Arg_Config_pSSM_Cfg->ClockGPIOGPIOPin, STD_LOW);
			Delay_DelayInMilliSecondsBlocking_v(1);

		}

	}

	GPIO_PinWrite_v(&L_ChipSelect_GPIO_Cfg, Arg_Config_pSSM_Cfg->ChipSelectGPIOPin, STD_HIGH);
}
/*
==================================================
  End Section --> Static Functions implementation.
==================================================
 */

/*
==================================================
  Start Section --> Functions implementation.
==================================================
 */
void SevenSegmentModule_Config_v(SevenSegmentModule56D330_Cfg * const Arg_Config_pSSM_Cfg){

	GPIO_Cfg L_SSM_GPIO_Cfg = {0};
	L_SSM_GPIO_Cfg.InstanceId = Arg_Config_pSSM_Cfg->ChipSelectGPIOInstanceId;
	L_SSM_GPIO_Cfg.Mode = GPIO_MODE_OUTPUT;
	L_SSM_GPIO_Cfg.OutputSpeed = GPIO_OUTPUT_SPEED_LOW;
	L_SSM_GPIO_Cfg.OutputType = GPIO_OUTPUT_TYPE_PUSH_PULL;
	SET_BIT(L_SSM_GPIO_Cfg.PINs, Arg_Config_pSSM_Cfg->ChipSelectGPIOPin);
	L_SSM_GPIO_Cfg.PullUpPullDownResistor = GPIO_RESISTOR_NO_PULL;

	GPIO_Config_v(&L_SSM_GPIO_Cfg);

	L_SSM_GPIO_Cfg.InstanceId = Arg_Config_pSSM_Cfg->ClockGPIOInstanceId;
	L_SSM_GPIO_Cfg.PINs = 0;
	SET_BIT(L_SSM_GPIO_Cfg.PINs, Arg_Config_pSSM_Cfg->ClockGPIOGPIOPin);
	GPIO_Config_v(&L_SSM_GPIO_Cfg);

	L_SSM_GPIO_Cfg.InstanceId = Arg_Config_pSSM_Cfg->DataInputGPIOInstanceId;
	L_SSM_GPIO_Cfg.PINs = 0;
	SET_BIT(L_SSM_GPIO_Cfg.PINs, Arg_Config_pSSM_Cfg->DataInputGPIOPin);
	GPIO_Config_v(&L_SSM_GPIO_Cfg);

	SevenSegmentModule_ApplyCommand_v(Arg_Config_pSSM_Cfg, CMD_SHUTDOWN, 0x01);
	SevenSegmentModule_ApplyCommand_v(Arg_Config_pSSM_Cfg, CMD_SCAN_LIMIT, 0x07);
	SevenSegmentModule_ApplyCommand_v(Arg_Config_pSSM_Cfg, CMD_INTENSITY, 0x0F);
	SevenSegmentModule_ApplyCommand_v(Arg_Config_pSSM_Cfg, CMD_DECODE_MODE, 0xFF);

	SevenSegmentModule_DisplayNumber_v(Arg_Config_pSSM_Cfg, 0, 0);
	SevenSegmentModule_DisplayNumber_v(Arg_Config_pSSM_Cfg, 1, 0);
}

void SevenSegmentModule_DisplayNumber_v(SevenSegmentModule56D330_Cfg * const Arg_Config_pSSM_Cfg, u8 Arg_DispNum_u8, u16 Arg_Number_u16){
	u16 L_CurrentDigit_u16, L_Number_u16 = Arg_Number_u16;

	for (u8 L_i_u8=0 ; L_i_u8<3 ; L_i_u8++){
		L_CurrentDigit_u16 = L_Number_u16 % 10;
		L_Number_u16 = L_Number_u16/10;
		SevenSegmentModule_ApplyCommand_v(Arg_Config_pSSM_Cfg, L_i_u8 + 3*Arg_DispNum_u8 + 1, L_CurrentDigit_u16);
	}
}

/*
==================================================
  End Section --> Functions implementation.
==================================================
 */
