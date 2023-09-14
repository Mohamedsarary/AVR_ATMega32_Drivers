/*
 *  	Created on: 13/09/2023
 *      LAYER : HAL
 *      Author: Mohamed sarary
 *      File  : SW_Interface.h
 */

#ifndef HAL_SW_SW_INTERFACE_H_
#define HAL_SW_SW_INTERFACE_H_

#include "../../SERVICES/StdTypes.h"

#define SW_FLOATING			0
#define SW_EXT_PULLUP		1
#define SW_EXT_PULLDOWN		2
#define SW_INT_PULLUP		3

#define SW_NOT_PRESSED		0
#define SW_PRESSED			1


u8 SW_u8Init (u8 Copy_u8Port , u8 Copy_u8Pin);
//u8 SW_u8Get_State (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_SW_Mode , u8* Copy_u8SwitchState );
u8 SW_u8Get_State(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_SW_Mode);
#endif /* HAL_SW_SW_INTERFACE_H_ */
