/*
 *  	Created on: 13/09/2023
 *      LAYER : HAL
 *      Author: Mohamed sarary
 *      File  : LED_Program.c
 */

#include "LED_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../SERVICES/BitMath.h"
#include "../../SERVICES/ErrorStates.h"
#include "../../SERVICES/StdTypes.h"


u8 LED_u8Init(u8 Copy_u8Port, u8 Copy_u8Pin) {
	u8 Func_State = Func_NOK;
	switch (Copy_u8Port) {
	case DIO_u8PortA:
		DIO_u8Set_Pin_Dir(DIO_u8PortA, Copy_u8Pin, DIO_u8_PIN_OUTPUT);
		DIO_u8Set_Pin_Val(DIO_u8PortA, Copy_u8Pin, DIO_u8_PIN_LOW);
		Func_State = Func_OK;
		break;

	case DIO_u8PortB:
		DIO_u8Set_Pin_Dir(DIO_u8PortB, Copy_u8Pin, DIO_u8_PIN_OUTPUT);
		DIO_u8Set_Pin_Val(DIO_u8PortB, Copy_u8Pin, DIO_u8_PIN_LOW);
		Func_State = Func_OK;
		break;

	case DIO_u8PortC:
		DIO_u8Set_Pin_Dir(DIO_u8PortC, Copy_u8Pin, DIO_u8_PIN_OUTPUT);
		DIO_u8Set_Pin_Val(DIO_u8PortC, Copy_u8Pin, DIO_u8_PIN_LOW);
		Func_State = Func_OK;
		break;

	case DIO_u8PortD:
		DIO_u8Set_Pin_Dir(DIO_u8PortD, Copy_u8Pin, DIO_u8_PIN_OUTPUT);
		DIO_u8Set_Pin_Val(DIO_u8PortD, Copy_u8Pin, DIO_u8_PIN_LOW);
		Func_State = Func_OK;
		break;
	}
	return Func_State ;
}
u8 LED_u8TurnON (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8LED_MODE)
{
	u8 Func_State = Func_NOK;
	switch (Copy_u8LED_MODE)
	{
	case LED_ACT_LOW :
		DIO_u8Set_Pin_Val(DIO_u8PortD, Copy_u8Pin, DIO_u8_PIN_LOW);
		Func_State = Func_OK;
		break ;

	case LED_ACT_HIGH :
		DIO_u8Set_Pin_Val(DIO_u8PortD, Copy_u8Pin, DIO_u8_PIN_HIGH);
		Func_State = Func_OK;
		break ;
	}
	return Func_State ;
}
u8 LED_u8TurnOFF (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8LED_MODE)
{
	u8 Func_State = Func_NOK;
		switch (Copy_u8LED_MODE)
		{
		case LED_ACT_LOW :
			DIO_u8Set_Pin_Val(DIO_u8PortD, Copy_u8Pin, DIO_u8_PIN_HIGH);
			Func_State = Func_OK;
			break ;

		case LED_ACT_HIGH :
			DIO_u8Set_Pin_Val(DIO_u8PortD, Copy_u8Pin, DIO_u8_PIN_LOW);
			Func_State = Func_OK;
			break ;
		}
		return Func_State ;

}
u8 LED_u8TOGGLE(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 Func_State = Func_NOK;
	DIO_u8Toggle_Pin(Copy_u8Port , Copy_u8Pin );
	Func_State = Func_OK ;
	return Func_State ;
}
