/*
 *  	Created on: 15/03/2023
 *      Driver: DIO Driver
 *      Author: Mohamed sarary
 *      File  : DIO_Interface.h
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

#include "../../Services/STD_TYPES.h"



/*i can use Enum instead of it*/
#define DIO_u8PortA  0
#define DIO_u8PortB  1
#define DIO_u8PortC  2
#define DIO_u8PortD  3

#define DIO_u8_PORT_INPUT   0
#define DIO_u8_PORT_OUTPUT  0XFF

#define DIO_u8_PORT_LOW   0
#define DIO_u8_PORT_HIGH  0XFF

#define DIO_u8_INPUT  0
#define DIO_u8_OUTPUT 1

#define DIO_u8_PIN_00 0
#define DIO_u8_PIN_01 1
#define DIO_u8_PIN_02 2
#define DIO_u8_PIN_03 3
#define DIO_u8_PIN_04 4
#define DIO_u8_PIN_05 5
#define DIO_u8_PIN_06 6
#define DIO_u8_PIN_07 7

#define DIO_u8_HIGH 1
#define DIO_u8_LOW  0

void DIO_Set_Port_Dir(u8 Copy_u8Port , u8 Copy_u8Direction);

void DIO_Set_Port_Val(u8 Copy_u8Port , u8 Copy_u8Value);

void DIO_Set_Pin_Dir(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Direction);

void DIO_Set_Pin_Val(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value);

u8 DIO_Read_Pin_Val (u8 Copy_u8Port , u8 Copy_u8Pin );

void DIO_ACT_PULLUP(u8 Copy_u8Port , u8 Copy_u8Pin );

#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
