/*
 * File Name --> BIT_MATH.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> LIB
 * Brief	 --> Bit math operations.
 * */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_


/*
==================================================
  Start Section --> File Includes
==================================================
*/
#include "STD_TYPES.h"
/*
==================================================
  End   Section --> File Includes
==================================================
*/


/*
==================================================
  Start Section --> Macro Functions
==================================================
*/
#define 		SET_BIT(REG, BIT_NUMBER) 			(REG |= (1<<BIT_NUMBER))
#define			CLEAR_BIT(REG, BIT_NUMBER) 			(REG &= ~(1<<BIT_NUMBER))


#define			TOGGLE_BIT(REG, BIT_NUMBER) 		(REG ^= (1<<BIT_NUMBER))
#define			GET_BIT(REG, BIT_NUMBER) 			((REG>>BIT_NUMBER) & 0x01)
/*
==================================================
  End   Section --> Macro Functions
==================================================
*/


#endif /* LIB_BIT_MATH_H_ */
