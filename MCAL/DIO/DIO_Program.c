/*
 *  	Created on: 15/03/2023
 *      Driver: DIO Driver
 *      Author: Mohamed sarary
 *      File  : DIO_Program.c
 */

#include "../../Services/STD_TYPES.h"
#include "../../Services/BIT_MATH.h"

#include "DIO_interface.h";
#include "DIO_Private.h" ;
#include "DIO_Confing.h";

void DIO_Set_Port_Dir(u8 Copy_u8Port, u8 Copy_u8Direction) {
	switch (Copy_u8Port) {
	case DIO_u8PortA:
		DDRA = Copy_u8Direction;
		break;
	case DIO_u8PortB:
		DDRB = Copy_u8Direction;
		break;
	case DIO_u8PortC:
		DDRC = Copy_u8Direction;
		break;
	case DIO_u8PortD:
		DDRD = Copy_u8Direction;
		break;
	}
}

void DIO_Set_Port_Val(u8 Copy_u8Port, u8 Copy_u8Value) {
	switch (Copy_u8Port) {
	case DIO_u8PortA:
		PORTA = Copy_u8Value;
		break;
	case DIO_u8PortB:
		PORTB = Copy_u8Value;
		break;
	case DIO_u8PortC:
		PORTC = Copy_u8Value;
		break;
	case DIO_u8PortD:
		PORTD = Copy_u8Value;
		break;
	}

}

void DIO_Set_Pin_Dir(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction) {
	switch (Copy_u8Port) {
	case DIO_u8PortA:
		switch (Copy_u8Direction) {
		case DIO_u8_OUTPUT:
			SET_BIT(DDRA, Copy_u8Pin);
			break;

		case DIO_u8_INPUT:
			CLR_BIT(DDRA, Copy_u8Pin);
			break;
		}
		break;
	case DIO_u8PortB:
		switch (Copy_u8Direction) {
		case DIO_u8_OUTPUT:
			SET_BIT(DDRB, Copy_u8Pin);
			break;

		case DIO_u8_INPUT:
			CLR_BIT(DDRB, Copy_u8Pin);
			break;
		}
		;
		break;
	case DIO_u8PortC:
		switch (Copy_u8Direction) {
		case DIO_u8_OUTPUT:
			SET_BIT(DDRC, Copy_u8Pin);
			break;

		case DIO_u8_INPUT:
			CLR_BIT(DDRC, Copy_u8Pin);
			break;
		}
		;
		break;
	case DIO_u8PortD:
		switch (Copy_u8Direction) {
		case DIO_u8_OUTPUT:
			SET_BIT(DDRD, Copy_u8Pin);
			break;

		case DIO_u8_INPUT:
			CLR_BIT(DDRD, Copy_u8Pin);
			break;
		}
		;
		break;
	}

}

void DIO_Set_Pin_Val(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value) {
	switch (Copy_u8Port) {
	case DIO_u8PortA:
		switch (Copy_u8Value) {
		case DIO_u8_HIGH:
			SET_BIT(PORTA, Copy_u8Pin);
			break;

		case DIO_u8_LOW:
			CLR_BIT(PORTA, Copy_u8Pin);
			break;
		}
		break;
	case DIO_u8PortB:
		switch (Copy_u8Value) {
		case DIO_u8_HIGH:
			SET_BIT(PORTB, Copy_u8Pin);
			break;

		case DIO_u8_LOW:
			CLR_BIT(PORTB, Copy_u8Pin);
			break;
		}
		;
		break;
	case DIO_u8PortC:
		switch (Copy_u8Value) {
		case DIO_u8_HIGH:
			SET_BIT(PORTC, Copy_u8Pin);
			break;

		case DIO_u8_LOW:
			CLR_BIT(PORTC, Copy_u8Pin);
			break;
		}
		;
		break;
	case DIO_u8PortD:
		switch (Copy_u8Value) {
		case DIO_u8_HIGH:
			SET_BIT(PORTD, Copy_u8Pin);
			break;

		case DIO_u8_LOW:
			CLR_BIT(PORTD, Copy_u8Pin);
			break;
		}
		;
		break;
	}

}

u8 DIO_Read_Pin_Val(u8 Copy_u8Port, u8 Copy_u8Pin) {
	u8 Local_u8_PINSTATE = 0;
	switch (Copy_u8Port) {
	case DIO_u8PortA:
		Local_u8_PINSTATE = GET_BIT(PINA, Copy_u8Pin);
		break;
	case DIO_u8PortB:
		Local_u8_PINSTATE = GET_BIT(PINB, Copy_u8Pin);
		break;
	case DIO_u8PortC:
		Local_u8_PINSTATE = GET_BIT(PINC, Copy_u8Pin);
		break;
	case DIO_u8PortD:
		Local_u8_PINSTATE = GET_BIT(PIND, Copy_u8Pin);
		break;
	}
	return Local_u8_PINSTATE;
}

void DIO_ACT_PULLUP(u8 Copy_u8Port, u8 Copy_u8Pin) {
	/*Define PORT As INPUT ( DDRA = 0x00 ) Then Use Register PORT ( PORTA = 0xFF ) so i Actived the PULLUP Resistor of The PORT*/

	switch (Copy_u8Port) {
	case DIO_u8PortA:
		CLR_BIT(DDRA, Copy_u8Pin);
		SET_BIT(PORTA, Copy_u8Pin);
		break;
	case DIO_u8PortB:
		CLR_BIT(DDRB, Copy_u8Pin);
		SET_BIT(PORTB, Copy_u8Pin);
		break;
	case DIO_u8PortC:
		CLR_BIT(DDRC, Copy_u8Pin);
		SET_BIT(PORTC, Copy_u8Pin);
		break;
	case DIO_u8PortD:
		CLR_BIT(DDRD, Copy_u8Pin);
		SET_BIT(PORTD, Copy_u8Pin);
		break;
	}

}

