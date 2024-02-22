/*******************************************************************/
/*******************************************************************/
/*******************    Author: Mohamed Fathy    *******************/
/*******************    Layer:  HAL	             *******************/
/*******************    SWC:    LED              *******************/
/*******************    Version:1.00             *******************/
/*******************************************************************/
/*******************************************************************/


#ifndef			LED_PRIVATE_H_
#define 		LED_PRIVATE_H_



typedef	struct
{
	u8	LED_u8PortID;
	u8	LED_u8PinID;
	u8	LED_u8ConnectionType;
	u8	LED_u8InitState;

}LED_t;

#endif