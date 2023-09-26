/*
 * File Name --> SPI.c
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> CAN driver implementation.
 * */


/*
==================================================
  Start Section --> File Includes
==================================================
 */
#include "CAN.h"
#include "CAN_Private.h"
#include "CAN_defs.h"
#include "HMCAL/RCC/RCC.h"

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
#define CAN_ID(id) ((volatile CAN_MemMap*const)(GCS_CAN_InstanceIdMapping_u32[((id)-1)]))
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
void CAN_Config_v(CAN_Cfg const * const Arg_conf_cpcCAN_Cfg){
	u8 L_CANInstanceId_u8 = Arg_conf_cpcCAN_Cfg->InstanceId;
	GPIO_Cfg L_CANConfig_GPIO_Cfg;
	L_CANConfig_GPIO_Cfg.InstanceId = Arg_conf_cpcCAN_Cfg->GPIOInstanceId;
	L_CANConfig_GPIO_Cfg.Mode = GPIO_MODE_ALTERNATE_FUNCTION;
	L_CANConfig_GPIO_Cfg.PINs = Arg_conf_cpcCAN_Cfg->GPIOPins;
	L_CANConfig_GPIO_Cfg.OutputSpeed = GPIO_OUTPUT_SPEED_HIGH;
	L_CANConfig_GPIO_Cfg.OutputType = GPIO_OUTPUT_TYPE_PUSH_PULL;
	L_CANConfig_GPIO_Cfg.PullUpPullDownResistor = GPIO_RESISTOR_NO_PULL;



	/*Mapping Pins*/
	u8 L_CANMappingPins[] = {
			CAN1_MAP_PIN,
			CAN2_MAP_PIN,
	};

	for (u8 L_i_u8 = 0; L_i_u8<16; L_i_u8++){
		if (GET_BIT(Arg_conf_cpcCAN_Cfg->GPIOPins, L_i_u8)){
			GPIO_MapGPIOPIN_v(
					&L_CANConfig_GPIO_Cfg,
					L_i_u8,
					L_CANMappingPins[L_CANInstanceId_u8-1]);
		}
	}

	GPIO_Config_v(&L_CANConfig_GPIO_Cfg);

	/*
	 * To reduce the headache on user of enabling clock of the used peripheral.
	 * It 's automatically enabled before configuring the peripheral.
	 * */
	RCC_EnableClock_v(
			RCC_GetPeripheralBus_u8((u32)CAN_ID(L_CANInstanceId_u8)),
			RCC_GetRCCCANBit_u8(L_CANInstanceId_u8));

	/*Reset registers*/
	CAN_ID(L_CANInstanceId_u8)->MCR = 0x10002;
	CAN_ID(L_CANInstanceId_u8)->MSR = 0xc02;
	CAN_ID(L_CANInstanceId_u8)->TSR = 0x1c000000;
	CAN_ID(L_CANInstanceId_u8)->RFxR[0] = 0x0;
	CAN_ID(L_CANInstanceId_u8)->RFxR[1] = 0x0;
	CAN_ID(L_CANInstanceId_u8)->IER = 0x0;
	CAN_ID(L_CANInstanceId_u8)->ESR = 0x0;
	CAN_ID(L_CANInstanceId_u8)->BTR = 0x1230000;


	/*Begin Configurations*/
	/* Enable or disable time triggered communication.*/
	if (STD_ENABLE == Arg_conf_cpcCAN_Cfg->TimeTriggeredEn){
		SET_BIT(
				CAN_ID(L_CANInstanceId_u8)->MCR,
				CAN_MCR_TTCM);


	}
	else{

		CLEAR_BIT(
				CAN_ID(L_CANInstanceId_u8)->MCR,
				CAN_MCR_TTCM);
	}

	/* Enable or disable Automatic bus-off management
	 * This mode controls the behavior of the CAN hardware on leaving the Buss-Off state.
	 * When Enabling this mode, Bus-Off state is left automatically
	 * by hardware once 128 occurrence of 11 recessive bits have been monitored.
	 *
	 * When Disabling this mode, Bus-Off state is left on software request, once 128 occurances of
	 * 11 recessive bits have been monitored and software has first set and cleared the INRQ bit of the CAN_MCR
	 * */
	if (STD_ENABLE == Arg_conf_cpcCAN_Cfg->AutoBusOffEn){
		SET_BIT(
				CAN_ID(L_CANInstanceId_u8)->MCR,
				CAN_MCR_ABOM);

	}
	else{
		CLEAR_BIT(
				CAN_ID(L_CANInstanceId_u8)->MCR,
				CAN_MCR_ABOM);
	}
	/* Enable or disable Automatic wake-up mode.
	 * This mode controls the behavior of the CAN hardware on message reception during sleep mode.
	 * When Enabling this mode, Sleep mode is left automatically by hardware on CAN message detection
	 *
	 * When Disabling this mode, Sleep mode is left on software request by clearing the SLEEP bit of the CAN_MCR register.
	 * */
	if (STD_ENABLE == Arg_conf_cpcCAN_Cfg->AutoWakeUpEn){
		SET_BIT(
				CAN_ID(L_CANInstanceId_u8)->MCR,
				CAN_MCR_AWUM);

	}
	else{
		CLEAR_BIT(
				CAN_ID(L_CANInstanceId_u8)->MCR,
				CAN_MCR_AWUM);
	}
	/* Enable or disable Automatic retransmission mode.
	 * When Enabling this mode, CAN hardware will automatically retransmit the message
	 * until it has been successfully transmitted according to the CAN standard.
	 *
	 * When Disabling this mode, Message will be transmitted only once independently of
	 * the transmission result.
	 * */
	if (STD_ENABLE == Arg_conf_cpcCAN_Cfg->AutoReTransmissionEn){
		CLEAR_BIT(
				CAN_ID(L_CANInstanceId_u8)->MCR,
				CAN_MCR_NART);
	}
	else{
		SET_BIT(
				CAN_ID(L_CANInstanceId_u8)->MCR,
				CAN_MCR_NART);
	}

	/* Enable or disable Receive FIFO Lock in case of overrun.
	 *
	 * When Enabling this mode, Receive FIFO is locked against overrun,
	 * and once a receive FIFO is full the next incoming message will be discarded.
	 *
	 * When Disabling this mode, Receive FIFO is not-locked against overrun,
	 * and once a receive FIFO is full the next incoming message will override the previous one.
	 * */
	if (STD_ENABLE == Arg_conf_cpcCAN_Cfg->ReceiveFifoLockOnOverrunEn){
		SET_BIT(
				CAN_ID(L_CANInstanceId_u8)->MCR,
				CAN_MCR_RFLM);

	}
	else{
		CLEAR_BIT(
				CAN_ID(L_CANInstanceId_u8)->MCR,
				CAN_MCR_RFLM);
	}
	/* Select the priority of Transmit FIFO whether
	 * priority is driven by ID of the message, or
	 * priority is driven by the request order.
	 * */
	if (CAN_TRANSMIT_FIFO_PRIORITY_BY_REQ_ORDER == Arg_conf_cpcCAN_Cfg->TransmitFifoPriority){
		SET_BIT(
				CAN_ID(L_CANInstanceId_u8)->MCR,
				CAN_MCR_TXFP);

	}
	else if (CAN_TRANSMIT_FIFO_PRIORITY_BY_MSG_ID == Arg_conf_cpcCAN_Cfg->TransmitFifoPriority){
		CLEAR_BIT(
				CAN_ID(L_CANInstanceId_u8)->MCR,
				CAN_MCR_TXFP);
	}
	else{

	}

	/*Enter Initialization Mode*/
	SET_BIT(
			CAN_ID(L_CANInstanceId_u8)->MCR,
			CAN_MCR_INRQ);

	while(!(
			!GET_BIT(CAN_ID(L_CANInstanceId_u8)->MSR,
					CAN_MSR_SLAK) )
			&&
			(GET_BIT(CAN_ID(L_CANInstanceId_u8)->MSR,
					CAN_MSR_INAK)));
	/*Exit Sleep Mode.*/
	CLEAR_BIT(
			CAN_ID(L_CANInstanceId_u8)->MCR,
			CAN_MCR_SLEEP);

	/*Interrupt*/
	CAN_ID(L_CANInstanceId_u8)->IER = Arg_conf_cpcCAN_Cfg->Interrupt;
	/*Mapping between USART interrupt and It's corresponding NVIC*/

	u8 L_CANInterruptMapping_u8[2][4] = {
			{NVIC_CAN1_TX, NVIC_CAN1_RX0, NVIC_CAN1_RX1, NVIC_CAN1_SCE},
			{NVIC_CAN2_TX, NVIC_CAN2_RX0, NVIC_CAN2_RX1, NVIC_CAN2_SCE}};

	if (0 != (Arg_conf_cpcCAN_Cfg->Interrupt & CAN_INTERRUPT_TRANSMIT_EMPTY) ){
		NVIC_EnableInterrupt_v(L_CANInterruptMapping_u8[Arg_conf_cpcCAN_Cfg->InstanceId-1][0]);
	}

	if (0 != (Arg_conf_cpcCAN_Cfg->Interrupt
			& CAN_INTERRUPT_FIFO0_MSG_PEND
			& CAN_INTERRUPT_FIFO0_FULL
			& CAN_INTERRUPT_FIFO0_OVERRUN
	) ){
		NVIC_EnableInterrupt_v(L_CANInterruptMapping_u8[Arg_conf_cpcCAN_Cfg->InstanceId-1][1]);
	}

	if (0 != (Arg_conf_cpcCAN_Cfg->Interrupt
			& CAN_INTERRUPT_FIFO1_MSG_PEND
			& CAN_INTERRUPT_FIFO1_FULL
			& CAN_INTERRUPT_FIFO1_OVERRUN
	) ){
		NVIC_EnableInterrupt_v(L_CANInterruptMapping_u8[Arg_conf_cpcCAN_Cfg->InstanceId-1][2]);
	}

	if (0 != (Arg_conf_cpcCAN_Cfg->Interrupt
			& CAN_INTERRUPT_ERR_WARNING
			& CAN_INTERRUPT_ERR_PASSIVE
			& CAN_INTERRUPT_BUSS_OFF
			& CAN_INTERRUPT_LAST_ERR
			& CAN_INTERRUPT_ERR
	) ){
		NVIC_EnableInterrupt_v(L_CANInterruptMapping_u8[Arg_conf_cpcCAN_Cfg->InstanceId-1][3]);
	}

	/*Configure test mode.*/
	u32 L_BitTimingRegisterValue_u32=0;
	switch (Arg_conf_cpcCAN_Cfg->OperatingMode){
	case CAN_OPERATING_MODE_NORMAL:
		CLEAR_BIT(L_BitTimingRegisterValue_u32,CAN_BTR_SILM);
		CLEAR_BIT(L_BitTimingRegisterValue_u32,CAN_BTR_LBKM);
		break;
	case CAN_OPERATING_MODE_LOOPBACK:
		CLEAR_BIT(L_BitTimingRegisterValue_u32,CAN_BTR_SILM);
		SET_BIT(L_BitTimingRegisterValue_u32,CAN_BTR_LBKM);
		break;
	case CAN_OPERATING_MODE_SILENT:
		SET_BIT(L_BitTimingRegisterValue_u32,CAN_BTR_SILM);
		CLEAR_BIT(L_BitTimingRegisterValue_u32,CAN_BTR_LBKM);
		break;
	case CAN_OPERATING_MODE_LoopbackWithSilent:
		SET_BIT(L_BitTimingRegisterValue_u32, CAN_BTR_SILM);
		SET_BIT(L_BitTimingRegisterValue_u32, CAN_BTR_LBKM);
		break;
	}
	/*Baud Rate Configurations*/

	L_BitTimingRegisterValue_u32 |= ((Arg_conf_cpcCAN_Cfg->BaudRatePrescaller-1)&0x3F);
	L_BitTimingRegisterValue_u32 |= (((Arg_conf_cpcCAN_Cfg->TimeSegment_1-1)<<CAN_BTR_TS1) & 0xF0000);
	L_BitTimingRegisterValue_u32 |= (((Arg_conf_cpcCAN_Cfg->TimeSegment_2-1)<<CAN_BTR_TS2) & 0x700000);
	L_BitTimingRegisterValue_u32 |= (((Arg_conf_cpcCAN_Cfg->ResychronizationJump-1)<<CAN_BTR_SJW) & 0x3000000);
	CAN_ID(L_CANInstanceId_u8)->BTR = L_BitTimingRegisterValue_u32;
	/*Enter Normal mode by clearing CAN_MCR_SLEEP bit and CAN_MCR_INRQ bit.*/
	CLEAR_BIT(
			CAN_ID(L_CANInstanceId_u8)->MCR,
			CAN_MCR_INRQ);
	CLEAR_BIT(
			CAN_ID(L_CANInstanceId_u8)->MCR,
			CAN_MCR_SLEEP);
}

