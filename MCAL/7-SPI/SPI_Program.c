/*
 *  	Created on: 20/10/2023
 *      LAYER : MCAL
 *      Author: Mohamed sarary
 *      File  : SPI_Program.c
 */

#include "SPI_Config.h"
#include "SPI_Interface.h"
#include "SPI_Private.h"
#include "util/delay.h"

#include "../../SERVICES/StdTypes.h"
#include "../../SERVICES/BitMath.h"
#include "../../SERVICES/ErrorStates.h"

/* GLOBAL FLAG TO CARRY SPI STATE	*/
static u8 SPI_u8GState = IDLE;

/* GLOBAL VARIABLE TO CARRY THR TRANSMIT DATA */
static u8 *SPI_pu8GTransData = NULL;

/* GLOBAL VARIABLE TO CARRY THR RECEIVE DATA */
static u8 *SPI_pu8GRecData = NULL;

/* GLOBAL VARIABLE TO CARRY THE BUFFER SIZE */
static u8 SPI_u8GBufferSize = NULL;

/* GLOBAL VARIABLE TO INDEX OF THE DATA */
static u8 SPI_u8GIndex = 0;

/* GLOBAL VARIABLE TO CARRY NOTIFICATION FUNCTION */
static void (*SPI_GpNotiFunction)(void) = NULL;

void SPI_voidInit(void) {
#if SPI_DATA_ORDER == SPI_DATA_LSB
	SET_BIT(SPCR, SPCR_DORD);
#elif SPI_DATA_ORDER == SPI_DATA_MSB
	CLR_BIT(SPCR,SPCR,DORD);
#else
	#error "Wrong SPI Data Order Config"
	#endif

#if SPI_INTERRUPT_MODE == SPI_INTERRUPT_ENB
	SET_BIT(SPCR, SPCR_SPIE);
#elif SPI_INTERRUPT_MODE == SPI_INTERRUPT_DIS
	CLR_BIT(SPCR,SPCR_SPIE);
#else
	#error "Wrong SPI Interrupt Config"
	#endif

#if SPI_MASTER_SLAVE_SELECT == SPI_MASTER
	SET_BIT(SPCR, SPCR_MSTR);
#elif SPI_MASTER_SLAVE_SELECT == SPI_SLAVE
	CLR_BIT(SPCR,SPCR_MSTR);
#else
	#error "Wrong SPI Master Slave Config"
	#endif

#if SPI_CLOCK_POLARITY == SPI_RISING_LEADING_FALLING_TRAILING
	CLR_BIT(SPCR, SPCR_CPOL);
#elif SPI_CLOCK_POLARITY == SPI_FALLING_LEADING_RISING_TRAILING
	SET_BIT(SPCR,SPCR_CPOL);
#else
	#error "Wrong SPI Clock Polarity Config"
	#endif

#if SPI_CLOCK_PHASE == SPI_SAMPLE_LEADING_SETUP_TRAILING
	CLR_BIT(SPCR, SPCR_CPHA);
#elif SPI_CLOCK_PHASE == SPI_SETUP_LEADING_SAMPLE_TRAILING
	SET_BIT(SPCR,SPCR_CPHA);
#else
	#error "Wrong SPI Clock Phase Config"
	#endif

#if SPI_CLOCK_RATE == SPI_FREQ_DIV_BY2
	CLR_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPSR,SPSR_SPI2X);
#elif SPI_CLOCK_RATE == SPI_FREQ_DIV_BY4
	CLR_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);
#elif SPI_CLOCK_RATE == SPI_FREQ_DIV_BY8
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPSR,SPSR_SPI2X);
#elif SPI_CLOCK_RATE == SPI_FREQ_DIV_BY16
	SET_BIT(SPCR, SPCR_SPR0);
	CLR_BIT(SPCR, SPCR_SPR1);
	CLR_BIT(SPSR, SPSR_SPI2X);
#elif SPI_CLOCK_RATE == SPI_FREQ_DIV_BY32
	CLR_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPSR,SPSR_SPI2X);
#elif SPI_CLOCK_RATE == SPI_FREQ_DIV_BY64
	SET_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPSR,SPSR_SPI2X);
#elif SPI_CLOCK_RATE == SPI_FREQ_DIV_BY128
	SET_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);
#else
	#error "Wrong SPI Clock Rate Config"
	#endif

#if SPI_STATE == SPI_ENB
	SET_BIT(SPCR, SPCR_SPE);
#elif SPI_STATE == SPI_DIS
	CLR_BIT(SPCR,SPCR_SPE);
#else
	#error "Wrong SPI State Config"
	#endif
}

void SPI_u8TransReceive(u8 Copy_u8TansData, u8 *Copy_u8RecData)
{

	if (SPI_u8GState == IDLE)
	{
		SPI_u8GState = BUSY;
		SPDR = Copy_u8TansData;

		while ( GET_BIT(SPSR,SPSR_SPIF) == 0){}
		*Copy_u8RecData = SPDR;
		SPI_u8GState = IDLE;
	}
}

void SPI_voidTransReceiveSync(u8* Copy_u8TansData, u8 *Copy_u8RecData, u8 Copy_u8_BufferSize) {
	u8 LOC_u8Counter = 0;

	if ((Copy_u8TansData != NULL) && (Copy_u8RecData != NULL))
	{
		while (LOC_u8Counter < Copy_u8_BufferSize) {
			SPI_u8TransReceive(Copy_u8TansData[LOC_u8Counter],
					&Copy_u8RecData[LOC_u8Counter]);
			LOC_u8Counter++;
		}
	}
}


void SPI_voidTransReceiveAsync(SPI_Data * SPI_data)
{

	if (SPI_u8GState == IDLE) {
		if ((SPI_data != NULL) && (SPI_data->Copy_u8Tran_Data != NULL) && (SPI_data->Copy_u8Rece_Data != NULL) && (SPI_data->Notification_Func != NULL)) {

			SPI_u8GState = BUSY;

		/* Assign the Data Which is Passed to SPI To Global Vars */
			SPI_pu8GTransData = SPI_data->Copy_u8Tran_Data;
			SPI_pu8GRecData = SPI_data->Copy_u8Rece_Data;
			SPI_u8GBufferSize = SPI_data->Copy_u8Buffer_Size;
			SPI_GpNotiFunction = SPI_data->Notification_Func;

			/* Set the Index to Zero To Transmit the First Data */
			SPI_u8GIndex = 0;

			/* Transmit The First Data */
			SPDR = SPI_pu8GTransData[SPI_u8GIndex];

			_delay_ms(100);

			/* Enable The Interrupt */
			SET_BIT(SPCR, SPCR_SPIE);
		}
	}
}

			/* SPI TRANSMITION AND RECEIVE ISR */
void __vector_12(void)
{

	/* Receive The First Data */
	SPI_pu8GRecData[SPI_u8GIndex] = SPDR;

	/* Increment the Index */
	SPI_u8GIndex++;

	if (SPI_u8GIndex == SPI_u8GBufferSize)
	{

		/*	 Transmition is Done   */

		SPI_u8GState = IDLE;

		SPI_u8GIndex = 0;

		SPI_pNotiFunction();

		/* Disable the Interrupt   */
		CLR_BIT(SPCR, SPCR_SPIE);

	}

	else {

		/* Transmit the Next Data   */

		SPDR = SPI_pu8GTransData[SPI_u8GIndex];

	}
}
