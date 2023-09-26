/*
 * File Name --> CAN_defs.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 */

#ifndef HMCAL_CAN_CAN_DEFS_H_
#define HMCAL_CAN_CAN_DEFS_H_

/*
==================================================
  Start Section --> Bit definitions
==================================================
*/
/*Bit definition for CAN_MCR register.*/
#define CAN_MCR_INRQ       0
#define CAN_MCR_SLEEP      1
#define CAN_MCR_TXFP       2
#define CAN_MCR_RFLM       3
#define CAN_MCR_NART       4
#define CAN_MCR_AWUM       5
#define CAN_MCR_ABOM       6
#define CAN_MCR_TTCM       7
#define CAN_MCR_RESET      15
#define CAN_MCR_DBF        16
/*Bit definition for CAN_MSR register.*/
#define CAN_MSR_INAK       0
#define CAN_MSR_SLAK       1
#define CAN_MSR_ERRI       2
#define CAN_MSR_WKUI       3
#define CAN_MSR_SLAKI      4
#define CAN_MSR_TXM        8
#define CAN_MSR_RXM        9
#define CAN_MSR_SAMP       10
#define CAN_MSR_RX         11

/*Bit definition for CAN_TSR register.*/
#define CAN_TSR_RQCP0      0
#define CAN_TSR_TXOK0      1
#define CAN_TSR_ALST0      2
#define CAN_TSR_TERR0      3
#define CAN_TSR_ABRQ0      7
#define CAN_TSR_RQCP1      8
#define CAN_TSR_TXOK1      9
#define CAN_TSR_ALST1      10
#define CAN_TSR_TERR1      11
#define CAN_TSR_ABRQ1      15
#define CAN_TSR_RQCP2      16
#define CAN_TSR_TXOK2      17
#define CAN_TSR_ALST2      18
#define CAN_TSR_TERR2      19
#define CAN_TSR_ABRQ2      23
#define CAN_TSR_CODE       24

#define CAN_TSR_TME        26
#define CAN_TSR_TME0       26
#define CAN_TSR_TME1       27
#define CAN_TSR_TME2       28

#define CAN_TSR_LOW        29
#define CAN_TSR_LOW0       29
#define CAN_TSR_LOW1       30
#define CAN_TSR_LOW2       31

/*Bit definition for CAN_RF0R register.*/
#define CAN_RF0R_FMP0      0
#define CAN_RF0R_FULL0     3
#define CAN_RF0R_FOVR0     4
#define CAN_RF0R_RFOM0     5

/*Bit definition for CAN_RF1R register.*/
#define CAN_RF1R_FMP1      0
#define CAN_RF1R_FULL1     3
#define CAN_RF1R_FOVR1     4
#define CAN_RF1R_RFOM1     5

/*Bit definition for CAN_IER register.*/
#define CAN_IER_TMEIE      0
#define CAN_IER_FMPIE0     1
#define CAN_IER_FFIE0      2
#define CAN_IER_FOVIE0     3
#define CAN_IER_FMPIE1     4
#define CAN_IER_FFIE1      5
#define CAN_IER_FOVIE1     6
#define CAN_IER_EWGIE      8
#define CAN_IER_EPVIE      9
#define CAN_IER_BOFIE      10
#define CAN_IER_LECIE      11
#define CAN_IER_ERRIE      15
#define CAN_IER_WKUIE      16
#define CAN_IER_SLKIE      17
#define CAN_IER_EWGIE      8

/*Bit definition for CAN_ESR register.*/
#define CAN_ESR_EWGF       0
#define CAN_ESR_EPVF       1
#define CAN_ESR_BOFF       2

#define CAN_ESR_LEC        4
#define CAN_ESR_LEC_0      (CAN_ESR_LEC + 0)
#define CAN_ESR_LEC_1      (CAN_ESR_LEC + 1)
#define CAN_ESR_LEC_2      (CAN_ESR_LEC + 2)

#define CAN_ESR_TEC        16
#define CAN_ESR_REC        24

/*Bit definition for CAN_BTR register.*/
#define CAN_BTR_BRP        0
#define CAN_BTR_TS1        16
#define CAN_BTR_TS2        20
#define CAN_BTR_SJW        24
#define CAN_BTR_LBKM       30
#define CAN_BTR_SILM       31


/*Mailbox registers.*/

/*Bit definition for CAN_TIxR register.*/
#define CAN_TIxR_TXRQ      0
#define CAN_TIxR_RTR       1
#define CAN_TIxR_IDE       2
#define CAN_TIxR_EXID      3
#define CAN_TIxR_STID      21

/*Bit definition for CAN_TI0R register.*/
#define CAN_TI0R_TXRQ      0
#define CAN_TI0R_RTR       1
#define CAN_TI0R_IDE       2
#define CAN_TI0R_EXID      3
#define CAN_TI0R_STID      21

/*Bit definition for CAN_TDT0R register.*/
#define CAN_TDT0R_DLC_0    0
#define CAN_TDT0R_DLC_1    1
#define CAN_TDT0R_DLC_2    2
#define CAN_TDT0R_DLC_3    3

#define CAN_TDT0R_TGT      8
#define CAN_TDT0R_TIME     16

/*Bit definition for CAN_TDL0R register.*/
#define CAN_TDL0R_DATA0    0
#define CAN_TDL0R_DATA1    8
#define CAN_TDL0R_DATA2    16
#define CAN_TDL0R_DATA3    24

/*Bit definition for CAN_TDH0R register.*/
#define CAN_TDH0R_DATA4    0
#define CAN_TDH0R_DATA5    8
#define CAN_TDH0R_DATA6    16
#define CAN_TDH0R_DATA7    24

/*Bit definition for CAN_TI1R register.*/
#define CAN_TI1R_TXRQ      0
#define CAN_TI1R_RTR       1
#define CAN_TI1R_IDE       2
#define CAN_TI1R_EXID      3
#define CAN_TI1R_STID      21

/*Bit definition for CAN_TDT1R register.*/
#define CAN_TDT1R_DLC      0
#define CAN_TDT1R_TGT      8
#define CAN_TDT1R_TIME     16

/*Bit definition for CAN_TDL1R register.*/
#define CAN_TDL1R_DATA0    0
#define CAN_TDL1R_DATA1    8
#define CAN_TDL1R_DATA2    16
#define CAN_TDL1R_DATA3    24

/*Bit definition for CAN_TDH1R register.*/
#define CAN_TDH1R_DATA4    0
#define CAN_TDH1R_DATA5    8
#define CAN_TDH1R_DATA6    16
#define CAN_TDH1R_DATA7    24

/*Bit definition for CAN_TI2R register.*/
#define CAN_TI2R_TXRQ      0
#define CAN_TI2R_RTR       1
#define CAN_TI2R_IDE       2
#define CAN_TI2R_EXID      3
#define CAN_TI2R_STID      21

/*Bit definition for CAN_TDT2R register.*/
#define CAN_TDT2R_DLC      0
#define CAN_TDT2R_TGT      8
#define CAN_TDT2R_TIME     16

