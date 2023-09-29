/*
 *  	Created on: 28/09/2023
 *      LAYER : HAL
 *      Author: Mohamed sarary
 *      File  : KPD_Config.h
 */


#ifndef HAL_KPD_KPD_CONFIG_H_
#define HAL_KPD_KPD_CONFIG_H_

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../SERVICES/StdTypes.h"

/*
 * KEYPAD PORT OPTIONS :
 * 1- DIO_u8PortA
 * 2- DIO_u8PortB
 * 3- DIO_u8PortC
 * 4- DIO_u8PortD
 */
#define KPD_PORT			DIO_u8PortA

/*
 * KEYPAD PIN OPTIONS :
 * 1- DIO_u8_PIN_00
 * 2- DIO_u8_PIN_01
 * 3- DIO_u8_PIN_02
 * 4- DIO_u8_PIN_03
 * 5- DIO_u8_PIN_04
 * 6- DIO_u8_PIN_05
 * 7- DIO_u8_PIN_06
 * 8- DIO_u8_PIN_07
 */

#define KPD_R1_PIN			DIO_u8_PIN_00
#define KPD_R2_PIN			DIO_u8_PIN_01
#define KPD_R3_PIN			DIO_u8_PIN_02
#define KPD_R4_PIN			DIO_u8_PIN_03

#define KPD_C1_PIN			DIO_u8_PIN_04
#define KPD_C2_PIN			DIO_u8_PIN_05
#define KPD_C3_PIN			DIO_u8_PIN_06
#define KPD_C4_PIN			DIO_u8_PIN_07

u8 KeyPad_u8Buttons[4][4] = { { '7' , '8' , '9' , '/' },
							  { '4' , '5' , '6' , '*' },
		                      { '1' , '2' , '3' , '-' },
                              { '?' , '0' , '=' , '+' }};
#endif /* HAL_KPD_KPD_CONFIG_H_ */
