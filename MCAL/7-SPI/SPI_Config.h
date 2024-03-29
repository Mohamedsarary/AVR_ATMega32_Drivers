/*
 *  	Created on: 20/10/2023
 *      LAYER : MCAL
 *      Author: Mohamed sarary
 *      File  : SPI_Config.h
 */

#ifndef MCAL_SPI_SPI_CONFIG_H_
#define MCAL_SPI_SPI_CONFIG_H_

/*
 * SPI DATA ORDER OPTIONS :-
 * 1- SPI_DATA_LSB
 * 2- SPI_DATA_MSB
 */
#define SPI_DATA_ORDER      	SPI_DATA_LSB

/*
 * SPI STATE OPTIONS :-
 * 1- SPI_DIS
 * 2- SPI_ENB
 */
#define SPI_STATE 				SPI_ENB

/*
 * SPI INTERRUPT MODE OPTIONS :-
 * 1- SPI_INTERRUPT_DIS
 * 2- SPI_INTERRUPT_ENB
 */
#define SPI_INTERRUPT_MODE		SPI_INTERRUPT_ENB

/*
 * SPI MASTER SLAVE SELECT OPTIONS :-
 * 1- SPI_MASTER
 * 2- SPI_SLAVE
 */
#define SPI_MASTER_SLAVE_SELECT			SPI_MASTER

/*
 * SPI CLOCK POLARITY OPTIONS :-
 * 1- SPI_RISING_LEADING_FALLING_TRAILING
 * 2- SPI_FALLING_LEADING_RISING_TRAILING
 */
#define SPI_CLOCK_POLARITY		SPI_RISING_LEADING_FALLING_TRAILING

/*
 * SPI CLOCK PHASE OPTIONS :-
 * 1- SPI_SAMPLE_LEADING_SETUP_TRAILING
 * 2- SPI_SETUP_LEADING_SAMPLE_TRAILING
 */
#define SPI_CLOCK_PHASE    		SPI_SAMPLE_LEADING_SETUP_TRAILING

/*
 * SPI CLOCK RATE OPTIONS :-
 * 1- SPI_FREQ_DIV_BY2
 * 2- SPI_FREQ_DIV_BY4
 * 3- SPI_FREQ_DIV_BY8
 * 4- SPI_FREQ_DIV_BY16
 * 5- SPI_FREQ_DIV_BY32
 * 6- SPI_FREQ_DIV_BY64
 * 7- SPI_FREQ_DIV_BY128
 */
#define SPI_CLOCK_RATE			SPI_FREQ_DIV_BY16

#endif /* MCAL_SPI_SPI_CONFIG_H_ */
