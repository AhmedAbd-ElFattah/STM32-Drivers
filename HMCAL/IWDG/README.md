# Universal Synchronous and Asynchronous Receiver-Transmitter (USART) module
IWDG (Independent Watchdog) is a hardware feature available in STM32 microcontrollers that provides a mechanism for monitoring the system's operation and recovering from software failures or lock-ups. It acts as a safety net to prevent the microcontroller from getting stuck in an unexpected state.

## Table of Contents
- [API Reference](#api-reference)

## API Reference

- **IWDG_Config_v(const u8 Arg_Prescaler_Cu8, const u16 Arg_ReloadValue_Cu16)**

	**Explanation** 

	This function configures IWDG.
	
	**Parameters**
	
	Arg_Prescaler_Cu8    : IWDG prescaler. 

    Arg_ReloadValue_Cu16 : IWDG Auto reload value.

	**Return value** 

	None