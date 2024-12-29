/*
 * Studen.c
 *
 *  Created on: Dec 19, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */


/*====================Includes========================*/

#include "student.h"

/*====================Macros========================*/



/*====================Type_Definitions========================*/



/*====================Global_Variables========================*/

LLS_BaseNode* gp_BaseStudent = (LLS_BaseNode*)NULL;
uint32_t Count;

/*====================ProtoTypes========================*/



/*====================Functions========================*/


void AddStudent()
{
	LLS_BaseNode* lp_Stud;
	lp_Stud = (LLS_BaseNode*)NULL;
	if(LLS_CreatNode(&gp_BaseStudent, &lp_Stud))
	{
		DPRINTF("\n===============================\n");
		int8_t i;
		AGAIN:
		DPRINTF("Enter the ID: ");
		scanf("%u",&lp_Stud->Student.ID);
		LLS_BaseNode* check_List = gp_BaseStudent;
		while(check_List->P_NextNode)
		{
			if(lp_Stud->Student.ID == check_List->Student.ID)
			{
				DPRINTF("\n[INFO] The ID you entered is already exist\n");
				DPRINTF("\n===============================\n\n");
				goto AGAIN;
			}
			else
				check_List = check_List->P_NextNode;
		}
		DPRINTF("Enter the Student full name: ");
		gets(lp_Stud->Student.name);

		while(1)
		{
			DPRINTF("Enter the GPA you obtained: ");
			scanf("%f",&lp_Stud->Student.GPA);
			if(lp_Stud->Student.GPA <= 4 && lp_Stud->Student.GPA >= 0)
				break;
			else
			{
				DPRINTF("\nYou entered GPA out of range 0--->4 \n");
			}
		}

		int32_t num = 6;
		while(num)
		{
			DPRINTF("Enter the number of course to be registered up to '5' courses: ");
			scanf("%d",&num);
			if(num != 0 && num <= 5)
			{
				for(i = 0; i < 5; i++)
					lp_Stud->Student.course_id[i] = '\0';
				for(i = 0; i < num; i++)
				{
					DPRINTF("\nEnter the Course ID you want to register in: \n\n");
					DPRINTF("1. Course_1 \n");
					DPRINTF("2. Course_2 \n");
					DPRINTF("3. Course_3 \n");
					DPRINTF("4. Course_4 \n");
					DPRINTF("5. Course_5 \n");
					DPRINTF("\nEnter your choice: ");
					int32_t C_ID;
					scanf("%d",&C_ID);
					if(C_ID != 0 && C_ID <= 5)
					{
						ROLL:
						if(lp_Stud->Student.course_id[C_ID-1] == 0)
						{
							DPRINTF("\nCourse %d, Enter the RollNum of Student: ",C_ID);
							scanf("%u",&lp_Stud->Student.course_id[C_ID-1]);
							check_List = gp_BaseStudent;
							while(check_List->P_NextNode)
							{
								if(lp_Stud->Student.course_id[C_ID-1] == check_List->Student.course_id[C_ID-1])
								{
									DPRINTF("\nThe RollNum you entered is already exist\n");
									DPRINTF("\n===============================\n\n");
									lp_Stud->Student.course_id[C_ID-1] = 0;
									goto ROLL;
								}
								else
									check_List = check_List->P_NextNode;
							}
						}
						else
						{
							DPRINTF("\n[INFO] The Student already registered in this Course!!\n");
							DPRINTF("\n===============================\n\n");
							i--;
						}
					}
					else
					{
						i--;
						DPRINTF("\nError !!, There is no course matching with this ID\n");
						DPRINTF("\n===============================\n\n");
					}
				}
				lp_Stud->Student.NCourse = (char)num ;
				num = 0;
			}
			else
			{
				DPRINTF("\n   Error in number of courses\n\n");
				num = 6;
			}
		}

		DPRINTF("\n            Done Creation\n\n");
	}
	else
		DPRINTF("\nFailed !! Cannot create student data \n");
}

