/*
 * EXTI_private.h
 *
 *  Created on: Apr 18, 2023
 *      Author: mkotb
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

///////////////////MCU Control Register – MCUCR/////////////////////////

#define MCUCR			*((volatile u8*)0x55)
//INT0
#define MCUCR_ISC00		0
#define MCUCR_ISC01		1
//INT1
#define MCUCR_ISC10		2
#define MCUCR_ISC11		3

////////////////////////////////////////////////////////////////////////

///////////////////MCU Control Register – MCUCSR////////////////////////

#define MCUCSR			*((volatile u8*)0x54)
//INT2
#define MCUCSR_ISC2		6

///////////////////////////////////////////////////////////////////////

//////////////General Interrupt Control Register – GICR////////////////

#define GICR			*((volatile u8*)0x5B)
//INT2
#define	GICR_INT2		5
//INT0
#define	GICR_INT0		6
//INT1
#define	GICR_INT1		7

#define GICR_Disabled	2
#define GICR_Enabled 	1

///////////////////////////////////////////////////////////////////////


///////////////General Interrupt Flag Register – GIFR//////////////////

#define GIFR			*((volatile u8*)0x5A)
//INTF2
#define	GIFR_INTF2		5
//INTF0
#define	GIFR_INTF0		6
//INTF1
#define	GIFR_INTF1		7

///////////////////////////////////////////////////////////////////////

///////////////////Interrupt Sense Control trigger/////////////////////

#define INT_SENSE_LOW_LEVEL			1
#define INT_SENSE_ON_CHANGE			2
#define INT_SENSE_FALLING_EDGE		3
#define INT_SENSE_RISING_EDGE		4

///////////////////////////////////////////////////////////////////////

#endif /* EXTI_PRIVATE_H_ */
