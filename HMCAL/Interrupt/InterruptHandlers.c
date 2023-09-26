/*
 * File Name --> InterruptHandlers.c
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> Interrupt handler implementation for all HMCAL peripherals.
 * */


/*
==================================================
  Start Section --> File Includes
==================================================
 */
#include "InterruptHandlers.h"
#include "HMCAL/SYSCFG/SYSCFG.h"
#include "HMCAL/DMA/DMA.h"
#include "HMCAL/USART/USART.h"
#include "HMCAL/EXTI/EXTI.h"

/*
==================================================
  End   Section --> File Includes
==================================================
 */

#define DMA_INTERRUPT_FLAG_NUMs					7
#define DMA_INTERRUPT_STREAMS					7
#define DMA_INSTANCES_MAX_NUMs					2

#define USART_INSTANCES_MAX_NUMs				6
#define USART_INTERRUPTS_TYPES_NUMs				10

/*
==================================================
  Start Section --> Functions implementation.
==================================================
 */
#define DMA_HANDLER(DMA_INSTANCE_ID, STREAM_ID) 	for (u8 L_InterruptFlag_u8 = 0; L_InterruptFlag_u8<DMA_INTERRUPT_FLAG_NUMs; L_InterruptFlag_u8++){ \
		if (1==L_InterruptFlag_u8){ \
			continue; \
		} \
		if (STD_TRUE == DMA_CheckInterruptAndClear_Bool(DMA_INSTANCE_ID, STREAM_ID, L_InterruptFlag_u8)){ \
			if (NULL != GS_DMA_CallBacks_pF[DMA_INSTANCE_ID-1][STREAM_ID][L_InterruptFlag_u8]){ \
				GS_DMA_CallBacks_pF[DMA_INSTANCE_ID-1][STREAM_ID][L_InterruptFlag_u8](); \
			} \
			else{ \
			} \
		} \
		else{ \
		} \
}\


#define USART_HANDLER(USART_INSTANCE_ID) 	for (u8 L_InterruptType_u8 = 0; L_InterruptType_u8<USART_INTERRUPTS_TYPES_NUMs; L_InterruptType_u8++){ \
		if (STD_TRUE ==USART_CheckInterruptAndClear_Bool(USART_INSTANCE_ID, L_InterruptType_u8)){ \
			if (NULL != GS_USART_CallBacks_pF[USART_INSTANCE_ID-1][L_InterruptType_u8]){ \
				GS_USART_CallBacks_pF[USART_INSTANCE_ID-1][L_InterruptType_u8](); \
			} \
			else { \
			} \
		}\
}\

static void (*GS_EXTI_CallBacks_pF[8][16])(void);
/*DMA has 2 instances
 * With
 * 1. Error
 *
 * */
static void (*GS_DMA_CallBacks_pF[DMA_INSTANCES_MAX_NUMs][DMA_INTERRUPT_STREAMS][DMA_INTERRUPT_FLAG_NUMs])(void);

static void (*GS_USART_CallBacks_pF[USART_INSTANCES_MAX_NUMs][USART_INTERRUPTS_TYPES_NUMs])(void);

void InterruptHandler_Init_v(void){
	/*Init EXTI Interrupts*/
	for (u8 L_GPIO_u8 = 0;L_GPIO_u8<8;L_GPIO_u8++){
		for (u8 L_PIN_u8 = 0;L_PIN_u8<16;L_PIN_u8++){
			GS_EXTI_CallBacks_pF[L_GPIO_u8][L_PIN_u8] = NULL;
		}
	}

	/*DMA*/
	for (u8 L_DMAInstanceId_u8 = 0; L_DMAInstanceId_u8<DMA_INSTANCES_MAX_NUMs; L_DMAInstanceId_u8++){
		for (u8 L_DMAStreamId_u8 = 0; L_DMAStreamId_u8<=DMA_INTERRUPT_STREAMS; L_DMAStreamId_u8++){
			for (u8 L_DMAInterruptFlags_u8 = 0; L_DMAInterruptFlags_u8<DMA_INTERRUPT_FLAG_NUMs; L_DMAInterruptFlags_u8++){

				GS_DMA_CallBacks_pF[L_DMAInstanceId_u8][L_DMAStreamId_u8][L_DMAInterruptFlags_u8] = NULL;
			}
		}
	}

	/*USART*/
	for (u8 L_USARTInstanceId_u8 = 0; L_USARTInstanceId_u8<USART_INSTANCES_MAX_NUMs; L_USARTInstanceId_u8++){
		for (u8 L_USARTInterruptType_u8 = 0; L_USARTInterruptType_u8<USART_INTERRUPTS_TYPES_NUMs; L_USARTInterruptType_u8++){
			GS_USART_CallBacks_pF[L_USARTInstanceId_u8][L_USARTInterruptType_u8] = NULL;
		}
	}

}