void DelStud()
{
	LLS_BaseNode* P_gp_BaseStudent = gp_BaseStudent;
	DPRINTF("\n===============================\n");
	if(P_gp_BaseStudent)
	{
		uint32_t id;
		DPRINTF("Enter the ID: ");
		scanf("%u",&id);
		while(P_gp_BaseStudent->Student.ID != id && P_gp_BaseStudent != (LLS_BaseNode*)NULL)
		{
			if((P_gp_BaseStudent->P_NextNode))
				P_gp_BaseStudent = P_gp_BaseStudent->P_NextNode;
			else if((!P_gp_BaseStudent) || (!P_gp_BaseStudent->P_NextNode))
				break;
		}
		if(P_gp_BaseStudent->Student.ID == id)
		{
			if(LLS_RemoveNode(&gp_BaseStudent, &P_gp_BaseStudent))
			{
				DPRINTF("Done\n");
			}
		}
		else
		{
			DPRINTF("Failed...!!\n");
		}
	}
	else
	{
		DPRINTF("Empty list\n");
	}
	DPRINTF("===============================\n\n");
}

void ViewStudent()
{
	DPRINTF("\n===============================\n");
	uint32_t i = 0;
	LLS_BaseNode* P_gp_BaseStudent = gp_BaseStudent;
	if(!P_gp_BaseStudent)
	{
		DPRINTF("\nEmpty list\n");
		DPRINTF("\n===============================\n\n");
	}
	else
	{
		while(P_gp_BaseStudent)
		{
			DPRINTF("Record Number %u\n",++i);
			DPRINTF("ID  :                                                    %u\n",P_gp_BaseStudent->Student.ID);
			DPRINTF("Name:                                                    %s\n",P_gp_BaseStudent->Student.name);
			DPRINTF("GPA :                                                    %0.1f\n",P_gp_BaseStudent->Student.GPA);
			DPRINTF("Total Course registered is:                              %d\n",P_gp_BaseStudent->Student.NCourse);
			uint32_t i;
			for(i = 0 ; i < 5; i++)
			{
				if(P_gp_BaseStudent->Student.course_id[i] != '\0')
					DPRINTF("Course %d, The RollNum of Student is:                     %u\n",i+1,P_gp_BaseStudent->Student.course_id[i]);
			}
			DPRINTF("\n===============================\n");
			DPRINTF("\n\n");
			P_gp_BaseStudent = P_gp_BaseStudent->P_NextNode;
		}
	}
}

void Delete_All()
{
	DPRINTF("\n===============================\n");
	LLS_BaseNode* P_gp_BaseStudent = gp_BaseStudent;
	LLS_BaseNode* P_Temp;
	if(!P_gp_BaseStudent)
	{
		DPRINTF("Empty list\n");
	}
	else
	{
		while(P_gp_BaseStudent)
		{
			P_Temp = P_gp_BaseStudent->P_NextNode;
			free(P_gp_BaseStudent);
			P_gp_BaseStudent = P_Temp;
		}
		if(!P_gp_BaseStudent)
			gp_BaseStudent = P_gp_BaseStudent;
		DPRINTF("Now the list is Empty\n");
	}
}

void VPos_Index()
{
	DPRINTF("\n===============================\n");
	LLS_BaseNode* P_gp_BaseStudent = gp_BaseStudent;
	LLS_BaseNode*Carriage_Data;
	if(P_gp_BaseStudent)
	{
		uint32_t pos;
		DPRINTF("Enter the Position of Index: ");
		scanf("%u",&pos);

		Carriage_Data = GetNth(P_gp_BaseStudent,&pos);
		//Carriage_Data = GetNth_FromLast(P_gp_BaseStudent,&pos);

		if(Carriage_Data && pos != 0)
		{
			//DPRINTF("Display data normally.\n");
			DPRINTF("Display data from the last member position.\n");
			DPRINTF("ID:      %u\n",Carriage_Data->Student.ID);
			DPRINTF("Name:    %s\n",Carriage_Data->Student.name);
			//DPRINTF("Height:  %0.1f\n\n",Carriage_Data->Student.height);
		}
		else
			DPRINTF("There is no data matching with your Index\n\n");
	}
	else
	{
		DPRINTF("The list is Empty\n");
	}
}

