/*
 * File Name --> USART.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> Provides API and available configuration options for USART peripheral.
 * */

#ifndef HMCAL_USART_USART_H_
#define HMCAL_USART_USART_H_
/*
==================================================
  Start Section --> File Includes
==================================================
*/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "USART_defs.h"

/*
==================================================
  End   Section --> File Includes
==================================================
*/


/*
==================================================
  Start Section --> USART Configurations available options
==================================================
*/

/*@ref GPIO_Pin_modes*/
#define 		USART_Databits_8                                                                0
#define 		USART_Databits_9                                                                1

/*Oversampling available options section.*/
#define 		USART_OVERSAMPLING_16                                                           0
#define 		USART_OVERSAMPLING_8                                                            1
/*Parity available options section.*/
#define 		USART_PARITY_DISABLE                                                            0
#define 		USART_PARITY_EVEN                                                               1
#define 		USART_PARITY_ODD                                                                2

/*Interrupt available options section.*/
#define			USART_INTERRUPT_DISABLE															0
#define 		USART_INTERRUPT_TRANSMIT_DATA_EMPTY                                             ((u32)1<<0)
#define 		USART_INTERRUPT_TRANSMIT_COMPLETE                                               ((u32)1<<1)
#define 		USART_INTERRUPT_READ_DATA_REGISTER_NOT_EMPTY                                    ((u32)1<<2)
#define 		USART_INTERRUPT_IDLE_LINE_DETECTED                                              ((u32)1<<3)
#define 		USART_INTERRUPT_CTS                                                             ((u32)1<<4)

#define 		USART_INTERRUPT_ERROR                                                           ((u32)1<<5)
#define 		USART_INTERRUPT_OVERRUN_ERROR                                                   ((u32)1<<6)
#define 		USART_INTERRUPT_NOISE_DETECTED                                                  ((u32)1<<7)
#define 		USART_INTERRUPT_FRAME_ERROR                                                   	((u32)1<<8)
#define 		USART_INTERRUPT_PARITY_ERROR                                                   	((u32)1<<9)



/*DMA available options section.*/
#define			USART_DMA_DISABLE																0
#define 		USART_DMA_TRANSMIT                                                          	((u32)1<<0)
#define 		USART_DMA_RECEIVE                                            					((u32)1<<1)
/*Transmit/Receive available options section.*/
#define			USART_NO_TRANSMIT_NOR_RECEIVE													0
#define 		USART_RECEIVE                                                           		((u32)1<<0)
#define 		USART_TRANSMIT                                            						((u32)1<<1)
/*Stop Bits available options section.*/
#define 		USART_STOP_ONE_BIT                                                              0
#define 		USART_STOP_HALF_BIT                                                             1
#define 		USART_STOP_ONE_HALF_BIT                                                         2
#define 		USART_STOP_TWO_BITS                                                             3
/*Clock available options section.*/
#define 		USART_CLOCK_STEADY_LOW_FIRST_DATA_CAPTURE                                       0
#define 		USART_CLOCK_STEADY_LOW_SECOND_DATA_CAPTURE                                      1
#define 		USART_CLOCK_STEADY_HIGH_FIRST_DATA_CAPTURE                                      2
#define 		USART_CLOCK_STEADY_HIGH_SECOND_DATA_CAPTURE                                     3
/*CTS / RTS available options section.*/
#define 		USART_CTS_DISABLE_RTS_DISABLE                                                   0
#define 		USART_CTS_ENABLE_RTS_DISABLE                                                    1
#define 		USART_CTS_DISABLE_RTS_ENABLE                                                    2
#define 		USART_CTS_ENABLE_RTS_ENABLE                                                     3
/*Half Duplex available options section.*/
#define 		USART_HALF_DUPLEX_DISABLE                                                       0
#define 		USART_HALF_DUPLEX_ENABLE                                                        1
/*
==================================================
  End Section --> USART Configurations available options
==================================================
*/