/*Bit definition for CAN_TDL2R register.*/
#define CAN_TDL2R_DATA0    0
#define CAN_TDL2R_DATA1    8
#define CAN_TDL2R_DATA2    16
#define CAN_TDL2R_DATA3    24

/*Bit definition for CAN_TDH2R register.*/
#define CAN_TDH2R_DATA4    0
#define CAN_TDH2R_DATA5    8
#define CAN_TDH2R_DATA6    16
#define CAN_TDH2R_DATA7    24

/*Bit definition for CAN_RIxR register.*/
#define CAN_RIxR_RTR       1
#define CAN_RIxR_IDE       2
#define CAN_RIxR_EXID      3
#define CAN_RIxR_STID      21

/*Bit definition for CAN_RI0R register.*/
#define CAN_RI0R_RTR       1
#define CAN_RI0R_IDE       2
#define CAN_RI0R_EXID      3
#define CAN_RI0R_STID      21

/*Bit definition for CAN_RDTxR register.*/
#define CAN_RDTxR_DLC      0
#define CAN_RDTxR_FMI      8
#define CAN_RDTxR_TIME     16

/*Bit definition for CAN_RDT0R register.*/
#define CAN_RDT0R_DLC      0
#define CAN_RDT0R_FMI      8
#define CAN_RDT0R_TIME     16

/*Bit definition for CAN_RDL0R register.*/
#define CAN_RDL0R_DATA0    0
#define CAN_RDL0R_DATA1    8
#define CAN_RDL0R_DATA2    16
#define CAN_RDL0R_DATA3    24

/*Bit definition for CAN_RDH0R register.*/
#define CAN_RDH0R_DATA4    0
#define CAN_RDH0R_DATA5    8
#define CAN_RDH0R_DATA6    16
#define CAN_RDH0R_DATA7    24

/*Bit definition for CAN_RI1R register.*/
#define CAN_RI1R_RTR       1
#define CAN_RI1R_IDE       2
#define CAN_RI1R_EXID      3
#define CAN_RI1R_STID      21

/*Bit definition for CAN_RDT1R register.*/
#define CAN_RDT1R_DLC      0
#define CAN_RDT1R_FMI      8
#define CAN_RDT1R_TIME     16

/*Bit definition for CAN_RDL1R register.*/
#define CAN_RDL1R_DATA0    0
#define CAN_RDL1R_DATA1    8
#define CAN_RDL1R_DATA2    16
#define CAN_RDL1R_DATA3    24

/*Bit definition for CAN_RDH1R register.*/
#define CAN_RDH1R_DATA4    0
#define CAN_RDH1R_DATA5    8
#define CAN_RDH1R_DATA6    16
#define CAN_RDH1R_DATA7    24

/*!<CAN filter registers */
/*Bit definition for CAN_FMR register.*/
#define CAN_FMR_FINIT      0
#define CAN_FMR_CAN2SB     8

/*Bit definition for CAN_FM1R register.*/
#define CAN_FM1R_FBM       0
#define CAN_FM1R_FBM0      0
#define CAN_FM1R_FBM1      1
#define CAN_FM1R_FBM2      2
#define CAN_FM1R_FBM3      3
#define CAN_FM1R_FBM4      4
#define CAN_FM1R_FBM5      5
#define CAN_FM1R_FBM6      6
#define CAN_FM1R_FBM7      7
#define CAN_FM1R_FBM8      8
#define CAN_FM1R_FBM9      9
#define CAN_FM1R_FBM10     10
#define CAN_FM1R_FBM11     11
#define CAN_FM1R_FBM12     12
#define CAN_FM1R_FBM13     13
#define CAN_FM1R_FBM14     14
#define CAN_FM1R_FBM15     15
#define CAN_FM1R_FBM16     16
#define CAN_FM1R_FBM17     17
#define CAN_FM1R_FBM18     18
#define CAN_FM1R_FBM19     19
#define CAN_FM1R_FBM20     20
#define CAN_FM1R_FBM21     21
#define CAN_FM1R_FBM22     22
#define CAN_FM1R_FBM23     23
#define CAN_FM1R_FBM24     24
#define CAN_FM1R_FBM25     25
#define CAN_FM1R_FBM26     26
#define CAN_FM1R_FBM27     27

/*Bit definition for CAN_FS1R register.*/
#define CAN_FS1R_FSC       0
#define CAN_FS1R_FSC0      0
#define CAN_FS1R_FSC1      1
#define CAN_FS1R_FSC2      2
#define CAN_FS1R_FSC3      3
#define CAN_FS1R_FSC4      4
#define CAN_FS1R_FSC5      5
#define CAN_FS1R_FSC6      6
#define CAN_FS1R_FSC7      7
#define CAN_FS1R_FSC8      8
#define CAN_FS1R_FSC9      9
#define CAN_FS1R_FSC10     10
#define CAN_FS1R_FSC11     11
#define CAN_FS1R_FSC12     12
#define CAN_FS1R_FSC13     13
#define CAN_FS1R_FSC14     14
#define CAN_FS1R_FSC15     15
#define CAN_FS1R_FSC16     16
#define CAN_FS1R_FSC17     17
#define CAN_FS1R_FSC18     18
#define CAN_FS1R_FSC19     19
#define CAN_FS1R_FSC20     20
#define CAN_FS1R_FSC21     21
#define CAN_FS1R_FSC22     22
#define CAN_FS1R_FSC23     23
#define CAN_FS1R_FSC24     24
#define CAN_FS1R_FSC25     25
#define CAN_FS1R_FSC26     26
#define CAN_FS1R_FSC27     27

/*Bit definition for CAN_FFA1R register.*/
#define CAN_FFA1R_FFA      0
#define CAN_FFA1R_FFA0     0
#define CAN_FFA1R_FFA1     1
#define CAN_FFA1R_FFA2     2
#define CAN_FFA1R_FFA3     3
#define CAN_FFA1R_FFA4     4
#define CAN_FFA1R_FFA5     5
#define CAN_FFA1R_FFA6     6
#define CAN_FFA1R_FFA7     7
#define CAN_FFA1R_FFA8     8
#define CAN_FFA1R_FFA9     9
#define CAN_FFA1R_FFA10    10
#define CAN_FFA1R_FFA11    11
#define CAN_FFA1R_FFA12    12
#define CAN_FFA1R_FFA13    13
#define CAN_FFA1R_FFA14    14
#define CAN_FFA1R_FFA15    15
#define CAN_FFA1R_FFA16    16
#define CAN_FFA1R_FFA17    17
#define CAN_FFA1R_FFA18    18
#define CAN_FFA1R_FFA19    19
#define CAN_FFA1R_FFA20    20
#define CAN_FFA1R_FFA21    21
#define CAN_FFA1R_FFA22    22
#define CAN_FFA1R_FFA23    23
#define CAN_FFA1R_FFA24    24
#define CAN_FFA1R_FFA25    25
#define CAN_FFA1R_FFA26    26
#define CAN_FFA1R_FFA27    27