LLS_BaseNode* GetNth(LLS_BaseNode* P_gp_BaseStudent,uint32_t* Index)
{
	if(!P_gp_BaseStudent)
		return (LLS_BaseNode*)NULL;
	else
	{
		LLS_BaseNode* P_Node = P_gp_BaseStudent;
		uint32_t i;
		for(i = 0; i < (*Index)-1; i++)
		{
			if((P_Node->P_NextNode) || ((!P_Node->P_NextNode) && i <((*Index)-1)))
				P_Node = P_Node->P_NextNode;
			else if((!P_Node->P_NextNode) && (i == ((*Index)-1)))
			{

			}
		}
		return P_Node;
	}
}

void Num_Student_L(LLS_BaseNode* P_gp_BaseStudent)
{
	uint32_t count = 0;
	if(!P_gp_BaseStudent)
	{
		DPRINTF("\nEmpty list\n");
	}
	else
	{
		while(P_gp_BaseStudent)
		{
			count++;
			P_gp_BaseStudent = P_gp_BaseStudent->P_NextNode;
		}
		DPRINTF("\nThe number of student is: %u\n",count);
	}
	DPRINTF("===============================\n\n");
}

uint32_t Num_Student_R(LLS_BaseNode* P_gp_BaseStudent)
{
	if((!P_gp_BaseStudent) && Count == 0)
	{
		DPRINTF("\nEmpty list\n");
	}
	else
	{
		if(P_gp_BaseStudent)
		{
			Count++;
			P_gp_BaseStudent = P_gp_BaseStudent->P_NextNode;
			Count = Num_Student_R(P_gp_BaseStudent);
		}
	}
	return	Count;
}

LLS_BaseNode* GetNth_FromLast(LLS_BaseNode* P_gp_BaseStudent,uint32_t* Index)
{
	LLS_BaseNode* C_P_gp_BaseStudent = P_gp_BaseStudent;
	if(C_P_gp_BaseStudent)
	{
		uint32_t count = 0;
		if(C_P_gp_BaseStudent->P_NextNode)
		{
			while(C_P_gp_BaseStudent->P_NextNode)
			{
				count++;
				C_P_gp_BaseStudent = C_P_gp_BaseStudent->P_NextNode;
			}
			count +=1;
		}
		else
			count = 1;
		if(*Index <= count)
		{
			uint32_t i;
			C_P_gp_BaseStudent = P_gp_BaseStudent;
			for(i = count; i > (*Index); i--)
				C_P_gp_BaseStudent = C_P_gp_BaseStudent->P_NextNode;
		}
		else
			return (LLS_BaseNode*)NULL;
	}
	else
		return (LLS_BaseNode*)NULL;
	return C_P_gp_BaseStudent;
}

void Mid_List(LLS_BaseNode* P_gp_BaseStudent)
{
	if(!P_gp_BaseStudent)
	{
		DPRINTF("\nThe list is Empty\n");
	}
	else
	{
		LLS_BaseNode* C_P_gp_BaseStudent = P_gp_BaseStudent;
		uint32_t count = 1;
		while(C_P_gp_BaseStudent->P_NextNode)
		{
			count++;
			C_P_gp_BaseStudent = C_P_gp_BaseStudent->P_NextNode;
		}
		uint32_t i;
		C_P_gp_BaseStudent = P_gp_BaseStudent;
		count = (count/2) + 1;
		for(i = 1; i < count; i++)
		{
			C_P_gp_BaseStudent = C_P_gp_BaseStudent->P_NextNode;
		}
		DPRINTF("ID:      %u\n",C_P_gp_BaseStudent->Student.ID);
		DPRINTF("Name:    %s\n",C_P_gp_BaseStudent->Student.name);
		//DPRINTF("Height:  %0.1f\n\n",C_P_gp_BaseStudent->Student.height);
	}
}

