# Serial Peripheral Interface (SPI) module
Serial Peripheral Interface (SPI) module allows for high-speed, full-duplex communication with peripheral devices. SPI is a synchronous serial communication protocol commonly used to interface microcontrollers with sensors, displays, memory devices, and other integrated circuits.


## Table of Contents
- [SPI Configurations](#spi-configurations)
- [API Reference](#api-reference)


## SPI Configurations

### Direction
| Direction                   | Corresponding option                      |
|-----------------------------|-------------------------------------------|
| Unidirectional              | SPI_DIRECTION_UNIDIRECTIONAL              |
| Bidirectional Receive only  | SPI_DIRECTION_RECEIVE_ONLY_BIDIRECTIONAL  |
| Bidirectional Transmit only | SPI_DIRECTION_TRANSMIT_ONLY_BIDIRECTIONAL |


### CRC
| CRC         | Corresponding option |
|-------------|----------------------|
| Disable CRC | SPI_CRC_DISABLE      |
| Enable CRC  | SPI_CRC_ENABLE       |


### Capture strobe
| Capture Strobe | Corresponding option                     |
|----------------|------------------------------------------|
| Low Rising     | SPI_CAPTURE_STROBE_IDLE_CLK_LOW_RISING   |
| High Rising    | SPI_CAPTURE_STROBE_IDLE_CLK_HIGH_RISING  |
| High Falling   | SPI_CAPTURE_STROBE_IDLE_CLK_HIGH_FALLING |
| Low Falling    | SPI_CAPTURE_STROBE_IDLE_CLK_LOW_FALLING  |


### Frame size
| Frame Size        | Corresponding option             |
|-------------------|----------------------------------|
| 8-Bits MSB First  | SPI_FRAME_SIZE_8_BITS_MSB_First  |
| 8-Bits LSB First  | SPI_FRAME_SIZE_8_BITS_LSB_First  |
| 16-Bits MSB First | SPI_FRAME_SIZE_16_BITS_MSB_First |
| 16-Bits LSB First | SPI_FRAME_SIZE_16_BITS_LSB_First |


### Master/slave state
| Master/Slave state | Corresponding option |
|--------------------|----------------------|
| Master             | SPI_STATE_MASTER     |
| Slave              | SPI_STATE_SLAVE      |

### Prescaler
| Prescaler | Corresponding option |
|-----------|----------------------|
| 2         | SPI_PRESCALER_2      |
| 4         | SPI_PRESCALER_4      |
| 8         | SPI_PRESCALER_8      |
| 16        | SPI_PRESCALER_16     |
| 32        | SPI_PRESCALER_32     |
| 64        | SPI_PRESCALER_64     |
| 128       | SPI_PRESCALER_128    |
| 256       | SPI_PRESCALER_256    |

### Interrupt
| Interrupt         | Corresponding option       |
|-------------------|----------------------------|
| Disable           | SPI_INTERRUPT_DISABLE      |
| Transmit Empty    | SPI_INTERRUPT_TX_EMPTY     |
| Receive Not-Empty | SPI_INTERRUPT_RX_NON_EMPTY |
| Error             | SPI_INTERRUPT_ERROR        |

## API Reference

- **void SPI_Config_v(SPI_Cfg const * const Arg_conf_cpcSPI_Cfg)**

  **Explanation:**

  This function configures GPIO based on configuration passed through SPI_Cfg struct.

  **Parameters**

  - Arg_conf_cpcDMA_Cfg 	: struct that have configured parameters.

  **Return value**

    None

- **void SPI_Sendu8Data_v(SPI_Cfg const * const Arg_conf_cpcSPI_Cfg, u8 Arg_data_u8)**

  **Explanation:**

  This function transmits 8-bit data using SPI.

  **Parameters**

  - Arg_conf_cpcDMA_Cfg 	: struct that have configured parameters.
  - Arg_data_u8             : Data that will be transmitted using SPI.
  **Return value**

    None

- **void SPI_Sendu16Data_v(SPI_Cfg const * const Arg_conf_cpcSPI_Cfg, u16 Arg_data_u16)**

  **Explanation:**

  This function transmits 16-bit data using SPI.

  **Parameters**

  - Arg_conf_cpcDMA_Cfg 	: struct that have configured parameters.
  - Arg_data_u16             : Data that will be transmitted using SPI.
  **Return value**

    None


- **void SPI_ChangeDataFrameFormatTo16Bit_v(SPI_Cfg const * const Arg_conf_cpcSPI_Cfg)**

  **Explanation:**

 This function changes spi to transmit/receive 16-bit

  **Parameters**

  - Arg_conf_cpcDMA_Cfg 	: struct that have configured parameters.
  **Return value**

    None

- **void SPI_ChangeDataFrameFormatTo8Bit_v(SPI_Cfg const * const Arg_conf_cpcSPI_Cfg)**

  **Explanation:**

 This function changes spi to transmit/receive 8-bit

  **Parameters**

  - Arg_conf_cpcDMA_Cfg 	: struct that have configured parameters.
  **Return value**

    None

- **Bool SPI_IsEnabled_Bool(SPI_Cfg const * const Arg_conf_cpcSPI_Cfg)**

  **Explanation:**

 This function checks whether SPI is enabled or not

  **Parameters**

  - Arg_conf_cpcDMA_Cfg 	: struct that have configured parameters.
  **Return value**

    SPI enable/disabled status.

- **u8 SPI_SendAndReceive_u8(SPI_Cfg const * const Arg_conf_cpcSPI_Cfg, u8 Arg_data_u8)**

  **Explanation:**

 This function transmits and receives 8-bit data

  **Parameters**

  - Arg_conf_cpcDMA_Cfg 	: struct that have configured parameters.
  - Arg_data_u8             : Data that will be transmitted.
  **Return value**

    Data that will be received.

- **u16 SPI_SendAndReceive_u16(SPI_Cfg const * const Arg_conf_cpcSPI_Cfg, u16 Arg_data_u16)**

  **Explanation:**

 This function transmits and receives 16-bit data

  **Parameters**

  - Arg_conf_cpcDMA_Cfg 	: struct that have configured parameters.
  - Arg_data_u16            : Data that will be transmitted.
  **Return value**

    Data that will be received.

- **void SPI_EnableSPI_v(SPI_Cfg const * const Arg_conf_cpcSPI_Cfg)**

  **Explanation:**

 Enable SPI

  **Parameters**

  - Arg_conf_cpcDMA_Cfg 	: struct that have configured parameters.

  **Return value**

    None

- **void SPI_DisableSPI_v(SPI_Cfg const * const Arg_conf_cpcSPI_Cfg)**

  **Explanation:**

 Disable SPI

  **Parameters**

  - Arg_conf_cpcDMA_Cfg 	: struct that have configured parameters.

  **Return value**

    None