/*Bit definition for CAN_FA1R register.*/
#define CAN_FA1R_FACT      0
#define CAN_FA1R_FACT0     0
#define CAN_FA1R_FACT1     1
#define CAN_FA1R_FACT2     2
#define CAN_FA1R_FACT3     3
#define CAN_FA1R_FACT4     4
#define CAN_FA1R_FACT5     5
#define CAN_FA1R_FACT6     6
#define CAN_FA1R_FACT7     7
#define CAN_FA1R_FACT8     8
#define CAN_FA1R_FACT9     9
#define CAN_FA1R_FACT10    10
#define CAN_FA1R_FACT11    11
#define CAN_FA1R_FACT12    12
#define CAN_FA1R_FACT13    13
#define CAN_FA1R_FACT14    14
#define CAN_FA1R_FACT15    15
#define CAN_FA1R_FACT16    16
#define CAN_FA1R_FACT17    17
#define CAN_FA1R_FACT18    18
#define CAN_FA1R_FACT19    19
#define CAN_FA1R_FACT20    20
#define CAN_FA1R_FACT21    21
#define CAN_FA1R_FACT22    22
#define CAN_FA1R_FACT23    23
#define CAN_FA1R_FACT24    24
#define CAN_FA1R_FACT25    25
#define CAN_FA1R_FACT26    26
#define CAN_FA1R_FACT27    27

/*Bit definition for CAN_FiRx register.*/
#define CAN_FiRx_FB0       0
#define CAN_FiRx_FB1       1
#define CAN_FiRx_FB2       2
#define CAN_FiRx_FB3       3
#define CAN_FiRx_FB4       4
#define CAN_FiRx_FB5       5
#define CAN_FiRx_FB6       6
#define CAN_FiRx_FB7       7
#define CAN_FiRx_FB8       8
#define CAN_FiRx_FB9       9
#define CAN_FiRx_FB10      10
#define CAN_FiRx_FB11      11
#define CAN_FiRx_FB12      12
#define CAN_FiRx_FB13      13
#define CAN_FiRx_FB14      14
#define CAN_FiRx_FB15      15
#define CAN_FiRx_FB16      16
#define CAN_FiRx_FB17      17
#define CAN_FiRx_FB18      18
#define CAN_FiRx_FB19      19
#define CAN_FiRx_FB20      20
#define CAN_FiRx_FB21      21
#define CAN_FiRx_FB22      22
#define CAN_FiRx_FB23      23
#define CAN_FiRx_FB24      24
#define CAN_FiRx_FB25      25
#define CAN_FiRx_FB26      26
#define CAN_FiRx_FB27      27
#define CAN_FiRx_FB28      28
#define CAN_FiRx_FB29      29
#define CAN_FiRx_FB30      30
#define CAN_FiRx_FB31      31

/*Bit definition for CAN_F0R1 register.*/
#define CAN_F0R1_FB0       0
#define CAN_F0R1_FB1       1
#define CAN_F0R1_FB2       2
#define CAN_F0R1_FB3       3
#define CAN_F0R1_FB4       4
#define CAN_F0R1_FB5       5
#define CAN_F0R1_FB6       6
#define CAN_F0R1_FB7       7
#define CAN_F0R1_FB8       8
#define CAN_F0R1_FB9       9
#define CAN_F0R1_FB10      10
#define CAN_F0R1_FB11      11
#define CAN_F0R1_FB12      12
#define CAN_F0R1_FB13      13
#define CAN_F0R1_FB14      14
#define CAN_F0R1_FB15      15
#define CAN_F0R1_FB16      16
#define CAN_F0R1_FB17      17
#define CAN_F0R1_FB18      18
#define CAN_F0R1_FB19      19
#define CAN_F0R1_FB20      20
#define CAN_F0R1_FB21      21
#define CAN_F0R1_FB22      22
#define CAN_F0R1_FB23      23
#define CAN_F0R1_FB24      24
#define CAN_F0R1_FB25      25
#define CAN_F0R1_FB26      26
#define CAN_F0R1_FB27      27
#define CAN_F0R1_FB28      28
#define CAN_F0R1_FB29      29
#define CAN_F0R1_FB30      30
#define CAN_F0R1_FB31      31

/*Bit definition for CAN_F1R1 register.*/
#define CAN_F1R1_FB0       0
#define CAN_F1R1_FB1       1
#define CAN_F1R1_FB2       2
#define CAN_F1R1_FB3       3
#define CAN_F1R1_FB4       4
#define CAN_F1R1_FB5       5
#define CAN_F1R1_FB6       6
#define CAN_F1R1_FB7       7
#define CAN_F1R1_FB8       8
#define CAN_F1R1_FB9       9
#define CAN_F1R1_FB10      10
#define CAN_F1R1_FB11      11
#define CAN_F1R1_FB12      12
#define CAN_F1R1_FB13      13
#define CAN_F1R1_FB14      14
#define CAN_F1R1_FB15      15
#define CAN_F1R1_FB16      16
#define CAN_F1R1_FB17      17
#define CAN_F1R1_FB18      18
#define CAN_F1R1_FB19      19
#define CAN_F1R1_FB20      20
#define CAN_F1R1_FB21      21
#define CAN_F1R1_FB22      22
#define CAN_F1R1_FB23      23
#define CAN_F1R1_FB24      24
#define CAN_F1R1_FB25      25
#define CAN_F1R1_FB26      26
#define CAN_F1R1_FB27      27
#define CAN_F1R1_FB28      28
#define CAN_F1R1_FB29      29
#define CAN_F1R1_FB30      30
#define CAN_F1R1_FB31      31

/*Bit definition for CAN_F2R1 register.*/
#define CAN_F2R1_FB0       0
#define CAN_F2R1_FB1       1
#define CAN_F2R1_FB2       2
#define CAN_F2R1_FB3       3
#define CAN_F2R1_FB4       4
#define CAN_F2R1_FB5       5
#define CAN_F2R1_FB6       6
#define CAN_F2R1_FB7       7
#define CAN_F2R1_FB8       8
#define CAN_F2R1_FB9       9
#define CAN_F2R1_FB10      10
#define CAN_F2R1_FB11      11
#define CAN_F2R1_FB12      12
#define CAN_F2R1_FB13      13
#define CAN_F2R1_FB14      14
#define CAN_F2R1_FB15      15
#define CAN_F2R1_FB16      16
#define CAN_F2R1_FB17      17
#define CAN_F2R1_FB18      18
#define CAN_F2R1_FB19      19
#define CAN_F2R1_FB20      20
#define CAN_F2R1_FB21      21
#define CAN_F2R1_FB22      22
#define CAN_F2R1_FB23      23
#define CAN_F2R1_FB24      24
#define CAN_F2R1_FB25      25
#define CAN_F2R1_FB26      26
#define CAN_F2R1_FB27      27
#define CAN_F2R1_FB28      28
#define CAN_F2R1_FB29      29
#define CAN_F2R1_FB30      30
#define CAN_F2R1_FB31      31

