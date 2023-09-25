/*
 *  	Created on: 24/09/2023
 *      LAYER : MCAL
 *      Author: Mohamed sarary
 *      File  : TIMER_Private.h
 */

#ifndef MCAL_TIMER_TIMER_PRIVATE_H_
#define MCAL_TIMER_TIMER_PRIVATE_H_

#include "../../SERVICES/StdTypes.h"

#define NULL				0
#define WDT_PRS_MASK		0b11111000

/*************************************************************************************************************/
/************************************ TIMERS REGISTER ADDRESSES **********************************************/
/*************************************************************************************************************/

/* TIMERS COMMON REGISTERS */
#define TIMSK	*((volatile u8*)(0x59))
#define TIFR	*((volatile u8*)(0x59))

/* TIMER 0 REGISTERS */
#define TCCR0	*((volatile u8*)(0x53))
#define TCNT0   *((volatile u8*)(0x52))
#define OCR0	*((volatile u8*)(0x5C))

/* TIMER 1 REGISTERS */
#define TCCR1A  *((volatile u8*)(0x4F))
#define TCCR1B  *((volatile u8*)(0x4E))
#define TCNT1   *((volatile u8*)(0x4C))
#define OCR1A   *((volatile u8*)(0x4A))
#define OCR1B   *((volatile u8*)(0x48))
#define ICR1    *((volatile u8*)(0x46))

/* TIMER 2 REGISTERS */
#define TCCR2   *((volatile u8*)(0x45))
#define TCNT2   *((volatile u8*)(0x44))
#define OCR2    *((volatile u8*)(0x43))

/* WATCH DOG TIMER REGISTERS */
#define WDTCR	*((volatile u8*)(0x41))
#define MCUCSR	*((volatile u8*)(0x54))

/*************************************************************************************************************/
/***************************************** END OF REGISTER ADDRESSES *****************************************/
/*************************************************************************************************************/

/*************************************************************************************************************/
/*****************************************  TIMERS REGISTER BITS *********************************************/
/*************************************************************************************************************/

/* TIMSK REGISTER BITS */
#define TIMSK_TOIE0		0
#define TIMSK_OCIE0		1
#define TIMSK_TOIE1		2
#define TIMSK_OCIE1B	3
#define TIMSK_OCIE1A	4
#define TIMSK_TICIE1	5
#define TIMSK_TOIE2		6
#define TIMSK_OCIE2		7

/* TIFR REGISTER BITS */
#define TIFR_TOV0		0
#define TIFR_OCF0		1
#define TIFR_TOV1		2
#define TIFR_OCF1B		3
#define TIFR_OCF1A		4
#define TIFR_ICF1		5
#define TIFR_TOV2		6
#define TIFR_OCF2		7

/* TCCR0 REGISTER BITS */
#define TCCR0_CS00		0
#define TCCR0_CS01		1
#define TCCR0_CS02		2
#define TCCR0_WGM01		3
#define TCCR0_COM00		4
#define TCCR0_COM01		5
#define TCCR0_WGM00		6
#define TCCR0_FOC0		7

/* TCCR1A REGISTER BITS */
#define TCCR1A_COM1A1	7
#define TCCR1A_COM1A0	6
#define TCCR1A_COM1B1	5
#define TCCR1A_COM1B0	4
#define TCCR1A_FOC1A	3
#define TCCR1A_FOC1B	2
#define TCCR1A_WGM11	1
#define TCCR1A_WGM10	0

/* TCCR1B REGISTER BITS */
#define TCCR1B_ICNC1	7
#define TCCR1B_ICES1	6
#define TCCR1B_WGM13	4
#define TCCR1B_WGM12	3
#define	TCCR1B_CS12		2
#define TCCR1B_CS11		1
#define TCCR1B_CS10		0

/* TIFR REGISTER BITS */
#define TIFR_ICF1		5
#define TIFR_OCF1A		4
#define TIFR_OCF1B		3
#define TIFR_TOV1		2

/* TCCR2 REGISTER BITS */
#define	TCCR2_FOC2		7
#define TCCR2_WGM20		6
#define TCCR2_COM21		5
#define TCCR2_COM20		4
#define TCCR2_WGM21		3
#define	TCCR2_CS22		2
#define	TCCR2_CS21		1
#define	TCCR2_CS20		0

#define TIMSK_TOIE2		6
#define TIMSK_OCIE2		7

#define TIFR_TOV2		6
#define TIFR_OCF2		7

#define WDTCR_WDP0		0
#define WDTCR_WDP1		1
#define WDTCR_WDP2		2
#define WDTCR_WDE		3
#define WDTCR_WDTOE		4

/*************************************************************************************************************/
/**************************************  END OF TIMERS REGISTER BITS *****************************************/
/*************************************************************************************************************/

/*************************************************************************************************************/
/******************************************** TIMERS ISR VECTOR IDS ******************************************/
/*************************************************************************************************************/
void __vector_11 (void) __attribute__ ((signal));		/*	TIMER 0 OVF MODE ISR ID */
void __vector_10 (void) __attribute__ ((signal));		/*	TIMER 0 CTC MODE ISR ID */
void __vector_9  (void) __attribute__ ((signal));		/*	TIMER 1 OVF MODE ISR ID */
void __vector_8  (void) __attribute__ ((signal));		/*	TIMER 1 COMP B MODE ISR ID */
void __vector_7  (void) __attribute__ ((signal));		/*	TIMER 1 COMP A MODE ISR ID */
void __vector_6  (void) __attribute__ ((signal));		/*	TIMER 1 CAPT MODE ISR ID */
void __vector_5  (void) __attribute__ ((signal));		/*	TIMER 2 OVF MODE ISR ID */
void __vector_4  (void) __attribute__ ((signal));		/*	TIMER 2 CTC MODE ISR ID */

/*************************************************************************************************************/
/**************************************** END OF TIMERS ISR VECTOR IDS ***************************************/
/*************************************************************************************************************/

static void (*TIMER0_OVF_PCallBack)(void) = NULL;
static void (*TIMER0_CTC_PCallBack)(void) = NULL;
static void (*TIMER1_OVF_PCallBack)(void) = NULL;
static void (*TIMER1_CTC_CHANNELA_PCallBack)(void) = NULL;
static void (*TIMER1_CTC_CHANNELB_PCallBack)(void) = NULL;
static void (*TIMER1_INU_PCallBack)(void) = NULL;
static void (*TIMER2_OVF_PCallBack)(void) = NULL;
static void (*TIMER2_CTC_PCallBack)(void) = NULL;

#endif /* MCAL_TIMER_TIMER_PRIVATE_H_ */
