/*
 * File Name --> TFTLCD.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> Provides API and available configuration options for TFT LCD.
 * */


#ifndef HAL_TFTLCD_TFTLCD_H_
#define HAL_TFTLCD_TFTLCD_H_




/*
==================================================
  Start Section --> File Includes
==================================================
*/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "HMCAL/GPIO/GPIO.h"
#include "HMCAL/SPI/SPI.h"
/*
==================================================
  End   Section --> File Includes
==================================================
*/


/*
==================================================
  Start Section --> TFTLCD Configurations.
==================================================
*/
typedef struct TFTLCD_Cfg{
	/*
	 * SPI pins GPIO Instance
	 * for example if you need to connect SPI pins to GPIOB
	 * this parameter takes the value 'B'.
	 * */
	u8 GPIOSPIInstanceId;
	/*
	 * SPI Instance id
	 * for example if you need to connect using SPI1
	 * this parameter takes the value 1.
	 * */
	u8 SPIInstanceId;
	/*
	 * A0 pin Instance id
	 * for example if you need to connect this ping through GPIOC
	 * this parameter takes the value 'C'.
	 * */
	u8 A0GPIOInstanceId;
	/*
	 * Reset pin Instance id
	 * for example if you need to connect this ping through GPIOA
	 * this parameter takes the value 'A'.
	 * */
	u8 ResetGPIOInstanceId;

	/*
	 * SPI pins
	 * for example if you need to connect SPI pins to B3 & B5
	 * this parameter takes the value PIN_3_MASK | PIN_5_MASK.
	 * */

	u16 SPIPins;
	/*
	 * A0 pin
	 * for example if you need to connect SPI pins to C1
	 * this parameter takes the value PIN_1_MASK.
	 * */
	u16 A0Pin;
	/*
	 * Reset pin
	 * for example if you need to connect SPI pins to A6
	 * this parameter takes the value PIN_6_MASK.
	 * */
	u16 ResetPin;

	/*
	 * Row size of LCD must be assigned to this parameter.
	 * */
	u16 Rows;
	/*
	 * Column size of LCD must be assigned to this parameter.
	 * */
	u16 Cols;

}TFTLCD_Cfg;
/*
==================================================
  End Section --> TFTLCD Configurations.
==================================================
*/


/*
==================================================
  Start Section --> APIs
==================================================
*/

/* @brief  --> This function configures TFTLCD based on configuration passed through TFTLCD_Cfg struct.
 * @param  Arg_conf_cpcTFTLCD_Cfg --> struct that have configured parameters.
 * @retval --> None.
 * */
void TFT_Config_v(TFTLCD_Cfg const * const Arg_conf_cpcTFTLCD_Cfg);

/* @brief  --> This function displays image on TFT LCD.
 * @param  Arg_conf_cpcTFTLCD_Cfg --> struct that have configured parameters.
 * @param  Arg_Image_u16 --> Image in 2D array with format RGB565.
 * @retval --> None.
 * */
void TFT_DisplayImage_v(TFTLCD_Cfg const * const Arg_conf_cpcTFTLCD_Cfg,
		const u16 Arg_Image_u16[Arg_conf_cpcTFTLCD_Cfg->Rows][Arg_conf_cpcTFTLCD_Cfg->Cols]);
/*
==================================================
  End   Section --> APIs
==================================================
*/
#endif /* HAL_TFTLCD_TFTLCD_H_ */
