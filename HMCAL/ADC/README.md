# Analog to digital converter (ADC) module
The ADC allows you to measure analog voltages and convert them into digital values that can be processed by the microcontroller.



## Table of Contents
- [ADC Configurations](#adc-configurations)
- [API Reference](#api-reference)

## ADC Configurations
### External trigger
| External Trigger              | Corresponding option             |
|-------------------------------|----------------------------------|
| Disable External trigger.     | ADC_EXT_TRIG_DETECT_DISABLED     |
| External Trigger rising edge  | ADC_EXT_TRIG_DETECT_RISING_EDGE  |
| External Trigger falling edge | ADC_EXT_TRIG_DETECT_FALLING_EDGE |
| External Trigger both edges   | ADC_EXT_TRIG_DETECT_FALLING_EDGE |

### DMA
| DMA     | Corresponding option |
|---------|----------------------|
| Disable | ADC_DMA_DISABLE      |
| Enable  | ADC_DMA_ENABLE       |

### ADC Resolution
| ADC Conversion resolution | Corresponding option |
|---------------------------|----------------------|
| 12-Bit                    | ADC_RES_12_BIT       |
| 10-Bit                    | ADC_RES_10_BIT       |
| 8-Bit                     | ADC_RES_8_BIT        |
| 6-Bit                     | ADC_RES_6_BIT        |

### Continuous scan
| Continous scan | Corresponding option  |
|----------------|-----------------------|
| Disable        | ADC_CONT_SCAN_DISABLE |
| Enable         | ADC_CONT_SCAN_ENABLE  |

### Regular event trigger
| Regular event trigger      | Corresponding option           |
|----------------------------|--------------------------------|
| Timer 1 CC1 event          | ADC_REG_EVENT_TRIG_TIM1_CC1    |
| Timer 1 CC2 event          | ADC_REG_EVENT_TRIG_TIM1_CC2    |
| Timer 1 CC3 event          | ADC_REG_EVENT_TRIG_TIM1_CC3    |
| Timer 2 CC2 event          | ADC_REG_EVENT_TRIG_TIM2_CC2    |
| Timer 2 CC3 event          | ADC_REG_EVENT_TRIG_TIM2_CC3    |
| Timer 2 CC4 event          | ADC_REG_EVENT_TRIG_TIM2_CC4    |
| Timer 2 TRGO event         | ADC_REG_EVENT_TRIG_TIM2_TRGO   |
| Timer 3 CC1 event          | ADC_REG_EVENT_TRIG_TIM3_CC1    |
| Timer 3 TRGO event         | ADC_REG_EVENT_TRIG_TIM3_TRGO   |
| Timer 4 CC4 event          | ADC_REG_EVENT_TRIG_TIM4_CC4    |
| Timer 5 CC1 event          | ADC_REG_EVENT_TRIG_TIM5_CC1    |
| Timer 5 CC2 event          | ADC_REG_EVENT_TRIG_TIM5_CC2    |
| Timer 5 CC3 event          | ADC_REG_EVENT_TRIG_TIM5_CC3    |
| Timer 8 CC1 event          | ADC_REG_EVENT_TRIG_TIM8_CC1    |
| Timer 8 TRGO event         | ADC_REG_EVENT_TRIG_TIM8_TRGO   |
| External Interrupt Line 11 | ADC_REG_EVENT_TRIG_EXTI_LINE11 |

### Sample time
| Sample time in terms of clock cycles | Corresponding option       |
|--------------------------------------|----------------------------|
| 3                                    | ADC_SAMPLE_TIME_3_CYCLES   |
| 15                                   | ADC_SAMPLE_TIME_15_CYCLES  |
| 28                                   | ADC_SAMPLE_TIME_28_CYCLES  |
| 56                                   | ADC_SAMPLE_TIME_56_CYCLES  |
| 84                                   | ADC_SAMPLE_TIME_84_CYCLES  |
| 112                                  | ADC_SAMPLE_TIME_112_CYCLES |
| 144                                  | ADC_SAMPLE_TIME_144_CYCLES |
| 480                                  | ADC_SAMPLE_TIME_480_CYCLES |

## API Reference

- **void ADC_Config_v(ADC_Cfg const * const Arg_conf_cpcADC_Cfg)**

	**Explanation** 

	This function configures ADC based on configuration passed through ADC_Cfg struct
	
	**Parameters**
	
	Arg_conf_cpcADC_Cfg    : struct that have configured parameters

	**Return value** 

	None

- **void ADC_StartSoftwareConversion_v(ADC_Cfg const * const Arg_conf_cpcADC_Cfg)**

	**Explanation** 

	Start Software Conversion
	
	**Parameters**
	
	Arg_conf_cpcADC_Cfg    : struct that have configured parameters

	**Return value** 

	None

- **void ADC_StopSoftwareConversion_v(ADC_Cfg const * const Arg_conf_cpcADC_Cfg)**

	**Explanation** 

	Stop Software Conversion
	
	**Parameters**
	
	Arg_conf_cpcADC_Cfg    : struct that have configured parameters

	**Return value** 

	None

- **void ADC_EnableADC_v(ADC_Cfg const * const Arg_conf_cpcADC_Cfg)**

	**Explanation** 

	Enable ADC
	
	**Parameters**
	
	Arg_conf_cpcADC_Cfg    : struct that have configured parameters

	**Return value** 

	None

- **void ADC_DisableADC_v(ADC_Cfg const * const Arg_conf_cpcADC_Cfg)**

	**Explanation** 

	Disable ADC
	
	**Parameters**
	
	Arg_conf_cpcADC_Cfg    : struct that have configured parameters

	**Return value** 

	None

- **u16 ADC_GetReading_u16(ADC_Cfg const * const Arg_conf_cpcADC_Cfg)**

	**Explanation** 

	Get measured value.
	
	**Parameters**
	
	Arg_conf_cpcADC_Cfg    : struct that have configured parameters

	**Return value** 

	Measured value


- **u32 ADC_GetAdressForDMA_u32(ADC_Cfg const * const Arg_conf_cpcADC_Cfg)**

	**Explanation** 

	Usually used with DMA to get the address of selected ADC.
	
	**Parameters**
	
	Arg_conf_cpcADC_Cfg    : struct that have configured parameters

	**Return value** 

	Address of selected ADC.

```c
#include "LIB/utils.h"
#include "LIB/Delay/Delay.h"
#include "HMCAL/ADC/ADC.h"


int result;
int main(void)
{
	ADC_Cfg ADCConfinguraion = {0};
	ADCConfinguraion.ConversionMode = ADC_CONV_MODE_CONTINUOUS;
	ADCConfinguraion.Resolution = ADC_RES_12_BIT;
	u32 Sequence[] = {
			ADC1_A0,
	};
	ADCConfinguraion.ConversionChannels = Sequence;
	ADCConfinguraion.ConversionLength = 1;
	ADCConfinguraion.InstanceId = 1;
	ADC_Config_v(&ADCConfinguraion);
	ADC_EnableADC_v(&ADCConfinguraion);
	ADC_StartSoftwareConversion_v(&ADCConfinguraion);

	while(1){
		result = ADC_GetReading_u16(&ADCConfinguraion);
		
	}
}
```



















