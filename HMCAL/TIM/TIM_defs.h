/*
 * File Name --> TIM_defs.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 */

#ifndef HMCAL_TIM_TIM_DEFS_H_
#define HMCAL_TIM_TIM_DEFS_H_



/*
==================================================
  Start Section --> Bit definitions
==================================================
*/
/*Timer Control 1 available options section.*/
#define 		TIM_CR1_CEN                                                                         0
#define 		TIM_CR1_UDIS                                                                        1
#define 		TIM_CR1_URS                                                                         2
#define 		TIM_CR1_OPM                                                                         3
#define 		TIM_CR1_DIR                                                                         4
#define 		TIM_CR1_CMS_0                                                                       5
#define 		TIM_CR1_CMS_1                                                                       6
#define 		TIM_CR1_ARPE                                                                        7
#define 		TIM_CR1_CKD_0                                                                       8
#define 		TIM_CR1_CKD_1                                                                       9

/*Timer Control 2 available options section.*/
#define 		TIM_CR2_CCPC                                                                        0
#define 		TIM_CR2_CCUS                                                                        2
#define 		TIM_CR2_CCDS                                                                        3
#define 		TIM_CR2_MMS_0                                                                       4
#define 		TIM_CR2_MMS_1                                                                       5
#define 		TIM_CR2_MMS_2                                                                       6
#define 		TIM_CR2_TI1S                                                                        7
#define 		TIM_CR2_OIS1                                                                        8
#define 		TIM_CR2_OIS1N                                                                       9
#define 		TIM_CR2_OIS2                                                                        10
#define 		TIM_CR2_OIS2N                                                                       11
#define 		TIM_CR2_OIS3                                                                        12
#define 		TIM_CR2_OIS3N                                                                       13
#define 		TIM_CR2_OIS4                                                                        14

/*Timer Control slave mode control available options section.*/
#define 		TIM_SMCR_SMS_0                                                                           0
#define 		TIM_SMCR_SMS_1                                                                           1
#define 		TIM_SMCR_SMS_2                                                                           2
#define 		TIM_SMCR_TS_0                                                                            4
#define 		TIM_SMCR_TS_1                                                                            5
#define 		TIM_SMCR_TS_2                                                                            6
#define 		TIM_SMCR_MSM                                                                             7
#define 		TIM_SMCR_ETF_0                                                                           8
#define 		TIM_SMCR_ETF_1                                                                           9
#define 		TIM_SMCR_ETF_2                                                                           10
#define 		TIM_SMCR_ETF_3                                                                           11
#define 		TIM_SMCR_ETPS_0                                                                          12
#define 		TIM_SMCR_ETPS_1                                                                          13
#define 		TIM_SMCR_ECE                                                                             14
#define 		TIM_SMCR_ETP                                                                             15

/*Timer DMA/interrupt enable register available options section.*/
#define 		TIM_DIER_UIE                                                                             0
#define 		TIM_DIER_CC1IE                                                                           1
#define 		TIM_DIER_CC2IE                                                                           2
#define 		TIM_DIER_CC3IE                                                                           3
#define 		TIM_DIER_CC4IE                                                                           4
#define 		TIM_DIER_COMIE                                                                           5
#define 		TIM_DIER_TIE                                                                             6
#define 		TIM_DIER_BIE                                                                             7
#define 		TIM_DIER_UDE                                                                             8
#define 		TIM_DIER_CC1DE                                                                           9
#define 		TIM_DIER_CC2DE                                                                           10
#define 		TIM_DIER_CC3DE                                                                           11
#define 		TIM_DIER_CC4DE                                                                           12
#define 		TIM_DIER_COMDE                                                                           13
#define 		TIM_DIER_TDE                                                                             14

/*Timer status register available options section.*/
#define 		TIM_SR_UIF                                                                             0
#define 		TIM_SR_CC1IF                                                                           1
#define 		TIM_SR_CC2IF                                                                           2
#define 		TIM_SR_CC3IF                                                                           3
#define 		TIM_SR_CC4IF                                                                           4
#define 		TIM_SR_COMIF                                                                           5
#define 		TIM_SR_TIF                                                                             6
#define 		TIM_SR_BIF                                                                             7
#define 		TIM_SR_CC1OF                                                                           9
#define 		TIM_SR_CC2OF                                                                           10
#define 		TIM_SR_CC3OF                                                                           11
#define 		TIM_SR_CC4OF                                                                           12

