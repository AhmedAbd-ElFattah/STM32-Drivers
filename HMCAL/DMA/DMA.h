/*
 * File Name --> DMA.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> Provides API and available configuration options for DMA peripheral.
 * */

#ifndef HMCAL_DMA_DMA_H_
#define HMCAL_DMA_DMA_H_


/*
==================================================
  Start Section --> File Includes
==================================================
*/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

/*
==================================================
  End   Section --> File Includes
==================================================
*/

/*
==================================================
  Start Section --> DMA Configurations available options
==================================================
*/
/*@ref DMA_Burst*/
/*Burst available options section.*/
#define 		DMA_BURST_MEM_SINGLE_TRANSFER_PERPH_SINGLE_TRANSFER                  0
#define 		DMA_BURST_MEM_INCR_4_BEATS_TRANSFER_PERPH_SINGLE_TRANSFER            1
#define 		DMA_BURST_MEM_INCR_8_BEATS_TRANSFER_PERPH_SINGLE_TRANSFER            2
#define 		DMA_BURST_MEM_INCR_16_BEATS_TRANSFER_PERPH_SINGLE_TRANSFER           3

#define 		DMA_BURST_MEM_SINGLE_TRANSFER_PERPH_INCR_4_BEATS                     4
#define 		DMA_BURST_MEM_INCR_4_BEATS_TRANSFER_PERPH_INCR_4_BEATS        		 5
#define 		DMA_BURST_MEM_INCR_8_BEATS_TRANSFER_PERPH_INCR_4_BEATS        		 6
#define 		DMA_BURST_MEM_INCR_16_BEATS_TRANSFER_PERPH_INCR_4_BEATS       		 7

#define 		DMA_BURST_MEM_SINGLE_TRANSFER_PERPH_INCR_8_BEATS                     8
#define 		DMA_BURST_MEM_INCR_4_BEATS_TRANSFER_PERPH_INCR_8_BEATS        		 9
#define 		DMA_BURST_MEM_INCR_8_BEATS_TRANSFER_PERPH_INCR_8_BEATS        		 10
#define 		DMA_BURST_MEM_INCR_16_BEATS_TRANSFER_PERPH_INCR_8_BEATS       		 11

#define 		DMA_BURST_MEM_SINGLE_TRANSFER_PERPH_INCR_16_BEATS                    12
#define 		DMA_BURST_MEM_INCR_4_BEATS_TRANSFER_PERPH_INCR_16_BEATS       		 13
#define 		DMA_BURST_MEM_INCR_8_BEATS_TRANSFER_PERPH_INCR_16_BEATS     		 14
#define 		DMA_BURST_MEM_INCR_16_BEATS_TRANSFER_PERPH_INCR_16_BEATS      		 15


/*@ref DMA_Double_Buffer*/
/*Double buffer available options section.*/
#define 		DMA_DOUBLE_BUFFER_DISABLE                                            0
#define 		DMA_DOUBLE_BUFFER_ENABLE_START_BUFFER_0                              1
#define 		DMA_DOUBLE_BUFFER_ENABLE_START_BUFFER_1                              2

/*@ref DMA_Priority*/
/*Priority available options section.*/
#define 		DMA_PRIORITY_LOW                                                     0
#define 		DMA_PRIORITY_MEDIUM                                                  1
#define 		DMA_PRIORITY_HIGH                                                    2
#define 		DMA_PRIORITY_VERY_HIGH                                               3

/*@ref DMA_Peripheral_Increment_Offset*/
/*Peripheral increment offset available options section.*/
#define 		DMA_PERPH_INCR_AS_PERPH_SIZE                                         0
#define 		DMA_PERPH_INCR_IS_WORD                                               1

/*@ref DMA_Data_Size*/
/*Data size available options section.*/
#define 		DMA_DATA_SIZE_MEM_BYTE_PERPH_BYTE                                    0
#define 		DMA_DATA_SIZE_MEM_BYTE_PERPH_HALF_WORD                               1
#define 		DMA_DATA_SIZE_MEM_BYTE_PERPH_WORD                                    2

#define 		DMA_DATA_SIZE_MEM_HALF_WORD_PERPH_BYTE                               3
#define 		DMA_DATA_SIZE_MEM_HALF_WORD_PERPH_HALF_WORD                          4
#define 		DMA_DATA_SIZE_MEM_HALF_WORD_PERPH_WORD                               5

