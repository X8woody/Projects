/*====================Includes========================*/

#include "MAlarm.h"

/*====================Macros========================*/



/*====================Type_Definitions========================*/



/*====================Global_Variables========================*/

void (*Monitor_Status)();

/*====================Functions========================*/
void Wait_Status ()
{
	Monitor_Status = High_pressure_detect;
}

void LDelay(int nCount)
{
	nCount = nCount * 5000;
	for(; nCount != 0; nCount--);
}

void High_pressure_detect()
{
	Set_Alarm_actuator(ON);
	LDelay(Per_Time);
	Set_Alarm_actuator(OFF);
	Monitor_Status = Wait_Status;
}

/*===============================================================*/