/*
 * File Name --> DMA.c
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> DMA driver implementation.
 * */

/*
==================================================
  Start Section --> File Includes
==================================================
 */
#include "DMA.h"
#include "DMA_defs.h"
#include "DMA_Private.h"
#include "HMCAL/RCC/RCC.h"
#include "LMCAL/NVIC/NVIC.h"
/*
==================================================
  End   Section --> File Includes
==================================================
 */

/*
==================================================
  Start Section --> Macro to map Instance Id with it's physical address.
==================================================
 */
#define DMA_ID(id) ((volatile DMA_MemMap*const)(GCS_DMA_InstanceIdMapping_u32[((id)-1)]))
/*
==================================================
  End   Section --> Macro to map Instance Id with it's physical address.
==================================================
 */



/*
==================================================
  Start Section --> Functions implementation.
==================================================
 */

void DMA_Config_v(DMA_Cfg const * const Arg_conf_cpcDMA_Cfg,const u8 Arg_ChannelStream_Cu8){
	/*
	 * Extract stream number value & channel number from function parameter Arg_ChannelStream_Cu8.
	 * */
	const u8 L_StreamNum_Cu8 = Arg_ChannelStream_Cu8 & 0x0F;
	const u8 L_ChannelNum_Cu8 = ((Arg_ChannelStream_Cu8 & 0x70) >> 4);
	/*
	 * To reduce the headache on user of enabling clock of the used peripheral.
	 * It 's automatically enabled before configuring the peripheral by
	 * 1. Get the bus which is connected to peripheral by passing the address of any peripheral register
	 * to RCC_GetPeripheralBus_u8
	 * 2. Get the corresponding bit number of peripheral on it's but through RCC_GetRCCDMABit_u8
	 * by passing instance id of DMA peripheral.
	 * */
	RCC_EnableClock_v(
			RCC_GetPeripheralBus_u8((u32)DMA_ID(Arg_conf_cpcDMA_Cfg->InstanceId)),
			RCC_GetRCCDMABit_u8(Arg_conf_cpcDMA_Cfg->InstanceId));

	/*Disable DMA*/
	DMA_DisableDMA_v(Arg_conf_cpcDMA_Cfg, Arg_ChannelStream_Cu8);

	/*
	 * Clear all interrupt flags for selected DMA
	 * If stream number is 0, 1, 2, and 3, it's cleared from LIFCR register.
	 * If stream number is 4, 5, 6, and 7, it's cleared from HIFCR register
	 * */
	if (L_StreamNum_Cu8 <4){
		DMA_ID(Arg_conf_cpcDMA_Cfg->InstanceId)->LIFCR &= ~((u32)0xF<<(L_StreamNum_Cu8*8));
	}
	else{
		DMA_ID(Arg_conf_cpcDMA_Cfg->InstanceId)->HIFCR &= ~((u32)0xF<<((L_StreamNum_Cu8%4)*8));
	}


	/*
	 * To optimize code size and execution time.
	 * These variables are defined by their corresponding register reset value,
	 * and set/clear only bits that differ from reset value.
	 * */

	u32 L_CR_Reg_Val_u32 = DMA_CR_RESET_VALUE;
	u32 L_FCR_Reg_Val_u32 = DMA_FCR_RESET_VALUE;

	/*Channel configurations section.*/

	/*Set Channel Number.*/
	/*
	 * If transfer direction is not Memory to memory, channel number value is ignored.
	 * */
	if (DMA_TRANSFER_DIR_MEM_TO_MEM != Arg_conf_cpcDMA_Cfg->TransferDir){
		L_CR_Reg_Val_u32 |= (L_ChannelNum_Cu8 <<DMA_CR_CHSEL_0);
	}

	/*Burst configurations section.*/
	switch(Arg_conf_cpcDMA_Cfg->Burst){
	case DMA_BURST_MEM_SINGLE_TRANSFER_PERPH_SINGLE_TRANSFER:
		/*It is default value, so no changes to L_CR_Reg_Val_u32.*/
		break;
	case DMA_BURST_MEM_INCR_4_BEATS_TRANSFER_PERPH_SINGLE_TRANSFER:
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_MBURST_0);
		break;

	case DMA_BURST_MEM_INCR_8_BEATS_TRANSFER_PERPH_SINGLE_TRANSFER:
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_MBURST_1);
		break;

	case DMA_BURST_MEM_INCR_16_BEATS_TRANSFER_PERPH_SINGLE_TRANSFER:
		SET_BIT(L_CR_Reg_Val_u32, DMA_CR_MBURST_0);
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_MBURST_1);
		break;

	case DMA_BURST_MEM_SINGLE_TRANSFER_PERPH_INCR_4_BEATS:
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_PBURST_0);
		break;

	case DMA_BURST_MEM_INCR_4_BEATS_TRANSFER_PERPH_INCR_4_BEATS:
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_MBURST_0);
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_PBURST_0);
		break;

	case DMA_BURST_MEM_INCR_8_BEATS_TRANSFER_PERPH_INCR_4_BEATS:
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_MBURST_1);
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_PBURST_0);
		break;

	case DMA_BURST_MEM_INCR_16_BEATS_TRANSFER_PERPH_INCR_4_BEATS:
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_MBURST_0);
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_MBURST_1);
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_PBURST_0);
		break;

	case DMA_BURST_MEM_SINGLE_TRANSFER_PERPH_INCR_8_BEATS:
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_PBURST_1);
		break;

	case DMA_BURST_MEM_INCR_4_BEATS_TRANSFER_PERPH_INCR_8_BEATS:
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_MBURST_0);
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_PBURST_1);
		break;

	case DMA_BURST_MEM_INCR_8_BEATS_TRANSFER_PERPH_INCR_8_BEATS:
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_MBURST_1);
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_PBURST_1);
		break;

	case DMA_BURST_MEM_INCR_16_BEATS_TRANSFER_PERPH_INCR_8_BEATS:
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_MBURST_0);
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_MBURST_1);
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_PBURST_1);
		break;

	case DMA_BURST_MEM_SINGLE_TRANSFER_PERPH_INCR_16_BEATS:
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_PBURST_0);
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_PBURST_1);
		break;

	case DMA_BURST_MEM_INCR_4_BEATS_TRANSFER_PERPH_INCR_16_BEATS:
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_MBURST_0);
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_PBURST_0);
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_PBURST_1);
		break;
	case DMA_BURST_MEM_INCR_8_BEATS_TRANSFER_PERPH_INCR_16_BEATS:
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_MBURST_1);
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_PBURST_0);
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_PBURST_1);
		break;

	case DMA_BURST_MEM_INCR_16_BEATS_TRANSFER_PERPH_INCR_16_BEATS:
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_MBURST_0);
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_MBURST_1);
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_PBURST_0);
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_PBURST_1);
		break;

	default:
		break;
	}



	/*Double buffer configurations section.*/
	switch(Arg_conf_cpcDMA_Cfg->DoubleBuffer){
	case DMA_DOUBLE_BUFFER_DISABLE:
		/*It is default value, so no changes to L_CR_Reg_Val_u32.*/
		break;

	case DMA_DOUBLE_BUFFER_ENABLE_START_BUFFER_0:
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_DBM);
		break;

	case DMA_DOUBLE_BUFFER_ENABLE_START_BUFFER_1:
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_DBM);
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_CT);
		break;

	default:
		break;
	}

	/*Priority configurations section.*/
	switch(Arg_conf_cpcDMA_Cfg->Priority){
	case DMA_PRIORITY_LOW:
		/*It is default value, so no changes to L_CR_Reg_Val_u32.*/
		break;

	case DMA_PRIORITY_MEDIUM:
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_PL_0);
		break;

	case DMA_PRIORITY_HIGH:
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_PL_1);
		break;

	case DMA_PRIORITY_VERY_HIGH:
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_PL_0);
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_PL_1);
		break;

	default:
		break;
	}

	/*Peripheral increment offset configurations*/
	switch (Arg_conf_cpcDMA_Cfg->PeripheralIncrementOffset){
	case DMA_PERPH_INCR_AS_PERPH_SIZE:
		/*It is default value, so no changes to L_CR_Reg_Val_u32.*/
		break;

	case DMA_PERPH_INCR_IS_WORD:
		SET_BIT(L_CR_Reg_Val_u32,DMA_CR_PINCOS);
		break;

	default:
		break;
	}

	/*Data size configurations section*/
	switch (Arg_conf_cpcDMA_Cfg->DataSize){
	case DMA_DATA_SIZE_MEM_BYTE_PERPH_BYTE:
		/*It is default value, so no changes to L_CR_Reg_Val_u32.*/
		break;

	case DMA_DATA_SIZE_MEM_BYTE_PERPH_HALF_WORD:
		SET_BIT(L_CR_Reg_Val_u32, DMA_CR_PSIZE_0);
		break;

	case DMA_DATA_SIZE_MEM_BYTE_PERPH_WORD:
		SET_BIT(L_CR_Reg_Val_u32, DMA_CR_PSIZE_1);
		break;

	case DMA_DATA_SIZE_MEM_HALF_WORD_PERPH_BYTE:
		SET_BIT(L_CR_Reg_Val_u32, DMA_CR_MSIZE_0);
		break;

	case DMA_DATA_SIZE_MEM_HALF_WORD_PERPH_HALF_WORD:
		SET_BIT(L_CR_Reg_Val_u32, DMA_CR_MSIZE_0);
		SET_BIT(L_CR_Reg_Val_u32, DMA_CR_PSIZE_0);
		break;

	case DMA_DATA_SIZE_MEM_HALF_WORD_PERPH_WORD:
		SET_BIT(L_CR_Reg_Val_u32, DMA_CR_MSIZE_0);
		SET_BIT(L_CR_Reg_Val_u32, DMA_CR_PSIZE_1);
		break;

	case DMA_DATA_SIZE_MEM_WORD_PERPH_BYTE:
		SET_BIT(L_CR_Reg_Val_u32, DMA_CR_MSIZE_1);
		break;

	case DMA_DATA_SIZE_MEM_WORD_PERPH_HALF_WORD:
		SET_BIT(L_CR_Reg_Val_u32, DMA_CR_MSIZE_1);
		SET_BIT(L_CR_Reg_Val_u32, DMA_CR_PSIZE_0);
		break;

	case DMA_DATA_SIZE_MEM_WORD_PERPH_WORD:
		SET_BIT(L_CR_Reg_Val_u32, DMA_CR_MSIZE_1);
		SET_BIT(L_CR_Reg_Val_u32, DMA_CR_PSIZE_1);
		break;

	default:
		break;
	}


	/*Increment mode configurations section.*/
	switch (Arg_conf_cpcDMA_Cfg->IncrementMode){
	case DMA_INCREMENT_MODE_FIXED_MEM_FIXED_PERPH:
		/*It is default value, so no changes to L_CR_Reg_Val_u32.*/
		break;

	case DMA_INCREMENT_MODE_INCR_MEM_INCR_PERPH:
		SET_BIT(L_CR_Reg_Val_u32, DMA_CR_MINC);
		SET_BIT(L_CR_Reg_Val_u32, DMA_CR_PINC);
		break;

	case DMA_INCREMENT_MODE_FIXED_MEM_INCR_PERPH:
		SET_BIT(L_CR_Reg_Val_u32, DMA_CR_PINC);
		break;

	case DMA_INCREMENT_MODE_INCR_MEM_FIXED_PERPH:
		SET_BIT(L_CR_Reg_Val_u32, DMA_CR_MINC);
		break;

	default:
		break;
	}

	/*Data transfer direction configurations section.*/

	switch(Arg_conf_cpcDMA_Cfg->TransferDir){

	case DMA_TRANSFER_DIR_PERPH_TO_MEM:
		/*It is default value, so no changes to L_CR_Reg_Val_u32.*/
		break;

	case DMA_TRANSFER_DIR_MEM_TO_PERPH:
		SET_BIT(L_CR_Reg_Val_u32, DMA_CR_DIR_0);
		break;

	case DMA_TRANSFER_DIR_MEM_TO_MEM:
		SET_BIT(L_CR_Reg_Val_u32, DMA_CR_DIR_1);
		break;

	default:
		break;
	}

	/*Circular Mode configurations section.*/
	switch(Arg_conf_cpcDMA_Cfg->CircularMode){
	case DMA_CIRCULAR_MODE_DISABLE:
		/*It is default value, so no changes to L_CR_Reg_Val_u32.*/
		break;

	case DMA_CIRCULAR_MODE_ENABLE:
		SET_BIT(L_CR_Reg_Val_u32, DMA_CR_CIRC);
		break;

	default:
		break;
	}
	/*Flow Controller configurations section.*/
	switch(Arg_conf_cpcDMA_Cfg->FlowController){
	case DMA_FLOW_Controller_DMA:
		/*It is default value, so no changes to L_CR_Reg_Val_u32.*/
		break;

	case DMA_PERPH_Controller_DMA:
		SET_BIT(L_CR_Reg_Val_u32, DMA_CR_PFCTRL);
		break;

	default:
		break;

	}

	/*Direct Mode configurations section.*/
	switch(Arg_conf_cpcDMA_Cfg->DirectMode){
	case DMA_DIRECT_MODE_ENABLE:
		/*It is default value, so no changes to L_CR_Reg_Val_u32.*/
		break;
	case DMA_DIRECT_MODE_DISABLE:
		SET_BIT(L_FCR_Reg_Val_u32, DMA_FCR_DMDIS);
		break;

	default:
		break;
	}
	/*Mapping between DMA stream interrupt and It's corresponding NVIC*/
	u8 L_DMANVIC_u8[2][8] = {{
			NVIC_DMA1_Stream0, NVIC_DMA1_Stream1, NVIC_DMA1_Stream2,
			NVIC_DMA1_Stream3, NVIC_DMA1_Stream4, NVIC_DMA1_Stream5,
			NVIC_DMA1_Stream6, NVIC_DMA1_Stream7
	}, {
			NVIC_DMA2_Stream0, NVIC_DMA2_Stream1, NVIC_DMA2_Stream2,
			NVIC_DMA2_Stream3, NVIC_DMA2_Stream4, NVIC_DMA2_Stream5,
			NVIC_DMA2_Stream6, NVIC_DMA2_Stream7

	}};



	/*interrupt*/

	if (DMA_INTERRUPT_DISABLE == Arg_conf_cpcDMA_Cfg->Interrupt){
		/*It is default value, so no changes to L_CR_Reg_Val_u32.
		 * Default value disabled the following interrupts.
		 * - Direct mode error interrupt.
		 * - Transfer error interrupt.
		 * - Half transfer interrupt.
		 * - Transfer complete interrupt.
		 * - FIFO error interrupt.
		 * */

	}
	else if (0 < (DMA_INTERRUPT_TRANSFER_COMPLETE & Arg_conf_cpcDMA_Cfg->Interrupt)){
		/*Enable Transfer complete interrupt.*/
		SET_BIT(L_CR_Reg_Val_u32, DMA_CR_TCIE);
	}
	else if (0 < (DMA_INTERRUPT_HALF_TRANSFER & Arg_conf_cpcDMA_Cfg->Interrupt)){
		/*Enable Half-Transfer complete interrupt.*/
		SET_BIT(L_CR_Reg_Val_u32, DMA_CR_HTIE);
	}
	else if (0 < (DMA_INTERRUPT_TRANSFER_ERR & Arg_conf_cpcDMA_Cfg->Interrupt)){
		/*Enable Transfer error interrupt.*/
		SET_BIT(L_CR_Reg_Val_u32, DMA_CR_TEIE);
	}
	else if (0 < (DMA_INTERRUPT_DIRECT_MODE_ERR & Arg_conf_cpcDMA_Cfg->Interrupt)){
		/*Enable Direct mode interrupt.*/
		SET_BIT(L_CR_Reg_Val_u32, DMA_CR_DMEIE);
	}
	else if (0 < (DMA_INTERRUPT_FIFO_ERR & Arg_conf_cpcDMA_Cfg->Interrupt)){
		/*Enable FIFO error interrupt.*/
		SET_BIT(L_FCR_Reg_Val_u32, DMA_FCR_FEIE);
	}
	else{

	}

	/*
	 * If any type of interrupt exist, enable this intterupt to be detected by NVIC.
	 * */
	if (0 < Arg_conf_cpcDMA_Cfg->Interrupt){
		NVIC_EnableInterrupt_v(L_DMANVIC_u8[Arg_conf_cpcDMA_Cfg->InstanceId-1][L_StreamNum_Cu8]);
	}

	/*Assign each register to it's corresponding value.*/
	DMA_ID(Arg_conf_cpcDMA_Cfg->InstanceId)->Stream[L_StreamNum_Cu8].FCR = L_FCR_Reg_Val_u32;
	DMA_ID(Arg_conf_cpcDMA_Cfg->InstanceId)->Stream[L_StreamNum_Cu8].CR = L_CR_Reg_Val_u32;
	DMA_ID(Arg_conf_cpcDMA_Cfg->InstanceId)->Stream[L_StreamNum_Cu8].NDTR = Arg_conf_cpcDMA_Cfg->Size;
	DMA_ID(Arg_conf_cpcDMA_Cfg->InstanceId)->Stream[L_StreamNum_Cu8].PAR = Arg_conf_cpcDMA_Cfg->PeripheralAddress;
	DMA_ID(Arg_conf_cpcDMA_Cfg->InstanceId)->Stream[L_StreamNum_Cu8].M0AR = Arg_conf_cpcDMA_Cfg->MemoryAddress;
	DMA_ID(Arg_conf_cpcDMA_Cfg->InstanceId)->Stream[L_StreamNum_Cu8].M1AR = Arg_conf_cpcDMA_Cfg->MemoryAddressSecondBuffer;
}


