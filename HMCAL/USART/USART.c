/*
 * File Name --> USART.c
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> USART driver implementation.
 * */



/*
==================================================
  Start Section --> File Includes
==================================================
 */
#include "USART.h"
#include "USART_defs.h"
#include "USART_Private.h"
#include "HMCAL/RCC/RCC.h"
#include "HMCAL/GPIO/GPIO.h"
#include "LMCAL/SYSTICK/SYSTICK.h"
#include "LIB/utils.h"
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
#define USART_ID(id) ((volatile USART_MemMap*const)(GCS_USART_InstanceIdMapping_u32[((id)-1)]))
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

void USART_Config_v(USART_Cfg const * const Arg_conf_cpcUSART_Cfg){

	/*GPIO that will be used with USART peripheral.*/
	GPIO_Cfg L_usartGPIO_GPIO_Cfg = {0};
	L_usartGPIO_GPIO_Cfg.InstanceId = Arg_conf_cpcUSART_Cfg->GPIOInstanceId;
	L_usartGPIO_GPIO_Cfg.Mode = GPIO_MODE_ALTERNATE_FUNCTION;
	L_usartGPIO_GPIO_Cfg.PINs = Arg_conf_cpcUSART_Cfg->GPIOPins;
	L_usartGPIO_GPIO_Cfg.OutputSpeed = GPIO_OUTPUT_SPEED_HIGH;
	L_usartGPIO_GPIO_Cfg.OutputType = GPIO_OUTPUT_TYPE_PUSH_PULL;
	L_usartGPIO_GPIO_Cfg.PullUpPullDownResistor = GPIO_RESISTOR_NO_PULL;


	/*Mapping USART with it's corresponding alternate function number.*/
	u8 L_USARTMappingPins[] = {
			USART1_MAP_PIN,
			USART2_MAP_PIN,
			USART3_MAP_PIN,
			UART4_MAP_PIN,
			UART5_MAP_PIN,
			USART6_MAP_PIN,
	};

	for (u8 L_i_u8 = 0; L_i_u8<16; L_i_u8++){
		if (STD_TRUE == GET_BIT(Arg_conf_cpcUSART_Cfg->GPIOPins, L_i_u8)){
			GPIO_MapGPIOPIN_v(&L_usartGPIO_GPIO_Cfg,
					L_i_u8,
					L_USARTMappingPins[Arg_conf_cpcUSART_Cfg->InstanceId-1]);
		}
	}

	/*Configure pin that will be used with USART*/
	GPIO_Config_v(&L_usartGPIO_GPIO_Cfg);

	/*Disable USART*/
	USART_DisableUSART_v(Arg_conf_cpcUSART_Cfg);

	/*
	 * To reduce the headache on user of enabling clock of the used peripheral.
	 * It 's automatically enabled before configuring the peripheral by
	 * 1. Get the bus which is connected to peripheral by passing the address of any peripheral register
	 * to RCC_GetPeripheralBus_u8
	 * 2. Get the corresponding bit number of peripheral on it's but through RCC_GetRCCUSARTBit_u8
	 * by passing instance id of USART peripheral.
	 * */

	RCC_EnableClock_v(
			RCC_GetPeripheralBus_u8((u32)USART_ID(Arg_conf_cpcUSART_Cfg->InstanceId)),
			RCC_GetRCCUSARTBit_u8(Arg_conf_cpcUSART_Cfg->InstanceId));


	/*Reset registers*/
	USART_ID(Arg_conf_cpcUSART_Cfg->InstanceId)->SR = USART_SR_RESET_VALUE;

	/*
	 * To optimize code size and execution time.
	 * These variables are defined by their corresponding register reset value,
	 * and set/clear only bits that differ from reset value.
	 * */

	u32 L_CR1_Reg_Val_u32 = USART_CR1_RESET_VALUE;
	u32 L_CR2_Reg_Val_u32 = USART_CR2_RESET_VALUE;
	u32 L_CR3_Reg_Val_u32 = USART_CR3_RESET_VALUE;

	/*Databits configurations section.*/
	switch (Arg_conf_cpcUSART_Cfg->Databits){
	case USART_Databits_8:
		/*It is default value, so no changes to L_CR1_Reg_Val_u32.*/
		break;
	case USART_Databits_9:
		SET_BIT(L_CR1_Reg_Val_u32, USART_CR1_M);
		break;
	default:

		break;
	}

	/*Oversampling configurations section.*/
	switch (Arg_conf_cpcUSART_Cfg->Oversampling){
	case USART_OVERSAMPLING_16:
		/*It is default value, so no changes to L_CR1_Reg_Val_u32.*/
		break;
	case USART_OVERSAMPLING_8:
		SET_BIT(L_CR1_Reg_Val_u32, USART_CR1_OVER8);
		break;
	default :
		break;
	}

	/*Parity configurations section.*/
	switch(Arg_conf_cpcUSART_Cfg->Parity){
	case USART_PARITY_DISABLE:
		/*It is default value, so no changes to L_CR1_Reg_Val_u32.*/
		break;
	case USART_PARITY_EVEN:
		SET_BIT(L_CR1_Reg_Val_u32, 10);

		break;
	case USART_PARITY_ODD:
		SET_BIT(L_CR1_Reg_Val_u32, 10);
		SET_BIT(L_CR1_Reg_Val_u32, 9);
		break;
	default :
		break;
	}

	/*Mapping between USART interrupt and It's corresponding NVIC*/
	if (0 !=Arg_conf_cpcUSART_Cfg->Interrupt){
		u8 L_USARTPinMapping_u8[] = {
				NVIC_USART1,
				NVIC_USART2,
				NVIC_USART3,
				NVIC_UART4,
				NVIC_UART5,
				NVIC_USART6
		};
		NVIC_EnableInterrupt_v(L_USARTPinMapping_u8[Arg_conf_cpcUSART_Cfg->InstanceId-1]);
	}
	/*Interrupt configurations section.*/
	/*Interrupt :: Parity error.*/
	if ((Arg_conf_cpcUSART_Cfg->Interrupt & (u32)USART_INTERRUPT_PARITY_ERROR)>0){
		SET_BIT(L_CR1_Reg_Val_u32, USART_CR1_PEIE);
	}
	/*Interrupt :: Transmit data empty.*/
	if ((Arg_conf_cpcUSART_Cfg->Interrupt & USART_INTERRUPT_TRANSMIT_DATA_EMPTY)>0){
		SET_BIT(L_CR1_Reg_Val_u32, USART_CR1_TXEIE);
	}
	/*Interrupt :: Transmit complete.*/
	if ((Arg_conf_cpcUSART_Cfg->Interrupt & USART_INTERRUPT_TRANSMIT_COMPLETE)>0){
		SET_BIT(L_CR1_Reg_Val_u32, USART_CR1_TCIE);
	}
	/*Interrupt :: Read data not-empty.*/
	if ((Arg_conf_cpcUSART_Cfg->Interrupt & USART_INTERRUPT_READ_DATA_REGISTER_NOT_EMPTY)>0){
		SET_BIT(L_CR1_Reg_Val_u32, USART_CR1_RXNEIE);
	}
	/*Interrupt :: Idle line detected.*/
	if ((Arg_conf_cpcUSART_Cfg->Interrupt & USART_INTERRUPT_IDLE_LINE_DETECTED)>0){
		SET_BIT(L_CR1_Reg_Val_u32, USART_CR1_IDLEIE);
	}
	/*Interrupt :: CTS Hardware flow control.*/
	if ((Arg_conf_cpcUSART_Cfg->Interrupt & USART_INTERRUPT_CTS)>0){
		SET_BIT(L_CR3_Reg_Val_u32, USART_CR3_CTSIE);
	}
	/*Interrupt :: Error.*/
	if ((Arg_conf_cpcUSART_Cfg->Interrupt & USART_INTERRUPT_ERROR)>0){
		SET_BIT(L_CR3_Reg_Val_u32, USART_CR3_EIE);
	}
	/*Interrupt :: Over run error.*/
	if ((Arg_conf_cpcUSART_Cfg->Interrupt & USART_INTERRUPT_OVERRUN_ERROR)>0){
		SET_BIT(L_CR3_Reg_Val_u32, USART_CR3_EIE);
	}
	/*Interrupt :: Noise detected.*/
	if ((Arg_conf_cpcUSART_Cfg->Interrupt & USART_INTERRUPT_NOISE_DETECTED)>0){
		SET_BIT(L_CR3_Reg_Val_u32, USART_CR3_EIE);
	}
	/*Interrupt :: Frame error.*/
	if ((Arg_conf_cpcUSART_Cfg->Interrupt & USART_INTERRUPT_FRAME_ERROR)>0){
		SET_BIT(L_CR3_Reg_Val_u32, USART_CR3_EIE);
	}
	/*Interrupt :: Parity error.*/
	if ((Arg_conf_cpcUSART_Cfg->Interrupt & USART_INTERRUPT_PARITY_ERROR)>0){
		SET_BIT(L_CR3_Reg_Val_u32, USART_CR3_EIE);
	}
	/*DMA configurations.*/

	/*Configure DMA transmission.*/
	if ((Arg_conf_cpcUSART_Cfg->DMA & USART_DMA_TRANSMIT)>0){

		SET_BIT(L_CR3_Reg_Val_u32, USART_CR3_DMAT);
	}

	/*Configure DMA reception.*/
	if((Arg_conf_cpcUSART_Cfg->DMA & USART_DMA_RECEIVE)>0){
		SET_BIT(L_CR3_Reg_Val_u32, USART_CR3_DMAR);
	}

	/*USART Transmit/Receive configurations.*/
	if ((Arg_conf_cpcUSART_Cfg->TransferDirection & USART_RECEIVE)>0){
		SET_BIT(L_CR1_Reg_Val_u32, USART_CR1_RE);
	}

	if ((Arg_conf_cpcUSART_Cfg->TransferDirection & USART_TRANSMIT)>0){
		SET_BIT(L_CR1_Reg_Val_u32, USART_CR1_TE);
	}


	/*Stop Bits configurations section.*/
	switch(Arg_conf_cpcUSART_Cfg->StopBits){
	case USART_STOP_ONE_BIT:
		/*It is default value, so no changes to L_CR2_Reg_Val_u32.*/
		break;

	case USART_STOP_HALF_BIT:
		SET_BIT(L_CR2_Reg_Val_u32, USART_CR2_STOP_0);

		break;

	case USART_STOP_ONE_HALF_BIT:
		SET_BIT(L_CR2_Reg_Val_u32, USART_CR2_STOP_0);
		SET_BIT(L_CR2_Reg_Val_u32, USART_CR2_STOP_1);
		break;
	case USART_STOP_TWO_BITS:

		SET_BIT(L_CR2_Reg_Val_u32, USART_CR2_STOP_1);
		break;
	default :
		break;
	}

	/*Clock configurations section.*/

	switch(Arg_conf_cpcUSART_Cfg->ClockPhaseAndPolarity){
	case USART_CLOCK_STEADY_LOW_FIRST_DATA_CAPTURE:
		/*It is default value, so no changes to L_CR2_Reg_Val_u32.*/
		break;

	case USART_CLOCK_STEADY_LOW_SECOND_DATA_CAPTURE:

		SET_BIT(L_CR2_Reg_Val_u32, USART_CR2_CPOL);
		break;

	case USART_CLOCK_STEADY_HIGH_FIRST_DATA_CAPTURE:

		SET_BIT(L_CR2_Reg_Val_u32, USART_CR2_CPOL);
		break;

	case USART_CLOCK_STEADY_HIGH_SECOND_DATA_CAPTURE:
		SET_BIT(L_CR2_Reg_Val_u32, USART_CR2_CPHA);
		SET_BIT(L_CR2_Reg_Val_u32, USART_CR2_CPOL);
		break;
	default :
		break;
	}

	/*CTS / RTS configurations section.*/
	switch(Arg_conf_cpcUSART_Cfg->CTSAndRTS){
	case USART_CTS_DISABLE_RTS_DISABLE:
		/*It is default value, so no changes to L_CR3_Reg_Val_u32.*/
		break;
	case USART_CTS_ENABLE_RTS_DISABLE:
		SET_BIT(L_CR3_Reg_Val_u32, USART_CR3_CTSE);

		break;
	case USART_CTS_DISABLE_RTS_ENABLE:

		SET_BIT(L_CR3_Reg_Val_u32, USART_CR3_RTSE);
		break;
	case USART_CTS_ENABLE_RTS_ENABLE:
		SET_BIT(L_CR3_Reg_Val_u32, USART_CR3_CTSE);
		SET_BIT(L_CR3_Reg_Val_u32, USART_CR3_RTSE);
		break;
	default :
		break;
	}

	/*Half Duplex configurations section.*/
	switch(Arg_conf_cpcUSART_Cfg->HalfDuplex){
	case USART_HALF_DUPLEX_DISABLE:
		/*It is default value, so no changes to L_CR3_Reg_Val_u32.*/
		break;

	case USART_HALF_DUPLEX_ENABLE:
		SET_BIT(L_CR3_Reg_Val_u32, USART_CR3_HDSEL);
		break;

	default :
		break;
	}

	/*Prescaller configurations section.*/
	USART_ID(Arg_conf_cpcUSART_Cfg->InstanceId)->GTPR = (Arg_conf_cpcUSART_Cfg->PrescalerValue) | (Arg_conf_cpcUSART_Cfg->PrescalerValue <<8);


	/*Baudrate configurations section. */
	/*Multiply*/
	u32 L_BaudRateCalculation;
	if (RCC_APB1 == RCC_GetPeripheralBus_u8((u32)USART_ID(Arg_conf_cpcUSART_Cfg->InstanceId))){
		L_BaudRateCalculation = RCC_GetAPB1PeripheralClockFrequency_f32()*1000000;
	}
	if (RCC_APB2 == RCC_GetPeripheralBus_u8((u32)USART_ID(Arg_conf_cpcUSART_Cfg->InstanceId))){
		L_BaudRateCalculation = RCC_GetAPB2PeripheralClockFrequency_f32()*1000000;
	}
	L_BaudRateCalculation += (Arg_conf_cpcUSART_Cfg->BaudRate/2U);
	L_BaudRateCalculation /= Arg_conf_cpcUSART_Cfg->BaudRate;

	USART_ID(Arg_conf_cpcUSART_Cfg->InstanceId)->BRR = L_BaudRateCalculation;




	USART_ID(Arg_conf_cpcUSART_Cfg->InstanceId)->CR1 = L_CR1_Reg_Val_u32;
	USART_ID(Arg_conf_cpcUSART_Cfg->InstanceId)->CR2 = L_CR2_Reg_Val_u32;
	USART_ID(Arg_conf_cpcUSART_Cfg->InstanceId)->CR3 = L_CR3_Reg_Val_u32;

}

