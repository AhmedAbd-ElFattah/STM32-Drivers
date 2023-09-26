/*
 * File Name --> USART_defs.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 */

#ifndef HMCAL_USART_USART_DEFS_H_
#define HMCAL_USART_USART_DEFS_H_


/*
==================================================
  Start Section --> Bit definitions
==================================================
*/
/*Bit definitons for USART_SR register*/

#define 		USART_SR_PE			0
#define 		USART_SR_FE         1
#define 		USART_SR_NF         2
#define 		USART_SR_ORE        3
#define 		USART_SR_IDLE       4
#define 		USART_SR_RXNE       5
#define 		USART_SR_TC         6
#define 		USART_SR_TXE        7
#define 		USART_SR_LBD        8
#define 		USART_SR_CTS        9

/*Bit definitons for USART_DR register*/

#define 		USART_DR_0          0
#define 		USART_DR_1          1
#define 		USART_DR_2          2
#define 		USART_DR_3          3
#define 		USART_DR_4          4
#define 		USART_DR_5          5
#define 		USART_DR_6          6
#define 		USART_DR_7          7
#define 		USART_DR_8          8

/*Bit definitons for USART_BRR (Baud rate register) register*/

#define 		USART_BRR_DIV_FRACTION_0   0
#define 		USART_BRR_DIV_FRACTION_1   1
#define 		USART_BRR_DIV_FRACTION_2   2
#define 		USART_BRR_DIV_FRACTION_3   3
#define 		USART_BRR_DIV_MANTISSA_0   4
#define 		USART_BRR_DIV_MANTISSA_1   5
#define 		USART_BRR_DIV_MANTISSA_2   6
#define 		USART_BRR_DIV_MANTISSA_3   7
#define 		USART_BRR_DIV_MANTISSA_4   8
#define 		USART_BRR_DIV_MANTISSA_5   9
#define 		USART_BRR_DIV_MANTISSA_6   10
#define 		USART_BRR_DIV_MANTISSA_7   11
#define 		USART_BRR_DIV_MANTISSA_8   12
#define 		USART_BRR_DIV_MANTISSA_9   13
#define 		USART_BRR_DIV_MANTISSA_10  14
#define 		USART_BRR_DIV_MANTISSA_11  15

/*Bit definitons for USART_CR1 (Control register 1) register*/

#define 		USART_CR1_SBK     0
#define 		USART_CR1_RWU     1
#define 		USART_CR1_RE      2
#define 		USART_CR1_TE      3
#define 		USART_CR1_IDLEIE  4
#define 		USART_CR1_RXNEIE  5
#define 		USART_CR1_TCIE    6
#define 		USART_CR1_TXEIE   7
#define 		USART_CR1_PEIE    8
#define 		USART_CR1_PS      9
#define 		USART_CR1_PCE     10
#define 		USART_CR1_WAKE    11
#define 		USART_CR1_M       12
#define 		USART_CR1_UE      13
#define 		USART_CR1_OVER8   15


/*Bit definitons for USART_CR2 (Control register 2) register*/

#define 		USART_CR2_ADD_0    0
#define 		USART_CR2_ADD_1    1
#define 		USART_CR2_ADD_2    2
#define 		USART_CR2_ADD_3    3
#define 		USART_CR2_LBDL     5
#define 		USART_CR2_LBDIE    6
#define 		USART_CR2_LBCL     8
#define 		USART_CR2_CPHA     9
#define 		USART_CR2_CPOL     10
#define 		USART_CR2_CLKEN    11
#define 		USART_CR2_STOP_0   12
#define 		USART_CR2_STOP_1   13
#define 		USART_CR2_LINEN    14

/*Bit definitons for USART_CR3 (Control register 3) register*/

#define 		USART_CR3_EIE      0
#define 		USART_CR3_IREN     1
#define 		USART_CR3_IRLP     2
#define 		USART_CR3_HDSEL    3
#define 		USART_CR3_NACK     4
#define 		USART_CR3_SCEN     5
#define 		USART_CR3_DMAR     6
#define 		USART_CR3_DMAT     7
#define 		USART_CR3_RTSE     8
#define 		USART_CR3_CTSE     9
#define 		USART_CR3_CTSIE    10
#define 		USART_CR3_ONEBIT   11

/*Bit definitons for USART_GTPR (Guard time and prescaler register) register*/

#define 		USART_GTPR_PSC_0   0
#define 		USART_GTPR_PSC_1   1
#define 		USART_GTPR_PSC_2   2
#define 		USART_GTPR_PSC_3   3
#define 		USART_GTPR_PSC_4   4
#define 		USART_GTPR_PSC_5   5
#define 		USART_GTPR_PSC_6   6
#define 		USART_GTPR_PSC_7   7
#define 		USART_GTPR_GT_0    8
#define 		USART_GTPR_GT_1    9
#define 		USART_GTPR_GT_2    10
#define 		USART_GTPR_GT_3    11
#define 		USART_GTPR_GT_4    12
#define 		USART_GTPR_GT_5    13
#define 		USART_GTPR_GT_6    14
#define 		USART_GTPR_GT_7    15
/*
==================================================
  End   Section --> Bit definitions
==================================================
*/
#endif /* HMCAL_USART_USART_DEFS_H_ */
