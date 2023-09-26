/*
 * File Name --> SPI_defs.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 */

#ifndef HMCAL_SPI_SPI_DEFS_H_
#define HMCAL_SPI_SPI_DEFS_H_

/*
==================================================
  Start Section --> Bit definitions
==================================================
*/

/*Bit definitions for SPI_CR1 register.*/
#define 		SPI_CR1_CPHA                                                                            0
#define 		SPI_CR1_CPOL                                                                            1
#define 		SPI_CR1_MSTR                                                                            2
#define 		SPI_CR1_BR_0                                                                            3
#define 		SPI_CR1_BR_1                                                                            4
#define 		SPI_CR1_BR_2                                                                            5
#define 		SPI_CR1_SPE                                                                             6
#define 		SPI_CR1_LSBFIRST                                                                        7
#define 		SPI_CR1_SSI                                                                             8
#define 		SPI_CR1_SSM                                                                             9
#define 		SPI_CR1_RXONLY                                                                          10
#define 		SPI_CR1_DFF                                                                             11
#define 		SPI_CR1_CRCNEXT                                                                         12
#define 		SPI_CR1_CRCEN                                                                           13
#define 		SPI_CR1_BIDIOE                                                                          14
#define 		SPI_CR1_BIDIMODE                                                                        15


/*Bit definitions for SPI_CR2 register.*/
#define 		SPI_CR2_RXDMAEN                                                                         0
#define 		SPI_CR2_TXDMAEN                                                                         1
#define 		SPI_CR2_SSOE                                                                            2
#define 		SPI_CR2_FRF                                                                             4
#define 		SPI_CR2_ERRIE                                                                           5
#define 		SPI_CR2_RXNEIE                                                                          6
#define 		SPI_CR2_TXEIE                                                                           7


/*Bit definitions for SPI_SR register.*/
#define 		SPI_SR_RXNE                                                                            0
#define 		SPI_SR_TXE                                                                             1
#define 		SPI_SR_CHSIDE                                                                          2
#define 		SPI_SR_UDR                                                                             3
#define 		SPI_SR_CRCERR                                                                          4
#define 		SPI_SR_MODF                                                                            5
#define 		SPI_SR_OVR                                                                             6
#define 		SPI_SR_BSY                                                                             7
#define 		SPI_SR_FRE                                                                             8


/*Bit definitions for SPI_DR register.*/
#define 		SPI_DR_DR_0                                                                            0
#define 		SPI_DR_DR_1                                                                            1
#define 		SPI_DR_DR_2                                                                            2
#define 		SPI_DR_DR_3                                                                            3
#define 		SPI_DR_DR_4                                                                            4
#define 		SPI_DR_DR_5                                                                            5
#define 		SPI_DR_DR_6                                                                            6
#define 		SPI_DR_DR_7                                                                            7
#define 		SPI_DR_DR_8                                                                            8
#define 		SPI_DR_DR_9                                                                            9
#define 		SPI_DR_DR_10                                                                           10
#define 		SPI_DR_DR_11                                                                           11
#define 		SPI_DR_DR_12                                                                           12
#define 		SPI_DR_DR_13                                                                           13
#define 		SPI_DR_DR_14                                                                           14
#define 		SPI_DR_DR_15                                                                           15


/*Bit definitions for SPI_CRCPR register.*/
#define 		SPI_CRCPR_CRCPOLY_0                                                                       0
#define 		SPI_CRCPR_CRCPOLY_1                                                                       1
#define 		SPI_CRCPR_CRCPOLY_2                                                                       2
#define 		SPI_CRCPR_CRCPOLY_3                                                                       3
#define 		SPI_CRCPR_CRCPOLY_4                                                                       4
#define 		SPI_CRCPR_CRCPOLY_5                                                                       5
#define 		SPI_CRCPR_CRCPOLY_6                                                                       6
#define 		SPI_CRCPR_CRCPOLY_7                                                                       7
#define 		SPI_CRCPR_CRCPOLY_8                                                                       8
#define 		SPI_CRCPR_CRCPOLY_9                                                                       9
#define 		SPI_CRCPR_CRCPOLY_10                                                                      10
#define 		SPI_CRCPR_CRCPOLY_11                                                                      11
#define 		SPI_CRCPR_CRCPOLY_12                                                                      12
#define 		SPI_CRCPR_CRCPOLY_13                                                                      13
#define 		SPI_CRCPR_CRCPOLY_14                                                                      14
#define 		SPI_CRCPR_CRCPOLY_15                                                                      15


/*Bit definitions for SPI_RXCRCR register.*/
#define 		SPI_RXCRCR_RXCRC_0                                                                         0
#define 		SPI_RXCRCR_RXCRC_1                                                                         1
#define 		SPI_RXCRCR_RXCRC_2                                                                         2
#define 		SPI_RXCRCR_RXCRC_3                                                                         3
#define 		SPI_RXCRCR_RXCRC_4                                                                         4
#define 		SPI_RXCRCR_RXCRC_5                                                                         5
#define 		SPI_RXCRCR_RXCRC_6                                                                         6
#define 		SPI_RXCRCR_RXCRC_7                                                                         7
#define 		SPI_RXCRCR_RXCRC_8                                                                         8
#define 		SPI_RXCRCR_RXCRC_9                                                                         9
#define 		SPI_RXCRCR_RXCRC_10                                                                        10
#define 		SPI_RXCRCR_RXCRC_11                                                                        11
#define 		SPI_RXCRCR_RXCRC_12                                                                        12
#define 		SPI_RXCRCR_RXCRC_13                                                                        13
#define 		SPI_RXCRCR_RXCRC_14                                                                        14
#define 		SPI_RXCRCR_RXCRC_15                                                                        15

/*Bit definitions for SPI_TXCRCR register.*/
#define 		SPI_TXCRCR_TXCRC_0                                                                         0
#define 		SPI_TXCRCR_TXCRC_1                                                                         1
#define 		SPI_TXCRCR_TXCRC_2                                                                         2
#define 		SPI_TXCRCR_TXCRC_3                                                                         3
#define 		SPI_TXCRCR_TXCRC_4                                                                         4
#define 		SPI_TXCRCR_TXCRC_5                                                                         5
#define 		SPI_TXCRCR_TXCRC_6                                                                         6
#define 		SPI_TXCRCR_TXCRC_7                                                                         7
#define 		SPI_TXCRCR_TXCRC_8                                                                         8
#define 		SPI_TXCRCR_TXCRC_9                                                                         9
#define 		SPI_TXCRCR_TXCRC_10                                                                        10
#define 		SPI_TXCRCR_TXCRC_11                                                                        11
#define 		SPI_TXCRCR_TXCRC_12                                                                        12
#define 		SPI_TXCRCR_TXCRC_13                                                                        13
#define 		SPI_TXCRCR_TXCRC_14                                                                        14
#define 		SPI_TXCRCR_TXCRC_15                                                                        15


/*
==================================================
  End Section --> Bit definitions
==================================================
*/


#endif /* HMCAL_SPI_SPI_DEFS_H_ */
