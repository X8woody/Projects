#ifndef MALARM__H
#define MALARM__H
/*====================Includes========================*/

#include "DLink.h"

/*====================Macros========================*/

#define Per_Time  60

/*====================Type_Definitions========================*/

typedef enum 
{
	ON,
	OFF
}LED_REQ;

/*====================Global_Variables========================*/

extern void (*Monitor_Status)();

/*====================ProtoTypes========================*/

void LDelay(int nCount);
void Wait_Status ();
void Set_Alarm_actuator(int i);

/*====================MAIN_APPLICATION========================*/



/*====================Functions========================*/



/*===============================================================*/
#endif 
/*===============================================================*/