/*

 *  	Created on: 14/09/2023
 *      LAYER : HAL
 *      Author: Mohamed sarary
 *      File  : GIE_Program.c
*/
#include "../../SERVICES/StdTypes.h"
#include "../../SERVICES/ErrorStates.h"
#include "../../SERVICES/BitMath.h"

#include "GIE_Private.h"
#include "GIE_Interface.h"

u8 GIE_u8ENB() {
	u8 Func_State = Func_NOK;
	SET_BIT(SREG,GIE_I);
    Func_State = Func_OK;
	return Func_State;

}

u8 GIE_u8DIS() {

	u8 Func_State = Func_NOK;
	CLR_BIT(SREG, GIE_I);
	Func_State = Func_OK;
	return Func_State;

}

