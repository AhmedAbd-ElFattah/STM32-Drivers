/*
 * File Name --> FMI_defs.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 -->  
 * Github    --> github.com/AhmedAbd-ElFattah
 * Linkedin  --> https://www.linkedin.com/in/ahmed-mohamed-abd-elfattah-39705b238/
 */

#ifndef HMCAL_FMI_FMI_DEFS_H_
#define HMCAL_FMI_FMI_DEFS_H_

/*
==================================================
  Start Section --> Bit definitions
==================================================
*/
/* FMI_ACR Bits. */
#define			FMI_FLASH_ACR_LATENCY_0		0
#define			FMI_FLASH_ACR_LATENCY_1		1
#define			FMI_FLASH_ACR_LATENCY_2		2

#define			FMI_FLASH_ACR_PRFTEN		8
#define			FMI_FLASH_ACR_ICEN			9
#define			FMI_FLASH_ACR_DCEN			10
#define			FMI_FLASH_ACR_ICRST			11
#define			FMI_FLASH_ACR_DCRST			12

/* FMI_SR Bits. */
#define			FMI_SR_EOP					0
#define			FMI_SR_OPERR				1
#define			FMI_SR_WRPERR				4
#define			FMI_SR_PGAERR				5
#define			FMI_SR_PGPERR				6
#define			FMI_SR_RGSERR				7
#define			FMI_SR_BSY					16

/* FMI_CR Bits. */
#define			FMI_CR_PG					0
#define			FMI_CR_SER					1
#define			FMI_CR_MER					2
#define			FMI_CR_SNB_0				3
#define			FMI_CR_SNB_1				4
#define			FMI_CR_SNB_2				5
#define			FMI_CR_SNB_3				6
#define			FMI_CR_PSIZE_0				8
#define			FMI_CR_PSIZE_1				9
#define			FMI_CR_STRT					16
#define			FMI_CR_EOPIE				24
#define			FMI_CR_ERRIE				25
#define			FMI_CR_LOCK					31

/* FMI_OPTCR Bits. */
#define         FMI_OPTCR_OPTLOCK 			0
#define         FMI_OPTCR_OPTSTRT 			1
#define         FMI_OPTCR_BOR_LEV_0 		2
#define         FMI_OPTCR_BOR_LEV_1 		3
#define         FMI_OPTCR_WDG_SW 			5
#define         FMI_OPTCR_NRST_STOP 		6
#define         FMI_OPTCR_NRST_STDBY 		7
#define         FMI_OPTCR_RDP_0 			8
#define         FMI_OPTCR_RDP_1 			9
#define         FMI_OPTCR_RDP_2 			10
#define         FMI_OPTCR_RDP_3 			11
#define         FMI_OPTCR_RDP_4 			12
#define         FMI_OPTCR_RDP_5 			13
#define         FMI_OPTCR_RDP_6 			14
#define         FMI_OPTCR_RDP_7 			15
#define         FMI_OPTCR_NWRP_0 			16
#define         FMI_OPTCR_NWRP_1 			17
#define         FMI_OPTCR_NWRP_2 			18
#define         FMI_OPTCR_NWRP_3 			19
#define         FMI_OPTCR_NWRP_4 			20
#define         FMI_OPTCR_NWRP_5 			21
#define         FMI_OPTCR_NWRP_6 			22
#define         FMI_OPTCR_NWRP_7 			23
#define         FMI_OPTCR_NWRP_8 			24
#define         FMI_OPTCR_NWRP_9 			25
#define         FMI_OPTCR_NWRP_10 			26
#define         FMI_OPTCR_NWRP_11 			27
/*
==================================================
  End   Section --> Bit definitions
==================================================
*/



#endif /* HMCAL_FMI_FMI_DEFS_H_ */