/*Timer event generation register available options section.*/
#define 		TIM_EGR_UG                                                                              0
#define 		TIM_EGR_CC1G                                                                            1
#define 		TIM_EGR_CC2G                                                                            2
#define 		TIM_EGR_CC3G                                                                            3
#define 		TIM_EGR_CC4G                                                                            4
#define 		TIM_EGR_COMG                                                                            5
#define 		TIM_EGR_TG                                                                              6
#define 		TIM_EGR_BG                                                                              7

/*Timer Capture Compare mode register 1.*/
#define 		TIM_CCMR1_CC1S_0																		0
#define 		TIM_CCMR1_CC1S_1																		1

#define 		TIM_CCMR1_OC1FE																			2
#define 		TIM_CCMR1_OC1PE																			3
#define			TIM_CCMR1_IC1PSC_0																		2
#define			TIM_CCMR1_IC1PSC_1																		3

#define			TIM_CCMR1_OC1M_0																		4
#define			TIM_CCMR1_OC1M_1																		5
#define			TIM_CCMR1_OC1M_2																		6
#define			TIM_CCMR1_OC1CE																			7

#define			TIM_CCMR1_IC1F_0																		4
#define			TIM_CCMR1_IC1F_1																		5
#define			TIM_CCMR1_IC1F_2																		6
#define			TIM_CCMR1_IC1F_3																		7

#define			TIM_CCMR1_CC2S_0																		8
#define			TIM_CCMR1_CC2S_1																		9

#define			TIM_CCMR1_OC2FE																			10
#define			TIM_CCMR1_OC2PE																			11
#define			TIM_CCMR1_IC2PSC_0																		10
#define			TIM_CCMR1_IC2PSC_1																		11

#define			TIM_CCMR1_OC2M_0																		12
#define			TIM_CCMR1_OC2M_1																		13
#define			TIM_CCMR1_OC2M_2																		14
#define			TIM_CCMR1_OC2E																			15

#define			TIM_CCMR1_IC2F_0																		12
#define			TIM_CCMR1_IC2F_1																		13
#define			TIM_CCMR1_IC2F_2																		14
#define			TIM_CCMR1_IC2F_3																		15

/*Timer Capture Compare mode register 2.*/
#define 		TIM_CCMR2_CC3S_0																		0
#define 		TIM_CCMR2_CC3S_1																		1

#define 		TIM_CCMR2_OC3FE																			2
#define 		TIM_CCMR2_OC3PE																			3
#define			TIM_CCMR2_IC3PSC_0																		2
#define			TIM_CCMR2_IC3PSC_1																		3

#define			TIM_CCMR2_OC3M_0																		4
#define			TIM_CCMR2_OC3M_1																		5
#define			TIM_CCMR2_OC3M_2																		6
#define			TIM_CCMR2_OC3CE																			7

#define			TIM_CCMR2_IC3F_0																		4
#define			TIM_CCMR2_IC3F_1																		5
#define			TIM_CCMR2_IC3F_2																		6
#define			TIM_CCMR2_IC3F_3																		7

#define			TIM_CCMR2_CC4S_0																		8
#define			TIM_CCMR2_CC4S_1																		9

#define			TIM_CCMR2_OC4FE																			10
#define			TIM_CCMR2_OC4PE																			11
#define			TIM_CCMR2_IC4PSC_0																		10
#define			TIM_CCMR2_IC4PSC_1																		11

#define			TIM_CCMR2_OC4M_0																		12
#define			TIM_CCMR2_OC4M_1																		13
#define			TIM_CCMR2_OC4M_2																		14
#define			TIM_CCMR2_OC4E																			15

#define			TIM_CCMR2_IC4F_0																		12
#define			TIM_CCMR2_IC4F_1																		13
#define			TIM_CCMR2_IC4F_2																		14
#define			TIM_CCMR2_IC4F_3																		15

