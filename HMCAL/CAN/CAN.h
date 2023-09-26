/*
 * File Name --> CAN.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> Provides API and available configuration options for CAN peripheral.
 * */

#ifndef HMCAL_CAN_CAN_H_
#define HMCAL_CAN_CAN_H_

/*
==================================================
  Start Section --> File Includes
==================================================
 */
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "HMCAL/GPIO/GPIO.h"
/*
==================================================
  End   Section --> File Includes
==================================================
 */


/*
==================================================
  Start Section --> Macro Declaration
==================================================
 */



/*Operating Mode Available Options*/
/*@ref CAN_Operating_Mode*/
#define CAN_OPERATING_MODE_NORMAL						0
#define CAN_OPERATING_MODE_LOOPBACK						1
#define CAN_OPERATING_MODE_SILENT						2
#define CAN_OPERATING_MODE_LoopbackWithSilent			3

/*Id type*/
#define CAN_IDTYPE_STANDARD								0
#define CAN_IDTYPE_EXTENDED								1

/*Frame type*/
#define CAN_FRAMETYPE_DATA								0
#define CAN_FRAMETYPE_REMOTE							1

/*Filter Configurations*/
#define CAN_FILTER_MODE_MASK							0
#define CAN_FILTER_MODE_Id								1

#define CAN_FILTER_SCALE_DUAL16							0
#define CAN_FILTER_SCALE_SINGLE32						1

/*@ref CAN_Filter_FIFO_Number*/
#define CAN_FILTER_FIFONUMBER_1							0
#define CAN_FILTER_FIFONUMBER_2							1

/**/
#define CAN_FILTER_IDTYPE_STANDARD						0
#define CAN_FILTER_IDTYPE_EXTENDED						1

/**/
#define CAN_FILTER_FRAMETYPE_DATA						0
#define CAN_FILTER_FRAMETYPE_REMOTE						1
/**/
#define CAN_TRANSMIT_FIFO_PRIORITY_BY_MSG_ID			0
#define CAN_TRANSMIT_FIFO_PRIORITY_BY_REQ_ORDER			1
/*@ref CAN_Interrupt*/
#define CAN_INTERRUPT_DISABLE							0
#define CAN_INTERRUPT_TRANSMIT_EMPTY 					(1<<0)
#define CAN_INTERRUPT_FIFO0_MSG_PEND 					(1<<1)
#define CAN_INTERRUPT_FIFO0_FULL 						(1<<2)
#define CAN_INTERRUPT_FIFO0_OVERRUN 					(1<<3)
#define CAN_INTERRUPT_FIFO1_MSG_PEND 					(1<<4)
#define CAN_INTERRUPT_FIFO1_FULL 						(1<<5)
#define CAN_INTERRUPT_FIFO1_OVERRUN 					(1<<6)
#define CAN_INTERRUPT_ERR_WARNING 						(1<<8)
#define CAN_INTERRUPT_ERR_PASSIVE 						(1<<9)
#define CAN_INTERRUPT_BUSS_OFF 							(1<<10)
#define CAN_INTERRUPT_LAST_ERR 							(1<<11)
#define CAN_INTERRUPT_ERR 								(1<<15)
#define CAN_INTERRUPT_WAKE_UP 							(1<<16)
#define CAN_INTERRUPT_SLEEP 							(1<<17)

/*@ref CAN_Filter_Type*/
#define CAN_FILTER_TYPE_1ID32_1MASK32					0
#define CAN_FILTER_TYPE_2ID32							1
#define CAN_FILTER_TYPE_2ID16_2MASK16					2
#define CAN_FILTER_TYPE_4ID16							3

/*@ref CAN_FrameType*/
typedef enum FrameType{
	CAN_Data_Frame,
	CAN_Remote_Frame,
}CAN_FrameType;

/*@ref CAN_IdType*/
typedef enum IdType{
	CAN_Standard_Id,
	CAN_Extended_Id,
}CAN_IdType;

typedef enum TxInterrupt{
	CAN_TxInterrupt_TRANSMIT_EMPTY,
}CAN_TxInterrupt;

typedef enum RxInterrupt{
	CAN_RxInterrupt_FIFO0_MSG_PEND,
	CAN_RxInterrupt_FIFO0_FULL,
	CAN_RxInterrupt_FIFO0_OVERRUN,
	CAN_RxInterrupt_FIFO1_MSG_PEND,
	CAN_RxInterrupt_FIFO1_FULL,
	CAN_RxInterrupt_FIFO1_OVERRUN

}CAN_RxInterrupt;