void CAN_SendData_v(CAN_Cfg const * const Arg_conf_cpcCAN_Cfg, CAN_TxData const * const Arg_TransmitData_cpcCAN_TxData,
		const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32){

	u8 L_TimeoutCheckCondition_u8;

	Utils_TimeoutChecker L_timeout_Utils_TimeoutChecker;
	Utils_TimeoutChecker_Init(&L_timeout_Utils_TimeoutChecker, Arg_ToutVal_Cu32);




	u8 L_CANInstanceId_u8 = Arg_conf_cpcCAN_Cfg->InstanceId;
	u8 L_FreeMailBoxIndex_u8 = 255;
	/*Search for empty mail boc*/
	while(255 == L_FreeMailBoxIndex_u8){
		L_TimeoutCheckCondition_u8 = Utils_IsTimeoutOccurred_u8(&L_timeout_Utils_TimeoutChecker);

		if ((STD_TRUE == L_TimeoutCheckCondition_u8) ){
			if (NULL != Arg_ToutErr_pCu32){
				*Arg_ToutErr_pCu32 = STD_TimeOutError;
			}

			return ;
		}
		else if (STD_FALSE == L_TimeoutCheckCondition_u8){
			if (NULL != Arg_ToutErr_pCu32){
				*Arg_ToutErr_pCu32 = STD_NoTimeOutError;
			}
		}
		else{

		}


		for (u8 L_MailBoxIdx_u8 = 0; L_MailBoxIdx_u8 <CAN_TRANSMIT_MAILBOX_NUMS ;L_MailBoxIdx_u8++){
			if (GET_BIT(CAN_ID(L_CANInstanceId_u8)->TSR, (CAN_TSR_TME + L_MailBoxIdx_u8))){
				L_FreeMailBoxIndex_u8 = L_MailBoxIdx_u8;
				break;
			}
			else{

			}
		}
	}

	/*Reset TX mailbox identifier register.*/
	CAN_ID(L_CANInstanceId_u8)->TxMailBox[L_FreeMailBoxIndex_u8].TIR = 0;
	/*Reset mailbox datalength control and time-stamp control register.*/
	CAN_ID(L_CANInstanceId_u8)->TxMailBox[L_FreeMailBoxIndex_u8].TDTR = 0;

	/*Configure Data length code.*/
	CAN_ID(L_CANInstanceId_u8)->TxMailBox[L_FreeMailBoxIndex_u8].TDTR|= (Arg_TransmitData_cpcCAN_TxData->DataLength&0xF);

	/*Configure identifier and it's type whether it's standard or extended.*/
	switch(Arg_TransmitData_cpcCAN_TxData->IdType){
	case CAN_Standard_Id:
		/*Set standard id value.*/
		CAN_ID(L_CANInstanceId_u8)->TxMailBox[L_FreeMailBoxIndex_u8].TIR|=(Arg_TransmitData_cpcCAN_TxData->ID<<CAN_TIxR_STID);
		/*Clear TIxR to configure that it's standard.*/
		CLEAR_BIT(
				CAN_ID(L_CANInstanceId_u8)->TxMailBox[L_FreeMailBoxIndex_u8].TIR,
				CAN_TIxR_IDE);
		break;

	case CAN_Extended_Id:
		/*Set Extended id value.*/
		CAN_ID(L_CANInstanceId_u8)->TxMailBox[L_FreeMailBoxIndex_u8].TIR|=(Arg_TransmitData_cpcCAN_TxData->ID<<CAN_TIxR_EXID);
		/*Set TIxR to configure that it's extended.*/
		SET_BIT(CAN_ID(L_CANInstanceId_u8)->TxMailBox[L_FreeMailBoxIndex_u8].TIR, CAN_TIxR_IDE);
		break;
	}

	/*Configure Frame type whether it's data frame or remote frame*/
	switch(Arg_TransmitData_cpcCAN_TxData->FrameType){
	case CAN_Data_Frame:
		CLEAR_BIT(
				CAN_ID(L_CANInstanceId_u8)->TxMailBox[L_FreeMailBoxIndex_u8].TIR,
				CAN_TIxR_RTR);

		/*Reset Mailbox data low and high register.*/
		CAN_ID(L_CANInstanceId_u8)->TxMailBox[L_FreeMailBoxIndex_u8].TDLR = 0;
		CAN_ID(L_CANInstanceId_u8)->TxMailBox[L_FreeMailBoxIndex_u8].TDHR = 0;

		for (u8 L_i_u8 = 0; L_i_u8 <Arg_TransmitData_cpcCAN_TxData->DataLength ;L_i_u8++){
			if (L_i_u8 > 3){
				CAN_ID(L_CANInstanceId_u8)->TxMailBox[L_FreeMailBoxIndex_u8].TDHR
						|= Arg_TransmitData_cpcCAN_TxData->DataPtr[L_i_u8]<<(8*(L_i_u8%4));
			}
			else {
				CAN_ID(L_CANInstanceId_u8)->TxMailBox[L_FreeMailBoxIndex_u8].TDLR
						|= Arg_TransmitData_cpcCAN_TxData->DataPtr[L_i_u8]<<(8*(L_i_u8));
			}
		}
		break;

	case CAN_Remote_Frame:
		SET_BIT(
				CAN_ID(L_CANInstanceId_u8)->TxMailBox[L_FreeMailBoxIndex_u8].TIR,
				CAN_TIxR_RTR);
		break;
	}

	/*Transmit Request of Mailbox*/
	SET_BIT(CAN_ID(L_CANInstanceId_u8)->TxMailBox[L_FreeMailBoxIndex_u8].TIR, CAN_TIxR_TXRQ);
}

