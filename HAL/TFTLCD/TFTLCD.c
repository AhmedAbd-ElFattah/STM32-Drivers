/*
 * File Name --> TFTLCD.c
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> TFTLCD driver implementation.
 * */


/*
==================================================
  Start Section --> File Includes
==================================================
 */
#include "TFTLCD.h"
#include "TFTLCD_cmds.h"

#include "HMCAL/SPI/SPI.h"
#include "HMCAL/GPIO/GPIO.h"
#include "LIB/Delay/Delay.h"
/*
==================================================
  End   Section --> File Includes
==================================================
 */

/*
==================================================
  Start Section --> Static Functions Prototypes.
==================================================
 */

/*
==================================================
  Start Section --> Static Functions Prototypes.
==================================================
 */

void TFT_Writeu8Data_v (TFTLCD_Cfg const * const Arg_conf_cpcTFTLCD_Cfg, u8 Arg_Data_u8);
void TFT_Writeu16Data_v (TFTLCD_Cfg const * const Arg_conf_cpcTFTLCD_Cfg, u16 Arg_Data_u16);
void TFT_WriteCommand_v (TFTLCD_Cfg const * const Arg_conf_cpcTFTLCD_Cfg, u8 Arg_Data_u8);
void TFT_Init_v(TFTLCD_Cfg const * const Arg_conf_cpcTFTLCD_Cfg);
/*
==================================================
  End Section --> Static Function Definitions
==================================================
 */

/*
==================================================
  Start Section --> Functions implementation.
==================================================
 */
void TFT_Config_v(TFTLCD_Cfg const * const Arg_conf_cpcTFTLCD_Cfg){

	SPI_Cfg L_TFTSPI_SPI_Cfg = {0};
	L_TFTSPI_SPI_Cfg.InstanceId = Arg_conf_cpcTFTLCD_Cfg->SPIInstanceId;
	L_TFTSPI_SPI_Cfg.GPIOPins = Arg_conf_cpcTFTLCD_Cfg->SPIPins;
	L_TFTSPI_SPI_Cfg.GPIOInstanceId = Arg_conf_cpcTFTLCD_Cfg->GPIOSPIInstanceId;

	L_TFTSPI_SPI_Cfg.CRC = SPI_CRC_DISABLE;
	L_TFTSPI_SPI_Cfg.CaptureStrobe = SPI_CAPTURE_STROBE_IDLE_CLK_HIGH_RISING;
	L_TFTSPI_SPI_Cfg.ClockPrescaler = SPI_PRESCALER_16;
	L_TFTSPI_SPI_Cfg.Direction = SPI_DIRECTION_UNIDIRECTIONAL;
	L_TFTSPI_SPI_Cfg.FrameSize = SPI_FRAME_SIZE_8_BITS_MSB_First;
	L_TFTSPI_SPI_Cfg.Interrupt = SPI_INTERRUPT_DISABLE;
	L_TFTSPI_SPI_Cfg.State = SPI_STATE_MASTER;
	SPI_Config_v(&L_TFTSPI_SPI_Cfg);

	/*A0 PIN GPIO Configurations Section*/
	GPIO_Cfg L_A0_Pin_GPIO_Cfg = {0};
	L_A0_Pin_GPIO_Cfg.InstanceId = Arg_conf_cpcTFTLCD_Cfg->A0GPIOInstanceId;
	L_A0_Pin_GPIO_Cfg.Mode = GPIO_MODE_OUTPUT;
	L_A0_Pin_GPIO_Cfg.OutputSpeed = GPIO_OUTPUT_SPEED_HIGH;
	L_A0_Pin_GPIO_Cfg.OutputType = GPIO_OUTPUT_TYPE_PUSH_PULL;
	L_A0_Pin_GPIO_Cfg.PINs = Arg_conf_cpcTFTLCD_Cfg->A0Pin;
	L_A0_Pin_GPIO_Cfg.PullUpPullDownResistor = GPIO_RESISTOR_NO_PULL;
	GPIO_Config_v(&L_A0_Pin_GPIO_Cfg);

	/*Reset PIN GPIO Configurations Section*/
	GPIO_Cfg L_Reset_Pin_GPIO_Cfg = {0};
	L_Reset_Pin_GPIO_Cfg.InstanceId = Arg_conf_cpcTFTLCD_Cfg->ResetGPIOInstanceId;
	L_Reset_Pin_GPIO_Cfg.Mode = GPIO_MODE_OUTPUT;
	L_Reset_Pin_GPIO_Cfg.OutputSpeed = GPIO_OUTPUT_SPEED_HIGH;
	L_Reset_Pin_GPIO_Cfg.OutputType = GPIO_OUTPUT_TYPE_PUSH_PULL;
	L_Reset_Pin_GPIO_Cfg.PINs = Arg_conf_cpcTFTLCD_Cfg->ResetPin;
	L_Reset_Pin_GPIO_Cfg.PullUpPullDownResistor = GPIO_RESISTOR_NO_PULL;
	GPIO_Config_v(&L_Reset_Pin_GPIO_Cfg);

	TFT_Init_v(Arg_conf_cpcTFTLCD_Cfg);
}


