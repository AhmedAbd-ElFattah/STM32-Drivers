/*
 * File Name --> RCC_Private.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> RCC driver private info like addresses.
 * */

#ifndef HMCAL_RCC_RCC_PRIVATE_H_
#define HMCAL_RCC_RCC_PRIVATE_H_

/*
==================================================
  Start Section --> File Includes
==================================================
 */
#include "LIB/STD_TYPES.h"
#include "STM32_Drivers_Configurations/Driver_ClockConfig.h"
/*
==================================================
  End   Section --> File Includes
==================================================
 */

/*
==================================================
  Start Section --> Define peripheral addresses.
==================================================
 */
#define RCC_BASE_ADDRESS	0x40023800
/*
==================================================
  End   Section --> Define peripheral addresses.
==================================================
 */

/*
==================================================
  Start Section --> Reset values.
==================================================
 */

#define RCC_CR_RESET_VALUE							0x00000083
#define RCC_PLLCFGR_RESET_VALUE						0x24003010
#define RCC_CFGR_RESET_VALUE						0x00000000
#define RCC_CIR_RESET_VALUE							0x00000000
#define RCC_AHB1RSTR_RESET_VALUE					0x00000000
#define RCC_AHB2RSTR_RESET_VALUE					0x00000000
#define RCC_AHB3RSTR_RESET_VALUE					0x00000000
#define RCC_APB1RSTR_RESET_VALUE					0x00000000
#define RCC_APB2RSTR_RESET_VALUE					0x00000000
#define RCC_AHB1ENR_RESET_VALUE						0x00000000
#define RCC_AHB2ENR_RESET_VALUE						0x00000000
#define RCC_AHB3ENR_RESET_VALUE						0x00000000
#define RCC_APB1ENR_RESET_VALUE						0x00000000
#define RCC_APB2ENR_RESET_VALUE						0x00000000
#define RCC_AHB1LPENR_RESET_VALUE					0x606790FF
#define RCC_AHB2LPENR_RESET_VALUE					0x00000081
#define RCC_AHB3LPENR_RESET_VALUE					0x00000003
#define RCC_APB1LPENR_RESET_VALUE					0x3FFFC9FF
#define RCC_APB2LPENR_RESET_VALUE					0x00C77F33
#define RCC_BDCR_RESET_VALUE						0x00000000
#define RCC_CSR_RESET_VALUE							0x00000074
#define RCC_SSCGR_RESET_VALUE						0x00000000
#define RCC_PLLI2SCFGR_RESET_VALUE					0x24003010
#define RCC_PLLSAICFGR_RESET_VALUE					0x04003010
#define RCC_DCKCFGR_RESET_VALUE						0x00000000
#define RCC_CKGATENR_RESET_VALUE					0x00000000
#define RCC_DCKCFGR2_RESET_VALUE					0x00000000
/*
==================================================
  End Section --> Reset values.
==================================================
 */

/*
==================================================
  Start Section --> RCC Bus range addresses.
==================================================
 */
/*Bus address Ranges.*/
#define RCC_AHB3_BUS_FROM_ADDRESS	0xA0000000
#define RCC_AHB3_BUS_TO_ADDRESS		0xA0000FFF

#define RCC_AHB2_BUS_FROM_ADDRESS	0x50000000
#define RCC_AHB2_BUS_TO_ADDRESS		0x50060BFF

#define RCC_AHB1_BUS_FROM_ADDRESS	0x40020000
#define RCC_AHB1_BUS_TO_ADDRESS		0x4007FFFF


#define RCC_APB2_BUS_FROM_ADDRESS	0x40010000
#define RCC_APB2_BUS_TO_ADDRESS		0x40016BFF

#define RCC_APB1_BUS_FROM_ADDRESS	0x40000000
#define RCC_APB1_BUS_TO_ADDRESS		0x40007FFF

/*
==================================================
  End Section --> RCC Bus range addresses.
==================================================
 */



/*
==================================================
  Start Section --> Peripheral register mapping.
==================================================
 */