void USART_EnableUSART_v(USART_Cfg const * const Arg_conf_cpcUSART_Cfg){
	SET_BIT(USART_ID(Arg_conf_cpcUSART_Cfg->InstanceId)->CR1, USART_CR1_UE); // Enable USART
	/*Wait till USART is enabled*/
	while(STD_FALSE == GET_BIT(USART_ID(Arg_conf_cpcUSART_Cfg->InstanceId)->CR1, USART_CR1_UE)){

	}
}

void USART_DisableUSART_v(USART_Cfg const * const Arg_conf_cpcUSART_Cfg){
	CLEAR_BIT(USART_ID(Arg_conf_cpcUSART_Cfg->InstanceId)->CR1, USART_CR1_UE); // Disable USART
	while(STD_TRUE == GET_BIT(USART_ID(Arg_conf_cpcUSART_Cfg->InstanceId)->CR1, USART_CR1_UE)){

	}
}

u8 USART_ReceiveU8Interrupt_u8(USART_Cfg const * const Arg_conf_cpcUSART_Cfg){
	return USART_ID(Arg_conf_cpcUSART_Cfg->InstanceId)->DR;
}

u8 USART_ReceiveU8Pooling_u8(
		USART_Cfg const * const Arg_conf_cpcUSART_Cfg, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32){

	Utils_TimeoutChecker L_timeout_Utils_TimeoutChecker;
	Utils_TimeoutChecker_Init(&L_timeout_Utils_TimeoutChecker, Arg_ToutVal_Cu32);

	u8 L_TimeoutCheckCondition_u8;

	while(STD_FALSE == GET_BIT(USART_ID(Arg_conf_cpcUSART_Cfg->InstanceId)->SR, USART_SR_RXNE)){
		L_TimeoutCheckCondition_u8 = Utils_IsTimeoutOccurred_u8(&L_timeout_Utils_TimeoutChecker);

		if ((STD_TRUE == L_TimeoutCheckCondition_u8) ){
			if (NULL != Arg_ToutErr_pCu32){
				*Arg_ToutErr_pCu32 = STD_TimeOutError;
			}

			break;
		}
		else if (STD_FALSE == L_TimeoutCheckCondition_u8){
			if (NULL != Arg_ToutErr_pCu32){
				*Arg_ToutErr_pCu32 = STD_NoTimeOutError;
			}
		}
		else{
		}

	}

	return USART_ID(Arg_conf_cpcUSART_Cfg->InstanceId)->DR;
}

