/*
 * File Name --> RCC.c
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> RCC driver implementation.
 * */


/*
==================================================
  Start Section --> File Includes
==================================================
 */
#include "RCC.h"
#include "RCC_defs.h"
#include "RCC_Private.h"
#include "LIB/BIT_MATH.h"

#include "STM32_Drivers_Configurations/Driver_WaitState.h"
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

void RCC_InitClock_v(void){
	/*
	 * "L_PLLCFGVal_u32" stores the value of RCC_PLLCFG register.
	 * "L_CFGRVal_u32" 	 stores the value of RCC_CFGR register.
	 * "L_CRVal_u32" 	 stores the value of RCC_CR register.
	 * After configurations these variable will store values that match configured parameters,then
	 * registers 's values will be assigned based on these variables.
	 * */
	u32 L_PLLCFGVal_u32 = 0;
	u32 L_CFGRVal_u32 = 0;
	u32 L_CRVal_u32 = RCC->CR;
	/* Set PLL M, N, Q */
	L_PLLCFGVal_u32 |= CLOCK_PLL_M | (CLOCK_PLL_N<<6) | (CLOCK_PLL_Q<<24);
	/* Set PLL P. */
#if CLOCK_PLL_P==2
	CLEAR_BIT(L_PLLCFGVal_u32, RCC_PLLCFGR_PLLP_0);
	CLEAR_BIT(L_PLLCFGVal_u32, RCC_PLLCFGR_PLLP_1);
#elif CLOCK_PLL_P==4
	SET_BIT(L_PLLCFGVal_u32, RCC_PLLCFGR_PLLP_0);
	CLEAR_BIT(L_PLLCFGVal_u32, RCC_PLLCFGR_PLLP_1);
#elif CLOCK_PLL_P==6
	CLEAR_BIT(L_PLLCFGVal_u32, RCC_PLLCFGR_PLLP_0);
	SET_BIT(L_PLLCFGVal_u32, RCC_PLLCFGR_PLLP_1);
#elif CLOCK_PLL_P==8
	SET_BIT(L_PLLCFGVal_u32, RCC_PLLCFGR_PLLP_0);
	SET_BIT(L_PLLCFGVal_u32, RCC_PLLCFGR_PLLP_1);
#endif

	/*Select PLL Clock source, whether it's HSI or HSE*/
#if CLOCK_PLL_SOURCE_MUX == CLOCK_PLL_SOURCE_HSI
	CLEAR_BIT(L_PLLCFGVal_u32, RCC_PLLCFGR_PLLSRC);
#elif CLOCK_PLL_SOURCE_MUX == CLOCK_PLL_SOURCE_HSE
	SET_BIT(L_PLLCFGVal_u32, RCC_PLLCFGR_PLLSRC);
#endif

	/*Set APB2 prescaler*/
#if CLOCK_APB2_PRESCALER == 1
	CLEAR_BIT(L_CFGRVal_u32, RCC_CFGR_PPRE2_0);
	CLEAR_BIT(L_CFGRVal_u32, RCC_CFGR_PPRE2_1);
	CLEAR_BIT(L_CFGRVal_u32, RCC_CFGR_PPRE2_2);

#elif  CLOCK_APB2_PRESCALER == 2
	CLEAR_BIT(L_CFGRVal_u32, RCC_CFGR_PPRE2_0);
	CLEAR_BIT(L_CFGRVal_u32, RCC_CFGR_PPRE2_1);
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_PPRE2_2);

#elif  CLOCK_APB2_PRESCALER == 4
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_PPRE2_0);
	CLEAR_BIT(L_CFGRVal_u32, RCC_CFGR_PPRE2_1);
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_PPRE2_2);

#elif  CLOCK_APB2_PRESCALER == 8
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_PPRE2_1);
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_PPRE2_2);
	CLEAR_BIT(L_CFGRVal_u32, RCC_CFGR_PPRE2_0);
#elif  CLOCK_APB2_PRESCALER == 16
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_PPRE2_0);
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_PPRE2_1);
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_PPRE2_2);
#endif

	/*Set APB1 prescaler*/
#if CLOCK_APB1_PRESCALER == 1
	CLEAR_BIT(L_CFGRVal_u32, RCC_CFGR_PPRE1_0);
	CLEAR_BIT(L_CFGRVal_u32, RCC_CFGR_PPRE1_1);
	CLEAR_BIT(L_CFGRVal_u32, RCC_CFGR_PPRE1_2);
