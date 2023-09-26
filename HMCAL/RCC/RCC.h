/*
 * File Name --> RCC.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> Provides API and available configuration options for RCC peripheral.
 * */

#ifndef HMCAL_RCC_RCC_H_
#define HMCAL_RCC_RCC_H_




/*
==================================================
  Start Section --> File Includes
==================================================
*/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

/*
==================================================
  End   Section --> File Includes
==================================================
*/

/*
==================================================
  Start Section --> RCC Bus & Peripherals on bus Id definitions
==================================================
*/
/*RCC Available buses ID. */
#define			RCC_AHB1			0
#define			RCC_AHB2			1
#define			RCC_AHB3			2

#define			RCC_APB1			3
#define			RCC_APB2			4

/* Peripherals located on AHB1 bus. */
#define			RCC_GPIOA			0
#define			RCC_GPIOB			1
#define			RCC_GPIOC			2
#define			RCC_GPIOD			3
#define			RCC_GPIOE			4
#define			RCC_GPIOF			5
#define			RCC_GPIOG			6
#define			RCC_GPIOH			7

#define			RCC_CRC				12

#define			BKPSRAMEN			18
#define			RCC_DMA1			21
#define			RCC_DMA2			22

#define			RCC_OTGHS			29
#define			RCC_OTGHSULPI		30

/* Peripherals located on AHB2 bus. */
#define			RCC_DCMI			0
#define			RCC_CRYP			4
#define			RCC_HASH			5
#define			RCC_RNG				6
#define			RCC_OTGFS			7

/* Peripherals located on AHB3 bus. */
#define			RCC_FMC				0
#define			RCC_QSPI			1


/* Peripherals located on APB1 bus. */
#define			RCC_TIM2			0
#define			RCC_TIM3			1
#define			RCC_TIM4			2
#define			RCC_TIM5			3
#define			RCC_TIM6			4
#define			RCC_TIM7			5
#define			RCC_TIM12			6
#define			RCC_TIM13			7
#define			RCC_TIM14			8

#define			RCC_WWDG			11

#define			RCC_SPI2			14
#define			RCC_SPI3			15


#define			RCC_SPDIFRX			16
#define			RCC_USART2			17
#define			RCC_USART3			18
#define			RCC_UART4			19
#define			RCC_UART5			20
#define			RCC_I2C1			21
#define			RCC_I2C2			22
#define			RCC_I2C3			23
#define			RCC_FMPI2C1			24
#define			RCC_CAN1			25
#define			RCC_CAN2			26
#define			RCC_CEC				27
#define			RCC_PWR				28
#define			RCC_DAC				29
/* Peripherals located on APB2 bus. */
#define			RCC_TIM1			0
#define			RCC_TIM8			1

#define			RCC_USART1			4
#define			RCC_USART6			5

#define			RCC_ADC1			8
#define			RCC_ADC2			9
#define			RCC_ADC3			10
#define			RCC_SDIO			11
#define			RCC_SPI1			12
#define			RCC_SPI4			13
#define			RCC_SYSCFG			14

#define			RCC_TIM9			16
#define			RCC_TIM10			17
#define			RCC_TIM11			18

#define			RCC_SAI1			22
#define			RCC_SAI2			23
/*
==================================================
  End Section --> RCC Bus & Peripherals on bus Id definitions
==================================================
*/
/*
==================================================
  Start Section --> APIs
==================================================
*/
/* @brief  --> This function adjust the clock of system
 * based on your configuration in "Driver_ClockConfig.h" file.
 * It is recommended to be called before main in startup code.
 * @param  --> None
 * @retval --> None
 * */
void RCC_InitClock_v(void);
/* @brief  --> This function Enable the clock of any peripheral in system
 * @param  Arg_PeripheralBus_u8 --> It takes the bus id of the peripheral
 * e.g RCC_AHB1, RCC_AHB2
 * @retval Arg_Peripheral_u8 --> It takes the bus id of the peripheral in other words
 * the position of peripheral bit in the register which adjusts the bus.
 * */
