/*
 *  	Created on: 13/09/2023
 *      LAYER : HAL
 *      Author: Mohamed sarary
 *      File  : SSD_Interface.h
 */

#ifndef HAL_SSD_SSD_INTERFACE_H_
#define HAL_SSD_SSD_INTERFACE_H_

#include "../../SERVICES/StdTypes.h"

#define SSD_CountDown 	 0
#define SSD_CountUP		 1

#define SSD_CommonCathod 0
#define SSD_CommonAnode	 1

u8 SSD_u8Init (u8 Copy_u8Port);
u8 SSD_u8Display_Number (u8 Copy_u8Port , u8 Copy_u8SSDMode , u8 Copy_u8Number );
u8 SSD_u8Display_Counter(u8 Copy_u8Port , u8 Copy_u8SSDMode , u8 Copy_u8CounterMode);


#endif /* HAL_SSD_SSD_INTERFACE_H_ */