typedef enum Error{
	CAN_NoError,
	CAN_StuffError,
	CAN_FormError,
	CAN_AcknowledgmentError,
	CAN_BitRecessiveError,
	CAN_BitDominantError,
	CAN_CRCError,
	CAN_SoftwareError
}CAN_Error;

/*
==================================================
  End   Section --> Macro Declaration
==================================================
 */


/*
==================================================
  Start Section --> CAN Configurations available options
==================================================
 */

typedef struct{
	/*Id of received data*/
	u32 ID;

	/*Array of received data*/
	u8  ReceivedData[8];

	/*Select ID Wheter it's Standard or Extended*/
	/*@ref CAN_IdType*/
	CAN_IdType IdType;

	/*Select Whether it's Data or Remote Frame.
	 * takes values from @ref CAN_FrameType
	 * */
	CAN_FrameType FrameType;

	/*Data length of received data*/
	u8 DataLength:4;

	/*Filter id that received data*/
	u8 FilterId;
}CAN_RxData;

typedef struct
{
	/*Id of data that will be transmitted.*/
	u32 ID;
	/*Pointer of data that will be transmitted.*/
	u8 *DataPtr;
	/*Maximum is 8 bytes*/
	u8 DataLength;
	/*Select ID Wheter it's Standard or Extended
	 * takes values from @ref CAN_IdType
	 * */
	CAN_IdType IdType;

	/*Select Wheter it's Data or Remote Frame.*/

	/*Select Whether it's Data or Remote Frame.
	 * takes values from @ref CAN_FrameType
	 * */
	CAN_FrameType FrameType;
	/*This parameter take a value of @ref CAN_Filter_FIFO_Number*/
	u8 FIFONumbers:1;
}CAN_TxData;

typedef struct CAN_Cfg{
	/* Enable or disable time triggered communication.*/
	u8 TimeTriggeredEn:1;
	/* Enable or disable Automatic bus-off management
	 * This mode controls the behavior of the CAN hardware on leaving the Buss-Off state.
	 * When Enabling this mode, Bus-Off state is left automatically
	 * by hardware once 128 occurrence of 11 recessive bits have been monitored.
	 *
	 * When Disabling this mode, Bus-Off state is left on software request, once 128 occurances of
	 * 11 recessive bits have been monitored and software has first set and cleared the INRQ bit of the CAN_MCR
	 * */
	u8 AutoBusOffEn:1;
	/* Enable or disable Automatic wake-up mode.
	 * This mode controls the behavior of the CAN hardware on message reception during sleep mode.
	 * When Enabling this mode, Sleep mode is left automatically by hardware on CAN message detection
	 *
	 * When Disabling this mode, Sleep mode is left on software request by clearing the SLEEP bit of the CAN_MCR register.
	 * */
	u8 AutoWakeUpEn:1;
	/* Enable or disable Automatic retransmission mode.
	 * When Enabling this mode, CAN hardware will automatically retransmit the message
	 * until it has been successfully transmitted according to the CAN standard.
	 *
	 * When Disabling this mode, Message will be transmitted only once independently of
	 * the transmission result.
	 * */
	u8 AutoReTransmissionEn:1;
	/* Enable or disable Receive FIFO Lock in case of overrun.
	 *
	 * When Enabling this mode, Receive FIFO is locked against overrun,
	 * and once a receive FIFO is full the next incoming message will be discarded.
	 *
	 * When Disabling this mode, Receive FIFO is not-locked against overrun,
	 * and once a receive FIFO is full the next incoming message will override the previous one.
	 * */
	u8 ReceiveFifoLockOnOverrunEn:1;
	/* Select the priority of Transmit FIFO whether
	 * priority is driven by ID of the message, or
	 * priority is driven by the request order.
	 * */
	u8 TransmitFifoPriority:1;
	/*This parameter take a value of @ref CAN_Operating_Mode*/
	u8 OperatingMode:2;
	/*This parameter can be the value of CAN instance for example
	 * If you want to configure CAN1, This parameter will take the value 1*/
	u8 InstanceId;
	u16 BaudRatePrescaller;
	u8 TimeSegment_1;
	u8 TimeSegment_2;
	u8 ResychronizationJump;
	/*This parameter can be the value of GPIO instance used by CAN for example
	 * If you want to configure GPIOA, This parameter will take the value 'A'*/
	u8 GPIOInstanceId;
	/*This parameter can be the value of assigned pins for SPI instance
	 * using the following pattern
	 * PIN_x_MASK | PIN_y_MASK | PIN_z_MASK
	 * where x, y, and z are the values of selected pins
	 * for example if you want to configure Pin A0, A3, A10
	 * This parameter will take
	 * PIN_0_MASK | PIN_3_MASK | PIN_10_MASK
	 * */
	u16 GPIOPins;

	/*This parameter take a value of @ref CAN_Interrupt*/
	u32 Interrupt;
}CAN_Cfg;

