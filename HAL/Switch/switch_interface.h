/*******************************************************************/
/*******************************************************************/
/*******************    Author: Mohamed Fathy    *******************/
/*******************    Layer:  HAL              *******************/
/*******************    SWC:    switch           *******************/
/*******************    Version:1.00             *******************/
/*******************************************************************/
/*******************************************************************/

#ifndef		SWITCH_INTERFACE_H_
#define 	SWITCH_INTERFACE_H_



typedef struct
{
	u8 switch_u8PortID;
	u8 switch_u8PinID;
	u8 switch_u8Type;
}SW_t;


ES_t 	switch_enuInit(SW_t* Copy_AstrSwitchInfo);

ES_t 	switch_enuGetState(SW_t* Copy_strSwitchInfo, u8* Copy_pu8State);


#endif