void DMA_EnableDMA_v (DMA_Cfg const * const Arg_conf_cpcDMA_Cfg,const u8 Arg_ChannelStream_Cu8){
	const u8 L_StreamNum_Cu8 = Arg_ChannelStream_Cu8 & 0x0F;
	const u8 L_InstanceId_Cu8 = Arg_conf_cpcDMA_Cfg->InstanceId;

	SET_BIT(DMA_ID(L_InstanceId_Cu8)->Stream[L_StreamNum_Cu8].CR, DMA_CR_EN);
	/*Wait till DMA is enabled.*/
	while(STD_DIASBLE == GET_BIT(DMA_ID(L_InstanceId_Cu8)->Stream[L_StreamNum_Cu8].CR, DMA_CR_EN)){

	}
}
void DMA_DisableDMA_v (DMA_Cfg const * const Arg_conf_cpcDMA_Cfg,const u8 Arg_ChannelStream_Cu8){
	u8 L_StreamNum_Cu8 = Arg_ChannelStream_Cu8 & 0x0F;
	CLEAR_BIT(DMA_ID(Arg_conf_cpcDMA_Cfg->InstanceId)->Stream[L_StreamNum_Cu8].CR, DMA_CR_EN);
	/*wait till DMA is disabled*/
	while (STD_TRUE == GET_BIT(DMA_ID(Arg_conf_cpcDMA_Cfg->InstanceId)->Stream[L_StreamNum_Cu8].CR, DMA_CR_EN)){

	}
}

