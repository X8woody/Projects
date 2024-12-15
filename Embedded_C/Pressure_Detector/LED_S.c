/*====================Includes========================*/

#include "LED_S.h"

/*====================Macros========================*/



/*====================Type_Definitions========================*/



/*====================Global_Variables========================*/

void (*LED_Status)();

/*====================Functions========================*/
void init_LED()
{	
	LED_Status = GPIO_INITIALIZATION ;
}

void Idle ()
{
	LED_Status = Idle;
}

void Set_Alarm_actuator(int i){
	if (i == 1){
		SET_BIT(GPIOA_ODR,13);
	}
	else if (i == 0){
		RESET_BIT(GPIOA_ODR,13);
	}
	LED_Status = Idle;
}

void GPIO_INITIALIZATION (){
	SET_BIT(APB2ENR, 2);
	GPIOA_CRL &= 0xFF0FFFFF;
	GPIOA_CRL |= 0x00000000;
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x22222222;
	Set_Alarm_actuator(OFF_Status);
}

/*===============================================================*/