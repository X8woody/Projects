/*
 * App.h
 *
 *  Created on: Dec 29, 2024
 *      Author: Abdulrhman
 */

#ifndef APP_H_
#define APP_H_

/*====================Includes========================*/

#include "student.h"

/*====================Macros========================*/

#define DELAY   1000000
#define Dwel    500
#define DMoni   300

/*====================Type_Definitions========================*/



/*====================Global_Variables========================*/

extern LLS_BaseNode* gp_BaseStudent;
extern uint32_t Count;

/*====================ProtoTypes========================*/

void Delay(uint32_t delay);
uint8_t Main_App();
/*===============================================================*/

#endif /* APP_H_ */
