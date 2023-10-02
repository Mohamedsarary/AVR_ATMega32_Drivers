/*
 *  	Created on: 27/09/2023
 *      LAYER : MCAL
 *      Author: Mohamed sarary
 *      File  : USART_Interface.h
 */

#ifndef MCAL_USART_USART_INTERFACE_H_
#define MCAL_USART_USART_INTERFACE_H_

#include "../../SERVICES/StdTypes.h"
/*************************************************************************************************************/
/*********************************************** USART INTERFACES ********************************************/
/*************************************************************************************************************/

#define DISABLE				 	0
#define ENABLE				 	1

#define USART_X1				1
#define USART_X2				2

#define USART_ASYNC				0
#define USART_SYNC				1

#define	STOP_1BIT				0
#define	STOP_2BIT				1

#define EVEN_PARITY				0
#define ODD_PARITY				1

#define DATA_5BITS				0
#define DATA_6BITS				1
#define DATA_7BITS				2
#define DATA_8BITS				3
#define DATA_9BITS				4

#define XCK_RISING_TX_XCH_FALLING_RX			0
#define XCK_RISING_RX_XCH_FALLING_TX			1

#define UBRRL_MAX								256


/*************************************************************************************************************/
/******************************************* USART FUNCTIONS PROTOTYPE ***************************************/
/*************************************************************************************************************/

void USART_voidInit(void);

u16 USART_voidSendData(u8 Copy_u8Data );
u16 USART_u16Receive();

u8 USART_u8SendStringSynch (const u8 * Copy_u8PString);
u8 USART_u8ReceiveStringSynch (u8 * Copy_u8PString , u32 Copy_u32BufferSize);


void USART_u8SendStringAsunch( u8* Copy_u8PString , void (* NotificationFunc)(void) );
void USART_u8ReceiveStringAsunch(u8 *Copy_u8RecString , u32 Copy_u32BufferSize ,  void (* NotificationFunc)(void) );


#endif /* MCAL_USART_USART_INTERFACE_H_ */