u16 USART_ReceiveU16Pooling_u16(
		USART_Cfg const * const Arg_conf_cpcUSART_Cfg, const STD_EndianType Arg_EndianMode_CSTD_EndianType, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32){
	u16 L_ReceivedValue_u16 = 0;
	for (u8  L_i_u8 = 0; L_i_u8<2; L_i_u8++){
		u8 L_R_u8 = USART_ReceiveU8Pooling_u8(
				Arg_conf_cpcUSART_Cfg,
				Arg_ToutVal_Cu32,
				Arg_ToutErr_pCu32);
		if (STD_LittleEndian == Arg_EndianMode_CSTD_EndianType){
			L_ReceivedValue_u16 |= L_R_u8<<(8*L_i_u8);
		}
		else if (STD_BigEndian == Arg_EndianMode_CSTD_EndianType){
			L_ReceivedValue_u16 |= L_R_u8<<(8*(1-L_i_u8));
		}
		else{

		}
	}
	return L_ReceivedValue_u16;
}

u32 USART_ReceiveU32Pooling_u32(
		USART_Cfg const * const Arg_conf_cpcUSART_Cfg, const STD_EndianType Arg_EndianMode_CSTD_EndianType, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32 ){
	u32 L_ReceivedValue_u32 = 0;
	for (u8  L_i_u8 = 0; L_i_u8<4; L_i_u8++){
		u8 L_R_u8 = USART_ReceiveU8Pooling_u8(
				Arg_conf_cpcUSART_Cfg,
				Arg_ToutVal_Cu32,
				Arg_ToutErr_pCu32);
		if (STD_LittleEndian == Arg_EndianMode_CSTD_EndianType){
			L_ReceivedValue_u32 |= L_R_u8<<((8*L_i_u8));
		}
		else if (STD_BigEndian == Arg_EndianMode_CSTD_EndianType){
			L_ReceivedValue_u32 |= L_R_u8<<(8*(3-L_i_u8));
		}
		else{

		}
	}
	return L_ReceivedValue_u32;
}

