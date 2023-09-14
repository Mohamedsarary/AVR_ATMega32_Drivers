/*
 *  	Created on: 09/07/2023
 *      LAYER : HAL
 *      Author: Mohamed sarary
 *      File  : CLCD_Config.h
 */

#ifndef HAL_CLCD_CLCD_CONFIG_H_
#define HAL_CLCD_CLCD_CONFIG_H_


/*
CLCD DATA PORT OPTIONS :
	1- DIO_u8PortA
	2- DIO_u8PortB
	3- DIO_u8PortC
	4- DIO_u8PortD
*/

#define	CLCD_DATA_PORT 		DIO_u8PortA


/*
CLCD CONTROL PORT OPTIONS :
	1- DIO_u8PortA
	2- DIO_u8PortB
	3- DIO_u8PortC
	4- DIO_u8PortD
*/

#define CLCD_CONTROL_PORT 	DIO_u8PortB


/*
CLCD RS/EN PINS OPTIONS :
	1- DIO_u8_PIN_00
	2- DIO_u8_PIN_01
	3- DIO_u8_PIN_02
	4- DIO_u8_PIN_03
	5- DIO_u8_PIN_04
	6- DIO_u8_PIN_05
	7- DIO_u8_PIN_06
	8- DIO_u8_PIN_07
*/

#define CLCD_RS_PIN			DIO_u8_PIN_00
#define CLCD_EN_PIN			DIO_u8_PIN_01

/* 		BY DEFUALT RW IS LOW WHEN IS DEFINED AS WRITE 		*/
#define CLCD_RW_PIN 		DIO_u8_PIN_02


/*
 * CLCD_u8_INTEFACE_DATA_LENGTH OPTIONS :
 *
 *	1- CLCD_u8_4_DATA_LENGTH
 * 	2- CLCD_u8_8_DATA_LENGTH
 */
#define CLCD_u8_INTEFACE_DATA_LENGTH		CLCD_u8_4_DATA_LENGTH

#endif /* HAL_CLCD_CLCD_CONFIG_H_ */