void DMA_ChangeBuffer0Address_v (DMA_Cfg  * const Arg_conf_cpcDMA_Cfg,const u8 Arg_ChannelStream_Cu8, const u32 Arg_NewAddress_Cu32){
	/*Disable DMA*/
	DMA_DisableDMA_v (Arg_conf_cpcDMA_Cfg,Arg_ChannelStream_Cu8);
	/*Enable RCC if it's not enabled*/
	RCC_EnableClock_v(
			RCC_GetPeripheralBus_u8((u32)DMA_ID(Arg_conf_cpcDMA_Cfg->InstanceId)),
			RCC_GetRCCDMABit_u8(Arg_conf_cpcDMA_Cfg->InstanceId));
	/*Assign new address to DMA.*/
	Arg_conf_cpcDMA_Cfg->MemoryAddress = Arg_NewAddress_Cu32;

	/*Assign new address to DMA_Cfg.*/
	DMA_ID(Arg_conf_cpcDMA_Cfg->InstanceId)->Stream[Arg_ChannelStream_Cu8 & 0x0F].M0AR = Arg_conf_cpcDMA_Cfg->MemoryAddress;
	/*Enable DMA*/
	DMA_EnableDMA_v(Arg_conf_cpcDMA_Cfg, Arg_ChannelStream_Cu8);
}