void TFT_Writeu8Data_v (TFTLCD_Cfg const * const Arg_conf_cpcTFTLCD_Cfg, u8 Arg_Data_u8){
	GPIO_Cfg L_GPIO_Cfg={0};
	L_GPIO_Cfg.InstanceId = Arg_conf_cpcTFTLCD_Cfg->A0GPIOInstanceId;
	L_GPIO_Cfg.PINs = Arg_conf_cpcTFTLCD_Cfg->A0Pin;
	GPIO_PORTMaskedWrite_v(&L_GPIO_Cfg , 0xFFFF);


	SPI_Cfg L_TFTSPI_SPI_Cfg = {0};
	L_TFTSPI_SPI_Cfg.InstanceId = Arg_conf_cpcTFTLCD_Cfg->SPIInstanceId;
	SPI_Sendu8Data_v(&L_TFTSPI_SPI_Cfg, Arg_Data_u8);
}

void TFT_Writeu16Data_v (TFTLCD_Cfg const * const Arg_conf_cpcTFTLCD_Cfg, u16 Arg_Data_u16){
	GPIO_Cfg L_GPIO_Cfg={0};
	L_GPIO_Cfg.InstanceId = Arg_conf_cpcTFTLCD_Cfg->A0GPIOInstanceId;
	L_GPIO_Cfg.PINs = Arg_conf_cpcTFTLCD_Cfg->A0Pin;
	GPIO_PORTMaskedWrite_v(&L_GPIO_Cfg , 0xFFFF);



	SPI_Cfg L_TFTSPI_SPI_Cfg = {0};
	L_TFTSPI_SPI_Cfg.InstanceId = Arg_conf_cpcTFTLCD_Cfg->SPIInstanceId;
	SPI_Sendu16Data_v(&L_TFTSPI_SPI_Cfg, Arg_Data_u16);
}

void TFT_WriteCommand_v (TFTLCD_Cfg const * const Arg_conf_cpcTFTLCD_Cfg, u8 Arg_Data_u8){
	GPIO_Cfg L_GPIO_Cfg={0};
	L_GPIO_Cfg.InstanceId = Arg_conf_cpcTFTLCD_Cfg->A0GPIOInstanceId;
	L_GPIO_Cfg.PINs = Arg_conf_cpcTFTLCD_Cfg->A0Pin;
	GPIO_PORTMaskedWrite_v(&L_GPIO_Cfg , 0x0000);


	SPI_Cfg L_TFTSPI_SPI_Cfg = {0};
	L_TFTSPI_SPI_Cfg.InstanceId = Arg_conf_cpcTFTLCD_Cfg->SPIInstanceId;
	SPI_Sendu8Data_v(&L_TFTSPI_SPI_Cfg, Arg_Data_u8);
}