/*
==================================================
  Start Section --> USART Configurations.
==================================================
*/
typedef struct USART_Cfg{

	u8 Oversampling :1;
	u8 Databits :1;
	u8 HalfDuplex:1;
	u8 Parity :2;
	u8 TransferDirection:2;
	u8 DMA :2;
	u8 StopBits :2;
	u8 ClockPhaseAndPolarity :2;
	u8 Address :2;
	u8 CTSAndRTS :2;
	u32 Interrupt;
	u8 GaurdTime;
	u8 PrescalerValue;
	u8 InstanceId;
	u8 GPIOInstanceId;
	u16 GPIOPins;
	u32 BaudRate;
	u32 PoolingTimeOutInMilliSeconds;
}USART_Cfg;
/*
==================================================
  End Section --> USART Configurations.
==================================================
*/


/*
==================================================
  Start Section --> APIs
==================================================
*/

/* @brief  --> This function configures USART based on configuration passed through USART_Cfg struct.
 * @param  Arg_conf_cpcUSART_Cfg --> struct that have configured parameters.
 * @retval --> None.
 * */
void USART_Config_v(USART_Cfg const * const Arg_conf_cpcUSART_Cfg);

/* @brief  --> This function start USART transmission data.
 * @param  Arg_conf_cpcUSART_Cfg --> Struct to know intended USART.
 * @retval --> None.
 * */
void USART_EnableUSART_v(USART_Cfg const * const Arg_conf_cpcUSART_Cfg);

/* @brief  --> This function stop USART transmission data.
 * @param  Arg_conf_cpcUSART_Cfg --> Struct to know intended USART.
 * @retval --> None.
 * */
void USART_DisableUSART_v(USART_Cfg const * const Arg_conf_cpcUSART_Cfg);

/* @brief  --> This function receives data of 1-byte.
 * @param  Arg_conf_cpcUSART_Cfg --> Struct to know intended USART.
 * @param  Arg_ToutVal_Cu32		 --> Timeout value of received data. For infinite time, pass STD_MAX_DELAY.
 * @param  Arg_ToutErr_pCu32	 --> To determine whether received data is complete or exceed timeout value.
 * @retval --> Received data.
 * */
u8 USART_ReceiveU8Pooling_u8(
		USART_Cfg const * const Arg_conf_cpcUSART_Cfg, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32);

/* @brief  --> This function receives data of 2-bytes.
 * @param  Arg_conf_cpcUSART_Cfg 		 --> Struct to know intended USART.
 * @param  Arg_EndianMode_STD_EndianType --> Select whether it's bigger (STD_BigEndian) or little (STD_LittleEndian) endian mode.
 * @param  Arg_ToutVal_Cu32		 		 --> Timeout value of received data. For infinite time, pass STD_MAX_DELAY.
 * @param  Arg_ToutErr_pCu32	 		 --> To determine whether received data is complete or exceed timeout value.
 * @retval --> Received data.
 * */
u16 USART_ReceiveU16Pooling_u16(
		USART_Cfg const * const Arg_conf_cpcUSART_Cfg, const STD_EndianType Arg_EndianMode_STD_EndianType, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32);

/* @brief  --> This function receives data of 4-bytes.
 * @param  Arg_conf_cpcUSART_Cfg 		 --> Struct to know intended USART.
 * @param  Arg_EndianMode_STD_EndianType --> Select whether it's bigger (STD_BigEndian) or little (STD_LittleEndian) endian mode.
 * @param  Arg_ToutVal_Cu32		 		 --> Timeout value of received data. For infinite time, pass STD_MAX_DELAY.
 * @param  Arg_ToutErr_pCu32	 		 --> To determine whether received data is complete or exceed timeout value.
 * @retval --> Received data.
 * */
u32 USART_ReceiveU32Pooling_u32(
		USART_Cfg const * const Arg_conf_cpcUSART_Cfg, const STD_EndianType Arg_EndianMode_STD_EndianType, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32);

/* @brief  --> This function receives data of 8-bytes.
 * @param  Arg_conf_cpcUSART_Cfg 		 --> Struct to know intended USART.
 * @param  Arg_EndianMode_STD_EndianType --> Select whether it's bigger (STD_BigEndian) or little (STD_LittleEndian) endian mode.
 * @param  Arg_ToutVal_Cu32		 		 --> Timeout value of received data. For infinite time, pass STD_MAX_DELAY.
 * @param  Arg_ToutErr_pCu32	 		 --> To determine whether received data is complete or exceed timeout value.
 * @retval --> Received data.
 * */
u64 USART_ReceiveU64Pooling_u64(
		USART_Cfg const * const Arg_conf_cpcUSART_Cfg, const STD_EndianType Arg_EndianMode_STD_EndianType, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32);