u64 USART_ReceiveU64Pooling_u64(
		USART_Cfg const * const Arg_conf_cpcUSART_Cfg, const STD_EndianType Arg_EndianMode_CSTD_EndianType, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32 ){
	u64 L_ReceivedValue_u64 = 0;
	for (u8  L_i_u8 = 0; L_i_u8<8; L_i_u8++){
		u8 L_R_u8 = USART_ReceiveU8Pooling_u8(
				Arg_conf_cpcUSART_Cfg,
				Arg_ToutVal_Cu32,
				Arg_ToutErr_pCu32);

		if (STD_LittleEndian == Arg_EndianMode_CSTD_EndianType){
			L_ReceivedValue_u64 |= L_R_u8<<(8*L_i_u8);
		}
		else if (STD_BigEndian == Arg_EndianMode_CSTD_EndianType){
			L_ReceivedValue_u64 |= L_R_u8<<(8*(7-L_i_u8));
		}
		else{
			/*Error*/
		}
	}
	return L_ReceivedValue_u64;
}

void USART_SendU8Pooling_v(
		USART_Cfg const * const Arg_conf_cpcUSART_Cfg, u8 Arg_Data_u8, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32){

	Utils_TimeoutChecker L_timeout_Utils_TimeoutChecker;
	Utils_TimeoutChecker_Init(&L_timeout_Utils_TimeoutChecker, Arg_ToutVal_Cu32);

	u8 L_TimeoutCheckCondition_u8;
	L_TimeoutCheckCondition_u8 = Utils_IsTimeoutOccurred_u8(&L_timeout_Utils_TimeoutChecker);
	while(STD_FALSE == GET_BIT(USART_ID(Arg_conf_cpcUSART_Cfg->InstanceId)->SR, USART_SR_TXE)){
		if ((STD_TRUE == L_TimeoutCheckCondition_u8) ){
			if (NULL != Arg_ToutErr_pCu32){
				*Arg_ToutErr_pCu32 = STD_TimeOutError;
				return;
			}

			break;
		}
		else if (STD_FALSE == L_TimeoutCheckCondition_u8){
			if (NULL != Arg_ToutErr_pCu32){
				*Arg_ToutErr_pCu32 = STD_NoTimeOutError;
			}
		}
		else{
		}

	}
	USART_ID(Arg_conf_cpcUSART_Cfg->InstanceId)->DR  = Arg_Data_u8;
}






