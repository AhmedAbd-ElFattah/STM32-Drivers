/*
 * File Name --> ADC_Private.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> ADC driver private info like addresses.
 * */

#ifndef HMCAL_ADC_ADC_PRIVATE_H_
#define HMCAL_ADC_ADC_PRIVATE_H_

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
#define			ADC1_BASE_ADDRESS			0x40012000
#define			ADC2_BASE_ADDRESS			(ADC1_BASE_ADDRESS + 0x100)
#define			ADC3_BASE_ADDRESS			(ADC1_BASE_ADDRESS + 0x200)
#define			ADC_BASE_ADDRESS			(ADC1_BASE_ADDRESS + 0x300)
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

#define ADC_SR_RESET_VALUE		0x00
#define ADC_CR1_RESET_VALUE     0x00
#define ADC_CR2_RESET_VALUE     0x00
#define ADC_SMPR1_RESET_VALUE   0x00
#define ADC_SMPR2_RESET_VALUE   0x00
#define ADC_JOFR1_RESET_VALUE   0x00
#define ADC_JOFR2_RESET_VALUE   0x00
#define ADC_JOFR3_RESET_VALUE   0x00
#define ADC_JOFR4_RESET_VALUE   0x00
#define ADC_HTR_RESET_VALUE     0x00000FFF
#define ADC_LTR_RESET_VALUE     0x00
#define ADC_SQR1_RESET_VALUE    0x00
#define ADC_SQR2_RESET_VALUE    0x00
#define ADC_SQR3_RESET_VALUE    0x00
#define ADC_JSQR_RESET_VALUE    0x00
#define ADC_JDR1_RESET_VALUE    0x00
#define ADC_JDR2_RESET_VALUE    0x00
#define ADC_JDR3_RESET_VALUE    0x00
#define ADC_JDR4_RESET_VALUE    0x00
#define ADC_DR_RESET_VALUE      0x00

/*
==================================================
  End Section --> Reset values.
==================================================
*/

/*
==================================================
  Start Section --> Peripheral register structure.
==================================================
*/
typedef struct{
	/*ADC status register.*/
	volatile u32 SR;
	/*ADC control register 1.*/
	volatile u32	CR1;
	/*ADC control register 2.*/
	volatile u32 CR2;
	/*ADC sample time register 1.*/
	volatile u32 SMPR1;
	/*ADC sample time register 2.*/
	volatile u32 SMPR2;
	/*ADC injected channel data offset register 1.*/
	volatile u32 JOFR1;
	/*ADC injected channel data offset register 2.*/
	volatile u32 JOFR2;
	/*ADC injected channel data offset register 3.*/
	volatile u32 JOFR3;
	/*ADC injected channel data offset register 4.*/
	volatile u32 JOFR4;
	/*ADC watchdog higher threshold register.*/
	volatile u32 HTR;
	/*ADC watchdog lower threshold register.*/
	volatile u32 LTR;
	/*ADC regular sequence register 1.*/
	volatile u32 SQR1;
	/*ADC regular sequence register 2.*/
	volatile u32 SQR2;
	/*ADC regular sequence register 3.*/
	volatile u32 SQR3;
	/*ADC injected sequence register.*/
	volatile u32 JSQR;
	/*ADC injected data register 1.*/
	volatile u32 JDR1;
	/*ADC injected data register 2.*/
	volatile u32 JDR2;
	/*ADC injected data register 3.*/
	volatile u32 JDR3;
	/*ADC injected data register 4.*/
	volatile u32 JDR4;
	/*ADC regular data register.*/
	volatile u32 DR;
}ADC_MemMap;

typedef struct{
	/*ADC Common status register.*/
	volatile u32 CSR;
	/*ADC common control register.*/
	volatile u32 CCR;
	/*ADC common regular data register for dual and triple modes.*/
	volatile u32 CDR;
}ADC_CommonMemMap;

/*
==================================================
  End Section --> Peripheral register structure.
==================================================
*/

/*
==================================================
  Start Section --> Array that maps instance id with it's address.
==================================================
*/
const static u32 GCS_ADC_InstanceIdMapping_u32[]={
		ADC1_BASE_ADDRESS,
		ADC2_BASE_ADDRESS,
		ADC3_BASE_ADDRESS,
};
/*
==================================================
  End Section --> Array that maps instance id with it's address.
==================================================
*/

#endif /* HMCAL_ADC_ADC_PRIVATE_H_ */