/*Timer event capture/compare enable register available options section.*/
#define 		TIM_CCER_CC1E                                                                            0
#define 		TIM_CCER_CC1P                                                                            1
#define 		TIM_CCER_CC1NE                                                                           2
#define 		TIM_CCER_CC1NP                                                                           3
#define 		TIM_CCER_CC2E                                                                            4
#define 		TIM_CCER_CC2P                                                                            5
#define 		TIM_CCER_CC2NE                                                                           6
#define 		TIM_CCER_CC2NP                                                                           7
#define 		TIM_CCER_CC3E                                                                            8
#define 		TIM_CCER_CC3P                                                                            9
#define 		TIM_CCER_CC3NE                                                                           10
#define 		TIM_CCER_CC3NP                                                                           11
#define 		TIM_CCER_CC4E                                                                            12
#define 		TIM_CCER_CC4P                                                                            13
#define 		TIM_CCER_CC4NP                                                                           15

/*CNT (TIM counter) Bits.*/

#define 		TIM_CNT_CNT_0                                                                   0
#define 		TIM_CNT_CNT_1                                                                   1
#define 		TIM_CNT_CNT_2                                                                   2
#define 		TIM_CNT_CNT_3                                                                   3
#define 		TIM_CNT_CNT_4                                                                   4
#define 		TIM_CNT_CNT_5                                                                   5
#define 		TIM_CNT_CNT_6                                                                   6
#define 		TIM_CNT_CNT_7                                                                   7
#define 		TIM_CNT_CNT_8                                                                   8
#define 		TIM_CNT_CNT_9                                                                   9
#define 		TIM_CNT_CNT_10                                                                  10
#define 		TIM_CNT_CNT_11                                                                  11
#define 		TIM_CNT_CNT_12                                                                  12
#define 		TIM_CNT_CNT_13                                                                  13
#define 		TIM_CNT_CNT_14                                                                  14
#define 		TIM_CNT_CNT_15                                                                  15

/*PSC (TIM Prescaler) Bits.*/

#define 		TIM_PSC_PSC_0                                                                   0
#define 		TIM_PSC_PSC_1                                                                   1
#define 		TIM_PSC_PSC_2                                                                   2
#define 		TIM_PSC_PSC_3                                                                   3
#define 		TIM_PSC_PSC_4                                                                   4
#define 		TIM_PSC_PSC_5                                                                   5
#define 		TIM_PSC_PSC_6                                                                   6
#define 		TIM_PSC_PSC_7                                                                   7
#define 		TIM_PSC_PSC_8                                                                   8
#define 		TIM_PSC_PSC_9                                                                   9
#define 		TIM_PSC_PSC_10                                                                  10
#define 		TIM_PSC_PSC_11                                                                  11
#define 		TIM_PSC_PSC_12                                                                  12
#define 		TIM_PSC_PSC_13                                                                  13
#define 		TIM_PSC_PSC_14                                                                  14
#define 		TIM_PSC_PSC_15                                                                  15

/*ARR (TIM Auto-reload Register) Bits.*/

#define 		TIM_ARR_ARR_0                                                                   0
#define 		TIM_ARR_ARR_1                                                                   1
#define 		TIM_ARR_ARR_2                                                                   2
#define 		TIM_ARR_ARR_3                                                                   3
#define 		TIM_ARR_ARR_4                                                                   4
#define 		TIM_ARR_ARR_5                                                                   5
#define 		TIM_ARR_ARR_6                                                                   6
#define 		TIM_ARR_ARR_7                                                                   7
#define 		TIM_ARR_ARR_8                                                                   8
#define 		TIM_ARR_ARR_9                                                                   9
#define 		TIM_ARR_ARR_10                                                                  10
#define 		TIM_ARR_ARR_11                                                                  11
#define 		TIM_ARR_ARR_12                                                                  12
#define 		TIM_ARR_ARR_13                                                                  13
#define 		TIM_ARR_ARR_14                                                                  14
#define 		TIM_ARR_ARR_15                                                                  15


/*RCR (TIM repetition counter Register) Bits.*/

#define 		TIM_RCR_REP_0                                                                   0
#define 		TIM_RCR_REP_1                                                                   1
#define 		TIM_RCR_REP_2                                                                   2
#define 		TIM_RCR_REP_3                                                                   3
#define 		TIM_RCR_REP_4                                                                   4
#define 		TIM_RCR_REP_5                                                                   5
#define 		TIM_RCR_REP_6                                                                   6
#define 		TIM_RCR_REP_7                                                                   7

