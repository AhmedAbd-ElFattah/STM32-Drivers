# Button module


## Table of Contents
- [API Reference](#api-reference)
- [Examples](#examples)


## API Reference

- **void Button_Config_v(Button_Cfg *Arg_Config_pLButton_Cfg)**

	**Explanation** 

	This function configures Button based on configuration passed through Button_Cfg struct.
	
	**Parameters**
	
	Arg_Config_pLButton_Cfg    : struct that have configured parameters.

	**Return value** 

	None

- **void Button_Reset_v(Button_Cfg *Arg_Config_pLButton_Cfg)**

	**Explanation** 

	This function resets configure of Button based on configuration passed through Button_Cfg struct.
	
	**Parameters**
	
	Arg_Config_pLButton_Cfg    : struct that have configured parameters.

	**Return value** 

	None

- **u16 Button_GetReading_u16(Button_Cfg *Arg_Config_pLButton_Cfg)**

	**Explanation** 

	This function reads button reading.
	
	**Parameters**
	
	Arg_Config_pLButton_Cfg    : struct that have configured parameters.

	**Return value** 

	None

- **Bool Button_GetPinReading_Bool(Button_Cfg *Arg_Config_pLButton_Cfg, u8 Arg_Pin_u8)**

	**Explanation** 

	This function reads pin of specific button.
	
	**Parameters**
	
	Arg_Config_pLButton_Cfg    : struct that have configured parameters.
	Arg_Pin_u8				   : Pin that you need to get it's reading.

	**Return value** 

	Reading of pins.

- **Bool Button_IsPressed_Bool(Button_Cfg *Arg_Config_pLButton_Cfg, u8 Arg_Pin_u8)**

	**Explanation** 

	This function checks whether button is ressed or released regardless of Pull Up/Down Resistor mode.
	
	**Parameters**
	
	Arg_Config_pLButton_Cfg    : struct that have configured parameters.
	Arg_Pin_u8				   : Pin connected to button that you need to check about it.

	**Return value** 

	 Is button is pressed ?

## Examples
## Continuous reading of Button connected with A1 Pin.

```c
#include "HAL/Button/Button.h"
Button_Cfg G_Example_Button_Cfg;
Bool Reading;
int main(void)
{
	G_Example_Button_Cfg.GPIOInstanceId = 'A';
	G_Example_Button_Cfg.Pin = PIN_1_MASK;
	G_Example_Button_Cfg.PullUpPullDownResistor = Button_RESISTOR_PULL_UP;
	Button_Config_v(&G_Example_Button_Cfg);
	while(1){
		Reading = Button_IsPressed_Bool(&G_Example_Button_Cfg, 1);
	}
}
```