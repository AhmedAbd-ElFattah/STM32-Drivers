# Buzzer module


## Table of Contents
- [API Reference](#api-reference)
- [Examples](#examples)


## API Reference

- **void Buzzer_Config_v(Buzzer_Cfg const * const Arg_Config_cpcLBuzzer)**

	**Explanation** 

	This function configures Button based on configuration passed through Buzzer_Cfg struct.
	
	**Parameters**
	
	Arg_Config_cpcLBuzzer    : struct that have configured parameters.

	**Return value** 

	None

- **void Buzzer_ChangeFrequencyAndPWM_v(Buzzer_Cfg const * const Arg_Config_cpcLBuzzer)**

	**Explanation** 

	This function updates configuration of Buzzer based on configuration passed through Buzzer_Cfg struct.
	
	**Parameters**
	
	Arg_Config_cpcLBuzzer    : struct that have new-configured parameters.

	**Return value** 

	None


## Examples
## Buzzer Example

```c
#include "HAL/Buzzer/Buzzer.h"
int main(void)
{
	Buzzer_Cfg L_BuzzerExample_Buzzer_Cfg = {0};
	L_BuzzerExample_Buzzer_Cfg.AutoReloadValue = 999;
	L_BuzzerExample_Buzzer_Cfg.Channel = 1;
	L_BuzzerExample_Buzzer_Cfg.GPIOInstanceId = 'A';
	L_BuzzerExample_Buzzer_Cfg.PINId = 2;
	L_BuzzerExample_Buzzer_Cfg.PWM = 40;
	L_BuzzerExample_Buzzer_Cfg.Prescaler = 15;
	L_BuzzerExample_Buzzer_Cfg.TimerInstanceId=9;
	/*Configure & start*/
	Buzzer_Config_v(&L_BuzzerExample_Buzzer_Cfg);
	while(1){

	}
}

```