void USART_SendU16Pooling_v(
		USART_Cfg const * const Arg_conf_cpcUSART_Cfg,
		u16 Arg_Data_u16,
		const STD_EndianType Arg_EndianMode_CSTD_EndianType,
		const u32 Arg_ToutVal_Cu32,
		u32 * const Arg_ToutErr_pCu32){
	for (u8 L_i_u8 = 0; L_i_u8<2; L_i_u8++){
		if (STD_LittleEndian == Arg_EndianMode_CSTD_EndianType){
			USART_SendU8Pooling_v(
					Arg_conf_cpcUSART_Cfg,
					((Arg_Data_u16>>(8*L_i_u8))&0xFF),
					Arg_ToutVal_Cu32,
					Arg_ToutErr_pCu32);
		}
		else if (STD_BigEndian== Arg_EndianMode_CSTD_EndianType){
			USART_SendU8Pooling_v(
					Arg_conf_cpcUSART_Cfg,
					((Arg_Data_u16>>(8*(1-L_i_u8)))&0xFF),
					Arg_ToutVal_Cu32,
					Arg_ToutErr_pCu32);
		}
		else{

		}

	}
}



void USART_SendU32Pooling_v(
		USART_Cfg const * const Arg_conf_cpcUSART_Cfg,
		u32 Arg_Data_u32,
		const STD_EndianType Arg_EndianMode_CSTD_EndianType,
		const u32 Arg_ToutVal_Cu32,
		u32 * const Arg_ToutErr_pCu32){
	for (u8 L_i_u8 = 0; L_i_u8<4; L_i_u8++){
		if (STD_LittleEndian == Arg_EndianMode_CSTD_EndianType){
			USART_SendU8Pooling_v(
					Arg_conf_cpcUSART_Cfg,
					((Arg_Data_u32>>(8*L_i_u8))&0xFF),
					Arg_ToutVal_Cu32,
					Arg_ToutErr_pCu32);
		}
		else if (STD_BigEndian== Arg_EndianMode_CSTD_EndianType){
			USART_SendU8Pooling_v(
					Arg_conf_cpcUSART_Cfg,
					((Arg_Data_u32>>(8*(3-L_i_u8)))&0xFF),
					Arg_ToutVal_Cu32,
					Arg_ToutErr_pCu32);
		}
		else{
			/*Error*/
		}

	}
}



