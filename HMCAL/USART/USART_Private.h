/*
 * File Name --> USART_Private.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> USART driver private info like addresses.
 * */


#ifndef HMCAL_USART_USART_PRIVATE_H_
#define HMCAL_USART_USART_PRIVATE_H_

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
#define 		USART1_BASE_ADDRESS				0x40011000
#define 		USART2_BASE_ADDRESS             0x40004400
#define 		USART3_BASE_ADDRESS             0x40004800
#define 		UART4_BASE_ADDRESS              0x40004C00
#define 		UART5_BASE_ADDRESS              0x40005000
#define 		USART6_BASE_ADDRESS             0x40011400
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

#define USART_SR_RESET_VALUE			0x00C00000
#define USART_DR_RESET_VALUE			0x00000000
#define USART_BRR_RESET_VALUE			0x00000000
#define USART_CR1_RESET_VALUE			0x00000000
#define USART_CR2_RESET_VALUE			0x00000000
#define USART_CR3_RESET_VALUE			0x00000000
#define USART_GTPR_RESET_VALUE			0x00000000
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
	/* Status register.*/
	volatile u32 SR;
	/* Data register.*/
	volatile u32 DR;
	/* Baud rate register.*/
	volatile u32 BRR;
	/*Control register 1.*/
	volatile u32 CR1;
	/*Control register 2.*/
	volatile u32 CR2;
	/*Control register 3.*/
	volatile u32 CR3;
	/*Guard time and prescaler register.*/
	volatile u32 GTPR;
}USART_MemMap;
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


static u32 GCS_USART_InstanceIdMapping_u32[]={

		USART1_BASE_ADDRESS,
		USART2_BASE_ADDRESS,
		USART3_BASE_ADDRESS,
		UART4_BASE_ADDRESS,
		UART5_BASE_ADDRESS,
		USART6_BASE_ADDRESS,
};
/*
==================================================
  End Section --> Define peripheral with it's address.
==================================================
*/


#endif /* HMCAL_USART_USART_PRIVATE_H_ */
