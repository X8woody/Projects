/*
 * App.c
 *
 *  Created on: Dec 29, 2024
 *      Author: Abdulrhman
 */
/*====================Includes========================*/

#include "App.h"

/*====================Macros========================*/



/*====================Type_Definitions========================*/



/*====================Global_Variables========================*/



/*====================ProtoTypes========================*/



/*====================Functions========================*/

void Delay(uint32_t delay)
{
	delay *= DELAY;
	uint32_t i;
	for(i = 0 ; i < delay; i++);
}

uint8_t Main_App()
{
	DPRINTF("         Choose the task that you want to perform\n");
	Delay(DMoni);
	DPRINTF("===========================================================\n");
	DPRINTF("1.  Add the Student details Manually\n");
	DPRINTF("2.  Add the Student details from text file\n");
	DPRINTF("3.  Find the Student details by ID number\n");
	DPRINTF("4.  Find the Student details by first name\n");
	DPRINTF("5.  Find who registered in a course by ID of course\n");
	DPRINTF("6.  Find the total number of Students\n");
	DPRINTF("7.  Delete the Student details by ID number\n");
	DPRINTF("8.  Update the Student details by ID number\n");
	DPRINTF("9.  Show all information of all Students\n");
	DPRINTF("10. To SAVE\n");
	DPRINTF("11. To Exit\n");
	DPRINTF("===========================================================\n\n");
	Delay(DMoni);
	DPRINTF("10. Enter your choice: ");
	int32_t choice;
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		AddStudent();
		break;
	case 2:
		AddStud_text_file();
		break;
	case 3:
		View_by_ID();
		break;
	case 4:
		View_by_FName();
		break;
	case 5:
		Course_REG();
		break;
	case 6:
		Num_Student_L(gp_BaseStudent);
		break;
	case 7:
		DelStud();
		break;
	case 8:
		Update_data();
		break;
	case 9:
		ViewStudent();
		break;
	case 10:
		Save();
		break;
	case 11:
		exit(1);
		break;
	default :
		DPRINTF("\n        -------------> Error !! insert the correct choice <-------------\n\n");
		Delay(Dwel);
		break;
	}
	DPRINTF("\n\n===============================\n\n");
	DPRINTF("\nTo Continue press 'Y': ");
	char Y;
	scanf("%c",&Y);
	if(Y != 'Y' && Y != 'y')
	{
		DPRINTF("\n-----DO YOU WANT TO SAVE!!-----\n");
		DPRINTF("\n===============================\n\n");
		DPRINTF("\nTo  PRESS 'Y' TO SAVE: ");
		scanf("%c",&Y);
		if(Y != 'Y' && Y != 'y')
		{
			DPRINTF("\n-----NO DATA HAS BEEN SAVED-----\n");
			DPRINTF("\n===============================\n\n");
		}
		else
		{
			Save();
		}
		DPRINTF("\n-----Program End-----\n");
		DPRINTF("\n===============================\n");
		uint32_t i;
		for(i = 0; i<500000000; i++);
		return 1;
	}
	return 0;
}

/*===============================================================*/