void USART_SendU64Pooling_v(
		USART_Cfg const * const Arg_conf_cpcUSART_Cfg,
		u64 Arg_Data_u64,
		const STD_EndianType Arg_EndianMode_CSTD_EndianType,
		const u32 Arg_ToutVal_Cu32,
		u32 * const Arg_ToutErr_pCu32){
	for (u8 L_i_u8 = 0; L_i_u8<8; L_i_u8++){
		if (STD_LittleEndian == Arg_EndianMode_CSTD_EndianType){
			USART_SendU8Pooling_v(
					Arg_conf_cpcUSART_Cfg,
					((Arg_Data_u64>>(8*L_i_u8))&0xFF),
					Arg_ToutVal_Cu32,
					Arg_ToutErr_pCu32);
		}
		else if (STD_BigEndian == Arg_EndianMode_CSTD_EndianType){
			USART_SendU8Pooling_v(
					Arg_conf_cpcUSART_Cfg,
					((Arg_Data_u64>>(8*(7-L_i_u8)))&0xFF),
					Arg_ToutVal_Cu32,
					Arg_ToutErr_pCu32);
		}
		else{
			/*Error*/
		}
	}
}



void USART_ReceiveU8ArrayPooling_v(
		USART_Cfg const * const Arg_conf_cpcUSART_Cfg, u8 *Arg_Arr_pu8, u32 Arg_ArrLen_u32, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32){
	for (u32 L_i_u32 = 0;L_i_u32 < Arg_ArrLen_u32;L_i_u32++){
		Arg_Arr_pu8[L_i_u32] = USART_ReceiveU8Pooling_u8(Arg_conf_cpcUSART_Cfg, Arg_ToutVal_Cu32, Arg_ToutErr_pCu32);
	}
}

void USART_ReceiveU16ArrayPooling_v(
		USART_Cfg const * const Arg_conf_cpcUSART_Cfg, u16 *Arg_Arr_pu16, u32 Arg_ArrLen_u32, const STD_EndianType Arg_EndianMode_CSTD_EndianType, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32 ){
	for (u32 L_i_u32 = 0;L_i_u32 < Arg_ArrLen_u32;L_i_u32++){
		Arg_Arr_pu16[L_i_u32] = USART_ReceiveU16Pooling_u16( Arg_conf_cpcUSART_Cfg, Arg_EndianMode_CSTD_EndianType, Arg_ToutVal_Cu32, Arg_ToutErr_pCu32);
	}
}