#elif  CLOCK_APB1_PRESCALER == 2
	CLEAR_BIT(L_CFGRVal_u32, RCC_CFGR_PPRE1_0);
	CLEAR_BIT(L_CFGRVal_u32, RCC_CFGR_PPRE1_1);
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_PPRE1_2);
#elif  CLOCK_APB1_PRESCALER == 4
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_PPRE1_0);
	CLEAR_BIT(L_CFGRVal_u32, RCC_CFGR_PPRE1_1);
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_PPRE1_2);
#elif  CLOCK_APB1_PRESCALER == 8
	CLEAR_BIT(L_CFGRVal_u32, RCC_CFGR_PPRE1_0);
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_PPRE1_1);
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_PPRE1_2);
#elif  CLOCK_APB1_PRESCALER == 16
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_PPRE1_0);
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_PPRE1_1);
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_PPRE1_2);
#endif

	/*Set AHB prescaler*/
#if CLOCK_AHB_PRESCALER == 1
	CLEAR_BIT(L_CFGRVal_u32, RCC_CFGR_HPRE_0);
	CLEAR_BIT(L_CFGRVal_u32, RCC_CFGR_HPRE_1);
	CLEAR_BIT(L_CFGRVal_u32, RCC_CFGR_HPRE_2);
	CLEAR_BIT(L_CFGRVal_u32, RCC_CFGR_HPRE_3);

#elif	CLOCK_AHB_PRESCALER == 2
	CLEAR_BIT(L_CFGRVal_u32, RCC_CFGR_HPRE_0);
	CLEAR_BIT(L_CFGRVal_u32, RCC_CFGR_HPRE_1);
	CLEAR_BIT(L_CFGRVal_u32, RCC_CFGR_HPRE_2);
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_HPRE_3);

#elif	CLOCK_AHB_PRESCALER == 4
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_HPRE_0);
	CLEAR_BIT(L_CFGRVal_u32, RCC_CFGR_HPRE_1);
	CLEAR_BIT(L_CFGRVal_u32, RCC_CFGR_HPRE_2);
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_HPRE_3);

#elif	CLOCK_AHB_PRESCALER == 8
	CLEAR_BIT(L_CFGRVal_u32, RCC_CFGR_HPRE_0);
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_HPRE_1);
	CLEAR_BIT(L_CFGRVal_u32, RCC_CFGR_HPRE_2);
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_HPRE_3);

#elif	CLOCK_AHB_PRESCALER == 16
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_HPRE_0);
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_HPRE_1);
	CLEAR_BIT(L_CFGRVal_u32, RCC_CFGR_HPRE_2);
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_HPRE_3);

#elif	CLOCK_AHB_PRESCALER == 64
	CLEAR_BIT(L_CFGRVal_u32, RCC_CFGR_HPRE_0);
	CLEAR_BIT(L_CFGRVal_u32, RCC_CFGR_HPRE_1);
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_HPRE_2);
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_HPRE_3);

#elif	CLOCK_AHB_PRESCALER == 128
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_HPRE_0);
	CLEAR_BIT(L_CFGRVal_u32, RCC_CFGR_HPRE_1);
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_HPRE_2);
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_HPRE_3);

#elif	CLOCK_AHB_PRESCALER == 256
	CLEAR_BIT(L_CFGRVal_u32, RCC_CFGR_HPRE_0);
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_HPRE_1);
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_HPRE_2);
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_HPRE_3);

#elif	CLOCK_AHB_PRESCALER == 512
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_HPRE_0);
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_HPRE_1);
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_HPRE_2);
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_HPRE_3);
#endif

	/*Select System Clock source, whether it's HSI, HSE, or PLL*/

#if CLOCK_SYSTEM_CLOCK_MUX == CLOCK_SYSTEM_CLOCK_MUX_HSI
	CLEAR_BIT(L_CFGRVal_u32, RCC_CFGR_SWS_0);
	CLEAR_BIT(L_CFGRVal_u32, RCC_CFGR_SWS_1);

#elif CLOCK_SYSTEM_CLOCK_MUX == CLOCK_SYSTEM_CLOCK_MUX_HSE
	/*Enable HSE */
	SET_BIT(L_CRVal_u32, RCC_CR_HSEON);
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_SW_0);
	CLEAR_BIT(L_CFGRVal_u32, RCC_CFGR_SW_1);


#elif CLOCK_SYSTEM_CLOCK_MUX == CLOCK_SYSTEM_CLOCK_MUX_PLLCLK
	/* Select PLL Clock Source*/
#if CLOCK_PLL_SOURCE_MUX == CLOCK_PLL_SOURCE_HSI
	CLEAR_BIT(L_PLLCFGVal_u32, RCC_PLLCFGR_PLLSRC);
#elif CLOCK_PLL_SOURCE_MUX == CLOCK_PLL_SOURCE_HSE
	SET_BIT(L_CRVal_u32, RCC_CR_HSEON);
	SET_BIT(L_PLLCFGVal_u32, RCC_PLLCFGR_PLLSRC);
#endif
	CLEAR_BIT(L_CFGRVal_u32, RCC_CFGR_SW_0);
	SET_BIT(L_CFGRVal_u32, RCC_CFGR_SW_1);
	/* Enable PLL */
	SET_BIT(L_CRVal_u32, RCC_CR_PLLON);
