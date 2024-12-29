/*
 * FileHandle.c
 *
 *  Created on: Dec 19, 2024
 *      Author: Abdulrhman
 */
/*====================Includes========================*/

#include "filehandle.h"

/*====================Macros========================*/

#define DPRINTF(...)        {fflush(stdout);\
		fflush(stdin);\
		printf(__VA_ARGS__);\
		fflush(stdout);\
		fflush(stdin);}
#define delayy              2500000000

/*====================Type_Definitions========================*/



/*====================Global_Variables========================*/

FILE *fp ,*temp;
char data[50] = {'\0'};
char* dat;
extern LLS_BaseNode* gp_BaseStudent;
extern uint32_t Count;

/*====================ProtoTypes========================*/

extern uint32_t Num_Student_R(LLS_BaseNode* P_gp_BaseStudent);

/*====================Functions========================*/

FH_STATUS init_file()
{
	if(!mkdir("C:\\Student_MSys"))
	{
		fp = fopen("C:\\Student_MSys\\SData.txt","a");
		fclose(fp);
		return FH_OK;
	}
	else
		return FH_Error;
}

FILE* backup_data()
{
	FILE* backup = fopen("C:\\Student_MSys\\backup__SData.txt","w");
	fp           = fopen("C:\\Student_MSys\\SData.txt","r");
	char  bac[50]    = {'\0'};
	while(!feof(fp))
	{
		fgets(bac,50,fp);
		fputs(bac,backup);
		memset(bac,'\0',50);
	}
	fclose(fp);
	fclose(backup);
	return backup;
}

void delete_specific_line(uint32_t line)
{
	memset(data,'\0',50);
	fp = fopen("C:\\Student_MSys\\SData.txt","r");
	temp = fopen("C:\\Student_MSys\\temp__SData.txt","w");
	if(fp == '\0' && temp == '\0')
	{
		DPRINTF("\n[INFO] Error in opening files\n");
		DPRINTF("\n=============================================\n\n");
		int32_t k;
		for(k=0; k<delayy; k++);
		exit(1);

	}
	uint8_t statt = 1;
	uint32_t counter = 0;
	dat = "DATA ERASED HERE!!\n";
	while(statt)
	{
		fgets(data,50,fp);
		if(feof(fp))
		{
			if(counter != line)
				fputs(data,temp);
			else
				fputs(dat,temp);
			statt = 0;
		}
		else if(counter != line)
			fputs(data,temp);
		else if(counter == line)
		{
			fputs(dat,temp);
		}
		counter++;
	}
	fclose(fp);
	fclose(temp);
	remove("C:\\Student_MSys\\SData.txt");
	rename("C:\\Student_MSys\\temp__SData.txt","C:\\Student_MSys\\SData.txt");
}

void check_Courses()
{
	LLS_BaseNode* LP_Stud  = gp_BaseStudent;
	LLS_BaseNode* LP_NStud = LP_Stud->P_NextNode;
	uint32_t num = Num_Student_R(LP_Stud);
	uint8_t  NCourse = 5;
	uint8_t flag = 0;
	int32_t CCS;
	for(CCS = 0; CCS < NCourse; CCS++)
	{
		int32_t  i;
		for(i = 0; i < num; i++)
		{
			int32_t l;
			for(l = i; l < num; l++)
			{
				if(LP_NStud)
				{
					if((LP_Stud->Student.course_id[CCS] == LP_NStud->Student.course_id[CCS]) && (LP_Stud->Student.course_id[CCS] != '\0'))
					{
						delete_specific_line(l+1);
						DPRINTF("\n[INFO] Data of \"%s\" have been erased because of \"Repeated RollNum '%d' in Course\" --> %d\n",LP_NStud->Student.name,LP_NStud->Student.course_id[CCS],CCS+1);
						DPRINTF("\n==========================================================================\n\n");
						LLS_RemoveNode(&gp_BaseStudent ,&LP_NStud);
						LP_NStud = LP_Stud->P_NextNode;
						num--;
						flag = 1;

					}
					else
					{
						LP_NStud = LP_NStud->P_NextNode;
					}
				}
				else
				{
					if(LP_Stud)
						LP_Stud = LP_Stud->P_NextNode;
					if(LP_Stud)
						LP_NStud = LP_Stud->P_NextNode;
				}
			}
		}
		LP_Stud  = gp_BaseStudent;
		LP_NStud = LP_Stud->P_NextNode;
	}
	if(flag == 1)
	{
		DPRINTF("\n[INFO] Error in form of file !! fix it \n");
		DPRINTF("\n=============================================\n\n");
		int32_t k;
		for(k=0; k<delayy; k++);
		exit(1);
	}
}

void check_ID()
{
	LLS_BaseNode* LP_Stud  = gp_BaseStudent;
	LLS_BaseNode* LP_NStud = LP_Stud->P_NextNode;
	uint32_t num = Num_Student_R(LP_Stud);
	uint8_t flag = 0;
	while(LP_Stud && LP_NStud)
	{
		int32_t  i;
		for(i = 0; i < num; i++)
		{
			int32_t l;
			for(l = i; l < num; l++)
			{
				if(LP_NStud)
				{
					if(LP_Stud->Student.ID == LP_NStud->Student.ID)
					{
						delete_specific_line(l+1);
						DPRINTF("\n[INFO] Data of \"%s\" have been erased because of \"Repeated ID\" --> %d\n",LP_NStud->Student.name,LP_NStud->Student.ID);
						DPRINTF("\n==========================================================================\n\n");
						LLS_RemoveNode(&gp_BaseStudent ,&LP_NStud);
						LP_NStud = LP_Stud->P_NextNode;
						flag = 1;

					}
					else
					{
						LP_NStud = LP_NStud->P_NextNode;
					}
				}
				else
				{
					if(LP_Stud)
						LP_Stud = LP_Stud->P_NextNode;
					if(LP_Stud)
						LP_NStud = LP_Stud->P_NextNode;
				}
			}
		}
	}
	if(flag == 1)
	{
		DPRINTF("\n[INFO] Error in form of file !! fix it \n");
		DPRINTF("\n=============================================\n\n");
		int32_t k;
		for(k=0; k<delayy; k++);
		exit(1);
	}
}