void InterruptHandler_SetEXTIxCallback_void(u8 Arg_GPIOInstanceId_u8, u8 Arg_PinNumber_u8,void (*Arg_FunctionCallback_v)(void) ){
	u8 L_GPIOInstanceId_u8 = Arg_GPIOInstanceId_u8;

	/*
	 * GPIOA will have index 0 in L_GPIOid_u8 array
	 * So the following process check for the boundary of input value
	 * If input id exceeds the boundary an error will be issued.
	 * */
	if (('A' <= Arg_GPIOInstanceId_u8 ) && (Arg_GPIOInstanceId_u8 <= 'Z')){
		L_GPIOInstanceId_u8 -= 'A';
	}
	else if (('a' <= Arg_GPIOInstanceId_u8 ) && (Arg_GPIOInstanceId_u8 <= 'z')){
		L_GPIOInstanceId_u8 -= 'a';
	}
	else{
		/*Error*/

	}

	GS_EXTI_CallBacks_pF[L_GPIOInstanceId_u8][Arg_PinNumber_u8] = Arg_FunctionCallback_v;
}


void InterruptHandler_SetDMACallback_v(u8 Arg_DMAInstanceId_u8, u8 Arg_StreamNumber_u8,u8 Arg_InterruptFagNum_u8, void (*Arg_FunctionCallback_v)(void) ){
	for (u32 L_i_u32 = 0; L_i_u32<32 ;L_i_u32++){
		if (STD_TRUE == GET_BIT(Arg_InterruptFagNum_u8, L_i_u32)){
			GS_DMA_CallBacks_pF[Arg_DMAInstanceId_u8-1][Arg_StreamNumber_u8][L_i_u32] = Arg_FunctionCallback_v;
		}
	}

}


void InterruptHandler_SetUSARTCallback_v(u8 Arg_USARTInstanceId_u8, u8 Arg_InterruptType_u8, void (*Arg_FunctionCallback_v)(void) ){
	for (u32 L_i_u32 = 0; L_i_u32<32 ;L_i_u32++){
		if (STD_TRUE == GET_BIT(Arg_InterruptType_u8, L_i_u32)){
			GS_USART_CallBacks_pF[Arg_USARTInstanceId_u8-1][L_i_u32] = Arg_FunctionCallback_v;

		}
	}

}







void NMI_Handler(void){

}
void HardFault_Handler(void){

}
void MemManage_Handler(void){

}
void BusFault_Handler(void){

}
void UsageFault_Handler(void){

}
#if (CONFIG_USE_RTOS==CONFIG_NO_RTOS)
void SVC_Handler(void){
#if CONFIG_USE_SVC_INTERUPT	== 1
	if (InterruptHandler_SVCCallback_void != NULL){
		InterruptHandler_SVCCallback_void();
	}
#endif
}
#endif
void DebugMon_Handler(void){

}

#if (CONFIG_USE_RTOS==CONFIG_NO_RTOS)
void PendSV_Handler(void){

}
#endif

void WWDG_IRQHandler(void){
	/* Window Watchdog interrupt*/

}
void PVD_IRQHandler(void){
	/* PVD through EXTI line detection interrupt*/

}
void TAMP_STAMP_IRQHandler(void){
	/* Tamper and TimeStamp interrupts through the EXTI line*/

}
void RTC_WKUP_IRQHandler(void){
	/* RTC Wakeup interrupt through the EXTI line*/

}
void RCC_IRQHandler(void){
	/* RCC global interrupt*/

}