void Detect_LoapList(LLS_BaseNode* P_gp_BaseStudent)
{
	LLS_BaseNode* CP_gp_BaseStudent = P_gp_BaseStudent;
	if(!CP_gp_BaseStudent)
	{
		DPRINTF("\nThe list is Empty\n");
	}
	else
	{
		while(CP_gp_BaseStudent->P_NextNode)
		{
			CP_gp_BaseStudent = CP_gp_BaseStudent->P_NextNode;
			if(CP_gp_BaseStudent->P_NextNode == P_gp_BaseStudent)
			{
				break;
			}
		}
		if(!CP_gp_BaseStudent->P_NextNode)
		{
			DPRINTF("\nNo Looping\n");
		}
		else
		{
			DPRINTF("\nFined Looping\n");
		}
	}
}

void Rev_List(LLS_BaseNode** PP_gp_BaseStudent)
{
	LLS_BaseNode* PC = (*PP_gp_BaseStudent);
	LLS_BaseNode* PTail = (*PP_gp_BaseStudent);
	LLS_BaseNode* Base_Head = (*PP_gp_BaseStudent);
	LLS_BaseNode** SavedTail;
	if(!PC)
	{
		DPRINTF("\nThe list is Empty\n");
	}
	else
	{
		while(PTail->P_NextNode)
		{
			PTail = PTail->P_NextNode;
		}
		(*PP_gp_BaseStudent) = PTail;
		SavedTail = &PTail;
		while (PC != PTail)
		{
			while(PC->P_NextNode != PTail)
			{
				PC = PC->P_NextNode;
			}
			(*SavedTail)->P_NextNode = PC;
			SavedTail = &((*SavedTail)->P_NextNode);
			PTail = PC;
			PC = Base_Head;
		}
		if(PTail == PC)
		{
			(*SavedTail)->P_NextNode = (LLS_BaseNode*)NULL;
		}
		DPRINTF("\n REVERSE DONE \n");
	}
}

LLS_BaseNode* Get_ID_Details(LLS_BaseNode* P_gp_BaseStudent,uint32_t* ID,uint32_t* Roll)
{
	if(!P_gp_BaseStudent)
		return (LLS_BaseNode*)NULL;
	else
	{
		LLS_BaseNode* P_Node = P_gp_BaseStudent;
		if(P_Node->Student.ID == *ID)
		{
			*Roll = 1;
			return P_Node;
		}
		else
		{
			P_Node = P_Node->P_NextNode;
			*Roll = 1;
			while(P_Node)
			{
				(*Roll)++;
				if(P_Node->Student.ID == *ID)
				{
					return P_Node;
				}
				else
				{
					P_Node = P_Node->P_NextNode;
				}

			}
			return P_Node;
		}
	}
}

void View_by_ID()
{
	DPRINTF("\n===============================\n");
	LLS_BaseNode* P_gp_BaseStudent = gp_BaseStudent;
	LLS_BaseNode* Carriage_Data;
	if(P_gp_BaseStudent)
	{
		uint32_t ID;
		uint32_t Roll = 0;
		DPRINTF("Enter the ID of Students: ");
		scanf("%u",&ID);

		Carriage_Data = Get_ID_Details(P_gp_BaseStudent ,&ID ,&Roll);

		if(Carriage_Data)
		{
			DPRINTF("Roll Number:                                             %u\n",Roll);
			DPRINTF("Name:                                                    %s\n",Carriage_Data->Student.name);
			DPRINTF("GPA :                                                    %0.1f\n",Carriage_Data->Student.GPA);
			DPRINTF("Total Course registered is:                              %d\n",Carriage_Data->Student.NCourse);
			uint32_t i;
			for(i = 0 ; i < 5; i++)
			{
				if(Carriage_Data->Student.course_id[i] != '\0')
					DPRINTF("Course %d, The RollNum of Student is:                     %u\n",i+1,Carriage_Data->Student.course_id[i]);
			}
			DPRINTF("\n===============================\n");
			DPRINTF("\n\n");
		}
		else
		{
			DPRINTF("\nThere is no data matching with this ID\n");
			DPRINTF("\n===============================\n\n");
		}
	}
	else
	{
		DPRINTF("\nThe list is Empty\n");
		DPRINTF("\n===============================\n\n");
	}
}

