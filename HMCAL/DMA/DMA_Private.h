/*
 * File Name --> DMA_Private.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> DMA driver private info like addresses.
 * */

#ifndef HMCAL_DMA_DMA_PRIVATE_H_
#define HMCAL_DMA_DMA_PRIVATE_H_

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
#define 		DMA1_BASE_ADDRESS                                                             	0x40026000
#define 		DMA2_BASE_ADDRESS                                                             	0x40026400
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
#define DMA_CR_RESET_VALUE					0x00
#define DMA_NDTR_RESET_VALUE				0x00
#define DMA_PAR_RESET_VALUE					0x00
#define DMA_M0AR_RESET_VALUE				0x00
#define DMA_M1AR_RESET_VALUE				0x00
#define DMA_FCR_RESET_VALUE					0x00000021
#define DMA_LISR_RESET_VALUE				0x00
#define DMA_HISR_RESET_VALUE				0x00
#define DMA_LIFCR_RESET_VALUE				0x00
#define DMA_HIFCR_RESET_VALUE				0x00
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
typedef struct{
	/*DMA stream x configurations register.*/
	volatile u32 CR;
	/*DMA stream x number of data register.*/
	volatile u32 NDTR;
	/*DMA stream x peripheral address register.*/
	volatile u32 PAR;
	/*DMA stream x memory 0 address register.*/
	volatile u32 M0AR;
	/*DMA stream x memory 1 address register.*/
	volatile u32 M1AR;
	/*DMA stream x FIFO control register.*/
	volatile u32 FCR;
}DMA_S_MemMap;

typedef struct{
	/*Low Interrupt status register.*/
	volatile u32 LISR;
	/*High Interrupt status register.*/
	volatile u32 HISR;
	/*Low Interrupt flag clear register.*/
	volatile u32 LIFCR;
	/*High Interrupt flag clear register.*/
	volatile u32 HIFCR;
	volatile DMA_S_MemMap Stream[8];
}DMA_MemMap;

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

const static u32 GCS_DMA_InstanceIdMapping_u32[]={
		DMA1_BASE_ADDRESS,
		DMA2_BASE_ADDRESS,
};
/*
==================================================
  End Section --> Define peripheral with it's address.
==================================================
*/

#endif /* HMCAL_DMA_DMA_PRIVATE_H_ */
