/*
 * File Name --> ADC_defs.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 -->
 */

#ifndef HMCAL_ADC_ADC_DEFS_H_
#define HMCAL_ADC_ADC_DEFS_H_
/*Bit definition for ADC_SR register*/
#define ADC_SR_AWD            0
#define ADC_SR_EOC            1
#define ADC_SR_JEOC           2
#define ADC_SR_JSTRT          3
#define ADC_SR_STRT           4
#define ADC_SR_OVR            5
/*Bit definition for ADC_CR1 register*/
#define ADC_CR1_AWDCH         0
#define ADC_CR1_AWDCH_0       (0 + ADC_CR1_AWDCH)
#define ADC_CR1_AWDCH_1       (1 + ADC_CR1_AWDCH)
#define ADC_CR1_AWDCH_2       (2 + ADC_CR1_AWDCH)
#define ADC_CR1_AWDCH_3       (3 + ADC_CR1_AWDCH)
#define ADC_CR1_AWDCH_4       (4 + ADC_CR1_AWDCH)
#define ADC_CR1_EOCIE         5
#define ADC_CR1_AWDIE         6
#define ADC_CR1_JEOCIE        7
#define ADC_CR1_SCAN          8
#define ADC_CR1_AWDSGL        9
#define ADC_CR1_JAUTO         10
#define ADC_CR1_DISCEN        11
#define ADC_CR1_JDISCEN       12
#define ADC_CR1_DISCNUM       13
#define ADC_CR1_DISCNUM_0     (0 + ADC_CR1_DISCNUM)
#define ADC_CR1_DISCNUM_1     (1 + ADC_CR1_DISCNUM)
#define ADC_CR1_DISCNUM_2     (2 + ADC_CR1_DISCNUM)
#define ADC_CR1_JAWDEN        22
#define ADC_CR1_AWDEN         23
#define ADC_CR1_RES           24
#define ADC_CR1_RES_0         (0 + ADC_CR1_RES)
#define ADC_CR1_RES_1         (1 + ADC_CR1_RES)
#define ADC_CR1_OVRIE         26
/*Bit definition for ADC_CR2 register*/
#define ADC_CR2_ADON          0
#define ADC_CR2_CONT          1
#define ADC_CR2_DMA           8
#define ADC_CR2_DDS           9
#define ADC_CR2_EOCS          10
#define ADC_CR2_ALIGN         11
#define ADC_CR2_JEXTSEL       16
#define ADC_CR2_JEXTSEL_0     (0 + ADC_CR2_JEXTSEL)
#define ADC_CR2_JEXTSEL_1     (1 + ADC_CR2_JEXTSEL)
#define ADC_CR2_JEXTSEL_2     (2 + ADC_CR2_JEXTSEL)
#define ADC_CR2_JEXTSEL_3     (3 + ADC_CR2_JEXTSEL)
#define ADC_CR2_JEXTEN        20
#define ADC_CR2_JEXTEN_0      (0 + ADC_CR2_JEXTEN)
#define ADC_CR2_JEXTEN_1      (1 + ADC_CR2_JEXTEN)
#define ADC_CR2_JSWSTART      22
#define ADC_CR2_EXTSEL        24
#define ADC_CR2_EXTSEL_0      (0 + ADC_CR2_EXTSEL)
#define ADC_CR2_EXTSEL_1      (1 + ADC_CR2_EXTSEL)
#define ADC_CR2_EXTSEL_2      (2 + ADC_CR2_EXTSEL)
#define ADC_CR2_EXTSEL_3      (3 + ADC_CR2_EXTSEL)
#define ADC_CR2_EXTEN         28
#define ADC_CR2_EXTEN_0       (0 + ADC_CR2_EXTEN)
#define ADC_CR2_EXTEN_1       (1 + ADC_CR2_EXTEN)
#define ADC_CR2_SWSTART       30
/*Bit definition for ADC_SMPR1 register*/
#define ADC_SMPR1_SMP10       0
#define ADC_SMPR1_SMP10_0     (0 + ADC_SMPR1_SMP10)
#define ADC_SMPR1_SMP10_1     (1 + ADC_SMPR1_SMP10)
#define ADC_SMPR1_SMP10_2     (2 + ADC_SMPR1_SMP10)
#define ADC_SMPR1_SMP11       3
#define ADC_SMPR1_SMP11_0     (0 + ADC_SMPR1_SMP11)
#define ADC_SMPR1_SMP11_1     (1 + ADC_SMPR1_SMP11)
#define ADC_SMPR1_SMP11_2     (2 + ADC_SMPR1_SMP11)
#define ADC_SMPR1_SMP12       6
#define ADC_SMPR1_SMP12_0     (0 + ADC_SMPR1_SMP12)
#define ADC_SMPR1_SMP12_1     (1 + ADC_SMPR1_SMP12)
#define ADC_SMPR1_SMP12_2     (2 + ADC_SMPR1_SMP12)
#define ADC_SMPR1_SMP13       9
#define ADC_SMPR1_SMP13_0     (0 + ADC_SMPR1_SMP13)
#define ADC_SMPR1_SMP13_1     (1 + ADC_SMPR1_SMP13)
#define ADC_SMPR1_SMP13_2     (2 + ADC_SMPR1_SMP13)
#define ADC_SMPR1_SMP14       12
#define ADC_SMPR1_SMP14_0     (0 + ADC_SMPR1_SMP14)
#define ADC_SMPR1_SMP14_1     (1 + ADC_SMPR1_SMP14)
#define ADC_SMPR1_SMP14_2     (2 + ADC_SMPR1_SMP14)
#define ADC_SMPR1_SMP15       15
#define ADC_SMPR1_SMP15_0     (0 + ADC_SMPR1_SMP15)
#define ADC_SMPR1_SMP15_1     (1 + ADC_SMPR1_SMP15)
#define ADC_SMPR1_SMP15_2     (2 + ADC_SMPR1_SMP15)
#define ADC_SMPR1_SMP16       18
#define ADC_SMPR1_SMP16_0     (0 + ADC_SMPR1_SMP16)
#define ADC_SMPR1_SMP16_1     (1 + ADC_SMPR1_SMP16)
#define ADC_SMPR1_SMP16_2     (2 + ADC_SMPR1_SMP16)
#define ADC_SMPR1_SMP17       21
#define ADC_SMPR1_SMP17_0     (0 + ADC_SMPR1_SMP17)
#define ADC_SMPR1_SMP17_1     (1 + ADC_SMPR1_SMP17)
#define ADC_SMPR1_SMP17_2     (2 + ADC_SMPR1_SMP17)
#define ADC_SMPR1_SMP18       24
#define ADC_SMPR1_SMP18_0     (0 + ADC_SMPR1_SMP18)
#define ADC_SMPR1_SMP18_1     (1 + ADC_SMPR1_SMP18)
#define ADC_SMPR1_SMP18_2     (2 + ADC_SMPR1_SMP18)
/*Bit definition for ADC_SMPR2 register*/
#define ADC_SMPR2_SMP0        0
#define ADC_SMPR2_SMP0_0      (0 + ADC_SMPR2_SMP0)
#define ADC_SMPR2_SMP0_1      (1 + ADC_SMPR2_SMP0)
#define ADC_SMPR2_SMP0_2      (2 + ADC_SMPR2_SMP0)
#define ADC_SMPR2_SMP1        3
#define ADC_SMPR2_SMP1_0      (0 + ADC_SMPR2_SMP1)
#define ADC_SMPR2_SMP1_1      (1 + ADC_SMPR2_SMP1)
#define ADC_SMPR2_SMP1_2      (2 + ADC_SMPR2_SMP1)
#define ADC_SMPR2_SMP2        6
#define ADC_SMPR2_SMP2_0      (0 + ADC_SMPR2_SMP2)
#define ADC_SMPR2_SMP2_1      (1 + ADC_SMPR2_SMP2)
#define ADC_SMPR2_SMP2_2      (2 + ADC_SMPR2_SMP2)
#define ADC_SMPR2_SMP3        9
#define ADC_SMPR2_SMP3_0      (0 + ADC_SMPR2_SMP3)
#define ADC_SMPR2_SMP3_1      (1 + ADC_SMPR2_SMP3)
#define ADC_SMPR2_SMP3_2      (2 + ADC_SMPR2_SMP3)
#define ADC_SMPR2_SMP4        12
#define ADC_SMPR2_SMP4_0      (0 + ADC_SMPR2_SMP4)
#define ADC_SMPR2_SMP4_1      (1 + ADC_SMPR2_SMP4)
#define ADC_SMPR2_SMP4_2      (2 + ADC_SMPR2_SMP4)
#define ADC_SMPR2_SMP5        15
#define ADC_SMPR2_SMP5_0      (0 + ADC_SMPR2_SMP5)
#define ADC_SMPR2_SMP5_1      (1 + ADC_SMPR2_SMP5)
#define ADC_SMPR2_SMP5_2      (2 + ADC_SMPR2_SMP5)
#define ADC_SMPR2_SMP6        18
#define ADC_SMPR2_SMP6_0      (0 + ADC_SMPR2_SMP6)
#define ADC_SMPR2_SMP6_1      (1 + ADC_SMPR2_SMP6)
#define ADC_SMPR2_SMP6_2      (2 + ADC_SMPR2_SMP6)
#define ADC_SMPR2_SMP7        21
#define ADC_SMPR2_SMP7_0      (0 + ADC_SMPR2_SMP7)
#define ADC_SMPR2_SMP7_1      (1 + ADC_SMPR2_SMP7)
#define ADC_SMPR2_SMP7_2      (2 + ADC_SMPR2_SMP7)
#define ADC_SMPR2_SMP8        24
#define ADC_SMPR2_SMP8_0      (0 + ADC_SMPR2_SMP8)
#define ADC_SMPR2_SMP8_1      (1 + ADC_SMPR2_SMP8)
#define ADC_SMPR2_SMP8_2      (2 + ADC_SMPR2_SMP8)
#define ADC_SMPR2_SMP9        27
#define ADC_SMPR2_SMP9_0      (0 + ADC_SMPR2_SMP9)
#define ADC_SMPR2_SMP9_1      (1 + ADC_SMPR2_SMP9)
#define ADC_SMPR2_SMP9_2      (2 + ADC_SMPR2_SMP9)
/*Bit definition for ADC_JOFRx register*/
#define ADC_JOFR1_JOFFSET1    0
#define ADC_JOFR2_JOFFSET2    0
#define ADC_JOFR3_JOFFSET3    0
#define ADC_JOFR4_JOFFSET4    0
/*Bit definition for ADC_HTR register*/
#define ADC_HTR_HT            0
/*Bit definition for ADC_LTR register*/
#define ADC_LTR_LT            0
/*Bit definition for ADC_SQR1 register  *******************/
#define ADC_SQR1_SQ13         0
#define ADC_SQR1_SQ13_0       (0 + ADC_SQR1_SQ13)
#define ADC_SQR1_SQ13_1       (1 + ADC_SQR1_SQ13)
#define ADC_SQR1_SQ13_2       (2 + ADC_SQR1_SQ13)
#define ADC_SQR1_SQ13_3       (3 + ADC_SQR1_SQ13)
#define ADC_SQR1_SQ13_4       (4 + ADC_SQR1_SQ13)
#define ADC_SQR1_SQ14         5
#define ADC_SQR1_SQ14_0       (0 + ADC_SQR1_SQ14)
#define ADC_SQR1_SQ14_1       (1 + ADC_SQR1_SQ14)
#define ADC_SQR1_SQ14_2       (2 + ADC_SQR1_SQ14)
#define ADC_SQR1_SQ14_3       (3 + ADC_SQR1_SQ14)
#define ADC_SQR1_SQ14_4       (4 + ADC_SQR1_SQ14)
#define ADC_SQR1_SQ15         10
#define ADC_SQR1_SQ15_0       (0 + ADC_SQR1_SQ15)
#define ADC_SQR1_SQ15_1       (1 + ADC_SQR1_SQ15)
#define ADC_SQR1_SQ15_2       (2 + ADC_SQR1_SQ15)
#define ADC_SQR1_SQ15_3       (3 + ADC_SQR1_SQ15)
#define ADC_SQR1_SQ15_4       (4 + ADC_SQR1_SQ15)
#define ADC_SQR1_SQ16         15
#define ADC_SQR1_SQ16_0       (0 + ADC_SQR1_SQ16)
#define ADC_SQR1_SQ16_1       (1 + ADC_SQR1_SQ16)
#define ADC_SQR1_SQ16_2       (2 + ADC_SQR1_SQ16)
#define ADC_SQR1_SQ16_3       (3 + ADC_SQR1_SQ16)
#define ADC_SQR1_SQ16_4       (4 + ADC_SQR1_SQ16)
#define ADC_SQR1_L            20
#define ADC_SQR1_L_0          (0 + ADC_SQR1_L)
#define ADC_SQR1_L_1          (1 + ADC_SQR1_L)
#define ADC_SQR1_L_2          (2 + ADC_SQR1_L)
#define ADC_SQR1_L_3          (3 + ADC_SQR1_L)
/*Bit defi(4 + ADC_SQR1_SQ13)register  *******************/
#define ADC_SQR2_SQ7          0
#define ADC_SQR2_SQ7_0        (0 + ADC_SQR2_SQ7)
#define ADC_SQR2_SQ7_1        (1 + ADC_SQR2_SQ7)
#define ADC_SQR2_SQ7_2        (2 + ADC_SQR2_SQ7)
#define ADC_SQR2_SQ7_3        (3 + ADC_SQR2_SQ7)
#define ADC_SQR2_SQ7_4        (4 + ADC_SQR2_SQ7)
#define ADC_SQR2_SQ8          5
#define ADC_SQR2_SQ8_0        (0 + ADC_SQR2_SQ8)
#define ADC_SQR2_SQ8_1        (1 + ADC_SQR2_SQ8)
#define ADC_SQR2_SQ8_2        (2 + ADC_SQR2_SQ8)
#define ADC_SQR2_SQ8_3        (3 + ADC_SQR2_SQ8)
#define ADC_SQR2_SQ8_4        (4 + ADC_SQR2_SQ8)
#define ADC_SQR2_SQ9          10
#define ADC_SQR2_SQ9_0        (0 + ADC_SQR2_SQ9)
#define ADC_SQR2_SQ9_1        (1 + ADC_SQR2_SQ9)
#define ADC_SQR2_SQ9_2        (2 + ADC_SQR2_SQ9)
#define ADC_SQR2_SQ9_3        (3 + ADC_SQR2_SQ9)
#define ADC_SQR2_SQ9_4        (4 + ADC_SQR2_SQ9)
#define ADC_SQR2_SQ10         15
#define ADC_SQR2_SQ10_0       (0 + ADC_SQR2_SQ10)
#define ADC_SQR2_SQ10_1       (1 + ADC_SQR2_SQ10)
#define ADC_SQR2_SQ10_2       (2 + ADC_SQR2_SQ10)
#define ADC_SQR2_SQ10_3       (3 + ADC_SQR2_SQ10)
#define ADC_SQR2_SQ10_4       (4 + ADC_SQR2_SQ10)
#define ADC_SQR2_SQ11         20
#define ADC_SQR2_SQ11_0       (0 + ADC_SQR2_SQ11)
#define ADC_SQR2_SQ11_1       (1 + ADC_SQR2_SQ11)
#define ADC_SQR2_SQ11_2       (2 + ADC_SQR2_SQ11)
#define ADC_SQR2_SQ11_3       (3 + ADC_SQR2_SQ11)
#define ADC_SQR2_SQ11_4       (4 + ADC_SQR2_SQ11)
#define ADC_SQR2_SQ12         25
#define ADC_SQR2_SQ12_0       (0 + ADC_SQR2_SQ12)
#define ADC_SQR2_SQ12_1       (1 + ADC_SQR2_SQ12)
#define ADC_SQR2_SQ12_2       (2 + ADC_SQR2_SQ12)
#define ADC_SQR2_SQ12_3       (3 + ADC_SQR2_SQ12)
#define ADC_SQR2_SQ12_4       (4 + ADC_SQR2_SQ12)
/*Bit definition for ADC_SQR3 register  *******************/
#define ADC_SQR3_SQ1          0
#define ADC_SQR3_SQ1_0        (0 + ADC_SQR3_SQ1)
#define ADC_SQR3_SQ1_1        (1 + ADC_SQR3_SQ1)
#define ADC_SQR3_SQ1_2        (2 + ADC_SQR3_SQ1)
#define ADC_SQR3_SQ1_3        (3 + ADC_SQR3_SQ1)
#define ADC_SQR3_SQ1_4        (4 + ADC_SQR3_SQ1)
#define ADC_SQR3_SQ2          5
#define ADC_SQR3_SQ2_0        (0 + ADC_SQR3_SQ2)
#define ADC_SQR3_SQ2_1        (1 + ADC_SQR3_SQ2)
#define ADC_SQR3_SQ2_2        (2 + ADC_SQR3_SQ2)
#define ADC_SQR3_SQ2_3        (3 + ADC_SQR3_SQ2)
#define ADC_SQR3_SQ2_4        (4 + ADC_SQR3_SQ2)
#define ADC_SQR3_SQ3          10
#define ADC_SQR3_SQ3_0        (0 + ADC_SQR3_SQ3)
#define ADC_SQR3_SQ3_1        (1 + ADC_SQR3_SQ3)
#define ADC_SQR3_SQ3_2        (2 + ADC_SQR3_SQ3)
#define ADC_SQR3_SQ3_3        (3 + ADC_SQR3_SQ3)
#define ADC_SQR3_SQ3_4        (4 + ADC_SQR3_SQ3)
#define ADC_SQR3_SQ4          15
#define ADC_SQR3_SQ4_0        (0 + ADC_SQR3_SQ4)
#define ADC_SQR3_SQ4_1        (1 + ADC_SQR3_SQ4)
#define ADC_SQR3_SQ4_2        (2 + ADC_SQR3_SQ4)
#define ADC_SQR3_SQ4_3        (3 + ADC_SQR3_SQ4)
#define ADC_SQR3_SQ4_4        (4 + ADC_SQR3_SQ4)
#define ADC_SQR3_SQ5          20
#define ADC_SQR3_SQ5_0        (0 + ADC_SQR3_SQ5)
#define ADC_SQR3_SQ5_1        (1 + ADC_SQR3_SQ5)
#define ADC_SQR3_SQ5_2        (2 + ADC_SQR3_SQ5)
#define ADC_SQR3_SQ5_3        (3 + ADC_SQR3_SQ5)
#define ADC_SQR3_SQ5_4        (4 + ADC_SQR3_SQ5)
#define ADC_SQR3_SQ6          25
#define ADC_SQR3_SQ6_0        (0 + ADC_SQR3_SQ6)
#define ADC_SQR3_SQ6_1        (1 + ADC_SQR3_SQ6)
#define ADC_SQR3_SQ6_2        (2 + ADC_SQR3_SQ6)
#define ADC_SQR3_SQ6_3        (3 + ADC_SQR3_SQ6)
#define ADC_SQR3_SQ6_4        (4 + ADC_SQR3_SQ6)
/*Bit definition for ADC_JSQR register  *******************/
#define ADC_JSQR_JSQ1         0
#define ADC_JSQR_JSQ1_0       (0 + ADC_JSQR_JSQ1)
#define ADC_JSQR_JSQ1_1       (1 + ADC_JSQR_JSQ1)
#define ADC_JSQR_JSQ1_2       (2 + ADC_JSQR_JSQ1)
#define ADC_JSQR_JSQ1_3       (3 + ADC_JSQR_JSQ1)
#define ADC_JSQR_JSQ1_4       (4 + ADC_JSQR_JSQ1)
#define ADC_JSQR_JSQ2         5
#define ADC_JSQR_JSQ2_0       (0 + ADC_JSQR_JSQ2)
#define ADC_JSQR_JSQ2_1       (1 + ADC_JSQR_JSQ2)
#define ADC_JSQR_JSQ2_2       (2 + ADC_JSQR_JSQ2)
#define ADC_JSQR_JSQ2_3       (3 + ADC_JSQR_JSQ2)
#define ADC_JSQR_JSQ2_4       (4 + ADC_JSQR_JSQ2)
#define ADC_JSQR_JSQ3         10
#define ADC_JSQR_JSQ3_0       (0 + ADC_JSQR_JSQ3)
#define ADC_JSQR_JSQ3_1       (1 + ADC_JSQR_JSQ3)
#define ADC_JSQR_JSQ3_2       (2 + ADC_JSQR_JSQ3)
#define ADC_JSQR_JSQ3_3       (3 + ADC_JSQR_JSQ3)
#define ADC_JSQR_JSQ3_4       (4 + ADC_JSQR_JSQ3)
#define ADC_JSQR_JSQ4         15
#define ADC_JSQR_JSQ4_0       (0 + ADC_JSQR_JSQ4)
#define ADC_JSQR_JSQ4_1       (1 + ADC_JSQR_JSQ4)
#define ADC_JSQR_JSQ4_2       (2 + ADC_JSQR_JSQ4)
#define ADC_JSQR_JSQ4_3       (3 + ADC_JSQR_JSQ4)
#define ADC_JSQR_JSQ4_4       (4 + ADC_JSQR_JSQ4)
#define ADC_JSQR_JL           20
#define ADC_JSQR_JL_0         (0 + ADC_JSQR_JL)
#define ADC_JSQR_JL_1         (1 + ADC_JSQR_JL)
/*Bit definition for ADC_JDR1 register  *******************/
#define ADC_JDR1_JDATA        0
/*Bit definition for ADC_JDR2 register  *******************/
#define ADC_JDR2_JDATA        0
/*Bit definition for ADC_JDR3 register  *******************/
#define ADC_JDR3_JDATA        0
/*Bit definition for ADC_JDR4 register  *******************/
#define ADC_JDR4_JDATA        0
/********************  Bit definition for ADC_DR register*/
#define ADC_DR_DATA           0
#define ADC_DR_ADC2DATA       16
/*Bit definition for ADC_CSR register*/
#define ADC_CSR_AWD1          0
#define ADC_CSR_EOC1          1
#define ADC_CSR_JEOC1         2
#define ADC_CSR_JSTRT1        3
#define ADC_CSR_STRT1         4
#define ADC_CSR_OVR1          5
#define ADC_CSR_AWD2          8
#define ADC_CSR_EOC2          9
#define ADC_CSR_JEOC2         10
#define ADC_CSR_JSTRT2        11
#define ADC_CSR_STRT2         12
#define ADC_CSR_OVR2          13
#define ADC_CSR_AWD3          16
#define ADC_CSR_EOC3          17
#define ADC_CSR_JEOC3         18
#define ADC_CSR_JSTRT3        19
#define ADC_CSR_STRT3         20
#define ADC_CSR_OVR3          21
/*Bit definition for ADC_CCR register*/
#define ADC_CCR_MULTI         0
#define ADC_CCR_MULTI_0       (0 + ADC_CCR_MULTI)
#define ADC_CCR_MULTI_1       (1 + ADC_CCR_MULTI)
#define ADC_CCR_MULTI_2       (2 + ADC_CCR_MULTI)
#define ADC_CCR_MULTI_3       (3 + ADC_CCR_MULTI)
#define ADC_CCR_MULTI_4       (4 + ADC_CCR_MULTI)
#define ADC_CCR_DELAY         8
#define ADC_CCR_DELAY_0       (0 + ADC_CCR_DELAY)
#define ADC_CCR_DELAY_1       (1 + ADC_CCR_DELAY)
#define ADC_CCR_DELAY_2       (2 + ADC_CCR_DELAY)
#define ADC_CCR_DELAY_3       (3 + ADC_CCR_DELAY)
#define ADC_CCR_DDS           13
#define ADC_CCR_DMA           14
#define ADC_CCR_DMA_0         (0 + ADC_CCR_DMA)
#define ADC_CCR_DMA_1         (1 + ADC_CCR_DMA)
#define ADC_CCR_ADCPRE        16
#define ADC_CCR_ADCPRE_0      (0 + ADC_CCR_ADCPRE)
#define ADC_CCR_ADCPRE_1      (1 + ADC_CCR_ADCPRE)
#define ADC_CCR_VBATE         22
#define ADC_CCR_TSVREFE       23
/*Bit definition for ADC_CDR register*/
#define ADC_CDR_DATA1         0
#define ADC_CDR_DATA2         16
#endif /* HMCAL_ADC_ADC_DEFS_H_ */
