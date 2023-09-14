/*
 *  	Created on: 15/03/2023
 *      Driver: BIT_MATH
 *      Author: Mohamed sarary
 *      File  : BIT_MATH.h
 */

#ifndef SERVICES_BIT_MATH_H_
#define SERVICES_BIT_MATH_H_

#define SET_BIT(BYTE,Bit_NO) (BYTE) |= (1<<(Bit_NO))
#define CLR_BIT(BYTE,Bit_NO) (BYTE) &= ~(1<<(Bit_NO))
#define TOGGEL_BIT(BYTE,Bit_NO) (BYTE) ^= 1<<(Bit_NO)
#define GET_BIT(BYTE,Bit_NO) ((BYTE>>Bit_NO)&(0x01))


#endif /* SERVICES_BIT_MATH_H_ */
