/*******************************************************************/
/*******************************************************************/
/*******************    Author: Mohamed Fathy    *******************/
/*******************    Layer:  MCAL             *******************/
/*******************    SWC:    GIE              *******************/
/*******************    Version:1.00             *******************/
/*******************************************************************/
/*******************************************************************/

#include "STD_TYPES.h"
#include "errorStates.h"

#include "GIE_private.h"
#include "GIE_interface.h"


void GIE_voidEnable(void)
{
	SREG |= (1<<SREG_I); 	//set the interrupt bit
}
void GIE_voidDisable(void)
{
	SREG &= ~(1<<SREG_I); 	//clear the interrupt bit
}