void EXTI0_IRQHandler (void){
	/* EXTI Line0 interrupt*/
	for (u8 L_i_u8 = 0; L_i_u8<16; L_i_u8++){
		if (STD_TRUE == EXTI_CheckInterrupt_Bool(L_i_u8)){
			if (NULL != GS_EXTI_CallBacks_pF[SYSCFG_GetActiveGPIO_u8(0)][L_i_u8]){
				GS_EXTI_CallBacks_pF[SYSCFG_GetActiveGPIO_u8(0)][L_i_u8]();
				EXTI_ClearInterrupt_v(L_i_u8);
			}
			else{

			}
		}
		else{

		}
	}
}
void EXTI1_IRQHandler(void){
	/* EXTI Line1 interrupt*/
	for (u8 L_i_u8 = 0; L_i_u8<16; L_i_u8++){
		if (STD_TRUE == EXTI_CheckInterrupt_Bool(L_i_u8)){
			if (NULL != GS_EXTI_CallBacks_pF[SYSCFG_GetActiveGPIO_u8(1)][L_i_u8]){
				GS_EXTI_CallBacks_pF[SYSCFG_GetActiveGPIO_u8(1)][L_i_u8]();
				EXTI_ClearInterrupt_v(L_i_u8);
			}
			else{

			}
		}
		else{

		}
	}
}
void EXTI2_IRQHandler(void){
	/* EXTI Line2 interrupt*/
	for (u8 L_i_u8 = 0; L_i_u8<16; L_i_u8++){
		if (STD_TRUE == EXTI_CheckInterrupt_Bool(L_i_u8)){
			if (NULL != GS_EXTI_CallBacks_pF[SYSCFG_GetActiveGPIO_u8(2)][L_i_u8]){
				GS_EXTI_CallBacks_pF[SYSCFG_GetActiveGPIO_u8(2)][L_i_u8]();
				EXTI_ClearInterrupt_v(L_i_u8);
			}
			else{

			}
		}
		else{

		}
	}
}
void EXTI3_IRQHandler(void){
	/* EXTI Line3 interrupt*/
	for (u8 L_i_u8 = 0; L_i_u8<16; L_i_u8++){
		if (STD_TRUE == EXTI_CheckInterrupt_Bool(L_i_u8)){
			if (NULL != GS_EXTI_CallBacks_pF[SYSCFG_GetActiveGPIO_u8(3)][L_i_u8]){
				GS_EXTI_CallBacks_pF[SYSCFG_GetActiveGPIO_u8(3)][L_i_u8]();
				EXTI_ClearInterrupt_v(L_i_u8);

			}
			else{

			}
		}
		else{

		}
	}
}
void EXTI4_IRQHandler (void){
	/* EXTI Line4 interrupt*/
	for (u8 L_i_u8 = 0; L_i_u8<16; L_i_u8++){
		if (STD_TRUE == EXTI_CheckInterrupt_Bool(L_i_u8)){
			if (NULL != GS_EXTI_CallBacks_pF[SYSCFG_GetActiveGPIO_u8(4)][L_i_u8]){
				GS_EXTI_CallBacks_pF[SYSCFG_GetActiveGPIO_u8(4)][L_i_u8]();
				EXTI_ClearInterrupt_v(L_i_u8);
			}
			else{

			}
		}
		else{

		}
	}
}

void DMA1_Stream0_IRQHandler(void){
	/* DMA1 Stream0 global interrupt*/
	DMA_HANDLER(1, 0);
}
void DMA1_Stream1_IRQHandler(void){
	/* DMA1 Stream1 global interrupt*/
	DMA_HANDLER(1, 1);
}
void DMA1_Stream2_IRQHandler(void){
	/* DMA1 Stream2 global interrupt*/
	DMA_HANDLER(1, 2);
}
void DMA1_Stream3_IRQHandler(void){
	/* DMA1 Stream3 global interrupt*/
	DMA_HANDLER(1, 3);
}
void DMA1_Stream4_IRQHandler(void){
	/* DMA1 Stream4 global interrupt*/
	DMA_HANDLER(1, 4);
}
void DMA1_Stream5_IRQHandler(void){
	/* DMA1 Stream5 global interrupt*/
	DMA_HANDLER(1, 5);
}
void DMA1_Stream6_IRQHandler(void){
	/* DMA1 Stream6 global interrupt*/
	DMA_HANDLER(1, 6);
}
void ADC_IRQHandler(void){
	/* ADC3 global interrupts*/
}

