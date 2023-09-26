/*
 * File Name --> SPI.c
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> SPI driver implementation.
 * */


/*
==================================================
  Start Section --> File Includes
==================================================
 */
#include "SPI.h"
#include "SPI_Private.h"
#include "HMCAL/RCC/RCC.h"
#include "HMCAL/GPIO/GPIO.h"
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
#define SPI_ID(id) ((volatile SPI_MemMap*const)(GCS_SPI_InstanceIdMapping_u32[((id)-1)]))
/*
==================================================
  End   Section --> Macro to map Instance Id with it's physical address.
==================================================
 */

/*
==================================================
  Start Section --> Functions implemetation.
==================================================
 */

void SPI_Config_v(SPI_Cfg const * const Arg_conf_cpcSPI_Cfg){

	/*GPIO that will be used with USART peripheral.*/
	GPIO_Cfg L_spiGPIO_GPIO_Cfg = {0};
	L_spiGPIO_GPIO_Cfg.InstanceId = Arg_conf_cpcSPI_Cfg->GPIOInstanceId;
	L_spiGPIO_GPIO_Cfg.Mode = GPIO_MODE_ALTERNATE_FUNCTION;
	L_spiGPIO_GPIO_Cfg.PINs = Arg_conf_cpcSPI_Cfg->GPIOPins;
	L_spiGPIO_GPIO_Cfg.OutputSpeed = GPIO_OUTPUT_SPEED_HIGH;
	L_spiGPIO_GPIO_Cfg.OutputType = GPIO_OUTPUT_TYPE_PUSH_PULL;
	L_spiGPIO_GPIO_Cfg.PullUpPullDownResistor = GPIO_RESISTOR_NO_PULL;


	/*Mapping USART with it's corresponding alternate function number.*/
	u8 L_SPIMappingPins[] = {
			SPI1_MAP_PIN,
			SPI2_MAP_PIN,
			SPI3_MAP_PIN,
	};

	for (u8 L_i_u8 = 0; L_i_u8<16; L_i_u8++){
		if (STD_TRUE == GET_BIT(Arg_conf_cpcSPI_Cfg->GPIOPins, L_i_u8)){
			GPIO_MapGPIOPIN_v(&L_spiGPIO_GPIO_Cfg,
					L_i_u8,
					L_SPIMappingPins[Arg_conf_cpcSPI_Cfg->InstanceId-1]);
		}
	}

	/*Configure pin that will be used with USART*/
	GPIO_Config_v(&L_spiGPIO_GPIO_Cfg);

	/*
	 * To reduce the headache on user of enabling clock of the used peripheral.
	 * It 's automatically enabled before configuring the peripheral by
	 * 1. Get the bus which is connected to peripheral by passing the address of any peripheral register
	 * to RCC_GetPeripheralBus_u8
	 * 2. Get the corresponding bit number of peripheral on it's but through RCC_GetRCCUSARTBit_u8
	 * by passing instance id of USART peripheral.
	 * */

	RCC_EnableClock_v(
			RCC_GetPeripheralBus_u8((u32)SPI_ID(Arg_conf_cpcSPI_Cfg->InstanceId)),
			RCC_GetRCCSPIBit_u8(Arg_conf_cpcSPI_Cfg->InstanceId));

	u32 L_CR1_Reg_Val_u32 = SPI_CR1_RESET_VALUE;
	u32 L_CR2_Reg_Val_u32 = SPI_CR2_RESET_VALUE;
	u32 L_SR_Reg_Val_u32 = SPI_SR_RESET_VALUE;
	u32 L_CRCPR_Reg_Val_u32 = SPI_CRCPR_RESET_VALUE;

	u32 L_RXCRCR_Reg_Val_u32 = SPI_RXCRCR_RESET_VALUE;
	u32 L_TXCRCR_Reg_Val_u32 = SPI_TXCRCR_RESET_VALUE;

	u32 L_I2SCFGR_Reg_Val_u32 = SPI_I2SCFGR_RESET_VALUE;
	u32 L_I2SPR_Reg_Val_u32 = SPI_I2SPR_RESET_VALUE;
	/*Reset registers*/


	/* SPI Direction configurations section. */
	switch (Arg_conf_cpcSPI_Cfg->Direction){
	case SPI_DIRECTION_UNIDIRECTIONAL:
		CLEAR_BIT(L_CR1_Reg_Val_u32, SPI_CR1_BIDIMODE);
		break;

	case SPI_DIRECTION_RECEIVE_ONLY_BIDIRECTIONAL:
		/*In Master Mode MOSI pin is used while MISO pin is used in slave mode.*/
		SET_BIT(L_CR1_Reg_Val_u32, SPI_CR1_BIDIMODE);
		CLEAR_BIT(L_CR1_Reg_Val_u32, SPI_CR1_BIDIOE);
		break;
	case SPI_DIRECTION_TRANSMIT_ONLY_BIDIRECTIONAL:
		/*In Master Mode MOSI pin is used while MISO pin is used in slave mode.*/
		SET_BIT(L_CR1_Reg_Val_u32, SPI_CR1_BIDIMODE);
		SET_BIT(L_CR1_Reg_Val_u32, SPI_CR1_BIDIOE);
		break;
	default:

		break;
	}
	/* SPI CRC configurations section. */
	switch (Arg_conf_cpcSPI_Cfg->CRC){
	case SPI_CRC_DISABLE:
		CLEAR_BIT(L_CR1_Reg_Val_u32, SPI_CR1_CRCEN);
		break;

	case SPI_CRC_ENABLE:
		SET_BIT(L_CR1_Reg_Val_u32, SPI_CR1_CRCEN);
		break;
	default:

		break;
	}
	/* SPI Capture Strobe configurations section. */
	switch (Arg_conf_cpcSPI_Cfg->CaptureStrobe){
	case SPI_CAPTURE_STROBE_IDLE_CLK_LOW_RISING:
		CLEAR_BIT(L_CR1_Reg_Val_u32, SPI_CR1_CPOL);
		CLEAR_BIT(L_CR1_Reg_Val_u32, SPI_CR1_CPHA);
		break;
	case SPI_CAPTURE_STROBE_IDLE_CLK_HIGH_RISING:
		SET_BIT(L_CR1_Reg_Val_u32, SPI_CR1_CPOL);
		SET_BIT(L_CR1_Reg_Val_u32, SPI_CR1_CPHA);
		break;
	case SPI_CAPTURE_STROBE_IDLE_CLK_HIGH_FALLING:
		SET_BIT(L_CR1_Reg_Val_u32, SPI_CR1_CPOL);
		CLEAR_BIT(L_CR1_Reg_Val_u32, SPI_CR1_CPHA);
		break;
	case SPI_CAPTURE_STROBE_IDLE_CLK_LOW_FALLING:
		CLEAR_BIT(L_CR1_Reg_Val_u32, SPI_CR1_CPOL);
		SET_BIT(L_CR1_Reg_Val_u32, SPI_CR1_CPHA);
		break;
	default:

		break;
	}

	/* SPI Frame Size configurations section. */
	switch (Arg_conf_cpcSPI_Cfg->FrameSize){
	case SPI_FRAME_SIZE_8_BITS_MSB_First:
		CLEAR_BIT(L_CR1_Reg_Val_u32, SPI_CR1_DFF);
		CLEAR_BIT(L_CR1_Reg_Val_u32, SPI_CR1_LSBFIRST);
		break;
	case SPI_FRAME_SIZE_8_BITS_LSB_First:
		CLEAR_BIT(L_CR1_Reg_Val_u32, SPI_CR1_DFF);
		SET_BIT(L_CR1_Reg_Val_u32, SPI_CR1_LSBFIRST);
		break;

	case SPI_FRAME_SIZE_16_BITS_MSB_First:
		SET_BIT(L_CR1_Reg_Val_u32, SPI_CR1_DFF);
		CLEAR_BIT(L_CR1_Reg_Val_u32, SPI_CR1_LSBFIRST);
		break;
	case SPI_FRAME_SIZE_16_BITS_LSB_First:
		SET_BIT(L_CR1_Reg_Val_u32, SPI_CR1_DFF);
		SET_BIT(L_CR1_Reg_Val_u32, SPI_CR1_LSBFIRST);
		break;
	default:

		break;
	}

	/* SPI State configurations section.  */
	switch (Arg_conf_cpcSPI_Cfg->State){
	case SPI_STATE_MASTER:
		SET_BIT(L_CR1_Reg_Val_u32, SPI_CR1_MSTR);
		SET_BIT(SPI_ID(Arg_conf_cpcSPI_Cfg->InstanceId)->CR2, SPI_CR2_SSOE);
		break;
	case SPI_STATE_SLAVE:
		CLEAR_BIT(L_CR1_Reg_Val_u32, SPI_CR1_MSTR);
		break;
	default:

		break;
	}

	/*SPI Clock Prescaler configurations section.*/
	L_CR1_Reg_Val_u32 |= (Arg_conf_cpcSPI_Cfg->ClockPrescaler <<SPI_CR1_BR_0);

	/*CHECK AGAIN. */
	SET_BIT(L_CR1_Reg_Val_u32,SPI_CR1_SSI);
	SET_BIT(L_CR1_Reg_Val_u32,SPI_CR1_SSM);

	/* Interupt configurations section. */
	if (Arg_conf_cpcSPI_Cfg->Interrupt & SPI_INTERRUPT_TX_EMPTY){
		SET_BIT(L_CR2_Reg_Val_u32, SPI_CR2_TXEIE);
	}
	if (Arg_conf_cpcSPI_Cfg->Interrupt & SPI_INTERRUPT_RX_NON_EMPTY){
		SET_BIT(L_CR2_Reg_Val_u32, SPI_CR2_RXNEIE);
	}
	if (Arg_conf_cpcSPI_Cfg->Interrupt & SPI_INTERRUPT_ERROR){
		SET_BIT(L_CR2_Reg_Val_u32, SPI_CR2_ERRIE);
	}


	SPI_ID(Arg_conf_cpcSPI_Cfg->InstanceId)->CR1 = L_CR1_Reg_Val_u32;
	SPI_ID(Arg_conf_cpcSPI_Cfg->InstanceId)->CR2 = L_CR2_Reg_Val_u32;
	SPI_ID(Arg_conf_cpcSPI_Cfg->InstanceId)->SR = L_SR_Reg_Val_u32;

	SPI_ID(Arg_conf_cpcSPI_Cfg->InstanceId)->CRCPR = L_CRCPR_Reg_Val_u32;
	SPI_ID(Arg_conf_cpcSPI_Cfg->InstanceId)->RXCRCR = L_RXCRCR_Reg_Val_u32;
	SPI_ID(Arg_conf_cpcSPI_Cfg->InstanceId)->TXCRCR = L_TXCRCR_Reg_Val_u32;
	SPI_ID(Arg_conf_cpcSPI_Cfg->InstanceId)->I2SCFGR = L_I2SCFGR_Reg_Val_u32;
	SPI_ID(Arg_conf_cpcSPI_Cfg->InstanceId)->I2SPR = L_I2SPR_Reg_Val_u32;


}