#endif
	/*Assigne register values (RCC_PLLCFGR, RCC_CR, or RCC_CFGR) to be as assigned configurations.*/


	RCC->PLLCFGR = L_PLLCFGVal_u32;
	RCC->CR = L_CRVal_u32;
	RCC->CFGR = L_CFGRVal_u32;

	/*configure Wait Latency*/

	/*Calculate operating frequency.*/
#define OPERATING_FREQUENCY ((CLOCK_SYSCLK_MHz/CLOCK_AHB_PRESCALER))

	/*Define voltage region.*/

#if  ((DRIVER_OPERATING_VOLTAGE_IN_MS >DRIVER_VOLTAGE_RANGE_0_IN_MS_FROM) && (DRIVER_OPERATING_VOLTAGE_IN_MS <=DRIVER_VOLTAGE_RANGE_0_IN_MS_TO))
#define RCC_VOLTAGE_REGION	0

#elif ((DRIVER_OPERATING_VOLTAGE_IN_MS >DRIVER_VOLTAGE_RANGE_1_IN_MS_FROM) && (DRIVER_OPERATING_VOLTAGE_IN_MS <=DRIVER_VOLTAGE_RANGE_1_IN_MS_TO))
#define RCC_VOLTAGE_REGION	1

#elif ((DRIVER_OPERATING_VOLTAGE_IN_MS >DRIVER_VOLTAGE_RANGE_2_IN_MS_FROM) && (DRIVER_OPERATING_VOLTAGE_IN_MS <=DRIVER_VOLTAGE_RANGE_2_IN_MS_TO))
#define RCC_VOLTAGE_REGION	2

#elif ((DRIVER_OPERATING_VOLTAGE_IN_MS >DRIVER_VOLTAGE_RANGE_3_IN_MS_FROM) && (DRIVER_OPERATING_VOLTAGE_IN_MS <=DRIVER_VOLTAGE_RANGE_3_IN_MS_TO))
#define RCC_VOLTAGE_REGION	3

#else
#error "Please make sure that you specified voltage configuration correctly !"
#endif


#ifndef RCC_VOLTAGE_REGION
#error "RCC_VOLTAGE_REGION is not defined !"
#endif

#if RCC_VOLTAGE_REGION==0

#define 	WAIT_STATE_0_FROM_FREQ	DRIVER_WAIT_STATE_0_V0_FROM
#define 	WAIT_STATE_0_TO_FREQ	  DRIVER_WAIT_STATE_0_V0_TO

#define 	WAIT_STATE_1_FROM_FREQ	DRIVER_WAIT_STATE_1_V0_FROM
#define 	WAIT_STATE_1_TO_FREQ	  DRIVER_WAIT_STATE_1_V0_TO

#define 	WAIT_STATE_2_FROM_FREQ	DRIVER_WAIT_STATE_2_V0_FROM
#define 	WAIT_STATE_2_TO_FREQ	  DRIVER_WAIT_STATE_2_V0_TO

#define 	WAIT_STATE_3_FROM_FREQ	DRIVER_WAIT_STATE_3_V0_FROM
#define 	WAIT_STATE_3_TO_FREQ	  DRIVER_WAIT_STATE_3_V0_TO

#define 	WAIT_STATE_4_FROM_FREQ	DRIVER_WAIT_STATE_4_V0_FROM
#define 	WAIT_STATE_4_TO_FREQ	  DRIVER_WAIT_STATE_4_V0_TO

#define 	WAIT_STATE_5_FROM_FREQ	DRIVER_WAIT_STATE_5_V0_FROM
#define 	WAIT_STATE_5_TO_FREQ	  DRIVER_WAIT_STATE_5_V0_TO

#elif RCC_VOLTAGE_REGION==1

#define 	WAIT_STATE_0_FROM_FREQ	DRIVER_WAIT_STATE_0_V1_FROM
#define 	WAIT_STATE_0_TO_FREQ	  DRIVER_WAIT_STATE_0_V1_TO

#define 	WAIT_STATE_1_FROM_FREQ	DRIVER_WAIT_STATE_1_V1_FROM
#define 	WAIT_STATE_1_TO_FREQ	  DRIVER_WAIT_STATE_1_V1_TO

#define 	WAIT_STATE_2_FROM_FREQ	DRIVER_WAIT_STATE_2_V1_FROM
#define 	WAIT_STATE_2_TO_FREQ	  DRIVER_WAIT_STATE_2_V1_TO

#define 	WAIT_STATE_3_FROM_FREQ	DRIVER_WAIT_STATE_3_V1_FROM
#define 	WAIT_STATE_3_TO_FREQ	  DRIVER_WAIT_STATE_3_V1_TO