/* @brief --> This function stores 1-byte received data in an array.
 * @param  Arg_conf_cpcUSART_Cfg 		 --> Struct to know intended USART.
 * @param  Arg_Arr_pu8					 --> Address of array.
 * @param  Arg_ArrLen_u32				 --> Array length.
 * @param  Arg_ToutVal_Cu32		 		 --> Timeout value of received data. For infinite time, pass STD_MAX_DELAY.
 * @param  Arg_ToutErr_pCu32	 		 --> To determine whether received data is complete or exceed timeout value.
 * @retval --> None.
 * */
void USART_ReceiveU8ArrayPooling_v(
		USART_Cfg const * const Arg_conf_cpcUSART_Cfg, u8 *Arg_Arr_pu8, u32 Arg_ArrLen_u32, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32);

/* @brief --> This function stores 2-bytes received data in an array.
 * @param  Arg_conf_cpcUSART_Cfg 		 --> Struct to know intended USART.
 * @param  Arg_Arr_pu16					 --> Address of array.
 * @param  Arg_ArrLen_u32				 --> Array length.
 * @param  Arg_EndianMode_STD_EndianType --> Select whether it's bigger (STD_BigEndian) or little (STD_LittleEndian) endian mode.
 * @param  Arg_ToutVal_Cu32		 		 --> Timeout value of received data. For infinite time, pass STD_MAX_DELAY.
 * @param  Arg_ToutErr_pCu32	 		 --> To determine whether received data is complete or exceed timeout value.
 * @retval --> None.
 * */
void USART_ReceiveU16ArrayPooling_v(
		USART_Cfg const * const Arg_conf_cpcUSART_Cfg, u16 *Arg_Arr_pu16, u32 Arg_ArrLen_u16, const STD_EndianType Arg_EndianMode_STD_EndianType, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32);

/* @brief --> This function stores 4-bytes received data in an array.
 * @param  Arg_conf_cpcUSART_Cfg 		 --> Struct to know intended USART.
 * @param  Arg_Arr_pu32					 --> Address of array.
 * @param  Arg_ArrLen_u32				 --> Array length.
 * @param  Arg_EndianMode_STD_EndianType --> Select whether it's bigger (STD_BigEndian) or little (STD_LittleEndian) endian mode.
 * @param  Arg_ToutVal_Cu32		 		 --> Timeout value of received data. For infinite time, pass STD_MAX_DELAY.
 * @param  Arg_ToutErr_pCu32	 		 --> To determine whether received data is complete or exceed timeout value.
 * @retval --> None.
 * */
void USART_ReceiveU32ArrayPooling_v(
		USART_Cfg const * const Arg_conf_cpcUSART_Cfg, u32 *Arg_Arr_pu32, u32 Arg_ArrLen_u32, const STD_EndianType Arg_EndianMode_STD_EndianType, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32);

/* @brief --> This function stores 4-bytes received data in an array.
 * @param  Arg_conf_cpcUSART_Cfg 		 --> Struct to know intended USART.
 * @param  Arg_Arr_pu64					 --> Address of array.
 * @param  Arg_ArrLen_u32				 --> Array length.
 * @param  Arg_EndianMode_STD_EndianType --> Select whether it's bigger (STD_BigEndian) or little (STD_LittleEndian) endian mode.
 * @param  Arg_ToutVal_Cu32		 		 --> Timeout value of received data. For infinite time, pass STD_MAX_DELAY.
 * @param  Arg_ToutErr_pCu32	 		 --> To determine whether received data is complete or exceed timeout value.
 * @retval --> None.
 * */
void USART_ReceiveU64ArrayPooling_v(
		USART_Cfg const * const Arg_conf_cpcUSART_Cfg, u64 *Arg_Arr_pu64, u32 Arg_ArrLen_u32, const STD_EndianType Arg_EndianMode_STD_EndianType, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32 );

/* @brief  --> This function send data of 1-byte.
 * @param  Arg_conf_cpcUSART_Cfg 		 --> Struct to know intended USART.
 * @param  Arg_Data_u8					 --> Data that will be sent.
 * @param  Arg_ToutVal_Cu32		 		 --> Timeout value of received data. For infinite time, pass STD_MAX_DELAY.
 * @param  Arg_ToutErr_pCu32	 		 --> To determine whether received data is complete or exceed timeout value.
 * @retval --> Received data.
 * */