void Get_FName_Details(LLS_BaseNode* P_gp_BaseStudent,char* FN,uint32_t* Roll)
{
	if(!P_gp_BaseStudent)
		*Roll = 0;
	else
	{
		LLS_BaseNode* P_Node = P_gp_BaseStudent;
		uint32_t i;
		char SF_Name[40];
		while(P_Node)
		{
			for(i = 0; i < 40; i++)
			{
				if(P_Node->Student.name[i] != ' ')
					SF_Name[i] = P_Node->Student.name[i];
				else
				{
					SF_Name[i] = '\0';
					break;
				}
			}
			if(!(strcasecmp(FN,SF_Name)))
			{
				(*Roll)++;
				DPRINTF("Roll Number:                                             %u\n",*Roll);
				DPRINTF("ID:                                                      %u\n",P_Node->Student.ID);
				DPRINTF("Name:                                                    %s\n",P_Node->Student.name);
				DPRINTF("GPA :                                                    %0.1f\n",P_Node->Student.GPA);
				DPRINTF("Total Course registered is:                              %d\n",P_Node->Student.NCourse);
				uint32_t i;
				for(i = 0 ; i < 5; i++)
				{
					if(P_Node->Student.course_id[i] != '\0')
						DPRINTF("Course %d, The RollNum of Student is:                     %u\n",i+1,P_Node->Student.course_id[i]);
				}
				DPRINTF("\n===============================\n");
				DPRINTF("\n\n");
			}
			P_Node = P_Node->P_NextNode;
		}
	}
}

void View_by_FName()
{
	DPRINTF("\n===============================\n");
	LLS_BaseNode* P_gp_BaseStudent = gp_BaseStudent;
	if(P_gp_BaseStudent)
	{
		char FN[40];
		uint32_t Roll = 0;
		DPRINTF("Enter the first name of Students: ");
		gets(FN);

		Get_FName_Details(P_gp_BaseStudent ,FN ,&Roll);

		if(Roll == 0)
		{
			DPRINTF("\nThere is no data matching with this Name\n");
			DPRINTF("\n===============================\n\n");
		}
	}
	else
	{
		DPRINTF("\nThe list is Empty\n");
		DPRINTF("\n===============================\n\n");
	}
}

void Course_REG()
{
	DPRINTF("\n===============================\n");
	LLS_BaseNode* P_gp_BaseStudent = gp_BaseStudent;
	if(!P_gp_BaseStudent)
	{
		DPRINTF("\nEmpty list\n");
		DPRINTF("\n===============================\n\n");
	}
	else
	{
		Rep:
		DPRINTF("Insert ID of Course: ");
		uint32_t ID;
		uint32_t c = 0;
		scanf("%u",&ID);
		if(ID != 0 && ID <= 5)
		{
			while(P_gp_BaseStudent)
			{
				if(P_gp_BaseStudent->Student.course_id[ID-1] != 0)
				{
					DPRINTF("\nThe Student details are:\n");
					DPRINTF("ID  :                            %u\n",P_gp_BaseStudent->Student.ID);
					DPRINTF("Name:                            %s\n",P_gp_BaseStudent->Student.name);
					DPRINTF("GPA :                            %0.1f\n",P_gp_BaseStudent->Student.GPA);
					DPRINTF("\n===============================\n");
					c++;
				}
				P_gp_BaseStudent = P_gp_BaseStudent->P_NextNode;
			}
			if(c == 0)
			{
				DPRINTF("\nThere is no Students registered in this Course\n");
				DPRINTF("\n===============================\n\n");
			}
		}
		else
		{
			DPRINTF("\nError Insert the correct course ID from 1 up to 5\n");
			DPRINTF("\n===============================\n\n");
			goto Rep;
		}
	}
}