#define 		DMA_DATA_SIZE_MEM_WORD_PERPH_BYTE                                    6
#define 		DMA_DATA_SIZE_MEM_WORD_PERPH_HALF_WORD                               7
#define 		DMA_DATA_SIZE_MEM_WORD_PERPH_WORD                                    8

/*@ref DMA_Increment_Mode*/
/*Increment mode of Memory and Peripheral  available options section.*/
#define 		DMA_INCREMENT_MODE_FIXED_MEM_FIXED_PERPH		                     0
#define 		DMA_INCREMENT_MODE_INCR_MEM_INCR_PERPH                            	 1
#define 		DMA_INCREMENT_MODE_FIXED_MEM_INCR_PERPH                              2
#define 		DMA_INCREMENT_MODE_INCR_MEM_FIXED_PERPH                              3

/*@ref DMA_Transfer_Dir*/
/*Data transfer direction available options section.*/
#define 		DMA_TRANSFER_DIR_PERPH_TO_MEM		                                 0
#define 		DMA_TRANSFER_DIR_MEM_TO_PERPH                                    	 1
#define 		DMA_TRANSFER_DIR_MEM_TO_MEM                                       	 2

/*@ref DMA_Circular_Mode*/
/*Circular Mode available options section.*/
#define 		DMA_CIRCULAR_MODE_DISABLE                                            0
#define 		DMA_CIRCULAR_MODE_ENABLE                                             1

/*@ref DMA_Flow_Controller*/
/*Flow Controller available options section.*/
#define 		DMA_FLOW_Controller_DMA                                              0
#define 		DMA_PERPH_Controller_DMA                                             1

/*@ref DMA_Direct_Mode*/
/*Direct Mode available options section.*/
#define 		DMA_DIRECT_MODE_ENABLE                                               0
#define 		DMA_DIRECT_MODE_DISABLE                                              1

/*@ref DMA_Interrupt*/
/*Interrupt available options.*/
#define			DMA_INTERRUPT_DISABLE												 0
#define 		DMA_INTERRUPT_FIFO_ERR												 (u8)(1<<0)
#define 		DMA_INTERRUPT_DIRECT_MODE_ERR										 (u8)(1<<2)
#define 		DMA_INTERRUPT_TRANSFER_ERR											 (u8)(1<<3)
#define 		DMA_INTERRUPT_HALF_TRANSFER											 (u8)(1<<4)
#define 		DMA_INTERRUPT_TRANSFER_COMPLETE										 (u8)(1<<5)


/*@ref DMA_ChannelNumber_StreamNumber*/
#define	DMA1_SPI3_RX_CH_0_S_2				0x02
#define	DMA1_SPI2_RX_CH_0_S_3				0x03
#define	DMA1_SPI2_TX_CH_0_S_4				0x04
#define	DMA1_SPI3_TX_CH_0_S_5				0x05
#define	DMA1_SPI3_TX_CH_0_S_7				0x07

#define	DMA1_I2C1_RX_CH_1_S_0				0x10
#define	DMA1_TIM7_UP_CH_1_S_2				0x12
#define	DMA1_TIM7_UP_CH_1_S_4				0x14
#define	DMA1_I2C1_RX_CH_1_S_5				0x15
#define	DMA1_I2C1_TX_CH_1_S_6				0x16
#define	DMA1_I2C1_TX_CH_1_S_7				0x17

#define	DMA1_TIM4_CH1_CH_2_S_0				0x20
#define	DMA1_I2S3_EXT_RX_CH_2_S_2			0x22
#define	DMA1_TIM4_CH2_CH_2_S_3				0x23
#define	DMA1_I2S2_EXT_TX_CH_2_S_4			0x24
#define	DMA1_I2S3_EXT_TX_CH_2_S_5			0x25
#define	DMA1_TIM4_UP_CH_2_S_6				0x26
#define	DMA1_TIM4_CH3_CH_2_S_7				0x27