#define 	WAIT_STATE_4_FROM_FREQ	DRIVER_WAIT_STATE_4_V1_FROM
#define 	WAIT_STATE_4_TO_FREQ	  DRIVER_WAIT_STATE_4_V1_TO

#define 	WAIT_STATE_5_FROM_FREQ	DRIVER_WAIT_STATE_5_V1_FROM
#define 	WAIT_STATE_5_TO_FREQ	  DRIVER_WAIT_STATE_5_V1_TO

#define 	WAIT_STATE_6_FROM_FREQ	DRIVER_WAIT_STATE_6_V1_FROM
#define 	WAIT_STATE_6_TO_FREQ	  DRIVER_WAIT_STATE_6_V1_TO

#define 	WAIT_STATE_7_FROM_FREQ	DRIVER_WAIT_STATE_7_V1_FROM
#define 	WAIT_STATE_7_TO_FREQ	  DRIVER_WAIT_STATE_7_V1_TO

#elif RCC_VOLTAGE_REGION==2

#define 	WAIT_STATE_0_FROM_FREQ	DRIVER_WAIT_STATE_0_V2_FROM
#define 	WAIT_STATE_0_TO_FREQ	  DRIVER_WAIT_STATE_0_V2_TO

#define 	WAIT_STATE_1_FROM_FREQ	DRIVER_WAIT_STATE_1_V2_FROM
#define 	WAIT_STATE_1_TO_FREQ	  DRIVER_WAIT_STATE_1_V2_TO

#define 	WAIT_STATE_2_FROM_FREQ	DRIVER_WAIT_STATE_2_V2_FROM
#define 	WAIT_STATE_2_TO_FREQ	  DRIVER_WAIT_STATE_2_V2_TO

#define 	WAIT_STATE_3_FROM_FREQ	DRIVER_WAIT_STATE_3_V2_FROM
#define 	WAIT_STATE_3_TO_FREQ	  DRIVER_WAIT_STATE_3_V2_TO

#define 	WAIT_STATE_4_FROM_FREQ	DRIVER_WAIT_STATE_4_V2_FROM
#define 	WAIT_STATE_4_TO_FREQ	  DRIVER_WAIT_STATE_4_V2_TO

#define 	WAIT_STATE_5_FROM_FREQ	DRIVER_WAIT_STATE_5_V2_FROM
#define 	WAIT_STATE_5_TO_FREQ	  DRIVER_WAIT_STATE_5_V2_TO

#define 	WAIT_STATE_6_FROM_FREQ	DRIVER_WAIT_STATE_6_V2_FROM
#define 	WAIT_STATE_6_TO_FREQ	  DRIVER_WAIT_STATE_6_V2_TO

#define 	WAIT_STATE_7_FROM_FREQ	DRIVER_WAIT_STATE_7_V2_FROM
#define 	WAIT_STATE_7_TO_FREQ	  DRIVER_WAIT_STATE_7_V2_TO

#define 	WAIT_STATE_8_FROM_FREQ	DRIVER_WAIT_STATE_8_V2_FROM
#define 	WAIT_STATE_8_TO_FREQ	  DRIVER_WAIT_STATE_8_V2_TO

#elif RCC_VOLTAGE_REGION==3

#define 	WAIT_STATE_0_FROM_FREQ	DRIVER_WAIT_STATE_0_V3_FROM
#define 	WAIT_STATE_0_TO_FREQ	  DRIVER_WAIT_STATE_0_V3_TO

#define 	WAIT_STATE_1_FROM_FREQ	DRIVER_WAIT_STATE_1_V3_FROM
#define 	WAIT_STATE_1_TO_FREQ	  DRIVER_WAIT_STATE_1_V3_TO

#define 	WAIT_STATE_2_FROM_FREQ	DRIVER_WAIT_STATE_2_V3_FROM
#define 	WAIT_STATE_2_TO_FREQ	  DRIVER_WAIT_STATE_2_V3_TO

#define 	WAIT_STATE_3_FROM_FREQ	DRIVER_WAIT_STATE_3_V3_FROM
#define 	WAIT_STATE_3_TO_FREQ	  DRIVER_WAIT_STATE_3_V3_TO

#define 	WAIT_STATE_4_FROM_FREQ	DRIVER_WAIT_STATE_4_V3_FROM
#define 	WAIT_STATE_4_TO_FREQ	  DRIVER_WAIT_STATE_4_V3_TO

#define 	WAIT_STATE_5_FROM_FREQ	DRIVER_WAIT_STATE_5_V3_FROM
#define 	WAIT_STATE_5_TO_FREQ	  DRIVER_WAIT_STATE_5_V3_TO

#define 	WAIT_STATE_6_FROM_FREQ	DRIVER_WAIT_STATE_6_V3_FROM
#define 	WAIT_STATE_6_TO_FREQ	  DRIVER_WAIT_STATE_6_V3_TO

