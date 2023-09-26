/*
 * File Name --> GPIO.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> Provides API and available configuration options for GPIO peripheral.
 * */

#ifndef HMCAL_GPIO_GPIO_H_
#define HMCAL_GPIO_GPIO_H_


/*
==================================================
  Start Section --> File Includes
==================================================
*/
#include "LIB/STD_TYPES.h"
/*
==================================================
  End   Section --> File Includes
==================================================
*/

/*
==================================================
  Start Section --> GPIO Configurations available options
==================================================
*/

/*@ref GPIO_Pin_modes*/
#define	GPIO_MODE_INPUT               	0
#define	GPIO_MODE_OUTPUT            	1
/*Alternate Function mode is selected when
 * you need to assign pin for peripheral like
 * USART, CAN, and so on
 * Note:
 * ADC and DAC peripheral shouldn't be used with this mode
 * */
#define	GPIO_MODE_ALTERNATE_FUNCTION	2
/*Analog mode is selected when
 * you need to assign pins for
 * Analog to digital converter (ADC) & Digital to analog cnverter (DAC)*/
#define	GPIO_MODE_ANALOG              	3

/*@ref GPIO_Output_Types*/
#define GPIO_OUTPUT_TYPE_PUSH_PULL    	0
#define	GPIO_OUTPUT_TYPE_OPEN_DRAIN		1


/*@ref GPIO_Output_Speed*/
/*Check your microcontroller'sdatasheet to know the exact values of slew rate of each option.*/
#define 		GPIO_OUTPUT_SPEED_LOW      0
#define 		GPIO_OUTPUT_SPEED_MEDIUM   1
#define 		GPIO_OUTPUT_SPEED_FAST     2
#define 		GPIO_OUTPUT_SPEED_HIGH     3

/*@ref GPIO_Pull_up_or_Pull_down_Resistor*/
/* Pull Up/Down resistor */
#define 		GPIO_RESISTOR_NO_PULL     0
#define 		GPIO_RESISTOR_PULL_UP     1
#define 		GPIO_RESISTOR_PULL_DOWN   2





/*
==================================================
  End Section --> GPIO Configurations available options
==================================================
*/

/*
==================================================
  Start Section --> GPIO map pins available options
==================================================
*/
/* Configure pins */
/*
 * Macros which is defined with x_MAP_PIN (Where x is a peripheral name)
 * used by function
 * GPIO_MapGPIOPIN_void(GPIO_Cfg const * const Arg_conf_cpcGPIO_Cfg, u8 Arg_PIN_u8, u8 Arg_Peripheral_u8)
 * To set Alternate function for specific pin
 * */
#define			SYS_MAP_PIN				0

#define			TIM1_MAP_PIN			1
#define			TIM2_MAP_PIN			1

#define			TIM3_MAP_PIN			2
#define			TIM4_MAP_PIN			2
#define			TIM5_MAP_PIN			2

#define			TIM8_MAP_PIN			3
#define			TIM9_MAP_PIN			3
#define			TIM10_MAP_PIN			3
#define			TIM11_MAP_PIN			3

#define			I2C1_MAP_PIN			4
#define			I2C2_MAP_PIN			4
#define			I2C3_MAP_PIN			4

#define			SPI1_MAP_PIN			5
#define			SPI2_MAP_PIN			5
#define			I2S2_MAP_PIN			5
#define			I2S2ext_MAP_PIN			5

#define			SPI3_MAP_PIN			6
#define			I2Sext_MAP_PIN			6
#define			I2S3_MAP_PIN			6

#define			USART1_MAP_PIN			7
#define			USART2_MAP_PIN			7
#define			USART3_MAP_PIN			7
#define			I2S3ext_MAP_PIN			7

#define			UART4_MAP_PIN			8
#define			UART5_MAP_PIN			8
#define			USART6_MAP_PIN			8

