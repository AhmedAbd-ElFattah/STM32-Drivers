/*
 * File Name --> GPIO_Private.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> GPIO driver private info like addresses.
 * */

#ifndef HMCAL_GPIO_GPIO_PRIVATE_H_
#define HMCAL_GPIO_GPIO_PRIVATE_H_

/*
==================================================
  Start Section --> Define peripheral addresses.
==================================================
*/
#define GPIOA_BASE_ADDRESS	0x40020000
#define GPIOB_BASE_ADDRESS	0x40020400
#define GPIOC_BASE_ADDRESS	0x40020800
#define GPIOD_BASE_ADDRESS	0x40020C00
#define GPIOE_BASE_ADDRESS	0x40021000
#define GPIOF_BASE_ADDRESS	0x40021400
#define GPIOG_BASE_ADDRESS	0x40021800
#define GPIOH_BASE_ADDRESS	0x40021C00
#define GPIOI_BASE_ADDRESS	0x40022000
#define GPIOJ_BASE_ADDRESS	0x40022400
#define GPIOK_BASE_ADDRESS	0x40022800

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

#define GPIO_MODER_RESET_VALUE					0x00
#define GPIO_OTYPER_RESET_VALUE					0x00
#define GPIO_OSPEEDER_RESET_VALUE				0x00
#define GPIO_PUPDR_RESET_VALUE					0x00
#define GPIO_IDR_RESET_VALUE					0x00
#define GPIO_ODR_RESET_VALUE					0x00
#define GPIO_BSRR_RESET_VALUE					0x00
#define GPIO_LCKR_RESET_VALUE					0x00
#define GPIO_AFRL_RESET_VALUE					0x00
#define GPIO_AFRH_RESET_VALUE					0x00

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
	/* GPIO port mode register.*/
	volatile u32 MODER;
	/*GPIO port output type register.*/
	volatile u32 OTYPER;
	/*GPIO port output speed register.*/
	volatile u32 OSPEEDER;
	/*GPIO port pull-up/pull-down register.*/
	volatile u32 PUPDR;
	/*GPIO port input data register.*/
	volatile u32 IDR;
	/*GPIO port output data register.*/
	volatile u32 ODR;
	/*GPIO port bit set/reset register*/
	volatile u32 BSRR;
	/*GPIO port configuration lock register*/
	volatile u32 LCKR;
	/*GPIO alternate function low register*/
	volatile u32 AFRL;
	/*GPIO alternate function high register*/
	volatile u32 AFRH;
}GPIO_MemMap;
/*
==================================================
  End   Section --> Peripheral register mapping.
==================================================
*/

/*
==================================================
  Start Section --> Define peripheral with it's address.
==================================================
*/

const static u32 GCS_GPIO_InstanceIdMapping_u32[]={

		GPIOA_BASE_ADDRESS,
		GPIOB_BASE_ADDRESS,
		GPIOC_BASE_ADDRESS,
		GPIOD_BASE_ADDRESS,
		GPIOE_BASE_ADDRESS,
		GPIOF_BASE_ADDRESS,
		GPIOG_BASE_ADDRESS,
		GPIOH_BASE_ADDRESS,
		GPIOI_BASE_ADDRESS,
		GPIOJ_BASE_ADDRESS,
		GPIOK_BASE_ADDRESS
};
/*
==================================================
  End Section --> Define peripheral with it's address.
==================================================
*/

#endif /* HMCAL_GPIO_GPIO_PRIVATE_H_ */