#define 	WAIT_STATE_7_FROM_FREQ	DRIVER_WAIT_STATE_7_V3_FROM
#define 	WAIT_STATE_7_TO_FREQ	  DRIVER_WAIT_STATE_7_V3_TO

#define 	WAIT_STATE_8_FROM_FREQ	DRIVER_WAIT_STATE_8_V3_FROM
#define 	WAIT_STATE_8_TO_FREQ	  DRIVER_WAIT_STATE_8_V3_TO

#else
#error "Undefined voltage region !"
#endif

#if ((OPERATING_FREQUENCY>WAIT_STATE_0_FROM_FREQ) && (OPERATING_FREQUENCY<=WAIT_STATE_0_TO_FREQ))
	*(volatile u32 *)(DRIVER_WAIT_STATE_ADDRESS_REGISTER) |= 0;
#elif ((OPERATING_FREQUENCY>WAIT_STATE_1_FROM_FREQ) && (OPERATING_FREQUENCY<=WAIT_STATE_1_TO_FREQ))
	*(volatile u32 *)(DRIVER_WAIT_STATE_ADDRESS_REGISTER) |= 1;
#elif ((OPERATING_FREQUENCY>WAIT_STATE_2_FROM_FREQ) && (OPERATING_FREQUENCY<=WAIT_STATE_2_TO_FREQ))
	*(volatile u32 *)(DRIVER_WAIT_STATE_ADDRESS_REGISTER) |= 2;
#elif ((OPERATING_FREQUENCY>WAIT_STATE_3_FROM_FREQ) && (OPERATING_FREQUENCY<=WAIT_STATE_3_TO_FREQ))
	*(volatile u32 *)(DRIVER_WAIT_STATE_ADDRESS_REGISTER) |= 3;
#elif ((OPERATING_FREQUENCY>WAIT_STATE_4_FROM_FREQ) && (OPERATING_FREQUENCY<=WAIT_STATE_4_TO_FREQ))
	*(volatile u32 *)(DRIVER_WAIT_STATE_ADDRESS_REGISTER) |= 4;
#elif ((OPERATING_FREQUENCY>WAIT_STATE_5_FROM_FREQ) && (OPERATING_FREQUENCY<=WAIT_STATE_5_TO_FREQ))
	*(volatile u32 *)(DRIVER_WAIT_STATE_ADDRESS_REGISTER) |= 5;
#elif ((OPERATING_FREQUENCY>WAIT_STATE_6_FROM_FREQ) && (OPERATING_FREQUENCY<=WAIT_STATE_6_TO_FREQ))
	*(volatile u32 *)(DRIVER_WAIT_STATE_ADDRESS_REGISTER) |= 6;
#elif ((OPERATING_FREQUENCY>WAIT_STATE_7_FROM_FREQ) && (OPERATING_FREQUENCY<=WAIT_STATE_7_TO_FREQ))
	*(volatile u32 *)(DRIVER_WAIT_STATE_ADDRESS_REGISTER) |= 7;
#elif ((OPERATING_FREQUENCY>WAIT_STATE_8_FROM_FREQ) && (OPERATING_FREQUENCY<=WAIT_STATE_8_TO_FREQ))
	*(volatile u32 *)(DRIVER_WAIT_STATE_ADDRESS_REGISTER) |= 8;
#endif

}


void RCC_EnableClock_v(const u8 Arg_PeripheralBus_Cu8,const u8 Arg_Peripheral_Cu8){
	/*Enable clock of peripheral,
	 * Arg_Peripheral_Cu8 is the location of peripheral's bit on
	 * peripheral bus.*/
	switch (Arg_PeripheralBus_Cu8) {
	case RCC_AHB1:
		SET_BIT(RCC->AHB1ENR, Arg_Peripheral_Cu8);
		/*Wait till clock become stable & enabled.*/
		while(STD_FALSE == GET_BIT(RCC->AHB1ENR, Arg_Peripheral_Cu8)){

		}
		break;
	case RCC_AHB2:
		SET_BIT(RCC->AHB2ENR, Arg_Peripheral_Cu8);
		/*Wait till clock become stable & enabled.*/
		while(STD_FALSE == GET_BIT(RCC->AHB2ENR, Arg_Peripheral_Cu8)){

		}
		break;
	case RCC_AHB3:
		SET_BIT(RCC->AHB3ENR, Arg_Peripheral_Cu8);
		/*Wait till clock become stable & enabled.*/
		while(STD_FALSE == GET_BIT(RCC->AHB3ENR, Arg_Peripheral_Cu8)){

		}
		break;
	case RCC_APB1:
		SET_BIT(RCC->APB1ENR, Arg_Peripheral_Cu8);
		/*Wait till clock become stable & enabled.*/
		while(STD_FALSE == GET_BIT(RCC->APB1ENR, Arg_Peripheral_Cu8)){

		}
		break;
	case RCC_APB2:
		SET_BIT(RCC->APB2ENR, Arg_Peripheral_Cu8);
		/*Wait till clock become stable & enabled.*/
		while(STD_FALSE == GET_BIT(RCC->APB2ENR, Arg_Peripheral_Cu8)){

		}
		break;
	default:
		/*Error*/
		break;
	}
}


