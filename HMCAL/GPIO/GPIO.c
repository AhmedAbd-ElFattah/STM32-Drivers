/*
 * File Name --> GPIO.c
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 * Brief	 --> GPIO driver implementation.
 * */


/*
==================================================
  Start Section --> File Includes
==================================================
 */
#include "GPIO.h"
#include "HMCAL/RCC/RCC.h"
#include "GPIO_Private.h"
/*
==================================================
  End   Section --> File Includes
==================================================
 */

/*
==================================================
  Start Section --> Macro to map Instance Id with it's physical address.
==================================================
 */
#define GPIO_ID(id) ((volatile GPIO_MemMap*const)(GCS_GPIO_InstanceIdMapping_u32[((id))]))
/*
==================================================
  End   Section --> Macro to map Instance Id with it's physical address.
==================================================
 */



/*
==================================================
  Start Section --> Functions implementation.
==================================================
 */

void GPIO_Config_v(GPIO_Cfg const * const Arg_conf_cpcGPIO_Cfg){
	/*
	 * Convert input range if instance id from {a-z} or {A-Z} to {0-Max number of GPIO defined peripherals}
	 * Target of this process is to get peripheral using user-friendly convention.
	 * For example instead of using GPIOA in APP/HAL layer, we decided to use 'A' or 'a'
	 * */

	/*Read input id from user.*/
	u8 L_GPIOid_u8 = Arg_conf_cpcGPIO_Cfg->InstanceId;
	/*
	 * GPIOA will have index 0 in L_GPIOid_u8 array
	 * So the following process check for the boundary of input value
	 * If input id exceeds the boundary an error will be issued.
	 * */
	if (('A' <= L_GPIOid_u8 ) && (L_GPIOid_u8 <= 'Z')){
		L_GPIOid_u8 -= 'A';
	}
	else if (('a' <= L_GPIOid_u8 ) && (L_GPIOid_u8 <= 'z')){
		L_GPIOid_u8 -= 'a';
	}
	else{
		/*Error*/

	}

	/*
	 * To reduce the headache on user of enabling clock of the used peripheral.
	 * It 's automatically enabled before configuring the peripheral.
	 * */
	RCC_EnableClock_v(
			RCC_GetPeripheralBus_u8((u32)GPIO_ID(L_GPIOid_u8)),
			RCC_GetRCCGPIOBit_u8(L_GPIOid_u8+1));


	/*
	 * Read PINs in the masked format for example
	 * when we assign the value 0b0101
	 * pin 0 & 2 have the value of enabled attributes.
	 * pin 1 & 3 have the value of disabled attributes.
	 * */

	u16 L_PINsMask_u16 = Arg_conf_cpcGPIO_Cfg->PINs;
	/* Some registers for configuration assign 2 bits to than same pin
	 * to have more options for configuration
	 * for example if input is 0x0101
	 * the following loop assign value 0x00110011
	 * the first 2 bits(LSB) for pin 0
	 * the second 2 bits (LSB) bit 0 & bit 1 for pin 1
	 * */
	u32 L_PINsMask_u32 = 0;
	for (u8 L_i_u8 =0; L_i_u8<16; L_i_u8++){
		if (STD_TRUE == GET_BIT(L_PINsMask_u16, L_i_u8)){
			L_PINsMask_u32 |= (0b11<<(L_i_u8*2));
		}
	}

	/*Configure Pin mode
	 * It can have the following modes
	 * Input
	 * Output
	 * Alternate Function which used to map pin for USART/SPI for example
	 * Analog this mode is used wither for input(ADC)/output(DAC) Analog signal
	 *
	 *
	 * To configure input mode for PINs --> GPIO_Mode_INPUT
	 * To configure output mode for PINs --> GPIO_Mode_OUTPUT
	 * To configure Alternate Function mode for PINs --> GPIO_Mode_Alternate_Function
	 * To configure Analog Mode for PINs --> GPIO_Mode_Analog
	 * */
	u32 L_MODERVal_u32 = GPIO_ID(L_GPIOid_u8)->MODER;
	switch (Arg_conf_cpcGPIO_Cfg->Mode){
	case GPIO_MODE_INPUT:
		L_MODERVal_u32 |= 0x00u & L_PINsMask_u32;
		L_MODERVal_u32 &= ~(~0x00u & L_PINsMask_u32);
		break;
	case GPIO_MODE_OUTPUT:
		L_MODERVal_u32 |= 0x55555555 & L_PINsMask_u32;
		L_MODERVal_u32 &= ~(~0x55555555 & L_PINsMask_u32);
		break;
	case GPIO_MODE_ALTERNATE_FUNCTION:
		L_MODERVal_u32 |= 0xAAAAAAAAu & L_PINsMask_u32;
		L_MODERVal_u32 &= ~(~0xAAAAAAAAu & L_PINsMask_u32);
		break;
	case GPIO_MODE_ANALOG:
		L_MODERVal_u32 |= 0xFFFFFFFFu & L_PINsMask_u32;
		L_MODERVal_u32 &= ~(~0xFFFFFFFFu & L_PINsMask_u32);
		break;
	default :
		/*Error*/
		break;
	}
	GPIO_ID(L_GPIOid_u8)->MODER = L_MODERVal_u32;
	/* Configure the output type of Pins
	 * either Push Pull can be configured by assigned OutputType with macro GPIO_Output_Type_Push_Pull
	 * or Open Drain can be configured by assigned OutputType with macro GPIO_Output_Type_Open_Drain
	 * */

	switch (Arg_conf_cpcGPIO_Cfg->OutputType){
	case GPIO_OUTPUT_TYPE_PUSH_PULL:
		GPIO_ID(L_GPIOid_u8)->OTYPER &= ~(~0x00 & L_PINsMask_u16);
		break;
	case GPIO_OUTPUT_TYPE_OPEN_DRAIN:
		GPIO_ID(L_GPIOid_u8)->OTYPER |= 0xFFFF & L_PINsMask_u16;
		break;
	default :
		/*Error*/
		break;
	}
	/* Configure output speed (higher speed higher slew rate) of selected pins.
	 * Can have the following options
	 * GPIO_Output_Speed_Low ,GPIO_Output_Speed_Medium, GPIO_Output_Speed_Fast, or GPIO_Output_Speed_High
	 * */
	switch (Arg_conf_cpcGPIO_Cfg->OutputSpeed){
	case GPIO_OUTPUT_SPEED_LOW:
		GPIO_ID(L_GPIOid_u8)->OSPEEDER &= ~(0x00u &L_PINsMask_u32);
		break;
	case GPIO_OUTPUT_SPEED_MEDIUM:
		GPIO_ID(L_GPIOid_u8)->OSPEEDER &= ~(0x55555555u &L_PINsMask_u32);
		GPIO_ID(L_GPIOid_u8)->OSPEEDER |= (0x55555555u &L_PINsMask_u32);
		break;

	case GPIO_OUTPUT_SPEED_FAST:
		GPIO_ID(L_GPIOid_u8)->OSPEEDER &= ~(0xAAAAAAAAu &L_PINsMask_u32);
		GPIO_ID(L_GPIOid_u8)->OSPEEDER |= (0xAAAAAAAAu &L_PINsMask_u32);
		break;
	case GPIO_OUTPUT_SPEED_HIGH:
		GPIO_ID(L_GPIOid_u8)->OSPEEDER |= (0xFFFFFFFFu & L_PINsMask_u32);
		break;
	default :
		/*Error*/
		break;
	}

	/* Configure the type of pulled resistors of selected pins.
	 * Can have the following options
	 * GPIO_Resistor_No_Pull ,GPIO_Resistor_Pull_Up, or GPIO_Resistor_Pull_Down
	 * */
	switch (Arg_conf_cpcGPIO_Cfg->PullUpPullDownResistor){
	case GPIO_RESISTOR_NO_PULL:
		GPIO_ID(L_GPIOid_u8)->PUPDR &= ~(0x00 &L_PINsMask_u32);
		break;
	case GPIO_RESISTOR_PULL_UP:
		GPIO_ID(L_GPIOid_u8)->PUPDR &= ~(0x55555555u &L_PINsMask_u32);
		GPIO_ID(L_GPIOid_u8)->PUPDR |= (0x55555555u &L_PINsMask_u32);
		break;
	case GPIO_RESISTOR_PULL_DOWN:
		GPIO_ID(L_GPIOid_u8)->PUPDR &= ~(0xAAAAAAAAu &L_PINsMask_u32);
		GPIO_ID(L_GPIOid_u8)->PUPDR |= (0xAAAAAAAAu &L_PINsMask_u32);
		break;
	default :
		/*Error*/
		break;
	}

}



