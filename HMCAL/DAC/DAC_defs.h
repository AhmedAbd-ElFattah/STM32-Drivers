/*
 * File Name --> DAC_defs.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 -->
 */

#ifndef HMCAL_DAC_DAC_DEFS_H_
#define HMCAL_DAC_DAC_DEFS_H_

/*
==================================================
  Start Section --> Bit definitions
==================================================
*/

/*Bit definition for DAC_CR register*/
#define 		DAC_CR_EN1                                                                      0
#define 		DAC_CR_BOFF1                                                                    1
#define 		DAC_CR_TEN1                                                                     2

#define 		DAC_CR_TSEL1	                                                                3
#define 		DAC_CR_TSEL1_0                                                                  3
#define 		DAC_CR_TSEL1_1                                                                  4
#define 		DAC_CR_TSEL1_2                                                                  5

#define 		DAC_CR_WAVE1  	                                                                6
#define 		DAC_CR_WAVE1_0                                                                  6
#define 		DAC_CR_WAVE1_1                                                                  7

#define 		DAC_CR_MAMP1                                                                    8
#define 		DAC_CR_MAMP1_0                                                                  8
#define 		DAC_CR_MAMP1_1                                                                  9
#define 		DAC_CR_MAMP1_2                                                                  10
#define 		DAC_CR_MAMP1_3                                                                  11

#define 		DAC_CR_DMAEN1                                                                   12
#define 		DAC_CR_DMAUDRIE1                                                                13
#define 		DAC_CR_EN2                                                                      16
#define 		DAC_CR_BOFF2                                                                    17
#define 		DAC_CR_TEN2                                                                     18

#define 		DAC_CR_TSEL2                                                                    19
#define 		DAC_CR_TSEL2_0                                                                  19
#define 		DAC_CR_TSEL2_1                                                                  20
#define 		DAC_CR_TSEL2_2                                                                  21

#define 		DAC_CR_WAVE2                                                                    22
#define 		DAC_CR_WAVE2_0                                                                  22
#define 		DAC_CR_WAVE2_1                                                                  23

#define 		DAC_CR_MAMP2                                                                    24
#define 		DAC_CR_MAMP2_0                                                                  24
#define 		DAC_CR_MAMP2_1                                                                  25
#define 		DAC_CR_MAMP2_2                                                                  26
#define 		DAC_CR_MAMP2_3                                                                  27
#define 		DAC_CR_DMAEN2                                                                   28
#define 		DAC_CR_DMAUDRIE2                                                                29


/*Bit definition for DAC_SWTRIGR register*/
#define 		DAC_SWTRIGR_SWTRIG1                                                             0
#define 		DAC_SWTRIGR_SWTRIG2                                                             1


/*Bit definition for DAC_DHR12R1 register*/
#define 		DAC_DHR12R1_DACC1DHR_0                                                          0
#define 		DAC_DHR12R1_DACC1DHR_1                                                          1
#define 		DAC_DHR12R1_DACC1DHR_2                                                          2
#define 		DAC_DHR12R1_DACC1DHR_3                                                          3
#define 		DAC_DHR12R1_DACC1DHR_4                                                          4
#define 		DAC_DHR12R1_DACC1DHR_5                                                          5
#define 		DAC_DHR12R1_DACC1DHR_6                                                          6
#define 		DAC_DHR12R1_DACC1DHR_7                                                          7
#define 		DAC_DHR12R1_DACC1DHR_8                                                          8
#define 		DAC_DHR12R1_DACC1DHR_9                                                          9
#define 		DAC_DHR12R1_DACC1DHR_10                                                         10
#define 		DAC_DHR12R1_DACC1DHR_11                                                         11


/*Bit definition for DAC_DHR12L1 register*/
#define 		DAC_DHR12L1_DACC1DHR_0                                                          4
#define 		DAC_DHR12L1_DACC1DHR_1                                                          5
#define 		DAC_DHR12L1_DACC1DHR_2                                                          6
#define 		DAC_DHR12L1_DACC1DHR_3                                                          7
#define 		DAC_DHR12L1_DACC1DHR_4                                                          8
#define 		DAC_DHR12L1_DACC1DHR_5                                                          9
#define 		DAC_DHR12L1_DACC1DHR_6                                                          10
#define 		DAC_DHR12L1_DACC1DHR_7                                                          11
#define 		DAC_DHR12L1_DACC1DHR_8                                                          12
#define 		DAC_DHR12L1_DACC1DHR_9                                                          13
#define 		DAC_DHR12L1_DACC1DHR_10                                                         14
#define 		DAC_DHR12L1_DACC1DHR_11                                                         15

/*Bit definition for DAC_DHR8R1 register*/
#define 		DAC_DHR8R1_DACC1DHR_0                                                           0
#define 		DAC_DHR8R1_DACC1DHR_1                                                           1
#define 		DAC_DHR8R1_DACC1DHR_2                                                           2
#define 		DAC_DHR8R1_DACC1DHR_3                                                           3
#define 		DAC_DHR8R1_DACC1DHR_4                                                           4
#define 		DAC_DHR8R1_DACC1DHR_5                                                           5
#define 		DAC_DHR8R1_DACC1DHR_6                                                           6
#define 		DAC_DHR8R1_DACC1DHR_7                                                           7

