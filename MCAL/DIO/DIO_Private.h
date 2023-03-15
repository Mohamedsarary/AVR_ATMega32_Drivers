/*
 *  	Created on: 15/03/2023
 *      Driver: DIO Driver
 *      Author: Mohamed sarary
 *      File  : DIO_Private.h
 */

#ifndef MCAL_DIO_DIO_PRIVATE_H_
#define MCAL_DIO_DIO_PRIVATE_H_

#include "../../Services/STD_TYPES/STD_TYPES.h"

/*	PORTA REGISTERS	*/
#define DDRA	*((u8 volatile *) 0x3A )
#define PORTA	*((u8 volatile *) 0x3B)
#define PINA	*((u8 volatile *) 0x39)

/*	PORTB REGISTERS	*/
#define DDRB	*((u8 volatile*) 0x37 )
#define PORTB	*((u8 volatile*) 0x38)
#define PINB	*((u8 volatile*) 0x36)

/*	PORTC REGISTERS	*/
#define DDRC	*((u8 volatile*) 0x34 )
#define PORTC	*((u8 volatile*) 0x35)
#define PINC	*((u8 volatile*) 0x33)

/* PORTD REGISTERS	*/
#define DDRD	*((u8 volatile*) 0x31 )
#define PORTD	*((u8 volatile*) 0x32)
#define PIND	*((u8 volatile*) 0x30)


#endif /* MCAL_DIO_DIO_PRIVATE_H_ */
