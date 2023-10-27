/*
 *  	Created on: 23/10/2023
 *      LAYER : MCAL
 *      Author: Mohamed sarary
 *      File  : I2C_Program.c
 */

#include "I2C_Config.h"
#include "I2C_Interface.h"
#include "I2C_Private.h"

#include "../../SERVICES/StdTypes.h"
#include "../../SERVICES/BitMath.h"


void I2C_voidInitMaster(void)
{
	/* SET THE BIT RATE TO THE REGISTER USING THE EQUATION */
	TWBR =  (u8) ( ( ( F_CPU/  SCL_CLOCK ) - 16 ) / (2 * I2C_PRESCALLER ) );

#if	I2C_PRESCALLER == I2C_FREQ_DIV_BY1
	TWSR = 0 ;
#elif I2C_PRESCALLER == I2C_FREQ_DIV_BY4
	TWSR = 1 ;
#elif I2C_PRESCALLER == I2C_FREQ_DIV_BY16
	TWSR = 2 ;
#elif I2C_PRESCALLER == I2C_FREQ_DIV_BY64
	TWSR = 3 ;

#else
#error "WRONG I2C PRESCALLER OPTION"
#endif


#if I2C_ACK_STATE == I2C_ACK_ENB
	SET_BIT(TWCR,TWCR_TWEA);
#elif I2C_ACK_STATE == I2C_ACK_DIS
	CLR_BIT(TWCR,TWCR_TWEA);
#else
#error	"WRONG I2C ACKNOWLEDGE OPTION"
#endif


	/* I2C ENABLE */
	SET_BIT(TWCR,TWCR_TWEN);
}

void I2C_void_InitSlave (u8 Copy_u8Address)
{
	TWAR = ( Copy_u8Address << 1 );

#if I2C_ACK_STATE == I2C_ACK_ENB
	SET_BIT(TWCR,TWCR_TWEA);
#elif I2C_ACK_STATE == I2C_ACK_DIS
	CLR_BIT(TWCR,TWCR_TWEA);
#else
#error	"WRONG I2C ACKNOWLEDGE OPTION"
#endif

#if I2C_GEN_CALL_REC_STATE == I2C_GEN_CALL_REC_DIS
	CLR_BIT(TWAR,TWAR_TWGCE);
#elif I2C_GEN_CALL_REC_STATE == I2C_GEN_CALL_REC_ENB
	SET_BIT(TWAR,TWAR_TWGCE);
#else
#error "WRONG I2C CALL RECOGNITION OPTION"
#endif

	/* DISABLE STOP CONDITION */
	CLR_BIT(TWCR,TWCR_TWSTO);
	/* I2C ENABLE */
	SET_BIT(TWCR,TWCR_TWEN);
}

I2C_ErrorStatus I2C_voidStartCondition (void)
{
	I2C_ErrorStatus Loc_Error = NoError ;

	/* SEND START CONDITION */
	SET_BIT(TWCR,TWCR_TWSTA);

	/* CLEAR FLAG */
	SET_BIT(TWCR,TWCR_TWINT);

	/* WAIT ULTIL THE CURRENT OPERATION IS DONE */
	while(GET_BIT(TWCR,TWCR_TWINT)==0);

	/* CHECK IF THE START CONDITION IS DONE */
	if( (TWSR & 0xF8) != START_ACK )
	{
		Loc_Error = StartCondError ;
	}
	else
	{
	}
	return Loc_Error ;
}

I2C_ErrorStatus I2C_voidREPStartCondition (void)
{
	I2C_ErrorStatus Loc_Error = NoError ;

	/* SEND START CONDITION */
	SET_BIT(TWCR,TWCR_TWSTA);

	/* CLEAR FLAG  */
	SET_BIT(TWCR,TWCR_TWINT);

	/* WAIT ULTIL THE CURRENT OPERATION IS DONE */
	while(GET_BIT(TWCR,TWCR_TWINT)==0);

	/* CHECK IF THE START CONDITION IS DONE */
	if( (TWSR & 0xF8) != REP_START_ACK )
	{
		Loc_Error = RepStartError ;
	}
	else
	{
	}
	return Loc_Error ;
}

void I2C_voidStopCondition (void)
{
	/* SEND STOP CONDITION */
	SET_BIT(TWCR,TWCR_TWSTO);

	/* CLEAR FLAG  */
	CLR_BIT(TWCR,TWCR_TWINT);

}