void USART_SendU8Pooling_v(
		USART_Cfg const * const Arg_conf_cpcUSART_Cfg, u8 Arg_Data_u8, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32);

/* @brief  --> This function send data of 2-bytes.
 * @param  Arg_conf_cpcUSART_Cfg 		 --> Struct to know intended USART.
 * @param  Arg_Data_u16			 		 --> Data that will be sent.
 * @param  Arg_EndianMode_STD_EndianType --> Select whether it's bigger (STD_BigEndian) or little (STD_LittleEndian) endian mode.
 * @param  Arg_ToutVal_Cu32		 		 --> Timeout value of received data. For infinite time, pass STD_MAX_DELAY.
 * @param  Arg_ToutErr_pCu32	 		 --> To determine whether received data is complete or exceed timeout value.
 * @retval --> Received data.
 * */
void USART_SendU16Pooling_v(
		USART_Cfg const * const Arg_conf_cpcUSART_Cfg, u16 Arg_Data_u16, const STD_EndianType Arg_EndianMode_STD_EndianType, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32);

/* @brief  --> This function send data of 4-bytes.
 * @param  Arg_conf_cpcUSART_Cfg 		 --> Struct to know intended USART.
 * @param  Arg_Data_u32			 		 --> Data that will be sent.
 * @param  Arg_EndianMode_STD_EndianType --> Select whether it's bigger (STD_BigEndian) or little (STD_LittleEndian) endian mode.
 * @param  Arg_ToutVal_Cu32		 		 --> Timeout value of received data. For infinite time, pass STD_MAX_DELAY.
 * @param  Arg_ToutErr_pCu32	 		 --> To determine whether received data is complete or exceed timeout value.
 * @retval --> Received data.
 * */
void USART_SendU32Pooling_v(
		USART_Cfg const * const Arg_conf_cpcUSART_Cfg, u32 Arg_Data_u32, const STD_EndianType Arg_EndianMode_STD_EndianType, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32);

/* @brief  --> This function send data of 8-bytes.
 * @param  Arg_conf_cpcUSART_Cfg 		 --> Struct to know intended USART.
 * @param  Arg_Data_u64			 		 --> Data that will be sent.
 * @param  Arg_EndianMode_STD_EndianType --> Select whether it's bigger (STD_BigEndian) or little (STD_LittleEndian) endian mode.
 * @param  Arg_ToutVal_Cu32		 		 --> Timeout value of received data. For infinite time, pass STD_MAX_DELAY.
 * @param  Arg_ToutErr_pCu32	 		 --> To determine whether received data is complete or exceed timeout value.
 * @retval --> Received data.
 * */
void USART_SendU64Pooling_v(
		USART_Cfg const * const Arg_conf_cpcUSART_Cfg, u64 Arg_Data_u64, const STD_EndianType Arg_EndianMode_STD_EndianType, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32);


/* @brief  --> This function send array of 1-byte data.
 * @param  Arg_conf_cpcUSART_Cfg 		 --> Struct to know intended USART.
 * @param  Arg_Arr_pu8			 		 --> Array of Data that will be sent.
 * @param  Arg_ArrLen_u32 				 --> Array length.
 * @param  Arg_ToutVal_Cu32		 		 --> Timeout value of received data. For infinite time, pass STD_MAX_DELAY.
 * @param  Arg_ToutErr_pCu32	 		 --> To determine whether received data is complete or exceed timeout value.
 * @retval --> Received data.
 * */
void USART_SendU8ArrayPooling_v(
		USART_Cfg const * const Arg_conf_cpcUSART_Cfg, u8 *Arg_Arr_pu8, u32 Arg_ArrLen_u32, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32);

/* @brief  --> This function send array of 2-bytes data.
 * @param  Arg_conf_cpcUSART_Cfg 		 --> Struct to know intended USART.
 * @param  Arg_Arr_pu16			 		 --> Array of Data that will be sent.
 * @param  Arg_ArrLen_u32 				 --> Array length.
 * @param  Arg_EndianMode_STD_EndianType --> Select whether it's bigger (STD_BigEndian) or little (STD_LittleEndian) endian mode.
 * @param  Arg_ToutVal_Cu32		 		 --> Timeout value of received data. For infinite time, pass STD_MAX_DELAY.
 * @param  Arg_ToutErr_pCu32	 		 --> To determine whether received data is complete or exceed timeout value.
 * @retval --> Received data.
 * */