void SPI_Sendu8Data_v(SPI_Cfg const * const Arg_conf_cpcSPI_Cfg, u8 Arg_data_u8){
	while(!GET_BIT(SPI_ID(Arg_conf_cpcSPI_Cfg->InstanceId)->SR, SPI_SR_TXE));
	SPI_ID(Arg_conf_cpcSPI_Cfg->InstanceId)->DR = Arg_data_u8;
	while(GET_BIT(SPI_ID(Arg_conf_cpcSPI_Cfg->InstanceId)->SR, SPI_SR_BSY));

}

void SPI_Sendu16Data_v(SPI_Cfg const * const Arg_conf_cpcSPI_Cfg, u16 Arg_data_u16){
	while(!GET_BIT(SPI_ID(Arg_conf_cpcSPI_Cfg->InstanceId)->SR, SPI_SR_TXE));
	SPI_ID(Arg_conf_cpcSPI_Cfg->InstanceId)->DR = Arg_data_u16;
	while(GET_BIT(SPI_ID(Arg_conf_cpcSPI_Cfg->InstanceId)->SR, SPI_SR_BSY));

}

void SPI_ChangeDataFrameFormatTo16Bit_v(SPI_Cfg const * const Arg_conf_cpcSPI_Cfg){
	Bool L_IsActive_Bool = SPI_IsEnabled_Bool(Arg_conf_cpcSPI_Cfg);

	if (STD_TRUE == L_IsActive_Bool){
		SPI_DisableSPI_v(Arg_conf_cpcSPI_Cfg);
	}


	SET_BIT(SPI_ID(Arg_conf_cpcSPI_Cfg->InstanceId)->CR1, SPI_CR1_DFF);
	if (STD_TRUE == L_IsActive_Bool){
		SPI_EnableSPI_v(Arg_conf_cpcSPI_Cfg);
	}

}

