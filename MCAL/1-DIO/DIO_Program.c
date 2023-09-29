/*
 *  	Created on: 30/04/2023
 *      LAYER : MCAL
 *      Author: Mohamed sarary
 *      File  : DIO_Program.c
 */

#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "../../SERVICES/ErrorStates.h"
#include "../../SERVICES/BitMath.h"
#include "../../SERVICES/StdTypes.h"

u8 DIO_u8Set_Port_Dir(u8 Copy_u8Port, u8 Copy_u8Direction) {

	u8 Func_State = Func_NOK;
	switch (Copy_u8Port) {
	case DIO_u8PortA:
		DDRA = Copy_u8Direction;
		Func_State = Func_OK;
		break;
	case DIO_u8PortB:
		DDRB = Copy_u8Direction;
		Func_State = Func_OK;
		break;
	case DIO_u8PortC:
		DDRC = Copy_u8Direction;
		Func_State = Func_OK;
		break;
	case DIO_u8PortD:
		DDRD = Copy_u8Direction;
		Func_State = Func_OK;
		break;
	}
	return Func_State;
}

u8 DIO_u8Set_Port_Val(u8 Copy_u8Port, u8 Copy_u8Value) {
	u8 Func_State = Func_NOK;
	switch (Copy_u8Port) {
	case DIO_u8PortA:
		PORTA = Copy_u8Value;
		Func_State = Func_OK;
		break;
	case DIO_u8PortB:
		PORTB = Copy_u8Value;
		Func_State = Func_OK;
		break;
	case DIO_u8PortC:
		PORTC = Copy_u8Value;
		Func_State = Func_OK;
		break;
	case DIO_u8PortD:
		PORTD = Copy_u8Value;
		Func_State = Func_OK;
		break;
	}
	return Func_State;
}

u8 DIO_u8Set_Pin_Dir(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction) {
	u8 Func_State = Func_NOK;
	switch (Copy_u8Port) {
	case DIO_u8PortA:
		switch (Copy_u8Direction) {
		case DIO_u8_PIN_OUTPUT:
			SET_BIT(DDRA, Copy_u8Pin);
			Func_State = Func_OK;
			break;

		case DIO_u8_PIN_INPUT:
			CLR_BIT(DDRA, Copy_u8Pin);
			Func_State = Func_OK;
			break;
		}
		break;
	case DIO_u8PortB:
		switch (Copy_u8Direction) {
		case DIO_u8_PIN_OUTPUT:
			SET_BIT(DDRB, Copy_u8Pin);
			Func_State = Func_OK;
			break;

		case DIO_u8_PIN_INPUT:
			CLR_BIT(DDRB, Copy_u8Pin);
			Func_State = Func_OK;
			break;
		}
		break;
	case DIO_u8PortC:
		switch (Copy_u8Direction) {
		case DIO_u8_PIN_OUTPUT:
			SET_BIT(DDRC, Copy_u8Pin);
			Func_State = Func_OK;
			break;

		case DIO_u8_PIN_INPUT:
			CLR_BIT(DDRC, Copy_u8Pin);
			Func_State = Func_OK;
			break;
		}
		break;
	case DIO_u8PortD:
		switch (Copy_u8Direction) {
		case DIO_u8_PIN_OUTPUT:
			SET_BIT(DDRD, Copy_u8Pin);
			Func_State = Func_OK;
			break;

		case DIO_u8_PIN_INPUT:
			CLR_BIT(DDRD, Copy_u8Pin);
			Func_State = Func_OK;
			break;
		}
		break;
	}
	return Func_State;
}

u8 DIO_u8Set_Pin_Val(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value) {
	u8 Func_State = Func_NOK;
	switch (Copy_u8Port) {
	case DIO_u8PortA:
		switch (Copy_u8Value) {
		case DIO_u8_PIN_HIGH:
			SET_BIT(PORTA, Copy_u8Pin);
			Func_State = Func_OK;
			break;

		case DIO_u8_PIN_LOW:
			CLR_BIT(PORTA, Copy_u8Pin);
			Func_State = Func_OK;
			break;
		}
		break;
	case DIO_u8PortB:
		switch (Copy_u8Value) {
		case DIO_u8_PIN_HIGH:
			SET_BIT(PORTB, Copy_u8Pin);
			Func_State = Func_OK;
			break;

		case DIO_u8_PIN_LOW:
			CLR_BIT(PORTB, Copy_u8Pin);
			Func_State = Func_OK;
			break;
		}
		break;
	case DIO_u8PortC:
		switch (Copy_u8Value) {
		case DIO_u8_PIN_HIGH:
			SET_BIT(PORTC, Copy_u8Pin);
			Func_State = Func_OK;
			break;

		case DIO_u8_PIN_LOW:
			CLR_BIT(PORTC, Copy_u8Pin);
			Func_State = Func_OK;
			break;
		}
		break;
	case DIO_u8PortD:
		switch (Copy_u8Value) {
		case DIO_u8_PIN_HIGH:
			SET_BIT(PORTD, Copy_u8Pin);
			Func_State = Func_OK;
			break;

		case DIO_u8_PIN_LOW:
			CLR_BIT(PORTD, Copy_u8Pin);
			Func_State = Func_OK;
			break;
		}
		break;
	}
	return Func_State;
}

