/*
 * linkedlist.c
 *
 *  Created on: Nov 18, 2024
 *      Author: Abdulrhman Alaa-Eldin
 */

/*====================Includes========================*/

#include "linkedlist.h"


/*====================Macros========================*/



/*====================Type_Definitions========================*/



/*====================Global_Variables========================*/



/*====================Functions========================*/

LLS_Status LLS_Init(LLS_BaseNode*** P_BaseNode) //P_BaseNode must be global.
{
	if((**P_BaseNode))
		return LLS_Error;
	(**P_BaseNode) = (LLS_BaseNode*)malloc(sizeof(LLS_BaseNode));
	(**P_BaseNode)->P_NextNode = (LLS_BaseNode*)NULL;
	return LLS_Done;
}

LLS_Status LLS_CreatNode(LLS_BaseNode** P_BaseNode, LLS_BaseNode** P_Node)
{
	LLS_BaseNode** PP_BaseNode;
	if(*P_Node)
		return LLS_Error;
	PP_BaseNode = P_BaseNode;
	if(!(LLS_Init(&PP_BaseNode)))
	{
		while((*PP_BaseNode)->P_NextNode)
		{
			(*P_Node) = (*PP_BaseNode)->P_NextNode;
			PP_BaseNode = P_Node;
		}
		(*PP_BaseNode)->P_NextNode = (LLS_BaseNode*)malloc(sizeof(LLS_BaseNode));
		if(!(*PP_BaseNode)->P_NextNode)
			return LLS_Error;
		(*P_Node) = (*PP_BaseNode)->P_NextNode;
	}
	else
		(*P_Node) = (*PP_BaseNode);
	(*P_Node)->P_NextNode = (LLS_BaseNode*)NULL;
	return LLS_Done;
}

LLS_Status LLS_RemoveNode(LLS_BaseNode** P_BaseNode, LLS_BaseNode** P_Node)
{
	LLS_BaseNode** Ptemp_Node;
	if(!(*P_BaseNode) || !(*P_Node))
		return LLS_Error;
	if((*P_Node)->P_NextNode == NULL)
	{
		if((*P_BaseNode) == (*P_Node))
			(*P_BaseNode) = (LLS_BaseNode*)NULL;
		else
		{
			Ptemp_Node = P_BaseNode;
			while((*Ptemp_Node)->P_NextNode != (*P_Node))
				Ptemp_Node = &((*Ptemp_Node)->P_NextNode);
			(*Ptemp_Node)->P_NextNode = (LLS_BaseNode*)NULL;
		}
	}
	else
	{
		if((*P_BaseNode) == (*P_Node))
			(*P_BaseNode) = (*P_Node)->P_NextNode;
		else
		{
			Ptemp_Node = P_BaseNode;
			while((*Ptemp_Node)->P_NextNode != (*P_Node))
				Ptemp_Node = &((*Ptemp_Node)->P_NextNode);
			(*Ptemp_Node)->P_NextNode = (*P_Node)->P_NextNode;
		}
	}
	free((*P_Node));
	return LLS_Done;
}

/*===============================================================*/
