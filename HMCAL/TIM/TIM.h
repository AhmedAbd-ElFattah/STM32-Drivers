/*
 * File Name --> DMA.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> Provides API and available configuration options for DMA peripheral.
 * */

#ifndef HMCAL_TIM_TIM_H_
#define HMCAL_TIM_TIM_H_

/*
==================================================
  Start Section --> File Includes
==================================================
 */
#include <HMCAL/TIM/TIM_defs.h>
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
  Start Section --> Macro Declaration
==================================================
 */

/*
==================================================
  Start Section --> TIM Configurations available options
==================================================
*/

/*@ref TIM_Preload*/
/*Autoreload Preload available options section.*/
#define 		TIM_PRELOAD_NOT_BUFFERED                                                            0
#define 		TIM_PRELOAD_BUFFERED                                                                1

/*@ref TIM_One_Pulse_Mode*/
/* One oulse mode available options section. */
#define 		TIM_ONE_PULSE_DISABLE                                                               0
#define 		TIM_ONE_PULSE_ENABLE                                                                1


/*@ref TIM_Master*/
/*Master Mode available options section.*/
#define 		TIM_MASTER_MODE_DISABLE                                                             0
#define 		TIM_MASTER_MODE_RESET                                                               1
#define 		TIM_MASTER_MODE_ENABLE                                                              2
#define 		TIM_MASTER_MODE_UPDATE                                                              3

/*@ref TIM_Interrupt*/
/*Interrupt available options section.*/
#define 		TIM_INTERRUPT_DISABLE                                                               0
#define 		TIM_INTERRUPT_UPDATE                                                                (1<<1)

/*@ref TIM_DMA*/
/*DMA Request available options section.*/
#define 		TIM_DMA_REQUEST_DISABLE                                                             0
#define 		TIM_DMA_REQUEST_UPDATE                                                              1



/*@ref TIM_Channel_Mode*/
/* TIM Channel Modes available options section. */
/*
 * Lower byte represents mode
 * Higher byte represents channel number
 * */
#define TIM_CHANNEL_MODE_OUTPUT_FROZEN					(0<<4)
#define TIM_CHANNEL_MODE_OUTPUT_COMPARE_TOGGLE			(3<<4)
#define TIM_CHANNEL_MODE_OUTPUT_PWM_ACTIVE_HIGH			(6<<4)
#define TIM_CHANNEL_MODE_OUTPUT_PWM_ACTIVE_LOW			(7<<4)

/*@ref TIM_Active_Channel*/
#define TIM_CHANNEL_1_MASK								(1<<0)
#define TIM_CHANNEL_2_MASK								(1<<1)
#define TIM_CHANNEL_3_MASK								(1<<2)
#define TIM_CHANNEL_4_MASK								(1<<3)

#define TIM_CHANNEL_1_NEGATIVE_MASK						(1<<(0+4))
#define TIM_CHANNEL_2_NEGATIVE_MASK						(1<<(1+4))
#define TIM_CHANNEL_3_NEGATIVE_MASK						(1<<(2+4))
#define TIM_CHANNEL_4_NEGATIVE_MASK						(1<<(3+4))


#define TIM_ACTIVE_CHANNELS_CH1_OUT						(1<<0)
#define TIM_ACTIVE_CHANNELS_CH2_OUT						(1<<1)
#define TIM_ACTIVE_CHANNELS_CH3_OUT						(1<<2)
#define TIM_ACTIVE_CHANNELS_CH4_OUT						(1<<3)

/*
==================================================
  End   Section --> DMA Configurations available options
==================================================
*/



/*
==================================================
  Start Section --> Data Type Declaration
==================================================
 */


