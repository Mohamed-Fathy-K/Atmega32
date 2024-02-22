/*******************************************************************/
/*******************************************************************/
/*******************    Author: Mohamed Fathy    *******************/
/*******************    Layer:  HAL	             *******************/
/*******************    SWC:    SSD              *******************/
/*******************    Version:1.00             *******************/
/*******************************************************************/
/*******************************************************************/

#ifndef SSD_CONFIG_H_
#define SSD_CONFIG_H_

#include "SSD_interface.h"

#define 	SSD_NUM			2

SSD_t 		SSD_AstrSevenSegmentsInfo[SSD_NUM] ={

	{
		 DIO_u8PORTA, DIO_u8PIN0, //PORT and PIN -> Leg A
		 DIO_u8PORTA, DIO_u8PIN1, //PORT and PIN -> Leg B
		 DIO_u8PORTB, DIO_u8PIN2, //PORT and PIN -> Leg C
		 DIO_u8PORTB, DIO_u8PIN3, //PORT and PIN -> Leg D
		 DIO_u8PORTC, DIO_u8PIN4, //PORT and PIN -> Leg E
		 DIO_u8PORTC, DIO_u8PIN5, //PORT and PIN -> Leg F
		 DIO_u8PORTD, DIO_u8PIN6, //PORT and PIN -> Leg G


		 SSD_NOT_CONNECTED, SSD_NOT_CONNECTED, //PORT and PIN -> Dot

		 DIO_u8PORTD, DIO_u8PIN2, //PORT and PIN -> Enable


		 SSD_COMMON_CATHODE //PORT and PIN -> Type
	},
	{
		 DIO_u8PORTA, DIO_u8PIN2, //PORT and PIN -> Leg A
		 DIO_u8PORTA, DIO_u8PIN3, //PORT and PIN -> Leg B
		 DIO_u8PORTB, DIO_u8PIN4, //PORT and PIN -> Leg C
		 DIO_u8PORTB, DIO_u8PIN5, //PORT and PIN -> Leg D
		 DIO_u8PORTC, DIO_u8PIN6, //PORT and PIN -> Leg E
		 DIO_u8PORTC, DIO_u8PIN7, //PORT and PIN -> Leg F
		 DIO_u8PORTD, DIO_u8PIN0, //PORT and PIN -> Leg G


		 SSD_NOT_CONNECTED, SSD_NOT_CONNECTED, //PORT and PIN -> Dot

		 DIO_u8PORTD, DIO_u8PIN3, //PORT and PIN -> Enable


		 SSD_COMMON_ANODE //PORT and PIN -> Type
	}


};








#endif /* SSD_CONFIG_H_ */
