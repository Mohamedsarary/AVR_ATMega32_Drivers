/*
 *  	Created on: 15/03/2023
 *      Driver: CLCD Driver
 *      Author: Mohamed sarary
 *      File  : CLCD_Config.h
 */

#ifndef HAL_CLCD_DRIVER_CLCD_CONFING_H_
#define HAL_CLCD_DRIVER_CLCD_CONFING_H_

#include "../../MCAL/DIO/DIO_Confing.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/DIO/DIO_Private.h"

/*
 *  CLCD Data Port Options : 1- DIO_u8PortA
 *  						 2- DIO_u8PortB
 *  						 3- DIO_u8PortC
 *  						 4- DIO_u8PortD
 */
#define CLCD_DATA_PORT DIO_u8PortA

/*
 *  CLCD Control Port Options : 1- DIO_u8PortA
 *  						  2- DIO_u8PortB
 *  						  3- DIO_u8PortC
 *  						  4- DIO_u8PortD
 */
#define CLCD_CTR_PORT DIO_u8PortB

/*
 *  CLCD RS , EN PINS       : 1- DIO_u8_PIN_00
 *  						  2- DIO_u8_PIN_01
 *  						  3- DIO_u8_PIN_02
 *  						  4- DIO_u8_PIN_03
 *  						  5- DIO_u8_PIN_04
 *  						  6- DIO_u8_PIN_05
 *  						  7- DIO_u8_PIN_06
 *  						  8- DIO_u8_PIN_07
 */

#define CLCD_RS_PIN   DIO_u8_PIN_00
#define CLCD_EN_PIN   DIO_u8_PIN_01
/*not important to Define RW PIN*/
#define CLCD_RW_PIN   DIO_u8_PIN_02

/* CLCD ROWS */
#define CLCD_u8_ROW_01   0
#define CLCD_u8_ROW_02   1

/* CLCD COLOUMS*/
#define CLCD_u8_Coloum_00   0
#define CLCD_u8_Coloum_01	1
#define CLCD_u8_Coloum_02	2
#define CLCD_u8_Coloum_03	3
#define CLCD_u8_Coloum_04	4
#define CLCD_u8_Coloum_05	5
#define CLCD_u8_Coloum_06	6
#define CLCD_u8_Coloum_07	7
#define CLCD_u8_Coloum_08	8
#define CLCD_u8_Coloum_09	9
#define CLCD_u8_Coloum_10	10
#define CLCD_u8_Coloum_11	11
#define CLCD_u8_Coloum_12	12
#define CLCD_u8_Coloum_13	13
#define CLCD_u8_Coloum_14	14
#define CLCD_u8_Coloum_15	15

#define STD_NOK 0
#define STD_OK  1

/* Array to Enter the Custom Sympol in it */
/* We can draw Custom Sympol Using this Website : https://maxpromer.github.io/LCD-Character-Creator/ */
static u8 Loc_u8StaArr[] = { 0x07, 0x04, 0x1F, 0x04, 0x04, 0x04, 0x04, 0x04, //First  Char
		0x07, 0x04, 0x1F, 0x04, 0x04, 0x04, 0x04, 0x04,		//Second Char
		0x07, 0x04, 0x1F, 0x04, 0x04, 0x04, 0x04, 0x04,		//Third  Char
		0x07, 0x04, 0x1F, 0x04, 0x04, 0x04, 0x04, 0x04,		//Fourth Char
		0x07, 0x04, 0x1F, 0x04, 0x04, 0x04, 0x04, 0x04,   	//FIFTH  Char
		0x07, 0x04, 0x1F, 0x04, 0x04, 0x04, 0x04, 0x04,		//Sixth  Char
		0x07, 0x04, 0x1F, 0x04, 0x04, 0x04, 0x04, 0x04,		//7th	 Char
		0x07, 0x04, 0x1F, 0x04, 0x04, 0x04, 0x04, 0x04,		//8Th    Char

		};

#endif /* HAL_CLCD_DRIVER_CLCD_CONFING_H_ */
