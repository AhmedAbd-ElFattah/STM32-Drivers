```c
#include "HAL/DCMotor/DCMotor.h"

int main(void)
{
	DCMotor_Cfg L_DCMotorExample_DCMotor_Cfg = {0};
	L_DCMotorExample_DCMotor_Cfg.AutoReloadValue = 999;
	L_DCMotorExample_DCMotor_Cfg.Channel = 1;
	L_DCMotorExample_DCMotor_Cfg.GPIOInstanceId = 'A';
	L_DCMotorExample_DCMotor_Cfg.PINId = 2;
	L_DCMotorExample_DCMotor_Cfg.Prescaler = 15;
	L_DCMotorExample_DCMotor_Cfg.TimerInstanceId=9;


	L_DCMotorExample_DCMotor_Cfg.GPIO_ClockWise = 'C';
	L_DCMotorExample_DCMotor_Cfg.GPIO_CounterClockWise = 'C';

	L_DCMotorExample_DCMotor_Cfg.PIN_ClockWise = PIN_1_MASK;
	L_DCMotorExample_DCMotor_Cfg.PIN_CounterClockWise = PIN_3_MASK;


	DCMotor_Config_v(&L_DCMotorExample_DCMotor_Cfg);

	L_DCMotorExample_DCMotor_Cfg.SpeedInPercentage = 23;
	DCMotor_ChangeSpeed_v(&L_DCMotorExample_DCMotor_Cfg);

	DCMotor_SetDirectionToClockWise_v(&L_DCMotorExample_DCMotor_Cfg);
	DCMotor_SetDirectionToCounterClockWise_v(&L_DCMotorExample_DCMotor_Cfg);

	DCMotor_StopMotor_v(&L_DCMotorExample_DCMotor_Cfg);
	while(1){


	}
}

```