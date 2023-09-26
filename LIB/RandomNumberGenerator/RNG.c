/*
 * File Name --> RNG.c
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> LIB
 * Brief	 --> Implementation for random function generator module.
 * */


/*
==================================================
  Start Section --> File Includes
==================================================
*/
#include "RNG_Config.h"
#include "RNG.h"
#include "RNG_defs.h"
#include "HMCAL/RCC/RCC.h"
/*
==================================================
  End   Section --> File Includes
==================================================
*/

/*
==================================================
  Start Section --> Implementation
==================================================
*/
u32 RNG_GetRandomNumber_u32(u32 Arg_LowerLimit_u32, u32 Arg_UpperLimit_u32){
	static u32 StaticLocal_A_u32 = RNG_SOFTWARE_RNG_LINERT_CONFRUENTIAL_A;
	static u32 StaticLocal_B_u32 = RNG_SOFTWARE_RNG_LINERT_CONFRUENTIAL_B;
	static u32 StaticLocal_M_u32 = RNG_SOFTWARE_RNG_LINERT_CONFRUENTIAL_M;
	static u32 StaticLocal_Seed_u32 = RNG_SOFTWARE_RNG_LINERT_CONFRUENTIAL_INIT_SEED;

	u32 Local_Output_u32;

#if MCConfig_RNG_EXIST
	/*Enable RCC*/
	RCC_EnableClock_v(RCC_AHB2, RCC_RNG);
	SET_BIT(RNG->CR, RNG_CR_RNGEN);

	if (GET_BIT(RNG->SR, RNG_SR_CECS) | GET_BIT(RNG->SR, RNG_SR_SECS)){
		/*Software Calculation due to error in hardware calculations, check Frequencies !.*/
		StaticLocal_Seed_u32 *= ((StaticLocal_A_u32 * StaticLocal_Seed_u32) + StaticLocal_B_u32)%StaticLocal_M_u32;
		Local_Output_u32 = StaticLocal_Seed_u32;
	}
	else{
		while (!GET_BIT(RNG->SR, RNG_SR_DRDY));
		return Arg_LowerLimit_u32 + (u32)(RNG->DR % (Arg_UpperLimit_u32 - Arg_LowerLimit_u32 + 1));
	}

#else
	StaticLocal_Seed_u32 *= ((StaticLocal_A_u32 * StaticLocal_Seed_u32) + StaticLocal_B_u32)%StaticLocal_M_u32;
	Local_Output_u32 = StaticLocal_Seed_u32;
#endif
	Local_Output_u32 = Arg_LowerLimit_u32 + (u32)(Local_Output_u32 % (Arg_UpperLimit_u32 - Arg_LowerLimit_u32 + 1));
	return Local_Output_u32;
}
/*
==================================================
  End   Section --> Implementation
==================================================
*/