void Update_Name(LLS_BaseNode** P_gp_BaseStudent)
{
	DPRINTF("Enter the new name: ");
	gets((*P_gp_BaseStudent)->Student.name);
	DPRINTF("\n[Info] UPDATED SUCCESFULLY\n");
}

void Update_ID(LLS_BaseNode** P_gp_BaseStudent)
{
	LLS_BaseNode* check_List = gp_BaseStudent;
	uint32_t c;
	NewID:
	DPRINTF("Enter the new ID: ");
	scanf("%u",&c);
	while(check_List)
	{
		if(c == check_List->Student.ID)
		{
			DPRINTF("The ID you entered is already exist\n\n");
			goto NewID;
		}
		else
			check_List = check_List->P_NextNode;
	}
	(*P_gp_BaseStudent)->Student.ID = c;
	DPRINTF("\n[Info] UPDATED SUCCESFULLY\n");
}

void Update_GPA(LLS_BaseNode** P_gp_BaseStudent)
{
	while(1)
	{
		DPRINTF("Enter the new GPA: ");
		scanf("%f",&(*P_gp_BaseStudent)->Student.GPA);
		if((*P_gp_BaseStudent)->Student.GPA <= 4 && (*P_gp_BaseStudent)->Student.GPA >= 0)
			break;
		else
		{
			DPRINTF("\nYou entered GPA out of range 0--->4 \n");
		}
	}
	DPRINTF("\n[Info] UPDATED SUCCESFULLY\n");
}

void Update_Courses(LLS_BaseNode** P_gp_BaseStudent)
{
	UpdateC:
	DPRINTF("\nSelect option:\n");
	DPRINTF("1.Delete Course\n2.Add Course\n");
	DPRINTF("\nEnter your choice: ");
	uint32_t choice;
	scanf("%u",&choice);
	if(choice != 0 && choice <= 2)
	{
		if(choice == 2)
		{
			DPRINTF("Enter the Course ID that you want to register in: ");
			int32_t C_ID;
			scanf("%d",&C_ID);
			if(C_ID != 0 && C_ID <= 5)
			{
				if((*P_gp_BaseStudent)->Student.course_id[C_ID-1] == 0)
				{
					DPRINTF("Course %d, Enter the RollNum of Student: ",C_ID);
					scanf("%u",&(*P_gp_BaseStudent)->Student.course_id[C_ID-1]);
					(*P_gp_BaseStudent)->Student.NCourse++;
					DPRINTF("\n[Info] UPDATED SUCCESFULLY\n");
				}
				else
				{
					DPRINTF("Course %d, Already registered\n\n",C_ID);
					DPRINTF("Press 'y' if you want to update RollNum: ");
					char Y;
					scanf("%c",&Y);
					if(Y != 'Y' && Y != 'y')
					{
						DPRINTF("\n[Info] UPDATED UNSUCCESFULLY\n");
					}
					else
					{
						DPRINTF("\nCourse %d, Enter the RollNum of Student: ",C_ID);
						scanf("%u",&(*P_gp_BaseStudent)->Student.course_id[C_ID-1]);
						DPRINTF("\n[Info] UPDATED SUCCESFULLY\n");
					}
				}
			}
			else
			{
				DPRINTF("\nError !!, There is no course matching with this ID\n");
				DPRINTF("\n===============================\n\n");
				goto UpdateC;
			}
		}
		else
		{
			DPRINTF("Enter the Course ID that you want to remove: ");
			int32_t C_ID;
			scanf("%d",&C_ID);
			if(C_ID != 0 && C_ID <= 5)
			{
				if((*P_gp_BaseStudent)->Student.course_id[C_ID-1] != 0)
				{
					(*P_gp_BaseStudent)->Student.course_id[C_ID-1] = 0;
					(*P_gp_BaseStudent)->Student.NCourse--;
					DPRINTF("\n[Info] UPDATED SUCCESFULLY\n");
				}
				else
				{
					DPRINTF("Course %d, Already not registered in\n\n",C_ID);
				}
			}
			else
			{
				DPRINTF("\nError !!, There is no course matching with this ID\n");
				DPRINTF("\n===============================\n\n");
				goto UpdateC;
			}
		}
	}
	else
	{
		DPRINTF("\n[Info] Error !! WRONG CHOICE\n");
		goto UpdateC;
	}
}

