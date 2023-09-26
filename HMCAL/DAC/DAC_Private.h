/*
 * File Name --> DAC_Private.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> DAC driver private info like addresses.
 * */


#ifndef HMCAL_DAC_DAC_PRIVATE_H_
#define HMCAL_DAC_DAC_PRIVATE_H_

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
#define 		DAC1_BASE_ADDRESS                                                             	0x40007400
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
#define DAC_MCR_RESET_VALUE				0x00
#define DAC_CR_RESET_VALUE				0x00
#define DAC_SWTRIGR_RESET_VALUE			0x00
#define DAC_DHR12R1_RESET_VALUE			0x00
#define DAC_DHR12L1_RESET_VALUE			0x00
#define DAC_DHR8R1_RESET_VALUE			0x00
#define DAC_DHR12R2_RESET_VALUE			0x00
#define DAC_DHR12L2_RESET_VALUE			0x00
#define DAC_DHR8R2_RESET_VALUE			0x00
#define DAC_DHR12RD_RESET_VALUE			0x00
#define DAC_DHR12LD_RESET_VALUE			0x00
#define DAC_DHR8RD_RESET_VALUE			0x00
#define DAC_DOR1_RESET_VALUE			0x00
#define DAC_DOR2_RESET_VALUE			0x00
#define DAC_SR_RESET_VALUE				0x00

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
	/*DAC control register.*/
	volatile u32 CR;
	/*DAC software trigger register.*/
	volatile u32 SWTRIGR;
	/*DAC channel1 12-bit right-aligned data holding register.*/
	volatile u32 DHR12R1;
	/*DAC channel1 12-bit left aligned data holding register. */
	volatile u32 DHR12L1;
	/*DAC channel1 8-bit right aligned data holding register. */
	volatile u32 DHR8R1;
	/*DAC channel2 12-bit right aligned data holding register. */
	volatile u32 DHR12R2;
	/*DAC channel2 12-bit left aligned data holding register. */
	volatile u32 DHR12L2;
	/*DAC channel2 8-bit right-aligned data holding register. */
	volatile u32 DHR8R2;
	/*Dual DAC 12-bit right-aligned data holding register. */
	volatile u32 DHR12RD;
	/*DUAL DAC 12-bit left aligned data holding register. */
	volatile u32 DHR12LD;
	/*DUAL DAC 8-bit right aligned data holding register. */
	volatile u32 DHR8RD;
	/*DAC channel1 data output register. */
	volatile u32 DOR1;
	/*DAC channel2 data output register. */
	volatile u32 DOR2;
	/*DAC status register. */
	volatile u32 SR;
}DAC_MemMap;
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

static u32 GCS_DAC_InstanceIdMapping_u32[]={
		DAC1_BASE_ADDRESS,
};
/*
==================================================
  End Section --> Define peripheral with it's address.
==================================================
*/
#endif /* HMCAL_DAC_DAC_PRIVATE_H_ */