void CAN1_TX_IRQHandler(void){
	/* CAN1 TX interrupts*/

}
void CAN1_RX0_IRQHandler(void){
	/* CAN1 RX0 interrupts*/


}
void CAN1_RX1_IRQHandler(void){
	/* CAN1 RX1 interrupts*/
}
void CAN1_SCE_IRQHandler(void){
	/* CAN1 SCE interrupt*/

}
void EXTI9_5_IRQHandler(void){
	/* EXTI Line[9:5] interrupts*/

	for (u8 L_EXTILine_u8 = 5;L_EXTILine_u8<=9;L_EXTILine_u8++){
		for (u8 L_i_u8 = 0; L_i_u8<16; L_i_u8++){
			if (STD_TRUE == EXTI_CheckInterrupt_Bool(L_i_u8)){
				if (NULL != GS_EXTI_CallBacks_pF[SYSCFG_GetActiveGPIO_u8(L_EXTILine_u8)][L_i_u8]){
					GS_EXTI_CallBacks_pF[SYSCFG_GetActiveGPIO_u8(L_EXTILine_u8)][L_i_u8]();
					EXTI_ClearInterrupt_v(L_i_u8);
				}
				else{

				}
			}
			else{

			}
		}
	}



}
void TIM1_BRK_TIM9_IRQHandler(void){
	/* TIM1 Break interrupt and TIM9 global interrupt*/
}
void TIM1_UP_TIM10_IRQHandler(void){
	/* TIM1 Update interrupt and TIM10 global interrupt*/
}
void TIM1_TRG_COM_TIM11_IRQHandler(void){
	/* TIM1 Trigger and Commutation interrupts and TIM11 global interrupt */
}
void TIM1_CC_IRQHandler(void){
/* TIM1 Capture Compare interrupt*/}
void TIM2_IRQHandler(void){
	/* TIM2 global interrupt*/
}
void TIM3_IRQHandler(void){
	/* TIM3 global interrupt*/
}
void TIM4_IRQHandler(void){
	/* TIM4 global interrupt*/
}
void I2C1_EV_IRQHandler(void){
	/* I2C1 event interrupt*/
}
void I2C1_ER_IRQHandler(void){
	/* I2C1 error interrupt*/
}
void I2C2_EV_IRQHandler(void){
	/* I2C2 event interrupt*/
}
void I2C2_ER_IRQHandler (void){
	/* I2C2 error interrupt*/
}
void SPI1_IRQHandler(void){
	/* SPI1 global interrupt*/
#if CONFIG_USE_SPI1_TX_BUFFER_EMPTY_INTERRUPT
	if (NULL != InterruptHandler_SPI1TXBufferEmptyCallback_void) {
		InterruptHandler_SPI1TXBufferEmptyCallback_void();
	}

#endif
#if CONFIG_USE_SPI1_RX_BUFFER_NONEMPTY_INTERRUPT
	if (NULL != InterruptHandler_SPI1RXBufferNonEmptyCallback_void) {
		InterruptHandler_SPI1RXBufferNonEmptyCallback_void();
	}

#endif

#if CONFIG_USE_SPI1_ERROR_INTERRUPT
	if (NULL != InterruptHandler_SPI1ErrorCRCCallback_void) {
		InterruptHandler_SPI1ErrorCRCCallback_void();
	}
	if (NULL != InterruptHandler_SPI1ErrorOverFlowCallback_void) {
		InterruptHandler_SPI1ErrorOverFlowCallback_void();
	}
	if (NULL != InterruptHandler_SPI1ErrorModeFaultCallback_void) {
		InterruptHandler_SPI1ErrorModeFaultCallback_void();
	}
	if (NULL != InterruptHandler_SPI1ErrorFrameFormatCallback_void) {
		InterruptHandler_SPI1ErrorFrameFormatCallback_void();
	}
	if (NULL != InterruptHandler_SPI1ErrorUnderrunCallback_void) {
		InterruptHandler_SPI1ErrorUnderrunCallback_void();
	}

#endif

}
void SPI2_IRQHandler(void){
	/* SPI2 global interrupt*/
#if CONFIG_USE_SPI2_TX_BUFFER_EMPTY_INTERRUPT
	if (NULL != InterruptHandler_SPI2TXBufferEmptyCallback_void) {
		InterruptHandler_SPI2TXBufferEmptyCallback_void();
	}

#endif

#if CONFIG_USE_SPI2_RX_BUFFER_NONEMPTY_INTERRUPT
	if (NULL != InterruptHandler_SPI2RXBufferNonEmptyCallback_void) {
		InterruptHandler_SPI2RXBufferNonEmptyCallback_void();
	}

#endif

#if CONFIG_USE_SPI2_ERROR_INTERRUPT
	if (NULL != InterruptHandler_SPI2ErrorCRCCallback_void) {
		InterruptHandler_SPI2ErrorCRCCallback_void();
	}
	if (NULL != InterruptHandler_SPI2ErrorOverFlowCallback_void) {
		InterruptHandler_SPI2ErrorOverFlowCallback_void();
	}
	if (NULL != InterruptHandler_SPI2ErrorModeFaultCallback_void) {
		InterruptHandler_SPI2ErrorModeFaultCallback_void();
	}
	if (NULL != InterruptHandler_SPI2ErrorFrameFormatCallback_void) {
		InterruptHandler_SPI2ErrorFrameFormatCallback_void();
	}
	if (NULL != InterruptHandler_SPI2ErrorUnderrunCallback_void) {
		InterruptHandler_SPI2ErrorUnderrunCallback_void();
	}

#endif

}
void USART1_IRQHandler(void){
	/* USART1 global interrupt*/
	USART_HANDLER(1);
}
void USART2_IRQHandler(void){
	/* USART2 global interrupt*/
	USART_HANDLER(2);
}
void USART3_IRQHandler(void){
	/* USART3 global interrupt*/
	USART_HANDLER(3);
}
void EXTI15_10_IRQHandler(void){
	/* EXTI Line[15:10] interrupts*/

	for (u8 L_EXTILine_u8 = 10;L_EXTILine_u8<=15;L_EXTILine_u8++){

		u8 L_ActiveGPIO_u8 = SYSCFG_GetActiveGPIO_u8(L_EXTILine_u8);

		for (u8 L_i_u8 = 0; L_i_u8<16; L_i_u8++){
			if (STD_TRUE == EXTI_CheckInterrupt_Bool(L_i_u8)){
				if (NULL != GS_EXTI_CallBacks_pF[L_ActiveGPIO_u8][L_i_u8]){

					GS_EXTI_CallBacks_pF[L_ActiveGPIO_u8][L_i_u8]();
					EXTI_ClearInterrupt_v(L_i_u8);
				}
				else{

				}
			}
			else{

			}
		}
	}

}
void RTC_Alarm_IRQHandler(void){
	/* RTC Alarms (A and B) through EXTI line interrupt*/
}
void OTG_FS_WKUP_IRQHandler(void){
	/* USB On-The-Go FS Wakeup through EXTI line interrupt*/
}
void TIM8_BRK_TIM12_IRQHandler(void){
	/* TIM8 Break interrupt and TIM12 global interrupt*/
}
void TIM8_UP_TIM13_IRQHandler(void){
	/* TIM8 Update interrupt and TIM13 global interrupt*/
}
void TIM8_TRG_COM_TIM14_IRQHandler(void){
	/* TIM8 Trigger and Commutation interrupts and TIM14 global interrupt*/
}
void TIM8_CC_IRQHandler(void){
	/* TIM8 Capture Compare interrupt*/
}
void DMA1_Stream7_IRQHandler(void){
	/* DMA1 Stream7 global interrupt*/
	DMA_HANDLER(1, 7);
}
void FSMC_IRQHandler(void){
	/* FSMC global interrupt*/
}
void SDIO_IRQHandler(void){
	/* SDIO global interrupt*/
}
void TIM5_IRQHandler(void){
	/* TIM5 global interrupt*/
}
void SPI3_IRQHandler(void){
	/* SPI3 global interrupt*/
#if CONFIG_USE_SPI3_TX_BUFFER_EMPTY_INTERRUPT
	if (NULL != InterruptHandler_SPI3TXBufferEmptyCallback_void) {
		InterruptHandler_SPI3TXBufferEmptyCallback_void();
	}

#endif

#if CONFIG_USE_SPI3_RX_BUFFER_NONEMPTY_INTERRUPT
	if (NULL != InterruptHandler_SPI3RXBufferNonEmptyCallback_void) {
		InterruptHandler_SPI3RXBufferNonEmptyCallback_void();
	}

#endif


#if CONFIG_USE_SPI3_ERROR_INTERRUPT
	if (NULL != InterruptHandler_SPI3ErrorCRCCallback_void) {
		InterruptHandler_SPI3ErrorCRCCallback_void();
	}
	if (NULL != InterruptHandler_SPI3ErrorOverFlowCallback_void) {
		InterruptHandler_SPI3ErrorOverFlowCallback_void();
	}
	if (NULL != InterruptHandler_SPI3ErrorModeFaultCallback_void) {
		InterruptHandler_SPI3ErrorModeFaultCallback_void();
	}
	if (NULL != InterruptHandler_SPI3ErrorFrameFormatCallback_void) {
		InterruptHandler_SPI3ErrorFrameFormatCallback_void();
	}
	if (NULL != InterruptHandler_SPI3ErrorUnderrunCallback_void) {
		InterruptHandler_SPI3ErrorUnderrunCallback_void();
	}

#endif


}
void UART4_IRQHandler(void){
	/* UART4 global interrupt*/
	USART_HANDLER(4);
}
void UART5_IRQHandler(void){
	/*UART5 global interrupt*/
	USART_HANDLER(5);

}
void TIM6_DAC_IRQHandler(void){
	/* TIM6 global interrupt, DAC1 and DAC2 underrun error interrupt*/
#if CONFIG_USE_TIM6_UPDATE_INTERUPT
	if (InterruptHandler_TIM6UpdateCallback_void != NULL){
		CLEAR_BIT(TIM6->SR, 0);
		InterruptHandler_TIM6UpdateCallback_void();
	}
#endif
}
void TIM7_IRQHandler(void){
	/* TIM7 global interrupt*/
#if CONFIG_USE_TIM7_UPDATE_INTERUPT
	if (InterruptHandler_TIM7UpdateCallback_void != NULL){
		CLEAR_BIT(TIM7->SR, 0);
		InterruptHandler_TIM7UpdateCallback_void();
	}
#endif
}
void DMA2_Stream0_IRQHandler(void){
	/* DMA2 Stream0 global interrupt*/
	DMA_HANDLER(2, 0);

}
void DMA2_Stream1_IRQHandler(void){
	/* DMA2 Stream1 global interrupt*/
	DMA_HANDLER(2, 1);
}
void DMA2_Stream2_IRQHandler(void){
	/* DMA2 Stream2 global interrupt*/
	DMA_HANDLER(2, 2);
}
void DMA2_Stream3_IRQHandler(void){
	/* DMA2 Stream3 global interrupt*/
	DMA_HANDLER(2, 3);
}
void DMA2_Stream4_IRQHandler(void){
	/* DMA2 Stream4 global interrupt*/
	DMA_HANDLER(2, 4);
}
void ETH_IRQHandler(void){
	/* Ethernet global interrupt*/
}
void ETH_WKUP_IRQHandler(void){
	/*Ethernet Wakeup through EXTI line interrupt*/
}
void CAN2_TX_IRQHandler(void){
	/* CAN2 TX interrupts*/
}
void CAN2_RX0_IRQHandler(void){
	/* CAN2 RX0 interrupts*/
}
void CAN2_RX1_IRQHandler(void){
	/* CAN2 RX1 interrupts*/
}
void CAN2_SCE_IRQHandler(void){
	/* CAN2 SCE interrupt*/

}
void OTG_FS_IRQHandler(void){
	/* USB On The Go FS global interrupt*/
}
void DMA2_Stream5_IRQHandler(void){
	/* DMA2 Stream5 global interrupt*/
	DMA_HANDLER(2, 5);
}
void DMA2_Stream6_IRQHandler(void){
	/* DMA2 Stream6 global interrupt*/
	DMA_HANDLER(2, 6);
}
void DMA2_Stream7_IRQHandler(void){
	/* DMA2 Stream7 global interrupt*/
	DMA_HANDLER(2, 7);
}
void USART6_IRQHandler(void){
	/* USART6 global interrupt*/
	USART_HANDLER(6);
}
void I2C3_EV_IRQHandler(void){
	/* I2C3 event interrupt*/
}
void I2C3_ER_IRQHandler(void){
	/* I2C3 error interrupt*/
}
void OTG_HS_EP1_OUT_IRQHandler(void){
	/* USB On The Go HS End Point 1 Out global interrupt*/
}
void OTG_HS_EP1_IN_IRQHandler(void){
	/* USB On The Go HS End Point 1 In global interrupt*/
}
void OTG_HS_WKUP_IRQHandler(void){
	/* USB On The Go HS Wakeup through EXTI interrupt*/
}
void OTG_HS_IRQHandler(void){
	/* USB On The Go HS global interrupt*/
}
void DCMI_IRQHandler(void){
	/* DCMI global interrupt*/
}
void CRYP_IRQHandler(void){
	/* CRYP crypto global interrupt*/
}
void HASH_RNG_IRQHandler(void){
	/* Hash and Rng global interrupt*/
}
void FPU_IRQHandler(void){
	/* Floating point interrupt*/
}
void LCD_TFT_IRQHandler(void){
	/* LTDC global interrupt*/
}
void LCD_TFT_1_IRQHandler(void){
	/* LTDC global error interrupt.*/
}


/*
==================================================
  End   Section --> Functions implementation.
==================================================
 */
