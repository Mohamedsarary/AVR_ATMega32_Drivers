/*
 *  	Created on: 20/10/2023
 *      LAYER : MCAL
 *      Author: Mohamed sarary
 *      File  : SPI_Private.h
 */

#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_

#include "../../SERVICES/StdTypes.h"


/*************************************************************************************************************/
/*************************************** SPI REGISTER ADDRESSES **********************************************/
/*************************************************************************************************************/

#define SPCR  *((volatile u8*)0x2D)
#define SPSR  *((volatile u8*)0x2E)
#define SPDR  *((volatile u8*)0x2F)

/*************************************************************************************************************/
/***************************************** END OF REGISTER ADDRESSES *****************************************/
/*************************************************************************************************************/



/*************************************************************************************************************/
/*******************************************  SPI REGISTER BITS **********************************************/
/*************************************************************************************************************/

/* SPCR REGISTER BITS */
#define SPCR_SPIE			7
#define SPCR_SPE			6
#define SPCR_DORD			5
#define SPCR_MSTR			4
#define SPCR_CPOL			3
#define SPCR_CPHA			2
#define SPCR_SPR1			1
#define SPCR_SPR0			0

/* SPSR REGISTER BITS */
#define SPSR_SPIF			7
#define SPSR_WCOL			6
#define SPSR_SPI2X			0

/* SPDR	REGISTER BITS */
#define SPDR_MSB			7
#define SPDR_LSB			0

/*************************************************************************************************************/
/****************************************  END OF SPI REGISTER BITS ******************************************/
/*************************************************************************************************************/


/*************************************************************************************************************/
/************************************************* SPI ISR IDS ***********************************************/
/*************************************************************************************************************/

void __vector_12 (void) __attribute__ ((signal));


#endif /* MCAL_SPI_SPI_PRIVATE_H_ */