void RCC_DisableClock_v(const u8 Arg_PeripheralBus_Cu8,const u8 Arg_Peripheral_Cu8){
	/*Disable clock of peripheral,
	 * Arg_Peripheral_Cu8 is the location of peripheral's bit on
	 * peripheral bus.*/
	switch (Arg_PeripheralBus_Cu8) {
	case RCC_AHB1:
		SET_BIT(RCC->AHB1RSTR, Arg_Peripheral_Cu8);
		/*Wait till clock become disabled.*/
		while(STD_TRUE == GET_BIT(RCC->AHB1ENR, Arg_Peripheral_Cu8)){

		}
		break;
	case RCC_AHB2:
		SET_BIT(RCC->AHB2RSTR, Arg_Peripheral_Cu8);
		/*Wait till clock become disabled.*/
		while(STD_TRUE == GET_BIT(RCC->AHB2ENR, Arg_Peripheral_Cu8)){

		}
		break;
	case RCC_AHB3:
		SET_BIT(RCC->AHB3RSTR, Arg_Peripheral_Cu8);
		/*Wait till clock become disabled.*/
		while(STD_TRUE == GET_BIT(RCC->AHB3ENR, Arg_Peripheral_Cu8)){

		}
		break;
	case RCC_APB1:
		SET_BIT(RCC->APB1RSTR, Arg_Peripheral_Cu8);
		/*Wait till clock become disabled.*/
		while(STD_TRUE == GET_BIT(RCC->APB1ENR, Arg_Peripheral_Cu8)){

		}
		break;
	case RCC_APB2:
		SET_BIT(RCC->APB2RSTR, Arg_Peripheral_Cu8);
		/*Wait till clock become disabled.*/
		while(STD_TRUE == GET_BIT(RCC->APB2ENR, Arg_Peripheral_Cu8)){

		}
		break;
	default:
		/*Error*/
		break;
	}
}



f32 RCC_GetSystemClockFrequency_f32(void){
	return (f32)CLOCK_SYSCLK_MHz;
}


f32 RCC_GetHCLKFrequency_f32(void){
	return (((f32)CLOCK_SYSCLK_MHz)/CLOCK_AHB_PRESCALER);
}


f32 RCC_GetCortexSystemTimerFrequency_f32(void){
	return (f32)(CLOCK_SYSCLK_MHz / (CLOCK_AHB_PRESCALER*CLOCK_PRESCALLER_TO_CORTEX_SYSTEM_TIMER));
}

f32 RCC_GetFCLKFrequency_f32(void){
	return (((f32)CLOCK_SYSCLK_MHz)/CLOCK_AHB_PRESCALER);
}

f32 RCC_GetAPB1PeripheralClockFrequency_f32(void){
	return (((f32)CLOCK_SYSCLK_MHz)/(CLOCK_APB1_PRESCALER*CLOCK_AHB_PRESCALER));
}


f32 RCC_GetAPB1TimerClockFrequency_f32(void){
	/*When APB1 prescaler equals 1, timer frequency is multiplied by 2*/
#if (CLOCK_APB1_PRESCALER>1)
	return (((f32)CLOCK_SYSCLK_MHz*2.0)/(CLOCK_APB1_PRESCALER*CLOCK_AHB_PRESCALER));
#else
	return (((f32)CLOCK_SYSCLK_MHz)/(CLOCK_APB1_PRESCALER*CLOCK_AHB_PRESCALER));
#endif
}


f32 RCC_GetAPB2PeripheralClockFrequency_f32(void){
	return ((f32)(CLOCK_SYSCLK_MHz)/(CLOCK_APB2_PRESCALER*CLOCK_AHB_PRESCALER));
}


f32 RCC_GetAPB2TimerClockFrequency_f32(void){
	/*When APB2 prescaler equals 1, timer frequency is multiplied by 2*/
#if (CLOCK_APB2_PRESCALER>1)
	return ((f32)CLOCK_SYSCLK_MHz*2.0)/(CLOCK_APB2_PRESCALER*CLOCK_AHB_PRESCALER);
#else
	return ((f32)CLOCK_SYSCLK_MHz)/(CLOCK_APB2_PRESCALER*CLOCK_AHB_PRESCALER);
#endif
}

