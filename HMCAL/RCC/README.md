# Reset and Clock Control (RCC) module

In STM32 microcontrollers, the RCC (Reset and Clock Control) peripheral is responsible for managing the system reset and clock configuration. It provides control and configuration options for the various clocks used by the microcontroller.

The RCC peripheral allows you to:

1. Enable or disable the clock for specific peripherals or system components.
2. Configure the clock source and prescaler for different system clocks.
3. Monitor the status of clocks and reset events through status flags.


## Table of Contents
- [API Reference](#api-reference)
- [Examples](#examples)

## API Reference
- **void RCC_InitClock_v(void)** 

	**Explanation** 

	This function adjust the clock of system based on your configuration in "Driver_ClockConfig.h" file. 
	It is recommended to be called before main in startup code.
	
	**Parameters** 
	
	None
	
	**Return value** 
	

	None

- **void RCC_EnableClock_v(const u8 Arg_PeripheralBus_Cu8,const u8 Arg_Peripheral_Cu8)**

	**Explanation** 

	This function Enable the clock of any peripheral in system
	
	**Parameters**
	
	Arg_PeripheralBus_u8 : It takes the bus id of the peripheral e.g RCC_AHB1, RCC_AHB2

	**Return value** 

	Arg_Peripheral_u8 : It takes the bus id of the peripheral in other words 
	the position of peripheral bit in the register which adjusts the bus.

- **void RCC_DisableClock_v(const u8 Arg_PeripheralBus_Cu8,const u8 Arg_Peripheral_Cu8)**

	**Explanation** 

	This function Disable the clock of any peripheral in system

	**Parameters**

	Arg_PeripheralBus_u8 : It takes the bus id of the peripheral e.g RCC_AHB1, RCC_AHB2

	**Return value** 

	Arg_Peripheral_u8 : It takes the bus id of the peripheral in other words the position of peripheral bit 
	in the register which adjusts the bus.

- **f32 RCC_GetSystemClockFrequency_f32(void)**

	**Explanation** 

	This function calculate the value of System Clock In MHz

	**Parameters**
	
	None

	**Return value** 

	CLOCK_SYSCLK_MHz : System Clock In MHz

- **f32 RCC_GetHCLKFrequency_f32(void)**

	**Explanation** 

	This function calculate the value of HClock In MHz
	
	**Parameters**

	None

	**Return value** 

	HClock In MHz

- **f32 RCC_GetCortexSystemTimerFrequency_f32(void)**

	**Explanation** 

	This function calculate the value of Input clock to systick timer in MHz.
	
	**Parameters**

	None

	**Return value** 

	Input clock to systick timer in MHz.

- **f32 RCC_GetFCLKFrequency_f32(void)**

	**Explanation** 

	This function calculate the value of FCLK in MHz.
	
	**Parameters**

	None

	**Return value** 

	FCLK in MHz.

- **f32 RCC_GetAPB1PeripheralClockFrequency_f32(void)**

	**Explanation** 

	This function calculate APB1 bus frequency in MHz of any peripheral connected to this bus except Timers

	**Parameters**

	None

	**Return value** 

	APB1 bus frequency in MHz of any peripheral connected to this bus except Timers.

- **u8 RCC_GetPeripheralBus_u8(const u32 Arg_PeripheralAddress_Cu32)**

	**Explanation** 

	This function returns the bus which peripheral is connected to it. for example if you want to know the peripheral GPIOB connected to which bus call the following function RCC_GetPeripheralBus_u8((u32)GPIOB); It will calculate the bus corresponding to peripheral through it's address.

	**Parameters**
	
	Arg_PeripheralAddress_u32 : Address of peripheral

	**Return value** 

	Bus of selected peripheral.

- **f32 RCC_GetPeripheralFrequencyInMHz_f32(const u32 Arg_PeripheralAddress_Cu32)**

	**Explanation** 

	This function returns the frequency of bus which peripheral is connected to it. 
	for example if you want to know the frequency of the bus which SPI1 peripheral 
	connected to it just call the following function RCC_GetPeripheralBus_u8((u32)SPI1); 
	It will calculate the bus frequency of peripheral through it's address. Note: This function doesn't calculate 
	the frequency of timer. 
	To calculate the frequency of input clock timer use the following function. 
	RCC_GetTimerPeripheralFrequencyInMHz_f32((u32) TIM1); 

	**Parameters**

	Arg_PeripheralAddress_u32 : Address of peripheral

	**Return value** 

	Frequency of peripheral's bus In Mega-hertez.

- **f32 RCC_GetTimerPeripheralFrequencyInMHz_f32(const u32 Arg_PeripheralAddress_Cu32)**

	**Explanation** 

	This function returns the frequency of bus which peripheral is connected to it. 
	for example if you want to know the frequency of the bus which SPI1 peripheral connected to it 
	just call the following function RCC_GetPeripheralBus_u8((u32)SPI1); 
	It will calculate the bus frequency of peripheral through it's address. 
	Note: This function doesn't calculate the frequency of timer. 
	To calculate the frequency of input clock timer use the following function. 
	RCC_GetTimerPeripheralFrequencyInMHz_f32((u32) TIM1); 

	**Parameters** 

	Arg_PeripheralAddress_Cu32 : Address of peripheral

	**Return value** 

	Frequency of peripheral's bus In Mega-hertez.

- **f32 RCC_GetAPB1TimerClockFrequency_f32(void)**

	**Explanation** 

	This function calculate APB1 bus frequency in MHz of any timer peripheral connected to this bus.

	**Parameters** 

	None

	**Return value** 

	Input clock frequency of any timer connected to APB1 Bus.

- **f32 RCC_GetAPB2PeripheralClockFrequency_f32(void)**

	**Explanation** 

	This function calculate APB2 bus frequency in MHz of any peripheral connected to this bus except Timers

	**Parameters** 

	None

	**Return value** 

	APB1 bus frequency in MHz of any peripheral connected to this bus except Timers.

- **f32 RCC_GetAPB2TimerClockFrequency_f32(void)**

	**Explanation** 

	This function calculate APB2 bus frequency in MHz of any timer peripheral connected to this bus.

	**Parameters** 
	
	None

	**Return value** 

	Input clock frequency of any timer connected to APB1 Bus.

- **u8 RCC_GetRCCTimerBit_u8(const u8 Arg_TimerInstanceId_Cu8)**
	
	**Explanation** 

	This function return the position on bit of timer peripheral on it's corresponding bus register.
	usually used with RCC_EnableClock_v to enable clock for peripheral.
	for e.g
	RCC_EnableClock_v(
	RCC_GetPeripheralBus_u8((u32)TIM_PERIPHERALID(1)),
	RCC_GetRCCTimerBit_u8(1));

	**Parameters** 
	Arg_TimerInstanceId_u8 : Instance ID of timer.

	**Return value** 

	bit position in bus register.

- **u8 RCC_GetRCCGPIOBit_u8(const u8 Arg_GPIOInstanceId_Cu8)**

	**Explanation** 

	This function return the position on bit of GPIO peripheral on it's corresponding bus register.
	usually used with RCC_EnableClock_v to enable clock for peripheral.
	for e.g
	RCC_EnableClock_v(
	RCC_GetPeripheralBus_u8((u32)GPIO_PERIPHERALID(1)),
	RCC_GetRCCGPIOBit_u8(1));

	**Parameters** 

	Arg_GPIOInstanceId_u8 : Instance ID of GPIO.

	**Return value** 

	bit position in bus register.

- **u8 RCC_GetRCCUSARTBit_u8(const u8 Arg_USARTInstanceId_Cu8)**

	**Explanation** 

	This function return the position on bit of USART peripheral on it's corresponding bus register.
	usually used with RCC_EnableClock_v to enable clock for peripheral.
	for e.g
	RCC_EnableClock_v(
	RCC_GetPeripheralBus_u8((u32)USART_PERIPHERALID(1)),
	RCC_GetRCCUSARTBit_u8(1));

	**Parameters** 

	Arg_USARTInstanceId_u8 : Instance ID of USART.

	**Return value** 

	bit position in bus register.

- **u8 RCC_GetRCCCANBit_u8(const u8 Arg_CANInstanceId_Cu8)**

	**Explanation** 

	This function return the position on bit of CAN peripheral on it's corresponding bus register.
	usually used with RCC_EnableClock_v to enable clock for peripheral.
	for e.g
	RCC_EnableClock_v(
	RCC_GetPeripheralBus_u8((u32)CAN_PERIPHERALID(1)),
	RCC_GetRCCCANBit_u8(1));

	**Parameters** 

	Arg_CANInstanceId_u8 : Instance ID of CAN.

	**Return value** 

	bit position in bus register.

- **u8 RCC_GetRCCI2CBit_u8(const u8 Arg_I2CInstanceId_Cu8)**

	**Explanation** 

	This function return the position on bit of I2C peripheral on it's corresponding bus register.
	usually used with RCC_EnableClock_v to enable clock for peripheral.
	for e.g
	RCC_EnableClock_v(
	RCC_GetPeripheralBus_u8((u32)I2C_PERIPHERALID(1)),
	RCC_GetRCCI2CBit_u8(1));

	**Parameters** 
	
	Arg_I2CInstanceId_u8 : Instance ID of I2C.

	**Return value** 

	bit position in bus register.

- **u8 RCC_GetRCCDACBit_u8(const u8 Arg_DACInstanceId_Cu8)**

	**Explanation** 

	This function return the position on bit of DAC peripheral on it's corresponding bus register.
	usually used with RCC_EnableClock_v to enable clock for peripheral.
	for e.g
	RCC_EnableClock_v(
	RCC_GetPeripheralBus_u8((u32)DAC_PERIPHERALID(1)),
	RCC_GetRCCGPIOBit_u8(1));
	
	**Parameters** 

	  Arg_DACInstanceId_u8 : Instance ID of DAC.
	  
	**Return value** 

	bit position in bus register.

- **u8 RCC_GetRCCDMABit_u8(const u8 Arg_DMAInstanceId_Cu8)**

	**Explanation** 

	This function return the position on bit of DMA peripheral on it's corresponding bus register.
	usually used with RCC_EnableClock_v to enable clock for peripheral.
	for e.g
	RCC_EnableClock_v(
	RCC_GetPeripheralBus_u8((u32)DMA_PERIPHERALID(1)),
	RCC_GetRCCDMABit_u8(1));
	
	**Parameters** 

	  Arg_DMAInstanceId_u8 : Instance ID of DMA.
	  
	**Return value** 

	bit position in bus register.

- **u8 RCC_GetRCCADCBit_u8(const u8 Arg_ADCInstanceId_Cu8)**

	**Explanation** 

	This function return the position on bit of ADC peripheral on it's corresponding bus register.
	usually used with RCC_EnableClock_v to enable clock for peripheral.
	for e.g
	RCC_EnableClock_v(
	RCC_GetPeripheralBus_u8((u32)ADC_PERIPHERALID(1)),
	RCC_GetRCCADCBit_u8(1));
	
	**Parameters** 

	  Arg_ADCInstanceId_u8 : Instance ID of ADC.
	  
	**Return value** 

	bit position in bus register.

- **u8 RCC_GetRCCSYSCFGBit_u8(const u8 Arg_SYSCFGInstanceId_Cu8)**

	**Explanation** 

	This function return the position on bit of SYSCFG peripheral on it's corresponding bus register.
	usually used with RCC_EnableClock_v to enable clock for peripheral.
	for e.g
	RCC_EnableClock_v(
	RCC_GetPeripheralBus_u8((u32)SYSCFG_PERIPHERALID(1)),
	RCC_GetRCCSYSCFGBit_u8(1));
	
	**Parameters** 

	  Arg_SYSCFGInstanceId_u8 : Instance ID of SYSCFG.
	  
	**Return value** 

	bit position in bus register.

- **u8 RCC_GetRCCSPIBit_u8(const u8 Arg_SPIInstanceId_u8)**

	**Explanation** 

	This function return the position on bit of SPI peripheral on it's corresponding bus register.
	usually used with RCC_EnableClock_v to enable clock for peripheral.
	for e.g
	RCC_EnableClock_v(
	RCC_GetPeripheralBus_u8((u32)SPI_PERIPHERALID(1)),
	RCC_GetRCCSPIBit_u8(1));
	
	**Parameters** 

	  Arg_SPIInstanceId_u8 : Instance ID of SPI.
	  
	**Return value** 

	bit position in bus register.

## Examples
### Initialize System Clock
```c
#include "HMCAL/RCC/RCC.h"
int main(void)
{
	/*Init system clock.*/
	RCC_InitClock_v();
	while(1){
	}
}
```

### Enable GPIOA Clock
```c
#include "HMCAL/RCC/RCC.h"
int main(void)
{
	/*Enable GPIOA clock*/
	RCC_EnableClock_v(RCC_AHB1, RCC_GPIOA);

	while(1){
	}
}
```