/*CCR1 (TIM capture/compare register 1 Register) Bits.*/

#define 		TIM_CCR1_CCR1_0                                                                 0
#define 		TIM_CCR1_CCR1_1                                                                 1
#define 		TIM_CCR1_CCR1_2                                                                 2
#define 		TIM_CCR1_CCR1_3                                                                 3
#define 		TIM_CCR1_CCR1_4                                                                 4
#define 		TIM_CCR1_CCR1_5                                                                 5
#define 		TIM_CCR1_CCR1_6                                                                 6
#define 		TIM_CCR1_CCR1_7                                                                 7
#define 		TIM_CCR1_CCR1_8                                                                 8
#define 		TIM_CCR1_CCR1_9                                                                 9
#define 		TIM_CCR1_CCR1_10                                                                10
#define 		TIM_CCR1_CCR1_11                                                                11
#define 		TIM_CCR1_CCR1_12                                                                12
#define 		TIM_CCR1_CCR1_13                                                                13
#define 		TIM_CCR1_CCR1_14                                                                14
#define 		TIM_CCR1_CCR1_15                                                                15


/*CCR2 (TIM capture/compare register 2 Register) Bits.*/

#define 		TIM_CCR2_CCR2_0                                                                 0
#define 		TIM_CCR2_CCR2_1                                                                 1
#define 		TIM_CCR2_CCR2_2                                                                 2
#define 		TIM_CCR2_CCR2_3                                                                 3
#define 		TIM_CCR2_CCR2_4                                                                 4
#define 		TIM_CCR2_CCR2_5                                                                 5
#define 		TIM_CCR2_CCR2_6                                                                 6
#define 		TIM_CCR2_CCR2_7                                                                 7
#define 		TIM_CCR2_CCR2_8                                                                 8
#define 		TIM_CCR2_CCR2_9                                                                 9
#define 		TIM_CCR2_CCR2_10                                                                10
#define 		TIM_CCR2_CCR2_11                                                                11
#define 		TIM_CCR2_CCR2_12                                                                12
#define 		TIM_CCR2_CCR2_13                                                                13
#define 		TIM_CCR2_CCR2_14                                                                14
#define 		TIM_CCR2_CCR2_15                                                                15


/*CCR3 (TIM capture/compare register 3 Register) Bits.*/

#define 		TIM_CCR3_CCR3_0                                                                 0
#define 		TIM_CCR3_CCR3_1                                                                 1
#define 		TIM_CCR3_CCR3_2                                                                 2
#define 		TIM_CCR3_CCR3_3                                                                 3
#define 		TIM_CCR3_CCR3_4                                                                 4
#define 		TIM_CCR3_CCR3_5                                                                 5
#define 		TIM_CCR3_CCR3_6                                                                 6
#define 		TIM_CCR3_CCR3_7                                                                 7
#define 		TIM_CCR3_CCR3_8                                                                 8
#define 		TIM_CCR3_CCR3_9                                                                 9
#define 		TIM_CCR3_CCR3_10                                                                10
#define 		TIM_CCR3_CCR3_11                                                                11
#define 		TIM_CCR3_CCR3_12                                                                12
#define 		TIM_CCR3_CCR3_13                                                                13
#define 		TIM_CCR3_CCR3_14                                                                14
#define 		TIM_CCR3_CCR3_15                                                                15

/*CCR4 (TIM capture/compare register 4 Register) Bits.*/

#define 		TIM_CCR4_CCR4_0                                                                 0
#define 		TIM_CCR4_CCR4_1                                                                 1
#define 		TIM_CCR4_CCR4_2                                                                 2
#define 		TIM_CCR4_CCR4_3                                                                 3
#define 		TIM_CCR4_CCR4_4                                                                 4
#define 		TIM_CCR4_CCR4_5                                                                 5
#define 		TIM_CCR4_CCR4_6                                                                 6
#define 		TIM_CCR4_CCR4_7                                                                 7
#define 		TIM_CCR4_CCR4_8                                                                 8
#define 		TIM_CCR4_CCR4_9                                                                 9
#define 		TIM_CCR4_CCR4_10                                                                10
#define 		TIM_CCR4_CCR4_11                                                                11
#define 		TIM_CCR4_CCR4_12                                                                12
#define 		TIM_CCR4_CCR4_13                                                                13
#define 		TIM_CCR4_CCR4_14                                                                14
#define 		TIM_CCR4_CCR4_15                                                                15

