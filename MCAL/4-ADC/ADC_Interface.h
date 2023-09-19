/*
 *  	Created on: 18/09/2023
 *      LAYER : MCAL
 *      Author: Mohamed sarary
 *      File  : ADC_Interface.h
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_


#define AREF				0
#define AVCC				1
#define INT_2_56			2


#define ADC_LEFT_ADJ		0
#define ADC_RIGHT_ADJ		1

#define ADC_DIV_2			1
#define ADC_DIV_4			2
#define ADC_DIV_8			3
#define ADC_DIV_16			4
#define ADC_DIV_32			5
#define ADC_DIV_64			6
#define ADC_DIV_128			7


#define ADC_SINGLE_CONV		0
#define ADC_AUTO_TRIG		1

#define ADC_FREE_RUNNING	0
#define ADC_ANALOG_COMP		1
#define ADC_EXTI_REQ0		2
#define ADC_TIMER0_CMP		3
#define ADC_TIMER0_OVF		4
#define ADC_TIMER1_CMP		5
#define ADC_TIMER1_OVF		6
#define ADC_TIMER1_CP_EV	7

#define ADC_CH0				0
#define ADC_CH1				1
#define ADC_CH2				2
#define ADC_CH3				3
#define ADC_CH4				4
#define ADC_CH5				5
#define ADC_CH6				6
#define ADC_CH7				7

u8 ADC_u8Init(void);
u8 ADC_u8ENB(void);
u8 ADC_u8DIS(void);
u8 ADC_INTENB(void);
u8 ADC_INTDIS(void);
u16 ADC_u8GetChannelVal(u8 Copy_u8CHANNEL );


#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