/*Bit definition for DAC_DHR12R2 register*/
#define 		DAC_DHR12R2_DACC2DHR_0                                                          0
#define 		DAC_DHR12R2_DACC2DHR_1                                                          1
#define 		DAC_DHR12R2_DACC2DHR_2                                                          2
#define 		DAC_DHR12R2_DACC2DHR_3                                                          3
#define 		DAC_DHR12R2_DACC2DHR_4                                                          4
#define 		DAC_DHR12R2_DACC2DHR_5                                                          5
#define 		DAC_DHR12R2_DACC2DHR_6                                                          6
#define 		DAC_DHR12R2_DACC2DHR_7                                                          7
#define 		DAC_DHR12R2_DACC2DHR_8                                                          8
#define 		DAC_DHR12R2_DACC2DHR_9                                                          9
#define 		DAC_DHR12R2_DACC2DHR_10                                                         10
#define 		DAC_DHR12R2_DACC2DHR_11                                                         11

/*Bit definition for DAC_DHR12L2 register*/
#define 		DAC_DHR12L2_DACC2DHR_0                                                          4
#define 		DAC_DHR12L2_DACC2DHR_1                                                          5
#define 		DAC_DHR12L2_DACC2DHR_2                                                          6
#define 		DAC_DHR12L2_DACC2DHR_3                                                          7
#define 		DAC_DHR12L2_DACC2DHR_4                                                          8
#define 		DAC_DHR12L2_DACC2DHR_5                                                          9
#define 		DAC_DHR12L2_DACC2DHR_6                                                          10
#define 		DAC_DHR12L2_DACC2DHR_7                                                          11
#define 		DAC_DHR12L2_DACC2DHR_8                                                          12
#define 		DAC_DHR12L2_DACC2DHR_9                                                          13
#define 		DAC_DHR12L2_DACC2DHR_10                                                         14
#define 		DAC_DHR12L2_DACC2DHR_11                                                         15

/*Bit definition for DAC_DHR8R2 register*/
#define 		DAC_DHR8R2_DACC2DHR_0                                                           0
#define 		DAC_DHR8R2_DACC2DHR_1                                                           1
#define 		DAC_DHR8R2_DACC2DHR_2                                                           2
#define 		DAC_DHR8R2_DACC2DHR_3                                                           3
#define 		DAC_DHR8R2_DACC2DHR_4                                                           4
#define 		DAC_DHR8R2_DACC2DHR_5                                                           5
#define 		DAC_DHR8R2_DACC2DHR_6                                                           6
#define 		DAC_DHR8R2_DACC2DHR_7                                                           7

/*Bit definition for DAC_DHR12RD register*/
#define 		DAC_DHR12RD_DACC1DHR_0                                                          0
#define 		DAC_DHR12RD_DACC1DHR_1                                                          1
#define 		DAC_DHR12RD_DACC1DHR_2                                                          2
#define 		DAC_DHR12RD_DACC1DHR_3                                                          3
#define 		DAC_DHR12RD_DACC1DHR_4                                                          4
#define 		DAC_DHR12RD_DACC1DHR_5                                                          5
#define 		DAC_DHR12RD_DACC1DHR_6                                                          6
#define 		DAC_DHR12RD_DACC1DHR_7                                                          7
#define 		DAC_DHR12RD_DACC1DHR_8                                                          8
#define 		DAC_DHR12RD_DACC1DHR_9                                                          9
#define 		DAC_DHR12RD_DACC1DHR_10                                                         10
#define 		DAC_DHR12RD_DACC1DHR_11                                                         11

#define 		DAC_DHR12RD_DACC2DHR_0                                                          16
#define 		DAC_DHR12RD_DACC2DHR_1                                                          17
#define 		DAC_DHR12RD_DACC2DHR_2                                                          18
#define 		DAC_DHR12RD_DACC2DHR_3                                                          19
#define 		DAC_DHR12RD_DACC2DHR_4                                                          20
#define 		DAC_DHR12RD_DACC2DHR_5                                                          21
#define 		DAC_DHR12RD_DACC2DHR_6                                                          22
#define 		DAC_DHR12RD_DACC2DHR_7                                                          23
#define 		DAC_DHR12RD_DACC2DHR_8                                                          24
#define 		DAC_DHR12RD_DACC2DHR_9                                                          25
#define 		DAC_DHR12RD_DACC2DHR_10                                                         26
#define 		DAC_DHR12RD_DACC2DHR_11                                                         27


