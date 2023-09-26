# External Interrupt (EXTI) module
The STM32 EXTI (External Interrupt) peripheral is a feature found in microcontrollers of the STM32 family. EXTI allows the microcontroller to respond to external events or signals by generating interrupts. This feature is particularly useful for real-time applications where immediate response to external events is required

## Table of Contents
- [EXTI Configurations](#exti-configurations)
- [API Reference](#api-reference)
- [Examples](#examples)

## EXTI Configurations
### Edge
| Edge detection							|Corresponding option 			   |
|-------------------------------------------|----------------------------------|
| Disable Edge detection                    | EXTI_EDGE_NO_EDGE_DETECTION      |
| Enable Rising edge detection              | EXTI_EDGE_RISING_EDGE_DETECTION  |
| Enable Falling edge detection             | EXTI_EDGE_FALLING_EDGE_DETECTION |
| Enable Rising and Falling edge detection. | EXTI_EDGE_BOTH_EDGES_DETECTION   |

## API Reference

- **void EXTI_Config_v(EXTI_Cfg const * const Arg_conf_cpcEXTI_Cfg)**

	**Explanation** 

	This function configures EXTI based on configuration passed through EXTI_Cfg struct.
	
	**Parameters**
	
	Arg_conf_cpcEXTI_Cfg    : struct that have configured parameters.

	**Return value** 

	None

- **Bool EXTI_CheckInterrupt_Bool(u8 Arg_PinNumber_u8)**

	**Explanation** 

	This function usually used by interrupt handler to check for
    the existence of interrupt for specific pin number.
	
	**Parameters**
	
	Arg_PinNumber_u8    : Arg_PinNumber_u8 --> Pin number that you need to check whether it's source of interrupt or not.

	**Return value** 

	Bool value represents whether there is an interrupt or not.

- **Bool EXTI_ClearInterrupt_v(u8 Arg_PinNumber_u8)**

	**Explanation** 

	This function usually used by interrupt handler to check for
    the existence of interrupt for specific pin number and clear pending flag if it's exist.
	
	**Parameters**
	
	Arg_PinNumber_u8    : Arg_PinNumber_u8 --> Pin number that you need to clear pending flag.

	**Return value** 

	None.

## Examples
## External interrupt using push button connected to C13 pin.

```c
#include "HMCAL/EXTI/EXTI.h"
#include "HMCAL/Interrupt/InterruptHandlers.h"

void A5_Callback(){
	/*You can set breakpoint here to check the trigger of intterupt.*/
	asm volatile ("NOP");
}

int main(void)
{
	EXTI_Cfg L_PushButtonIntterupt_EXTI_Cfg;
	/*Configure for Falling edge detection*/
	L_PushButtonIntterupt_EXTI_Cfg.Edge = EXTI_EDGE_FALLING_EDGE_DETECTION;
	/*Configure GPIOC*/
	L_PushButtonIntterupt_EXTI_Cfg.GPIOInstanceId = 'C';
	/*Configure pin number --> 13*/
	L_PushButtonIntterupt_EXTI_Cfg.PINs = PIN_13_MASK;
	/*Apply configurations.*/
	EXTI_Config_v(&L_PushButtonIntterupt_EXTI_Cfg);

	/*Assign function callback for GPIOC pin number 13*/
	InterruptHandler_SetEXTIxCallback_void('C', 13, A5_Callback);
}
```