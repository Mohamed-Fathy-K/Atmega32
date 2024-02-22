/*******************************************************************/
/*******************************************************************/
/*******************    Author: Mohamed Fathy    *******************/
/*******************    Layer:  HAL	             *******************/
/*******************    SWC:    LED              *******************/
/*******************    Version:1.00             *******************/
/*******************************************************************/
/*******************************************************************/

#ifndef			LED_CONFIG_H_
#define 		LED_CONFIG_H_

#define 		LED_NUM		3


#define 	LED_SOURCE_CONNECTION		0
#define 	LED_SINK_CONNECTION			1


/////////For initialization state//////////////
#define 		LED_ON		1
#define 		LED_OFF		0
///////////////////////////////////////////////




LED_t	LED_AstrLedsInfo[LED_NUM]	= {
		{DIO_u8PORTD,DIO_u8PIN0,LED_SOURCE_CONNECTION,LED_OFF},
		{DIO_u8PORTD,DIO_u8PIN1,LED_SOURCE_CONNECTION,LED_ON},
		{DIO_u8PORTD,DIO_u8PIN2,LED_SINK_CONNECTION,LED_OFF},
};


#endif
