/*
 *  	Created on: 28/09/2023
 *      LAYER : HAL
 *      Author: Mohamed sarary
 *      File  : KPD_Interface.h
 */


#ifndef HAL_KPD_KPD_INTERFACE_H_
#define HAL_KPD_KPD_INTERFACE_H_

#include "../../SERVICES/StdTypes.h"

void Keypad_voidInit(void);
u8 Keypad_u8GetPressed(void);

#endif /* HAL_KPD_KPD_INTERFACE_H_ */
