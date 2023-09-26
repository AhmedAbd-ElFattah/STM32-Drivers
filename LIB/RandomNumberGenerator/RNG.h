/*
 * File Name --> RNG.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> LIB
 * Brief	 --> APIs for random function generator module.
 * */

#ifndef LIB_RANDOMNUMBERGENERATOR_RNG_H_
#define LIB_RANDOMNUMBERGENERATOR_RNG_H_

/*
==================================================
  Start Section --> File Includes
==================================================
*/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "STM32_Drivers_Configurations/Driver_Config.h"

/*
==================================================
  End   Section --> File Includes
==================================================
*/


/*
==================================================
  Start Section --> Macro Declaration
==================================================
*/
#define		RNG_BASE_ADDRESS		0x50060800
/*
==================================================
  End   Section --> Macro Declaration
==================================================
*/


/*
==================================================
  Start Section --> Data Type Declaration
==================================================
*/
typedef struct{
	/*RNG control register.*/
	u32 CR;
	/*RNG status register.*/
	u32 SR;
	/*RNG data register.*/
	u32 DR;
}RNG_MemMap;



#define 		RNG		((volatile RNG_MemMap*)(RNG_BASE_ADDRESS))
/*
==================================================
  End   Section --> Data Type Declaration
==================================================
*/


/*
==================================================
  Start Section --> APIs
==================================================
*/
u32 RNG_GetRandomNumber_u32(u32 Arg_LowerLimit_u32, u32 Arg_UpperLimit_u32);
/*
==================================================
  End   Section --> APIs
==================================================
*/
#endif /* LIB_RANDOMNUMBERGENERATOR_RNG_H_ */
