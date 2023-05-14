/*
 *  	Created on: 11/05/2023
 *      Driver: EXTI Driver
 *      Author: Mohamed sarary
 *      File  : EXTI_Program.c
 */

#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/errorStates.h"
#include "EXTI_Config.h"
#include "EXTI_Interface.h"
#include "EXTI_Private.h"

u8 GIE_u8ENB(void) {
	u8 Func_State = Func_NOK;
	SET_BIT(SREG, GIE_I);
	Func_State = Func_OK;
	return Func_State;
}

u8 GIE_u8DIS(void) {
	u8 Func_State = Func_NOK;
	CLR_BIT(SREG, GIE_I);
	Func_State = Func_OK;
	return Func_State;
}

u8 EXTI_u8Init(void) {
	u8 Func_State = Func_NOK;
	/* INTERRUPT LINE 0 Is Enable */
#ifdef EXTI_LINE0_EN

	/* INTERRUPT LINE 0 MODE : LOW LEVEL  */
#if EXTI0_MODE == EXTI_LOWLEVEL
	CLR_BIT(MCUCR,ISC00);
	CLR_BIT(MCUCR,ISC01);
	Func_State = Func_OK;
#endif

	/* INTERRUPT LINE 0 MODE : ANY CHANGE  */
#if EXTI0_MODE == EXTI_ANYCHANGE
	SET_BIT(MCUCR,ISC00);
	CLR_BIT(MCUCR,ISC01);
	Func_State = Func_OK;
#endif

	/* INTERRUPT LINE 0 MODE : FALLING EDGE  */
#if EXTI0_MODE == EXTI_FALLINGEDGE
	CLR_BIT(MCUCR, ISC00);
	SET_BIT(MCUCR, ISC01);
	Func_State = Func_OK;
#endif

	/* INTERRUPT LINE 0 MODE : RISING EDGE  */
#if EXTI0_MODE == EXTI_RISINGEDGE
	SET_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
	Func_State = Func_OK;
#endif
#endif

	/* INTERRUPT LINE 1 Is Enable */
#ifdef EXTI_LINE1_EN

	/* INTERRUPT LINE 1 MODE : LOW LEVEL  */
#if EXTI1_MODE == EXTI_LOWLEVEL
	CLR_BIT(MCUCR,ISC10);
	CLR_BIT(MCUCR,ISC11);
	Func_State = Func_OK;
#endif

	/* INTERRUPT LINE 1 MODE : ANY CHANGE  */
#if EXTI1_MODE == EXTI_ANYCHANGE
	SET_BIT(MCUCR,ISC10);
	CLR_BIT(MCUCR,ISC11);
	Func_State = Func_OK;
#endif

	/* INTERRUPT LINE 1 MODE : FALLING EDGE  */
#if EXTI1_MODE == EXTI_FALLINGEDGE
	CLR_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
	Func_State = Func_OK;
#endif

	/* INTERRUPT LINE 1 MODE : RISING EDGE  */
#if EXTI1_MODE == EXTI_RISINGEDGE
	SET_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
	Func_State = Func_OK;
#endif
#endif
	/* INTERRUPT LINE 2 Is Enable */
#ifdef EXTI_LINE2_EN

	/* INTERRUPT LINE 2 MODE : FALLING EDGE  */
#if EXTI2_MODE == EXTI_FALLINGEDGE
	CLR_BIT(MCUCSR,ISC2);
	Func_State = Func_OK;
#endif

	/* INTERRUPT LINE 2 MODE : RISING EDGE  */
#if EXTI2_MODE == EXTI_RISINGEDGE
	SET_BIT(MCUCSR,ISC2);
	Func_State = Func_OK;
#endif
#endif

	return Func_State;
}

u8 EXTI_u8ENB(void) {
	u8 Func_state = Func_NOK;
	/* ENABLE INTERRUPT LINE 0 */
#ifdef EXTI_LINE0_EN
	SET_BIT(GICR, INT0);
	Func_state = Func_OK;
#endif
	/* ENABLE INTERRUPT LINE 1 */
#ifdef EXTI_LINE1_EN
	SET_BIT(GICR,INT1);
	Func_state=Func_OK;
#endif
	/* ENABLE INTERRUPT LINE 2 */
#ifdef EXTI_LINE2_EN
	SET_BIT(GICR,INT2);
	Func_state=Func_OK;
#endif
	return Func_state;
}

u8 EXTI_u8DIS(void) {
	u8 Func_state = Func_NOK;
	/* DISABLE INTERRUPT LINE 0 */
#ifdef EXTI_LINE0_EN
	CLR_BIT(GICR, INT0);
	Func_state = Func_OK;
#endif
	/* DISABLE INTERRUPT LINE 1 */
#ifdef EXTI_LINE1_EN
	CLR_BIT(GICR,INT1);
	Func_state=Func_OK;
#endif
	/* DISABLE INTERRUPT LINE 2 */
#ifdef EXTI_LINE2_EN
	CLR_BIT(GICR,INT2);
	Func_state=Func_OK;
#endif
	return Func_state;
}

u8 EXTI_u8ClearFlag(void) {
	u8 Func_state = Func_NOK;
	/* INTERRUPT LINE 0 CLEAR FLAG */
#ifdef EXTI_LINE0_EN
	SET_BIT(GIFR, INTF0);
	Func_state = Func_OK;
#endif
	/* INTERRUPT LINE 1 CLEAR FLAG */
#ifdef EXTI_LINE1_EN
	SET_BIT(GIFR,INTF1);
	Func_state = Func_OK;
#endif
	/* INTERRUPT LINE 2 CLEAR FLAG */
#ifdef EXTI_LINE2_EN
	SET_BIT(GIFR,INTF2);
	Func_state = Func_OK;
#endif
	return Func_state ;
}

void INT0_CALLBACK(void (*Copy_voidFunc)(void)) {
	if (Copy_voidFunc != NULL) {
		INT0_PCallBack = Copy_voidFunc;
	}

}

void INT1_CALLBACK(void (*Copy_voidFunc)(void)) {
	if (Copy_voidFunc != NULL) {
		INT1_PCallBack = Copy_voidFunc;
	}

}

void INT2_CALLBACK(void (*Copy_voidFunc)(void)) {
	if (Copy_voidFunc != NULL) {
		INT2_PCallBack = Copy_voidFunc;
	}

}

void __vector_1(void)
{
	INT0_PCallBack();
}

void __vector_2(void)
{
	INT1_PCallBack();
}

void __vector_3(void)
{
	INT2_PCallBack();

}

