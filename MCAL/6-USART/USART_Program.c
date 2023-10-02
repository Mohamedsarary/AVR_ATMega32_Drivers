/*
 *  	Created on: 27/09/2023
 *      LAYER : MCAL
 *      Author: Mohamed sarary
 *      File  : USART_Program.c
 */

#include "USART_Config.h"
#include "USART_Interface.h"
#include "USART_Private.h"

#include "../../SERVICES/BitMath.h"
#include "../../SERVICES/StdTypes.h"
#include "../../SERVICES/ErrorStates.h"

/*************************************************************************************************************/
/*************************************** GLBAL DATA TO BE USED IN FUNCTIONS **********************************/
/*************************************************************************************************************/

/* GLOBAL FLAG TO CARRY USART STATE */
static u8 USART_u8State = IDLE;

/*Global variable to carry the send Data*/
static const u8 *USART_u8PSendData = NULL;

/*Global variable to carry the Receive Data*/
static u8 *USART_u8PReceiveData = NULL;

/*Global variable to carry the buffer size*/
static u8 USART_u8BufferSize;

/*Global variable to indicate for the current Data index of the buffer*/
static u8 USART_u8Index;

/*Global pointer to function to carry the notification function called by ISR*/
static void (*USART_pvNotificationFunc)(void) = NULL;

