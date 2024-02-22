/*******************************************************************/
/*******************************************************************/
/*******************    Author: Mohamed Fathy    *******************/
/*******************    Layer:  HAL	             *******************/
/*******************    SWC:    LED              *******************/
/*******************    Version:1.00             *******************/
/*******************************************************************/
/*******************************************************************/


#ifndef			LED_INTERFACE_H_
#define 		LED_INTERFACE_H_

#include  "LED_private.h"


#define 		LED0 		0
#define 		LED1 		1
#define 		LED2 		2
#define 		LED3 		3
#define 		LED4 		4
#define 		LED5 		5
#define 		LED6 		6
#define 		LED7 		7
#define 		LED8 		8
#define 		LED9 		9
#define 		LED10		10
#define 		LED11		11
#define 		LED12		12
#define 		LED13		13
#define 		LED14		14
#define 		LED15		15
#define 		LED16		16
#define 		LED17		17
#define 		LED18		18
#define 		LED19		19
#define 		LED20		20
#define 		LED21		21
#define 		LED22		22
#define 		LED23		23
#define 		LED24		24
#define 		LED25		25
#define 		LED26		26
#define 		LED27		27
#define 		LED28		28
#define 		LED29		29
#define 		LED30		30
#define 		LED31		31



ES_t	LED_enuInit(LED_t* AstrConfig);

ES_t	LED_enuTurnLedOn(LED_t* strConfig);

ES_t	LED_enuTurnLedOff(LED_t* strConfig);


#endif