#define			CAN1_MAP_PIN			9
#define			CAN2_MAP_PIN			9
#define			TIM12_MAP_PIN			9
#define			TIM13_MAP_PIN			9
#define			TIM14_MAP_PIN			9

#define			OTG_FS_10_MAP_PIN		10
#define			OTG_HS_MAP_PIN			10

#define			ETH_MAP_PIN				11

#define			FSMC_MAP_PIN			12
#define			SDIO_MAP_PIN			12
#define			OTG_FS_12_MAP_PIN		12

#define			DCMI_MAP_PIN			13

#define			EVENTOUT_MAP_PIN		15
/*
==================================================
  End Section --> GPIO map pins available options
==================================================
*/


/*
==================================================
  Start Section --> GPIO Configurations.
==================================================
*/
typedef struct GPIO_Cfg{
	/*This parameter can be the value of GPIO instance for example
	 * If you want to configure GPIOA, This parameter will take the value 'A'*/
	u8 	InstanceId;
	/*This parameter can be the value of assigned pins for GPIO instance
	 * using the following pattern
	 * PIN_x_MASK | PIN_y_MASK | PIN_z_MASK
	 * where x, y, and z are the values of selected pins
	 * for example if you want to configure Pin A0, A3, A10
	 * This parameter will take
	 * PIN_0_MASK | PIN_3_MASK | PIN_10_MASK
	 * */
	u16 PINs;
	/*This parameter take a value of @ref GPIO_Pin_modes*/
	u16 Mode;
	/*This parameter take a value of @ref GPIO_Output_Types*/
	u16 OutputType;
	/*This parameter take a value of @ref GPIO_Output_Speed*/
	u16 OutputSpeed;
	/*This parameter take a value of @ref GPIO_Pull_up_or_Pull_down_Resistor*/
	u16 PullUpPullDownResistor;
}GPIO_Cfg;


/*
==================================================
  End Section --> GPIO Configurations.
==================================================
*/


/*
==================================================
  Start Section --> APIs
==================================================
*/

/* @brief  --> This function configures GPIO based on configuration passed through GPIO_Cfg struct.
 * @param  Arg_conf_cpcGPIO_Cfg --> struct that have configured parameters.
 * @retval --> None.
 * */
void GPIO_Config_v(GPIO_Cfg const *const Arg_conf_cpcGPIO_Cfg);

/* @brief  --> This function resets DMA to it's default configurations
 * @param  Arg_conf_cpcGPIO_Cfg --> struct that have configured parameters.
 * @retval --> None.
 * */
void GPIO_Reset_v (GPIO_Cfg const *const Arg_conf_cpcGPIO_Cfg);

/* @brief -->
 * Set and Reset one pin only
 * example
 *
 * To set D13 pin.
 *
 * GPIO_Cfg gpio_example;
 * gpio_example.InstanceId = 'D';
 * GPIO_PinWrite_v(&gpio_example, 13, STD_HIGH);
 *
 * To reset D13.
 * GPIO_PinWrite_v(&gpio_example, 13, STD_LOW);
 *
 * @param  Arg_conf_cpcGPIO_Cfg --> struct that have configured parameters.
 * @param  Arg_PIN_u8 --> Pin number.
 * @param  Arg_Value_u8 --> pass STD_HIGH or STD_LOW to set/reset selected pin.
 *
 * @retval --> None
 * */
void GPIO_PinWrite_v(GPIO_Cfg const * const Arg_conf_cpcGPIO_Cfg, const u8 Arg_PIN_Cu8, const u8 Arg_Value_Cu8);
/* @brief --> Set and Reset all pins in the port
 * @param  Arg_conf_cpcGPIO_Cfg --> struct that have configured parameters.
 * @param  Arg_Value_u8 --> pass STD_HIGH or STD_LOW to set/reset all pins in the port.
 * @retval --> None
 * */