void GPIO_PinWrite_v(GPIO_Cfg const * const Arg_conf_cpcGPIO_Cfg, const u8 Arg_PIN_Cu8, const u8 Arg_Value_Cu8){
	/*
	 * Convert input range if instance id from {a-z} or {A-Z} to {0-Max number of GPIO defined peripherals}
	 * Target of this process is to get peripheral using user-friendly convention.
	 * For example instead of using GPIOA in APP/HAL layer, we decided to use 'A' or 'a'
	 * */

	/*Read input id from user.*/
	u8 L_GPIOid_u8 = Arg_conf_cpcGPIO_Cfg->InstanceId;
	/*
	 * GPIOA will have index 0 in L_GPIOid_u8 array
	 * So the following process check for the boundary of input value
	 * If input id exceeds the boundary an error will be issued.
	 * */
	if (('A' <= Arg_conf_cpcGPIO_Cfg->InstanceId ) && (Arg_conf_cpcGPIO_Cfg->InstanceId <= 'Z')){
		L_GPIOid_u8 -= 'A';
	}
	else if (('a' <= Arg_conf_cpcGPIO_Cfg->InstanceId ) && (Arg_conf_cpcGPIO_Cfg->InstanceId <= 'z')){
		L_GPIOid_u8 -= 'a';
	}
	else{
		/*Error*/
	}

	/*
	 * Lower 16 bit of BSRR sets pin
	 * for example to set pin number 5
	 * set BSRR bit number 5
	 *
	 * Higher 16 bit of BSRR reset pin
	 * for example to reset pin number 5
	 * set BSRR bit number 5+16 --> bit number 21
	 * */
	switch (Arg_Value_Cu8){
	case STD_HIGH:
		GPIO_ID(L_GPIOid_u8)->BSRR = 1<<Arg_PIN_Cu8;
		break;
	case STD_LOW:
		GPIO_ID(L_GPIOid_u8)->BSRR = (1<<(Arg_PIN_Cu8+16));
		break;
	default:
		/*Error*/
		break;
	}

}