typedef struct {
	/*RCC clock control register (RCC_CR)*/
	volatile u32 CR;
	/*RCC PLL configuration register (RCC_PLLCFGR)*/
	volatile u32 PLLCFGR;
	/*RCC clock configuration register (RCC_CFGR)*/
	volatile u32 CFGR;
	/*RCC clock interrupt register (RCC_CIR)*/
	volatile u32 CIR;
	/*RCC AHB1 peripheral reset register (RCC_AHB1RSTR)*/
	volatile u32 AHB1RSTR;
	/*RCC AHB2 peripheral reset register (RCC_AHB2RSTR)*/
	volatile u32 AHB2RSTR;
	/*RCC AHB3 peripheral reset register (RCC_AHB3RSTR)*/
	volatile u32 AHB3RSTR;
	volatile u32 RESERVED0;
	/*RCC APB1 peripheral reset register (RCC_APB1RSTR)*/
	volatile u32 APB1RSTR;
	/*RCC APB2 peripheral reset register (RCC_APB2RSTR)*/
	volatile u32 APB2RSTR;
	volatile u32 RESERVED1;
	volatile u32 RESERVED2;
	/*RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)*/
	volatile u32 AHB1ENR;
	/*RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)*/
	volatile u32 AHB2ENR;
	/*RCC AHB3 peripheral clock enable register (RCC_AHB3ENR)*/
	volatile u32 AHB3ENR;
	volatile u32 RESERVED3;
	/*RCC APB1 peripheral clock enable register (RCC_APB1ENR)*/
	volatile u32 APB1ENR;
	/*RCC APB2 peripheral clock enable register (RCC_APB2ENR)*/
	volatile u32 APB2ENR;
	volatile u32 RESERVED4;
	volatile u32 RESERVED5;
	/*RCC AHB1 peripheral clock enable in low power mode register (RCC_AHB1LPENR)*/
	volatile u32 AHB1LPENR;
	/*RCC AHB2 peripheral clock enable in low power mode register (RCC_AHB2LPENR)*/
	volatile u32 AHB2LPENR;
	/*RCC AHB3 peripheral clock enable in low power mode register (RCC_AHB3LPENR)*/
	volatile u32 AHB3LPENR;
	volatile u32 RESERVED6;
	/*RCC APB1 peripheral clock enable in low power mode register (RCC_APB1LPENR)*/
	volatile u32 APB1LPENR;
	/*RCC APB2 peripheral clock enabled in low power mode register (RCC_APB2LPENR)*/
	volatile u32 APB2LPENR;
	volatile u32 RESERVED7;
	volatile u32 RESERVED8;
	/*RCC Backup domain control register (RCC_BDCR)*/
	volatile u32 BDCR;
	/*RCC clock control & status register (RCC_CSR)*/
	volatile u32 CSR;
	volatile u32 RESERVED9;
	volatile u32 RESERVED10;
	/*RCC spread spectrum clock generation register (RCC_SSCGR)*/
	volatile u32 SSCGR;
	/*RCC PLLI2S configuration register (RCC_PLLI2SCFGR)*/
	volatile u32 PLLI2SCFGR;
	/*RCC PLL configuration register (RCC_PLLSAICFGR)*/
	volatile u32 PLLSAICFGR;
	/*RCC dedicated clock configuration register (RCC_DCKCFGR)*/
	volatile u32 DCKCFGR;
	/*RCC clocks gated enable register (CKGATENR)*/
	volatile u32 CKGATENR;
	/*RCC dedicated clocks configuration register 2 (DCKCFGR2)*/
	volatile u32 DCKCFGR2;
}RCC_MemMap;
/*
==================================================
  End   Section --> Peripheral register mapping.
==================================================
 */

/*
==================================================
  Start Section --> Define peripheral with it's address.
==================================================
 */
#define 		RCC		((volatile RCC_MemMap* const)(RCC_BASE_ADDRESS))
/*
==================================================
  End Section --> Define peripheral with it's address.
==================================================
 */
/*
==================================================
  Start Section --> RCC Bus & Peripherals on bus Id definitions
==================================================
*/




/*
==================================================
  Start Section --> System Clock Definitions
==================================================
*/
/*Input clock system options Definitions.*/
#define	CLOCK_SYSTEM_CLOCK_MUX_HSI			0
#define	CLOCK_SYSTEM_CLOCK_MUX_HSE			1
#define	CLOCK_SYSTEM_CLOCK_MUX_PLLCLK		2

