/*
 *  	Created on: 20/10/2023
 *      LAYER : MCAL
 *      Author: Mohamed sarary
 *      File  : SPI_Interface.h
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

#include "../../SERVICES/StdTypes.h"

/*************************************************************************************************************/
/************************************************* SPI INTERFACES ********************************************/
/*************************************************************************************************************/

#define SPI_DIS										0
#define SPI_ENB										1

#define SPI_INTERRUPT_DIS							0
#define SPI_INTERRUPT_ENB							1

#define SPI_DATA_LSB								0
#define SPI_DATA_MSB								1

#define SPI_MASTER									0
#define SPI_SLAVE									1

#define SPI_RISING_LEADING_FALLING_TRAILING			0
#define SPI_FALLING_LEADING_RISING_TRAILING			1

#define SPI_SAMPLE_LEADING_SETUP_TRAILING 			0
#define SPI_SETUP_LEADING_SAMPLE_TRAILING			1

#define SPI_FREQ_DIV_BY2							0
#define SPI_FREQ_DIV_BY4							1
#define SPI_FREQ_DIV_BY8							2
#define SPI_FREQ_DIV_BY16							3
#define SPI_FREQ_DIV_BY32							4
#define SPI_FREQ_DIV_BY64							5
#define SPI_FREQ_DIV_BY128							6

typedef struct
{
	u8 SPI_u8State ;
	u8 SPI_u8Interrupt_Mode;
	u8 SPI_u8Data_Order;
	u8 SPI_u8Master_Slave_Select;
	u8 SPI_u8Clock_Polarity ;
	u8 SPI_u8Clock_Phase 	;
	u8 SPI_u8Clock_Rate   ;
}SPI_CONFIG;


typedef struct
{
	u8* Copy_u8Tran_Data ;
	u8* Copy_u8Rece_Data ;
	u8	Copy_u8Buffer_Size;
	void (*Notification_Func)(void);

}SPI_Data;

/*************************************************************************************************************/
/********************************************* SPI FUNCTIONS PROTOTYPE ***************************************/
/*************************************************************************************************************/

void SPI_voidInit (void);									  /* PRE BUILD CONFIG FUNCTION */
u8 SPI_u8InitConfig(SPI_CONFIG* Copy_SPI_Config); 			  /* POST BUILD CONFIG FUNCTION */
void SPI_u8TransReceive ( u8 Copy_u8TansData , u8 *Copy_u8RecData );
void SPI_voidTransReceiveSync( u8* Copy_u8TansData , u8 *Copy_u8RecData , u8 Copy_u8_BufferSize );
void SPI_voidTransReceiveAsync (SPI_Data * SPI_Buffer);

#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