void USART_SendU16ArrayPooling_v(
		USART_Cfg const * const Arg_conf_cpcUSART_Cfg, u16 *Arg_Arr_pu16, u32 Arg_ArrLen_u32, const STD_EndianType Arg_EndianMode_STD_EndianType, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32);

/* @brief  --> This function send array of 4-bytes data.
 * @param  Arg_conf_cpcUSART_Cfg 		 --> Struct to know intended USART.
 * @param  Arg_Arr_pu32			 		 --> Array of Data that will be sent.
 * @param  Arg_ArrLen_u32 				 --> Array length.
 * @param  Arg_EndianMode_STD_EndianType --> Select whether it's bigger (STD_BigEndian) or little (STD_LittleEndian) endian mode.
 * @param  Arg_ToutVal_Cu32		 		 --> Timeout value of received data. For infinite time, pass STD_MAX_DELAY.
 * @param  Arg_ToutErr_pCu32	 		 --> To determine whether received data is complete or exceed timeout value.
 * @retval --> Received data.
 * */
void USART_SendU32ArrayPooling_v(
		USART_Cfg const * const Arg_conf_cpcUSART_Cfg, u32 *Arg_Arr_pu32, u32 Arg_ArrLen_u32, const STD_EndianType Arg_EndianMode_STD_EndianType, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32);


/* @brief  --> This function send array of 8-bytes data.
 * @param  Arg_conf_cpcUSART_Cfg 		 --> Struct to know intended USART.
 * @param  Arg_Arr_pu64			 		 --> Array of Data that will be sent.
 * @param  Arg_ArrLen_u32 				 --> Array length.
 * @param  Arg_EndianMode_STD_EndianType --> Select whether it's bigger (STD_BigEndian) or little (STD_LittleEndian) endian mode.
 * @param  Arg_ToutVal_Cu32		 		 --> Timeout value of received data. For infinite time, pass STD_MAX_DELAY.
 * @param  Arg_ToutErr_pCu32	 		 --> To determine whether received data is complete or exceed timeout value.
 * @retval --> Received data.
 * */
void USART_SendU64ArrayPooling_v(
		USART_Cfg const * const Arg_conf_cpcUSART_Cfg, u64 *Arg_Arr_pu64, u32 Arg_ArrLen_u32, const STD_EndianType Arg_EndianMode_STD_EndianType, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32);

/* @brief  --> This function gets the address which used with DMA.
 * @param  Arg_conf_cpcUSART_Cfg --> Struct to know intended USART.
 * @retval --> Address of Data register USART .
 * */
u32 USART_GetAdressForDMA_u32(USART_Cfg const * const Arg_conf_cpcUSART_Cfg);

/* @brief  --> This function is used by interrupt handler to check the existence of interrupt
 * and clear pending flag for this interrupt type.
 * @param  Arg_USARTInstanceId_u8 --> Instance id of USART that you need to check about it.
 * @param  Arg_USARTInterruptType_u8 -->	USART interrupt type.
 * @retval --> Is there any interrupt for the mentioned interrupt type of USART.
 * */
Bool USART_CheckInterruptAndClear_Bool(u8 Arg_USARTInstanceId_u8, u8 Arg_USARTInterruptType_u8);

/* @brief  --> This function is used by interrupt callback to get received data from interrupt callback only!
 * @param  Arg_conf_cpcUSART_Cfg --> Instance id of USART that you need to check about it.
 * @retval --> received data.
 * */
u8 USART_ReceiveU8Interrupt_u8(USART_Cfg const * const Arg_conf_cpcUSART_Cfg);

/* @brief  --> This function resets USART to it's default configurations
 * @param  Arg_conf_cpcUSART_Cfg --> struct that have configured parameters.
 * @retval --> None.
 * */
void USART_Reset_v (USART_Cfg const * const Arg_conf_cpcUSART_Cfg);
/*
==================================================
  End Section --> APIs
==================================================
*/
#endif /* HMCAL_USART_USART_H_ */