/*Bit definition for CAN_F3R1 register.*/
#define CAN_F3R1_FB0       0
#define CAN_F3R1_FB1       1
#define CAN_F3R1_FB2       2
#define CAN_F3R1_FB3       3
#define CAN_F3R1_FB4       4
#define CAN_F3R1_FB5       5
#define CAN_F3R1_FB6       6
#define CAN_F3R1_FB7       7
#define CAN_F3R1_FB8       8
#define CAN_F3R1_FB9       9
#define CAN_F3R1_FB10      10
#define CAN_F3R1_FB11      11
#define CAN_F3R1_FB12      12
#define CAN_F3R1_FB13      13
#define CAN_F3R1_FB14      14
#define CAN_F3R1_FB15      15
#define CAN_F3R1_FB16      16
#define CAN_F3R1_FB17      17
#define CAN_F3R1_FB18      18
#define CAN_F3R1_FB19      19
#define CAN_F3R1_FB20      20
#define CAN_F3R1_FB21      21
#define CAN_F3R1_FB22      22
#define CAN_F3R1_FB23      23
#define CAN_F3R1_FB24      24
#define CAN_F3R1_FB25      25
#define CAN_F3R1_FB26      26
#define CAN_F3R1_FB27      27
#define CAN_F3R1_FB28      28
#define CAN_F3R1_FB29      29
#define CAN_F3R1_FB30      30
#define CAN_F3R1_FB31      31

/*Bit definition for CAN_F4R1 register.*/
#define CAN_F4R1_FB0       0
#define CAN_F4R1_FB1       1
#define CAN_F4R1_FB2       2
#define CAN_F4R1_FB3       3
#define CAN_F4R1_FB4       4
#define CAN_F4R1_FB5       5
#define CAN_F4R1_FB6       6
#define CAN_F4R1_FB7       7
#define CAN_F4R1_FB8       8
#define CAN_F4R1_FB9       9
#define CAN_F4R1_FB10      10
#define CAN_F4R1_FB11      11
#define CAN_F4R1_FB12      12
#define CAN_F4R1_FB13      13
#define CAN_F4R1_FB14      14
#define CAN_F4R1_FB15      15
#define CAN_F4R1_FB16      16
#define CAN_F4R1_FB17      17
#define CAN_F4R1_FB18      18
#define CAN_F4R1_FB19      19
#define CAN_F4R1_FB20      20
#define CAN_F4R1_FB21      21
#define CAN_F4R1_FB22      22
#define CAN_F4R1_FB23      23
#define CAN_F4R1_FB24      24
#define CAN_F4R1_FB25      25
#define CAN_F4R1_FB26      26
#define CAN_F4R1_FB27      27
#define CAN_F4R1_FB28      28
#define CAN_F4R1_FB29      29
#define CAN_F4R1_FB30      30
#define CAN_F4R1_FB31      31

/*Bit definition for CAN_F5R1 register.*/
#define CAN_F5R1_FB0       0
#define CAN_F5R1_FB1       1
#define CAN_F5R1_FB2       2
#define CAN_F5R1_FB3       3
#define CAN_F5R1_FB4       4
#define CAN_F5R1_FB5       5
#define CAN_F5R1_FB6       6
#define CAN_F5R1_FB7       7
#define CAN_F5R1_FB8       8
#define CAN_F5R1_FB9       9
#define CAN_F5R1_FB10      10
#define CAN_F5R1_FB11      11
#define CAN_F5R1_FB12      12
#define CAN_F5R1_FB13      13
#define CAN_F5R1_FB14      14
#define CAN_F5R1_FB15      15
#define CAN_F5R1_FB16      16
#define CAN_F5R1_FB17      17
#define CAN_F5R1_FB18      18
#define CAN_F5R1_FB19      19
#define CAN_F5R1_FB20      20
#define CAN_F5R1_FB21      21
#define CAN_F5R1_FB22      22
#define CAN_F5R1_FB23      23
#define CAN_F5R1_FB24      24
#define CAN_F5R1_FB25      25
#define CAN_F5R1_FB26      26
#define CAN_F5R1_FB27      27
#define CAN_F5R1_FB28      28
#define CAN_F5R1_FB29      29
#define CAN_F5R1_FB30      30
#define CAN_F5R1_FB31      31

/*Bit definition for CAN_F6R1 register.*/
#define CAN_F6R1_FB0       0
#define CAN_F6R1_FB1       1
#define CAN_F6R1_FB2       2
#define CAN_F6R1_FB3       3
#define CAN_F6R1_FB4       4
#define CAN_F6R1_FB5       5
#define CAN_F6R1_FB6       6
#define CAN_F6R1_FB7       7
#define CAN_F6R1_FB8       8
#define CAN_F6R1_FB9       9
#define CAN_F6R1_FB10      10
#define CAN_F6R1_FB11      11
#define CAN_F6R1_FB12      12
#define CAN_F6R1_FB13      13
#define CAN_F6R1_FB14      14
#define CAN_F6R1_FB15      15
#define CAN_F6R1_FB16      16
#define CAN_F6R1_FB17      17
#define CAN_F6R1_FB18      18
#define CAN_F6R1_FB19      19
#define CAN_F6R1_FB20      20
#define CAN_F6R1_FB21      21
#define CAN_F6R1_FB22      22
#define CAN_F6R1_FB23      23
#define CAN_F6R1_FB24      24
#define CAN_F6R1_FB25      25
#define CAN_F6R1_FB26      26
#define CAN_F6R1_FB27      27
#define CAN_F6R1_FB28      28
#define CAN_F6R1_FB29      29
#define CAN_F6R1_FB30      30
#define CAN_F6R1_FB31      31

/*Bit definition for CAN_F7R1 register.*/
#define CAN_F7R1_FB0       0
#define CAN_F7R1_FB1       1
#define CAN_F7R1_FB2       2
#define CAN_F7R1_FB3       3
#define CAN_F7R1_FB4       4
#define CAN_F7R1_FB5       5
#define CAN_F7R1_FB6       6
#define CAN_F7R1_FB7       7
#define CAN_F7R1_FB8       8
#define CAN_F7R1_FB9       9
#define CAN_F7R1_FB10      10
#define CAN_F7R1_FB11      11
#define CAN_F7R1_FB12      12
#define CAN_F7R1_FB13      13
#define CAN_F7R1_FB14      14
#define CAN_F7R1_FB15      15
#define CAN_F7R1_FB16      16
#define CAN_F7R1_FB17      17
#define CAN_F7R1_FB18      18
#define CAN_F7R1_FB19      19
#define CAN_F7R1_FB20      20
#define CAN_F7R1_FB21      21
#define CAN_F7R1_FB22      22
#define CAN_F7R1_FB23      23
#define CAN_F7R1_FB24      24
#define CAN_F7R1_FB25      25
#define CAN_F7R1_FB26      26
#define CAN_F7R1_FB27      27
#define CAN_F7R1_FB28      28
#define CAN_F7R1_FB29      29
#define CAN_F7R1_FB30      30
#define CAN_F7R1_FB31      31