/*Input phase locked loop options Definitions.*/
#define	CLOCK_PLL_SOURCE_HSI				0
#define	CLOCK_PLL_SOURCE_HSE				1
/*
==================================================
  End Section --> System Clock Definitions
==================================================
*/


/*
==================================================
  Start Section --> CLock calculations.
==================================================
*/
/*PLL output calculations for P-Line & Q-Line and setting input clock source for PLL.*/
#if	(CLOCK_PLL_SOURCE_MUX == CLOCK_PLL_SOURCE_HSI)
#define				CLOCK_MAIN_PLL_OUT_Q		((CLOCK_HSI_RC*CLOCK_PLL_N)/(CLOCK_PLL_M*CLOCK_PLL_Q))
#define				CLOCK_MAIN_PLL_CLK			((CLOCK_HSI_RC*CLOCK_PLL_N)/(CLOCK_PLL_M*CLOCK_PLL_P))
#elif (CLOCK_PLL_SOURCE_MUX == CLOCK_PLL_SOURCE_HSE)
#define				CLOCK_MAIN_PLL_OUT_Q		((CLOCK_HSE_RC*CLOCK_PLL_N)/(CLOCK_PLL_M*CLOCK_PLL_Q))
#define				CLOCK_MAIN_PLL_CLK			((CLOCK_HSE_RC*CLOCK_PLL_N)/(CLOCK_PLL_M*CLOCK_PLL_P))
#else
#error CLOCK_PLL_SOURCE_MUX : Avilable Options are CLOCK_PLL_SOURCE_HSI & CLOCK_PLL_SOURCE_HSE
#endif

/*Select the input clock source for system whether it's HSI, HSE, and PLL.*/
#if CLOCK_SYSTEM_CLOCK_MUX == CLOCK_SYSTEM_CLOCK_MUX_HSI
#define CLOCK_SYSCLK_MHz  CLOCK_HSI_RC
#elif CLOCK_SYSTEM_CLOCK_MUX == CLOCK_SYSTEM_CLOCK_MUX_HSE
#define CLOCK_SYSCLK_MHz  CLOCK_HSE_RC
#elif CLOCK_SYSTEM_CLOCK_MUX == CLOCK_SYSTEM_CLOCK_MUX_PLLCLK
#define CLOCK_SYSCLK_MHz  CLOCK_MAIN_PLL_CLK
#else
#error CLOCK_SYSTEM_CLOCK_MUX : Avilable Options are CLOCK_SYSTEM_CLOCK_MUX_HSI & CLOCK_SYSTEM_CLOCK_MUX_HSE & CLOCK_SYSTEM_CLOCK_MUX_PLLCLK
#endif

/*Calculate each bus's frequency.*/
#define				CLOCK_HCLK_MHz													(CLOCK_SYSCLK_MHz/CLOCK_AHB_PRESCALER)

#define				CLOCK_ETHERNET_PTP_CLOCK										CLOCK_SYSCLK_MHz

#define				CLOCK_HCLK_TO_AHB_BUS_CORE_MEMORY_DMA							CLOCK_HCLK_MHz

#define				CLOCK_TO_CORTEX_SYSTEM_TIMER									CLOCK_HCLK_MHz/CLOCK_PRESCALLER_TO_CORTEX_SYSTEM_TIMER

#define				CLOCK_FCLK_CORTEX_CLOCK											CLOCK_HCLK_MHz

#define				CLOCK_APB1_PERIPHERAL_CLOCKS									(CLOCK_HCLK_MHz/CLOCK_APB1_PRESCALER)
#if (CLOCK_APB1_PRESCALER>1)
#define				CLOCK_APB1_TIMER_CLOCKS											((2.0*CLOCK_HCLK_MHz)/CLOCK_APB1_PRESCALER)
#else
#define				CLOCK_APB1_TIMER_CLOCKS											(CLOCK_HCLK_MHz/CLOCK_APB1_PRESCALER)
#endif

