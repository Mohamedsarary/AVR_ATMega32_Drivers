/*
 *  	Created on: 30/04/2023
 *      LAYER : MCAL
 *      Author: Mohamed sarary
 *      File  : DIO_Interface.h
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

#include "../../SERVICES/StdTypes.h"

/*i can use Enum instead of it*/
#define DIO_u8PortA  0
#define DIO_u8PortB  1
#define DIO_u8PortC  2
#define DIO_u8PortD  3

#define DIO_u8_PORT_INPUT   0
#define DIO_u8_PORT_OUTPUT  0XFF

#define DIO_u8_PORT_LOW   0
#define DIO_u8_PORT_HIGH  0XFF

#define DIO_u8_PIN_INPUT  0
#define DIO_u8_PIN_OUTPUT 1

#define DIO_u8_PIN_HIGH 1
#define DIO_u8_PIN_LOW  0

#define DIO_u8_PIN_00 0
#define DIO_u8_PIN_01 1
#define DIO_u8_PIN_02 2
#define DIO_u8_PIN_03 3
#define DIO_u8_PIN_04 4
#define DIO_u8_PIN_05 5
#define DIO_u8_PIN_06 6
#define DIO_u8_PIN_07 7


u8 DIO_u8Set_Port_Dir(u8 Copy_u8Port , u8 Copy_u8Direction);

u8 DIO_u8Set_Port_Val(u8 Copy_u8Port , u8 Copy_u8Value);

u8 DIO_u8Set_Pin_Dir(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Direction);

u8 DIO_u8Set_Pin_Val(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value);

u8 DIO_Read_Pin_Val(u8 Copy_u8Port, u8 Copy_u8Pin , u8* Copy_u8PinValue) ;

u8 DIO_u8ACT_PULLUP(u8 Copy_u8Port , u8 Copy_u8Pin );

u8 DIO_u8Toggle_Pin(u8 Copy_u8Port , u8 Copy_u8Pin );

#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