void get_data()
{
	fp = fopen("C:\\Student_MSys\\SData.txt","r");
	uint32_t counter = 1;
	char ch = fgetc(fp);
	rewind(fp);
	if(ch != -1)
	{
		while((ch = fgetc(fp)) != EOF)
		{
			if(ch == '\n')
			{
				ch = fgetc(fp);
				if( ch != '\n' && ch != ' ')
					counter++;
				else
				{
					DPRINTF("\n[INFO] Error in form of file !! fix it \n");
					DPRINTF("\n=============================================\n\n");
					int32_t k;
					for(k=0; k<delayy; k++);
					exit(1);
				}
			}
		}
		LLS_BaseNode* LP_Stud = (LLS_BaseNode*)NULL;
		uint32_t i;
		if((ch = fgetc(fp)) != '\0' )
		{
			rewind(fp);
			for(i = 1; i <= counter; i++)
			{
				LP_Stud = (LLS_BaseNode*)NULL;
				LLS_CreatNode(&gp_BaseStudent, &LP_Stud);
				uint32_t l;
				for(l = 0; l < 5; l++)
					LP_Stud->Student.course_id[l] = '\0';
				for(l = 0; l < 4; l++)
					LP_Stud->Student.name[l] = '\0';
				fscanf(fp,"%s",data);
				if(atoi(data))
				{
					LP_Stud->Student.ID = atoi(data);
					//DPRINTF("%d\n",LP_Stud->Student.ID);
				}
				else
				{
					DPRINTF("\n[INFO] Error in form of file !! fix it \n");
					DPRINTF("\n=============================================\n\n");
					int32_t k;
					for(k=0; k<delayy; k++);
					exit(1);
				}
				fscanf(fp,"%s",data);
				while(!atoi(data))
				{
					strcat(LP_Stud->Student.name,data);
					fscanf(fp,"%s",data);
					if(!atoi(data))
						strcat(LP_Stud->Student.name," ");
					else
					{
						int32_t c;
						for(c = 0; c < strlen(data); c++)
						{
							if((data[c] >= '0' && data[c] <= '9') || (data[c] == '.'))
							{

							}
							else
							{
								DPRINTF("\n[INFO] Error in form of file !! fix it \n");
								DPRINTF("\n=============================================\n\n");
								int32_t k;
								for(k=0; k<delayy; k++);
								exit(1);
							}
						}
						LP_Stud->Student.GPA = atof(data);
					}
				}
				//DPRINTF("%s\n",LP_Stud->Student.name);
				//DPRINTF("%0.2f\n",LP_Stud->Student.GPA);
				fscanf(fp,"%s",data);
				int d;
				if((d = atoi(data)) && (d >= 1 && d <= 5 ))
				{
					LP_Stud->Student.NCourse = d;
					//DPRINTF("%d\n",LP_Stud->Student.NCourse);
				}
				else
				{
					DPRINTF("\n[INFO] Error in form of file !! fix it \n");
					DPRINTF("\n=============================================\n\n");
					int32_t k;
					for(k=0; k<delayy; k++);
					exit(1);
				}
				int32_t k ,p=0,t;
				for(k = 0; k < LP_Stud->Student.NCourse; k++,p++)
				{
					t = fscanf(fp,"%s",data);
					if(atoi(data) && t != -1)
					{
						LP_Stud->Student.course_id[p] = atoi(data);
						//DPRINTF("%d\n",LP_Stud->Student.course_id[k]);
					}
					else if(data[0] == 48 && t != -1)
					{
						k--;
						LP_Stud->Student.course_id[p] = atoi(data);
						//DPRINTF("%d\n",LP_Stud->Student.course_id[p]);
					}
					else
					{
						DPRINTF("\n[INFO] Error in form of file !! fix it \n");
						DPRINTF("\n=============================================\n\n");
						int32_t c;
						for(c=0; c<delayy; c++);
						exit(1);
					}
				}
				rewind(fp);
				uint32_t loop = i;
				while(loop)
				{
					fgets(data,50,fp);
					loop--;
				}
			}
			DPRINTF("\n=============================================\n\n");
		}
		else
		{
			DPRINTF("\n[INFO] Data is Empty \n");
			DPRINTF("\n=============================================\n\n");
		}
		fclose(fp);
		check_list();
	}
}

uint8_t send_data(LLS_BaseNode* P_Student)
{
	fp = fopen("C:\\Student_MSys\\SData.txt","w");
	uint8_t NCO;
	if(P_Student)
	{
		while(P_Student)
		{
			fprintf(fp,"%d "    ,P_Student->Student.ID);
			fprintf(fp,"%s "    ,P_Student->Student.name);
			fprintf(fp,"%0.2f " ,P_Student->Student.GPA);
			fprintf(fp,"%d "    ,P_Student->Student.NCourse);
			for(NCO = 0; NCO < 5; NCO++)
			{
				fprintf(fp,"%d ",P_Student->Student.course_id[NCO]);
			}
			P_Student = P_Student->P_NextNode;
			if(P_Student)
				fprintf(fp,"\n");
		}
		fclose(fp);
	}
	else
		return 0;
	return 1;
}

void check_list()
{
	if(!gp_BaseStudent)
	{

	}
	else
	{
		backup_data();
		check_ID();
		check_Courses();
	}
}

/*===============================================================*/