void TFT_Init_v(TFTLCD_Cfg const * const Arg_conf_cpcTFTLCD_Cfg){
	/*Enable SPI*/

	SPI_Cfg L_SPI_Cfg = {0};
	L_SPI_Cfg.InstanceId = Arg_conf_cpcTFTLCD_Cfg->SPIInstanceId;
	SPI_EnableSPI_v(&L_SPI_Cfg);

	/*Reset Rest PIN.*/
	GPIO_Cfg L_GPIO_Cfg={0};
	L_GPIO_Cfg.InstanceId = Arg_conf_cpcTFTLCD_Cfg->ResetGPIOInstanceId;
	L_GPIO_Cfg.PINs = Arg_conf_cpcTFTLCD_Cfg->ResetPin;

	GPIO_PORTMaskedWrite_v(&L_GPIO_Cfg, 0xFFFF);

	Delay_DelayInMilliSecondsBlocking_v(100);
	/*Send sleep output command.*/
	TFT_WriteCommand_v(Arg_conf_cpcTFTLCD_Cfg, TFT_CMD_SLEEPOUT);
	/*Send color mode and it's id.*/
	TFT_WriteCommand_v(Arg_conf_cpcTFTLCD_Cfg, TFT_CMD_INTERFACE_PIXEL_FORMAT);
	TFT_Writeu8Data_v(Arg_conf_cpcTFTLCD_Cfg, 0x05);
	/*Send display on mode.*/
	TFT_WriteCommand_v(Arg_conf_cpcTFTLCD_Cfg, TFT_CMD_DISPLAY_ON);

	/*Command to set X-position.*/
	TFT_WriteCommand_v(Arg_conf_cpcTFTLCD_Cfg, TFT_CMD_COLUMN_ADDRESS_SET);
	TFT_Writeu8Data_v(Arg_conf_cpcTFTLCD_Cfg, 0);
	TFT_Writeu8Data_v(Arg_conf_cpcTFTLCD_Cfg, 0);
	TFT_Writeu8Data_v(Arg_conf_cpcTFTLCD_Cfg, 0);
	TFT_Writeu8Data_v(Arg_conf_cpcTFTLCD_Cfg, Arg_conf_cpcTFTLCD_Cfg->Cols);
	/*Command to set y-position.*/
	TFT_WriteCommand_v(Arg_conf_cpcTFTLCD_Cfg, TFT_CMD_ROW_ADDRESS_SET);
	TFT_Writeu8Data_v(Arg_conf_cpcTFTLCD_Cfg, 0);
	TFT_Writeu8Data_v(Arg_conf_cpcTFTLCD_Cfg, 0);
	TFT_Writeu8Data_v(Arg_conf_cpcTFTLCD_Cfg, 0);
	TFT_Writeu8Data_v(Arg_conf_cpcTFTLCD_Cfg, Arg_conf_cpcTFTLCD_Cfg->Rows);

	/*Command to send image.*/
	TFT_Writeu8Data_v(Arg_conf_cpcTFTLCD_Cfg, TFT_CMD_MEMORY_WRITE);

	SPI_ChangeDataFrameFormatTo16Bit_v(&L_SPI_Cfg);

	for (u16 L_Rows_u16 = 0; L_Rows_u16 < Arg_conf_cpcTFTLCD_Cfg->Rows; L_Rows_u16++){
		for (u16 L_Cols_u16 = 0; L_Cols_u16 < Arg_conf_cpcTFTLCD_Cfg->Cols; L_Cols_u16++){
			TFT_Writeu16Data_v(Arg_conf_cpcTFTLCD_Cfg, 0);
		}
	}
	SPI_ChangeDataFrameFormatTo8Bit_v(&L_SPI_Cfg);
}

void TFT_DisplayImage_v(TFTLCD_Cfg const * const Arg_conf_cpcTFTLCD_Cfg,
		const u16 Arg_Image_u16[Arg_conf_cpcTFTLCD_Cfg->Rows][Arg_conf_cpcTFTLCD_Cfg->Cols]){

	SPI_Cfg L_SPI_Cfg = {0};
	L_SPI_Cfg.InstanceId = Arg_conf_cpcTFTLCD_Cfg->SPIInstanceId;
	SPI_EnableSPI_v(&L_SPI_Cfg);

	/*Command to set X-position.*/
	TFT_WriteCommand_v(Arg_conf_cpcTFTLCD_Cfg, TFT_CMD_COLUMN_ADDRESS_SET);
	TFT_Writeu8Data_v(Arg_conf_cpcTFTLCD_Cfg, 0);
	TFT_Writeu8Data_v(Arg_conf_cpcTFTLCD_Cfg, 0);
	TFT_Writeu8Data_v(Arg_conf_cpcTFTLCD_Cfg, 0);
	TFT_Writeu8Data_v(Arg_conf_cpcTFTLCD_Cfg, Arg_conf_cpcTFTLCD_Cfg->Cols);

	/*Command to set y-position.*/
	TFT_WriteCommand_v(Arg_conf_cpcTFTLCD_Cfg, TFT_CMD_ROW_ADDRESS_SET);
	TFT_Writeu8Data_v(Arg_conf_cpcTFTLCD_Cfg, 0);
	TFT_Writeu8Data_v(Arg_conf_cpcTFTLCD_Cfg, 0);
	TFT_Writeu8Data_v(Arg_conf_cpcTFTLCD_Cfg, 0);
	TFT_Writeu8Data_v(Arg_conf_cpcTFTLCD_Cfg, Arg_conf_cpcTFTLCD_Cfg->Rows);

	/*Command to send image.*/
	TFT_WriteCommand_v(Arg_conf_cpcTFTLCD_Cfg, TFT_CMD_MEMORY_WRITE);

	SPI_ChangeDataFrameFormatTo16Bit_v(&L_SPI_Cfg);

	for (u16 L_Rows_u16 = 0; L_Rows_u16 < Arg_conf_cpcTFTLCD_Cfg->Rows; L_Rows_u16++){
		for (u16 L_Cols_u16 = 0; L_Cols_u16 < Arg_conf_cpcTFTLCD_Cfg->Cols; L_Cols_u16++){
			TFT_Writeu16Data_v(Arg_conf_cpcTFTLCD_Cfg, Arg_Image_u16[L_Cols_u16][L_Rows_u16]);
		}
	}

	SPI_ChangeDataFrameFormatTo8Bit_v(&L_SPI_Cfg);

}



/*
==================================================
  End Section --> Functions implementation.
==================================================
 */
