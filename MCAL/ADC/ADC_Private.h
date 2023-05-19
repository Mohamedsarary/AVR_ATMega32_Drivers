/*
 *  	Created on: 18/05/2023
 *      Driver: ADC Driver
 *      Author: Mohamed sarary
 *      File  : ADC_Private.h
 */

#include "../../SERVICES/STD_TYPES.h"
#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_


#define ADCL	*((u8 volatile*)(0x24))
#define ADCH	*((u8 volatile*)(0x25))
#define ADCSRA	*((u8 volatile*)(0x26))
#define ADMUX 	*((u8 volatile*)(0x27))
#define SFIOR	*((u8 volatile*)(0x50))


/*   	 Register ADMUX BITS 		*/
#define MUX0	0
#define MUX1	1
#define MUX2	2
#define MUX3	3
#define MUX4	4
#define ADLAR 	5
#define REFS0	6
#define REFS1	7

/*   	 Register ADCSRA BITS 		*/
#define ADPS0	0
#define ADPS1	1
#define ADPS2	2
#define ADIE	3
#define ADIF	4
#define ADATE 	5
#define ADSC	6
#define ADEN	7


/*   	 Register SFIOR BITS 		*/
#define ADTS0	5
#define ADTS1	6
#define ADTS2	7


#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