void GPIO_PORTWrite_v(GPIO_Cfg const * const Arg_conf_cpcGPIO_Cfg, const u8 Arg_Value_Cu8);
/*
 * @brief --> Set and Reset some pins or write value to specific pins
 * example
 *
 * To set D12 , D13, D14 and D15 pin.
 *
 * GPIO_Cfg gpio_example;
 * gpio_example.InstanceId = 'D';
 * gpio_example.PINs = PIN_13_MASK | PIN_14_MASK | PIN_15_MASK | PIN_12_MASK;
 * GPIO_PinWrite_v(GPIO_Cfg const * const Arg_conf_cpcGPIO_Cfg, 0xFFFF);
 *
 * To reset D13.
 * GPIO_PinWrite_v(&gpio_example , 0x0000);
 * @param  Arg_Value_u8 --> pass STD_HIGH or STD_LOW to set/reset selected pins.
 * @retval --> None
 * */
void GPIO_PORTMaskedWrite_v(GPIO_Cfg const * const Arg_conf_cpcGPIO_Cfg, const u16 Arg_Value_Cu16);
/* @brief Read Specific pin whether it's set or reset
 * example
 * To read pin A0
 * GPIO_Cfg gpio_example;
 * gpio_example.InstanceId = 'A';
 * GPIO_PinRead_u8(&gpio_example , 0);
 * the output of function is 0 or 1 depending on wheter input pin is high or low;
 *
 * @param Arg_conf_cpcGPIO_Cfg --> struct that have configured parameters.
 * @param Arg_PIN_Cu8 		   --> select pin number
 * @retval --> Pin input value.
 * */
u8 GPIO_PinRead_u8(GPIO_Cfg const * const Arg_conf_cpcGPIO_Cfg, const u8 Arg_PIN_Cu8);
/*
 * @brief Read Specific pin whether it's set or reset
 *
 * Read value of all pins in specific port such as GPIOA
 * Example
 * GPIO_Cfg gpio_example;
 * gpio_example.InstanceId = 'A';
 * GPIO_PORTRead_u16(&gpio_example);
 *
 * @param Arg_conf_cpcGPIO_Cfg --> struct that have configured parameters.
 *
 * @retval --> Port input value.
 * */
u16 GPIO_PORTRead_u16(GPIO_Cfg const * const Arg_conf_cpcGPIO_Cfg);
/* @brief Read specific pins
 * To read D12 , D13, D14 and D15 pin.
 * GPIO_Cfg gpio_example;
 * gpio_example.InstanceId = 'D';
 * gpio_example.PINs = PIN_13_MASK | PIN_14_MASK | PIN_15_MASK | PIN_12_MASK;
 * GPIO_PORTMaskedRead_u16(gpio_example);
 *
 * @param Arg_conf_cpcGPIO_Cfg --> struct that have configured parameters.
 *
 * @retval --> Masked pins input value.
 * */
u16 GPIO_PORTMaskedRead_u16(GPIO_Cfg const * const Arg_conf_cpcGPIO_Cfg);

/*
 * @brief Map specific pin to peripheral such as USART
 * example
 *
 * GPIO_Cfg gpio_example;
 * gpio_example.InstanceId = 'D';
 * gpio_example.PINs = PIN_13_MASK | PIN_14_MASK | PIN_15_MASK | PIN_12_MASK;
 *
 * GPIO_MapGPIOPIN_v(GPIO_Cfg const * const Arg_conf_cpcGPIO_Cfg, u8 Arg_PIN_Cu8, u8 Arg_Peripheral_Cu8)
 * */
void GPIO_MapGPIOPIN_v(GPIO_Cfg const * const Arg_conf_cpcGPIO_Cfg, const u8 Arg_PIN_Cu8, const u8 Arg_Peripheral_Cu8);



/*
==================================================
  End   Section --> APIs
==================================================
*/
#endif /* HMCAL_GPIO_GPIO_H_ */
