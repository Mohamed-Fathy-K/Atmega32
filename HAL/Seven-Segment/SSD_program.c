/*******************************************************************/
/*******************************************************************/
/*******************    Author: Mohamed Fathy    *******************/
/*******************    Layer:  HAL	             *******************/
/*******************    SWC:    SSD              *******************/
/*******************    Version:1.00             *******************/
/*******************************************************************/
/*******************************************************************/

#include "STD_TYPES.h"
#include "errorStates.h"

#include "DIO_interface.h"

//#include "SSD_private.h"
#include "SSD_config.h"

//#include "SSD_interface.h"

u8 SSD_Au8CommonCathodeNumbers[SSD_Numbers] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};


ES_t	SSD_enuInit(SSD_t* AstrSevenSegmentsInfo)
{
	ES_t	Local_enuErrorState = ES_NOK;


	typedef	struct
	{
		u8 Local_u8PinAErrorState: 3;
		u8 Local_u8PinBErrorState: 3;
		u8 Local_u8PinCErrorState: 3;
		u8 Local_u8PinDErrorState: 3;
		u8 Local_u8PinEErrorState: 3;
		u8 Local_u8PinFErrorState: 3;
		u8 Local_u8PinGErrorState: 3;

		u8 Local_u8DotErrorState: 3;

		u8 Local_u8EnableErrorState:3;

	}ErrorsState_t;

	ErrorsState_t Local_strErrorsState;

	if(AstrSevenSegmentsInfo != NULL)
	{
		for(u8 Local_u8Iterator = 0 ; Local_u8Iterator < SSD_NUM ; Local_u8Iterator++)
		{
			Local_strErrorsState.Local_u8PinAErrorState = DIO_enuSetPinDirection(AstrSevenSegmentsInfo[Local_u8Iterator].SSD_u8PortA, AstrSevenSegmentsInfo[Local_u8Iterator].SSD_u8PinA, DIO_u8OUTPUT);
			Local_strErrorsState.Local_u8PinBErrorState = DIO_enuSetPinDirection(AstrSevenSegmentsInfo[Local_u8Iterator].SSD_u8PortB, AstrSevenSegmentsInfo[Local_u8Iterator].SSD_u8PinB, DIO_u8OUTPUT);
			Local_strErrorsState.Local_u8PinCErrorState = DIO_enuSetPinDirection(AstrSevenSegmentsInfo[Local_u8Iterator].SSD_u8PortC, AstrSevenSegmentsInfo[Local_u8Iterator].SSD_u8PinC, DIO_u8OUTPUT);
			Local_strErrorsState.Local_u8PinDErrorState = DIO_enuSetPinDirection(AstrSevenSegmentsInfo[Local_u8Iterator].SSD_u8PortD, AstrSevenSegmentsInfo[Local_u8Iterator].SSD_u8PinD, DIO_u8OUTPUT);
			Local_strErrorsState.Local_u8PinEErrorState = DIO_enuSetPinDirection(AstrSevenSegmentsInfo[Local_u8Iterator].SSD_u8PortE, AstrSevenSegmentsInfo[Local_u8Iterator].SSD_u8PinE, DIO_u8OUTPUT);
			Local_strErrorsState.Local_u8PinFErrorState = DIO_enuSetPinDirection(AstrSevenSegmentsInfo[Local_u8Iterator].SSD_u8PortF, AstrSevenSegmentsInfo[Local_u8Iterator].SSD_u8PinF, DIO_u8OUTPUT);
			Local_strErrorsState.Local_u8PinGErrorState = DIO_enuSetPinDirection(AstrSevenSegmentsInfo[Local_u8Iterator].SSD_u8PortG, AstrSevenSegmentsInfo[Local_u8Iterator].SSD_u8PinG, DIO_u8OUTPUT);

			if(AstrSevenSegmentsInfo[Local_u8Iterator].SSD_u8DotPort != SSD_NOT_CONNECTED && AstrSevenSegmentsInfo[Local_u8Iterator].SSD_u8DotPin != SSD_NOT_CONNECTED)
			{
				Local_strErrorsState.Local_u8DotErrorState = DIO_enuSetPinDirection(AstrSevenSegmentsInfo[Local_u8Iterator].SSD_u8DotPort, AstrSevenSegmentsInfo[Local_u8Iterator].SSD_u8DotPin, DIO_u8OUTPUT);
			}
			else
			{
				Local_strErrorsState.Local_u8DotErrorState = ES_OK;
			}

			if(AstrSevenSegmentsInfo[Local_u8Iterator].SSD_u8EnablePort != SSD_NOT_CONNECTED && AstrSevenSegmentsInfo[Local_u8Iterator].SSD_u8EnablePIN != SSD_NOT_CONNECTED)
			{
				Local_strErrorsState.Local_u8EnableErrorState = DIO_enuSetPinDirection(AstrSevenSegmentsInfo[Local_u8Iterator].SSD_u8EnablePort, AstrSevenSegmentsInfo[Local_u8Iterator].SSD_u8EnablePIN, DIO_u8OUTPUT);
			}
			else
			{
				Local_strErrorsState.Local_u8EnableErrorState = ES_OK;
			}

			if(
					(Local_strErrorsState.Local_u8PinAErrorState == ES_OK) &&
					(Local_strErrorsState.Local_u8PinBErrorState == ES_OK) &&
					(Local_strErrorsState.Local_u8PinCErrorState == ES_OK) &&
					(Local_strErrorsState.Local_u8PinDErrorState == ES_OK) &&
					(Local_strErrorsState.Local_u8PinEErrorState == ES_OK) &&
					(Local_strErrorsState.Local_u8PinFErrorState == ES_OK) &&
					(Local_strErrorsState.Local_u8PinGErrorState == ES_OK) &&

					(Local_strErrorsState.Local_u8DotErrorState == ES_OK) &&

					(Local_strErrorsState.Local_u8EnableErrorState == ES_OK)
					)
			{
				Local_enuErrorState = ES_OK;
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

ES_t	SSD_enuDisplayNum(u8 Copy_u8SevenSegmentIndex, u8 Copy_u8Number)
{
	ES_t	Local_enuErrorState = ES_NOK;


	typedef	struct
	{
		u8 Local_u8PinAErrorState: 3;
		u8 Local_u8PinBErrorState: 3;
		u8 Local_u8PinCErrorState: 3;
		u8 Local_u8PinDErrorState: 3;
		u8 Local_u8PinEErrorState: 3;
		u8 Local_u8PinFErrorState: 3;
		u8 Local_u8PinGErrorState: 3;

		u8 Local_u8DotErrorState: 3;

		u8 Local_u8EnableErrorState:3;

	}ErrorsState_t;

	ErrorsState_t Local_strErrorsState;

	if(SSD_AstrSevenSegmentsInfo != NULL)
	{
		if(SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8Type == SSD_COMMON_CATHODE)
		{
			Local_strErrorsState.Local_u8PinAErrorState =	DIO_enuSetPinValue(SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8PortA, SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8PinA,((SSD_Au8CommonCathodeNumbers[Copy_u8Number] >> 0) & 1));
			Local_strErrorsState.Local_u8PinBErrorState =	DIO_enuSetPinValue(SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8PortB, SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8PinB,((SSD_Au8CommonCathodeNumbers[Copy_u8Number] >> 1) & 1));
			Local_strErrorsState.Local_u8PinCErrorState =	DIO_enuSetPinValue(SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8PortC, SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8PinC,((SSD_Au8CommonCathodeNumbers[Copy_u8Number] >> 2) & 1));
			Local_strErrorsState.Local_u8PinDErrorState =	DIO_enuSetPinValue(SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8PortD, SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8PinD,((SSD_Au8CommonCathodeNumbers[Copy_u8Number] >> 3) & 1));
			Local_strErrorsState.Local_u8PinEErrorState =	DIO_enuSetPinValue(SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8PortE, SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8PinE,((SSD_Au8CommonCathodeNumbers[Copy_u8Number] >> 4) & 1));
			Local_strErrorsState.Local_u8PinFErrorState =	DIO_enuSetPinValue(SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8PortF, SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8PinF,((SSD_Au8CommonCathodeNumbers[Copy_u8Number] >> 5) & 1));
			Local_strErrorsState.Local_u8PinGErrorState =	DIO_enuSetPinValue(SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8PortG, SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8PinG,((SSD_Au8CommonCathodeNumbers[Copy_u8Number] >> 6) & 1));

		}
		else if(SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8Type == SSD_COMMON_ANODE)
		{
			Local_strErrorsState.Local_u8PinAErrorState =	DIO_enuSetPinValue(SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8PortA, SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8PinA,!((SSD_Au8CommonCathodeNumbers[Copy_u8Number] >> 0) & 1));
			Local_strErrorsState.Local_u8PinBErrorState =	DIO_enuSetPinValue(SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8PortB, SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8PinB,!((SSD_Au8CommonCathodeNumbers[Copy_u8Number] >> 1) & 1));
			Local_strErrorsState.Local_u8PinCErrorState =	DIO_enuSetPinValue(SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8PortC, SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8PinC,!((SSD_Au8CommonCathodeNumbers[Copy_u8Number] >> 2) & 1));
			Local_strErrorsState.Local_u8PinDErrorState =	DIO_enuSetPinValue(SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8PortD, SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8PinD,!((SSD_Au8CommonCathodeNumbers[Copy_u8Number] >> 3) & 1));
			Local_strErrorsState.Local_u8PinEErrorState =	DIO_enuSetPinValue(SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8PortE, SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8PinE,!((SSD_Au8CommonCathodeNumbers[Copy_u8Number] >> 4) & 1));
			Local_strErrorsState.Local_u8PinFErrorState =	DIO_enuSetPinValue(SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8PortF, SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8PinF,!((SSD_Au8CommonCathodeNumbers[Copy_u8Number] >> 5) & 1));
			Local_strErrorsState.Local_u8PinGErrorState =	DIO_enuSetPinValue(SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8PortG, SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8PinG,!((SSD_Au8CommonCathodeNumbers[Copy_u8Number] >> 6) & 1));
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}

		if(
				(Local_strErrorsState.Local_u8PinAErrorState == ES_OK) &&
				(Local_strErrorsState.Local_u8PinBErrorState == ES_OK) &&
				(Local_strErrorsState.Local_u8PinCErrorState == ES_OK) &&
				(Local_strErrorsState.Local_u8PinDErrorState == ES_OK) &&
				(Local_strErrorsState.Local_u8PinEErrorState == ES_OK) &&
				(Local_strErrorsState.Local_u8PinFErrorState == ES_OK) &&
				(Local_strErrorsState.Local_u8PinGErrorState == ES_OK) &&

				(Local_strErrorsState.Local_u8DotErrorState == ES_OK) &&

				(Local_strErrorsState.Local_u8EnableErrorState == ES_OK)
				)
		{
			Local_enuErrorState = ES_OK;
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

ES_t	SSD_enuEnableCommon(u8 Copy_u8SevenSegmentIndex)
{
	ES_t	Local_enuErrorState = ES_NOK;

	if(SSD_AstrSevenSegmentsInfo != NULL)
	{
		if(SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8Type == SSD_COMMON_CATHODE)
		{
			Local_enuErrorState = DIO_enuSetPinValue(SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8EnablePort, SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8EnablePIN,DIO_u8LOW);
		}
		else if(SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8Type == SSD_COMMON_ANODE)
		{
			Local_enuErrorState = DIO_enuSetPinValue(SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8EnablePort, SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8EnablePIN,DIO_u8HIGH);
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

ES_t	SSD_enuDisableCommon(u8 Copy_u8SevenSegmentIndex)
{
	ES_t	Local_enuErrorState = ES_NOK;

	if(SSD_AstrSevenSegmentsInfo != NULL)
	{
		if(SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8Type == SSD_COMMON_CATHODE)
		{
			Local_enuErrorState = DIO_enuSetPinValue(SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8EnablePort, SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8EnablePIN,DIO_u8HIGH);
		}
		else if(SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8Type == SSD_COMMON_ANODE)
		{
			Local_enuErrorState = DIO_enuSetPinValue(SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8EnablePort, SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8EnablePIN,DIO_u8LOW);
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


ES_t	SSD_enuEnableDot(u8 Copy_u8SevenSegmentIndex)
{
	ES_t	Local_enuErrorState = ES_NOK;

	if(SSD_AstrSevenSegmentsInfo != NULL)
	{
		if(SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8Type == SSD_COMMON_CATHODE)
		{
			Local_enuErrorState = DIO_enuSetPinValue(SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8DotPort, SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8DotPin,DIO_u8HIGH);
		}
		else if(SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8Type == SSD_COMMON_ANODE)
		{
			Local_enuErrorState = DIO_enuSetPinValue(SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8DotPort, SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8DotPin,DIO_u8LOW);
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

ES_t	SSD_enuDisableDot(u8 Copy_u8SevenSegmentIndex)
{
	ES_t	Local_enuErrorState = ES_NOK;

	if(SSD_AstrSevenSegmentsInfo != NULL)
	{
		if(SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8Type == SSD_COMMON_CATHODE)
		{
			Local_enuErrorState = DIO_enuSetPinValue(SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8DotPort, SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8DotPin,DIO_u8LOW);
		}
		else if(SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8Type == SSD_COMMON_ANODE)
		{
			Local_enuErrorState = DIO_enuSetPinValue(SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8DotPort, SSD_AstrSevenSegmentsInfo[Copy_u8SevenSegmentIndex].SSD_u8DotPin,DIO_u8HIGH);
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


