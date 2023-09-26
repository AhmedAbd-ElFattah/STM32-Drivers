# TFT LCD (TFTLCD) module

 LCD screen module that uses the Serial Peripheral Interface (SPI) protocol for communication based on ST7735S controller chip.


## Table of Contents
- [API Reference](##api-reference)
- [Example](##wxample)

## API Reference
- **void TFT_Config_v(TFTLCD_Cfg const * const Arg_conf_cpcTFTLCD_Cfg)**

  **Explanation:**

  This function configures TFTLCD based on configuration passed through TFTLCD_Cfg struct.

  **Parameters**

  - Arg_conf_cpcTFTLCD_Cfg 	: struct that have configured parameters.

  **Return value**

    None

- **void TFT_DisplayImage_v(TFTLCD_Cfg const * const Arg_conf_cpcTFTLCD_Cfg, const u16 Arg_Image_u16[Arg_conf_cpcTFTLCD_Cfg->Rows][Arg_conf_cpcTFTLCD_Cfg->Cols])**

  **Explanation:**

  This function displays image on TFT LCD.

  **Parameters**

  - Arg_conf_cpcTFTLCD_Cfg 	: struct that have configured parameters.
  - Arg_Image_u16           : Image in 2D array with format RGB565.

  **Return value**

    None

## Examples
## Display image
```c
#include "HAL/TFTLCD/TFTLCD.h"
#include "HAL/TFTLCD/TFTTestImage.h"

int main(void)
{

	TFTLCD_Cfg L_TFTExample_TFTLCD_Cfg = {0};

	L_TFTExample_TFTLCD_Cfg.GPIOSPIInstanceId = 'B';
	L_TFTExample_TFTLCD_Cfg.SPIInstanceId = 1;
	L_TFTExample_TFTLCD_Cfg.SPIPins = PIN_3_MASK|PIN_5_MASK;

	L_TFTExample_TFTLCD_Cfg.A0GPIOInstanceId = 'A';
	L_TFTExample_TFTLCD_Cfg.A0Pin = PIN_2_MASK;

	L_TFTExample_TFTLCD_Cfg.ResetGPIOInstanceId = 'A';
	L_TFTExample_TFTLCD_Cfg.ResetPin = PIN_1_MASK;

	L_TFTExample_TFTLCD_Cfg.Cols = 128;
	L_TFTExample_TFTLCD_Cfg.Rows = 160;


	TFT_Config_v(&L_TFTExample_TFTLCD_Cfg);

	TFT_DisplayImage_v(&L_TFTExample_TFTLCD_Cfg, L_TFTTestImage_u16);

}

```