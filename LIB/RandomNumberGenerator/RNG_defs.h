/*
 * File Name --> RNG_Config.c
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> LIB
 * Brief	 --> defines for random function generator module.
 * */

#ifndef LIB_RANDOMNUMBERGENERATOR_RNG_DEFS_H_
#define LIB_RANDOMNUMBERGENERATOR_RNG_DEFS_H_

/*
==================================================
  Start Section --> Macro Declaration
==================================================
*/
/* RNG Control register. */
#define 		RNG_CR_RNGEN						2
#define 		RNG_CR_IE							3

/* RNG Status register. */
#define			RNG_SR_DRDY							0
#define			RNG_SR_CECS							1
#define			RNG_SR_SECS							2
#define			RNG_SR_CEIS							5
#define			RNG_SR_SEIS							6

/*
==================================================
  End   Section --> Macro Declaration
==================================================
*/

#endif /* LIB_RANDOMNUMBERGENERATOR_RNG_DEFS_H_ */
