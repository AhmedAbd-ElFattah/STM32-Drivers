/*
 * File Name --> ADC.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> Provides API and available configuration options for ADC peripheral.
 * */

#ifndef HMCAL_ADC_ADC_H_
#define HMCAL_ADC_ADC_H_


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
  Start Section --> ADC Configurations available options
==================================================
*/

/*@ref ADC_External_Trigger*/
#define 		ADC_EXT_TRIG_DETECT_DISABLED			0
#define 		ADC_EXT_TRIG_DETECT_RISING_EDGE			1
#define 		ADC_EXT_TRIG_DETECT_FALLING_EDGE		2
#define 		ADC_EXT_TRIG_DETECT_BOTH_EDGES			3

/*@ref ADC_DMA*/
#define			ADC_DMA_DISABLE							0
#define			ADC_DMA_ENABLE							1

/*@ref ADC_Resolution*/
#define 		ADC_RES_12_BIT                          0
#define 		ADC_RES_10_BIT                          1
#define 		ADC_RES_8_BIT                           2
#define 		ADC_RES_6_BIT                           3

/*@ref ADC_Continuous_Scan*/
#define 		ADC_CONT_SCAN_DISABLE	                0
#define 		ADC_CONT_SCAN_ENABLE	                1

/*@ref ADC_Regular_Event_Trigger*/
#define   		ADC_REG_EVENT_TRIG_TIM1_CC1   			0
#define     	ADC_REG_EVENT_TRIG_TIM1_CC2   			1
#define     	ADC_REG_EVENT_TRIG_TIM1_CC3   			2
#define   		ADC_REG_EVENT_TRIG_TIM2_CC2   			3
#define   		ADC_REG_EVENT_TRIG_TIM2_CC3   			4
#define   		ADC_REG_EVENT_TRIG_TIM2_CC4   			5
#define   		ADC_REG_EVENT_TRIG_TIM2_TRGO   			6
#define   		ADC_REG_EVENT_TRIG_TIM3_CC1   			7
#define   		ADC_REG_EVENT_TRIG_TIM3_TRGO   			8
#define   		ADC_REG_EVENT_TRIG_TIM4_CC4   			9
#define   		ADC_REG_EVENT_TRIG_TIM5_CC1   			10
#define   		ADC_REG_EVENT_TRIG_TIM5_CC2   			11
#define   		ADC_REG_EVENT_TRIG_TIM5_CC3   			12
#define   		ADC_REG_EVENT_TRIG_TIM8_CC1   			13
#define   		ADC_REG_EVENT_TRIG_TIM8_TRGO   			14
#define   		ADC_REG_EVENT_TRIG_EXTI_LINE11   		15

/*@ref ADC_Sample_Time*/
#define			ADC_SAMPLE_TIME_3_CYCLES		0
#define			ADC_SAMPLE_TIME_15_CYCLES		1
#define			ADC_SAMPLE_TIME_28_CYCLES		2
#define			ADC_SAMPLE_TIME_56_CYCLES		3
#define			ADC_SAMPLE_TIME_84_CYCLES		4
#define			ADC_SAMPLE_TIME_112_CYCLES		5
#define			ADC_SAMPLE_TIME_144_CYCLES		6
#define			ADC_SAMPLE_TIME_480_CYCLES		7

/*@ref ADC_Conversion_Mode*/
#define			ADC_CONV_MODE_SINGLE			0
#define			ADC_CONV_MODE_CONTINUOUS		1

/*@ref ADC_Channel*/
/*ADC1 Channels*/
#define ADC1_A0 						(0x410000)
#define ADC1_A1 						(0x410101)
#define ADC1_A2 						(0x410202)
#define ADC1_A3 						(0x410303)
#define ADC1_A4 						(0x410404)
#define ADC1_A5 						(0x410505)
#define ADC1_A6 						(0x410606)
#define ADC1_A7 						(0x410707)

#define ADC1_B0 						(0x420008)
#define ADC1_B1 						(0x420109)

#define ADC1_C0 						(0x43000a)
#define ADC1_C1 						(0x43010b)
#define ADC1_C2 						(0x43020c)
#define ADC1_C3 						(0x43030d)
#define ADC1_C4 						(0x43040e)
#define ADC1_C5 						(0x43050f)

#define ADC1_EXT_TRIG_INJECTED_CONV_C15 (0x430f10)
#define ADC1_EXT_TRIG_REGULAR_CONV_E11  (0x450b11)
/*ADC2 Channels*/
#define ADC2_A0 						(0x410000)
#define ADC2_A1 						(0x410101)
#define ADC2_A2 						(0x410202)
#define ADC2_A3 						(0x410303)
#define ADC2_A4 						(0x410404)
#define ADC2_A5 						(0x410505)
#define ADC2_A6 						(0x410606)
#define ADC2_A7 						(0x410707)

#define ADC2_B0 						(0x420008)
#define ADC2_B1 						(0x420109)

