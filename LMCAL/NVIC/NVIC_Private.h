/*
 * File Name --> NVIC_Private.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> LMCAL
 * Brief	 --> NVIC driver private info like addresses.
 * */
#ifndef LMCAL_NVIC_NVIC_PRIVATE_H_
#define LMCAL_NVIC_NVIC_PRIVATE_H_


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
#define 	NVIC_BASE_ADDRESS	0xE000E100
/*
==================================================
  End   Section --> Define peripheral addresses.
==================================================
 */

/*
==================================================
  Start Section --> Peripheral register structure.
==================================================
 */
typedef struct {
	volatile u32 ISER[8];
	volatile u32 Reserved0[24];
	volatile u32 ICER[8];
	volatile u32 Reserved1[24];
	volatile u32 ISPR[8];
	volatile u32 Reserved2[24];
	volatile u32 ICPR[8];
	volatile u32 Reserved3[24];
	volatile u32 IABR[8];
	volatile u32 Reserved4[56];
	volatile u8  IPR[240];
	volatile u32 Reserved5[644];
	volatile u32 STIR;
}NVIC_Memory_map;

/*
==================================================
  End Section -->   Peripheral register structure.
==================================================
 */



#endif /* LMCAL_NVIC_NVIC_PRIVATE_H_ */