u8 DIO_Read_Pin_Val(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_u8PinValue) {
	// *Copy_u8PinValue = 0;
	u8 Func_State = Func_NOK;
	switch (Copy_u8Port) {
	case DIO_u8PortA:
		*Copy_u8PinValue = GET_BIT(PINA, Copy_u8Pin);
		Func_State = Func_OK;
		break;
	case DIO_u8PortB:
		*Copy_u8PinValue = GET_BIT(PINB, Copy_u8Pin);
		Func_State = Func_OK;
		break;
	case DIO_u8PortC:
		*Copy_u8PinValue = GET_BIT(PINC, Copy_u8Pin);
		Func_State = Func_OK;
		break;
	case DIO_u8PortD:
		*Copy_u8PinValue = GET_BIT(PIND, Copy_u8Pin);
		Func_State = Func_OK;
		break;
	}
	return Func_State;
}

u8 DIO_GET_Pin_Val(u8 Copy_u8Port, u8 Copy_u8Pin) {
	u8 Copy_u8PinValue = 0;
	u8 Func_State = Func_NOK;
	switch (Copy_u8Port) {
	case DIO_u8PortA:
		Copy_u8PinValue = GET_BIT(PINA, Copy_u8Pin);
		break;
	case DIO_u8PortB:
		Copy_u8PinValue = GET_BIT(PINB, Copy_u8Pin);
		break;
	case DIO_u8PortC:
		Copy_u8PinValue = GET_BIT(PINC, Copy_u8Pin);
		break;
	case DIO_u8PortD:
		Copy_u8PinValue = GET_BIT(PIND, Copy_u8Pin);
		break;
	}
	return Copy_u8PinValue;
}

u8 DIO_u8ACT_PULLUP(u8 Copy_u8Port, u8 Copy_u8Pin) {
	/*Define PORT As INPUT ( DDRA = 0x00 ) Then Use Register PORT ( PORTA = 0xFF ) so i Actived the PULLUP Resistor of The PORT*/
	u8 Func_State = Func_NOK;
	switch (Copy_u8Port) {
	case DIO_u8PortA:
		CLR_BIT(DDRA, Copy_u8Pin);
		SET_BIT(PORTA, Copy_u8Pin);
		Func_State = Func_OK;
		break;
	case DIO_u8PortB:
		CLR_BIT(DDRB, Copy_u8Pin);
		SET_BIT(PORTB, Copy_u8Pin);
		Func_State = Func_OK;
		break;
	case DIO_u8PortC:
		CLR_BIT(DDRC, Copy_u8Pin);
		SET_BIT(PORTC, Copy_u8Pin);
		Func_State = Func_OK;
		break;
	case DIO_u8PortD:
		CLR_BIT(DDRD, Copy_u8Pin);
		SET_BIT(PORTD, Copy_u8Pin);
		break;
	}
	return Func_State;
}

u8 DIO_u8Toggle_Pin(u8 Copy_u8Port, u8 Copy_u8Pin) {
	u8 Func_State = Func_NOK;
	switch (Copy_u8Port) {
	case DIO_u8PortA:
		TOGGEL_BIT(PORTA, Copy_u8Pin);
		Func_State = Func_OK;
		break;
	case DIO_u8PortB:
		TOGGEL_BIT(PORTB, Copy_u8Pin);
		Func_State = Func_OK;
		break;
	case DIO_u8PortC:
		TOGGEL_BIT(PORTC, Copy_u8Pin);
		Func_State = Func_OK;
		break;
	case DIO_u8PortD:
		TOGGEL_BIT(PORTD, Copy_u8Pin);
		Func_State = Func_OK;
		break;
	}
	return Func_State;
}