void RCC_EnableClock_v(const u8 Arg_PeripheralBus_Cu8,const u8 Arg_Peripheral_Cu8);

/* @brief  --> This function Disable the clock of any peripheral in system
 * @param  Arg_PeripheralBus_u8 --> It takes the bus id of the peripheral
 * e.g RCC_AHB1, RCC_AHB2
 * @retval Arg_Peripheral_u8 --> It takes the bus id of the peripheral in other words
 * the position of peripheral bit in the register which adjusts the bus.
 * */
void RCC_DisableClock_v(const u8 Arg_PeripheralBus_Cu8,const u8 Arg_Peripheral_Cu8);

/* @brief  --> This function calculate the value of
 * System Clock In MHz
 * @param  --> None
 * @retval CLOCK_SYSCLK_MHz --> System Clock In MHz
 * */
f32 RCC_GetSystemClockFrequency_f32(void);

/* @brief  --> This function calculate the value of
 * HClock In MHz
 * @param  --> None
 * @retval --> HClock In MHz
 * */
f32 RCC_GetHCLKFrequency_f32(void);

/* @brief  --> This function calculate the value of
 * Input clock to systick timer in MHz.
 * @param  --> None
 * @retval --> Input clock to systick timer in MHz.
 * */
f32 RCC_GetCortexSystemTimerFrequency_f32(void);

/* @brief  --> This function calculate the value of
 * FCLK in MHz.
 * @param  --> None
 * @retval --> FCLK in MHz.
 * */
f32 RCC_GetFCLKFrequency_f32(void);
/* @brief  --> This function calculate APB1 bus frequency in MHz of any peripheral connected to this bus except Timers
 * @param  --> None
 * @retval --> APB1 bus frequency in MHz of any peripheral connected to this bus except Timers.
 * */
f32 RCC_GetAPB1PeripheralClockFrequency_f32(void);

/* @brief  --> This function returns the bus which peripheral is connected to it.
 * for example if you want to know the peripheral GPIOB connected to which bus call the following function
 * RCC_GetPeripheralBus_u8((u32)GPIOB);
 * It will calculate the bus corresponding to peripheral through it's address.
 * @param  Arg_PeripheralAddress_u32 --> Address of peripheral
 * @retval --> Bus of selected peripheral.
 * */
u8 RCC_GetPeripheralBus_u8(const u32 Arg_PeripheralAddress_Cu32);
/* @brief  --> This function returns the frequency of bus which peripheral is connected to it.
 * for example if you want to know the frequency of the bus which SPI1 peripheral connected to it just call the following function
 * RCC_GetPeripheralBus_u8((u32)SPI1);
 * It will calculate the bus frequency of peripheral through it's address.
 *
 * @Note --> This function doesn't calculate the frequency of timer.
 * To calculate the frequency of input clock timer use the following function.
 * RCC_GetTimerPeripheralFrequencyInMHz_f32((u32) TIM1);
 *
 * @param  Arg_PeripheralAddress_u32 --> Address of peripheral
 * @retval --> Frequency of peripheral's bus In Mega-hertez.
 * */
f32 RCC_GetPeripheralFrequencyInMHz_f32(const u32 Arg_PeripheralAddress_Cu32);

/* @brief  --> This function returns the frequency of bus which peripheral is connected to it.
 * for example if you want to know the frequency of the bus which SPI1 peripheral connected to it just call the following function
 * RCC_GetPeripheralBus_u8((u32)SPI1);
 * It will calculate the bus frequency of peripheral through it's address.
 *
 * @Note --> This function doesn't calculate the frequency of timer.
 * To calculate the frequency of input clock timer use the following function.
 * RCC_GetTimerPeripheralFrequencyInMHz_f32((u32) TIM1);
 *
 * @param  Arg_PeripheralAddress_Cu32 --> Address of peripheral
 * @retval --> Frequency of peripheral's bus In Mega-hertez.
 * */