void USART_voidInit(void)
{

	u8 LOC_u8UCSRC = 0;
	u16 LOC_u16UBRR;

	/* SET USART SYSTEM SPEED MODE */
#if ( USART_MODE == USART_ASYNC ) && ( USART_SYSTEM_SPEED == USART_X1)
	CLR_BIT(UCSRA, UCSRA_U2X);
	LOC_u16UBRR = (u16) (( SYSTEM_FREQ / (16 * USART_BAUD_RATE)) - 1);

#elif ( USART_MODE == USART_ASYNC ) && ( USART_SYSTEM_SPEED == USART_X2)
	SET_BIT(UCSRA,UCSRA_U2X);
	LOC_u16UBRR = (u16) (( SYSTEM_FREQ / (8 * USART_BAUD_RATE)) - 1);

#elif ( USART_MODE == USART_SYNC )
	LOC_u16UBRR = (u16) (( SYSTEM_FREQ / (2 * USART_BAUD_RATE)) - 1);

#else
#error "WRONG USART MODE OR USART SPEED MODE CONFIG"
#endif

	/* ASSIGN REGISTER UBRRH FIRST THEN UBRRL TO AVOID ANY PROBLEMS */
	UBRRH = (u8) (LOC_u16UBRR >> 8);
	UBRRL = (u8) LOC_u16UBRR;

	/* SET MULTI PROCESSOR COMMUNICATION MODE */
#if USART_MBCM == DISABLE
	CLR_BIT(UCSRA, UCSRA_MPCM);
#elif USART_MBCM = ENABLE
	SET_BIT(UCSRA,UCSRA_MPCM);
#else
#error "WRONG MULTI PROCESSOR COMMUNICATION MODE CONFIG"
#endif

	/* SET USART MODE */
#if USART_MODE == USART_ASYNC
	CLR_BIT(LOC_u8UCSRC, UCSRC_UMSEL);
#elif USART_MODE == USART_SYNC
	SET_BIT(LOC_u8UCSRC,UCSRC_UMSEL);
#else
#error "WRONG USART MODE CONFIG"
#endif

	/* SET USART PARITY MODE */
#if USART_PARITY_MODE == DISABLE
	CLR_BIT(LOC_u8UCSRC, UCSRC_UPM0);
	CLR_BIT(LOC_u8UCSRC, UCSRC_UPM1);
#elif USART_PARITY_MODE == EVEN_PARITY
	CLR_BIT(LOC_u8UCSRC , UCSRC_UPM0);
	SET_BIT(LOC_u8UCSRC , UCSRC_UPM1);
#elif USART_PARITY_MODE == ODD_PARITY
	SET_BIT(LOC_u8UCSRC , UCSRC_UPM0);
	SET_BIT(LOC_u8UCSRC , UCSRC_UPM1);
#else
#error "Wrong USART_PARITY_MODE config"
#endif

	/* SET STOP BIT MODE */
#if USART_STOP_BIT == STOP_BIT_1
	CLR_BIT(LOC_u8UCSRC, UCSRC_USBS);
#elif USART_STOP_BIT == STOP_BIT_2
	SET_BIT(LOC_u8UCSRC , UCSRC_USBS);
#else
#error "Wrong USART_STOP_BIT config"
#endif

	/*Data Size*/
#if USART_DATA_SIZE == DATA_5BITS
	CLR_BIT(LOC_u8UCSRC , UCSRC_UCSZ0);
	CLR_BIT(LOC_u8UCSRC , UCSRC_UCSZ1);
	CLR_BIT(UCSRB , UCSRB_UCSZ2);
#elif USART_DATA_SIZE == DATA_6BITS
	SET_BIT(LOC_u8UCSRC , UCSRC_UCSZ0);
	CLR_BIT(LOC_u8UCSRC , UCSRC_UCSZ1);
	CLR_BIT(UCSRB , UCSRB_UCSZ2);
#elif USART_DATA_SIZE == DATA_7BITS
	CLR_BIT(LOC_u8UCSRC , UCSRC_UCSZ0);
	SET_BIT(LOC_u8UCSRC , UCSRC_UCSZ1);
	CLR_BIT(UCSRB , UCSRB_UCSZ2);
#elif USART_DATA_SIZE == DATA_8BITS
	SET_BIT(LOC_u8UCSRC, UCSRC_UCSZ0);
	SET_BIT(LOC_u8UCSRC, UCSRC_UCSZ1);
	CLR_BIT(UCSRB, UCSRB_UCSZ2);
#elif USART_DATA_SIZE == DATA_9BITS
	SET_BIT(LOC_u8UCSRC , UCSRC_UCSZ0);
	SET_BIT(LOC_u8UCSRC , UCSRC_UCSZ1);
	SET_BIT(UCSRB , UCSRB_UCSZ2);
#else
#error "Wrong USART_DATA_SIZE config"
#endif

	/* CLOCK POLARITY (for SYNC MODE ONLY) */
#if USART_MODE == SYNCHRONOUS
#if USART_CLOCK_POLARITY == XCK_RISING_TX_XCH_FALLING_RX
	CLR_BIT(LOC_u8UCSRC, UCSRC_UCPOL);
#elif USART_CLOCK_POLARITY == XCK_RISING_RX_XCH_FALLING_TX
	SET_BIT(LOC_u8UCSRC , UCSRC_UCPOL);
#else
#error "Wrong USART_STOP_BIT config"
#endif
#endif

	/* Set UCSRC MODE */
	SET_BIT(LOC_u8UCSRC, UCSRC_URSEL);

	/*STORE THE VALUE IN UCSRC REGISTER (one operation) */
	UCSRC = LOC_u8UCSRC;

	/**************************** ENABLE THE COMPONENTS *******************************/

	/* SET RX COMPLETE INT MODE */
#if USART_RX_COMPLETE_INTERRUPT == DISABLE
	CLR_BIT(UCSRB, UCSRB_RXCIE);
#elif USART_RX_COMPLETE_INTERRUPT == ENABLE
	SET_BIT(UCSRB , UCSRB_RXCIE);
#else
#error "Wrong USART_RX_COMPLETE_INTERRUPT config"
#endif

	/* SET TX COMPLETE INT MODE */
#if USART_TX_COMPLETE_INTERRUPT == DISABLE
	CLR_BIT(UCSRB, UCSRB_TXCIE);
#elif USART_TX_COMPLETE_INTERRUPT == ENABLE
	SET_BIT(UCSRB , UCSRB_TXCIE);
#else
#error "Wrong USART_TX_COMPLETE_INTERRUPT config"
#endif

	/* SET UDR EMPTY INT MODE */
#if USART_UDR_EMPTY_INTERRUPT == DISABLE
	CLR_BIT(UCSRB, UCSRB_UDRIE);
#elif USART_UDR_EMPTY_INTERRUPT == ENABLE
	SET_BIT(UCSRB , UCSRB_UDRIE);
#else
#error "Wrong USART_UDR_EMPTY_INTERRUPT config"
#endif

	/* SET TRANSMITTER MODE */
#if USART_RECEIVER_ENABLE == DISABLE
	CLR_BIT(UCSRB , UCSRB_RXEN);
#elif USART_RECEIVER_ENABLE == ENABLE
	SET_BIT(UCSRB, UCSRB_RXEN);
#else
#error "Wrong USART_RECEIVER_ENABLE config"
#endif

	/* SET TRANSMITTER MODE */
#if USART_TRANSMITTER_ENABLE == DISABLE
	CLR_BIT(UCSRB , UCSRB_TXEN);
#elif USART_TRANSMITTER_ENABLE == ENABLE
	SET_BIT(UCSRB, UCSRB_TXEN);
#else
#error "Wrong USART_TRANSMITTER_ENABLE config"
#endif

}

/*************************************************************************************************************/
/****************************************** FUNCTIONS SEND/RECEIVE BYTE **************************************/
/*************************************************************************************************************/

