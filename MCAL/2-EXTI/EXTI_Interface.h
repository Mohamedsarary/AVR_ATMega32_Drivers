/*
 *  	Created on: 11/05/2023
 *      Driver: EXTI Driver
 *      Author: Mohamed sarary
 *      File  : EXTI_Interface.h
 */

#include "../../SERVICES/STD_TYPES.h"

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_


/* 				Interrupt Modes		 	*/
#define EXTI_LOWLEVEL 		0
#define EXTI_ANYCHANGE 		1
#define EXTI_FALLINGEDGE 	2
#define EXTI_RISINGEDGE 	3

#define EXTI_LINE0 		0
#define EXTI_LINE1		1
#define EXTI_LINE2		2

u8 GIE_u8ENB(void);
u8 GIE_u8DIS(void);
u8 EXTI_u8Init(void);
u8 EXTI_u8ENB(void);
u8 EXTI_u8DIS(void);
u8 EXTI_u8ClearFlag(void);


#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