#define ADC2_C0 						(0x43000a)
#define ADC2_C1 						(0x43010b)
#define ADC2_C2 						(0x43020c)
#define ADC2_C3 						(0x43030d)
#define ADC2_C4 						(0x43040e)
#define ADC2_C5 						(0x43050f)

#define ADC2_EXT_TRIG_INJECTED_CONV_C15 (0x430f10)
#define ADC2_EXT_TRIG_REGULAR_CONV_E11  (0x450b11)

/*ADC3 Channels*/
#define ADC3_A0 						(0x410000)
#define ADC3_A1 						(0x410101)
#define ADC3_A2 						(0x410202)
#define ADC3_A3 						(0x410303)

#define ADC3_C0 						(0x43000a)
#define ADC3_C1 						(0x43010b)
#define ADC3_C2 						(0x43020c)
#define ADC3_C3 						(0x43030d)


#define ADC3_EXT_TRIG_INJECTED_CONV_C15 (0x430f10)
#define ADC3_EXT_TRIG_REGULAR_CONV_E11  (0x450b11)

/*
==================================================
  End Section --> ADC Configurations available options
==================================================
*/

/*
==================================================
  Start Section --> ADC Configurations.
==================================================
*/
typedef struct ADC_Cfg{
	/*This parameter can be the value of ADC instance for example
	 * If you want to configure ADC1, This parameter will take the value 1*/
	u8 InstanceId;
	/*This parameter take a value of @ref ADC_Continuous_Scan*/
	u8 ContinuousScanEn;
	/*This parameter take a value of @ref ADC_DMA*/
	u8 DMA;
	/*This parameter take a value of @ref ADC_Resolution*/
	u8 Resolution;
	/*This parameter take a value of @ref ADC_Sample_Time*/
	u8 SampleTime;
	/*This parameter take a value of @ref ADC_Regular_Event_Trigger*/
	u8 RegularEventTrigger;
	/*This parameter take a value of @ref ADC_Conversion_Mode*/
	u8 ConversionMode;
	/*This parameter take a value of @ref ADC_External_Trigger*/
	u8 ExternalTriggerDetection;
	/* ConversionChannels --> pointer of array which contains sequence of pins that you need to convert it's analog values.
	 * ConversionLength	  --> sequence length || Array length.
	 * For e.g if you need to convert some pins using ADC1 based on the following sequence pins A0, A2, A7
	 * u32 Sequence[] = {ADC1_A0, ADC1_A2, ADC1_A7};
	 * elements of all has the following pattern
	 * ADCx_y
	 * where x is instance id of ADC & y is pin
	 * All available combination of pins & adc instance id @ref ADC_Channel.
	 * */
	u8 ConversionLength;
	u32 *ConversionChannels;
}ADC_Cfg;
/*
==================================================
  End Section --> ADC Configurations.
==================================================
*/
/*
==================================================
  End   Section --> Data Type Declaration
==================================================
*/


/*
==================================================
  Start Section --> APIs
==================================================
*/

/* @brief  --> This function configures ADC based on configuration passed through ADC_Cfg struct.
 * @param  Arg_conf_cpcADC_Cfg --> struct that have configured parameters.
 * @retval --> None.
 * */
void ADC_Config_v(ADC_Cfg const * const Arg_conf_cpcADC_Cfg);

/* @brief  --> Start Software Conversion.
 * @param  Arg_conf_cpcADC_Cfg --> struct that have configured parameters.
 * @retval --> None.
 * */
void ADC_StartSoftwareConversion_v(ADC_Cfg const * const Arg_conf_cpcADC_Cfg);

/* @brief  --> Stop Software Conversion.
 * @param  Arg_conf_cpcADC_Cfg --> struct that have configured parameters.
 * @retval --> None.
 * */
void ADC_StopSoftwareConversion_v(ADC_Cfg const * const Arg_conf_cpcADC_Cfg);

/* @brief  --> Enable ADC.
 * @param  Arg_conf_cpcADC_Cfg --> struct that have configured parameters.
 * @retval --> None.
 * */
void ADC_EnableADC_v(ADC_Cfg const * const Arg_conf_cpcADC_Cfg);

/* @brief  --> Disable ADC.
 * @param  Arg_conf_cpcADC_Cfg --> struct that have configured parameters.
 * @retval --> None.
 * */
void ADC_DisableADC_v(ADC_Cfg const * const Arg_conf_cpcADC_Cfg);

/* @brief  --> Get measured value.
 * @param  Arg_conf_cpcADC_Cfg --> struct that have configured parameters.
 * @retval --> Measured value.
 * */
u16 ADC_GetReading_u16(ADC_Cfg const * const Arg_conf_cpcADC_Cfg);

/* @brief  --> Usually used with DMA to get the address of selected ADC.
 * @param  Arg_conf_cpcADC_Cfg --> struct that have configured parameters.
 * @retval --> Address of selected ADC.
 * */
u32 ADC_GetAdressForDMA_u32(ADC_Cfg const * const Arg_conf_cpcADC_Cfg);
/*
==================================================
  End   Section --> APIs
==================================================
*/
#endif /* HMCAL_ADC_ADC_H_ */