#define	DMA1_I2S3_EXT_RX_CH_3_S_0			0x30
#define	DMA1_TIM2_CH3_CH_3_S_1				0x31
#define	DMA1_TIM2_UP_CH_3_S_1				0x31
#define	DMA1_I2C3_RX_CH_3_S_2				0x32
#define	DMA1_I2S2_EXT_RX_CH_3_S_3			0x33
#define	DMA1_I2C3_TX_CH_3_S_4				0x34
#define	DMA1_TIM2_CH1_CH_3_S_5				0x35
#define	DMA1_TIM2_CH2_CH_3_S_6				0x36
#define	DMA1_TIM2_CH4_CH_3_S_6				0x36
#define	DMA1_TIM2_UP_CH_3_S_7				0x37
#define	DMA1_TIM2_CH4_CH_3_S_7				0x37

#define	DMA1_UART5_RX_CH_4_S_0				0x40
#define	DMA1_USART3_RX_CH_4_S_1				0x41
#define	DMA1_UART4_RX_CH_4_S_2				0x42
#define	DMA1_USART3_TX_CH_4_S_3				0x43
#define	DMA1_UART4_TX_CH_4_S_4				0x44
#define	DMA1_USART2_RX_CH_4_S_5				0x45
#define	DMA1_USART2_TX_CH_4_S_6				0x46
#define	DMA1_UART5_TX_CH_4_S_7				0x47

#define	DMA1_TIM3_UP_CH_5_S_2				0x52
#define	DMA1_TIM3_CH4_CH_5_S_2				0x52
#define	DMA1_TIM3_TRIG_CH_5_S_4				0x54
#define	DMA1_TIM3_CH1_CH_5_S_4	            0x54
#define	DMA1_TIM3_CH2_CH_5_S_5	            0x55
#define	DMA1_TIM3_CH3_CH_5_S_7	            0x57

#define	DMA1_TIM5_CH3_CH_6_S_0	            0x60
#define	DMA1_TIM5_UP_CH_6_S_0	            0x60
#define	DMA1_TIM5_CH4_CH_6_S_1	            0x61
#define	DMA1_TIM5_TRIG_CH_6_S_1				0x61
#define	DMA1_TIM5_CH1_CH_6_S_2				0x62
#define	DMA1_TIM5_CH4_CH_6_S_3				0x63
#define	DMA1_TIM5_TRIG_CH_6_S_3				0x63
#define	DMA1_TIM5_CH2_CH_6_S_4	            0x64
#define	DMA1_TIM5_UP_CH_6_S_6	            0x66

#define	DMA1_TIM6_UP_CH_7_S_1	            0x71
#define	DMA1_I2C2_RX_CH_7_S_2	            0x72
#define	DMA1_I2C2_RX_CH_7_S_3	            0x73
#define	DMA1_USART3_TX_CH_7_S_4				0x74
#define	DMA1_DAC1_CH_7_S_5					0x75
#define	DMA1_DAC2_CH_7_S_6					0x76
#define	DMA1_I2C2_TX_CH_7_S_7				0x77