u8 RCC_GetPeripheralBus_u8(const u32 Arg_PeripheralAddress_Cu32){
	u8 L_PeripheralBus_u8 = -1;
	if ((Arg_PeripheralAddress_Cu32 >= RCC_AHB3_BUS_FROM_ADDRESS)&&(Arg_PeripheralAddress_Cu32<=RCC_AHB3_BUS_TO_ADDRESS) ){
		L_PeripheralBus_u8 = RCC_AHB3;
	}
	if ((Arg_PeripheralAddress_Cu32 >= RCC_AHB2_BUS_FROM_ADDRESS)&&(Arg_PeripheralAddress_Cu32<=RCC_AHB2_BUS_TO_ADDRESS) ){
		L_PeripheralBus_u8 = RCC_AHB2;
	}
	if ((Arg_PeripheralAddress_Cu32 >= RCC_AHB1_BUS_FROM_ADDRESS)&&(Arg_PeripheralAddress_Cu32<=RCC_AHB1_BUS_TO_ADDRESS) ){
		L_PeripheralBus_u8 = RCC_AHB1;
	}
	if ((Arg_PeripheralAddress_Cu32 >= RCC_APB2_BUS_FROM_ADDRESS)&&(Arg_PeripheralAddress_Cu32<=RCC_APB2_BUS_TO_ADDRESS) ){
		L_PeripheralBus_u8 = RCC_APB2;
	}
	if ((Arg_PeripheralAddress_Cu32 >= RCC_APB1_BUS_FROM_ADDRESS)&&(Arg_PeripheralAddress_Cu32<=RCC_APB1_BUS_TO_ADDRESS) ){
		L_PeripheralBus_u8 = RCC_APB1;
	}

	return L_PeripheralBus_u8;
}


f32 RCC_GetPeripheralFrequencyInMHz_f32(const u32 Arg_PeripheralAddress_Cu32){
	f32 L_PeripheralFreq_f32 = -1;
	if ((Arg_PeripheralAddress_Cu32 >= RCC_AHB3_BUS_FROM_ADDRESS)&&(Arg_PeripheralAddress_Cu32<=RCC_AHB3_BUS_TO_ADDRESS) ){
		/*Not Supported in this version.*/
		L_PeripheralFreq_f32 = 0;
	}
	if ((Arg_PeripheralAddress_Cu32 >= RCC_AHB2_BUS_FROM_ADDRESS)&&(Arg_PeripheralAddress_Cu32<=RCC_AHB2_BUS_TO_ADDRESS) ){
		L_PeripheralFreq_f32 = RCC_GetHCLKFrequency_f32();
	}
	if ((Arg_PeripheralAddress_Cu32 >= RCC_AHB1_BUS_FROM_ADDRESS)&&(Arg_PeripheralAddress_Cu32<=RCC_AHB1_BUS_TO_ADDRESS) ){
		L_PeripheralFreq_f32 = RCC_GetHCLKFrequency_f32();
	}
	if ((Arg_PeripheralAddress_Cu32 >= RCC_APB2_BUS_FROM_ADDRESS)&&(Arg_PeripheralAddress_Cu32<=RCC_APB2_BUS_TO_ADDRESS) ){
		L_PeripheralFreq_f32 = RCC_GetAPB2PeripheralClockFrequency_f32();
	}
	if ((Arg_PeripheralAddress_Cu32 >= RCC_APB1_BUS_FROM_ADDRESS)&&(Arg_PeripheralAddress_Cu32<=RCC_APB1_BUS_TO_ADDRESS) ){
		L_PeripheralFreq_f32 = RCC_GetAPB1PeripheralClockFrequency_f32();
	}

	return L_PeripheralFreq_f32;
}


f32 RCC_GetTimerPeripheralFrequencyInMHz_f32(const u32 Arg_PeripheralAddress_Cu32){
	f32 L_TimClk_f32 = -1;
	if ((Arg_PeripheralAddress_Cu32 >= RCC_APB2_BUS_FROM_ADDRESS)&&(Arg_PeripheralAddress_Cu32<=RCC_APB2_BUS_TO_ADDRESS) ){
		L_TimClk_f32 = RCC_GetAPB2TimerClockFrequency_f32();
	}
	if ((Arg_PeripheralAddress_Cu32 >= RCC_APB1_BUS_FROM_ADDRESS)&&(Arg_PeripheralAddress_Cu32<=RCC_APB1_BUS_TO_ADDRESS) ){
		L_TimClk_f32 = RCC_GetAPB1TimerClockFrequency_f32();
	}
	/*Error*/
	return L_TimClk_f32;
}



u8 RCC_GetRCCTimerBit_u8(const u8 Arg_TimerInstanceId_Cu8){
	/*Map each timer instance id with corresponding bit position in register.
	 * where instance id is the index of array -1*/
	const u8 L_TimerBit_Cu8[] = {
			RCC_TIM1, // TIM1
			RCC_TIM2, // TIM2
			RCC_TIM3, // TIM3
			RCC_TIM4, // TIM4
			RCC_TIM5, // TIM5
			RCC_TIM6, // TIM6
			RCC_TIM7, // TIM7
			RCC_TIM8, // TIM8
			RCC_TIM9, // TIM9
			RCC_TIM10, // TIM10
			RCC_TIM11, // TIM11
			RCC_TIM12, // TIM12
			RCC_TIM13, // TIM13
			RCC_TIM14, // TIM14
	};
	return L_TimerBit_Cu8[Arg_TimerInstanceId_Cu8-1];
}