void SPI_ChangeDataFrameFormatTo8Bit_v(SPI_Cfg const * const Arg_conf_cpcSPI_Cfg){
	Bool L_IsActive_Bool = SPI_IsEnabled_Bool(Arg_conf_cpcSPI_Cfg);

	if (STD_TRUE == L_IsActive_Bool){
		SPI_DisableSPI_v(Arg_conf_cpcSPI_Cfg);
	}

	SPI_DisableSPI_v(Arg_conf_cpcSPI_Cfg);


	CLEAR_BIT(SPI_ID(Arg_conf_cpcSPI_Cfg->InstanceId)->CR1, SPI_CR1_DFF);
	if (STD_TRUE == L_IsActive_Bool){
		SPI_EnableSPI_v(Arg_conf_cpcSPI_Cfg);
	}

}

u8 SPI_Receiveu8Data_v(SPI_Cfg const * const Arg_conf_cpcSPI_Cfg){
	u8 Local_data_u8;
	while(!GET_BIT(SPI_ID(Arg_conf_cpcSPI_Cfg->InstanceId)->SR, SPI_SR_RXNE));
	Local_data_u8 =  SPI_ID(Arg_conf_cpcSPI_Cfg->InstanceId)->DR;
	return Local_data_u8;
}

u8 SPI_SendAndReceive_u8(SPI_Cfg const * const Arg_conf_cpcSPI_Cfg, u8 Arg_data_u8){
	SPI_ID(Arg_conf_cpcSPI_Cfg->InstanceId)->DR = Arg_data_u8;
	while(GET_BIT(SPI_ID(Arg_conf_cpcSPI_Cfg->InstanceId)->SR, SPI_SR_BSY));
	Arg_data_u8 = SPI_ID(Arg_conf_cpcSPI_Cfg->InstanceId)->DR;
	return Arg_data_u8;
}

