/*====================Includes========================*/

#include "HPD.h"

/*====================Macros========================*/



/*====================Type_Definitions========================*/



/*====================Global_Variables========================*/

int pVAL = 0;
void (*PressureSen_Status)();

/*====================Functions========================*/

void init_PressureSens ()
{
	PressureSen_Status = reading ;
}

void reading ()
{
	pVAL = getPressureVal();
	PDelay(getVal_Time);
	PressureSen_Status = reading ;
}

void PDelay(int nCount)
{
	nCount = nCount * 1000;
	for(; nCount != 0; nCount--);
}

int getPressureVal(){
	return (GPIOA_IDR & 0xFF);
}

/*===============================================================*/