void DMA_ChangeBuffer1Address_v (DMA_Cfg  * const Arg_conf_cpcDMA_Cfg,const u8 Arg_ChannelStream_Cu8,const  u32 Arg_NewAddress_Cu32){
	/*Disable DMA*/
	DMA_DisableDMA_v (Arg_conf_cpcDMA_Cfg,Arg_ChannelStream_Cu8);
	/*Enable RCC if it's not enabled*/
	RCC_EnableClock_v(
			RCC_GetPeripheralBus_u8((u32)DMA_ID(Arg_conf_cpcDMA_Cfg->InstanceId)),
			RCC_GetRCCDMABit_u8(Arg_conf_cpcDMA_Cfg->InstanceId));
	/*Assign new address to DMA.*/
	Arg_conf_cpcDMA_Cfg->MemoryAddressSecondBuffer = Arg_NewAddress_Cu32;
	/*Assign new address to DMA_Cfg.*/
	DMA_ID(Arg_conf_cpcDMA_Cfg->InstanceId)->Stream[Arg_ChannelStream_Cu8 & 0x0F].M1AR = Arg_conf_cpcDMA_Cfg->MemoryAddressSecondBuffer;
	/*Enable DMA*/
	DMA_EnableDMA_v(Arg_conf_cpcDMA_Cfg, Arg_ChannelStream_Cu8);
}

