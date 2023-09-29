/*
 *  	Created on: 28/09/2023
 *      LAYER : HAL
 *      Author: Mohamed sarary
 *      File  : KPD_Program.c
 */

#include "KPD_Config.h"
#include "KPD_Interface.h"
#include "KPD_Private.h"

#include "util/delay.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../SERVICES/ErrorStates.h"
#include "../../SERVICES/StdTypes.h"

void Keypad_voidInit(void) {
	/* SET ALL ROWS PINS AS INPUT INTERNAL PULL UP */
	DIO_u8ACT_PULLUP(KPD_PORT, KPD_R1_PIN);
	DIO_u8ACT_PULLUP(KPD_PORT, KPD_R2_PIN);
	DIO_u8ACT_PULLUP(KPD_PORT, KPD_R3_PIN);
	DIO_u8ACT_PULLUP(KPD_PORT, KPD_R4_PIN);

	/* SET ALL COLUMNS PINS AS OUTPUT */
	DIO_u8Set_Pin_Dir(KPD_PORT, KPD_C1_PIN, DIO_u8_PIN_OUTPUT);
	DIO_u8Set_Pin_Dir(KPD_PORT, KPD_C2_PIN, DIO_u8_PIN_OUTPUT);
	DIO_u8Set_Pin_Dir(KPD_PORT, KPD_C3_PIN, DIO_u8_PIN_OUTPUT);
	DIO_u8Set_Pin_Dir(KPD_PORT, KPD_C4_PIN, DIO_u8_PIN_OUTPUT);

	/* SET ALL COLUMNS PINS AS HIGH */
	DIO_u8Set_Pin_Val(KPD_PORT, KPD_C1_PIN, DIO_u8_PIN_HIGH);
	DIO_u8Set_Pin_Val(KPD_PORT, KPD_C2_PIN, DIO_u8_PIN_HIGH);
	DIO_u8Set_Pin_Val(KPD_PORT, KPD_C3_PIN, DIO_u8_PIN_HIGH);
	DIO_u8Set_Pin_Val(KPD_PORT, KPD_C4_PIN, DIO_u8_PIN_HIGH);

}

u8 Keypad_u8GetPressed(void) {
	u8 LOC_u8RowsIter = 0;
	u8 LOC_u8ColuIter = 0;
	u8 LOC_ReturnData = 0;

	for (LOC_u8ColuIter = 0; LOC_u8ColuIter < 4; LOC_u8ColuIter++) {

		/* SET COLUMN AS LOW */
		DIO_u8Set_Pin_Val(KPD_PORT, Keypad_arrColPins[LOC_u8ColuIter],
				DIO_u8_PIN_LOW);

		for (LOC_u8RowsIter = 0; LOC_u8RowsIter < 4; LOC_u8RowsIter++)
		{

			if (DIO_GET_Pin_Val(KPD_PORT,
					Keypad_arrRowPins[LOC_u8RowsIter]) == DIO_u8_PIN_LOW)
			{
				_delay_ms(50);

				if (DIO_GET_Pin_Val(KPD_PORT,
						Keypad_arrRowPins[LOC_u8RowsIter]) == DIO_u8_PIN_LOW)
				{
					LOC_ReturnData = KeyPad_u8Buttons[LOC_u8RowsIter][LOC_u8ColuIter];
				}
				while (DIO_GET_Pin_Val(KPD_PORT,Keypad_arrRowPins[LOC_u8RowsIter]) == DIO_u8_PIN_LOW)
				{}
				break;

			}
		}
		/* SET COLUMN AS HIGH */
		DIO_u8Set_Pin_Val(KPD_PORT, Keypad_arrColPins[LOC_u8ColuIter],
				DIO_u8_PIN_HIGH);
	}
	return LOC_ReturnData;
}