f32 RCC_GetTimerPeripheralFrequencyInMHz_f32(const u32 Arg_PeripheralAddress_Cu32);

/* @brief  --> This function calculate APB1 bus frequency in MHz of any timer peripheral connected to this bus.
 * @param  --> None
 * @retval --> Input clock frequency of any timer connected to APB1 Bus.
 * */
f32 RCC_GetAPB1TimerClockFrequency_f32(void);
/* @brief  --> This function calculate APB2 bus frequency in MHz of any peripheral connected to this bus except Timers
 * @param  --> None
 * @retval --> APB1 bus frequency in MHz of any peripheral connected to this bus except Timers.
 * */
f32 RCC_GetAPB2PeripheralClockFrequency_f32(void);

/* @brief  --> This function calculate APB2 bus frequency in MHz of any timer peripheral connected to this bus.
 * @param  --> None
 * @retval --> Input clock frequency of any timer connected to APB1 Bus.
 * */
f32 RCC_GetAPB2TimerClockFrequency_f32(void);

/* @brief  --> This function return the position on bit of timer peripheral on it's corresponding bus register.
 * usually used with RCC_EnableClock_v to enable clock for peripheral.
 * for e.g
 * 	RCC_EnableClock_v(
 * 	RCC_GetPeripheralBus_u8((u32)TIM_PERIPHERALID(1)),
 * 	RCC_GetRCCTimerBit_u8(1));
 * @param  Arg_TimerInstanceId_u8 --> Instance ID of timer.
 * @retval --> bit position in bus register.
 * */
u8 RCC_GetRCCTimerBit_u8(const u8 Arg_TimerInstanceId_Cu8);
/* @brief  --> This function return the position on bit of GPIO peripheral on it's corresponding bus register.
 * usually used with RCC_EnableClock_v to enable clock for peripheral.
 * for e.g
 * 	RCC_EnableClock_v(
 * 	RCC_GetPeripheralBus_u8((u32)GPIO_PERIPHERALID(1)),
 * 	RCC_GetRCCGPIOBit_u8(1));
 * @param  Arg_GPIOInstanceId_u8 --> Instance ID of GPIO.
 * @retval --> bit position in bus register.
 * */
u8 RCC_GetRCCGPIOBit_u8(const u8 Arg_GPIOInstanceId_Cu8);
/* @brief  --> This function return the position on bit of USART peripheral on it's corresponding bus register.
 * usually used with RCC_EnableClock_v to enable clock for peripheral.
 * for e.g
 * 	RCC_EnableClock_v(
 * 	RCC_GetPeripheralBus_u8((u32)USART_PERIPHERALID(1)),
 * 	RCC_GetRCCUSARTBit_u8(1));
 * @param  Arg_USARTInstanceId_u8 --> Instance ID of USART.
 * @retval --> bit position in bus register.
 * */
u8 RCC_GetRCCUSARTBit_u8(const u8 Arg_USARTInstanceId_Cu8);
/* @brief  --> This function return the position on bit of CAN peripheral on it's corresponding bus register.
 * usually used with RCC_EnableClock_v to enable clock for peripheral.
 * for e.g
 * 	RCC_EnableClock_v(
 * 	RCC_GetPeripheralBus_u8((u32)CAN_PERIPHERALID(1)),
 * 	RCC_GetRCCCANBit_u8(1));
 * @param  Arg_CANInstanceId_u8 --> Instance ID of CAN.
 * @retval --> bit position in bus register.
 * */
u8 RCC_GetRCCCANBit_u8(const u8 Arg_CANInstanceId_Cu8);

