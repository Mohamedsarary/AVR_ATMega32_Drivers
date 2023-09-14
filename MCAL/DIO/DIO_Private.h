/*
 *  	Created on: 30/04/2023
 *      LAYER : MCAL
 *      Author: Mohamed sarary
 *      File  : DIO_Private.h
 */

#ifndef MCAL_DIO_DIO_PRIVATE_H_
#define MCAL_DIO_DIO_PRIVATE_H_

#include "../../SERVICES/StdTypes.h"

/*************************	PORT A REGISTERS	*************************/
#define DDRA	*((u8 volatile *) 0x3A )
#define PORTA	*((u8 volatile *) 0x3B)
#define PINA	*((u8 volatile *) 0x39)


/*************************	PORT B REGISTERS	*************************/
#define DDRB	*((u8 volatile*) 0x37 )
#define PORTB	*((u8 volatile*) 0x38)
#define PINB	*((u8 volatile*) 0x36)


/*************************	PORT C REGISTERS	*************************/
#define DDRC	*((u8 volatile*) 0x34 )
#define PORTC	*((u8 volatile*) 0x35)
#define PINC	*((u8 volatile*) 0x33)


/*************************	PORT D REGISTERS	*************************/
#define DDRD	*((u8 volatile*) 0x31 )
#define PORTD	*((u8 volatile*) 0x32)
#define PIND	*((u8 volatile*) 0x30)


#endif /* MCAL_DIO_DIO_PRIVATE_H_ */