u8 RCC_GetRCCGPIOBit_u8(const u8 Arg_GPIOInstanceId_Cu8){
	/*Map each GPIO instance id with corresponding bit position in register.
	 * where instance id is the index of array-1 */
	const u8 L_GPIOBit_Cu8[] = {
			RCC_GPIOA, // GPIOA
			RCC_GPIOB, // GPIOB
			RCC_GPIOC, // GPIOC
			RCC_GPIOD, // GPIOD
			RCC_GPIOE, // GPIOE
			RCC_GPIOF, // GPIOF
			RCC_GPIOG, // GPIOG
			RCC_GPIOH, // GPIOH

	};
	return L_GPIOBit_Cu8[Arg_GPIOInstanceId_Cu8-1];
}


u8 RCC_GetRCCUSARTBit_u8(const u8 Arg_USARTInstanceId_Cu8){
	/*Map each USART instance id with corresponding bit position in register.
	 * where instance id is the index of array-1 */
	const u8 L_USARTBit_Cu8[] = {
			RCC_USART1,
			RCC_USART2,
			RCC_USART3,
			RCC_UART4,
			RCC_UART5,
			RCC_USART6,
	};

	return L_USARTBit_Cu8[Arg_USARTInstanceId_Cu8 - 1];
}


u8 RCC_GetRCCCANBit_u8(const u8 Arg_CANInstanceId_Cu8){
	/*Map each CAN instance id with corresponding bit position in register.
	 * where instance id is the index of array-1 */
	const u8 L_CANBit_Cu8[] = {
			RCC_CAN1,
			RCC_CAN2,
	};

	return L_CANBit_Cu8[Arg_CANInstanceId_Cu8 - 1];
}



u8 RCC_GetRCCI2CBit_u8(const u8 Arg_I2CInstanceId_Cu8){
	/*Map each I2C instance id with corresponding bit position in register.
	 * where instance id is the index of array-1 */
	const u8 L_I2CBit_Cu8[] = {
			RCC_I2C1,
			RCC_I2C2,
			RCC_I2C3,
	};

	return L_I2CBit_Cu8[Arg_I2CInstanceId_Cu8 - 1];
}


u8 RCC_GetRCCDACBit_u8(const u8 Arg_DACInstanceId_Cu8){
	/*Map each DAC instance id with corresponding bit position in register.
	 * where instance id is the index of array-1 */

	const u8 L_DACBit_Cu8[] = {
			RCC_DAC,
	};

	return L_DACBit_Cu8[Arg_DACInstanceId_Cu8 - 1];
}


u8 RCC_GetRCCDMABit_u8(const u8 Arg_DMAInstanceId_Cu8){
	/*Map each DMA instance id with corresponding bit position in register.
	 * where instance id is the index of array-1 */
	const u8 L_DMABit_Cu8[] = {
			RCC_DMA1,
			RCC_DMA2,
	};
	return L_DMABit_Cu8[Arg_DMAInstanceId_Cu8 - 1];
}

u8 RCC_GetRCCADCBit_u8(const u8 Arg_ADCInstanceId_Cu8){
	/*Map each ADC instance id with corresponding bit position in register.
	 * where instance id is the index of array-1 */
	const u8 L_ADCBit_Cu8[] = {
			RCC_ADC1,
			RCC_ADC2,
			RCC_ADC3,

	};
	return L_ADCBit_Cu8[Arg_ADCInstanceId_Cu8 - 1];
}


u8 RCC_GetRCCSYSCFGBit_u8(const u8 Arg_SYSCFGInstanceId_Cu8){
	/*Map each SYSCFG instance id with corresponding bit position in register.
	 * where instance id is the index of array-1 */
	const u8 L_SYSCFGBit_Cu8[] = {
			RCC_SYSCFG,
	};
	return L_SYSCFGBit_Cu8[Arg_SYSCFGInstanceId_Cu8 - 1];
}

u8 RCC_GetRCCSPIBit_u8(const u8 Arg_SPIInstanceId_u8){
	/*Map each SPI instance id with corresponding bit position in register.
	 * where instance id is the index of array-1 */
	const u8 L_SPIBit_Cu8[] = {
			RCC_SPI1,
			RCC_SPI2,
			RCC_SPI3,
			RCC_SPI4,
	};
	return L_SPIBit_Cu8[Arg_SPIInstanceId_u8 - 1];
}

/*
==================================================
  End   Section --> Functions implementation.
==================================================
 */