u16 SPI_SendAndReceive_u16(SPI_Cfg const * const Arg_conf_cpcSPI_Cfg, u8 Arg_data_u16){
	/*Receive*/
	while(!GET_BIT(SPI_ID(Arg_conf_cpcSPI_Cfg->InstanceId)->SR, SPI_SR_TXE));
	SPI_ID(Arg_conf_cpcSPI_Cfg->InstanceId)->DR = Arg_data_u16;
	/*Send*/
	while(!GET_BIT(SPI_ID(Arg_conf_cpcSPI_Cfg->InstanceId)->SR, SPI_SR_RXNE));
	return Arg_data_u16;
}

Bool SPI_IsEnabled_Bool(SPI_Cfg const * const Arg_conf_cpcSPI_Cfg){

	return GET_BIT(SPI_ID(Arg_conf_cpcSPI_Cfg->InstanceId)->CR1, SPI_CR1_SPE);
}

void SPI_EnableSPI_v(SPI_Cfg const * const Arg_conf_cpcSPI_Cfg){
	SET_BIT(SPI_ID(Arg_conf_cpcSPI_Cfg->InstanceId)->CR1, SPI_CR1_SPE);
	while(STD_LOW == GET_BIT(SPI_ID(Arg_conf_cpcSPI_Cfg->InstanceId)->CR1, SPI_CR1_SPE));
}

void SPI_DisableSPI_v(SPI_Cfg const * const Arg_conf_cpcSPI_Cfg){
	CLEAR_BIT(SPI_ID(Arg_conf_cpcSPI_Cfg->InstanceId)->CR1, SPI_CR1_SPE);
	while(STD_HIGH == GET_BIT(SPI_ID(Arg_conf_cpcSPI_Cfg->InstanceId)->CR1, SPI_CR1_SPE));
}
/*
==================================================
  End   Section --> Functions implementation.
==================================================
 */

