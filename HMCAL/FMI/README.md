# Flash Memory Inteface module

The Flash memory interface peripheral in STM32 microcontrollers enables efficient writing, and erasing of the on-chip Flash memory. It provides features such as program and erase operations.

With the Flash memory interface, you can program data into the Flash memory in various sizes (byte, half-word, word, or double-word) and perform erasing on individual pages or entire sectors.


## Table of Contents

- [API Reference](#api-reference)
- [Examples](#examples)

## API Reference
- **void FMI_FlashWriteU16Data_v(const u32 Arg_Address_Cu32, const u16 Arg_Data_Cu16)**

  **Explanation:**

  This function writes 2-bytes value on flash.

  **Parameters**

  - Arg_Address_Cu32 : Address that you want to write on.
  - Arg_Data_Cu16   : Data that you write on address given in param  Arg_Address_Cu32

  **Return value**

    None

- **void FMI_FlashWriteU32Data_v(const u32 Arg_Address_Cu32,const  u32 Arg_Data_Cu32)**

  **Explanation:**

  This function writes 4-bytes value on flash.

  **Parameters**

  - Arg_Address_Cu32 : Address that you want to write on.
  - Arg_Data_Cu32   : Data that you write on address given in param  Arg_Address_Cu32

  **Return value**

    None


- **void FMI_EraseFlashSector_v(const u16 Arg_SectorNumber_Cu16)**

  **Explanation:**

  Erases specific section of flash.

  **Parameters**

  - Arg_SectorNumber_u8 : Onput sector number that you want to erase.

  **Return value**

    None


## Examples

### Write 4 bytes at flash address
```c
FMI_FlashWriteU16Data_v(0x102, 0xABCD);
```
### Write 4 bytes at flash address
```c
FMI_FlashWriteU16Data_v(0x102, 0xABCD1234);
```