u16 USART_voidSendData(u8 Copy_u8Data)
{
	u8 Func_u8State = Func_NOK;
	u32 USART_u32TimerCounter = 0;

	if (USART_u8State == IDLE) {
		USART_u8State = BUSY;

		while (( GET_BIT(UCSRA,UCSRA_UDRE) == 0)
				&& (USART_u32TimerCounter != USART_u32TIMEOUT)) {
			USART_u32TimerCounter++;
		}
		if (USART_u32TimerCounter == USART_u32TIMEOUT) {
			Func_u8State = TIMEOUT_STATE;
		} else {
			UDR = Copy_u8Data;
		}
		USART_u8State = IDLE;
	} else {
		Func_u8State = BUSY_STATE;
	}
	return Func_u8State;
}

u16 USART_u16Receive()
{

	u16 Copy_u16ReceviedData;

	while (( GET_BIT(UCSRA,UCSRA_RXC) == 0)) {
	}

	Copy_u16ReceviedData = UDR;

	return Copy_u16ReceviedData;

}

/*************************************************************************************************************/
/*************************************** FUNCTIONS SEND/RECEIVE SYNC DATA ************************************/
/*************************************************************************************************************/

u8 USART_u8SendStringSynch(const u8 * Copy_u8PString)
{
	u8 LOC_u8FuncState = Func_NOK;

	u32 LOC_u32Index = 0;

	if (Copy_u8PString != NULL) {
		while (Copy_u8PString[LOC_u32Index] != '\0') {
			LOC_u8FuncState = USART_voidSendData(Copy_u8PString[LOC_u32Index]);
			LOC_u32Index++;
		}
	} else {
		LOC_u8FuncState = Func_NULLPOINTER;
	}
	return LOC_u8FuncState;
}

u8 USART_u8ReceiveStringSynch(u8 * Copy_u8PString, u32 Copy_u32BufferSize)
{
	u8 Local_u8FuncState = Func_OK;

	u32 Local_u32Index = 0;

	if (Copy_u8PString != NULL) {
		while (Local_u32Index < Copy_u32BufferSize) {
			Local_u8FuncState = USART_u16Receive(
					&Copy_u8PString[Local_u32Index]);
			Local_u32Index++;

			if (Local_u8FuncState != Func_OK) {
				return Local_u8FuncState;
			}
		}
	} else {
		Local_u8FuncState = Func_NULLPOINTER;
	}

	return Local_u8FuncState;
}

/*************************************************************************************************************/
/************************************** FUNCTIONS SEND/RECEIVE ASYNC DATA ************************************/
/*************************************************************************************************************/

/* Function To Get Out Of It And Continue The Remain Code Before the All String is Sent But UART Will Send it after
 * I Get Out Of It
 */
void USART_u8SendStringAsunch(u8* Copy_u8PString, void (*NotificationFunc)(void))
{
	if ((Copy_u8PString != NULL) && (NotificationFunc != NULL)) {
		USART_u8PSendData = Copy_u8PString;
		USART_pvNotificationFunc = NotificationFunc;

		USART_u8Index = 0;

		UDR = USART_u8PSendData[USART_u8Index];

		/*USART Transmit Interrupt Enable*/
		SET_BIT(UCSRB , UCSRB_TXCIE);
	}

}

void USART_u8ReceiveStringAsunch(u8 *Copy_u8RecString, u32 Copy_u32BufferSize, void (*NotificationFunc)(void))
{
	if ((Copy_u8RecString != NULL) && (NotificationFunc != NULL)) {

		USART_u8PReceiveData = Copy_u8RecString;
		USART_pvNotificationFunc = NotificationFunc;
		USART_u8BufferSize = Copy_u32BufferSize;

		USART_u8Index = 0;

		SET_BIT(UCSRB , UCSRB_RXCIE);
	}

}

/*************************************************************************************************************/
/***************************************** (TX / RX) INTERRUPT FUNCTIONS *************************************/
/*************************************************************************************************************/

/* Transmition ISR Complete */
void __vector_15(void)
{
	USART_u8Index++;

	if (USART_u8PSendData[USART_u8Index] == '\0') {
		USART_u8Index = 0;
		USART_pvNotificationFunc();

		/*USART Transmit Interrupt Disable*/
		CLR_BIT(UCSRB, UCSRB_TXCIE);

	} else {
		/* Data is not complete */
		/* Continue Send data */
		UDR = USART_u8PSendData[USART_u8Index];
	}

}

/* Receive ISR Complete */
void __vector_13(void)
{
	USART_u8PReceiveData[USART_u8Index] = UDR;

	USART_u8Index++;

	if (USART_u8Index == USART_u8BufferSize)

	{
		USART_u8Index = 0;

		USART_pvNotificationFunc();

		CLR_BIT(UCSRB , UCSRB_RXCIE);
	}

}
