/*
 * File Name --> SPI.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> Provides API and available configuration options for SPI peripheral.
 * */

#ifndef HMCAL_SPI_SPI_H_
#define HMCAL_SPI_SPI_H_

/*
==================================================
  Start Section --> File Includes
==================================================
 */
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "STM32_Drivers_Configurations/Driver_Config.h"
#include "HMCAL/Interrupt/InterruptHandlers.h"
#include "SPI_Private.h"
#include "SPI_defs.h"
/*
==================================================
  End   Section --> File Includes
==================================================
 */



/*
==================================================
  Start Section --> SPI Configurations available options
==================================================
 */

/*@ref SPI_Direction*/
/*SPI Direction available options section.*/
#define			SPI_DIRECTION_UNIDIRECTIONAL													0
#define			SPI_DIRECTION_RECEIVE_ONLY_BIDIRECTIONAL										1
#define			SPI_DIRECTION_TRANSMIT_ONLY_BIDIRECTIONAL										2

/*@ref SPI_CRC*/
/*SPI CRC available options section.*/
#define			SPI_CRC_DISABLE																	0
#define			SPI_CRC_ENABLE																	1

/*@ref SPI_Capture_Strope*/
/* SPI Capture Strobe available options section. */
#define 		SPI_CAPTURE_STROBE_IDLE_CLK_LOW_RISING                                          0
#define 		SPI_CAPTURE_STROBE_IDLE_CLK_HIGH_RISING                                         1
#define 		SPI_CAPTURE_STROBE_IDLE_CLK_HIGH_FALLING                                        2
#define 		SPI_CAPTURE_STROBE_IDLE_CLK_LOW_FALLING                                         3

/*@ref SPI_Frame_Size*/
/* SPI Frame Size available options section.*/
#define 		SPI_FRAME_SIZE_8_BITS_MSB_First                                          		0
#define 		SPI_FRAME_SIZE_8_BITS_LSB_First                                          		1
#define 		SPI_FRAME_SIZE_16_BITS_MSB_First                                          		2
#define 		SPI_FRAME_SIZE_16_BITS_LSB_First                                          		3

/*@ref SPI_State*/
/* SPI State Master / Slave available options section. */
#define 		SPI_STATE_MASTER                                          						0
#define 		SPI_STATE_SLAVE                                          						1

/*@ref SPI_Frame_Prescaler*/
/*SPI Clock Prescaler available options section. */
#define 		SPI_PRESCALER_2                                          						0
#define 		SPI_PRESCALER_4                                          						1
#define 		SPI_PRESCALER_8                                          						2
#define 		SPI_PRESCALER_16                                          						3
#define 		SPI_PRESCALER_32                                          						4
#define 		SPI_PRESCALER_64                                          						5
#define 		SPI_PRESCALER_128                                          						6
#define 		SPI_PRESCALER_256                                          						7

/*@ref SPI_Interrupt*/
/* SPI Interrupt available options section. */
#define			SPI_INTERRUPT_DISABLE															0
#define			SPI_INTERRUPT_TX_EMPTY															(1<<0)
#define			SPI_INTERRUPT_RX_NON_EMPTY														(1<<1)
#define			SPI_INTERRUPT_ERROR																(1<<2)


/*
==================================================
  End Section --> SPI Configurations available options
==================================================
 */



/*
==================================================
  Start Section --> SPI Configurations.
==================================================
 */

typedef struct SPI_Cfg{
	/*This parameter take a value of @ref SPI_Interrupt*/
	u16 Interrupt:3;
	/*This parameter take a value of @ref SPI_Frame_Prescaler*/
	u16 ClockPrescaler:3;
	/*This parameter take a value of @ref SPI_Capture_Strope*/
	u16 CaptureStrobe :2;
	/*This parameter take a value of @ref SPI_Direction*/
	u16 Direction:2;
	/*This parameter take a value of @ref SPI_Frame_Size*/
	u16 FrameSize:2;
	/*This parameter take a value of @ref SPI_State*/
	u16 State:1;
	/*This parameter take a value of @ref SPI_CRC*/
	u16 CRC:1;
	/*This parameter can be the value of SPI instance for example
	 * If you want to configure SPI1, This parameter will take the value 1*/
	u8 InstanceId;
	/*This parameter can be the value of GPIO instance used by SPI for example
		 * If you want to configure GPIOA, This parameter will take the value 'A'*/
	u8 GPIOInstanceId;
	/*This parameter can be the value of assigned pins for SPI instance
	 * using the following pattern
	 * PIN_x_MASK | PIN_y_MASK | PIN_z_MASK
	 * where x, y, and z are the values of selected pins
	 * for example if you want to configure Pin A0, A3, A10
	 * This parameter will take
	 * PIN_0_MASK | PIN_3_MASK | PIN_10_MASK
	 * */
	u16 GPIOPins;
}SPI_Cfg;
/*
==================================================
  Start Section --> SPI Configurations.
==================================================
 */