/*BDTR (TIM break and dead-time register) Bits.*/
#define 		TIM_BDTR_DTG_0                                                                           0
#define 		TIM_BDTR_DTG_1                                                                           1
#define 		TIM_BDTR_DTG_2                                                                           2
#define 		TIM_BDTR_DTG_3                                                                           3
#define 		TIM_BDTR_DTG_4                                                                           4
#define 		TIM_BDTR_DTG_5                                                                           5
#define 		TIM_BDTR_DTG_6                                                                           6
#define 		TIM_BDTR_DTG_7                                                                           7
#define 		TIM_BDTR_LOCK_0                                                                          8
#define 		TIM_BDTR_LOCK_1                                                                          9
#define 		TIM_BDTR_OSSI                                                                            10
#define 		TIM_BDTR_OSSR                                                                            11
#define 		TIM_BDTR_BKE                                                                             12
#define 		TIM_BDTR_BKP                                                                             13
#define 		TIM_BDTR_AOE                                                                             14
#define 		TIM_BDTR_MOE                                                                             15

/*DCR (TIM DMA control register) Bits.*/
#define			TIM_DCR_DBA_0																			 0
#define			TIM_DCR_DBA_1																			 1
#define			TIM_DCR_DBA_2																			 2
#define			TIM_DCR_DBA_3																			 3
#define			TIM_DCR_DBA_4																			 4

#define			TIM_DCR_DBL_0																			 8
#define			TIM_DCR_DBL_1																			 9
#define			TIM_DCR_DBL_2																			 10
#define			TIM_DCR_DBL_3																			 11
#define			TIM_DCR_DBL_4																			 12

/*DMAR (TIM DMA address for full transfer) Bits.*/

#define 		TIM_DMAR_DMAB_0                                                                 0
#define 		TIM_DMAR_DMAB_1                                                                 1
#define 		TIM_DMAR_DMAB_2                                                                 2
#define 		TIM_DMAR_DMAB_3                                                                 3
#define 		TIM_DMAR_DMAB_4                                                                 4
#define 		TIM_DMAR_DMAB_5                                                                 5
#define 		TIM_DMAR_DMAB_6                                                                 6
#define 		TIM_DMAR_DMAB_7                                                                 7
#define 		TIM_DMAR_DMAB_8                                                                 8
#define 		TIM_DMAR_DMAB_9                                                                 9
#define 		TIM_DMAR_DMAB_10                                                                10
#define 		TIM_DMAR_DMAB_11                                                                11
#define 		TIM_DMAR_DMAB_12                                                                12
#define 		TIM_DMAR_DMAB_13                                                                13
#define 		TIM_DMAR_DMAB_14                                                                14
#define 		TIM_DMAR_DMAB_15                                                                15
#define 		TIM_DMAR_DMAB_16                                                                16
#define 		TIM_DMAR_DMAB_17                                                                17
#define 		TIM_DMAR_DMAB_18                                                                18
#define 		TIM_DMAR_DMAB_19                                                                19
#define 		TIM_DMAR_DMAB_20                                                                20
#define 		TIM_DMAR_DMAB_21                                                                21
#define 		TIM_DMAR_DMAB_22                                                                22
#define 		TIM_DMAR_DMAB_23                                                                23
#define 		TIM_DMAR_DMAB_24                                                                24
#define 		TIM_DMAR_DMAB_25                                                                25
#define 		TIM_DMAR_DMAB_26                                                                26
#define 		TIM_DMAR_DMAB_27                                                                27
#define 		TIM_DMAR_DMAB_28                                                                28
#define 		TIM_DMAR_DMAB_29                                                                29
#define 		TIM_DMAR_DMAB_30                                                                30
#define 		TIM_DMAR_DMAB_31                                                                31
/*
==================================================
  End   Section --> Bit definitions
==================================================
*/

#endif /* HMCAL_TIM_TIM_DEFS_H_ */
