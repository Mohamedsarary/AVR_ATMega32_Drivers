/*
 *  	Created on: 09/07/2023
 *      LAYER : HAL
 *      Author: Mohamed sarary
 *      File  : CLCD_Program.c
 */

#include "CLCD_Config.h"
#include "CLCD_Interface.h"
#include "CLCD_Private.h"
#include "../../SERVICES/BitMath.h""
#include "../../SERVICES/StdTypes.h""
#include "../../MCAL/DIO/DIO_interface.h"
#include "util/delay.h"


void CLCD_voidInit(void)
{
	/*	SELECT ALL PINS OF LCD OUTPUT */
	DIO_u8Set_Port_Dir( CLCD_DATA_PORT , DIO_u8_PORT_OUTPUT );
	DIO_u8Set_Pin_Dir( CLCD_CONTROL_PORT , CLCD_RS_PIN , DIO_u8_PIN_OUTPUT );
	DIO_u8Set_Pin_Dir( CLCD_CONTROL_PORT , CLCD_EN_PIN , DIO_u8_PIN_OUTPUT );
	DIO_u8Set_Pin_Dir( CLCD_CONTROL_PORT , CLCD_RW_PIN , DIO_u8_PIN_OUTPUT );
	DIO_u8Set_Pin_Val( CLCD_CONTROL_PORT , CLCD_RW_PIN , DIO_u8_PIN_LOW	   );


	/* INITIALIZAION OF 8Bit-MODE CLCD */
	_delay_ms(50);

	/* 		FUNCTION SET	 */
	CLCD_voidSendCommand(CLCD_u8SET_FUNCTION);
	_delay_ms(1);

	/* 	DISPLAY ON/OFF CONTROL 	*/
	CLCD_voidSendCommand(CLCD_u8DISPLAY_CONTROL);
	_delay_ms(1);

	/* 		DISPLAY CLEAR 		*/
	CLCD_voidSendCommand(CLCD_u8DISPLAY_CLEAR);
	_delay_ms(5);


	/* 		ENTRY MODE SET 		*/
	CLCD_voidSendCommand(CLCD_u8_ENTRY_MODE);



}

void CLCD_voidSendData(u8 Copy_u8Data)
{
	/* 	SEND DATA USING DATA PORY 	 */
	DIO_u8Set_Port_Val( CLCD_DATA_PORT , Copy_u8Data );

	/* SELECT SENDING DATA IN RS PIN */
	DIO_u8Set_Pin_Val(CLCD_CONTROL_PORT,CLCD_RS_PIN,DIO_u8_PIN_HIGH);

	/* APPLY FALLING EDGE IN EN PIN */
	DIO_u8Set_Pin_Val(CLCD_CONTROL_PORT,CLCD_EN_PIN,DIO_u8_PIN_HIGH);
	_delay_ms(1);
	DIO_u8Set_Pin_Val(CLCD_CONTROL_PORT,CLCD_EN_PIN,DIO_u8_PIN_LOW);
	_delay_ms(1);

}

void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	/* 	SEND DATA USING DATA PORY 	 */
	DIO_u8Set_Port_Val( CLCD_DATA_PORT , Copy_u8Command );

	/* SELECT SENDING COMMAND IN RS PIN */
	DIO_u8Set_Pin_Val(CLCD_CONTROL_PORT,CLCD_RS_PIN,DIO_u8_PIN_LOW);

	/* APPLY FALLING EDGE IN EN PIN */
	DIO_u8Set_Pin_Val(CLCD_CONTROL_PORT,CLCD_EN_PIN,DIO_u8_PIN_HIGH);
	_delay_ms(1);
	DIO_u8Set_Pin_Val(CLCD_CONTROL_PORT,CLCD_EN_PIN,DIO_u8_PIN_LOW);
	_delay_ms(1);


}

void CLCD_voidSendString(u8 *Copy_u8PtrString)
{
	u8 Local_u8Iterator = 0 ;
	while(Copy_u8PtrString[Local_u8Iterator] != '\0')
	{
		CLCD_voidSendData(Copy_u8PtrString[Local_u8Iterator]);
		Local_u8Iterator++;
	}

}

void CLCD_voidSendNum(u64 Copy_u64Number)
{
	u64 Local_u64Reversed = 1 ;
	if ( Copy_u64Number == 0 )
	{
		CLCD_voidSendData('0');
	}
	else
	{
	/* 		FIRST WE SHOULD REVERSE THE NUMBER 		*/
	while (Copy_u64Number)
	{
		Local_u64Reversed = (Local_u64Reversed*10) + (Copy_u64Number%10);
		Copy_u64Number = Copy_u64Number / 10 ;
	}
	/* 		SECOND WE SHOULD PRINT THE REVERSED NUMBER	*/
	while (	Local_u64Reversed != 1)
	{
		CLCD_voidSendData( (Local_u64Reversed % 10 ) + '0' );
		Local_u64Reversed /= 10 ;
	}
	}
}

void CLCD_voidSetPosition(u8 Copy_u8Row , u8 Copy_u8Coloum	){

	if(Copy_u8Row == CLCD_u8_ROW_00){
		CLCD_voidSendCommand(CLCD_u8_DDRAM_OFFSET + Copy_u8Coloum);

	}
	else{
		CLCD_voidSendCommand(CLCD_u8_DDRAM_OFFSET + CLCD_u8_DDRAM_ROW2_OFFSET + Copy_u8Coloum);
	}


}

void CLCD_voidClearLCD(void)
{
	CLCD_voidSendCommand(CLCD_u8_CLEAR_LCD_COMMAND);
}
