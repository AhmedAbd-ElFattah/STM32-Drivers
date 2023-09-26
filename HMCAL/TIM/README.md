# Timer (TIM) module
The Timer module in STM32 microcontrollers is a versatile peripheral that provides precise timing and time measurement capabilities. It is commonly used for tasks such as generating accurate delays, generating PWM signals for controlling motors or other devices, measuring time intervals, and triggering events at specific time intervals.

Here are some key features and functionalities of the Timer module in STM32:

Multiple Timers: STM32 microcontrollers typically include multiple timer units, each consisting of one or more timer channels. The number and type of timers vary depending on the specific STM32 microcontroller series and model.

Timer Modes: The Timer module supports different modes of operation, including:

Basic Timer Mode: A simple timer that counts up or down based on a clock source.
General-Purpose Timer Mode: Provides advanced features like input capture, output compare, and PWM generation.
Advanced-Control Timer Mode: Offers additional functionalities like motor control capabilities (e.g., complementary PWM outputs).
Clock Sources: The Timer module can be clocked by various sources, such as the system clock (HCLK), an external clock, or an internal clock (e.g., an internal oscillator or PLL). The clock source selection depends on the specific STM32 microcontroller and its available options.

Prescaler and Auto-Reload Register: The Timer module typically includes a prescaler and an auto-reload register. The prescaler divides the input clock frequency, allowing finer control over the timer resolution. The auto-reload register determines the value at which the timer will reset or generate an interrupt.

Interrupts and DMA: Timers can generate interrupts at specific events, such as reaching the overflow or matching a particular value. This allows for timely responses and event-driven programming. Additionally, Direct Memory Access (DMA) can be used to transfer data to or from the timer's registers without CPU intervention.

Input Capture: Timer channels can be configured for input capture mode, which allows the module to measure the duration or frequency of external events. This feature is commonly used in applications like frequency measurement, pulse-width measurement, or input signal synchronization.

Output Compare and PWM Generation: Timer channels can be configured for output compare mode, enabling the generation of digital waveforms with precise timing characteristics. This feature is commonly used for generating Pulse Width Modulation (PWM) signals for controlling devices like motors, LEDs, or audio signals.

Timers Synchronization: Some STM32 microcontrollers provide synchronization mechanisms between multiple timer units, allowing for precise coordination and timing between different timers.

To work with the Timer module in STM32 microcontrollers, you typically need to configure the timer's registers, set the desired mode of operation, select the clock source and prescaler values, and enable interrupts or DMA as needed. Then, you can interact with the timer by reading or writing its registers, monitoring events or flags, and handling interrupts.