/* @brief  --> This function return the position on bit of I2C peripheral on it's corresponding bus register.
 * usually used with RCC_EnableClock_v to enable clock for peripheral.
 * for e.g
 * 	RCC_EnableClock_v(
 * 	RCC_GetPeripheralBus_u8((u32)I2C_PERIPHERALID(1)),
 * 	RCC_GetRCCI2CBit_u8(1));
 * @param  Arg_I2CInstanceId_u8 --> Instance ID of I2C.
 * @retval --> bit position in bus register.
 * */
u8 RCC_GetRCCI2CBit_u8(const u8 Arg_I2CInstanceId_Cu8);
/* @brief  --> This function return the position on bit of DAC peripheral on it's corresponding bus register.
 * usually used with RCC_EnableClock_v to enable clock for peripheral.
 * for e.g
 * 	RCC_EnableClock_v(
 * 	RCC_GetPeripheralBus_u8((u32)DAC_PERIPHERALID(1)),
 * 	RCC_GetRCCGPIOBit_u8(1));
 * @param  Arg_DACInstanceId_u8 --> Instance ID of DAC.
 * @retval --> bit position in bus register.
 * */
u8 RCC_GetRCCDACBit_u8(const u8 Arg_DACInstanceId_Cu8);
/* @brief  --> This function return the position on bit of DMA peripheral on it's corresponding bus register.
 * usually used with RCC_EnableClock_v to enable clock for peripheral.
 * for e.g
 * 	RCC_EnableClock_v(
 * 	RCC_GetPeripheralBus_u8((u32)DMA_PERIPHERALID(1)),
 * 	RCC_GetRCCDMABit_u8(1));
 * @param  Arg_DMAInstanceId_u8 --> Instance ID of DMA.
 * @retval --> bit position in bus register.
 * */
u8 RCC_GetRCCDMABit_u8(const u8 Arg_DMAInstanceId_Cu8);
/* @brief  --> This function return the position on bit of ADC peripheral on it's corresponding bus register.
 * usually used with RCC_EnableClock_v to enable clock for peripheral.
 * for e.g
 * 	RCC_EnableClock_v(
 * 	RCC_GetPeripheralBus_u8((u32)ADC_PERIPHERALID(1)),
 * 	RCC_GetRCCADCBit_u8(1));
 * @param  Arg_ADCInstanceId_u8 --> Instance ID of ADC.
 * @retval --> bit position in bus register.
 * */
u8 RCC_GetRCCADCBit_u8(const u8 Arg_ADCInstanceId_Cu8);

/* @brief  --> This function return the position on bit of SYSCFG peripheral on it's corresponding bus register.
 * usually used with RCC_EnableClock_v to enable clock for peripheral.
 * for e.g
 * 	RCC_EnableClock_v(
 * 	RCC_GetPeripheralBus_u8((u32)SYSCFG_PERIPHERALID(1)),
 * 	RCC_GetRCCSYSCFGBit_u8(1));
 * @param  Arg_SYSCFGInstanceId_u8 --> Instance ID of SYSCFG.
 * @retval --> bit position in bus register.
 * */
u8 RCC_GetRCCSYSCFGBit_u8(const u8 Arg_SYSCFGInstanceId_Cu8);

/* @brief  --> This function return the position on bit of SPI peripheral on it's corresponding bus register.
 * usually used with RCC_EnableClock_v to enable clock for peripheral.
 * for e.g
 * 	RCC_EnableClock_v(
 * 	RCC_GetPeripheralBus_u8((u32)SPI_PERIPHERALID(1)),
 * 	RCC_GetRCCSPIBit_u8(1));
 * @param  Arg_SPIInstanceId_u8 --> Instance ID of SPI.
 * @retval --> bit position in bus register.
 * */
u8 RCC_GetRCCSPIBit_u8(const u8 Arg_SPIInstanceId_u8);
/*
==================================================
  End   Section --> APIs
==================================================
*/
#endif /* HMCAL_RCC_RCC_H_ */
