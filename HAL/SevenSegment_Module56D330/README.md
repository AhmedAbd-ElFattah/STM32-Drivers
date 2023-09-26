# Seven Segment Module 56D330


## Table of Contents
- [API Reference](#api-reference)
- [Examples](#examples)

## API Reference

- **void SevenSegmentModule_Config_v(SevenSegmentModule56D330_Cfg * const Arg_Config_pSSM_Cfg)**

	**Explanation** 

	This function configures Seven Segment module based on configuration passed through SevenSegmentModule56D330_Cfg struct.
	
	**Parameters**
	
	Arg_Config_pSSM_Cfg    : struct that have configured parameters.

	**Return value** 

	None

- **void SevenSegmentModule_DisplayNumber_v(SevenSegmentModule56D330_Cfg * const Arg_Config_pSSM_Cfg, u8 Arg_DispNum_u8, u16 Arg_Number_u16)**

	**Explanation** 

	This function configures Seven Segment module based on configuration passed through SevenSegmentModule56D330_Cfg struct.
	
	**Parameters**
	
	Arg_Config_pSSM_Cfg    : struct that have configured parameters.

	Arg_DispNum_u8    	   : Pass display number.

	Arg_Number_u16    	   : Number the you need to display on display number in Arg_DispNum_u8.

	**Return value** 

	None


## Examples
## Seven Segment Module 56D330 Up-counting on display 0 And Down-Counter on display 1.

```c
#include "HAL/SevenSegment_Module56D330/SevenSegmentModule56D330.h"
#include "LIB/Delay/Delay.h"

SevenSegmentModule56D330_Cfg G_SSExample_SevenSegmentModule_Cfg;

u16 G_Disp0Val_u16 = 0;
u16 G_Disp1Val_u16 = 999;
int main(void)
{
	/*Connect Chip Select to A3*/
	G_SSExample_SevenSegmentModule_Cfg.ChipSelectGPIOInstanceId = 'A';
	G_SSExample_SevenSegmentModule_Cfg.ChipSelectGPIOPin = 3;

	/*Connect Clock Pin to B1*/
	G_SSExample_SevenSegmentModule_Cfg.ClockGPIOInstanceId = 'B';
	G_SSExample_SevenSegmentModule_Cfg.ClockGPIOGPIOPin = 1;

	/*Connect Data input pin to C14*/
	G_SSExample_SevenSegmentModule_Cfg.DataInputGPIOInstanceId = 'C';
	G_SSExample_SevenSegmentModule_Cfg.DataInputGPIOPin = 14;


	SevenSegmentModule_Config_v(&G_SSExample_SevenSegmentModule_Cfg);


	while(1){
		SevenSegmentModule_DisplayNumber_v(&G_SSExample_SevenSegmentModule_Cfg, 0, G_Disp0Val_u16++);
		SevenSegmentModule_DisplayNumber_v(&G_SSExample_SevenSegmentModule_Cfg, 1, G_Disp1Val_u16--);

		if (1000 == G_Disp0Val_u16){
			G_Disp0Val_u16 = 0;
		}

		if (0 == G_Disp1Val_u16){
			G_Disp1Val_u16 = 999;
		}
		Delay_DelayInSecondsBlocking_v(1, 0);
	}
}
```