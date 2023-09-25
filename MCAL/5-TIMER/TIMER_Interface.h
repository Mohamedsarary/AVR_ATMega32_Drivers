/*
 *  	Created on: 24/09/2023
 *      LAYER : MCAL
 *      Author: Mohamed sarary
 *      File  : TIMER_Interface.h
 */

#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_

#include "../../SERVICES/BitMath.h"

#define TIMER_u8_TIMER_0	0
#define TIMER_u8_TIMER_1	1
#define TIMER_u8_TIMER_2	2




/*************************************************************************************************************/
/********************************************** TIMER 0 INTERFACES *******************************************/
/*************************************************************************************************************/
#define TIMER0_u8_NORMAL				0
#define TIMER0_u8_PWM_PHASE_CORRECT		1
#define TIMER0_u8_CTC					2
#define TIMER0_u8_FAST_PWM				3

#define TIMER0_u8_OC0_DISCONNECTED		0
#define TIMER0_u8_OC0_TOGGLE			1
#define TIMER0_u8_OC0_CLEAR				2
#define TIMER0_u8_OC0_SET				3

#define	TIMER0_u8_STOP					0
#define	TIMER0_u8_DIV_BY_1				1
#define TIMER0_u8_DIV_BY_8				2
#define TIMER0_u8_DIV_BY_64				3
#define TIMER0_u8_DIV_BY_256			4
#define TIMER0_u8_DIV_BY_1024			5

#define	TIMER0_u8_DISABLE_INTERRUPT		0
#define	TIMER0_u8_ENABLE_INTERRUPT		1


/*************************************************************************************************************/
/********************************************** TIMER 1 INTERFACES *******************************************/
/*************************************************************************************************************/
#define TIMER1_u8_NORMAL								0
#define TIMER1_u8_PWM_PHASE_CORRECT_8BIT				1
#define TIMER1_u8_PWM_PHASE_CORRECT_9BIT				2
#define TIMER1_u8_PWM_PHASE_CORRECT_10BIT				3
#define TIMER1_u8_CTC_OCR1A								4
#define TIMER1_u8_FAST_PWM_8BIT							5
#define TIMER1_u8_FAST_PWM_9BIT							6
#define TIMER1_u8_FAST_PWM_10BIT						7
#define TIMER1_u8_PWM_PHASE_FREQUANCY_CORRECT_ICR1		8
#define TIMER1_u8_PWM_PHASE_FREQUANCY_CORRECT_OCR1A		9
#define TIMER1_u8_PWM_PHASE_CORRECT_ICR1				10
#define TIMER1_u8_PWM_PHASE_CORRECT_OCR1A				11
#define TIMER1_u8_CTC_ICR1								12
#define TIMER1_u8_FAST_PWM_ICR1							13
#define TIMER1_u8_FAST_PWM_OCR1A						14

#define TIMER1_u8_OC1_DISCONNECTED			0
#define TIMER1_u8_OC1_TOGGLE				1
#define TIMER1_u8_OC1_CLEAR					2
#define TIMER1_u8_OC1_SET					3

#define	TIMER1_u8_STOP						0
#define	TIMER1_u8_DIV_BY_1					1
#define TIMER1_u8_DIV_BY_8					2
#define TIMER1_u8_DIV_BY_64					3
#define TIMER1_u8_DIV_BY_256				4
#define TIMER1_u8_DIV_BY_1024				5


#define	TIMER1_u8_FALLING_INPUT_CAPTURE		0
#define	TIMER1_u8_RISING_INPUT_CAPTURE		1


/*************************************************************************************************************/
/********************************************** TIMER 2 INTERFACES *******************************************/
/*************************************************************************************************************/
#define TIMER2_u8_NORMAL				0
#define TIMER2_u8_PWM_PHASE_CORRECT		1
#define TIMER2_u8_CTC					2
#define TIMER2_u8_FAST_PWM				3

#define TIMER2_u8_OC2_DISCONNECTED		0
#define TIMER2_u8_OC2_TOGGLE			1
#define TIMER2_u8_OC2_CLEAR				2
#define TIMER2_u8_OC2_SET				3

#define	TIMER2_u8_STOP					0
#define	TIMER2_u8_DIV_BY_1				1
#define TIMER2_u8_DIV_BY_8				2
#define TIMER2_u8_DIV_BY_32				3
#define TIMER2_u8_DIV_BY_64				4
#define TIMER2_u8_DIV_BY_128			5
#define TIMER2_u8_DIV_BY_256			6
#define TIMER2_u8_DIV_BY_1024			7

