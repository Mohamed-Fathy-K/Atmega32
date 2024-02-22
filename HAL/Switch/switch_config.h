/*******************************************************************/
/*******************************************************************/
/*******************    Author: Mohamed Fathy    *******************/
/*******************    Layer:  HAL              *******************/
/*******************    SWC:    switch           *******************/
/*******************    Version:1.00             *******************/
/*******************************************************************/
/*******************************************************************/


#ifndef		SWITCH_CONFIG_H_
#define 	SWITCH_CONFIG_H_



#define SW_NUM		3


SW_t Switch_AstrSwitchInfo [SW_NUM]=
{
		{DIO_u8PORTA, DIO_u8PIN0, DIO_u8FLOAT},
		{DIO_u8PORTA, DIO_u8PIN1, DIO_u8FLOAT},
		{DIO_u8PORTA, DIO_u8PIN2, DIO_u8PULLUP},
};


//SW_t	Switch_AstrSwitchInfo [SW_NUM] =
//{
//		{.switch_u8PortID = DIO_u8PORTA, .switch_u8PinID = DIO_u8PIN0, .switch_u8Type = DIO_u8FLOAT},
//		{.switch_u8PortID = DIO_u8PORTA, .switch_u8PinID = DIO_u8PIN1, .switch_u8Type = DIO_u8FLOAT},
//		{.switch_u8PortID = DIO_u8PORTA, .switch_u8PinID = DIO_u8PIN2, .switch_u8Type = DIO_u8FLOAT},
//
//};

#endif