Bool DMA_CheckInterruptAndClear_Bool(const u8 Arg_DMAInstanceId_u8,const  u8 Arg_StreamNum_Cu8,const  u8 Arg_InterruptFlagPos_Cu8){
	u8 L_PendRegPos_u8 = (Arg_StreamNum_Cu8 % 4);
	Bool L_CheckInterrupt_Bool = STD_FALSE;
	switch(L_PendRegPos_u8){
	case 0:
		L_PendRegPos_u8 += Arg_InterruptFlagPos_Cu8;
		break;

	case 1:
		L_PendRegPos_u8 += Arg_InterruptFlagPos_Cu8+6-1;
		break;

	case 2:
		L_PendRegPos_u8 += Arg_InterruptFlagPos_Cu8+16-2;
		break;

	case 3:
		L_PendRegPos_u8 += Arg_InterruptFlagPos_Cu8+22-3;
		break;
	default:
		break;
	}


	if ((Arg_StreamNum_Cu8 <= 3)&&(STD_TRUE == GET_BIT(DMA_ID(Arg_DMAInstanceId_u8)->LISR, L_PendRegPos_u8))){
		SET_BIT(DMA_ID(Arg_DMAInstanceId_u8)->LIFCR, L_PendRegPos_u8);
		L_CheckInterrupt_Bool = STD_TRUE;
	}
	else if ((Arg_StreamNum_Cu8 >= 4)&&(STD_TRUE == GET_BIT(DMA_ID(Arg_DMAInstanceId_u8)->HISR, L_PendRegPos_u8))){
		SET_BIT(DMA_ID(Arg_DMAInstanceId_u8)->HIFCR, L_PendRegPos_u8);
		L_CheckInterrupt_Bool = STD_TRUE;
	}
	else{
		L_CheckInterrupt_Bool = STD_FALSE;
	}


	return L_CheckInterrupt_Bool;
}



u8 DMA_GetCurrentBuffer_v(DMA_Cfg const * const Arg_conf_cpcDMA_Cfg,const u8 Arg_ChannelStream_Cu8){

	return GET_BIT(DMA_ID(Arg_conf_cpcDMA_Cfg->InstanceId)->Stream[(Arg_ChannelStream_Cu8 & 0x0F)].CR, DMA_CR_CT);
}

void DMA_Reset_v(DMA_Cfg const * const Arg_conf_cpcDMA_Cfg,const  u8 Arg_ChannelStream_Cu8){
	/*Set default configurations to DMA*/
	DMA_Cfg G_DMAExMem2Mem = {0};
	G_DMAExMem2Mem.InstanceId = Arg_conf_cpcDMA_Cfg->InstanceId;
	DMA_Config_v(&G_DMAExMem2Mem, Arg_ChannelStream_Cu8);
}
/*
==================================================
  End   Section --> Functions implementation.
==================================================
 */
