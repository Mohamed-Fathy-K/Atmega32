/*******************************************************************/
/*******************************************************************/
/*******************    Author: Mohamed Fathy    *******************/
/*******************    Layer:  HAL	             *******************/
/*******************    SWC:    SSD              *******************/
/*******************    Version:1.00             *******************/
/*******************************************************************/
/*******************************************************************/

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_
#include "SSD_private.h"

#define 		SSD_NOT_CONNECTED	  	2


#define 		SSD_COMMON_CATHODE		2
#define 		SSD_COMMON_ANODE		3


ES_t	SSD_enuInit(SSD_t* AstrSevenSegmentsInfo);

ES_t	SSD_enuDisplayNum(u8 Copy_u8SevenSegmentIndex, u8 Copy_u8Number);

ES_t	SSD_enuEnableCommon(u8 Copy_u8SevenSegmentIndex);

ES_t	SSD_enuDisableCommon(u8 Copy_u8SevenSegmentIndex);

ES_t	SSD_enuEnableDot(u8 Copy_u8SevenSegmentIndex);

ES_t	SSD_enuDisableDot(u8 Copy_u8SevenSegmentIndex);


#endif /* SSD_INTERFACE_H_ */
