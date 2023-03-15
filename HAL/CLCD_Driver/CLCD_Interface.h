/*
 *  	Created on: 15/03/2023
 *      Driver: CLCD Driver
 *      Author: Mohamed sarary
 *      File  : CLCD_Interface.h
 */

#ifndef HAL_CLCD_DRIVER_CLCD_INTERFACE_H_
#define HAL_CLCD_DRIVER_CLCD_INTERFACE_H_
#include "../../Services/STD_TYPES.h"
#include "../../Services/BIT_MATH.h"

void CLCD_voidinit(void);

void CLCD_voidSend_Command(u8 copy_u8command);

void CLCD_voidSend8b_data(u8 copy_u8data);

void CLCD_voidLatch(void);

void CLCD_voidSend_String(s8* copy_u8String);

void CLCD_u8Set_Position(u8 copy_u8Row, u8 copy_u8coloum);

void CLCD_voidSend_num(u16 copy_u16Number);

void CLCD_voidSendEXTR_Char();

void CLCD_voidCLCD_Clear(void);

#endif /* HAL_CLCD_DRIVER_CLCD_INTERFACE_H_ */
