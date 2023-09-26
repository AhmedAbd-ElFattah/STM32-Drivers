# LED module


## Table of Contents
- [API Reference](#api-reference)
- [Examples](#examples)


## API Reference

- **void SevenSegment_Config_v(SevenSegment_Cfg * const Arg_Config_pSevenSegment_Cfg)**

	**Explanation** 

	This function configures Seven Segment based on configuration passed through SevenSegment_Cfg struct.
	
	**Parameters**
	
	Arg_Config_pSevenSegment_Cfg    : struct that have configured parameters.

	**Return value** 

	None

- **void SevenSegment_DisplayValue_v(SevenSegment_Cfg * const Arg_Config_pSevenSegment_Cfg, const u8 Arg_DispVal_u8)**

	**Explanation** 

	This function displays number on Seven Segment.
	
	**Parameters**
	
	Arg_Config_pSevenSegment_Cfg    : struct that have configured parameters.

    Arg_DispVal_u8    : Value that will be displayed on sevensegment.

	**Return value** 

	None

- **void SevenSegment_TurnOFFDisplay_v(SevenSegment_Cfg * const Arg_Config_pSevenSegment_Cfg)**

	**Explanation** 

	This function turns off seven segment.
	
	**Parameters**
	
	Arg_Config_pSevenSegment_Cfg    : struct that have configured parameters.

	**Return value** 

	None

## Examples
## Display numbers from 0 to 9

```c
#include "HAL/SevenSegment/SevenSegment.h"
#include "LIB/Delay/Delay.h"

SevenSegment_Cfg G_SSExample_SevenSegment_Cfg;

int main(void)
{
	G_SSExample_SevenSegment_Cfg.GPIOInstanceId = 'A';
	G_SSExample_SevenSegment_Cfg.PIN_A = 8; // A8
	G_SSExample_SevenSegment_Cfg.PIN_B = 1; // A1
	G_SSExample_SevenSegment_Cfg.PIN_C = 2; // A2
	G_SSExample_SevenSegment_Cfg.PIN_D = 3; // A3
	G_SSExample_SevenSegment_Cfg.PIN_E = 4; // A4
	G_SSExample_SevenSegment_Cfg.PIN_F = 5; // A5
	G_SSExample_SevenSegment_Cfg.PIN_G = 6; // A6

	G_SSExample_SevenSegment_Cfg.CommonMode = COMMON_MODE_CATHODE;
	SevenSegment_Config_v(&G_SSExample_SevenSegment_Cfg);


	while(1){
		for (u8 L_i_u8 = 0; L_i_u8<10 ; L_i_u8++){
			SevenSegment_DisplayValue_v(&G_SSExample_SevenSegment_Cfg, L_i_u8);
			Delay_DelayInSecondsBlocking_v(2, 0);
		}

	}
}
```