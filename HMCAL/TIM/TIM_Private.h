/*
 * File Name --> TIM_Private.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> TIM driver private info like addresses.
 * */

#ifndef HMCAL_TIM_TIM_PRIVATE_H_
#define HMCAL_TIM_TIM_PRIVATE_H_

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
  Start Section --> Define peripheral addresses.
==================================================
*/
#define 	TIM1_BASE_ADDRESS           0x40010000
#define 	TIM2_BASE_ADDRESS           0x40000400
#define 	TIM3_BASE_ADDRESS           0x40000400
#define 	TIM4_BASE_ADDRESS           0x40000800
#define 	TIM5_BASE_ADDRESS           0x40000C00
#define 	TIM6_BASE_ADDRESS           0x40001000
#define 	TIM7_BASE_ADDRESS           0x40001400
#define 	TIM8_BASE_ADDRESS           0x40010400
#define 	TIM9_BASE_ADDRESS           0x40014000
#define 	TIM10_BASE_ADDRESS          0x40014400
#define 	TIM11_BASE_ADDRESS          0x40014800
#define 	TIM12_BASE_ADDRESS          0x40001800
#define 	TIM13_BASE_ADDRESS          0x40001C00
#define 	TIM14_BASE_ADDRESS          0x40002000

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
#define	TIM_CR1_RESET_VALUE		0x00
#define	TIM_CR2_RESET_VALUE		0x00
#define	TIM_SMCR_RESET_VALUE	0x00
#define	TIM_DIER_RESET_VALUE	0x00
#define	TIM_SR_RESET_VALUE		0x00
#define	TIM_EGR_RESET_VALUE		0x00
#define	TIM_CCMR1_RESET_VALUE	0x00
#define	TIM_CCMR2_RESET_VALUE	0x00
#define	TIM_CCER_RESET_VALUE	0x00
#define	TIM_CNT_RESET_VALUE		0x00
#define	TIM_PSC_RESET_VALUE		0x00
#define	TIM_ARR_RESET_VALUE		0x00
#define	TIM_CCER_RESET_VALUE	0x00
#define	TIM_RCR_RESET_VALUE		0x00
#define	TIM_CCR1_RESET_VALUE	0x00
#define	TIM_CCR2_RESET_VALUE	0x00
#define	TIM_CCR3_RESET_VALUE	0x00
#define	TIM_CCR4_RESET_VALUE	0x00
#define	TIM_BDTR_RESET_VALUE	0x00
#define	TIM_DCR_RESET_VALUE		0x00
#define	TIM_DMAR_RESET_VALUE	0x00
/*
==================================================
  End Section --> Reset values.
==================================================
*/


/*
==================================================
  Start Section --> Peripheral register mapping.
==================================================
*/
typedef struct {
	/* TIM control register 1.*/
	volatile u32 CR1;
	/* TIM control register 2.*/
	volatile u32 CR2;
	/*TIM slave mode control register.*/
	volatile u32 SMCR;
	/* DMA/Interrupt enable register. */
	volatile u32 DIER;
	/* TIM status register. */
	volatile u32 SR;
	/*TIM event generation register. */
	volatile u32 EGR;
	/*TIM capture/compare mode register 1.*/
	volatile u32 CCMR1;
	/*TIM capture/compare mode register 2.*/
	volatile u32 CCMR2;
	/*TIM capture/compare enable register.*/
	volatile u32 CCER;
	/*TIM counter. */
	volatile u32 CNT;
	/*TIM prescaler. */
	volatile u32 PSC;
	/*TIM auto-reload register. */
	volatile u32 ARR;
	/*TIM repetition counter register. */
	volatile u32 RCR;
	/*TIM capture/compare register 1*/
	volatile u32 CCR1;
	/*TIM capture/compare register 2*/
	volatile u32 CCR2;
	/*TIM capture/compare register 3*/
	volatile u32 CCR3;
	/*TIM capture/compare register 4*/
	volatile u32 CCR4;
	/*TIM break and dead-time register. */
	volatile u32 BDTR;
	/*TIM DMA control register. */
	volatile u32 DCR;
	/*TIM DMA address for full transfer register. */
	volatile u32 DMAR;

}TIM_MemMap;
/*
==================================================
  End Section --> Peripheral register mapping.
==================================================
*/


/*
==================================================
  Start Section --> Define peripheral with it's address.
==================================================
*/


const static u32 GCS_TIM_InstanceIdMapping_u32[]={
		TIM1_BASE_ADDRESS,
		TIM2_BASE_ADDRESS,
		TIM3_BASE_ADDRESS,
		TIM4_BASE_ADDRESS,
		TIM5_BASE_ADDRESS,
		TIM6_BASE_ADDRESS,
		TIM7_BASE_ADDRESS,
		TIM8_BASE_ADDRESS,
		TIM9_BASE_ADDRESS,
		TIM10_BASE_ADDRESS,
		TIM11_BASE_ADDRESS,
		TIM12_BASE_ADDRESS,
		TIM13_BASE_ADDRESS,
		TIM14_BASE_ADDRESS,
};
/*
==================================================
  End Section --> Define peripheral with it's address.
==================================================
*/

#endif /* HMCAL_TIM_TIM_PRIVATE_H_ */
