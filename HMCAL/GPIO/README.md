# General Purpose Input Output (GPIO) module
GPIO stands for General-Purpose Input/Output, and it refers to the pins on the microcontroller that can be configured as either inputs or outputs to interface with external devices.


- **u16 GPIO_PORTRead_u16(GPIO_Cfg const * const Arg_conf_cpcGPIO_Cfg)**

	**Explanation** 

	fdsfdsdfs.
	
	**Parameters**
	
	Parameter    : dsffsdfsdfsd. 

	**Return value** 

	None
## Table of Contents
- [API Reference](#api-reference)

## API Reference

- **void GPIO_Config_v(GPIO_Cfg const *const Arg_conf_cpcGPIO_Cfg)**

	**Explanation** 

	This function configures GPIO based on configuration passed through GPIO_Cfg struct.
	
	**Parameters**
	
	Arg_conf_cpcGPIO_Cfg    : struct that have configured parameters.

	**Return value** 

	None

- **void GPIO_Reset_v (GPIO_Cfg const *const Arg_conf_cpcGPIO_Cfg)**

	**Explanation** 

	Set and Reset one pin only
	example

	To set D13 pin.

	GPIO_Cfg gpio_example;
	gpio_example.InstanceId = 'D';
	GPIO_PinWrite_v(&gpio_example, 13, STD_HIGH); 
	To reset D13.
	GPIO_PinWrite_v(&gpio_example, 13, STD_LOW);
	
	**Parameters**
	
	Arg_conf_cpcGPIO_Cfg : struct that have configured parameters.    
    Arg_PIN_u8 : Pin number.                                          
	Arg_Value_u8 : pass STD_HIGH or STD_LOW to set/reset selected pin.

	**Return value** 

	None

- **void GPIO_PinWrite_v(GPIO_Cfg const * const Arg_conf_cpcGPIO_Cfg, const u8 Arg_PIN_Cu8, const u8 Arg_Value_Cu8)**

	**Explanation** 

	Set and Reset all pins in the port.
	
	**Parameters**
	
	Arg_conf_cpcGPIO_Cfg    : struct that have configured parameters. 
    Arg_Value_u8    :   pass STD_HIGH or STD_LOW to set/reset all pins in the port.
	**Return value** 

	None

- **void GPIO_PORTWrite_v(GPIO_Cfg const * const Arg_conf_cpcGPIO_Cfg, const u8 Arg_Value_Cu8)**

	**Explanation** 

	Set and Reset some pins or write value to specific pins
    example
    
    To set D12 , D13, D14 and D15 pin.
 
    GPIO_Cfg gpio_example;
    gpio_example.InstanceId = 'D';
    gpio_example.PINs = PIN_13_MASK | PIN_14_MASK | PIN_15_MASK | PIN_12_MASK;
    GPIO_PinWrite_v(GPIO_Cfg const * const Arg_conf_cpcGPIO_Cfg, 0xFFFF);

    To reset D13.
    GPIO_PinWrite_v(&gpio_example , 0x0000);
	
	**Parameters**
	
	Arg_Value_u8    : pass STD_HIGH or STD_LOW to set/reset selected pins. 

	**Return value** 

	None

- **u8 GPIO_PinRead_u8(GPIO_Cfg const * const Arg_conf_cpcGPIO_Cfg, const u8 Arg_PIN_Cu8)**

	**Explanation** 

	Read Specific pin whether it's set or reset
    example
    To read pin A0
    GPIO_Cfg gpio_example;
    gpio_example.InstanceId = 'A';
    GPIO_PinRead_u8(&gpio_example , 0);
    the output of function is 0 or 1 depending on wheter input pin is high or low;
	
	**Parameters**
	
	Arg_conf_cpcGPIO_Cfg    : struct that have configured parameters. 
    Arg_PIN_Cu8             : select pin number
	**Return value** 

	None
