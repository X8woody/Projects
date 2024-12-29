/*
 * main.c
 *
 *  Created on: Dec 19, 2024
 *      Author: Abdulrhman
 */
/*====================Includes========================*/

#include "App.h"


/*====================Macros========================*/



/*====================Type_Definitions========================*/



/*====================Global_Variables/Declaration========================*/



/*====================ProtoTypes========================*/



/*====================MAIN_APPLICATION========================*/

int main()
{
	if(!init_file())
	{
		get_data();
	}
	DPRINTF("Welcome to the student management System\n\n");
	Delay(Dwel);
	while(1)
	{
		uint8_t EXITT = Main_App();
		if(EXITT)
			break;
	}
	return 0;
}

/*====================Functions========================*/



/*===============================================================*/
