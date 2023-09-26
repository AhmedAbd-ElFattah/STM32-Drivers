/*
 * File Name --> SCB.c
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> LMCAL
 * Brief	 --> SYSTICK driver implementation.
 * */
/*
==================================================
  Start Section --> File Includes
==================================================
 */
#include "SCB.h"
/*
==================================================
  End   Section --> File Includes
==================================================
 */


/*
==================================================
  Start Section --> Function Implementation
==================================================
 */
u32 SCB_GetCPUId_u32(void){
	return SCB->CPUID;
}

u16 SCB_GetRevisionId_u16(void){
	return SCB->CPUID & 0xF;
}

u16 SCB_GetPartNumberId_u16(void){
	return (SCB->CPUID & 0xFFF0)>>4;
}

u16 SCB_GetVariantId_u16(void){
	return (SCB->CPUID & 0xF00000)>>20;
}

u16 SCB_GetImplementerId_u16(void){
	return (SCB->CPUID & 0xFF000000)>>24;
}

void SCB_EnableFPU_v(void){
#define SCB_FPU *((volatile u32* const)0xE000ED88)
	SCB_FPU |= (0xF<<20);
	asm volatile ("dsb 0xF":::"memory");


}
void SCB_SetVectorTableOffset_void(u32 Arg_VectorTableOffset_u32, u8 Arg_VectorTableLocation){
	u32 L_VOffset_u32 = Arg_VectorTableOffset_u32 & 0x1FFFFE00;
	switch (Arg_VectorTableLocation){
	case SCB_VectorTableInFlash:
		CLEAR_BIT(L_VOffset_u32, 29);
		break;

	case SCB_VectorTableInSRAM:
		SET_BIT(L_VOffset_u32, 29);
		break;
	}
	SCB->VTOR = L_VOffset_u32;
}

void SCB_SWReset(void){
	/*Data synchronization register*/
	asm volatile ("dsb 0xF":::"memory");
	SCB->AIRCR = (0x5FA<<16) | (1<<2) | (SCB->AIRCR&(7<<8));
	/*Data synchronization register*/
	asm volatile ("dsb 0xF":::"memory");
	while(1){
		asm volatile ("NOP");
	}
}
/*
==================================================
  End   Section --> Function Implementation
==================================================
 */