/*
==================================================
  Start Section --> APIs
==================================================
 */

/* @brief  --> This function configures SPI based on configuration passed through SPI_Cfg struct.
 * @param  Arg_conf_cpcSPI_Cfg --> struct that have configured parameters.
 * @retval --> None.
 * */
void SPI_Config_v(SPI_Cfg const * const Arg_conf_cpcSPI_Cfg);

/* @brief  --> This function transmits 8-bit data using SPI.
 * @param  Arg_conf_cpcSPI_Cfg --> struct that have configured parameters.
 * @param  Arg_data_u8		   --> Data that will be transmitted using SPI.
 * @retval --> None.
 * */
void SPI_Sendu8Data_v(SPI_Cfg const * const Arg_conf_cpcSPI_Cfg, u8 Arg_data_u8);

/* @brief  --> This function transmits 16-bit data using SPI.
 * @param  Arg_conf_cpcSPI_Cfg --> struct that have configured parameters.
 * @param  Arg_data_u16		   --> Data that will be transmitted using SPI.
 * @retval --> None.
 * */
void SPI_Sendu16Data_v(SPI_Cfg const * const Arg_conf_cpcSPI_Cfg, u16 Arg_data_u16);

/* @brief  --> This function changes spi to transmit/receive 16-bit.
 * @param  Arg_conf_cpcSPI_Cfg --> struct that have configured parameters.
 * @retval --> None.
 * */
void SPI_ChangeDataFrameFormatTo16Bit_v(SPI_Cfg const * const Arg_conf_cpcSPI_Cfg);

/* @brief  --> This function changes spi to transmit/receive 8-bit.
 * @param  Arg_conf_cpcSPI_Cfg --> struct that have configured parameters.
 * @retval --> None.
 * */
void SPI_ChangeDataFrameFormatTo8Bit_v(SPI_Cfg const * const Arg_conf_cpcSPI_Cfg);

/* @brief  --> This function checks whether SPI is enabled or not.
 * @param  Arg_conf_cpcSPI_Cfg --> struct that have configured parameters.
 * @retval --> SPI enable/disabled status.
 * */
Bool SPI_IsEnabled_Bool(SPI_Cfg const * const Arg_conf_cpcSPI_Cfg);

/* @brief  --> This function transmits and receives 8-bit data.
 * @param  Arg_conf_cpcSPI_Cfg --> struct that have configured parameters.
 * @param  Arg_data_u8		   --> Data that will be transmitted.
 * @retval --> Data that will be received.
 * */
u8 SPI_SendAndReceive_u8(SPI_Cfg const * const Arg_conf_cpcSPI_Cfg, u8 Arg_data_u8);

/* @brief  --> This function transmits and receives 16-bit data.
 * @param  Arg_conf_cpcSPI_Cfg --> struct that have configured parameters.
 * @param  Arg_data_u16		   --> Data that will be transmitted.
 * @retval --> Data that will be received.
 * */
u16 SPI_SendAndReceive_u16(SPI_Cfg const * const Arg_conf_cpcSPI_Cfg, u8 Arg_data_u16);

/* @brief  --> Enable SPI.
 * @param  Arg_conf_cpcSPI_Cfg --> struct that have configured parameters.
 * @retval --> Data that will be received.
 * */
void SPI_EnableSPI_v(SPI_Cfg const * const Arg_conf_cpcSPI_Cfg);

/* @brief  --> Disable SPI.
 * @param  Arg_conf_cpcSPI_Cfg --> struct that have configured parameters.
 * @retval --> Data that will be received.
 * */
void SPI_DisableSPI_v(SPI_Cfg const * const Arg_conf_cpcSPI_Cfg);

/*
==================================================
  End Section --> APIs
==================================================
 */




#endif /* HMCAL_SPI_SPI_H_ */