typedef struct  TIM_Cfg{
	/*This parameter can be the value of TIM instance for example
	* If you want to configure TIM1, This parameter will take the value 1*/
	u8 InstanceId;
	u8 GPIOInstanceId;
	u16 GPIOPins;
	/*This parameter take a value of @ref TIM_Preload*/
	u8 Preload;
	/*This parameter take a value of @ref TIM_One_Pulse_Mode*/
	u8 OnePulseMode;
	/*This parameter take a value of @ref TIM_DMA*/
	u8 DMARequests;
	/*This parameter take a value of @ref TIM_Master*/
	u8 MasterMode;
	/*This parameter take a value of @ref TIM_Active_Channel
	 * for e.g to active channel 1 & 2 you need to assign the following
	 * TIM_CHANNEL_1_MASK | TIM_CHANNEL_2_MASK
	 * */
	u8 ActiveChannels;

	/*This parameter take a value of @ref TIM_Channel_Mode*/
	u16 Channel1Mode;
	u16 Channel2Mode;
	u16 Channel3Mode;
	u16 Channel4Mode;

	u16 Channel1CaptureCompare;
	u16 Channel2CaptureCompare;
	u16 Channel3CaptureCompare;
	u16 Channel4CaptureCompare;

	u16 Prescaler;
	u16 AutoReloadValue;
	/*This parameter take a value of @ref TIM_Interrupt*/
	u32 Interrupt;
} TIM_Cfg;
/*
==================================================
  End Section --> TIM Configurations.
==================================================
*/


/*
==================================================
  Start Section --> APIs
==================================================
 */

/* @brief  --> This function configures TIM based on configuration passed through TIM_Cfg struct.
 * @param  Arg_conf_cpcTIM_Cfg --> struct that have configured parameters.
 * @retval --> None.
 * */
void TIM_Config_v(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg);

/* @brief  --> Assign new auto reload value to timer.
 * @param  Arg_conf_cpcTIM_Cfg --> struct that have configured parameters.
 * @param  Arg_Value_u16 --> Value of new Auto reload value that you need to assign with timer.
 * @retval --> None.
 * */
void TIM_SetAutoReloadValue_v(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg, u16 Arg_Value_u16);

/* @brief  --> Get assigned auto reload value of timer.
 * @param  Arg_conf_cpcTIM_Cfg --> struct that have configured parameters.
 * @retval --> Value of auto reload value of timer.
 * */
u16 TIM_GetAutoReloadValue_u16(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg);

/* @brief  --> Assign new prescaler value to timer.
 * @param  Arg_conf_cpcTIM_Cfg --> struct that have configured parameters.
 * @param  Arg_Value_u16 --> Value of new prescaler value that you need to assign with timer.
 * @retval --> None.
 * */
void TIM_SetPrescalerValue_v(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg, u16 Arg_Value_u16);

/* @brief  --> Get assigned prescaler value of timer.
 * @param  Arg_conf_cpcTIM_Cfg --> struct that have configured parameters.
 * @retval --> Value of prescaler value of timer.
 * */
u16 TIM_GetPrescalerValue_u16(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg);

/* @brief  --> Assign new counter value to timer.
 * @param  Arg_conf_cpcTIM_Cfg --> struct that have configured parameters.
 * @param  Arg_Value_u16 --> Value of new counter value that you need to assign with timer.
 * @retval --> None.
 * */
void TIM_SetCounterValue_v(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg, u16 Arg_Value_u16);

/* @brief  --> Get assigned current counter value of timer.
 * @param  Arg_conf_cpcTIM_Cfg --> struct that have configured parameters.
 * @retval --> Value of counter value of timer.
 * */
u16 TIM_GetCounterValue_u16(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg);

/* @brief  --> Reset counter value of timer.
 * @param  Arg_conf_cpcTIM_Cfg --> struct that have configured parameters.
 * @retval --> None.
 * */
void TIM_ResetCounter_v(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg);

/* @brief  --> Start timer.
 * @param  Arg_conf_cpcTIM_Cfg --> struct that have configured parameters.
 * @retval --> None.
 * */
void TIM_StartTimer_v(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg);

/* @brief  --> Stop timer.
 * @param  Arg_conf_cpcTIM_Cfg --> struct that have configured parameters.
 * @retval --> None.
 * */
void TIM_StopTimer_v(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg);

void TIM_SetOutputCompare1Value_v(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg, u16 Arg_Value_u16);
u16 TIM_GetOutputCompare1Value_u16(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg);

void TIM_SetOutputCompare2Value_v(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg, u16 Arg_Value_u16);
u16 TIM_GetOutputCompare2Value_u16(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg);

void TIM_SetOutputCompare3Value_v(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg, u16 Arg_Value_u16);
u16 TIM_GetOutputCompare3Value_u16(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg);

void TIM_SetOutputCompare4Value_v(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg, u16 Arg_Value_u16);
u16 TIM_GetOutputCompare4Value_u16(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg);
/*
==================================================
  End   Section --> APIs
==================================================
 */
#endif /* HMCAL_TIM_TIM_H_ */
