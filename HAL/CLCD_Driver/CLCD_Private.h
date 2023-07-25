/*
 *  	Created on: 09/07/2023
 *      Driver: CLCD Driver
 *      Author: Mohamed sarary
 *      File  : CLCD_Private.h
 */

#ifndef HAL_CLCD_CLCD_PRIVATE_H_
#define HAL_CLCD_CLCD_PRIVATE_H_


#define CLCD_u8SET_FUNCTION			0b00111100

#define CLCD_u8DISPLAY_CONTROL		0b00001100

#define CLCD_u8DISPLAY_CLEAR		0b00000001

#define CLCD_u8_ENTRY_MODE			0b00000110

#define CLCD_u8_DDRAM_OFFSET	0x80

#define CLCD_u8_DDRAM_ROW2_OFFSET	64


#define CLCD_u8_CGRAM_OFFSET		0x40

#define CLCD_u8_CLEAR_LCD_COMMAND	0b00000001


#endif /* HAL_CLCD_CLCD_PRIVATE_H_ */