void USART_ReceiveU32ArrayPooling_v(
		USART_Cfg const * const Arg_conf_cpcUSART_Cfg, u32 *Arg_Arr_pu32, u32 Arg_ArrLen_u32, const STD_EndianType Arg_EndianMode_CSTD_EndianType, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32 ){
	for (u32 L_i_u32 = 0;L_i_u32 < Arg_ArrLen_u32;L_i_u32++){
		Arg_Arr_pu32[L_i_u32] = USART_ReceiveU32Pooling_u32(Arg_conf_cpcUSART_Cfg, Arg_EndianMode_CSTD_EndianType, Arg_ToutVal_Cu32, Arg_ToutErr_pCu32);
	}
}


void USART_ReceiveU64ArrayPooling_v(
		USART_Cfg const * const Arg_conf_cpcUSART_Cfg, u64 *Arg_Arr_pu64, u32 Arg_ArrLen_u32, const STD_EndianType Arg_EndianMode_CSTD_EndianType, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32){
	for (u32 L_i_u32 = 0;L_i_u32 < Arg_ArrLen_u32;L_i_u32++){
		Arg_Arr_pu64[L_i_u32] = USART_ReceiveU64Pooling_u64(Arg_conf_cpcUSART_Cfg, Arg_EndianMode_CSTD_EndianType, Arg_ToutVal_Cu32, Arg_ToutErr_pCu32);
	}
}


void USART_SendU8ArrayPooling_v(
		USART_Cfg const * const Arg_conf_cpcUSART_Cfg, u8 *Arg_Arr_pu8, u32 Arg_ArrLen_u32, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32){
	for (u32 L_i_u32 = 0;L_i_u32 < Arg_ArrLen_u32;L_i_u32++){
		USART_SendU8Pooling_v(Arg_conf_cpcUSART_Cfg, Arg_Arr_pu8[L_i_u32], Arg_ToutVal_Cu32, Arg_ToutErr_pCu32);
	}
}

void USART_SendU16ArrayPooling_v(
		USART_Cfg const * const Arg_conf_cpcUSART_Cfg, u16 *Arg_Arr_pu16, u32 Arg_ArrLen_u32, const STD_EndianType Arg_EndianMode_CSTD_EndianType, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32){
	for (u32 L_i_u32 = 0;L_i_u32 < Arg_ArrLen_u32;L_i_u32++){
		USART_SendU16Pooling_v(Arg_conf_cpcUSART_Cfg, Arg_Arr_pu16[L_i_u32], Arg_EndianMode_CSTD_EndianType, Arg_ToutVal_Cu32, Arg_ToutErr_pCu32);
	}
}

void USART_SendU32ArrayPooling_v(
		USART_Cfg const * const Arg_conf_cpcUSART_Cfg, u32 *Arg_Arr_pu32, u32 Arg_ArrLen_u32, const STD_EndianType Arg_EndianMode_CSTD_EndianType, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32){
	for (u32 L_i_u32 = 0;L_i_u32 < Arg_ArrLen_u32;L_i_u32++){
		USART_SendU32Pooling_v(Arg_conf_cpcUSART_Cfg, Arg_Arr_pu32[L_i_u32], Arg_EndianMode_CSTD_EndianType, Arg_ToutVal_Cu32, Arg_ToutErr_pCu32);
	}
}

void USART_SendU64ArrayPooling_v(
		USART_Cfg const * const Arg_conf_cpcUSART_Cfg, u64 *Arg_Arr_pu64, u32 Arg_ArrLen_u32, const STD_EndianType Arg_EndianMode_CSTD_EndianType, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32){

	for (u32 L_i_u32 = 0;L_i_u32 < Arg_ArrLen_u32;L_i_u32++){
		USART_SendU64Pooling_v(Arg_conf_cpcUSART_Cfg, Arg_Arr_pu64[L_i_u32], Arg_EndianMode_CSTD_EndianType, Arg_ToutVal_Cu32, Arg_ToutErr_pCu32);
	}
}

u32 USART_GetAdressForDMA_u32(USART_Cfg const * const Arg_conf_cpcUSART_Cfg){
	return (u32)&USART_ID(Arg_conf_cpcUSART_Cfg->InstanceId)->DR;
}


