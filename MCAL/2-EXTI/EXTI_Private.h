/*
 *  	Created on: 15/09/2023
 *      LAYER : HAL
 *      Author: Mohamed sarary
 *      File  : EXTI_Private.h
 */

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_

#include "../../SERVICES/StdTypes.h"


#define MCUCR   *((u8 volatile*)(0x55))
#define MCUCSR  *((u8 volatile*)(0x54))
#define GICR  	*((u8 volatile*)(0x5B))
#define GIFR 	*((u8 volatile*)(0x5A))


/*   	 Register MCUCR BITS 		*/
/*    Interrupt 0 Modes Bits    */
#define ISC00 0
#define ISC01 1
/*    Interrupt 1 Modes Bits    */
#define ISC10 2
#define ISC11 3

/*   	 Register MCUCSR BITS 		*/
/*    Interrupt 2 Modes Bits    */
#define ISC2 6

/*   	 Register GICR BITS 		*/
#define INT0 6			/*    Interrupt 0 Enable Bit    */
#define INT1 7			/*    Interrupt 1 Enable Bit    */
#define INT2 5			/*    Interrupt 2 Enable Bit    */

/*   	 Register GIFR BITS 		*/
#define INTF0 6			/*    Interrupt 0 Flag Bit    */
#define INTF1 7			/*    Interrupt 1 Flag Bit    */
#define INTF2 5			/*    Interrupt 2 Flag Bit    */

/*	  INTERRUPT  LINE  0  ISR 		*/
void __vector_1 (void) __attribute__ ((signal));
/*	  INTERRUPT  LINE  1  ISR 		*/
void __vector_2 (void) __attribute__ ((signal));
/*	  INTERRUPT  LINE  2  ISR 		*/
void __vector_3 (void) __attribute__ ((signal));

/* 	POINTERS TO CALL BACK FUNCTIONS OF THE EXTI  */
static void (*INT0_PCallBack)(void)=NULL;
static void (*INT1_PCallBack)(void)=NULL;
static void (*INT2_PCallBack)(void)=NULL;

/* CALL BACK FUNCTIONS OF THE EXTI */
void INT0_CALLBACK(void(*Copy_voidFunc)(void));
void INT1_CALLBACK(void(*Copy_voidFunc)(void));
void INT2_CALLBACK(void(*Copy_voidFunc)(void));

#define NULL     0
#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
