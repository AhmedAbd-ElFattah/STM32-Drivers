/*
 * File Name --> EXTI.c
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> EXTI driver implementation.
 * */

/*
==================================================
  Start Section --> File Includes
==================================================
 */
#include "HMCAL/RCC/RCC.h"
#include "EXTI_Private.h"
#include "EXTI_defs.h"
#include "EXTI.h"
#include "HMCAL/SYSCFG/SYSCFG.h"
#include "HMCAL/GPIO/GPIO.h"
/*
==================================================
  End   Section --> File Includes
==================================================
 */


/*
==================================================
  Start Section --> Functions implementation.
==================================================
 */

/* @brief  --> This function configures EXTI based on configuration passed through EXTI_Cfg struct.
 * @param  Arg_conf_cpcDMA_Cfg --> struct that have configured parameters.
 * @retval --> None.
 * */
void EXTI_Config_v(EXTI_Cfg const * const Arg_conf_cpcEXTI_Cfg){

	GPIO_Cfg L_EXTIGPIO_GPIO_Cfg;
	L_EXTIGPIO_GPIO_Cfg.InstanceId = Arg_conf_cpcEXTI_Cfg->GPIOInstanceId;
	L_EXTIGPIO_GPIO_Cfg.Mode = GPIO_MODE_INPUT;
	L_EXTIGPIO_GPIO_Cfg.OutputSpeed = GPIO_OUTPUT_SPEED_LOW;
	L_EXTIGPIO_GPIO_Cfg.OutputType = GPIO_OUTPUT_TYPE_PUSH_PULL;
	L_EXTIGPIO_GPIO_Cfg.PINs = Arg_conf_cpcEXTI_Cfg->PINs;
	L_EXTIGPIO_GPIO_Cfg.PullUpPullDownResistor = GPIO_RESISTOR_PULL_DOWN;

	GPIO_Config_v(&L_EXTIGPIO_GPIO_Cfg);

	u32 L_Pins_u32 = Arg_conf_cpcEXTI_Cfg->PINs;

	u8 L_GPIOid_u8 = Arg_conf_cpcEXTI_Cfg->GPIOInstanceId;
	/*
	 * GPIOA will have index 0 in L_GPIOid_u8 array
	 * So the following process check for the boundary of input value
	 * If input id exceeds the boundary an error will be issued.
	 * */
	if (('A' <= L_GPIOid_u8 ) && (L_GPIOid_u8 <= 'Z')){
		L_GPIOid_u8 -= 'A';
	}
	else if (('a' <= L_GPIOid_u8 ) && (L_GPIOid_u8 <= 'z')){
		L_GPIOid_u8 -= 'a';
	}
	else{
		/*Error*/

	}


	u8 L_EXTIPinMapping_u8[] = {
							NVIC_EXTI0, 	// Pin 0
							NVIC_EXTI1, 	// Pin 1
							NVIC_EXTI2, 	// Pin 2
							NVIC_EXTI3, 	// Pin 3
							NVIC_EXTI4, 	// Pin 4
							NVIC_EXTI9_5,	// Pin 5
							NVIC_EXTI9_5,	// Pin 6
							NVIC_EXTI9_5,	// Pin 7
							NVIC_EXTI9_5,	// Pin 8
							NVIC_EXTI9_5,	// Pin 9
							NVIC_EXTI15_10, // Pin 10
							NVIC_EXTI15_10, // Pin 11
							NVIC_EXTI15_10, // Pin 12
							NVIC_EXTI15_10, // Pin 13
							NVIC_EXTI15_10, // Pin 14
							NVIC_EXTI15_10, // Pin 15
	};

	for (u8 L_i_u8 = 0; L_i_u8<32 ;L_i_u8++){

		if (STD_TRUE != GET_BIT(L_Pins_u32, L_i_u8)){
			continue;
		}

		if (EXTI_EDGE_NO_EDGE_DETECTION != Arg_conf_cpcEXTI_Cfg->Edge){
			SET_BIT(EXTI->IMR, L_i_u8);
			SYSCFG_EXTIConfig_v(L_GPIOid_u8, L_i_u8);
			/*Enable In NVIC*/
			NVIC_EnableInterrupt_v(L_EXTIPinMapping_u8[L_i_u8]);
		}
		else{

		}


		switch(Arg_conf_cpcEXTI_Cfg->Edge){
		case EXTI_EDGE_NO_EDGE_DETECTION:
			CLEAR_BIT(EXTI->RTSR, L_i_u8);
			CLEAR_BIT(EXTI->FTSR, L_i_u8);
			break;

		case EXTI_EDGE_RISING_EDGE_DETECTION:
			SET_BIT(EXTI->RTSR, L_i_u8);
			CLEAR_BIT(EXTI->FTSR, L_i_u8);
			break;

		case EXTI_EDGE_FALLING_EDGE_DETECTION:
			SET_BIT(EXTI->FTSR, L_i_u8);
			CLEAR_BIT(EXTI->RTSR, L_i_u8);
			break;

		case EXTI_EDGE_BOTH_EDGES_DETECTION:
			break;

		default:
			break;


		}
	}
}


/* @brief  --> This function usually used by interrupt handler to check for
    the existence of interrupt for specific pin number.
 * @param  Arg_PinNumber_u8 --> Pin number that you need to check whether it's source of interrupt or not.
 * @retval --> Bool value represents whether there is an interrupt or not.
 * */

Bool EXTI_CheckInterrupt_Bool(u8 Arg_PinNumber_u8){
	if (STD_TRUE == GET_BIT(EXTI->PR, Arg_PinNumber_u8)){
		return STD_TRUE;
	}
	else{

		return STD_FALSE;
	}
}

/* @brief  --> This function usually used by interrupt handler to check for
    the existence of interrupt for specific pin number and clear pending flag if it's exist.
 * @param  Arg_PinNumber_u8 --> Pin number that you need to clear pending flag.
 * @retval --> None.
 * */
void EXTI_ClearInterrupt_v(u8 Arg_PinNumber_u8){
	if (STD_TRUE == GET_BIT(EXTI->PR, Arg_PinNumber_u8)){
		SET_BIT(EXTI->PR, Arg_PinNumber_u8);
		return;
	}
	else{
		return;
	}
}

/*
==================================================
  End Section --> Functions implementation.
==================================================
 */