void GPIO_PORTWrite_v(GPIO_Cfg const * const Arg_conf_cpcGPIO_Cfg, const u8 Arg_Value_Cu8){
	/*
	 * Convert input range if instance id from {a-z} or {A-Z} to {0-Max number of GPIO defined peripherals}
	 * Target of this process is to get peripheral using user-friendly convention.
	 * For example instead of using GPIOA in APP/HAL layer, we decided to use 'A' or 'a'
	 * */

	/*Read input id from user.*/
	u8 L_GPIOid_u8 = Arg_conf_cpcGPIO_Cfg->InstanceId;
	/*
	 * GPIOA will have index 0 in L_GPIOid_u8 array
	 * So the following process check for the boundary of input value
	 * If input id exceeds the boundary an error will be issued.
	 * */
	if (('A' <= Arg_conf_cpcGPIO_Cfg->InstanceId ) && (Arg_conf_cpcGPIO_Cfg->InstanceId <= 'Z')){
		L_GPIOid_u8 -= 'A';
	}
	else if (('a' <= Arg_conf_cpcGPIO_Cfg->InstanceId ) && (Arg_conf_cpcGPIO_Cfg->InstanceId <= 'z')){
		L_GPIOid_u8 -= 'a';
	}
	else{
		/*Error*/
	}

	if (Arg_Value_Cu8 == STD_HIGH){
		GPIO_ID(L_GPIOid_u8)->ODR = 0xFFFF;
	}
	else if (Arg_Value_Cu8 == STD_LOW){
		GPIO_ID(L_GPIOid_u8)->ODR = 0;
	}
	else{

	}
}



