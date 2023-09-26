/*
 * File Name --> DMA_defs.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 */

#ifndef HMCAL_DMA_DMA_DEFS_H_
#define HMCAL_DMA_DMA_DEFS_H_

/*
==================================================
  Start Section --> Bit definitions
==================================================
*/

/*Bit definitons for DMA_CR (DMA stream configuration register) register.*/
#define 		DMA_CR_EN                                                                              0
#define 		DMA_CR_DMEIE                                                                           1
#define 		DMA_CR_TEIE                                                                            2
#define 		DMA_CR_HTIE                                                                            3
#define 		DMA_CR_TCIE                                                                            4
#define 		DMA_CR_PFCTRL                                                                          5
#define 		DMA_CR_DIR_0                                                                           6
#define 		DMA_CR_DIR_1                                                                           7
#define 		DMA_CR_CIRC                                                                            8
#define 		DMA_CR_PINC                                                                            9
#define 		DMA_CR_MINC                                                                            10
#define 		DMA_CR_PSIZE_0                                                                         11
#define 		DMA_CR_PSIZE_1                                                                         12
#define 		DMA_CR_MSIZE_0                                                                         13
#define 		DMA_CR_MSIZE_1                                                                         14
#define 		DMA_CR_PINCOS                                                                          15
#define 		DMA_CR_PL_0                                                                            16
#define 		DMA_CR_PL_1                                                                            17
#define 		DMA_CR_DBM                                                                             18
#define 		DMA_CR_CT                                                                              19
#define 		DMA_CR_PBURST_0                                                                        21
#define 		DMA_CR_PBURST_1                                                                        22
#define 		DMA_CR_MBURST_0                                                                        23
#define 		DMA_CR_MBURST_1                                                                        24
#define 		DMA_CR_CHSEL_0                                                                         25
#define 		DMA_CR_CHSEL_1                                                                         26
#define 		DMA_CR_CHSEL_2                                                                         27

/*Bit definitons for DMA_NDTR (DMA number of data register) register.*/
#define 		DMA_NDTR_NDT_0                                                                           0
#define 		DMA_NDTR_NDT_1                                                                           1
#define 		DMA_NDTR_NDT_2                                                                           2
#define 		DMA_NDTR_NDT_3                                                                           3
#define 		DMA_NDTR_NDT_4                                                                           4
#define 		DMA_NDTR_NDT_5                                                                           5
#define 		DMA_NDTR_NDT_6                                                                           6
#define 		DMA_NDTR_NDT_7                                                                           7
#define 		DMA_NDTR_NDT_8                                                                           8
#define 		DMA_NDTR_NDT_9                                                                           9
#define 		DMA_NDTR_NDT_10                                                                          10
#define 		DMA_NDTR_NDT_11                                                                          11
#define 		DMA_NDTR_NDT_12                                                                          12
#define 		DMA_NDTR_NDT_13                                                                          13
#define 		DMA_NDTR_NDT_14                                                                          14
#define 		DMA_NDTR_NDT_15                                                                          15

/*Bit definitons for DMA_PAR (DMA peripheral address register) register.*/
#define 		DMA_PAR_PAR_0                                                                           0
#define 		DMA_PAR_PAR_1                                                                           1
#define 		DMA_PAR_PAR_2                                                                           2
#define 		DMA_PAR_PAR_3                                                                           3
#define 		DMA_PAR_PAR_4                                                                           4
#define 		DMA_PAR_PAR_5                                                                           5
#define 		DMA_PAR_PAR_6                                                                           6
#define 		DMA_PAR_PAR_7                                                                           7
#define 		DMA_PAR_PAR_8                                                                           8
#define 		DMA_PAR_PAR_9                                                                           9
#define 		DMA_PAR_PAR_10                                                                          10
#define 		DMA_PAR_PAR_11                                                                          11
#define 		DMA_PAR_PAR_12                                                                          12
#define 		DMA_PAR_PAR_13                                                                          13
#define 		DMA_PAR_PAR_14                                                                          14
#define 		DMA_PAR_PAR_15                                                                          15
#define 		DMA_PAR_PAR_16                                                                          16
#define 		DMA_PAR_PAR_17                                                                          17
#define 		DMA_PAR_PAR_18                                                                          18
#define 		DMA_PAR_PAR_19                                                                          19
#define 		DMA_PAR_PAR_20                                                                          20
#define 		DMA_PAR_PAR_21                                                                          21
#define 		DMA_PAR_PAR_22                                                                          22
#define 		DMA_PAR_PAR_23                                                                          23
#define 		DMA_PAR_PAR_24                                                                          24
#define 		DMA_PAR_PAR_25                                                                          25
#define 		DMA_PAR_PAR_26                                                                          26
#define 		DMA_PAR_PAR_27                                                                          27
#define 		DMA_PAR_PAR_28                                                                          28
#define 		DMA_PAR_PAR_29                                                                          29
#define 		DMA_PAR_PAR_30                                                                          30
#define 		DMA_PAR_PAR_31                                                                          31

/*Bit definitons for DMA_M1AR (DMA memory address register) register.*/
#define 		DMA_M1A_M1A_0                                                                           0
#define 		DMA_M1A_M1A_1                                                                           1
#define 		DMA_M1A_M1A_2                                                                           2
#define 		DMA_M1A_M1A_3                                                                           3
#define 		DMA_M1A_M1A_4                                                                           4
#define 		DMA_M1A_M1A_5                                                                           5
#define 		DMA_M1A_M1A_6                                                                           6
#define 		DMA_M1A_M1A_7                                                                           7
#define 		DMA_M1A_M1A_8                                                                           8
#define 		DMA_M1A_M1A_9                                                                           9
#define 		DMA_M1A_M1A_10                                                                          10
#define 		DMA_M1A_M1A_11                                                                          11
#define 		DMA_M1A_M1A_12                                                                          12
#define 		DMA_M1A_M1A_13                                                                          13
#define 		DMA_M1A_M1A_14                                                                          14
#define 		DMA_M1A_M1A_15                                                                          15
#define 		DMA_M1A_M1A_16                                                                          16
#define 		DMA_M1A_M1A_17                                                                          17
#define 		DMA_M1A_M1A_18                                                                          18
#define 		DMA_M1A_M1A_19                                                                          19
#define 		DMA_M1A_M1A_20                                                                          20
#define 		DMA_M1A_M1A_21                                                                          21
#define 		DMA_M1A_M1A_22                                                                          22
#define 		DMA_M1A_M1A_23                                                                          23
#define 		DMA_M1A_M1A_24                                                                          24
#define 		DMA_M1A_M1A_25                                                                          25
#define 		DMA_M1A_M1A_26                                                                          26
#define 		DMA_M1A_M1A_27                                                                          27
#define 		DMA_M1A_M1A_28                                                                          28
#define 		DMA_M1A_M1A_29                                                                          29
#define 		DMA_M1A_M1A_30                                                                          30
#define 		DMA_M1A_M1A_31                                                                          31

/*Bit definitons for DMA_FCR (DMA FIFO control register) register.*/
#define 		DMA_FCR_FTH_0                                                                           0
#define 		DMA_FCR_FTH_1                                                                           1
#define 		DMA_FCR_DMDIS                                                                           2
#define 		DMA_FCR_FS_0                                                                            3
#define 		DMA_FCR_FS_1                                                                            4
#define 		DMA_FCR_FS_2                                                                            5
#define 		DMA_FCR_FEIE                                                                            7
/*
==================================================
  End   Section --> Bit definitions
==================================================
*/
#endif /* HMCAL_DMA_DMA_DEFS_H_ */
