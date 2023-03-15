/*
 *  	Created on: 15/03/2023
 *      Driver: CLCD Driver
 *      Author: Mohamed sarary
 *      File  : CLCD_Program.c
 */

#include "../../MCAL/DIO/DIO_interface.h"
#include "CLCD_Confing.h"
#include "CLCD_Private.h"
#include "CLCD_Interface.h"
#include <util/delay.h>

void CLCD_voidinit(void) {

	_delay_ms(50);

	DIO_Set_Port_Dir(CLCD_DATA_PORT, DIO_u8_PORT_OUTPUT);
	DIO_Set_Port_Dir(CLCD_CTR_PORT, DIO_u8_PORT_OUTPUT);
	DIO_Set_Pin_Dir(CLCD_CTR_PORT, CLCD_RS_PIN, DIO_u8_OUTPUT);
	DIO_Set_Pin_Dir(CLCD_CTR_PORT, CLCD_EN_PIN, DIO_u8_OUTPUT);
	DIO_Set_Pin_Dir(CLCD_CTR_PORT, CLCD_RW_PIN, DIO_u8_OUTPUT);
	DIO_Set_Pin_Val(CLCD_CTR_PORT, CLCD_RW_PIN, DIO_u8_LOW);
	/* Function Set of the LCD */
	CLCD_voidSend_Command(CLCD_u8_SetFun);
	_delay_ms(1);
	CLCD_voidSend_Command(CLCD_u8_Dis_Ctr);
	_delay_ms(2);
	CLCD_voidSend_Command(CLCD_u8_ENT_MOD);


}

void CLCD_voidSend8b_data(u8 copy_u8data) {
	DIO_Set_Port_Val(CLCD_DATA_PORT, copy_u8data);

	DIO_Set_Pin_Val(CLCD_CTR_PORT, CLCD_RS_PIN, DIO_u8_HIGH);

	CLCD_voidLatch();

}

void CLCD_voidSend_Command(u8 copy_u8command) {

	DIO_Set_Port_Val(CLCD_DATA_PORT, copy_u8command);

	DIO_Set_Pin_Val(CLCD_CTR_PORT, CLCD_RS_PIN, DIO_u8_LOW);

	CLCD_voidLatch();

}

void CLCD_voidSend_String(s8* copy_u8String) {
	u8 Local_u8_iterator = 0;

	while (copy_u8String[Local_u8_iterator] != '\0') {
		CLCD_voidSend8b_data(copy_u8String[Local_u8_iterator]);

		Local_u8_iterator++;
	}

}

void CLCD_voidSend_num(u16 copy_u16Number) {

	/* First Step to reverse the Number */
	u16 Local_u16_Reversed = 1;
	if (copy_u16Number == 0) {
		CLCD_voidSend8b_data('0');
	}
	else {
		while (copy_u16Number != 0) {
			/* for Examble copy_u16Number = 1234 --> 1- Local = 0 * 10 + 1234 % 10 (4) = 4    , Copy = 123
			 * 										 2- Local = 4 * 10 + 123 % 10 (3)  = 43   , Copy = 12
			 * 										 3- Local = 40 * 10 + 12 % 10 (2)  = 432  , Copy = 1
			 * 										 4-Local = 432 * 10 + 1 % 10 (1)  = 4321  , Copy = 0
			 * 										                    END OF WHILE
			 */
			Local_u16_Reversed = (Local_u16_Reversed * 10)
					+ (copy_u16Number % 10);
			copy_u16Number = copy_u16Number / 10;
		}

		/* Second Step to Devied the Number and Print it*/
		while (Local_u16_Reversed != 1) {
			CLCD_voidSend8b_data((Local_u16_Reversed % 10) + '0');
			Local_u16_Reversed = Local_u16_Reversed / 10;

		}
	}

}

void CLCD_voidLatch(void) {

	DIO_Set_Pin_Val(CLCD_CTR_PORT, CLCD_EN_PIN, DIO_u8_HIGH);
	_delay_ms(1);
	DIO_Set_Pin_Val(CLCD_CTR_PORT, CLCD_EN_PIN, DIO_u8_LOW);
	_delay_ms(1);

}

void CLCD_voidCLCD_Clear(void) {

	CLCD_voidSend_Command(CLCD_u8_Clear);

}

void CLCD_u8Set_Position(u8 copy_u8Row ,u8 copy_u8coloum)
{

	if(copy_u8Row == CLCD_u8_ROW_01)
	{
		CLCD_voidSend_Command(CLCD_u8_DDRM_Base + copy_u8coloum );
	}
	else
	{
		CLCD_voidSend_Command(CLCD_u8_DDRM_Base + copy_u8coloum + CLCD_u8_DDRM_ROW2_OFFSET);
	}


}

void CLCD_voidSendEXTR_Char()
{
	u8 Local_u8Iterator = 0 ;
	/* First Step is going to CGRAM */
	CLCD_voidSend_Command(CLCD_u8_CGRAM_ADD);

	/* First Step is Entering the Sympol */
	for (Local_u8Iterator = 0 ;Local_u8Iterator < (sizeof(Loc_u8StaArr)/sizeof(Loc_u8StaArr[0])) ; Local_u8Iterator++ )
	{
		CLCD_voidSend8b_data(Loc_u8StaArr[Local_u8Iterator]);
	}

}
