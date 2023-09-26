# Keypad


## Table of Contents
- [API Reference](#api-reference)
- [Examples](#examples)


## API Reference

- **void Keypad_Config_v(Keypad_Cfg const * const Arg_Config_cpcLKeypad)**

	**Explanation** 

	This function configures Button based on configuration passed through Keypad_Cfg struct.
	
	**Parameters**
	
	Arg_Config_cpcLKeypad    : struct that have configured parameters.

	**Return value** 

	None

- **void Keypad_ReadKeys_v(Keypad_Cfg const * const Arg_Config_cpcLKeypad, Bool *const Arg_OutputArr_pcBool)**

	**Explanation** 

	Read keypad values.
	
	**Parameters**
	
	Arg_Config_cpcLKeypad    : struct that have configured parameters.
    Arg_OutputArr_pcBool     : pointer to 2-D array of returned statis of key key on keypad
	**Return value** 

	None

## Examples
## Read keypad values

```c
#include "HAL/Keypad/Keypad.h"

Keypad_Cfg G_Example_Keypad_Cfg;
Bool Reading[4][4];

int main(void)
{
	u8 Rows_Pins[] = {0, 1, 2, 3};
	u8 Cols_Pins[] = {4, 5, 6, 7};
	G_Example_Keypad_Cfg.ColsGPIOInstanceId = 'A';
	G_Example_Keypad_Cfg.ColsPins = Cols_Pins;
	G_Example_Keypad_Cfg.RowsGPIOInstanceId = 'A';
	G_Example_Keypad_Cfg.RowsPins = Rows_Pins;
	G_Example_Keypad_Cfg.PullUpDownMode = Keypad_RESISTOR_PULL_DOWN;

	G_Example_Keypad_Cfg.Cols_Number = 4;
	G_Example_Keypad_Cfg.Rows_Number = 4;
	Keypad_Config_v(&G_Example_Keypad_Cfg);


	while(1){
		Keypad_ReadKeys_v(&G_Example_Keypad_Cfg, (Bool *)Reading);
	}
}

```