Bool USART_CheckInterruptAndClear_Bool(u8 Arg_USARTInstanceId_u8, u8 Arg_USARTInterruptType_u8){
	switch (Arg_USARTInterruptType_u8){

	/*USART_INTERRUPT_TRANSMIT_DATA_EMPTY*/
	case 0:
		if (STD_TRUE == GET_BIT(USART_ID(Arg_USARTInstanceId_u8)->SR, USART_SR_TXE)){

			return STD_TRUE;
		}
		else{
			return STD_FALSE;
		}
		break;

		/*USART_INTERRUPT_TRANSMIT_COMPLETE*/
	case 1:
		if (STD_TRUE == GET_BIT(USART_ID(Arg_USARTInstanceId_u8)->SR, USART_SR_TC)){
			CLEAR_BIT(USART_ID(Arg_USARTInstanceId_u8)->SR, USART_SR_TC);
			return STD_TRUE;
		}
		else{
			return STD_FALSE;
		}
		break;

		/*USART_INTERRUPT_READ_DATA_REGISTER_NOT_EMPTY*/
	case 2:
		if (STD_TRUE == GET_BIT(USART_ID(Arg_USARTInstanceId_u8)->SR, USART_SR_RXNE)){
			CLEAR_BIT(USART_ID(Arg_USARTInstanceId_u8)->SR, USART_SR_RXNE);
			return STD_TRUE;
		}
		else{
			return STD_FALSE;
		}
		break;
		/*USART_INTERRUPT_IDLE_LINE_DETECTED*/
	case 3:
		if (STD_TRUE == GET_BIT(USART_ID(Arg_USARTInstanceId_u8)->SR, USART_SR_IDLE)){
			return STD_TRUE;
		}
		else{
			return STD_FALSE;
		}
		break;
		/*USART_INTERRUPT_CTS*/
	case 4:
		if (STD_TRUE == GET_BIT(USART_ID(Arg_USARTInstanceId_u8)->SR, USART_SR_CTS)){

			return STD_TRUE;
		}
		else{
			return STD_FALSE;
		}
		break;

		/*USART_INTERRUPT_ERROR*/
	case 5:
		/*Not Implemented yet !*/
		break;

		/*USART_INTERRUPT_OVERRUN_ERROR*/
	case 6:
		if (STD_TRUE == GET_BIT(USART_ID(Arg_USARTInstanceId_u8)->SR, USART_SR_ORE)){
			return STD_TRUE;
		}
		else{
			return STD_FALSE;
		}
		break;

		/*USART_INTERRUPT_NOISE_DETECTED*/
	case 7:
		if (STD_TRUE == GET_BIT(USART_ID(Arg_USARTInstanceId_u8)->SR, USART_SR_NF)){
			return STD_TRUE;
		}
		else{
			return STD_FALSE;
		}
		break;

		/*USART_INTERRUPT_FRAME_ERROR*/
	case 8:
		if (STD_TRUE == GET_BIT(USART_ID(Arg_USARTInstanceId_u8)->SR, USART_SR_FE)){
			return STD_TRUE;
		}
		else{
			return STD_FALSE;
		}
		break;

		/*USART_INTERRUPT_PARITY_ERROR*/
	case 9:
		if (STD_TRUE == GET_BIT(USART_ID(Arg_USARTInstanceId_u8)->SR, USART_SR_PE)){
			return STD_TRUE;
		}
		else{
			return STD_FALSE;
		}
		break;

	}

	return STD_FALSE;
}

void USART_Reset_v (USART_Cfg const * const Arg_conf_cpcUSART_Cfg){

	USART_Cfg L_usart_USART_Cfg = {0};
	L_usart_USART_Cfg.GPIOInstanceId = Arg_conf_cpcUSART_Cfg->GPIOInstanceId;
	L_usart_USART_Cfg.GPIOPins = Arg_conf_cpcUSART_Cfg->GPIOPins;
	L_usart_USART_Cfg.InstanceId = Arg_conf_cpcUSART_Cfg->InstanceId;
	USART_Config_v(&L_usart_USART_Cfg);

	/*GPIO that will be used with USART peripheral.*/
	GPIO_Cfg L_usartGPIO_GPIO_Cfg = {0};
	L_usartGPIO_GPIO_Cfg.InstanceId = Arg_conf_cpcUSART_Cfg->GPIOInstanceId;
	L_usartGPIO_GPIO_Cfg.PINs = Arg_conf_cpcUSART_Cfg->GPIOPins;


	for (u8 L_i_u8 = 0; L_i_u8<16; L_i_u8++){
		if (STD_TRUE == GET_BIT(Arg_conf_cpcUSART_Cfg->GPIOPins, L_i_u8)){
			GPIO_MapGPIOPIN_v(&L_usartGPIO_GPIO_Cfg, L_i_u8, 0);
		}
	}
	GPIO_Reset_v(&L_usartGPIO_GPIO_Cfg);

	/*Disable USART clock*/
	USART_DisableUSART_v(Arg_conf_cpcUSART_Cfg);

}
/*
==================================================
  End Section --> Functions implementation.
==================================================
 */