#define	TIMER2_u8_DISABLE_INTERRUPT		0
#define	TIMER2_u8_ENABLE_INTERRUPT		1


/*************************************************************************************************************/
/*****************************************  WATCH DOG TIMER  INTERFACES **************************************/
/*************************************************************************************************************/
#define WDT_PRS_16_3		0		/*  (16.3ms) */
#define WDT_PRS_32_5		1		/*  (32.5ms) */
#define WDT_PRS_65			2		/*  (65ms) 	 */
#define WDT_PRS_0_13		3		/*  (0.13ms) */
#define WDT_PRS_0_26		4		/*  (0.26ms) */
#define WDT_PRS_0_52		5		/*  (0.52ms) */
#define WDT_PRS_1_0			6		/*  (1.0ms)  */
#define WDT_PRS_2_1			7		/*  (2.1ms)  */

void TIMER_voidInit(void);

/*************************************************************************************************************/
/***************************************** TIMER 0 FUNCTIONS PROTOTYPE ***************************************/
/*************************************************************************************************************/

void TIMER0_voidSetOVFRegister(u8 Copy_u8Value);
void TIMER0_voidSetCTCRegister(u8 Copy_u8Value);

void TIMER0_voidEnableOVFINT(void);
void TIMER0_voidDisableOVFINT(void);
void TIMER0_voidClearOVFFlag(void);

void TIMER0_voidEnableCTCINT(void);
void TIMER0_voidDisableCTCINT(void);
void TIMER0_voidClearCTCFlag(void);

void TIMER0_voidSetOVFCallBack(void (*Copy_pvoidCallBack) (void));
void TIMER0_voidSetCTCCallBack(void (*Copy_pvoidCallBack) (void));
void TIMER0_voidForceOutputCompare(void);


/*************************************************************************************************************/
/***************************************** TIMER 1 FUNCTIONS PROTOTYPE ***************************************/
/*************************************************************************************************************/

void TIMER1_voidSetOVFRegister(u16 Copy_u16Value);
void TIMER1_voidChannelASetCTCRegister(u16 Copy_u16Value);
void TIMER1_voidChannelBSetCTCRegister(u16 Copy_u16Value);
u16	 TIMER1_u16InputCaptureValue(void);


void TIMER1_voidEnableOVFINT(void);
void TIMER1_voidDisableOVFINT(void);
void TIMER1_voidClearOVFFlag(void);


void TIMER1_voidChannelAEnableCTCINT(void);
void TIMER1_voidChannelADisableCTCINT(void);
void TIMER1_voidChannelAClearCTCFlag(void);

void TIMER1_voidChannelBEnableCTCINT(void);
void TIMER1_voidChannelBDisableCTCINT(void);
void TIMER1_voidChannelBClearCTCFlag(void);

void TIMER1_voidEnableInputCaptureINT(void);
void TIMER1_voidDisableInputCaptureINT(void);
void TIMER1_voidClearInputCaptureFlag(void);

void TIMER1_voidSetOVFCallBack(void (*Copy_pvoidCallBack) (void));
void TIMER1_voidChannelASetCTCCallBack(void (*Copy_pvoidCallBack) (void));
void TIMER1_voidChannelBSetCTCCallBack(void (*Copy_pvoidCallBack) (void));
void TIMER1_voidSetInputCaptureCallBack(void (*Copy_pvoidCallBack) (void));

void TIMER1_voidChannelAForceOutputCompare(void);
void TIMER1_voidChannelBForceOutputCompare(void);



/*************************************************************************************************************/
/***************************************** TIMER 2 FUNCTIONS PROTOTYPE ***************************************/
/*************************************************************************************************************/

void TIMER2_voidSetOVFRegister(u8 Copy_u8Value);
void TIMER2_voidSetCTCRegister(u8 Copy_u8Value);

void TIMER2_voidEnableOVFINT(void);
void TIMER2_voidDisableOVFINT(void);
void TIMER2_voidClearOVFFlag(void);

void TIMER2_voidEnableCTCINT(void);
void TIMER2_voidDisableCTCINT(void);
void TIMER2_voidClearCTCFlag(void);

void TIMER2_voidSetOVFCallBack(void (*Copy_pvoidCallBack) (void));
void TIMER2_voidSetCTCCallBack(void (*Copy_pvoidCallBack) (void));

void TIMER2_voidForceOutputCompare(void);


/*************************************************************************************************************/
/************************************** WATCH DOG TIMER FUNCTIONS PROTOTYPE **********************************/
/*************************************************************************************************************/
void TIMER_voidWDTSLEEP(void);
void TIMER_voidWDTENB(void);
void TIMER_voidWDTDIS(void);


#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
