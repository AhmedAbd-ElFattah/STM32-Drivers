# Direct Memory Access (DMA) module

DMA is a hardware feature that allows for efficient data transfers between peripherals and memory without involving the CPU. It offloads data transfer tasks from the CPU, freeing up its processing power for other tasks.


## Table of Contents
- [DMA configurations](#dma-configurations)
- [API Reference](#api-reference)
- [Examples](#examples)

## DMA Configurations

### Burst Mode

| Memory                | Peripheral            | Corresponding option                                       |
| --------------------- | --------------------- | ---------------------------------------------------------- |
| Single Transfer       | Single Transfer       | DMA_BURST_MEM_SINGLE_TRANSFER_PERPH_SINGLE_TRANSFER        |
| Increment by 4 beats  | Single Transfer       | DMA_BURST_MEM_INCR_4_BEATS_TRANSFER_PERPH_SINGLE_TRANSFER  |
| Increment by 8 beats  | Single Transfer       | DMA_BURST_MEM_INCR_8_BEATS_TRANSFER_PERPH_SINGLE_TRANSFER  |
| Increment by 16 beats | Single Transfer       | DMA_BURST_MEM_INCR_16_BEATS_TRANSFER_PERPH_SINGLE_TRANSFER |
| Single Transfer       | Increment by 4 beats  | DMA_BURST_MEM_SINGLE_TRANSFER_PERPH_INCR_4_BEATS           |
| Increment by 4 beats  | Increment by 4 beats  | DMA_BURST_MEM_INCR_4_BEATS_TRANSFER_PERPH_INCR_4_BEATS     |
| Increment by 8 beats  | Increment by 4 beats  | DMA_BURST_MEM_INCR_8_BEATS_TRANSFER_PERPH_INCR_4_BEATS     |
| Increment by 16 beats | Increment by 4 beats  | DMA_BURST_MEM_INCR_16_BEATS_TRANSFER_PERPH_INCR_4_BEATS    |
| Single Transfer       | Increment by 8 beats  | DMA_BURST_MEM_SINGLE_TRANSFER_PERPH_INCR_8_BEATS           |
| Increment by 4 beats  | Increment by 8 beats  | DMA_BURST_MEM_INCR_4_BEATS_TRANSFER_PERPH_INCR_8_BEATS     |
| Increment by 8 beats  | Increment by 8 beats  | DMA_BURST_MEM_INCR_8_BEATS_TRANSFER_PERPH_INCR_8_BEATS     |
| Increment by 16 beats | Increment by 8 beats  | DMA_BURST_MEM_INCR_16_BEATS_TRANSFER_PERPH_INCR_8_BEATS    |
| Single Transfer       | Increment by 16 beats | DMA_BURST_MEM_SINGLE_TRANSFER_PERPH_INCR_16_BEATS          |
| Increment by 4 beats  | Increment by 16 beats | DMA_BURST_MEM_INCR_4_BEATS_TRANSFER_PERPH_INCR_16_BEATS    |
| Increment by 8 beats  | Increment by 16 beats | DMA_BURST_MEM_INCR_8_BEATS_TRANSFER_PERPH_INCR_16_BEATS    |
| Increment by 16 beats | Increment by 16 beats | DMA_BURST_MEM_INCR_16_BEATS_TRANSFER_PERPH_INCR_16_BEATS   |
| Increment by 16 beats | Increment by 16 beats | DMA_BURST_MEM_INCR_16_BEATS_TRANSFER_PERPH_INCR_16_BEATS   |
| Increment by 16 beats | Increment by 16 beats | DMA_BURST_MEM_INCR_16_BEATS_TRANSFER_PERPH_INCR_16_BEATS   |

### Double Buffer Mode

| Mode                           | Corresponding option                    |
|--------------------------------|-----------------------------------------|
| Disable                        | DMA_DOUBLE_BUFFER_DISABLE               |
| Enable and start with buffer 0 | DMA_DOUBLE_BUFFER_ENABLE_START_BUFFER_0 |
| Enable and start with buffer 1 | DMA_DOUBLE_BUFFER_ENABLE_START_BUFFER_1 |

### Stream Priority

| DMA Stream priority         | Corresponding option   |
|-----------------------------|------------------------|
| Low software priority       | DMA_PRIORITY_LOW       |
| Meduim software priority    | DMA_PRIORITY_MEDIUM    |
| High software priority      | DMA_PRIORITY_HIGH      |
| Very High software priority | DMA_PRIORITY_VERY_HIGH |

### Peripheral increment offset

| Peripheral increment offset                             | Corresponding option         |
|---------------------------------------------------------|------------------------------|
| Increment peripheral address by the size of peripheral  | DMA_PERPH_INCR_AS_PERPH_SIZE |
| Increment peripheral address by 32-bit                  | DMA_PERPH_INCR_IS_WORD       |

### Data Size

| Memory    | Peripheral | Corresponding option                        |
|-----------|------------|---------------------------------------------|
| Byte      | Byte       | DMA_DATA_SIZE_MEM_BYTE_PERPH_BYTE           |
| Byte      | Half-Word  | DMA_DATA_SIZE_MEM_BYTE_PERPH_HALF_WORD      |
| Byte      | Word       | DMA_DATA_SIZE_MEM_BYTE_PERPH_WORD           |
| Half-Word | Byte       | DMA_DATA_SIZE_MEM_HALF_WORD_PERPH_BYTE      |
| Half-Word | Half-Word  | DMA_DATA_SIZE_MEM_HALF_WORD_PERPH_HALF_WORD |
| Half-Word | Word       | DMA_DATA_SIZE_MEM_HALF_WORD_PERPH_WORD      |
| Word      | Byte       | DMA_DATA_SIZE_MEM_WORD_PERPH_BYTE           |
| Word      | Half-Word  | DMA_DATA_SIZE_MEM_WORD_PERPH_HALF_WORD      |
| Word      | Word       | DMA_DATA_SIZE_MEM_WORD_PERPH_WORD           |

### Increment Mode

| Memory            | Peripheral                                                  | Corresponding option                     |
|-------------------|-------------------------------------------------------------|------------------------------------------|
| Fixed address     | Fixed peripheral                                            | DMA_INCREMENT_MODE_FIXED_MEM_FIXED_PERPH |
| Increment address | Increment by selected option in peripheral increment offset | DMA_INCREMENT_MODE_INCR_MEM_INCR_PERPH   |
| Fixed address     | Increment by selected option in peripheral increment offset | DMA_INCREMENT_MODE_FIXED_MEM_INCR_PERPH  |
| Increment address | Fixed peripheral                                            | DMA_INCREMENT_MODE_INCR_MEM_FIXED_PERPH  |

### Transfer Direction

| Transfer direction   | Corresponding option          |
|----------------------|-------------------------------|
| Peripheral to memory | DMA_TRANSFER_DIR_PERPH_TO_MEM |
| Memory to peripheral | DMA_TRANSFER_DIR_MEM_TO_PERPH |
| Memory to memory     | DMA_TRANSFER_DIR_MEM_TO_MEM   |

### Circular Mode
| Circular mode | Corresponding option      |
|---------------|---------------------------|
| Disable       | DMA_CIRCULAR_MODE_DISABLE |
| Enable        | DMA_CIRCULAR_MODE_ENABLE  |

### Flow controller
| Flow controller | Corresponding option      |
|-----------------|---------------------------|
| DMA             | DMA_FLOW_Controller_DMA   |
| Peripheral      | DMA_PERPH_Controller_DMA  |


### Direct Mode
| Mode    | Corresponding option    |
|---------|-------------------------|
| Enable  | DMA_DIRECT_MODE_ENABLE  |
| Disable | DMA_DIRECT_MODE_DISABLE |

### Interrupt
| Interrupt            | Corresponding option            |
|----------------------|---------------------------------|
| Disable              | DMA_INTERRUPT_DISABLE           |
| FIFO Error           | DMA_INTERRUPT_FIFO_ERR          |
| Direct Mode error    | DMA_INTERRUPT_DIRECT_MODE_ERR   |
| Trasnfer error       | DMA_INTERRUPT_TRANSFER_ERR      |
| Half transfer error  | DMA_INTERRUPT_HALF_TRANSFER     |
| Trasfer complete     | DMA_INTERRUPT_TRANSFER_COMPLETE |


## API Reference
- **void DMA_Config_v(DMA_Cfg const * const Arg_conf_cpcDMA_Cfg,const u8 Arg_ChannelStream_Cu8)**

  **Explanation:**

  This function configures DMA based on configuration passed through DMA_Cfg struct.

  **Parameters**

  - Arg_conf_cpcDMA_Cfg 	: struct that have configured parameters.
  - Arg_ChannelStream_Cu8   : Contains stream & channel number encoded in one of the following options @ref DMA_ChannelNumber_StreamNumber.

  **Return value**

    None


- **void DMA_EnableDMA_v (DMA_Cfg const * const Arg_conf_cpcDMA_Cfg,const u8 Arg_ChannelStream_Cu8)**

  **Explanation:**

  This function enable DMA transmission data.

  **Parameters**

  - Arg_conf_cpcDMA_Cfg 	: Struct to know intended DMA.
  - Arg_ChannelStream_Cu8   : Contains stream & channel number encoded in one of the following options @ref DMA_ChannelNumber_StreamNumber.

  **Return value**

    None

- **void DMA_DisableDMA_v (DMA_Cfg const * const Arg_conf_cpcDMA_Cfg,const u8 Arg_ChannelStream_Cu8)**

  **Explanation:**

  This function disable DMA transmission data.

  **Parameters**

  - Arg_conf_cpcDMA_Cfg 	: Struct to know intended DMA.
  - Arg_ChannelStream_Cu8   : Contains stream & channel number encoded in one of the following options @ref DMA_ChannelNumber_StreamNumber.

  **Return value**

    None

- **void DMA_ChangeBuffer0Address_v (DMA_Cfg  * const Arg_conf_cpcDMA_Cfg,const u8 Arg_ChannelStream_Cu8, const u32 Arg_NewAddress_Cu32)**

  **Explanation:**

  This function changes DMA buffer 0.

  **Parameters**

  - Arg_conf_cpcDMA_Cfg 	: Struct to know intended DMA.
  - Arg_ChannelStream_Cu8   : Contains stream & channel number encoded in one of the following options.
  - Arg_NewAddress_Cu32     : contains the new assigned address.
  **Return value**

    None

- **void DMA_ChangeBuffer1Address_v (DMA_Cfg  * const Arg_conf_cpcDMA_Cfg,const u8 Arg_ChannelStream_Cu8, const u32 Arg_NewAddress_Cu32)**

  **Explanation:**

  This function changes DMA buffer 1.

  **Parameters**

  - Arg_conf_cpcDMA_Cfg 	: Struct to know intended DMA.
  - Arg_ChannelStream_Cu8   : Contains stream & channel number encoded in one of the following options.
  - Arg_NewAddress_Cu32     : contains the new assigned address.
  **Return value**

    None

- **Bool DMA_CheckInterruptAndClear_Bool(const u8 Arg_DMAInstanceId_u8,const  u8 Arg_StreamNum_Cu8, const  u8 Arg_InterruptFlagPos_Cu8)**

  **Explanation:**

  This function is used by interrupt handler to check the existence of interrupt and clear pending flag for this interrupt type.

  **Parameters**

  - Arg_DMAInstanceId_u8 	 : Instance id of DMA that you need to check about it.
  - Arg_StreamNum_Cu8   	 : Stream number that you need to check about it.
  - Arg_InterruptFlagPos_Cu8 : Interrupt flag bit-position in LISR or HISR register.
  **Return value**

    Is there any interrupt for the mentioned stream of DMA.


- **u8 DMA_GetCurrentBuffer_v(DMA_Cfg const * const Arg_conf_cpcDMA_Cfg,const u8 Arg_ChannelStream_Cu8)**

  **Explanation:**

  This function returns current active buffer.

  **Parameters**

  - Arg_conf_cpcDMA_Cfg 	 : Struct to know intended DMA.
  - Arg_ChannelStream_Cu8    : Contains encoded stream & channel number.
  - Arg_InterruptFlagPos_Cu8 : Interrupt flag bit-position in LISR or HISR register.
  **Return value**

    current active buffer number.

- **void DMA_Reset_v(DMA_Cfg const * const Arg_conf_cpcDMA_Cfg,const  u8 Arg_ChannelStream_Cu8)**

  **Explanation:**

  This function resets DMA to it's default configurations.

  **Parameters**

  - Arg_conf_cpcDMA_Cfg 	 : Struct that have configured parameters.
  - Arg_ChannelStream_Cu8    : Contains encoded stream & channel number.
  **Return value**

    None.

## Examples
## Memory to memory transfer with interupt of complete transfering data.
```c
#include "LIB/utils.h"
#include "HMCAL/DMA/DMA.h"
#include "HMCAL/Interrupt/InterruptHandlers.h"

u8 G_source_u8[8] = {
		'A','B','C','D',
		'E','F','G','H'};
u8 G_destinationu8[8];


void DMA_ArrayTransferCompletedCallback(void){
	/*you can insert a breakpoint here,
	 * to know the array transfer is completed while debugging*/
	asm volatile ("NOP");
}

int main(void)
{
	/*Set default configurations to DMA*/
	DMA_Cfg G_DMAExMem2Mem = {0};
	/*DMA 2*/
	G_DMAExMem2Mem.InstanceId = 2;

	G_DMAExMem2Mem.Burst = DMA_BURST_MEM_SINGLE_TRANSFER_PERPH_SINGLE_TRANSFER;
	G_DMAExMem2Mem.DirectMode = DMA_DIRECT_MODE_DISABLE;
	/*Set transfer datasize
	 * as source& d estination array contain data of 1 bytes*/
	G_DMAExMem2Mem.DataSize = DMA_DATA_SIZE_MEM_BYTE_PERPH_BYTE;
	/*
	 * As we trasnfer between two arrays, Trasnfer direction is Memory to memory.
	 * */
	G_DMAExMem2Mem.TransferDir = DMA_TRANSFER_DIR_MEM_TO_MEM;
	G_DMAExMem2Mem.DoubleBuffer = DMA_DIRECT_MODE_DISABLE;
	G_DMAExMem2Mem.FlowController = DMA_FLOW_Controller_DMA;
	/*Increment Memory address and peripheral address*/
	G_DMAExMem2Mem.IncrementMode = DMA_INCREMENT_MODE_INCR_MEM_INCR_PERPH;
	G_DMAExMem2Mem.PeripheralAddress = (u32)&G_source_u8;
	G_DMAExMem2Mem.MemoryAddress = (u32)&G_destinationu8;
	G_DMAExMem2Mem.Priority = DMA_PRIORITY_VERY_HIGH;
	G_DMAExMem2Mem.Size = ARRAY_LENGTH(G_source_u8);
	G_DMAExMem2Mem.Interrupt = DMA_INTERRUPT_TRANSFER_COMPLETE;
	/*Configure DMA2 with stream number 2*/
	DMA_Config_v(&G_DMAExMem2Mem, DMA2_MEM_S_0);
	/* First  parameter is instance id, in our example it's 2 as we use DMA2.
	 * Second parameter is stream number, in our example it's 0 as we use stream 0.
	 * Third  parameter is interrupt type, it can be assign to any available option for DMA_Cfg interrupt member.
	 * Fourth parameter is pointer callback function to the assigned interrupt type.
	 * */
	InterruptHandler_SetDMACallback_v(2, 0, DMA_INTERRUPT_TRANSFER_COMPLETE, DMA_ArrayTransferCompletedCallback);

	/*
	 * Enable DMA2 with stream number 2 to transfer data between two arrays.
	 * 
	 * Note that you should set all callbacks before enabling interrupt, 
	 * because DMA may complete it's transfer before the processor complete executing "InterruptHandler_SetDMACallback_v" function.
	 * */
	
	DMA_EnableDMA_v(&G_DMAExMem2Mem, DMA2_MEM_S_0);
	while(1);
}

```