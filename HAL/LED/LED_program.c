/*******************************************************************/
/*******************************************************************/
/*******************    Author: Mohamed Fathy    *******************/
/*******************    Layer:  HAL	             *******************/
/*******************    SWC:    LED              *******************/
/*******************    Version:1.00             *******************/
/*******************************************************************/
/*******************************************************************/

#include "STD_TYPES.h"
#include "errorStates.h"

#include "DIO_interface.h"

#include "LED_private.h"
#include "LED_config.h"

#include "LED_interface.h"




ES_t	LED_enuInit(LED_t* AstrConfig)
{
	ES_t	Local_enuErrorState = ES_NOK;

	if(AstrConfig != NULL)
	{
		for (u8	Local_u8Iterator = 0 ; Local_u8Iterator < LED_NUM ; Local_u8Iterator++)
		{
			Local_enuErrorState = DIO_enuSetPinDirection(AstrConfig[Local_u8Iterator].LED_u8PortID, AstrConfig[Local_u8Iterator].LED_u8PinID, DIO_u8OUTPUT);
			if(AstrConfig[Local_u8Iterator].LED_u8ConnectionType == LED_SOURCE_CONNECTION && AstrConfig[Local_u8Iterator].LED_u8InitState == LED_ON)
			{
				Local_enuErrorState = DIO_enuSetPinValue(AstrConfig[Local_u8Iterator].LED_u8PortID, AstrConfig[Local_u8Iterator].LED_u8PinID, DIO_u8HIGH);
			}

			else if(AstrConfig[Local_u8Iterator].LED_u8ConnectionType == LED_SOURCE_CONNECTION && AstrConfig[Local_u8Iterator].LED_u8InitState == LED_OFF)
			{
				Local_enuErrorState = DIO_enuSetPinValue(AstrConfig[Local_u8Iterator].LED_u8PortID, AstrConfig[Local_u8Iterator].LED_u8PinID, DIO_u8LOW);
			}

			else if(AstrConfig[Local_u8Iterator].LED_u8ConnectionType == LED_SINK_CONNECTION && AstrConfig[Local_u8Iterator].LED_u8InitState == LED_ON)
			{
				Local_enuErrorState = DIO_enuSetPinValue(AstrConfig[Local_u8Iterator].LED_u8PortID, AstrConfig[Local_u8Iterator].LED_u8PinID, DIO_u8LOW);
			}

			else if(AstrConfig[Local_u8Iterator].LED_u8ConnectionType == LED_SINK_CONNECTION && AstrConfig[Local_u8Iterator].LED_u8InitState == LED_OFF)
			{
				Local_enuErrorState = DIO_enuSetPinValue(AstrConfig[Local_u8Iterator].LED_u8PortID, AstrConfig[Local_u8Iterator].LED_u8PinID, DIO_u8HIGH);
			}
			else
			{
				Local_enuErrorState = ES_OUT_OF_RANGE;
			}
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return	Local_enuErrorState;
}

ES_t	LED_enuTurnLedOn(LED_t* strConfig)
{
	ES_t	Local_enuErrorState =	ES_NOK;

	if(strConfig != NULL)
	{
		if(strConfig -> LED_u8ConnectionType == LED_SOURCE_CONNECTION)
		{
			Local_enuErrorState = DIO_enuSetPinValue(strConfig -> LED_u8PortID, strConfig -> LED_u8PinID, DIO_u8HIGH);
		}
		else if(strConfig -> LED_u8ConnectionType == LED_SINK_CONNECTION)
		{
			Local_enuErrorState = DIO_enuSetPinValue(strConfig -> LED_u8PortID, strConfig -> LED_u8PinID, DIO_u8LOW);
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return	Local_enuErrorState;
}

ES_t	LED_enuTurnLedOff(LED_t* strConfig)
{
	ES_t	Local_enuErrorState =	ES_NOK;

	if(strConfig != NULL)
	{
		if(strConfig -> LED_u8ConnectionType == LED_SOURCE_CONNECTION)
		{
			Local_enuErrorState = DIO_enuSetPinValue(strConfig -> LED_u8PortID, strConfig -> LED_u8PinID, DIO_u8LOW);
		}
		else if(strConfig -> LED_u8ConnectionType == LED_SINK_CONNECTION)
		{
			Local_enuErrorState = DIO_enuSetPinValue(strConfig -> LED_u8PortID, strConfig -> LED_u8PinID, DIO_u8HIGH);
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return	Local_enuErrorState;
}
