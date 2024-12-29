/*
 * linkedlist.h
 *
 *  Created on: Nov 18, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

/*====================Includes========================*/

#include <stdint.h>
#include <stdlib.h>
/*====================Macros========================*/

//for user configurations.
#define LLS_BaseNode    struct LLS_SBaseNode

#define NULL 			((void *)0)



/*====================Type_Definitions========================*/

/*==============USER CONFIGURATIONS==============*/
//Here create any effective data.

//-----------------------------//
//for Example:

typedef struct
{
	uint32_t   ID;
	uint32_t   course_id[5];
	float      GPA;
	char       name[40];
	char       NCourse;
}SStudent_t;

/*============================*/

//Linked list
struct LLS_SBaseNode
{
	//Put here your effective data which you created.

	//for Example:
	SStudent_t             Student;
	/*============================*/
	struct LLS_SBaseNode*  P_NextNode;
};

typedef enum
{
	LLS_Error,
	LLS_Done
}LLS_Status;

/*====================ProtoTypes========================*/

LLS_Status LLS_Init(LLS_BaseNode*** P_Node);
LLS_Status LLS_CreatNode(LLS_BaseNode** P_BaseNode, LLS_BaseNode** P_Node);
LLS_Status LLS_RemoveNode(LLS_BaseNode** P_BaseNode, LLS_BaseNode** P_Node);

/*===============================================================*/

#endif /* LINKEDLIST_H_ */