#define				CLOCK_APB2_PERIPHERAL_CLOCKS									(CLOCK_HCLK_MHz/CLOCK_APB2_PRESCALER)
#if (CLOCK_APB2_PRESCALER>1)
#define				CLOCK_APB2_TIMER_CLOCKS											((2.0*CLOCK_HCLK_MHz)/CLOCK_APB2_PRESCALER)
#else
#define				CLOCK_APB2_TIMER_CLOCKS											(CLOCK_HCLK_MHz/CLOCK_APB2_PRESCALER)
#endif

#define				CLOCK_48_MHz_CLOCKS												CLOCK_MAIN_PLL_OUT_Q
/*
==================================================
  End Section --> CLock calculations.
==================================================
*/

/*
==================================================
  Start Section --> Guard from wrong input values from user.
==================================================
*/

#if (CLOCK_PLL_M < 2) | (CLOCK_PLL_M > 52)
#error CLOCK_PLL_M : Avilable Range From 2 To 63 only
#endif

#if (CLOCK_PLL_N < 50) | (CLOCK_PLL_N > 432)
#error CLOCK_PLL_N : Avilable Range From 50 To 432 only
#endif

#if !((CLOCK_PLL_P == 2) | (CLOCK_PLL_P == 4) | (CLOCK_PLL_P == 6) | (CLOCK_PLL_P == 8))
#error CLOCK_PLL_P : Avilable Options are even only From 2 To 8
#endif

#if (CLOCK_PLL_Q < 2) | (CLOCK_PLL_Q > 15)
#error CLOCK_PLL_Q : Avilable Range From 50 To 432 only
#endif


#if !(	CLOCK_AHB_PRESCALER==1 | CLOCK_AHB_PRESCALER==2 | CLOCK_AHB_PRESCALER==4 |\
		CLOCK_AHB_PRESCALER==8 | CLOCK_AHB_PRESCALER==16 | CLOCK_AHB_PRESCALER==64| \
		CLOCK_AHB_PRESCALER==128 | CLOCK_AHB_PRESCALER==256 | CLOCK_AHB_PRESCALER==512)

#error CLOCK_AHB_PRESCALER : Avilable Oprions are 1, 2, 4, 8, 16, 64, 128, 256, and 512 only
#endif

#if !(CLOCK_PRESCALLER_TO_CORTEX_SYSTEM_TIMER==1 | CLOCK_PRESCALLER_TO_CORTEX_SYSTEM_TIMER==8)
#error CLOCK_PRESCALLER_TO_CORTEX_SYSTEM_TIMER : Avilable Options are 1 & 8 Only
#endif

#if !(CLOCK_APB1_PRESCALER==1 | CLOCK_APB1_PRESCALER==2 | CLOCK_APB1_PRESCALER==4 | CLOCK_APB1_PRESCALER==8 | CLOCK_APB1_PRESCALER==16)
#error CLOCK_APB1_PRESCALER : Avilable Options are 1,2,4,8,or 16 Only
#endif

#if !(CLOCK_APB2_PRESCALER==1 | CLOCK_APB2_PRESCALER==2 | CLOCK_APB2_PRESCALER==4 | CLOCK_APB2_PRESCALER==8 | CLOCK_APB2_PRESCALER==16)
#error CLOCK_APB2_PRESCALER : Avilable Options are 1,2,4,8,or 16 Only
#endif

/********************** BUS MAXIMUM VALUES GAUARD **********************/
#if CLOCK_HCLK_MHz > 168
/*Maximum Value for CLOCK_HCLK_MHz is 168 Mhz*/
#error CLOCK_HCLK_MHz : Maximum value of clock is 168 Mhz
#endif


#if CLOCK_APB1_PERIPHERAL_CLOCKS > 42
#error CLOCK_APB1_PERIPHERAL_CLOCKS : Maximum value of clock is 42 MHz
#endif

#if CLOCK_APB2_PERIPHERAL_CLOCKS > 84
#error CLOCK_APB2_PERIPHERAL_CLOCKS : Maximum value of clock is 84 MHz
#endif

/*
==================================================
  End Section --> Guard from wrong input values from user.
==================================================
*/

#endif /* HMCAL_RCC_RCC_PRIVATE_H_ */