## Table of Contents
- [API Reference](#api-reference)

## TIM Configurations
### Preload
|Preload mode				 |Corresponding option		|
|----------------------------|--------------------------|
| Not Buffered preload value | TIM_PRELOAD_NOT_BUFFERED |
| Buffered preload value     | TIM_PRELOAD_BUFFERED     |

### One pulse mode
|One pulse mode			 |Corresponding option	 |
|------------------------|-----------------------|
| One pulse mode Disable | TIM_ONE_PULSE_DISABLE |
| One pulse mode Enable  | TIM_ONE_PULSE_ENABLE  |

### Master mode
|Master mode|Corresponding option	 |
|-----------|------------------------|
| Disable   | TIM_MASTER_MODE_DISABLE|
| Reset     | TIM_MASTER_MODE_RESET  |
| Enable    | TIM_MASTER_MODE_ENABLE |
| Update    | TIM_MASTER_MODE_UPDATE |

### Interrupt
|Interrupt on			  |Corresponding option	  |
|-------------------------|-----------------------|
| Disable                 | TIM_INTERRUPT_DISABLE |
| Update interrupt enable | TIM_INTERRUPT_UPDATE  |



## API Reference

- **void TIM_Config_v(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg)**

	**Explanation** 

	This function configures TIM based on configuration passed through TIM_Cfg struct.
	
	**Parameters**
	
	Arg_conf_cpcTIM_Cfg    : struct that have configured parameters
	
	**Return value** 

	None

- **void TIM_SetAutoReloadValue_v(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg, u16 Arg_Value_u16)**

	**Explanation** 

	Assign new auto reload value to timer.
	
	**Parameters**
	
	Arg_conf_cpcTIM_Cfg    : struct that have configured parameters

	Arg_Value_u16	       : Value of new Auto reload value that you need to assign with timer

	**Return value** 

	None

- **u16 TIM_GetAutoReloadValue_u16(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg)**

	**Explanation** 

	Get assigned auto reload value of timer
	
	**Parameters**
	
	Arg_conf_cpcTIM_Cfg    : struct that have configured parameters.

	**Return value** 

	Value of auto reload value of timer.

- **void TIM_SetPrescalerValue_v(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg, u16 Arg_Value_u16)**

	**Explanation** 

	Assign new prescaler value to timer.
	
	**Parameters**
	
	Arg_conf_cpcTIM_Cfg    : struct that have configured parameters

	Arg_Value_u16	       : Value of new prescaler value that you need to assign with timer

	**Return value** 

	None

- **u16 TIM_GetPrescalerValue_u16(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg)**

	**Explanation** 

	Get assigned prescaler value of timer
	
	**Parameters**
	
	Arg_conf_cpcTIM_Cfg    : struct that have configured parameters


	**Return value** 

	Value of prescaler value of timer.

- **void TIM_SetCounterValue_v(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg, u16 Arg_Value_u16)**

	**Explanation** 

	Assign new counter value to timer
	
	**Parameters**
	
	Arg_conf_cpcTIM_Cfg    : struct that have configured parameters

	Arg_Value_u16		   : Value of new counter value that you need to assign with timer

	**Return value** 

	None

- **u16 TIM_GetCounterValue_u16(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg)**

	**Explanation** 

	Get assigned current counter value of timer.
	
	**Parameters**
	
	Arg_conf_cpcTIM_Cfg    : struct that have configured parameters
	
	**Return value** 

	Value of counter value of timer


- **void TIM_ResetCounter_v(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg)**

	**Explanation** 

	Reset counter value of timer.
	
	**Parameters**
	
	Arg_conf_cpcTIM_Cfg    : struct that have configured parameters
	
	**Return value** 

	None

- **void TIM_StartTimer_v(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg)**

	**Explanation** 

	Start timer.
	
	**Parameters**
	
	Arg_conf_cpcTIM_Cfg    : struct that have configured parameters
	
	**Return value** 

	None

- **void TIM_StopTimer_v(TIM_Cfg const * const Arg_conf_cpcTIM_Cfg)**

	**Explanation** 

	Stop timer.
	
	**Parameters**
	
	Arg_conf_cpcTIM_Cfg    : struct that have configured parameters
	
	**Return value** 

	None

## Examples
## Output PWM signal on A2 & A3.
```c

#include "HMCAL/TIM/TIM.h"

int main(void)
{
	TIM_Cfg L_PWMEx_TIM_Cfg = {0};
	/*Configure selected timer. --> Timer 9*/
	L_PWMEx_TIM_Cfg.InstanceId = 9;
	/*Enable Channel 1 & Channel 2 as output.*/
	L_PWMEx_TIM_Cfg.ActiveChannels  = TIM_ACTIVE_CHANNELS_CH1_OUT | TIM_ACTIVE_CHANNELS_CH2_OUT;
	/*Assign auto reload value.*/
	L_PWMEx_TIM_Cfg.AutoReloadValue = 1000-1;
	/*Assign prescaler.*/
	L_PWMEx_TIM_Cfg.Prescaler = 16-1;
	/*Assign GPIOA pins --> A2 & A3*/
	L_PWMEx_TIM_Cfg.GPIOInstanceId = 'A';
	L_PWMEx_TIM_Cfg.GPIOPins = PIN_2_MASK | PIN_3_MASK;

	/*Configure Timer channel 1 & 2 in PWM mode*/
	L_PWMEx_TIM_Cfg.Channel1Mode = TIM_CHANNEL_MODE_OUTPUT_PWM_ACTIVE_HIGH;
	L_PWMEx_TIM_Cfg.Channel2Mode = TIM_CHANNEL_MODE_OUTPUT_PWM_ACTIVE_HIGH;

	/* Assign output compare value in this example to output pwm signal
	 * For channel 1 --> Duty cycle 20%
	 * For channel 2 --> Duty cycle 80%
	 * */
	L_PWMEx_TIM_Cfg.Channel1CaptureCompare = L_PWMEx_TIM_Cfg.AutoReloadValue*.2;
	L_PWMEx_TIM_Cfg.Channel2CaptureCompare = L_PWMEx_TIM_Cfg.AutoReloadValue*.8;

	/*Apply timer configurations.*/
	TIM_Config_v(&L_PWMEx_TIM_Cfg);
	
	TIM_StartTimer_v(&L_PWMEx_TIM_Cfg);

	while(1){

	}
}


```