void CAN_AddRxFilter_v(CAN_Cfg const * const Arg_conf_cpcCAN_Cfg, CAN_FilterConfig *Arg_FilterCfg_CAN_FilterConfig){
	u8 L_CANInstanceId_u8 = Arg_conf_cpcCAN_Cfg->InstanceId;
	u8 L_FilterId_u8 = Arg_FilterCfg_CAN_FilterConfig->FilterId;
	u8 L_FilterScale_u8;
	u8 L_FrameType_u8 = Arg_FilterCfg_CAN_FilterConfig->FrameType;
	u8 L_IdType_u8 = Arg_FilterCfg_CAN_FilterConfig->IdType;

	u32 L_FiR1Val_u32 = 0;
	u32 L_FiR2Val_u32 = 0;


	/*Set filter initialization mode.*/
	SET_BIT(CAN_ID(L_CANInstanceId_u8)->FMR, CAN_FMR_FINIT);
	/*Deactivate Filter*/
	CLEAR_BIT(CAN_ID(L_CANInstanceId_u8)->FA1R, L_FilterId_u8);

	switch(Arg_FilterCfg_CAN_FilterConfig->FIFONumber){
	case CAN_FILTER_FIFONUMBER_1:
		CLEAR_BIT(CAN_ID(L_CANInstanceId_u8)->FFA1R, L_FilterId_u8);
		break;

	case CAN_FILTER_FIFONUMBER_2:
		SET_BIT(CAN_ID(L_CANInstanceId_u8)->FFA1R, L_FilterId_u8);
		break;
	}




	switch (Arg_FilterCfg_CAN_FilterConfig->FilterType){
	/*Filter scale = CAN_FILTER_SCALE_SINGLE32*/
	case CAN_FILTER_TYPE_1ID32_1MASK32:
		L_FilterScale_u8 = CAN_Filter_Scale_Single;

		SET_BIT(CAN_ID(L_CANInstanceId_u8)->FS1R, L_FilterId_u8);
		CLEAR_BIT(CAN_ID(L_CANInstanceId_u8)->FM1R, L_FilterId_u8);

		if (CAN_Extended_Id == Arg_FilterCfg_CAN_FilterConfig->IdType){
			L_FiR1Val_u32 |= (Arg_FilterCfg_CAN_FilterConfig->ID1<<CAN_FiRx_FB3);
			L_FiR2Val_u32 |= (Arg_FilterCfg_CAN_FilterConfig->Mask1<<CAN_FiRx_FB3);
		}
		else if(CAN_Standard_Id == Arg_FilterCfg_CAN_FilterConfig->IdType){
			L_FiR1Val_u32 |= (Arg_FilterCfg_CAN_FilterConfig->ID1<<CAN_FiRx_FB21);
			L_FiR2Val_u32 |= (Arg_FilterCfg_CAN_FilterConfig->Mask1<<CAN_FiRx_FB21);
		}

		break;

		/*Filter scale = CAN_FILTER_SCALE_SINGLE32*/
	case CAN_FILTER_TYPE_2ID32:
		L_FilterScale_u8 = CAN_Filter_Scale_Single;

		SET_BIT(CAN_ID(L_CANInstanceId_u8)->FS1R, L_FilterId_u8);
		SET_BIT(CAN_ID(L_CANInstanceId_u8)->FM1R, L_FilterId_u8);

		if (CAN_Extended_Id == Arg_FilterCfg_CAN_FilterConfig->IdType){
			L_FiR1Val_u32 |= (Arg_FilterCfg_CAN_FilterConfig->ID1<<CAN_FiRx_FB3);
			L_FiR2Val_u32 |= (Arg_FilterCfg_CAN_FilterConfig->ID2<<CAN_FiRx_FB3);
		}
		else if(CAN_Standard_Id == Arg_FilterCfg_CAN_FilterConfig->IdType){
			L_FiR1Val_u32 |= (Arg_FilterCfg_CAN_FilterConfig->ID1<<CAN_FiRx_FB21);
			L_FiR2Val_u32 |= (Arg_FilterCfg_CAN_FilterConfig->ID2<<CAN_FiRx_FB21);
		}
		break;

		/*Filter scale = CAN_FILTER_SCALE_DUAL16*/
	case CAN_FILTER_TYPE_2ID16_2MASK16:
		L_FilterScale_u8 = CAN_Filter_Scale_Dual;

		CLEAR_BIT(CAN_ID(L_CANInstanceId_u8)->FS1R, L_FilterId_u8);
		CLEAR_BIT(CAN_ID(L_CANInstanceId_u8)->FM1R, L_FilterId_u8);

		if (CAN_Extended_Id == Arg_FilterCfg_CAN_FilterConfig->IdType){
			L_FiR1Val_u32 |= ((Arg_FilterCfg_CAN_FilterConfig->ID1&0x38000)>>15);
			L_FiR1Val_u32 |= (((Arg_FilterCfg_CAN_FilterConfig->Mask1&0x38000)>>15)<<CAN_FiRx_FB16);

			L_FiR2Val_u32 |= ((Arg_FilterCfg_CAN_FilterConfig->ID2&0x38000)>>15);
			L_FiR2Val_u32 |= (((Arg_FilterCfg_CAN_FilterConfig->Mask2&0x38000)>>15)<<CAN_FiRx_FB16);

		}

		else if(CAN_Standard_Id == L_IdType_u8){
			L_FiR1Val_u32 |= Arg_FilterCfg_CAN_FilterConfig->ID1<<CAN_FiRx_FB5;
			L_FiR1Val_u32 |= Arg_FilterCfg_CAN_FilterConfig->Mask1<<CAN_FiRx_FB21;

			L_FiR2Val_u32 |= Arg_FilterCfg_CAN_FilterConfig->ID2<<CAN_FiRx_FB5;
			L_FiR2Val_u32 |= Arg_FilterCfg_CAN_FilterConfig->Mask2<<CAN_FiRx_FB21;
		}
		break;

		/*Filter scale = CAN_FILTER_SCALE_DUAL16*/
	case CAN_FILTER_TYPE_4ID16:
		L_FilterScale_u8 = CAN_Filter_Scale_Dual;

		CLEAR_BIT(CAN_ID(L_CANInstanceId_u8)->FS1R, L_FilterId_u8);
		SET_BIT(CAN_ID(L_CANInstanceId_u8)->FM1R, L_FilterId_u8);

		if (CAN_Extended_Id == L_IdType_u8){
			L_FiR1Val_u32 |= ((Arg_FilterCfg_CAN_FilterConfig->ID1&0x38000)>>15);
			L_FiR1Val_u32 |= (((Arg_FilterCfg_CAN_FilterConfig->ID2&0x38000)>>15)<<CAN_FiRx_FB16);

			L_FiR2Val_u32 |= ((Arg_FilterCfg_CAN_FilterConfig->ID3&0x38000)>>15);
			L_FiR2Val_u32 |= (((Arg_FilterCfg_CAN_FilterConfig->ID4&0x38000)>>15)<<CAN_FiRx_FB16);

		}
		else if(CAN_Standard_Id == L_IdType_u8){
			L_FiR1Val_u32 |= Arg_FilterCfg_CAN_FilterConfig->ID1<<CAN_FiRx_FB5;
			L_FiR1Val_u32 |= Arg_FilterCfg_CAN_FilterConfig->ID2<<CAN_FiRx_FB21;

			L_FiR2Val_u32 |= Arg_FilterCfg_CAN_FilterConfig->ID3<<CAN_FiRx_FB5;
			L_FiR2Val_u32 |= Arg_FilterCfg_CAN_FilterConfig->ID4<<CAN_FiRx_FB21;
		}
		break;
	}

	switch(L_FilterScale_u8){
	case CAN_Filter_Scale_Single:
		if (CAN_Remote_Frame == L_FrameType_u8){
			SET_BIT(L_FiR1Val_u32, CAN_FiRx_FB1);
			SET_BIT(L_FiR2Val_u32, CAN_FiRx_FB1);
		}

		else if (CAN_Extended_Id == L_IdType_u8){
			SET_BIT(L_FiR1Val_u32, CAN_FiRx_FB2);
			SET_BIT(L_FiR2Val_u32, CAN_FiRx_FB2);
		}
		else{

		}


		break;

	case CAN_Filter_Scale_Dual:
		if (CAN_Remote_Frame == L_FrameType_u8){
			SET_BIT(L_FiR1Val_u32, CAN_FiRx_FB4);
			SET_BIT(L_FiR1Val_u32, CAN_FiRx_FB20);

			SET_BIT(L_FiR2Val_u32, CAN_FiRx_FB4);
			SET_BIT(L_FiR2Val_u32, CAN_FiRx_FB20);

		}

		else if (CAN_Extended_Id == L_IdType_u8){

			SET_BIT(L_FiR1Val_u32, CAN_FiRx_FB3);
			SET_BIT(L_FiR1Val_u32, CAN_FiRx_FB19);

			SET_BIT(L_FiR2Val_u32, CAN_FiRx_FB3);
			SET_BIT(L_FiR2Val_u32, CAN_FiRx_FB19);
		}
		else{

		}
		break;
	}


	CAN_ID(L_CANInstanceId_u8)->FilterRegister[L_FilterId_u8].FR1 = L_FiR1Val_u32;
	CAN_ID(L_CANInstanceId_u8)->FilterRegister[L_FilterId_u8].FR2 = L_FiR2Val_u32;
	/*Activate Filter*/

	SET_BIT(CAN_ID(L_CANInstanceId_u8)->FA1R, L_FilterId_u8);
	/*De-active Filters Mode*/
	CLEAR_BIT(CAN_ID(L_CANInstanceId_u8)->FMR, CAN_FMR_FINIT);
}

