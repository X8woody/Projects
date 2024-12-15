#ifndef LED_S__H
#define LED_S__H
/*====================Includes========================*/

#include "DLink.h"

/*====================Macros========================*/



/*====================Type_Definitions========================*/

typedef enum 
{
	ON_Status,
	OFF_Status
}LED_STATUS;

/*====================Global_Variables========================*/

extern void (*LED_Status)();

/*====================ProtoTypes========================*/

void init_LED();
void Idle ();
void Set_Alarm_actuator(int i);
void GPIO_INITIALIZATION ();

/*====================MAIN_APPLICATION========================*/



/*====================Functions========================*/



/*===============================================================*/
#endif 
/*===============================================================*/