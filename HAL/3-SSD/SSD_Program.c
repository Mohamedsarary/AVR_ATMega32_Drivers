/*
 *  	Created on: 13/09/2023
 *      LAYER : HAL
 *      Author: Mohamed sarary
 *      File  : SSD_Program.c
 */

#include "SSD_Interface.h"
#include "SSD_Private.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../SERVICES/BitMath.h"
#include "../../SERVICES/ErrorStates.h"
#include "util/delay.h"


u8 SSD_u8Init(u8 Copy_u8Port) {
	u8 Func_State = Func_NOK;
	DIO_u8Set_Port_Dir(Copy_u8Port, DIO_u8_PORT_OUTPUT);
	Func_State = Func_OK;
	return Func_State;
}

u8 SSD_u8Display_Number(u8 Copy_u8Port, u8 Copy_u8SSDMode, u8 Copy_u8Number) {
	u8 Func_State = Func_NOK;
	switch (Copy_u8SSDMode) {
	case SSD_CommonCathod:
		DIO_u8Set_Port_Val(Copy_u8Port, SSD_Data[Copy_u8Number]);
		Func_State = Func_OK;
		break;

	case SSD_CommonAnode:
		DIO_u8Set_Port_Val(Copy_u8Port, ~SSD_Data[Copy_u8Number]);
		Func_State = Func_OK;
		break;
	}
	return Func_State;
}

u8 SSD_u8Display_Counter(u8 Copy_u8Port, u8 Copy_u8SSDMode, u8 Copy_u8CounterMode) {
	u8 Func_State = Func_NOK;
	switch (Copy_u8SSDMode) {
	case SSD_CommonCathod:
		switch (Copy_u8CounterMode) {
		case SSD_CountUP:
			for (u8 SSD_Counter = 0; SSD_Counter < 10; SSD_Counter++) {
				DIO_u8Set_Port_Val(Copy_u8Port, SSD_Data[SSD_Counter]);
				_delay_ms(1000);

			}
			Func_State = Func_OK;
			break;

		case SSD_CountDown:
			for (u8 SSD_Counter = 10; SSD_Counter > 0; SSD_Counter++) {
				DIO_u8Set_Port_Val(Copy_u8Port, SSD_Data[SSD_Counter]);
				_delay_ms(1000);
			}
			Func_State = Func_OK;
			break;
		}
		break;

	case SSD_CommonAnode:
		switch (Copy_u8CounterMode) {
		case SSD_CountUP:
			for (u8 SSD_Counter = 0; SSD_Counter < 10; SSD_Counter++) {
				DIO_u8Set_Port_Val(Copy_u8Port, ~SSD_Data[SSD_Counter]);
				_delay_ms(1000);
			}
			Func_State = Func_OK;
			break;

		case SSD_CountDown:
			for (u8 SSD_Counter = 10; SSD_Counter > 0; SSD_Counter++) {
				DIO_u8Set_Port_Val(Copy_u8Port, ~SSD_Data[SSD_Counter]);
				_delay_ms(1000);
			}
			Func_State = Func_OK;
			break;
		}
		break;
	}
	return Func_State ;
}