void GPIO_PORTMaskedWrite_v(GPIO_Cfg const * const Arg_conf_cpcGPIO_Cfg, const u16 Arg_Value_Cu16){
	/*
	 * Convert input range if instance id from {a-z} or {A-Z} to {0-Max number of GPIO defined peripherals}
	 * Target of this process is to get peripheral using user-friendly convention.
	 * For example instead of using GPIOA in APP/HAL layer, we decided to use 'A' or 'a'
	 * */

	/*Read input id from user.*/
	u8 L_GPIOid_u8 = Arg_conf_cpcGPIO_Cfg->InstanceId;
	/*
	 * GPIOA will have index 0 in L_GPIOid_u8 array
	 * So the following process check for the boundary of input value
	 * If input id exceeds the boundary an error will be issued.
	 * */
	if (('A' <= Arg_conf_cpcGPIO_Cfg->InstanceId ) && (Arg_conf_cpcGPIO_Cfg->InstanceId <= 'Z')){
		L_GPIOid_u8 -= 'A';
	}
	else if (('a' <= Arg_conf_cpcGPIO_Cfg->InstanceId ) && (Arg_conf_cpcGPIO_Cfg->InstanceId <= 'z')){
		L_GPIOid_u8 -= 'a';
	}
	else{
		/*Error*/
	}

	u32 L_value_u32 = (Arg_Value_Cu16 & Arg_conf_cpcGPIO_Cfg->PINs);
	L_value_u32 |= (((~Arg_Value_Cu16)& Arg_conf_cpcGPIO_Cfg->PINs) <<16);
	GPIO_ID(L_GPIOid_u8)->BSRR = L_value_u32;
}


u8 GPIO_PinRead_u8(GPIO_Cfg const * const Arg_conf_cpcGPIO_Cfg, const u8 Arg_PIN_Cu8)
{
	/*
	 * Convert input range if instance id from {a-z} or {A-Z} to {0-Max number of GPIO defined peripherals}
	 * Target of this process is to get peripheral using user-friendly convention.
	 * For example instead of using GPIOA in APP/HAL layer, we decided to use 'A' or 'a'
	 * */

	/*Read input id from user.*/
	u8 L_GPIOid_u8 = Arg_conf_cpcGPIO_Cfg->InstanceId;
	/*
	 * GPIOA will have index 0 in L_GPIOid_u8 array
	 * So the following process check for the boundary of input value
	 * If input id exceeds the boundary an error will be issued.
	 * */
	if (('A' <= Arg_conf_cpcGPIO_Cfg->InstanceId ) && (Arg_conf_cpcGPIO_Cfg->InstanceId <= 'Z')){
		L_GPIOid_u8 -= 'A';
	}
	else if (('a' <= Arg_conf_cpcGPIO_Cfg->InstanceId ) && (Arg_conf_cpcGPIO_Cfg->InstanceId <= 'z')){
		L_GPIOid_u8 -= 'a';
	}
	else{
		/*Error*/
	}
	return GET_BIT(GPIO_ID(L_GPIOid_u8)->IDR, Arg_PIN_Cu8);
}

u16 GPIO_PORTRead_u16(GPIO_Cfg const * const Arg_conf_cpcGPIO_Cfg)
{
	/*
	 * Convert input range if instance id from {a-z} or {A-Z} to {0-Max number of GPIO defined peripherals}
	 * Target of this process is to get peripheral using user-friendly convention.
	 * For example instead of using GPIOA in APP/HAL layer, we decided to use 'A' or 'a'
	 * */

	/*Read input id from user.*/
	u8 L_GPIOid_u8 = Arg_conf_cpcGPIO_Cfg->InstanceId;
	/*
	 * GPIOA will have index 0 in L_GPIOid_u8 array
	 * So the following process check for the boundary of input value
	 * If input id exceeds the boundary an error will be issued.
	 * */
	if (('A' <= Arg_conf_cpcGPIO_Cfg->InstanceId ) && (Arg_conf_cpcGPIO_Cfg->InstanceId <= 'Z')){
		L_GPIOid_u8 -= 'A';
	}
	else if (('a' <= Arg_conf_cpcGPIO_Cfg->InstanceId ) && (Arg_conf_cpcGPIO_Cfg->InstanceId <= 'z')){
		L_GPIOid_u8 -= 'a';
	}
	else{
		/*Error*/
	}
	return GPIO_ID(L_GPIOid_u8)->IDR;

}

u16 GPIO_PORTMaskedRead_u16(GPIO_Cfg const * const Arg_conf_cpcGPIO_Cfg)
{
	/*
	 * Convert input range if instance id from {a-z} or {A-Z} to {0-Max number of GPIO defined peripherals}
	 * Target of this process is to get peripheral using user-friendly convention.
	 * For example instead of using GPIOA in APP/HAL layer, we decided to use 'A' or 'a'
	 * */

	/*Read input id from user.*/
	u8 L_GPIOid_u8 = Arg_conf_cpcGPIO_Cfg->InstanceId;
	/*
	 * GPIOA will have index 0 in L_GPIOid_u8 array
	 * So the following process check for the boundary of input value
	 * If input id exceeds the boundary an error will be issued.
	 * */
	if (('A' <= Arg_conf_cpcGPIO_Cfg->InstanceId ) && (Arg_conf_cpcGPIO_Cfg->InstanceId <= 'Z')){
		L_GPIOid_u8 -= 'A';
	}
	else if (('a' <= Arg_conf_cpcGPIO_Cfg->InstanceId ) && (Arg_conf_cpcGPIO_Cfg->InstanceId <= 'z')){
		L_GPIOid_u8 -= 'a';
	}
	else{
		/*Error*/
	}
	return GPIO_ID(L_GPIOid_u8)->IDR & Arg_conf_cpcGPIO_Cfg->PINs;

}