#define	DMA2_TIM8_CH3_CH_0_S_2	            0x02
#define	DMA2_TIM8_CH2_CH_0_S_2	            0x02
#define	DMA2_TIM8_CH1_CH_0_S_2	            0x02
#define	DMA2_ADC1_CH_0_S_4		            0x04
#define	DMA2_TIM1_CH3_CH_0_S_6	            0x06
#define	DMA2_TIM1_CH2_CH_0_S_6	            0x06
#define	DMA2_TIM1_CH1_CH_0_S_6	            0x06
#define	DMA2_DCMI_CH_1_S_1	                0x11
#define	DMA2_ADC2_CH_1_S_2	                0x12
#define	DMA2_ADC2_CH_1_S_3	                0x13
#define	DMA2_DCMI_CH_1_S_7	                0x17
#define	DMA2_ADC3_CH_2_S_0	                0x20
#define	DMA2_ADC3_CH_2_S_1	                0x21
#define	DMA2_CRYP_OUT_CH_2_S_5	            0x25
#define	DMA2_CRYP_IN_CH_2_S_6	            0x26
#define	DMA2_HASH_IN_CH_2_S_7	            0x27
#define	DMA2_USART1_RX_CH_4_S_2				0x42
#define	DMA2_SDIO_CH_4_S_3					0x43
#define	DMA2_USART1_RX_CH_4_S_5				0x45
#define	DMA2_SDIO_CH_4_S_6					0x46
#define	DMA2_USART1_TX_CH_4_S_7				0x47
#define	DMA2_USART6_RX_CH_5_S_1				0x51
#define	DMA2_USART6_RX_CH_5_S_2				0x52
#define	DMA2_USART6_TX_CH_5_S_6				0x56
#define	DMA2_USART6_TX_CH_5_S_7				0x57
#define	DMA2_TIM1_TRIG_CH_6_S_0				0x60
#define	DMA2_TIM1_CH1_CH_6_S_1				0x61
#define	DMA2_TIM1_CH2_CH_6_S_2				0x62
#define	DMA2_TIM1_CH1_CH_6_S_3				0x63
#define	DMA2_TIM1_CH4_CH_6_S_4				0x64
#define	DMA2_TIM1_TRIG_CH_6_S_4				0x64
#define	DMA2_TIM1_COM_CH_6_S_4				0x64
#define	DMA2_TIM1_UP_CH_6_S_5				0x65
#define	DMA2_TIM1_CH3_CH_6_S_6				0x66
#define	DMA2_TIM8_UP_CH_7_S_1				0x71
#define	DMA2_TIM8_CH1_CH_7_S_2				0x72
#define	DMA2_TIM8_CH2_CH_7_S_3				0x73
#define	DMA2_TIM8_CH3_CH_7_S_4				0x74
#define	DMA2_TIM8_CH4_CH_7_S_7				0x77
#define	DMA2_TIM8_TRIG_CH_7_S_7				0x77
#define	DMA2_TIM8_COM_CH_7_S_7				0x77

#define DMA2_MEM_S_0						0x0
#define DMA2_MEM_S_1						0x1
#define DMA2_MEM_S_2						0x2
#define DMA2_MEM_S_3						0x3
#define DMA2_MEM_S_4						0x4
#define DMA2_MEM_S_5						0x5
#define DMA2_MEM_S_6						0x6
#define DMA2_MEM_S_7						0x7
/*
==================================================
  End   Section --> DMA Configurations available options
==================================================
*/

/*
==================================================
  Start Section --> DMA Configurations.
==================================================
*/
typedef struct DMA_Configurations{
	/*This parameter can be the value of DMA instance for example
	 * If you want to configure DMA1, This parameter will take the value 1*/
	u8 InstanceId;
	/*This parameter take a value of @ref DMA_Interrupt*/
	u8 Interrupt;
	/*This parameter take a value of @ref DMA_Data_Size*/
	u8 DataSize;
	/*This parameter take a value of @ref DMA_Peripheral_Increment_Offset*/
	u8 PeripheralIncrementOffset;
	/*This parameter take a value of @ref DMA_Priority*/
	u8 Priority;
	/*This parameter take a value of @ref DMA_Burst*/
	u8 Burst;
	/*This parameter take a value of @ref DMA_Double_Buffer*/
	u8 DoubleBuffer;
	/*This parameter take a value of @ref DMA_Direct_Mode*/
	u8 DirectMode;
	/*This parameter take a value of @ref DMA_Circular_Mode*/
	u8 CircularMode;
	/*This parameter take a value of @ref DMA_Flow_Controller*/
	u8 FlowController;
	/*This parameter take a value of @ref DMA_Increment_Mode*/
	u8 IncrementMode;
	/*This parameter take a value of @ref DMA_Transfer_Dir*/
	u8 TransferDir;
	/*This parameter can be the value of DMA Stream Size for example
	 * If you want to transfer array with length = 10 elements, This parameter will take the value 10*/
	u16 Size;

	u32 PeripheralAddress;
	u32 MemoryAddress;
	u32 MemoryAddressSecondBuffer;

}DMA_Cfg;
/*
==================================================
  End Section --> DMA Configurations.
==================================================
*/


/*
==================================================
  Start Section --> APIs
==================================================
*/

/* @brief  --> This function configures DMA based on configuration passed through DMA_Cfg struct.
 * @param  Arg_conf_cpcDMA_Cfg --> struct that have configured parameters.
 * @param  Arg_ChannelStream_Cu8 --> Contains stream & channel number
 * encoded in one of the following options @ref DMA_ChannelNumber_StreamNumber
 * @retval --> None.
 * */
