/*
 *  	Created on: 23/10/2023
 *      LAYER : MCAL
 *      Author: Mohamed sarary
 *      File  : I2C_Private.h
 */

#ifndef MCAL_I2C_I2C_PRIVATE_H_
#define MCAL_I2C_I2C_PRIVATE_H_

#include "../../SERVICES/StdTypes.h"

/*************************************************************************************************************/
/*************************************** I2C REGISTER ADDRESSES **********************************************/
/*************************************************************************************************************/

#define TWBR			*((volatile u8*)0x20)
#define TWCR			*((volatile u8*)0x56)
#define TWSR			*((volatile u8*)0x21)
#define TWDR			*((volatile u8*)0x23)
#define TWAR			*((volatile u8*)0x22)

/*************************************************************************************************************/
/***************************************** END OF REGISTER ADDRESSES *****************************************/
/*************************************************************************************************************/


/*************************************************************************************************************/
/*******************************************  I2C REGISTER BITS **********************************************/
/*************************************************************************************************************/

/* TWBR REGISTER BITS */
#define TWBR_0				0
#define TWBR_1				1
#define TWBR_2				2
#define TWBR_3				3
#define TWBR_4				4
#define TWBR_5				5
#define TWBR_6				6
#define TWBR_7				7

/* TWCR REGISTER BITS */
#define TWCR_TWIE			0
#define TWCR_TWEN			2
#define TWCR_TWWC			3
#define TWCR_TWSTO			4
#define TWCR_TWSTA			5
#define TWCR_TWEA			6
#define TWCR_TWINT			7

/* TWSR REGISTER BITS */
#define TWSR_TWPS0			0
#define TWSR_TWPS1			1
#define TWSR_TWS3			3
#define TWSR_TWS4			4
#define TWSR_TWS5			5
#define TWSR_TWS6			6
#define TWSR_TWS7			7

/* TWDR REGISTER BITS */
#define TWDR_TWD0			0
#define TWDR_TWD1			1
#define TWDR_TWD2			2
#define TWDR_TWD3			3
#define TWDR_TWD4			4
#define TWDR_TWD5			5
#define TWDR_TWD6			6
#define TWDR_TWD7			7

/* TWAR REGISTER BITS */
#define TWAR_TWGCE			0
#define TWAR_TWA0			1
#define TWAR_TWA1			2
#define TWAR_TWA2			3
#define TWAR_TWA3			4
#define TWAR_TWA4			5
#define TWAR_TWA5			6
#define TWAR_TWA6			7

/*************************************************************************************************************/
/****************************************  END OF I2C REGISTER BITS ******************************************/
/*************************************************************************************************************/


#define START_ACK              	  	  0x08 /* start has been sent */
#define REP_START_ACK        	      0x10 /* repeated start */
#define SLAVE_ADD_AND_WR_ACK   	  	  0x18 /* Master transmit ( slave address + Write request ) ACK */
#define SLAVE_ADD_AND_RD_ACK   	  	  0x40 /* Master transmit ( slave address + Read request ) ACK */
#define MSTR_WR_BYTE_ACK       		  0x28 /* Master transmit data ACK */
#define MSTR_RD_BYTE_WITH_ACK    	  0x50 /* Master received data with ACK */
#define MSTR_RD_BYTE_WITH_NACK   	  0x58 /* Master received data with not ACK */
#define SLAVE_ADD_RCVD_RD_REQ         0xA8 /* means that slave address is received with read request */
#define SLAVE_ADD_RCVD_WR_REQ    	  0x60 /* means that slave address is received with write request */
#define SLAVE_DATA_RECEIVED      	  0x80 /* means that a byte is received */
#define SLAVE_BYTE_TRANSMITTED   	  0xB8 /* means that the written byte is transmitted */



/*************************************************************************************************************/
/************************************************* I2C ISR IDS ***********************************************/
/*************************************************************************************************************/

void __vector_19 (void) __attribute__ ((signal));



#endif /* MCAL_I2C_I2C_PRIVATE_H_ */
