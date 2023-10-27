/*
 *  	Created on: 23/10/2023
 *      LAYER : MCAL
 *      Author: Mohamed sarary
 *      File  : I2C_Interface.h
 */

#ifndef MCAL_I2C_I2C_INTERFACE_H_
#define MCAL_I2C_I2C_INTERFACE_H_

#include "../../SERVICES/StdTypes.h"

typedef enum
{
	NoError,
	StartCondError,
	RepStartError,
	SlaveAddWriteError,
	SlaveAddReadError,
	MasterWriteByteError,
	MasterReadByteError,
	SlaveWriteByteErr,
	SlaveReadByteErr,
	NullAddress,

}I2C_ErrorStatus;

#define I2C_ACK_DIS			0
#define I2C_ACK_ENB			1

#define I2C_FREQ_DIV_BY1		0
#define I2C_FREQ_DIV_BY4		1
#define I2C_FREQ_DIV_BY16		2
#define I2C_FREQ_DIV_BY64		3

#define I2C_GEN_CALL_REC_DIS	0
#define I2C_GEN_CALL_REC_ENB	1

/*************************************************************************************************************/
/********************************************* I2C FUNCTIONS PROTOTYPE ***************************************/
/*************************************************************************************************************/

void I2C_voidInitMaster(void);
void I2C_void_InitSlave (u8 Copy_u8Address);
void I2C_voidStopCondition (void);

I2C_ErrorStatus I2C_voidStartCondition (void);
I2C_ErrorStatus I2C_voidREPStartCondition (void);
I2C_ErrorStatus I2C_SendSlaveAdd_WithWriteReq (u8 Copy_u8SlaveAddress);
I2C_ErrorStatus I2C_SendSlaveAdd_WithReadReq (u8 Copy_u8SlaveAddress);
I2C_ErrorStatus I2C_MasterWriteByte(u8 Copy_u8Data);
I2C_ErrorStatus I2C_MasterReadByte (u8* Copy_pu8Data);
I2C_ErrorStatus I2C_SlaveWriteByte(u8 Copy_u8Data);
I2C_ErrorStatus I2C_SlaveReadByte(u8* Copy_pu8Data);

#endif /* MCAL_I2C_I2C_INTERFACE_H_ */