void Update_data()
{
	DPRINTF("\n===============================\n");
	LLS_BaseNode* P_gp_BaseStudent = gp_BaseStudent;
	LLS_BaseNode*Carriage_Data;
	if(!P_gp_BaseStudent)
	{
		DPRINTF("\nEmpty list\n");
		DPRINTF("\n===============================\n\n");
	}
	else
	{
		uint32_t d_in;
		uint32_t Roll = 0;
		DPRINTF("Enter the ID of Student to update the entry: ");
		scanf("%u",&d_in);
		Carriage_Data = Get_ID_Details(P_gp_BaseStudent ,&d_in ,&Roll);
		while(Roll)
		{
			DPRINTF("\nWhich kind of data you want to update: \n");
			DPRINTF("1.Name\n");
			DPRINTF("2.GPA\n");
			DPRINTF("3.ID\n");
			DPRINTF("4.Courses\n");
			DPRINTF("\nEnter your choice: ");
			scanf("%u",&d_in);
			switch(d_in)
			{
			case 1:
				Update_Name(&Carriage_Data);
				Roll = 0;
				break;
			case 2:
				Update_GPA(&Carriage_Data);
				Roll = 0;
				break;
			case 3:
				Update_ID(&Carriage_Data);
				Roll = 0;
				break;
			case 4:
				Update_Courses(&Carriage_Data);
				Roll = 0;
				break;
			default :
				DPRINTF("\nError !!\n    wrong choice: \n");
				break;
			}
		}
		if(!Carriage_Data)
		{
			DPRINTF("\nThere is no data matching with this ID\n");
		}
		DPRINTF("\n===============================\n\n");
	}
}

void Save()
{
	uint8_t prror = send_data(gp_BaseStudent);
	if(prror == 1)
	{
		DPRINTF("\nSAVED SUCCESFULLY\n");
		DPRINTF("\n===============================\n\n");
	}
	else
	{
		DPRINTF("\nSAVED UNSUCCESFULLY\n\n   [INFO] List is Empty\n");
		DPRINTF("\n===============================\n\n");
	}
}

void AddStud_text_file()
{
	DPRINTF("\n\n GO TO THIS PATH [C:\\Student_MSys\\SData.txt] and Edit the file\n");
	DPRINTF("\n========================================================================\n\n");
	DPRINTF("\n\n[NOTE] Insert data as file's form\n");
	DPRINTF("\n[EXAMPLE] 1 Ahmed Ali 3.5 5 100 100 100 100 100\n");
	DPRINTF("\n\nWhich:\n"
			"'1'   is : ID\n"
			"'3.5' is : GPA\n"
			"'5'   is : Number of Course Registered\n"
			"'100' is : Roll Number of student in the course ID 1\n"
			"'100' is : Roll Number of student in the course ID 2\n"
			"'100' is : Roll Number of student in the course ID 3\n"
			"'100' is : Roll Number of student in the course ID 4\n"
			"'100' is : Roll Number of student in the course ID 5\n");
	DPRINTF("\n========================================================================\n\n");
	int k;
	for(k=0; k<2000000000; k++);
	//exit(1);
}

/*===============================================================*/
