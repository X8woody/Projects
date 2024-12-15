/*====================Includes========================*/

#include "MAlarm.h"
#include "HPD.h"
#include "LED_S.h"

/*====================Macros========================*/

#define threshold_pressure     20

/*====================Type_Definitions========================*/



/*====================Global_Variables========================*/

extern int pVAL; 

/*====================ProtoTypes========================*/



/*====================MAIN_APPLICATION========================*/



/*====================Functions========================*/

void setup()
{
	Monitor_Status     = Wait_Status;
	LED_Status         = GPIO_INITIALIZATION;
	PressureSen_Status = init_PressureSens;
	LED_Status();
	PressureSen_Status();
}


int main()
{
	setup();
	while (1)
	{
		PressureSen_Status();
		if (pVAL > threshold_pressure)
		{
			Monitor_Status = High_pressure_detect;
		}
		else
		{
			Monitor_Status = Wait_Status;
		}
		Monitor_Status();
	}
	return 0;
}

/*===============================================================*/