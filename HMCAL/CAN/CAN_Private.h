/*
 * File Name --> CAN_Private.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> CAN driver private info like addresses.
 * */


#ifndef HMCAL_CAN_CAN_PRIVATE_H_
#define HMCAL_CAN_CAN_PRIVATE_H_

/*
==================================================
  Start Section --> File Includes
==================================================
*/
#include "LIB/STD_TYPES.h"
/*
==================================================
  End   Section --> File Includes
==================================================
*/

/*
==================================================
  Start Section --> Define peripheral addresses.
==================================================
 */
#define CAN1_BASE_ADDRESS	0x40006400
#define CAN2_BASE_ADDRESS	0x40006800

/*
==================================================
  End Section --> Define peripheral addresses.
==================================================
 */

/*
==================================================
  Start Section --> Reset values.
==================================================
*/
#define CAN_MCR_RESET_VALUE			0x00010002
#define CAN_MSR_RESET_VALUE			0x00000C02
#define CAN_TSR_RESET_VALUE			0x1C000000
#define CAN_IER_RESET_VALUE			0x00000000
#define CAN_ESR_RESET_VALUE			0x00000000
#define CAN_BTR_RESET_VALUE			0x01230000
#define CAN_FMR_RESET_VALUE			0x2A1C0E01
#define CAN_FM1R_RESET_VALUE		0x00000000
#define CAN_FS1R_RESET_VALUE		0x00000000
#define CAN_FFA1R_RESET_VALUE		0x00000000
#define CAN_FA1R_RESET_VALUE		0x00000000

/*
==================================================
  End Section --> Reset values.
==================================================
*/

/*
==================================================
  Start Section --> Peripheral register mapping.
==================================================
 */


typedef struct
{
	/*CAN TX mailbox identifier register (CAN_TIxR) (x=0..2)*/
	volatile u32 TIR;
	/*CAN mailbox data length control and time stamp register (CAN_TDTxR)*/
	volatile u32 TDTR;
	/*CAN mailbox data low register (CAN_TDLxR) (x=0..2)*/
	volatile u32 TDLR;
	/*CAN mailbox data high register (CAN_TDHxR) (x=0..2)*/
	volatile u32 TDHR;
} CAN_TxMailBox;

typedef struct
{
	/*CAN receive FIFO mailbox identifier register (CAN_RIxR) (x=0..1)*/
	volatile u32 RIR;
	/*CAN receive FIFO mailbox data length control and time stamp register (CAN_RDTxR) (x=0..1)*/
	volatile u32 RDTR;
	/*CAN receive FIFO mailbox data low register (CAN_RDLxR) (x=0..1)*/
	volatile u32 RDLR;
	/*CAN receive FIFO mailbox data high register (CAN_RDHxR) (x=0..1)*/
	volatile u32 RDHR;
} CAN_FIFOMailBox;


typedef struct
{
	volatile u32 FR1;
	volatile u32 FR2;
} CAN_FilterRegister;

typedef struct
{
	/*CAN master control register*/
	volatile u32 MCR;
	/*CAN master status register*/
	volatile u32 MSR;
	/*CAN transmit status register*/
	volatile u32 TSR;
	/*CAN receive FIFO 0, 1 register*/
	volatile u32 RFxR[2];
	/*CAN interrupt enable register*/
	volatile u32 IER;
	/*CAN error status register*/
	volatile u32 ESR;
	/*CAN bit timing register*/
	volatile u32 BTR;
	volatile u32 Reserved_0[88];
	volatile CAN_TxMailBox	TxMailBox[3];
	volatile CAN_FIFOMailBox	FIFOMailBox[2];
	volatile u32 Reserved_1[12];
	/*CAN filter master register (CAN_FMR)*/
	volatile u32 FMR;
	/*CAN filter mode register (CAN_FM1R)*/
	volatile u32 FM1R;
	volatile u32 Reserved_2;
	/*CAN filter scale register (CAN_FS1R)*/
	volatile u32 FS1R;
	volatile u32 Reserved_3;
	/*CAN filter FIFO assignment register (CAN_FFA1R)*/
	volatile u32 FFA1R;
	volatile u32 Reserved_4;
	/*CAN filter activation register (CAN_FA1R)*/
	volatile u32 FA1R;
	volatile u32 Reserved_5[8];
	/*Filter bank i register x (CAN_FiRx) (i=0..27, x=1, 2)*/
	volatile CAN_FilterRegister FilterRegister[28];
} CAN_MemMap;

/*
==================================================
  End Section --> Peripheral register mapping.
==================================================
 */


typedef enum FilterScale{
	CAN_Filter_Scale_Single,
	CAN_Filter_Scale_Dual,
}FilterScale;
typedef enum FilterMode{
	CAN_Filter_Mode_Mask,
	CAN_Filter_Mode_Id,
}FilterMode;


/*
==================================================
  Start Section --> Define peripheral with it's address.
==================================================
 */

const static u32 GCS_CAN_InstanceIdMapping_u32[]={
		CAN1_BASE_ADDRESS,
		CAN2_BASE_ADDRESS,
};

/*
==================================================
  End Section --> Define peripheral with it's address.
==================================================
 */


/*
==================================================
  Start Section --> Define Mailbox props.
==================================================
 */

#define 	CAN_TRANSMIT_MAILBOX_NUMS			3
#define 	CAN_RECEIVE_FIFO_NUMS				2
#define 	CAN_RECEIVE_FIFO_STAGES_NUMS		3


/*
==================================================
  End Section --> Define Mailbox props.
==================================================
 */
#endif /* HMCAL_CAN_CAN_PRIVATE_H_ */
