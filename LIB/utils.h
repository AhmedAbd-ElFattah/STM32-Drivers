/*
 * File Name --> utils.c
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> LIB
 * Brief	 --> APIs for utilization functions.
 * */

#ifndef LIB_UTILS_H_
#define LIB_UTILS_H_




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
#define	ARRAY_LENGTH(arr) sizeof(arr)/sizeof(arr[0])
#define UTILS_READ_ADDRESS(address)  (*((volatile u32*)address))
#define UTILS_WRITE_ADDRESS(address, value) *(( volatile u16*)address) = value
#define UTILS_MAX(a, b) (a>b ? a : b)
#define UTILS_MIN(a, b) (a<b ? a : b)
/*
==================================================
  End   Section --> Macro Functions
==================================================
*/


typedef struct Utils_TimeoutChecker{
	f32 PreciseDelayValue;
	u32 TimeoutValueInMilliSeconds;
}Utils_TimeoutChecker;


/*
==================================================
  Start Section --> APIs
==================================================
*/
void Utils_TimeoutChecker_Init(
		Utils_TimeoutChecker *Arg_Tout_Utils_TimeoutChecker,
		u32 Arg_TimeoutValueInmS_u32
);
u8 Utils_IsTimeoutOccurred_u8(Utils_TimeoutChecker *Arg_Tout_Utils_TimeoutChecker);

void Utils_SoftwareReset_v(void);
/*
==================================================
  End Section --> APIs
==================================================
*/
#endif /* LIB_UTILS_H_ */
