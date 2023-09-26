/*
 * File Name --> IWDG.c
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> IWDG driver implementation.
 * */


/*
==================================================
  Start Section --> File Includes
==================================================
*/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "IWDG.h"
#include "IWDG_Private.h"
#include "IWDG_defs.h"
/*
==================================================
  End   Section --> File Includes
==================================================
*/

/*
==================================================
  Start Section --> Functions implementation.
==================================================
*/
void IWDG_Config_v(const u8 Arg_Prescaler_Cu8, const u16 Arg_ReloadValue_Cu16){
	 /*Enable access to registers IWDG_PR and IWDG_RLR
	  * by writing 0xAAAA in IWDG_KR Register*/
	 IWDG->KR = IWDG_ENABLE_ACCESS;
	 /*Wait till prescaller is updated*/

	 while(GET_BIT(IWDG->SR, IWDG_SR_PVU));
	 /*Set prescaler divider to 256*/
	 IWDG->PR = Arg_Prescaler_Cu8;
	 /*Wait while prescaller is updated*/
	 while(GET_BIT(IWDG->SR, IWDG_SR_RVU));
	 /* To set timeout = 96 mS
	  * As LSI Frequency = 32KHz
	  * and prescaler = 256
	  * timeout = (prescaler/Frequency) * IWDG_RLR -1
	  * IWDG_RLR = timeout / (prescaler/Frequency) -1
	  * IWDG_RLR = (96*10^-3) / (256 / (32*10^3))  -1
	  * IWDG_RLR = 11
	  * IWDG_RLR = 0x00B
	  * */
	 IWDG->RLR = Arg_ReloadValue_Cu16;
	 /*Start IWDG
	  *by writing 0xCCCC in IWDG_KR Register*/
	 IWDG->KR = IWDG_START_KEY;

}

void IWDG_Refresh_v(void){
	IWDG->KR = IWDG_REFRESH_KEY;
}
/*
==================================================
  End   Section --> Functions implementation.
==================================================
*/