/*Bit definition for DAC_DHR12LD register*/
#define 		DAC_DHR12LD_DACC1DHR_0                                                          4
#define 		DAC_DHR12LD_DACC1DHR_1                                                          5
#define 		DAC_DHR12LD_DACC1DHR_2                                                          6
#define 		DAC_DHR12LD_DACC1DHR_3                                                          7
#define 		DAC_DHR12LD_DACC1DHR_4                                                          8
#define 		DAC_DHR12LD_DACC1DHR_5                                                          9
#define 		DAC_DHR12LD_DACC1DHR_6                                                          10
#define 		DAC_DHR12LD_DACC1DHR_7                                                          11
#define 		DAC_DHR12LD_DACC1DHR_8                                                          12
#define 		DAC_DHR12LD_DACC1DHR_9                                                          13
#define 		DAC_DHR12LD_DACC1DHR_10                                                         14
#define 		DAC_DHR12LD_DACC1DHR_11                                                         15

#define 		DAC_DHR12LD_DACC2DHR_0                                                          20
#define 		DAC_DHR12LD_DACC2DHR_1                                                          21
#define 		DAC_DHR12LD_DACC2DHR_2                                                          22
#define 		DAC_DHR12LD_DACC2DHR_3                                                          23
#define 		DAC_DHR12LD_DACC2DHR_4                                                          24
#define 		DAC_DHR12LD_DACC2DHR_5                                                          25
#define 		DAC_DHR12LD_DACC2DHR_6                                                          26
#define 		DAC_DHR12LD_DACC2DHR_7                                                          27
#define 		DAC_DHR12LD_DACC2DHR_8                                                          28
#define 		DAC_DHR12LD_DACC2DHR_9                                                          29
#define 		DAC_DHR12LD_DACC2DHR_10                                                         30
#define 		DAC_DHR12LD_DACC2DHR_11                                                         31

/*Bit definition for DAC_DHR8RD register*/
#define 		DAC_DHR8RD_DACC1DHR_0                                                           0
#define 		DAC_DHR8RD_DACC1DHR_1                                                           1
#define 		DAC_DHR8RD_DACC1DHR_2                                                           2
#define 		DAC_DHR8RD_DACC1DHR_3                                                           3
#define 		DAC_DHR8RD_DACC1DHR_4                                                           4
#define 		DAC_DHR8RD_DACC1DHR_5                                                           5
#define 		DAC_DHR8RD_DACC1DHR_6                                                           6
#define 		DAC_DHR8RD_DACC1DHR_7                                                           7

#define 		DAC_DHR8RD_DACC2DHR_0                                                           8
#define 		DAC_DHR8RD_DACC2DHR_1                                                           9
#define 		DAC_DHR8RD_DACC2DHR_2                                                           10
#define 		DAC_DHR8RD_DACC2DHR_3                                                           11
#define 		DAC_DHR8RD_DACC2DHR_4                                                           12
#define 		DAC_DHR8RD_DACC2DHR_5                                                           13
#define 		DAC_DHR8RD_DACC2DHR_6                                                           14
#define 		DAC_DHR8RD_DACC2DHR_7                                                           15

/*Bit definition for DAC_DOR1 register*/
#define 		DAC_DOR1_DACC1DOR_0                                                             0
#define 		DAC_DOR1_DACC1DOR_1                                                             1
#define 		DAC_DOR1_DACC1DOR_2                                                             2
#define 		DAC_DOR1_DACC1DOR_3                                                             3
#define 		DAC_DOR1_DACC1DOR_4                                                             4
#define 		DAC_DOR1_DACC1DOR_5                                                             5
#define 		DAC_DOR1_DACC1DOR_6                                                             6
#define 		DAC_DOR1_DACC1DOR_7                                                             7
#define 		DAC_DOR1_DACC1DOR_8                                                             8
#define 		DAC_DOR1_DACC1DOR_9                                                             9
#define 		DAC_DOR1_DACC1DOR_10                                                            10
#define 		DAC_DOR1_DACC1DOR_11                                                            11

/*Bit definition for DAC_DOR2 register*/
#define 		DAC_DOR2_DACC2DOR_0                                                             0
#define 		DAC_DOR2_DACC2DOR_1                                                             1
#define 		DAC_DOR2_DACC2DOR_2                                                             2
#define 		DAC_DOR2_DACC2DOR_3                                                             3
#define 		DAC_DOR2_DACC2DOR_4                                                             4
#define 		DAC_DOR2_DACC2DOR_5                                                             5
#define 		DAC_DOR2_DACC2DOR_6                                                             6
#define 		DAC_DOR2_DACC2DOR_7                                                             7
#define 		DAC_DOR2_DACC2DOR_8                                                             8
#define 		DAC_DOR2_DACC2DOR_9                                                             9
#define 		DAC_DOR2_DACC2DOR_10                                                            10
#define 		DAC_DOR2_DACC2DOR_11                                                            11

/*Bit definition for DAC_SR register*/
#define 		DAC_SR_DMAUDR1                                                             		13
#define 		DAC_SR_DMAUDR2                                                             		29
/*
==================================================
  End Section --> Bit definitions
==================================================
*/
#endif /* HMCAL_DAC_DAC_DEFS_H_ */