void CAN_RemoveRxFilter_v(CAN_Cfg const * const Arg_conf_cpcCAN_Cfg, CAN_FilterConfig *Arg_FilterCfg_CAN_FilterConfig){
	u8 L_CANInstanceId_u8 = Arg_conf_cpcCAN_Cfg->InstanceId;
	u8 L_FilterId_u8 = Arg_FilterCfg_CAN_FilterConfig->FilterId;

	/*Set filter initialization mode.*/
	SET_BIT(CAN_ID(L_CANInstanceId_u8)->FMR, CAN_FMR_FINIT);
	/*Deactivate Filter*/
	CLEAR_BIT(CAN_ID(L_CANInstanceId_u8)->FA1R, L_FilterId_u8);


	CAN_ID(L_CANInstanceId_u8)->FilterRegister[L_FilterId_u8].FR1 = 0;
	CAN_ID(L_CANInstanceId_u8)->FilterRegister[L_FilterId_u8].FR2 = 0;

	/*De-active Filters Mode*/
	CLEAR_BIT(CAN_ID(L_CANInstanceId_u8)->FMR, CAN_FMR_FINIT);
}

void CAN_Receive_v(CAN_Cfg const * const Arg_conf_cpcCAN_Cfg, CAN_RxData *Arg_RXData_CAN_RxData,
		const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32){

	u8 L_CANInstanceId_u8 = Arg_conf_cpcCAN_Cfg->InstanceId;
	u8 L_FIFONumber_u8 = -1;
	u8 L_PendingFlag_u8 = 1;

	u8 L_TimeoutCheckCondition_u8 = STD_FALSE;

	if ( STD_MAX_DELAY !=Arg_ToutVal_Cu32){

		Utils_TimeoutChecker L_timeout_Utils_TimeoutChecker;
		L_TimeoutCheckCondition_u8 = Utils_IsTimeoutOccurred_u8(&L_timeout_Utils_TimeoutChecker);
		Utils_TimeoutChecker_Init(&L_timeout_Utils_TimeoutChecker, Arg_ToutVal_Cu32);
	}

	while(L_PendingFlag_u8){
		for (u8 L_i_u8 = 0; L_i_u8<ARRAY_LENGTH(CAN_ID(L_CANInstanceId_u8)->RFxR);L_i_u8++){

			if ((STD_TRUE == L_TimeoutCheckCondition_u8) ){
				if (NULL != Arg_ToutErr_pCu32){
					*Arg_ToutErr_pCu32 = STD_TimeOutError;
				}

				return ;
			}
			else if (STD_FALSE == L_TimeoutCheckCondition_u8){
				if (NULL != Arg_ToutErr_pCu32){
					*Arg_ToutErr_pCu32 = STD_NoTimeOutError;
				}
			}
			else{

			}


			if (0 != (CAN_ID(L_CANInstanceId_u8)->RFxR[L_i_u8] & 0x3)){
				L_FIFONumber_u8 = L_i_u8;
				L_PendingFlag_u8 = 0;
				break;
			}
		}
	}

	if (-1 == L_FIFONumber_u8){
		return ;
	}


	/*Check If FIFO 0 is not Empty*/
	Arg_RXData_CAN_RxData->FilterId = (u8)((CAN_ID(L_CANInstanceId_u8)->FIFOMailBox[L_FIFONumber_u8].RDTR>>CAN_RDTxR_FMI)&0xFF);

	Arg_RXData_CAN_RxData->DataLength = (u8)(CAN_ID(L_CANInstanceId_u8)->FIFOMailBox[L_FIFONumber_u8].RDTR&0xF);

	Arg_RXData_CAN_RxData->FrameType = GET_BIT(CAN_ID(L_CANInstanceId_u8)->FIFOMailBox[L_FIFONumber_u8].RIR, CAN_RIxR_RTR);
	Arg_RXData_CAN_RxData->IdType = GET_BIT(CAN_ID(L_CANInstanceId_u8)->FIFOMailBox[L_FIFONumber_u8].RIR, CAN_RIxR_IDE);

	if (CAN_Standard_Id == Arg_RXData_CAN_RxData->IdType){
		Arg_RXData_CAN_RxData->ID = CAN_ID(L_CANInstanceId_u8)->FIFOMailBox[L_FIFONumber_u8].RIR>>CAN_RIxR_STID;
	}
	else if(CAN_Extended_Id == Arg_RXData_CAN_RxData->IdType){
		Arg_RXData_CAN_RxData->ID = CAN_ID(L_CANInstanceId_u8)->FIFOMailBox[L_FIFONumber_u8].RIR>>CAN_RIxR_EXID;
	}
	else{

	}

	if (CAN_Data_Frame == Arg_RXData_CAN_RxData->FrameType){
		for (u8 L_DataIdx_u8=0; L_DataIdx_u8<Arg_RXData_CAN_RxData->DataLength; L_DataIdx_u8++){
			if (L_DataIdx_u8<4){
				Arg_RXData_CAN_RxData->ReceivedData[L_DataIdx_u8]
													= (u8)(CAN_ID(L_CANInstanceId_u8)->FIFOMailBox[L_FIFONumber_u8].RDLR >> (8*L_DataIdx_u8));
			}
			else{
				Arg_RXData_CAN_RxData->ReceivedData[L_DataIdx_u8]
													= (u8)(CAN_ID(L_CANInstanceId_u8)->FIFOMailBox[L_FIFONumber_u8].RDHR >> (8*(L_DataIdx_u8%4)));
			}
		}
	}
	else{

	}

	/*Release FIFO for the next message.*/
	SET_BIT(CAN_ID(L_CANInstanceId_u8)->RFxR[L_FIFONumber_u8], CAN_RF0R_RFOM0);


}

