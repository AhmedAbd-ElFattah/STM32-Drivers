/*
 * File Name --> SCB.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 -->  
 * Github    --> github.com/AhmedAbd-ElFattah
 * Linkedin  --> https://www.linkedin.com/in/ahmed-mohamed-abd-elfattah-39705b238/
 */

#ifndef LMCAL_SCB_SCB_H_
#define LMCAL_SCB_SCB_H_




/*
==================================================
  Start Section --> File Includes
==================================================
*/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "STM32_Drivers_Configurations/Driver_Config.h"
#include "SCB_Private.h"
/*
==================================================
  End   Section --> File Includes
==================================================
*/



/*
==================================================
  Start Section --> Data Type Declaration
==================================================
*/

#define 		SCB                    ((volatile SCB_MemMap* const)(SCB_BASE_ADDRESS))

typedef enum{
	SCB_VectorTableInFlash,
	SCB_VectorTableInSRAM,
}SCB_VectorTableLocation;

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
u32 SCB_GetCPUId_u32(void);
u16 SCB_GetRevisionId_u16(void);
u16 SCB_GetPartNumberId_u16(void);
u16 SCB_GetVariantId_u16(void);
u16 SCB_GetImplementerId_u16(void);
void SCB_SetVectorTableOffset_void(u32 Arg_VectorTableOffset_u32, u8 Arg_VectorTableLocation);
void SCB_SWReset(void);
void SCB_EnableFPU_v(void);
/*
==================================================
  End   Section --> APIs
==================================================
*/
#endif /* LMCAL_SCB_SCB_H_ */
