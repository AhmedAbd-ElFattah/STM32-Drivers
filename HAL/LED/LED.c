/*
 * File Name --> LED.c
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HAL
 * Brief	 --> LED driver implementation.
 * */
/*
==================================================
  Start Section --> File Includes
==================================================
*/
#include "LED.h"
/*
==================================================
  End   Section --> File Includes
==================================================
*/

/*
==================================================
  Start Section --> Functions implementation.
==================================================
 */


void LED_Config_v(LED_Cfg *Arg_Config_pLED_Cfg){

	GPIO_Cfg L_led_GPIO_Cfg;
	L_led_GPIO_Cfg.InstanceId = Arg_Config_pLED_Cfg->GPIOInstanceId;
	L_led_GPIO_Cfg.Mode = GPIO_MODE_OUTPUT;
	L_led_GPIO_Cfg.OutputSpeed = GPIO_OUTPUT_SPEED_LOW;
	L_led_GPIO_Cfg.OutputType = GPIO_OUTPUT_TYPE_PUSH_PULL;
	L_led_GPIO_Cfg.PINs = Arg_Config_pLED_Cfg->Pin;
	L_led_GPIO_Cfg.PullUpPullDownResistor = GPIO_RESISTOR_NO_PULL;
	GPIO_Config_v(&L_led_GPIO_Cfg);
}
void LED_Reset_v(LED_Cfg *Arg_Config_pLED_Cfg){
	GPIO_Cfg L_led_GPIO_Cfg;
	L_led_GPIO_Cfg.InstanceId = Arg_Config_pLED_Cfg->GPIOInstanceId;
	L_led_GPIO_Cfg.Mode = GPIO_MODE_OUTPUT;
	L_led_GPIO_Cfg.OutputSpeed = GPIO_OUTPUT_SPEED_LOW;
	L_led_GPIO_Cfg.OutputType = GPIO_OUTPUT_TYPE_PUSH_PULL;
	L_led_GPIO_Cfg.PINs = Arg_Config_pLED_Cfg->Pin;
	L_led_GPIO_Cfg.PullUpPullDownResistor = GPIO_RESISTOR_NO_PULL;
	GPIO_Reset_v(&L_led_GPIO_Cfg);
}

void LED_TurnOn_v(LED_Cfg *Arg_Config_pLED_Cfg){
	GPIO_Cfg L_led_GPIO_Cfg;
	L_led_GPIO_Cfg.InstanceId = Arg_Config_pLED_Cfg->GPIOInstanceId;
	L_led_GPIO_Cfg.PINs = Arg_Config_pLED_Cfg->Pin;
	GPIO_PORTMaskedWrite_v(&L_led_GPIO_Cfg, 0xFFFF);
}

void LED_TurnOFF_v(LED_Cfg *Arg_Config_pLED_Cfg){
	GPIO_Cfg L_led_GPIO_Cfg;
	L_led_GPIO_Cfg.InstanceId = Arg_Config_pLED_Cfg->GPIOInstanceId;
	L_led_GPIO_Cfg.PINs = Arg_Config_pLED_Cfg->Pin;
	GPIO_PORTMaskedWrite_v(&L_led_GPIO_Cfg, 0x0000);
}

/*
==================================================
  End Section --> Functions implementation.
==================================================
 */