void DMA_Config_v(DMA_Cfg const * const Arg_conf_cpcDMA_Cfg,const u8 Arg_ChannelStream_Cu8);

/* @brief  --> This function enable DMA transmission data.
 * @param  Arg_conf_cpcDMA_Cfg --> Struct to know intended DMA.
 * @param  Arg_ChannelStream_Cu8 --> Contains stream & channel number
 * encoded in one of the following options @ref DMA_ChannelNumber_StreamNumber
 * @retval --> None.
 * */
void DMA_EnableDMA_v (DMA_Cfg const * const Arg_conf_cpcDMA_Cfg,const u8 Arg_ChannelStream_Cu8);

/* @brief  --> This function disable DMA transmission data.
 * @param  Arg_conf_cpcDMA_Cfg --> Struct to know intended DMA.
 * @param  Arg_ChannelStream_Cu8 --> Contains stream & channel number
 * encoded in one of the following options @ref DMA_ChannelNumber_StreamNumber
 * @retval --> None.
 * */
void DMA_DisableDMA_v (DMA_Cfg const * const Arg_conf_cpcDMA_Cfg,const u8 Arg_ChannelStream_Cu8);

/* @brief  --> This function changes DMA buffer 0.
 * @param  Arg_conf_cpcDMA_Cfg --> Struct to know intended DMA.
 * @param  Arg_ChannelStream_Cu8 --> Contains stream & channel number
 * encoded in one of the following options @ref DMA_ChannelNumber_StreamNumber
 * @param  Arg_NewAddress_Cu32 --> contains the new assigned address.
 * @retval --> None.
 * */
void DMA_ChangeBuffer0Address_v (DMA_Cfg  * const Arg_conf_cpcDMA_Cfg,const u8 Arg_ChannelStream_Cu8, const u32 Arg_NewAddress_Cu32);

/* @brief  --> This function changes DMA buffer 1.
 * @param  Arg_conf_cpcDMA_Cfg --> Struct to know intended DMA.
 * @param  Arg_ChannelStream_Cu8 --> Contains stream & channel number
 * encoded in one of the following options @ref DMA_ChannelNumber_StreamNumber
 * @param  Arg_NewAddress_Cu32 --> contains the new assigned address.
 * @retval --> None.
 * */
void DMA_ChangeBuffer1Address_v (DMA_Cfg  * const Arg_conf_cpcDMA_Cfg,const u8 Arg_ChannelStream_Cu8, const  u32 Arg_NewAddress_Cu32);

/* @brief  --> This function is used by interrupt handler to check the existence of interrupt
 * and clear pending flag for this interrupt type.
 * @param  Arg_DMAInstanceId_u8 --> Instance id of DMA that you need to check about it.
 * @param  Arg_StreamNum_Cu8 -->	Stream number that you need to check about it.
 * @param  Arg_InterruptFlagPos_Cu8 --> Interrupt flag bit-position in LISR or HISR register.
 * @retval --> Is there any interrupt for the mentioned stream of DMA.
 * */
Bool DMA_CheckInterruptAndClear_Bool(const u8 Arg_DMAInstanceId_u8,const  u8 Arg_StreamNum_Cu8, const  u8 Arg_InterruptFlagPos_Cu8);

/* @brief  --> This function returns current active buffer.
 * @param  Arg_conf_cpcDMA_Cfg --> Struct to know intended DMA.
 * @param  Arg_ChannelStream_Cu8 --> Contains encoded stream & channel number.
 * @retval --> current active buffer number.
 * */
u8 DMA_GetCurrentBuffer_v(DMA_Cfg const * const Arg_conf_cpcDMA_Cfg,const u8 Arg_ChannelStream_Cu8);

/* @brief  --> This function resets DMA to it's default configurations
 * @param  Arg_conf_cpcDMA_Cfg --> struct that have configured parameters.
 * @param  Arg_ChannelStream_Cu8 --> Contains stream & channel number
 * encoded in one of the following options @ref DMA_ChannelNumber_StreamNumber
 * @retval --> None.
 * */
void DMA_Reset_v(DMA_Cfg const * const Arg_conf_cpcDMA_Cfg,const  u8 Arg_ChannelStream_Cu8);
/*
==================================================
  End Section --> APIs
==================================================
*/
#endif /* HMCAL_DMA_DMA_H_ */