I2C_ErrorStatus I2C_SendSlaveAdd_WithWriteReq(u8 Copy_u8SlaveAddress) {
	I2C_ErrorStatus Loc_Error = NoError;

	if (Copy_u8SlaveAddress != 0) {
		/* Send the 7 Bit data to the Bus */
		TWDR = (Copy_u8SlaveAddress << 1);

		/* Set Write Request to the LSB */
		CLR_BIT(TWDR, 0);

		/* Clear Start Condition */
		CLR_BIT(TWCR, TWCR_TWSTA);

		/* Clear Flag */
		SET_BIT(TWCR, TWCR_TWINT);

		/* Wait Until Operation Finished and Flag is Raised */
		while (GET_BIT(TWCR,TWCR_TWINT) == 0);

		if ((TWSR & 0xF8) != SLAVE_ADD_AND_WR_ACK) {
			Loc_Error = SlaveAddWriteError;
		} else {
			/* Do no thing */
		}

	} else {
		Loc_Error = NullAddress;
	}
	return Loc_Error;
}

I2C_ErrorStatus I2C_SendSlaveAdd_WithReadReq(u8 Copy_u8SlaveAddress) {
	I2C_ErrorStatus Loc_Error = NoError;

	if (Copy_u8SlaveAddress != 0) {

		/* Send the 7 Bit data to the Bus */
		TWDR = (Copy_u8SlaveAddress << 1);

		/* Set Write Request to the LSB */
		CLR_BIT(TWDR, 0);

		/* Clear Start Condition */
		CLR_BIT(TWCR, TWCR_TWSTA);

		/* Clear Flag */
		SET_BIT(TWCR, TWCR_TWINT);

		/* Wait Until Operation Finished and Flag is Raised */
		while (GET_BIT(TWCR,TWCR_TWINT) == 0);

		if ((TWSR & 0xF8) != SLAVE_ADD_AND_RD_ACK)
		{
			Loc_Error = SlaveAddReadError;
		} else
		{
			/* Do No Thing */
		}

	} else {
		Loc_Error = NullAddress;
	}
	return Loc_Error;
}

I2C_ErrorStatus I2C_MasterWriteByte (u8 Copy_u8Data)
{
	I2C_ErrorStatus Loc_Error = NoError ;

	/* Send 8bit Data to the Bus */
	TWDR = Copy_u8Data ;

	/* Clear Flag to Start the Operation */
	SET_BIT(TWCR, TWCR_TWINT);

	/* Wait Until Operation Finished and Flag is Raised */
	while (GET_BIT(TWCR,TWCR_TWINT) == 0);

	if ( ( TWSR & 0xF8 ) != MSTR_WR_BYTE_ACK )
	{
		Loc_Error = MasterWriteByteError ;
	}
	else
	{
		/* Do No Thing */
	}
	return Loc_Error ;
}

I2C_ErrorStatus I2C_MasterReadByte (u8* Copy_pu8Data)
{
	I2C_ErrorStatus Loc_Error = NoError ;

	/* Clear Flag to Start the Operation */
	SET_BIT(TWCR, TWCR_TWINT);

	/* Wait Until Operation Finished and Flag is Raised */
	while (GET_BIT(TWCR,TWCR_TWINT) == 0);

	if ( ( TWSR & 0xF8 ) != MSTR_RD_BYTE_WITH_ACK )
	{
		Loc_Error = MasterReadByteError ;
	}
	else
	{
		*Copy_pu8Data = TWDR ;
	}
	return Loc_Error ;

}

I2C_ErrorStatus I2C_SlaveWriteByte(u8 Copy_u8Data)
{
	I2C_ErrorStatus Loc_Error = NoError ;

	/* Send 8bit Data to the Bus */
	TWDR = Copy_u8Data ;

	/* Clear Flag to Start the Operation */
	SET_BIT(TWCR, TWCR_TWINT);

	/* Wait Until Operation Finished and Flag is Raised */
	while (GET_BIT(TWCR,TWCR_TWINT) == 0);

	if ( ( TWSR & 0xF8 ) != SLAVE_BYTE_TRANSMITTED )
	{
		Loc_Error = SlaveWriteByteErr ;
	}
	else
	{
		/* Do No Thing */
	}
	return Loc_Error ;

}

I2C_ErrorStatus I2C_SlaveReadByte(u8* Copy_pu8Data)
{
	I2C_ErrorStatus Loc_Error = NoError ;

	/* Clear Flag to Start the Operation */
	SET_BIT(TWCR, TWCR_TWINT);

	/* Wait Until Operation Finished and Flag is Raised */
	while (GET_BIT(TWCR,TWCR_TWINT) == 0);

	if ( ( TWSR & 0xF8 ) != SLAVE_ADD_RCVD_WR_REQ )
	{
		Loc_Error = SlaveReadByteErr ;
	}
	else
	{
		*Copy_pu8Data = TWDR ;
	}
	return Loc_Error ;

}
