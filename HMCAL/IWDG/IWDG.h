/*
 * File Name --> IWDG.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> Provides API and available configuration options for IWDG peripheral.
 * */

#ifndef HMCAL_IWDG_IWDG_H_
#define HMCAL_IWDG_IWDG_H_




/*
==================================================
  Start Section --> File Includes
==================================================
*/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "IWDG_defs.h"
/*
==================================================
  End   Section --> File Includes
==================================================
*/

/*
==================================================
  Start Section --> APIs
==================================================
*/

void IWDG_Config_v(const u8 Arg_Prescaler_Cu8, const u16 Arg_ReloadValue_Cu16);
void IWDG_Refresh_v(void);
/*
==================================================
  End Section --> APIs
==================================================
*/
#endif /* HMCAL_IWDG_IWDG_H_ */
