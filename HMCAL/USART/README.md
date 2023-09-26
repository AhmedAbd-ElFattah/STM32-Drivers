# Universal Synchronous and Asynchronous Receiver-Transmitter (USART) module
USART (Universal Synchronous/Asynchronous Receiver Transmitter) is a communication interface commonly used in microcontrollers, including those in the STM32 family. It provides a versatile way to transmit and receive data between a microcontroller and external devices or other microcontrollers.


## Table of Contents
- [API Reference](#api-reference)

## API Reference

- **void USART_Config_v(USART_Cfg const * const Arg_conf_cpcUSART_Cfg)**

	**Explanation** 

	This function configures USART based on configuration passed through USART_Cfg struct.
	
	**Parameters**
	
	Arg_conf_cpcUSART_Cfg : It takes the bus id of the peripheral e.g RCC_AHB1, RCC_AHB2

	**Return value** 

	None


- **void USART_EnableUSART_v(USART_Cfg const * const Arg_conf_cpcUSART_Cfg)**

	**Explanation** 

	This function start USART transmission data
	
	**Parameters**
	
	Arg_conf_cpcUSART_Cfg : Struct to know intended USART

	**Return value** 

	None

- **USART_DisableUSART_v**

	**Explanation** 

	This function stop USART transmission data.
	
	**Parameters**
	
	Arg_conf_cpcUSART_Cfg : Struct to know intended USART.

	**Return value** 

	None

- **u8 USART_ReceiveU8Pooling_u8(USART_Cfg const * const Arg_conf_cpcUSART_Cfg, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32)**

	**Explanation** 

	This function receives data of 1-byte.
	
	**Parameters**
	
	Arg_conf_cpcUSART_Cfg: Struct to know intended USART.
    Arg_ToutVal_Cu32	 : Timeout value of received data. For infinite time, pass STD_MAX_DELAY.
    Arg_ToutErr_pCu32	 : To determine whether received data is complete or exceed timeout value.

	**Return value** 

	Received data

- **u16 USART_ReceiveU16Pooling_u16(USART_Cfg const * const Arg_conf_cpcUSART_Cfg, const STD_EndianType Arg_EndianMode_STD_EndianType, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32)**

	**Explanation** 

	This function receives data of 2-bytes.
	
	**Parameters**
	
	Arg_conf_cpcUSART_Cfg         : Struct to know intended USART.
    Arg_EndianMode_STD_EndianType : Select whether it's bigger (STD_BigEndian) or little (STD_LittleEndian) endian mode
    Arg_ToutVal_Cu32	          : Timeout value of received data. For infinite time, pass STD_MAX_DELAY.
    Arg_ToutErr_pCu32	          : To determine whether received data is complete or exceed timeout value.

	**Return value** 

	Received data

- **u32 USART_ReceiveU32Pooling_u32(USART_Cfg const * const Arg_conf_cpcUSART_Cfg, const STD_EndianType Arg_EndianMode_STD_EndianType, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32)**

	**Explanation** 

	This function receives data of 4-bytes.
	
	**Parameters**
	
	Arg_conf_cpcUSART_Cfg         : Struct to know intended USART.
    Arg_EndianMode_STD_EndianType : Select whether it's bigger (STD_BigEndian) or little (STD_LittleEndian) endian mode
    Arg_ToutVal_Cu32	          : Timeout value of received data. For infinite time, pass STD_MAX_DELAY.
    Arg_ToutErr_pCu32	          : To determine whether received data is complete or exceed timeout value.

	**Return value** 

	Received data

- **u64 USART_ReceiveU16Pooling_u64(USART_Cfg const * const Arg_conf_cpcUSART_Cfg, const STD_EndianType Arg_EndianMode_STD_EndianType, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32)**

	**Explanation** 

	This function receives data of 8-bytes.
	
	**Parameters**
	
	Arg_conf_cpcUSART_Cfg         : Struct to know intended USART.
    Arg_EndianMode_STD_EndianType : Select whether it's bigger (STD_BigEndian) or little (STD_LittleEndian) endian mode
    Arg_ToutVal_Cu32	          : Timeout value of received data. For infinite time, pass STD_MAX_DELAY.
    Arg_ToutErr_pCu32	          : To determine whether received data is complete or exceed timeout value.

	**Return value** 

	Received data

- **void USART_ReceiveU8ArrayPooling_v(USART_Cfg const * const Arg_conf_cpcUSART_Cfg, u8 *Arg_Arr_pu8, u32 Arg_ArrLen_u32, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32)**

	**Explanation** 

	This function stores 1-byte received data in an array
	
	**Parameters**
	
	Arg_conf_cpcUSART_Cfg : Struct to know intended USART.                                         
    Arg_Arr_pu8			  : Address of array.                                                      
    Arg_ArrLen_u32		  : Array length.                                                          
    Arg_ToutVal_Cu32	  : Timeout value of received data. For infinite time, pass STD_MAX_DELAY. 
    Arg_ToutErr_pCu32	  : To determine whether received data is complete or exceed timeout value.

	**Return value** 

	None

- **void USART_ReceiveU16ArrayPooling_v(USART_Cfg const * const Arg_conf_cpcUSART_Cfg, u16 *Arg_Arr_pu16, u32 Arg_ArrLen_u16, const STD_EndianType Arg_EndianMode_STD_EndianType, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32)**

	**Explanation** 

	This function stores 2-bytes received data in an array.
	
	**Parameters**
	
	Arg_conf_cpcUSART_Cfg 		 : Struct to know intended USART.                                                      
    Arg_Arr_pu16				 : Address of array.                                                                   
    Arg_ArrLen_u32				 : Array length.                                                                       
    Arg_EndianMode_STD_EndianType: Select whether it's bigger (STD_BigEndian) or little (STD_LittleEndian) endian mode.
    Arg_ToutVal_Cu32		 	 :Timeout value of received data. For infinite time, pass STD_MAX_DELAY.              
    Arg_ToutErr_pCu32	 		 :To determine whether received data is complete or exceed timeout value.             

	**Return value** 

	None

- **void USART_ReceiveU32ArrayPooling_v(USART_Cfg const * const Arg_conf_cpcUSART_Cfg, u32 *Arg_Arr_pu32, u32 Arg_ArrLen_u16, const STD_EndianType Arg_EndianMode_STD_EndianType, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32)**

	**Explanation** 

	This function stores 4-bytes received data in an array.
	
	**Parameters**
	
	Arg_conf_cpcUSART_Cfg 		 : Struct to know intended USART.                                                      
    Arg_Arr_pu32				 : Address of array.                                                                   
    Arg_ArrLen_u32				 : Array length.                                                                       
    Arg_EndianMode_STD_EndianType: Select whether it's bigger (STD_BigEndian) or little (STD_LittleEndian) endian mode.
    Arg_ToutVal_Cu32		 	 :Timeout value of received data. For infinite time, pass STD_MAX_DELAY.              
    Arg_ToutErr_pCu32	 		 :To determine whether received data is complete or exceed timeout value.             

	**Return value** 

	None

- **void USART_ReceiveU64ArrayPooling_v(USART_Cfg const * const Arg_conf_cpcUSART_Cfg, u32 *Arg_Arr_pu64, u32 Arg_ArrLen_u16, const STD_EndianType Arg_EndianMode_STD_EndianType, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32)**

	**Explanation** 

	This function stores 4-bytes received data in an array.
	
	**Parameters**
	
	Arg_conf_cpcUSART_Cfg 		 : Struct to know intended USART.                                                      
    Arg_Arr_pu64				 : Address of array.                                                                   
    Arg_ArrLen_u32				 : Array length.                                                                       
    Arg_EndianMode_STD_EndianType: Select whether it's bigger (STD_BigEndian) or little (STD_LittleEndian) endian mode.
    Arg_ToutVal_Cu32		 	 :Timeout value of received data. For infinite time, pass STD_MAX_DELAY.              
    Arg_ToutErr_pCu32	 		 :To determine whether received data is complete or exceed timeout value.             

	**Return value** 

	None

- **void USART_SendU8Pooling_v(USART_Cfg const * const Arg_conf_cpcUSART_Cfg, u8 Arg_Data_u8, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32)**

	**Explanation** 

	This function send data of 1-byte
	
	**Parameters**
	
	Arg_conf_cpcUSART_Cfg :Struct to know intended USART.                                         
    Arg_Data_u8			  :Data that will be sent.                                                
    Arg_ToutVal_Cu32	  :Timeout value of received data. For infinite time, pass STD_MAX_DELAY. 
    Arg_ToutErr_pCu32	  :To determine whether received data is complete or exceed timeout value.

	**Return value** 

	None

- **void USART_SendU16Pooling_v(USART_Cfg const * const Arg_conf_cpcUSART_Cfg, u16 Arg_Data_u16, const STD_EndianType Arg_EndianMode_STD_EndianType, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32)**

	**Explanation** 

	This function send data of 2-bytes.
	
	**Parameters**
	
	Arg_conf_cpcUSART_Cfg 		  : Struct to know intended USART.                                                      
    Arg_Data_u16			 	  : Data that will be sent.                                                             
    Arg_EndianMode_STD_EndianType : Select whether it's bigger (STD_BigEndian) or little (STD_LittleEndian) endian mode.
    Arg_ToutVal_Cu32		 	  : Timeout value of received data. For infinite time, pass STD_MAX_DELAY.              
    Arg_ToutErr_pCu32	 		  : To determine whether received data is complete or exceed timeout value.             

	**Return value** 

	None

- **void USART_SendU32Pooling_v(USART_Cfg const * const Arg_conf_cpcUSART_Cfg, u32 Arg_Data_u32, const STD_EndianType Arg_EndianMode_STD_EndianType, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32)**

	**Explanation** 

	This function send data of 4-bytes.
	
	**Parameters**
	
	Arg_conf_cpcUSART_Cfg 		  : Struct to know intended USART.                                                      
    Arg_Data_u32			 	  : Data that will be sent.                                                             
    Arg_EndianMode_STD_EndianType : Select whether it's bigger (STD_BigEndian) or little (STD_LittleEndian) endian mode.
    Arg_ToutVal_Cu32		 	  : Timeout value of received data. For infinite time, pass STD_MAX_DELAY.              
    Arg_ToutErr_pCu32	 		  : To determine whether received data is complete or exceed timeout value.             

	**Return value** 

	None

- **void USART_SendU64Pooling_v(USART_Cfg const * const Arg_conf_cpcUSART_Cfg, u64 Arg_Data_u64, const STD_EndianType Arg_EndianMode_STD_EndianType, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32)**

	**Explanation** 

	This function send data of 8-bytes.
	
	**Parameters**
	
	Arg_conf_cpcUSART_Cfg 		  : Struct to know intended USART.                                                      
    Arg_Data_u64			 	  : Data that will be sent.                                                             
    Arg_EndianMode_STD_EndianType : Select whether it's bigger (STD_BigEndian) or little (STD_LittleEndian) endian mode.
    Arg_ToutVal_Cu32		 	  : Timeout value of received data. For infinite time, pass STD_MAX_DELAY.              
    Arg_ToutErr_pCu32	 		  : To determine whether received data is complete or exceed timeout value.             

	**Return value** 

	None

- **void USART_SendU8ArrayPooling_v(USART_Cfg const * const Arg_conf_cpcUSART_Cfg, u8 *Arg_Arr_pu8, u32 Arg_ArrLen_u32, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32)**

	**Explanation** 

	This function send array of 1-byte data.
	
	**Parameters**
	
	Arg_conf_cpcUSART_Cfg : Struct to know intended USART.                                         
    Arg_Arr_pu8			  : Array of Data that will be sent.                                       
    Arg_ArrLen_u32 		  : Array length.                                                          
    Arg_ToutVal_Cu32	  : Timeout value of received data. For infinite time, pass STD_MAX_DELAY. 
    Arg_ToutErr_pCu32	  : To determine whether received data is complete or exceed timeout value.

	**Return value** 

	None

- **void USART_SendU16ArrayPooling_v(USART_Cfg const * const Arg_conf_cpcUSART_Cfg, u16 *Arg_Arr_pu16, u32 Arg_ArrLen_u32, const STD_EndianType Arg_EndianMode_STD_EndianType, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32)**

	**Explanation** 

	This function send array of 2-bytes data.
	
	**Parameters**
	
	Arg_conf_cpcUSART_Cfg 		 : Struct to know intended USART.                                                      
    Arg_Arr_pu16			 	 : Array of Data that will be sent.                                                    
    Arg_ArrLen_u32 				 : Array length.                                                                       
    Arg_EndianMode_STD_EndianType: Select whether it's bigger (STD_BigEndian) or little (STD_LittleEndian) endian mode.
    Arg_ToutVal_Cu32		 	 : Timeout value of received data. For infinite time, pass STD_MAX_DELAY.
    Arg_ToutErr_pCu32	 		 : To determine whether received data is complete or exceed timeout value.

	**Return value** 

	None

- **void USART_SendU32ArrayPooling_v(USART_Cfg const * const Arg_conf_cpcUSART_Cfg, u32 *Arg_Arr_pu32, u32 Arg_ArrLen_u32, const STD_EndianType Arg_EndianMode_STD_EndianType, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32)**

	**Explanation** 

	This function send array of 4-bytes data.
	
	**Parameters**
	
	Arg_conf_cpcUSART_Cfg 		 : Struct to know intended USART.                                                      
    Arg_Arr_pu32			 	 : Array of Data that will be sent.                                                    
    Arg_ArrLen_u32 				 : Array length.                                                                       
    Arg_EndianMode_STD_EndianType: Select whether it's bigger (STD_BigEndian) or little (STD_LittleEndian) endian mode.
    Arg_ToutVal_Cu32		 	 : Timeout value of received data. For infinite time, pass STD_MAX_DELAY.
    Arg_ToutErr_pCu32	 		 : To determine whether received data is complete or exceed timeout value.

	**Return value** 

	None


- **void USART_SendU64ArrayPooling_v(USART_Cfg const * const Arg_conf_cpcUSART_Cfg, u32 *Arg_Arr_pu64, u32 Arg_ArrLen_u32, const STD_EndianType Arg_EndianMode_STD_EndianType, const u32 Arg_ToutVal_Cu32, u32 * const Arg_ToutErr_pCu32)**

	**Explanation** 

	This function send array of 8-bytes data.
	
	**Parameters**
	
	Arg_conf_cpcUSART_Cfg 		 : Struct to know intended USART.                                                      
    Arg_Arr_pu64			 	 : Array of Data that will be sent.                                                    
    Arg_ArrLen_u32 				 : Array length.                                                                       
    Arg_EndianMode_STD_EndianType: Select whether it's bigger (STD_BigEndian) or little (STD_LittleEndian) endian mode.
    Arg_ToutVal_Cu32		 	 : Timeout value of received data. For infinite time, pass STD_MAX_DELAY.
    Arg_ToutErr_pCu32	 		 : To determine whether received data is complete or exceed timeout value.

	**Return value** 

	None


- **u32 USART_GetAdressForDMA_u32(USART_Cfg const * const Arg_conf_cpcUSART_Cfg)**

	**Explanation** 

	This function gets the address which used with DMA.
	
	**Parameters**
	
	Arg_conf_cpcUSART_Cfg : Struct to know intended USART.

	**Return value** 

	Address of Data register USART .


- **u8 USART_ReceiveU8Interrupt_u8(USART_Cfg const * const Arg_conf_cpcUSART_Cfg)**

	**Explanation** 

	This function is used by interrupt callback to get received data from interrupt callback only!
	
	**Parameters**
	
	Arg_conf_cpcUSART_Cfg : Instance id of USART that you need to check about it.

	**Return value** 

	Received data


- **void USART_Reset_v (USART_Cfg const * const Arg_conf_cpcUSART_Cfg)**

	**Explanation** 

	This function resets USART to it's default configurations
	
	**Parameters**
	
	Arg_conf_cpcUSART_Cfg : struct that have configured parameters.

	**Return value** 

	None