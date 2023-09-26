/*
 * File Name --> DAC.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> Provides API and available configuration options for DAC peripheral.
 * */

#ifndef HMCAL_DAC_DAC_H_
#define HMCAL_DAC_DAC_H_




/*
==================================================
  Start Section --> File Includes
==================================================
 */
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "STM32_Drivers_Configurations/Driver_Config.h"
#include "HMCAL/Interrupt/InterruptHandlers.h"
/*
==================================================
  End   Section --> File Includes
==================================================
 */


/*
==================================================
  Start Section --> DAC Configurations available options
==================================================
 */


/*@ref DAC_Channel*/
#define DAC_CHANNEL_1			0
#define DAC_CHANNEL_2			1

/*@ref DAC_Wave_Generation*/
/*Wave generation available options section.*/
#define 		DAC_WAVE_GENERATION_DISABLE                                              		0
#define 		DAC_WAVE_GENERATION_NOISE                                                		1
#define 		DAC_WAVE_GENERATION_TRIANGLE                                             		2

/*@ref DAC_Buffer*/
/*DAC Buffer available options section.*/
#define 		DAC_BUFFER_DISABLE                                                              0
#define 		DAC_BUFFER_ENABLE                                                               1

/*@ref DAC_Max_Amplitude*/
/*DAC Amplitude available options section.*/
#define			DAC_MAX_AMPLITUDE_1																0
#define			DAC_MAX_AMPLITUDE_3																1
#define			DAC_MAX_AMPLITUDE_7																2
#define			DAC_MAX_AMPLITUDE_15															3
#define			DAC_MAX_AMPLITUDE_31															4
#define			DAC_MAX_AMPLITUDE_63															5
#define			DAC_MAX_AMPLITUDE_127															6
#define			DAC_MAX_AMPLITUDE_255															7
#define			DAC_MAX_AMPLITUDE_511															8
#define			DAC_MAX_AMPLITUDE_1023															9
#define			DAC_MAX_AMPLITUDE_2047															10
#define			DAC_MAX_AMPLITUDE_4095															11

/*@ref DAC_Trigger*/
/*DAC Trigger options section.*/
#define			DAC_TRIGGER_NO_TRIGGER															0
#define			DAC_TRIGGER_TIM6_TRGO															1
#define			DAC_TRIGGER_TIM8_TRGO															2
#define			DAC_TRIGGER_TIM7_TRGO															3
#define			DAC_TRIGGER_TIM5_TRGO															4
#define			DAC_TRIGGER_TIM2_TRGO															5
#define			DAC_TRIGGER_TIM4_TRGO															6
#define			DAC_TRIGGER_EXT_LINE9															7
#define			DAC_TRIGGER_SW_TRIGGER															8

/*@ref DAC_DMA*/
/*DAC DMA options section.*/
#define			DAC_DMA_DISABLE																	0
#define			DAC_DMA_ENABLE																	1


/*
==================================================
  End   Section --> DAC Configurations available options
==================================================
 */




/*
==================================================
  Start Section --> DAC Configurations
==================================================
 */

typedef struct DAC_Cfg{
	/*This parameter can be the value of DAC instance for example
	 * If you want to configure DAC1, This parameter will take the value 1*/
	u8 GPIOInstanceId;
	/*This parameter can be the value of DAC instance for example
	 * If you want to configure DAC1, This parameter will take the value 1*/
	u8 InstanceId;
	/*This parameter take a value of @ref DAC_Channel*/
	u8 Channel;
	/*This parameter take a value of @ref DAC_Buffer*/
	u8 Buffer;
	/*This parameter take a value of @ref DAC_DMA*/
	u8 DMA;
	/*This parameter take a value of @ref DAC_Wave_Generation*/
	u8 WaveGeneration;
	/*This parameter take a value of @ref DAC_Max_Amplitude*/
	u8 AmplitudeDivideBy;
	/*This parameter take a value of @ref DAC_Trigger*/
	u8 Trigger;
	/*This parameter can be the value of assigned pins for DAC instance
	 * using the following pattern
	 * PIN_x_MASK | PIN_y_MASK | PIN_z_MASK
	 * where x, y, and z are the values of selected pins
	 * for example if you want to configure Pin A0, A3, A10
	 * This parameter will take
	 * PIN_0_MASK | PIN_3_MASK | PIN_10_MASK
	 * */
	u16 GPIOPins;
}DAC_Cfg;

/*
==================================================
  End   Section --> DAC Configurations
==================================================
 */


/*
==================================================
  Start Section --> APIs
==================================================
 */

/* @brief  --> This function configures DAC based on configuration passed through DAC_Cfg struct.
 * @param  Arg_conf_cpcDAC_Cfg --> struct that have configured parameters.
 * @retval --> None.
 * */
void DAC_Config_v(DAC_Cfg const * const Arg_conf_cpcDAC_Cfg);

/* @brief  --> Enable DAC.
 * @param  Arg_conf_cpcDAC_Cfg --> struct that have configured parameters.
 * @retval --> None.
 * */
void DAC_EnableDAC_v(DAC_Cfg const * const Arg_conf_cpcDAC_Cfg);

/* @brief  --> Disable DAC.
 * @param  Arg_conf_cpcDAC_Cfg --> struct that have configured parameters.
 * @retval --> None.
 * */
void DAC_DisableDAC_v(DAC_Cfg const * const Arg_conf_cpcDAC_Cfg);

/* @brief  --> Output analog value.
 * @param  Arg_conf_cpcDAC_Cfg --> struct that have configured parameters.
 * @param  Arg_OutputValue_u16 --> value of analog value.
 * @retval --> None.
 * */
void DAC_SetOutputValue_v(DAC_Cfg const * const Arg_conf_cpcDAC_Cfg, u16 Arg_OutputValue_u16);

/* @brief  --> Trigger DAC by software.
 * @param  Arg_conf_cpcDAC_Cfg --> struct that have configured parameters.
 * @retval --> None.
 * */
void DAC_SoftwareTrigger_v(DAC_Cfg const * const Arg_conf_cpcDAC_Cfg);

/* @brief  --> Usually used with DMA to get the address of selected DAC.
 * @param  Arg_conf_cpcDAC_Cfg --> struct that have configured parameters.
 * @retval --> Address of selected DAC.
 * */
u32 DAC_GetAddressForDMA_u32(DAC_Cfg const * const Arg_conf_cpcDAC_Cfg);
/*
==================================================
  End   Section --> APIs
==================================================
 */
#endif /* HMCAL_DAC_DAC_H_ */
