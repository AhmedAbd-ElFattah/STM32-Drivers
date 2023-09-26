# Digital to Analog (DAC) module

The DAC module allows the microcontroller to convert digital signals into analog voltage levels, which is essential for applications such as audio generation, waveform synthesis, and control systems.


## Table of Contents
- [DAC configurations](#dac-configurations)
- [API Reference](#api-reference)
- [Examples](#examples)

## DAC Configurations

### Channel
| Channel | Corresponding option |
|---------|----------------------|
| 1       | DAC_CHANNEL_1        |
| 2       | DAC_CHANNEL_2        |


## Wave generation
| Wave generation | Corresponding option         |
|-----------------|------------------------------|
| Disable         | DAC_WAVE_GENERATION_DISABLE  |
| Noise           | DAC_WAVE_GENERATION_NOISE    |
| Triangle        | DAC_WAVE_GENERATION_TRIANGLE |

## Buffer
| Buffer  | Corresponding option |
|---------|----------------------|
| Disable | DAC_BUFFER_DISABLE   |
| Enable  | DAC_BUFFER_ENABLE    |

## Max Amplitude
| Max Amplitude | Corresponding option   |
|---------------|------------------------|
| 1             | DAC_MAX_AMPLITUDE_1    |
| 3             | DAC_MAX_AMPLITUDE_3    |
| 7             | DAC_MAX_AMPLITUDE_7    |
| 15            | DAC_MAX_AMPLITUDE_15   |
| 31            | DAC_MAX_AMPLITUDE_31   |
| 63            | DAC_MAX_AMPLITUDE_63   |
| 127           | DAC_MAX_AMPLITUDE_127  |
| 255           | DAC_MAX_AMPLITUDE_255  |
| 511           | DAC_MAX_AMPLITUDE_511  |
| 1023          | DAC_MAX_AMPLITUDE_1023 |
| 2047          | DAC_MAX_AMPLITUDE_2047 |
| 4095          | DAC_MAX_AMPLITUDE_4095 |

## Trigger
| Trigger                 | Corresponding option   |
|-------------------------|------------------------|
| No Trigger              | DAC_TRIGGER_NO_TRIGGER |
| Timer 6 TRGO Event      | DAC_TRIGGER_TIM6_TRGO  |
| Timer 8 TRGO Event      | DAC_TRIGGER_TIM8_TRGO  |
| Timer 7 TRGO Event      | DAC_TRIGGER_TIM7_TRGO  |
| Timer 5 TRGO Event      | DAC_TRIGGER_TIM5_TRGO  |
| Timer 2 TRGO Event      | DAC_TRIGGER_TIM2_TRGO  |
| Timer 4 TRGO Event      | DAC_TRIGGER_TIM4_TRGO  |
| External Trigger Line 9 | DAC_TRIGGER_EXT_LINE9  |
| SW Trigger              | DAC_TRIGGER_SW_TRIGGER |

## DMA
| DMA     | Corresponding option |
|---------|----------------------|
| Disable | DAC_DMA_DISABLE      |
| Enable  | DAC_DMA_ENABLE       |



## API Reference
- **void DAC_Config_v(DAC_Cfg const * const Arg_conf_cpcDAC_Cfg)**

  **Explanation:**

  This function configures DAC based on configuration passed through DAC_Cfg struct.

  **Parameters**

  - Arg_conf_cpcDAC_Cfg 	: struct that have configured parameters.

  **Return value**

    None

- **void DAC_EnableDAC_v(DAC_Cfg const * const Arg_conf_cpcDAC_Cfg)**

  **Explanation:**

  Enable DAC.

  **Parameters**

  - Arg_conf_cpcDAC_Cfg 	: struct that have configured parameters.

  **Return value**

    None

- **void DAC_DisableDAC_v(DAC_Cfg const * const Arg_conf_cpcDAC_Cfg)**

  **Explanation:**

  Disable DAC.

  **Parameters**

  - Arg_conf_cpcDAC_Cfg 	: struct that have configured parameters.

  **Return value**

    None

- **void DAC_SetOutputValue_v(DAC_Cfg const * const Arg_conf_cpcDAC_Cfg, u16 Arg_OutputValue_u16)**

  **Explanation:**

  Output analog value.

  **Parameters**

  - Arg_conf_cpcDAC_Cfg 	: struct that have configured parameters.
  - Arg_OutputValue_u16     : value of analog value.

  **Return value**

    None

- **void DAC_SoftwareTrigger_v(DAC_Cfg const * const Arg_conf_cpcDAC_Cfg)**

  **Explanation:**

  Output analog value.

  **Parameters**

  - Arg_conf_cpcDAC_Cfg 	: struct that have configured parameters.

  **Return value**

    None

- **u32 DAC_GetAddressForDMA_u32(DAC_Cfg const * const Arg_conf_cpcDAC_Cfg)**

  **Explanation:**

  Usually used with DMA to get the address of selected DAC.

  **Parameters**

  - Arg_conf_cpcDAC_Cfg 	: struct that have configured parameters.

  **Return value**

    Address of selected DAC


## Examples
### Output value with 3.2 reference voltage.
```c
#include "HMCAL/DAC/DAC.h"
int main(void)
{
  /*Set output value at GPIO A4 pin*/
	DAC_Cfg G_DACExample = {0};
	G_DACExample.Channel = DAC_CHANNEL_1;
	G_DACExample.GPIOInstanceId = 'A';
	G_DACExample.GPIOPins = PIN_4_MASK;
	G_DACExample.InstanceId = 1;
	DAC_Config_v(&G_DACExample);
	DAC_EnableDAC_v(&G_DACExample);
  /*
  * output value will be 3.2 as resolution is 12 bit and reference voltage = 3.2 V.
  */
	DAC_SetOutputValue_v(&G_DACExample, 4095);
}
```