/*Bit definition for CAN_F8R1 register.*/
#define CAN_F8R1_FB0       0
#define CAN_F8R1_FB1       1
#define CAN_F8R1_FB2       2
#define CAN_F8R1_FB3       3
#define CAN_F8R1_FB4       4
#define CAN_F8R1_FB5       5
#define CAN_F8R1_FB6       6
#define CAN_F8R1_FB7       7
#define CAN_F8R1_FB8       8
#define CAN_F8R1_FB9       9
#define CAN_F8R1_FB10      10
#define CAN_F8R1_FB11      11
#define CAN_F8R1_FB12      12
#define CAN_F8R1_FB13      13
#define CAN_F8R1_FB14      14
#define CAN_F8R1_FB15      15
#define CAN_F8R1_FB16      16
#define CAN_F8R1_FB17      17
#define CAN_F8R1_FB18      18
#define CAN_F8R1_FB19      19
#define CAN_F8R1_FB20      20
#define CAN_F8R1_FB21      21
#define CAN_F8R1_FB22      22
#define CAN_F8R1_FB23      23
#define CAN_F8R1_FB24      24
#define CAN_F8R1_FB25      25
#define CAN_F8R1_FB26      26
#define CAN_F8R1_FB27      27
#define CAN_F8R1_FB28      28
#define CAN_F8R1_FB29      29
#define CAN_F8R1_FB30      30
#define CAN_F8R1_FB31      31

/*Bit definition for CAN_F9R1 register.*/
#define CAN_F9R1_FB0       0
#define CAN_F9R1_FB1       1
#define CAN_F9R1_FB2       2
#define CAN_F9R1_FB3       3
#define CAN_F9R1_FB4       4
#define CAN_F9R1_FB5       5
#define CAN_F9R1_FB6       6
#define CAN_F9R1_FB7       7
#define CAN_F9R1_FB8       8
#define CAN_F9R1_FB9       9
#define CAN_F9R1_FB10      10
#define CAN_F9R1_FB11      11
#define CAN_F9R1_FB12      12
#define CAN_F9R1_FB13      13
#define CAN_F9R1_FB14      14
#define CAN_F9R1_FB15      15
#define CAN_F9R1_FB16      16
#define CAN_F9R1_FB17      17
#define CAN_F9R1_FB18      18
#define CAN_F9R1_FB19      19
#define CAN_F9R1_FB20      20
#define CAN_F9R1_FB21      21
#define CAN_F9R1_FB22      22
#define CAN_F9R1_FB23      23
#define CAN_F9R1_FB24      24
#define CAN_F9R1_FB25      25
#define CAN_F9R1_FB26      26
#define CAN_F9R1_FB27      27
#define CAN_F9R1_FB28      28
#define CAN_F9R1_FB29      29
#define CAN_F9R1_FB30      30
#define CAN_F9R1_FB31      31

/*Bit definition for CAN_F10R1 register.*/
#define CAN_F10R1_FB0      0
#define CAN_F10R1_FB1      1
#define CAN_F10R1_FB2      2
#define CAN_F10R1_FB3      3
#define CAN_F10R1_FB4      4
#define CAN_F10R1_FB5      5
#define CAN_F10R1_FB6      6
#define CAN_F10R1_FB7      7
#define CAN_F10R1_FB8      8
#define CAN_F10R1_FB9      9
#define CAN_F10R1_FB10     10
#define CAN_F10R1_FB11     11
#define CAN_F10R1_FB12     12
#define CAN_F10R1_FB13     13
#define CAN_F10R1_FB14     14
#define CAN_F10R1_FB15     15
#define CAN_F10R1_FB16     16
#define CAN_F10R1_FB17     17
#define CAN_F10R1_FB18     18
#define CAN_F10R1_FB19     19
#define CAN_F10R1_FB20     20
#define CAN_F10R1_FB21     21
#define CAN_F10R1_FB22     22
#define CAN_F10R1_FB23     23
#define CAN_F10R1_FB24     24
#define CAN_F10R1_FB25     25
#define CAN_F10R1_FB26     26
#define CAN_F10R1_FB27     27
#define CAN_F10R1_FB28     28
#define CAN_F10R1_FB29     29
#define CAN_F10R1_FB30     30
#define CAN_F10R1_FB31     31

/*Bit definition for CAN_F11R1 register.*/
#define CAN_F11R1_FB0      0
#define CAN_F11R1_FB1      1
#define CAN_F11R1_FB2      2
#define CAN_F11R1_FB3      3
#define CAN_F11R1_FB4      4
#define CAN_F11R1_FB5      5
#define CAN_F11R1_FB6      6
#define CAN_F11R1_FB7      7
#define CAN_F11R1_FB8      8
#define CAN_F11R1_FB9      9
#define CAN_F11R1_FB10     10
#define CAN_F11R1_FB11     11
#define CAN_F11R1_FB12     12
#define CAN_F11R1_FB13     13
#define CAN_F11R1_FB14     14
#define CAN_F11R1_FB15     15
#define CAN_F11R1_FB16     16
#define CAN_F11R1_FB17     17
#define CAN_F11R1_FB18     18
#define CAN_F11R1_FB19     19
#define CAN_F11R1_FB20     20
#define CAN_F11R1_FB21     21
#define CAN_F11R1_FB22     22
#define CAN_F11R1_FB23     23
#define CAN_F11R1_FB24     24
#define CAN_F11R1_FB25     25
#define CAN_F11R1_FB26     26
#define CAN_F11R1_FB27     27
#define CAN_F11R1_FB28     28
#define CAN_F11R1_FB29     29
#define CAN_F11R1_FB30     30
#define CAN_F11R1_FB31     31

/*Bit definition for CAN_F12R1 register.*/
#define CAN_F12R1_FB0      0
#define CAN_F12R1_FB1      1
#define CAN_F12R1_FB2      2
#define CAN_F12R1_FB3      3
#define CAN_F12R1_FB4      4
#define CAN_F12R1_FB5      5
#define CAN_F12R1_FB6      6
#define CAN_F12R1_FB7      7
#define CAN_F12R1_FB8      8
#define CAN_F12R1_FB9      9
#define CAN_F12R1_FB10     10
#define CAN_F12R1_FB11     11
#define CAN_F12R1_FB12     12
#define CAN_F12R1_FB13     13
#define CAN_F12R1_FB14     14
#define CAN_F12R1_FB15     15
#define CAN_F12R1_FB16     16
#define CAN_F12R1_FB17     17
#define CAN_F12R1_FB18     18
#define CAN_F12R1_FB19     19
#define CAN_F12R1_FB20     20
#define CAN_F12R1_FB21     21
#define CAN_F12R1_FB22     22
#define CAN_F12R1_FB23     23
#define CAN_F12R1_FB24     24
#define CAN_F12R1_FB25     25
#define CAN_F12R1_FB26     26
#define CAN_F12R1_FB27     27
#define CAN_F12R1_FB28     28
#define CAN_F12R1_FB29     29
#define CAN_F12R1_FB30     30
#define CAN_F12R1_FB31     31

