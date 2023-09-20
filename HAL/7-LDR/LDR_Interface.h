/*
 *  	Created on: 20/09/2023
 *      LAYER : HAL
 *      Author: Mohamed sarary
 *      File  : LDR_Interface.h
 */

#ifndef HAL_LDR_LDR_INTERFACE_H_
#define HAL_LDR_LDR_INTERFACE_H_

#include "../../SERVICES/StdTypes.h"

u8  LDR_u8Init(void);
u32 LDR_GetVal(u8 Copy_u8CHANNEL);

#endif /* HAL_LDR_LDR_INTERFACE_H_ */
