/*
 * filehandle.h
 *
 *  Created on: Dec 25, 2024
 *      Author: Abdulrhman
 */

#ifndef FILEHANDLE_H_
#define FILEHANDLE_H_
/*====================Includes========================*/

#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "linkedlist.h"

/*====================Macros========================*/



/*====================Type_Definitions========================*/

typedef enum
{
	FH_Error,
	FH_OK
}FH_STATUS;


/*====================ProtoTypes========================*/

FH_STATUS init_file();
FILE* backup_data();
void get_data();
uint8_t send_data(LLS_BaseNode* P_Student);
void check_list();
void check_ID();
void delete_specific_line(uint32_t line);
void check_Courses();

/*===============================================================*/


#endif /* FILEHANDLE_H_ */
