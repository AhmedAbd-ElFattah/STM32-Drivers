/*
 * File Name --> SPI_Private.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> SPI driver private info like addresses.
 * */

#ifndef HMCAL_SPI_SPI_PRIVATE_H_
#define HMCAL_SPI_SPI_PRIVATE_H_

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
#define 		SPI1_BASE_ADDRESS 																0x40013000
#define 		SPI2_BASE_ADDRESS 																0x40003800
#define 		SPI3_BASE_ADDRESS 																0x40003C00
#define 		SPI4_BASE_ADDRESS 																0x40013400
#define 		SPI5_BASE_ADDRESS 																0x40015000
#define 		SPI6_BASE_ADDRESS 																0x40015400
/*
==================================================
  End   Section --> Define peripheral addresses.
==================================================
*/

/*
==================================================
  Start Section --> Reset values.
==================================================
 */

#define SPI_CR1_RESET_VALUE				0x0000
#define SPI_CR2_RESET_VALUE				0x0000
#define SPI_SR_RESET_VALUE				0x0002
#define SPI_DR_RESET_VALUE				0x0000
#define SPI_CRCPR_RESET_VALUE			0x0007
#define SPI_RXCRCR_RESET_VALUE			0x0000
#define SPI_TXCRCR_RESET_VALUE			0x0000
#define SPI_I2SCFGR_RESET_VALUE			0x0000
#define SPI_I2SPR_RESET_VALUE			0x0010
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

typedef struct {
	/*SPI Control register 1.*/
	volatile u32 CR1;
	/*SPI Control register 2.*/
	volatile u32 CR2;
	/*SPI Control status register.*/
	volatile u32 SR;
	/*SPI Control data register.*/
	volatile u32 DR;
	/*SPI CRC polynomial register.*/
	volatile u32 CRCPR;
	/*SPI RX CRC register.*/
	volatile u32 RXCRCR;
	/*SPI TX CRC register.*/
	volatile u32 TXCRCR;
	/*SPI I2S configuration register.*/
	volatile u32 I2SCFGR;
	/*SPI I2S prescaler register.*/
	volatile u32 I2SPR;
}SPI_MemMap;

/*
==================================================
  End Section --> Peripheral register mapping.
==================================================
 */

/*
==================================================
  Start Section --> Define peripheral with it's address.
==================================================
 */
const static u32 GCS_SPI_InstanceIdMapping_u32[]={
		SPI1_BASE_ADDRESS,
		SPI2_BASE_ADDRESS,
		SPI3_BASE_ADDRESS,
		SPI4_BASE_ADDRESS,
		SPI5_BASE_ADDRESS,
		SPI6_BASE_ADDRESS,
};

/*
==================================================
  End Section --> Define peripheral with it's address.
==================================================
 */
#endif /* HMCAL_SPI_SPI_PRIVATE_H_ */
