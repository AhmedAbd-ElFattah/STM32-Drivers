/*
 * File Name --> EXTI_Private.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> EXTI driver private info like addresses.
 * */

#ifndef HMCAL_EXTI_EXTI_PRIVATE_H_
#define HMCAL_EXTI_EXTI_PRIVATE_H_
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
#define 		EXTI_BASE_ADDRESS                                                             	0x40013C00
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
#define EXTI_IMR_RESET_VALUE					0x00
#define EXTI_EMR_RESET_VALUE					0x00
#define EXTI_RTSR_RESET_VALUE					0x00
#define EXTI_FTSR_RESET_VALUE					0x00
#define EXTI_SWIER_RESET_VALUE					0x00
#define EXTI_PR_RESET_VALUE						0x00
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
	/*Interrupt mask register.*/
	volatile u32 IMR;
	/*Event mask register.*/
	volatile u32 EMR;
	/*Rising trigger selection register.*/
	volatile u32 RTSR;
	/*Falling trigger selection register.*/
	volatile u32 FTSR;
	/*Software interrupt event register.*/
	volatile u32 SWIER;
	/*Pending register.*/
	volatile u32 PR;
}EXTI_MemMap;

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
#define 		EXTI      	((volatile EXTI_MemMap*const)(EXTI_BASE_ADDRESS))
/*
==================================================
  End Section --> Define peripheral with it's address.
==================================================
*/

#endif /* HMCAL_EXTI_EXTI_PRIVATE_H_ */
