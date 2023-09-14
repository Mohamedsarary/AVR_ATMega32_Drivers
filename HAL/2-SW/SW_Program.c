/*
 *  	Created on: 13/09/2023
 *      LAYER : HAL
 *      Author: Mohamed sarary
 *      File  : SW_Program.c
 */

#include "SW_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../SERVICES/StdTypes.h"
#include "../../SERVICES/ErrorStates.h"

u8 SW_u8Init(u8 Copy_u8Port, u8 Copy_u8Pin) {
	u8 Func_State = Func_NOK;
	DIO_u8Set_Pin_Dir(Copy_u8Port, Copy_u8Pin, DIO_u8_PIN_INPUT);
	Func_State = Func_OK;
	return Func_State;

}

/* u8 SW_u8Get_State(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_SW_Mode,	u8* Copy_u8SwitchState)
{
	u8 Func_state = Func_NOK;
	u8* Local_u8Pin_State = 0;

	DIO_Read_Pin_Val(Copy_u8Port, Copy_u8Pin,&Local_u8Pin_State);
	switch (Copy_SW_Mode) {
	case SW_EXT_PULLUP:
	case SW_INT_PULLUP:
		if (*Local_u8Pin_State == 0) {
			*Copy_u8SwitchState = SW_PRESSED;
			Func_state = Func_OK;
		}
		else if (*Local_u8Pin_State == 1) {
			*Copy_u8SwitchState = SW_NOT_PRESSED;
			Func_state = Func_OK;

		}
		break;

	case SW_EXT_PULLDOWN:
		if (*Local_u8Pin_State == 0) {
			*Copy_u8SwitchState = SW_NOT_PRESSED;
			Func_state = Func_OK;
		} else if (*Local_u8Pin_State == 1) {
			*Copy_u8SwitchState = SW_PRESSED;
			Func_state = Func_OK;
		}
		break;
	}

}
*/


u8 SW_u8Get_State(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_SW_Mode)
{
	u8 *Local_u8SWState = 0 ;
	DIO_Read_Pin_Val(Copy_u8Port, Copy_u8Pin,&Local_u8SWState);
	switch (Copy_SW_Mode) {
	case SW_EXT_PULLUP:
	case SW_INT_PULLUP:
		if (*Local_u8SWState == 0) {
			return SW_PRESSED ;
		}
		else if (*Local_u8SWState == 1) {
			return SW_NOT_PRESSED ;
		}
		break;

	case SW_EXT_PULLDOWN:
		if (*Local_u8SWState == 0)
		{
			return 0 ;
		} else if (*Local_u8SWState == 1) {
			return 1 ;
		}
		break;
	}

}
