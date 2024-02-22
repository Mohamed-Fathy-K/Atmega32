/*******************************************************************/
/*******************************************************************/
/*******************    Author: Mohamed Fathy    *******************/
/*******************    Layer:  HAL              *******************/
/*******************    SWC:    switch           *******************/
/*******************    Version:1.00             *******************/
/*******************************************************************/
/*******************************************************************/

#include "STD_TYPES.h"
#include "errorStates.h"
#include "DIO_interface.h"
#include "switch_interface.h"
#include "switch_private.h"
#include "switch_config.h"




ES_t 	switch_enuInit(SW_t* Copy_AstrSwitchInfo)
{
	ES_t	Local_enuErrorState  = ES_NOK;

	for(u8 Copy_u8Iterator = 0 ; Copy_u8Iterator < SW_NUM ; Copy_u8Iterator++)
	{
		if(Copy_AstrSwitchInfo != NULL)
		{
			Local_enuErrorState = DIO_enuSetPinDirection(Copy_AstrSwitchInfo[Copy_u8Iterator].switch_u8PortID, Copy_AstrSwitchInfo[Copy_u8Iterator].switch_u8PinID, DIO_u8INPUT);
			Local_enuErrorState = DIO_enuSetPinValue(Copy_AstrSwitchInfo[Copy_u8Iterator].switch_u8PortID, Copy_AstrSwitchInfo[Copy_u8Iterator].switch_u8PinID, Copy_AstrSwitchInfo[Copy_u8Iterator].switch_u8Type);
		}
		else
		{
			Local_enuErrorState = ES_NULL_POINTER;
		}
	}

	return	Local_enuErrorState;
}

ES_t switch_enuGetState(SW_t* Copy_strSwitchInfo, u8* Copy_pu8State)
{
	ES_t	Local_enuErrorState	= ES_NOK;
	if(Copy_strSwitchInfo != NULL && Copy_pu8State != NULL)
	{
		DIO_enuGetPinValue(Copy_strSwitchInfo->switch_u8PortID, Copy_strSwitchInfo->switch_u8PinID, Copy_pu8State);
	}
	else
	{
		Local_enuErrorState = ES_NOK;
	}
	return	Local_enuErrorState;
}
