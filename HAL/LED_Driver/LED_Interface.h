/*
 *  	Created on: 13/09/2023
 *      LAYER : HAL
 *      Author: Mohamed sarary
 *      File  : LED_Interface.h
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

#include "../../SERVICES/StdTypes.h"

#define LED_ACT_LOW	   	   0
#define LED_ACT_HIGH	   1

u8 LED_u8Init 	(u8 Copy_u8Port , u8 Copy_u8Pin);
u8 LED_u8TurnON (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8LED_MODE);
u8 LED_u8TurnOFF (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8LED_MODE);
u8 LED_u8TOGGLE (u8 Copy_u8Port , u8 Copy_u8Pin);

#endif /* HAL_LED_LED_INTERFACE_H_ */