/*Bit definition for CAN_F13R1 register.*/
#define CAN_F13R1_FB0      0
#define CAN_F13R1_FB1      1
#define CAN_F13R1_FB2      2
#define CAN_F13R1_FB3      3
#define CAN_F13R1_FB4      4
#define CAN_F13R1_FB5      5
#define CAN_F13R1_FB6      6
#define CAN_F13R1_FB7      7
#define CAN_F13R1_FB8      8
#define CAN_F13R1_FB9      9
#define CAN_F13R1_FB10     10
#define CAN_F13R1_FB11     11
#define CAN_F13R1_FB12     12
#define CAN_F13R1_FB13     13
#define CAN_F13R1_FB14     14
#define CAN_F13R1_FB15     15
#define CAN_F13R1_FB16     16
#define CAN_F13R1_FB17     17
#define CAN_F13R1_FB18     18
#define CAN_F13R1_FB19     19
#define CAN_F13R1_FB20     20
#define CAN_F13R1_FB21     21
#define CAN_F13R1_FB22     22
#define CAN_F13R1_FB23     23
#define CAN_F13R1_FB24     24
#define CAN_F13R1_FB25     25
#define CAN_F13R1_FB26     26
#define CAN_F13R1_FB27     27
#define CAN_F13R1_FB28     28
#define CAN_F13R1_FB29     29
#define CAN_F13R1_FB30     30
#define CAN_F13R1_FB31     31

/*Bit definition for CAN_F0R2 register.*/
#define CAN_F0R2_FB0       0
#define CAN_F0R2_FB1       1
#define CAN_F0R2_FB2       2
#define CAN_F0R2_FB3       3
#define CAN_F0R2_FB4       4
#define CAN_F0R2_FB5       5
#define CAN_F0R2_FB6       6
#define CAN_F0R2_FB7       7
#define CAN_F0R2_FB8       8
#define CAN_F0R2_FB9       9
#define CAN_F0R2_FB10      10
#define CAN_F0R2_FB11      11
#define CAN_F0R2_FB12      12
#define CAN_F0R2_FB13      13
#define CAN_F0R2_FB14      14
#define CAN_F0R2_FB15      15
#define CAN_F0R2_FB16      16
#define CAN_F0R2_FB17      17
#define CAN_F0R2_FB18      18
#define CAN_F0R2_FB19      19
#define CAN_F0R2_FB20      20
#define CAN_F0R2_FB21      21
#define CAN_F0R2_FB22      22
#define CAN_F0R2_FB23      23
#define CAN_F0R2_FB24      24
#define CAN_F0R2_FB25      25
#define CAN_F0R2_FB26      26
#define CAN_F0R2_FB27      27
#define CAN_F0R2_FB28      28
#define CAN_F0R2_FB29      29
#define CAN_F0R2_FB30      30
#define CAN_F0R2_FB31      31

/*Bit definition for CAN_F1R2 register.*/
#define CAN_F1R2_FB0       0
#define CAN_F1R2_FB1       1
#define CAN_F1R2_FB2       2
#define CAN_F1R2_FB3       3
#define CAN_F1R2_FB4       4
#define CAN_F1R2_FB5       5
#define CAN_F1R2_FB6       6
#define CAN_F1R2_FB7       7
#define CAN_F1R2_FB8       8
#define CAN_F1R2_FB9       9
#define CAN_F1R2_FB10      10
#define CAN_F1R2_FB11      11
#define CAN_F1R2_FB12      12
#define CAN_F1R2_FB13      13
#define CAN_F1R2_FB14      14
#define CAN_F1R2_FB15      15
#define CAN_F1R2_FB16      16
#define CAN_F1R2_FB17      17
#define CAN_F1R2_FB18      18
#define CAN_F1R2_FB19      19
#define CAN_F1R2_FB20      20
#define CAN_F1R2_FB21      21
#define CAN_F1R2_FB22      22
#define CAN_F1R2_FB23      23
#define CAN_F1R2_FB24      24
#define CAN_F1R2_FB25      25
#define CAN_F1R2_FB26      26
#define CAN_F1R2_FB27      27
#define CAN_F1R2_FB28      28
#define CAN_F1R2_FB29      29
#define CAN_F1R2_FB30      30
#define CAN_F1R2_FB31      31

/*Bit definition for CAN_F2R2 register.*/
#define CAN_F2R2_FB0       0
#define CAN_F2R2_FB1       1
#define CAN_F2R2_FB2       2
#define CAN_F2R2_FB3       3
#define CAN_F2R2_FB4       4
#define CAN_F2R2_FB5       5
#define CAN_F2R2_FB6       6
#define CAN_F2R2_FB7       7
#define CAN_F2R2_FB8       8
#define CAN_F2R2_FB9       9
#define CAN_F2R2_FB10      10
#define CAN_F2R2_FB11      11
#define CAN_F2R2_FB12      12
#define CAN_F2R2_FB13      13
#define CAN_F2R2_FB14      14
#define CAN_F2R2_FB15      15
#define CAN_F2R2_FB16      16
#define CAN_F2R2_FB17      17
#define CAN_F2R2_FB18      18
#define CAN_F2R2_FB19      19
#define CAN_F2R2_FB20      20
#define CAN_F2R2_FB21      21
#define CAN_F2R2_FB22      22
#define CAN_F2R2_FB23      23
#define CAN_F2R2_FB24      24
#define CAN_F2R2_FB25      25
#define CAN_F2R2_FB26      26
#define CAN_F2R2_FB27      27
#define CAN_F2R2_FB28      28
#define CAN_F2R2_FB29      29
#define CAN_F2R2_FB30      30
#define CAN_F2R2_FB31      31

/*Bit definition for CAN_F3R2 register.*/
#define CAN_F3R2_FB0       0
#define CAN_F3R2_FB1       1
#define CAN_F3R2_FB2       2
#define CAN_F3R2_FB3       3
#define CAN_F3R2_FB4       4
#define CAN_F3R2_FB5       5
#define CAN_F3R2_FB6       6
#define CAN_F3R2_FB7       7
#define CAN_F3R2_FB8       8
#define CAN_F3R2_FB9       9
#define CAN_F3R2_FB10      10
#define CAN_F3R2_FB11      11
#define CAN_F3R2_FB12      12
#define CAN_F3R2_FB13      13
#define CAN_F3R2_FB14      14
#define CAN_F3R2_FB15      15
#define CAN_F3R2_FB16      16
#define CAN_F3R2_FB17      17
#define CAN_F3R2_FB18      18
#define CAN_F3R2_FB19      19
#define CAN_F3R2_FB20      20
#define CAN_F3R2_FB21      21
#define CAN_F3R2_FB22      22
#define CAN_F3R2_FB23      23
#define CAN_F3R2_FB24      24
#define CAN_F3R2_FB25      25
#define CAN_F3R2_FB26      26
#define CAN_F3R2_FB27      27
#define CAN_F3R2_FB28      28
#define CAN_F3R2_FB29      29
#define CAN_F3R2_FB30      30
#define CAN_F3R2_FB31      31

