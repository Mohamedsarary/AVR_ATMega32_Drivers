/*
 *  	Created on: 18/09/2023
 *      LAYER : HAL
 *      Author: Mohamed sarary
 *      File  : LDR_Program.c
 */

#include "LDR_Config.h"
#include "LDR_Private.h"
#include "LDR_Interface.h"


#include"../../SERVICES/StdTypes.h"
#include"../../SERVICES/ErrorStates.h"
#include "../../MCAL/ADC/ADC_Interface.h"

u8  LDR_u8Init(void)
{	u8 Func_State = Func_NOK;
	ADC_u8Init();
	Func_State = Func_OK ;
	return Func_State ;
}
u32 LDR_GetVal(u8 Copy_u8CHANNEL)
{
	u16 Local_u16DigitalVal = 0 ;
	u16 Local_u16AnalogVal = 0 ;
	u16 Local_u16Res = 0 ;

	Local_u16DigitalVal = ADC_u8GetChannelVal(Copy_u8CHANNEL);

	Local_u16AnalogVal = (5*Local_u16DigitalVal)/1023 ;

	Local_u16Res = (1000 * Local_u16AnalogVal)/(5-Local_u16AnalogVal);

	return Local_u16Res ;

}