typedef struct{
	/*This parameter take a value of @ref CAN_Filter_Type*/
	u8 FilterType;

	u8 FilterId;
	u32 ID1;
	u32 ID2;
	u32 ID3;
	u32 ID4;
	u32 Mask1;
	u32 Mask2;
	/*This parameter take a value of @ref CAN_Filter_FIFO_Number*/
	u8 FIFONumber:1;

	/*Select ID Wheter it's Standard or Extended*/
	u8 IdType:1;
	/*Select Wheter it's Data or Remote Frame.*/
	/*This parameter take a value of @ref CAN_FrameType*/
	u8 FrameType:1;


}CAN_FilterConfig;


/*
==================================================
  End   Section --> CAN Configurations available options
==================================================
 */


/*
==================================================
  Start Section --> APIs
==================================================
 */

/* @brief  --> This function configures CAN based on configuration passed through CAN_Cfg struct.
 * @param  Arg_conf_cpcCAN_Cfg --> struct that have configured parameters.
 * @retval --> None.
 * */

void CAN_Config_v(CAN_Cfg const * const Arg_conf_cpcCAN_Cfg);

/* @brief  --> This function transmits data using CAN.
 * @param  Arg_conf_cpcCAN_Cfg --> struct that have configured parameters.
 * @param  Arg_TransmitData_cpcCAN_TxData --> struct that have configured parameters of Transmit data and configuration of Transmit Mailbox.
 * @param  Arg_ToutVal_Cu32 --> Timeout value in millisecond of received data. For infinite time, pass STD_MAX_DELAY.
 * @param  Arg_ToutErr_pCu32 --> To determine whether received data is complete or exceed timeout value.
 * @retval --> None.
 * */
void CAN_SendData_v(CAN_Cfg const * const Arg_conf_cpcCAN_Cfg, CAN_TxData const * const Arg_TransmitData_cpcCAN_TxData,
		const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32);

/* @brief  --> This function adds filter of received messages of can.
 * @param  Arg_conf_cpcCAN_Cfg --> struct that have configured parameters.
 * @param  Arg_FilterCfg_CAN_FilterConfig --> Filter configuration of CAN.
 * @retval --> None.
 * */
void CAN_AddRxFilter_v(CAN_Cfg const * const Arg_conf_cpcCAN_Cfg, CAN_FilterConfig *Arg_FilterCfg_CAN_FilterConfig);

/* @brief  --> This function removes filter of received messages of can.
 * @param  Arg_conf_cpcCAN_Cfg --> struct that have configured parameters.
 * @param  Arg_FilterCfg_CAN_FilterConfig --> Filter configuration of CAN.
 * @retval --> None.
 * */
void CAN_RemoveRxFilter_v(CAN_Cfg const * const Arg_conf_cpcCAN_Cfg, CAN_FilterConfig *Arg_FilterCfg_CAN_FilterConfig);

/* @brief  --> This function receives data using CAN.
 * @param  Arg_conf_cpcCAN_Cfg --> struct that have configured parameters.
 * @param  Arg_RXData_CAN_RxData --> struct that have configured parameters of received data.
 * @param  Arg_ToutVal_Cu32 --> Timeout value in millisecond of received data. For infinite time, pass STD_MAX_DELAY.
 * @param  Arg_ToutErr_pCu32 --> To determine whether received data is complete or exceed timeout value.
 * @retval --> None.
 * */
void CAN_Receive_v(CAN_Cfg const * const Arg_conf_cpcCAN_Cfg, CAN_RxData *Arg_RXData_CAN_RxData,
		const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32);


CAN_Error CAN_GetErrorInterrupt_u8(u8 Arg_CANInstanceId_u8);
Bool CAN_CheckInterruptAndClear_Bool(u8 Arg_CANInstanceId_u8, u8 Arg_CANInterruptType_u8);
/*
==================================================
  End   Section --> APIs
==================================================
 */
#endif /* HMCAL_CAN_CAN_H_ */