/*Bit definition for CAN_F4R2 register.*/
#define CAN_F4R2_FB0       0
#define CAN_F4R2_FB1       1
#define CAN_F4R2_FB2       2
#define CAN_F4R2_FB3       3
#define CAN_F4R2_FB4       4
#define CAN_F4R2_FB5       5
#define CAN_F4R2_FB6       6
#define CAN_F4R2_FB7       7
#define CAN_F4R2_FB8       8
#define CAN_F4R2_FB9       9
#define CAN_F4R2_FB10      10
#define CAN_F4R2_FB11      11
#define CAN_F4R2_FB12      12
#define CAN_F4R2_FB13      13
#define CAN_F4R2_FB14      14
#define CAN_F4R2_FB15      15
#define CAN_F4R2_FB16      16
#define CAN_F4R2_FB17      17
#define CAN_F4R2_FB18      18
#define CAN_F4R2_FB19      19
#define CAN_F4R2_FB20      20
#define CAN_F4R2_FB21      21
#define CAN_F4R2_FB22      22
#define CAN_F4R2_FB23      23
#define CAN_F4R2_FB24      24
#define CAN_F4R2_FB25      25
#define CAN_F4R2_FB26      26
#define CAN_F4R2_FB27      27
#define CAN_F4R2_FB28      28
#define CAN_F4R2_FB29      29
#define CAN_F4R2_FB30      30
#define CAN_F4R2_FB31      31

/*Bit definition for CAN_F5R2 register.*/
#define CAN_F5R2_FB0       0
#define CAN_F5R2_FB1       1
#define CAN_F5R2_FB2       2
#define CAN_F5R2_FB3       3
#define CAN_F5R2_FB4       4
#define CAN_F5R2_FB5       5
#define CAN_F5R2_FB6       6
#define CAN_F5R2_FB7       7
#define CAN_F5R2_FB8       8
#define CAN_F5R2_FB9       9
#define CAN_F5R2_FB10      10
#define CAN_F5R2_FB11      11
#define CAN_F5R2_FB12      12
#define CAN_F5R2_FB13      13
#define CAN_F5R2_FB14      14
#define CAN_F5R2_FB15      15
#define CAN_F5R2_FB16      16
#define CAN_F5R2_FB17      17
#define CAN_F5R2_FB18      18
#define CAN_F5R2_FB19      19
#define CAN_F5R2_FB20      20
#define CAN_F5R2_FB21      21
#define CAN_F5R2_FB22      22
#define CAN_F5R2_FB23      23
#define CAN_F5R2_FB24      24
#define CAN_F5R2_FB25      25
#define CAN_F5R2_FB26      26
#define CAN_F5R2_FB27      27
#define CAN_F5R2_FB28      28
#define CAN_F5R2_FB29      29
#define CAN_F5R2_FB30      30
#define CAN_F5R2_FB31      31

/*Bit definition for CAN_F6R2 register.*/
#define CAN_F6R2_FB0       0
#define CAN_F6R2_FB1       1
#define CAN_F6R2_FB2       2
#define CAN_F6R2_FB3       3
#define CAN_F6R2_FB4       4
#define CAN_F6R2_FB5       5
#define CAN_F6R2_FB6       6
#define CAN_F6R2_FB7       7
#define CAN_F6R2_FB8       8
#define CAN_F6R2_FB9       9
#define CAN_F6R2_FB10      10
#define CAN_F6R2_FB11      11
#define CAN_F6R2_FB12      12
#define CAN_F6R2_FB13      13
#define CAN_F6R2_FB14      14
#define CAN_F6R2_FB15      15
#define CAN_F6R2_FB16      16
#define CAN_F6R2_FB17      17
#define CAN_F6R2_FB18      18
#define CAN_F6R2_FB19      19
#define CAN_F6R2_FB20      20
#define CAN_F6R2_FB21      21
#define CAN_F6R2_FB22      22
#define CAN_F6R2_FB23      23
#define CAN_F6R2_FB24      24
#define CAN_F6R2_FB25      25
#define CAN_F6R2_FB26      26
#define CAN_F6R2_FB27      27
#define CAN_F6R2_FB28      28
#define CAN_F6R2_FB29      29
#define CAN_F6R2_FB30      30
#define CAN_F6R2_FB31      31

/*Bit definition for CAN_F7R2 register.*/
#define CAN_F7R2_FB0       0
#define CAN_F7R2_FB1       1
#define CAN_F7R2_FB2       2
#define CAN_F7R2_FB3       3
#define CAN_F7R2_FB4       4
#define CAN_F7R2_FB5       5
#define CAN_F7R2_FB6       6
#define CAN_F7R2_FB7       7
#define CAN_F7R2_FB8       8
#define CAN_F7R2_FB9       9
#define CAN_F7R2_FB10      10
#define CAN_F7R2_FB11      11
#define CAN_F7R2_FB12      12
#define CAN_F7R2_FB13      13
#define CAN_F7R2_FB14      14
#define CAN_F7R2_FB15      15
#define CAN_F7R2_FB16      16
#define CAN_F7R2_FB17      17
#define CAN_F7R2_FB18      18
#define CAN_F7R2_FB19      19
#define CAN_F7R2_FB20      20
#define CAN_F7R2_FB21      21
#define CAN_F7R2_FB22      22
#define CAN_F7R2_FB23      23
#define CAN_F7R2_FB24      24
#define CAN_F7R2_FB25      25
#define CAN_F7R2_FB26      26
#define CAN_F7R2_FB27      27
#define CAN_F7R2_FB28      28
#define CAN_F7R2_FB29      29
#define CAN_F7R2_FB30      30
#define CAN_F7R2_FB31      31

/*Bit definition for CAN_F8R2 register.*/
#define CAN_F8R2_FB0       0
#define CAN_F8R2_FB1       1
#define CAN_F8R2_FB2       2
#define CAN_F8R2_FB3       3
#define CAN_F8R2_FB4       4
#define CAN_F8R2_FB5       5
#define CAN_F8R2_FB6       6
#define CAN_F8R2_FB7       7
#define CAN_F8R2_FB8       8
#define CAN_F8R2_FB9       9
#define CAN_F8R2_FB10      10
#define CAN_F8R2_FB11      11
#define CAN_F8R2_FB12      12
#define CAN_F8R2_FB13      13
#define CAN_F8R2_FB14      14
#define CAN_F8R2_FB15      15
#define CAN_F8R2_FB16      16
#define CAN_F8R2_FB17      17
#define CAN_F8R2_FB18      18
#define CAN_F8R2_FB19      19
#define CAN_F8R2_FB20      20
#define CAN_F8R2_FB21      21
#define CAN_F8R2_FB22      22
#define CAN_F8R2_FB23      23
#define CAN_F8R2_FB24      24
#define CAN_F8R2_FB25      25
#define CAN_F8R2_FB26      26
#define CAN_F8R2_FB27      27
#define CAN_F8R2_FB28      28
#define CAN_F8R2_FB29      29
#define CAN_F8R2_FB30      30
#define CAN_F8R2_FB31      31

