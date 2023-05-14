/*
 *  	Created on: 11/05/2023
 *      Driver: EXTI Driver
 *      Author: Mohamed sarary
 *      File  : EXTI_Config.h
 */

#ifndef MCAL_EXTI_EXTI_CONFIG_H_
#define MCAL_EXTI_EXTI_CONFIG_H_


/* Interrupt 0 Modes :
 * 		1- EXTI_LOWLEVEL
 * 		2- EXTI_ANYCHANGE
 * 		3- EXTI_FALLINGEDGE
 * 		4- EXTI_RISINGEDGE
 */
#define EXTI0_MODE EXTI_ANYCHANGE

/* Interrupt 1 Modes :
 * 		1- EXTI_LOWLEVEL
 * 		2- EXTI_ANYCHANGE
 * 		3- EXTI_FALLINGEDGE
 * 		4- EXTI_RISINGEDGE
 */
#define EXTI1_MODE EXTI_RISINGEDGE


/* Interrupt 2 Modes :
 * 		1- EXTI_FALLINGEDGE
 * 		2- EXTI_RISINGEDGE
 */
#define EXTI2_MODE EXTI_FALLINGEDGE


 /*
  * COMMENT UN-NEEDED LINE
  */

#define EXTI_LINE0_EN
//#define EXTI_LINE1_EN
//#define EXTI_LINE2_EN


#endif /* MCAL_EXTI_EXTI_CONFIG_H_ */