CAN_Error CAN_GetErrorInterrupt_u8(u8 Arg_CANInstanceId_u8){
	u8 L_Error_u8 = CAN_ID(Arg_CANInstanceId_u8)->ESR;
	L_Error_u8 &= (1<<CAN_ESR_LEC_0) | (1<<CAN_ESR_LEC_1) | (1<<CAN_ESR_LEC_2);
	return (CAN_Error)L_Error_u8;
}

Bool CAN_CheckInterruptAndClear_Bool(u8 Arg_CANInstanceId_u8, u8 Arg_CANInterruptType_u8){
	switch (Arg_CANInterruptType_u8){

	/*CAN_INTERRUPT_TRANSMIT_EMPTY*/
	case 0:
		if (STD_TRUE == GET_BIT(CAN_ID(Arg_CANInstanceId_u8)->TSR, CAN_TSR_RQCP0)){
			SET_BIT(CAN_ID(Arg_CANInstanceId_u8)->TSR, CAN_TSR_RQCP0);
			return STD_TRUE;
		}
		else if (STD_TRUE == GET_BIT(CAN_ID(Arg_CANInstanceId_u8)->TSR, CAN_TSR_RQCP1)){
			SET_BIT(CAN_ID(Arg_CANInstanceId_u8)->TSR, CAN_TSR_RQCP1);
			return STD_TRUE;
		}
		else if (STD_TRUE == GET_BIT(CAN_ID(Arg_CANInstanceId_u8)->TSR, CAN_TSR_RQCP2)){
			SET_BIT(CAN_ID(Arg_CANInstanceId_u8)->TSR, CAN_TSR_RQCP2);
			return STD_TRUE;
		}
		else{
			return STD_FALSE;
		}
		break;
		/*CAN_INTERRUPT_FIFO0_MSG_PEND*/
	case 1:
		if (STD_TRUE == GET_BIT(CAN_ID(Arg_CANInstanceId_u8)->RFxR[0], CAN_RF0R_FMP0)){
			return STD_TRUE;
		}
		else{
			return STD_FALSE;
		}
		break;
		/*CAN_INTERRUPT_FIFO0_FULL*/
	case 2:
		if (STD_TRUE == GET_BIT(CAN_ID(Arg_CANInstanceId_u8)->RFxR[0], CAN_RF0R_FULL0)){
			SET_BIT(CAN_ID(Arg_CANInstanceId_u8)->RFxR[0], CAN_RF0R_FULL0);
			return STD_TRUE;
		}
		else{
			return STD_FALSE;
		}
		break;
		/*CAN_INTERRUPT_FIFO0_OVERRUN*/
	case 3:
		if (STD_TRUE == GET_BIT(CAN_ID(Arg_CANInstanceId_u8)->RFxR[0], CAN_RF0R_FOVR0)){
			SET_BIT(CAN_ID(Arg_CANInstanceId_u8)->RFxR[0], CAN_RF0R_FOVR0);
			return STD_TRUE;
		}
		else{
			return STD_FALSE;
		}
		break;
		/*CAN_INTERRUPT_FIFO1_MSG_PEND*/
	case 4:
		if (STD_TRUE == GET_BIT(CAN_ID(Arg_CANInstanceId_u8)->RFxR[1], CAN_RF1R_FMP1)){
			return STD_TRUE;
		}
		else{
			return STD_FALSE;
		}
		break;
		/*CAN_INTERRUPT_FIFO1_FULL*/
	case 5:
		if (STD_TRUE == GET_BIT(CAN_ID(Arg_CANInstanceId_u8)->RFxR[1], CAN_RF1R_FULL1)){
			SET_BIT(CAN_ID(Arg_CANInstanceId_u8)->RFxR[1], CAN_RF1R_FULL1);
			return STD_TRUE;
		}
		else{
			return STD_FALSE;
		}
		break;
		/*CAN_INTERRUPT_FIFO1_OVERRUN*/
	case 6:
		if (STD_TRUE == GET_BIT(CAN_ID(Arg_CANInstanceId_u8)->RFxR[1], CAN_RF1R_FOVR1)){
			SET_BIT(CAN_ID(Arg_CANInstanceId_u8)->RFxR[1], CAN_RF1R_FOVR1);
			return STD_TRUE;
		}
		else{
			return STD_FALSE;
		}
		break;
		/*CAN_INTERRUPT_ERR_WARNING*/
	case 8:
		if (STD_TRUE == GET_BIT(CAN_ID(Arg_CANInstanceId_u8)->ESR, CAN_ESR_EWGF)){
			return STD_TRUE;
		}
		else{
			return STD_FALSE;
		}

		break;
		/*CAN_INTERRUPT_ERR_PASSIVE*/
	case 9:
		if (STD_TRUE == GET_BIT(CAN_ID(Arg_CANInstanceId_u8)->ESR, CAN_ESR_EPVF)){
			return STD_TRUE;
		}
		else{
			return STD_FALSE;
		}
		break;
		/*CAN_INTERRUPT_BUSS_OFF*/
	case 10:
		if (STD_TRUE == GET_BIT(CAN_ID(Arg_CANInstanceId_u8)->ESR, CAN_ESR_BOFF)){
			return STD_TRUE;
		}
		else{
			return STD_FALSE;
		}
		break;
		/*CAN_INTERRUPT_LAST_ERR*/
	case 11:
		/*Error code*/
		;

		break;
		/*CAN_INTERRUPT_ERR*/
	case 15:
		/*Interrupt if error condition is pending in CAN_ESR*/
		return STD_FALSE;
		break;
		/*CAN_INTERRUPT_WAKE_UP*/
	case 16:

		if (STD_TRUE == GET_BIT(CAN_ID(Arg_CANInstanceId_u8)->IER, CAN_IER_WKUIE)){
			return STD_TRUE;
		}
		else{
			return STD_FALSE;
		}
		break;
		/*CAN_INTERRUPT_SLEEP*/
	case 17:

		if (STD_TRUE == GET_BIT(CAN_ID(Arg_CANInstanceId_u8)->IER, CAN_IER_SLKIE)){
			return STD_TRUE;
		}
		else{
			return STD_FALSE;
		}
		break;
	}

	return STD_FALSE;
}

/*
==================================================
  End   Section --> Functions implementation.
==================================================
 */