void GPIO_MapGPIOPIN_v(GPIO_Cfg const * const Arg_conf_cpcGPIO_Cfg, const u8 Arg_PIN_Cu8, const u8 Arg_Peripheral_Cu8){

	/*Read input id from user.*/
	u8 L_GPIOid_u8 = Arg_conf_cpcGPIO_Cfg->InstanceId;
	/*
	 * GPIOA will have index 0 in L_GPIOid_u8 array
	 * So the following process check for the boundary of input value
	 * If input id exceeds the boundary an error will be issued.
	 * */
	if (('A' <= Arg_conf_cpcGPIO_Cfg->InstanceId ) && (Arg_conf_cpcGPIO_Cfg->InstanceId <= 'Z')){
		L_GPIOid_u8 -= 'A';
	}
	else if (('a' <= Arg_conf_cpcGPIO_Cfg->InstanceId ) && (Arg_conf_cpcGPIO_Cfg->InstanceId <= 'z')){
		L_GPIOid_u8 -= 'a';
	}
	else{
		/*Error*/
	}

	/*
	 * To reduce the headache on user of enabling clock of the used peripheral.
	 * It 's automatically enabled before configuring the peripheral.
	 * */
	RCC_EnableClock_v(
			RCC_GetPeripheralBus_u8((u32)GPIO_ID(L_GPIOid_u8)),
			RCC_GetRCCGPIOBit_u8(L_GPIOid_u8+1));

	if (Arg_PIN_Cu8 <= 7){
		GPIO_ID(L_GPIOid_u8)->AFRL |= (Arg_Peripheral_Cu8<<(4*Arg_PIN_Cu8)) ;
	}
	else{
		GPIO_ID(L_GPIOid_u8)->AFRH |= (Arg_Peripheral_Cu8<<(4*(Arg_PIN_Cu8%8))) ;
	}
}

void GPIO_Reset_v (GPIO_Cfg const * const Arg_conf_cpcGPIO_Cfg){
	GPIO_Cfg L_Reset_GPIO_Cfg = {0};
	L_Reset_GPIO_Cfg.InstanceId = Arg_conf_cpcGPIO_Cfg->InstanceId;
	L_Reset_GPIO_Cfg.PINs = Arg_conf_cpcGPIO_Cfg->PINs;
	GPIO_Config_v(&L_Reset_GPIO_Cfg);

	/*
	 * Convert input range if instance id from {a-z} or {A-Z} to {0-Max number of GPIO defined peripherals}
	 * Target of this process is to get peripheral using user-friendly convention.
	 * For example instead of using GPIOA in APP/HAL layer, we decided to use 'A' or 'a'
	 * */

	/*Read input id from user.*/
	u8 L_GPIOid_u8 = Arg_conf_cpcGPIO_Cfg->InstanceId;
	/*
	 * GPIOA will have index 0 in L_GPIOid_u8 array
	 * So the following process check for the boundary of input value
	 * If input id exceeds the boundary an error will be issued.
	 * */
	if (('A' <= L_GPIOid_u8 ) && (L_GPIOid_u8 <= 'Z')){
		L_GPIOid_u8 -= 'A';
	}
	else if (('a' <= L_GPIOid_u8 ) && (L_GPIOid_u8 <= 'z')){
		L_GPIOid_u8 -= 'a';
	}
	else{
		/*Error*/

	}

	for (u8 L_i_u8 = 0; L_i_u8<16; L_i_u8++){
		if (STD_TRUE == GET_BIT(Arg_conf_cpcGPIO_Cfg->PINs, L_i_u8)){
			GPIO_MapGPIOPIN_v(Arg_conf_cpcGPIO_Cfg, L_i_u8, 0);
		}
	}

}
/*
==================================================
  End   Section --> Functions implementation.
==================================================
 */
