/*******************************************************************/
/*******************************************************************/
/*******************    Author: Mohamed Fathy    *******************/
/*******************    Layer:  HAL	             *******************/
/*******************    SWC:    SSD              *******************/
/*******************    Version:1.00             *******************/
/*******************************************************************/
/*******************************************************************/

#ifndef SSD_PRIVATE_H_
#define SSD_PRIVATE_H_

#define SSD_Numbers			10

typedef struct
{
	u8 SSD_u8PortA;
	u8 SSD_u8PinA;

	u8 SSD_u8PortB;
	u8 SSD_u8PinB;

	u8 SSD_u8PortC;
	u8 SSD_u8PinC;

	u8 SSD_u8PortD;
	u8 SSD_u8PinD;

	u8 SSD_u8PortE;
	u8 SSD_u8PinE;

	u8 SSD_u8PortF;
	u8 SSD_u8PinF;

	u8 SSD_u8PortG;
	u8 SSD_u8PinG;


	u8 SSD_u8DotPort;
	u8 SSD_u8DotPin;

	u8 SSD_u8EnablePort;
	u8 SSD_u8EnablePIN;

	u8 SSD_u8Type;

}SSD_t;

//u8 SSD_Au8CommonCathodeNumbers[SSD_Numbers] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F}; // 0 1 2 3 4 5 6 7 8 9


#endif /* SSD_PRIVATE_H_ */