/*Bit definition for CAN_F9R2 register.*/
#define CAN_F9R2_FB0       0
#define CAN_F9R2_FB1       1
#define CAN_F9R2_FB2       2
#define CAN_F9R2_FB3       3
#define CAN_F9R2_FB4       4
#define CAN_F9R2_FB5       5
#define CAN_F9R2_FB6       6
#define CAN_F9R2_FB7       7
#define CAN_F9R2_FB8       8
#define CAN_F9R2_FB9       9
#define CAN_F9R2_FB10      10
#define CAN_F9R2_FB11      11
#define CAN_F9R2_FB12      12
#define CAN_F9R2_FB13      13
#define CAN_F9R2_FB14      14
#define CAN_F9R2_FB15      15
#define CAN_F9R2_FB16      16
#define CAN_F9R2_FB17      17
#define CAN_F9R2_FB18      18
#define CAN_F9R2_FB19      19
#define CAN_F9R2_FB20      20
#define CAN_F9R2_FB21      21
#define CAN_F9R2_FB22      22
#define CAN_F9R2_FB23      23
#define CAN_F9R2_FB24      24
#define CAN_F9R2_FB25      25
#define CAN_F9R2_FB26      26
#define CAN_F9R2_FB27      27
#define CAN_F9R2_FB28      28
#define CAN_F9R2_FB29      29
#define CAN_F9R2_FB30      30
#define CAN_F9R2_FB31      31

/*Bit definition for CAN_F10R2 register.*/
#define CAN_F10R2_FB0      0
#define CAN_F10R2_FB1      1
#define CAN_F10R2_FB2      2
#define CAN_F10R2_FB3      3
#define CAN_F10R2_FB4      4
#define CAN_F10R2_FB5      5
#define CAN_F10R2_FB6      6
#define CAN_F10R2_FB7      7
#define CAN_F10R2_FB8      8
#define CAN_F10R2_FB9      9
#define CAN_F10R2_FB10     10
#define CAN_F10R2_FB11     11
#define CAN_F10R2_FB12     12
#define CAN_F10R2_FB13     13
#define CAN_F10R2_FB14     14
#define CAN_F10R2_FB15     15
#define CAN_F10R2_FB16     16
#define CAN_F10R2_FB17     17
#define CAN_F10R2_FB18     18
#define CAN_F10R2_FB19     19
#define CAN_F10R2_FB20     20
#define CAN_F10R2_FB21     21
#define CAN_F10R2_FB22     22
#define CAN_F10R2_FB23     23
#define CAN_F10R2_FB24     24
#define CAN_F10R2_FB25     25
#define CAN_F10R2_FB26     26
#define CAN_F10R2_FB27     27
#define CAN_F10R2_FB28     28
#define CAN_F10R2_FB29     29
#define CAN_F10R2_FB30     30
#define CAN_F10R2_FB31     31

/*Bit definition for CAN_F11R2 register.*/
#define CAN_F11R2_FB0      0
#define CAN_F11R2_FB1      1
#define CAN_F11R2_FB2      2
#define CAN_F11R2_FB3      3
#define CAN_F11R2_FB4      4
#define CAN_F11R2_FB5      5
#define CAN_F11R2_FB6      6
#define CAN_F11R2_FB7      7
#define CAN_F11R2_FB8      8
#define CAN_F11R2_FB9      9
#define CAN_F11R2_FB10     10
#define CAN_F11R2_FB11     11
#define CAN_F11R2_FB12     12
#define CAN_F11R2_FB13     13
#define CAN_F11R2_FB14     14
#define CAN_F11R2_FB15     15
#define CAN_F11R2_FB16     16
#define CAN_F11R2_FB17     17
#define CAN_F11R2_FB18     18
#define CAN_F11R2_FB19     19
#define CAN_F11R2_FB20     20
#define CAN_F11R2_FB21     21
#define CAN_F11R2_FB22     22
#define CAN_F11R2_FB23     23
#define CAN_F11R2_FB24     24
#define CAN_F11R2_FB25     25
#define CAN_F11R2_FB26     26
#define CAN_F11R2_FB27     27
#define CAN_F11R2_FB28     28
#define CAN_F11R2_FB29     29
#define CAN_F11R2_FB30     30
#define CAN_F11R2_FB31     31

/*Bit definition for CAN_F12R2 register.*/
#define CAN_F12R2_FB0      0
#define CAN_F12R2_FB1      1
#define CAN_F12R2_FB2      2
#define CAN_F12R2_FB3      3
#define CAN_F12R2_FB4      4
#define CAN_F12R2_FB5      5
#define CAN_F12R2_FB6      6
#define CAN_F12R2_FB7      7
#define CAN_F12R2_FB8      8
#define CAN_F12R2_FB9      9
#define CAN_F12R2_FB10     10
#define CAN_F12R2_FB11     11
#define CAN_F12R2_FB12     12
#define CAN_F12R2_FB13     13
#define CAN_F12R2_FB14     14
#define CAN_F12R2_FB15     15
#define CAN_F12R2_FB16     16
#define CAN_F12R2_FB17     17
#define CAN_F12R2_FB18     18
#define CAN_F12R2_FB19     19
#define CAN_F12R2_FB20     20
#define CAN_F12R2_FB21     21
#define CAN_F12R2_FB22     22
#define CAN_F12R2_FB23     23
#define CAN_F12R2_FB24     24
#define CAN_F12R2_FB25     25
#define CAN_F12R2_FB26     26
#define CAN_F12R2_FB27     27
#define CAN_F12R2_FB28     28
#define CAN_F12R2_FB29     29
#define CAN_F12R2_FB30     30
#define CAN_F12R2_FB31     31

/*Bit definition for CAN_F13R2 register.*/
#define CAN_F13R2_FB0      0
#define CAN_F13R2_FB1      1
#define CAN_F13R2_FB2      2
#define CAN_F13R2_FB3      3
#define CAN_F13R2_FB4      4
#define CAN_F13R2_FB5      5
#define CAN_F13R2_FB6      6
#define CAN_F13R2_FB7      7
#define CAN_F13R2_FB8      8
#define CAN_F13R2_FB9      9
#define CAN_F13R2_FB10     10
#define CAN_F13R2_FB11     11
#define CAN_F13R2_FB12     12
#define CAN_F13R2_FB13     13
#define CAN_F13R2_FB14     14
#define CAN_F13R2_FB15     15
#define CAN_F13R2_FB16     16
#define CAN_F13R2_FB17     17
#define CAN_F13R2_FB18     18
#define CAN_F13R2_FB19     19
#define CAN_F13R2_FB20     20
#define CAN_F13R2_FB21     21
#define CAN_F13R2_FB22     22
#define CAN_F13R2_FB23     23
#define CAN_F13R2_FB24     24
#define CAN_F13R2_FB25     25
#define CAN_F13R2_FB26     26
#define CAN_F13R2_FB27     27
#define CAN_F13R2_FB28     28
#define CAN_F13R2_FB29     29
#define CAN_F13R2_FB30     30
#define CAN_F13R2_FB31     31
/*
==================================================
  End   Section --> Bit definitions
==================================================
*/


#endif /* HMCAL_CAN_CAN_DEFS_H_ */
