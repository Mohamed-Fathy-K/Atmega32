/*
 * USART_private.h
 *
 *  Created on: Aug 5, 2023
 *      Author: mkotb
 */

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

#define 	UDR							*((volatile u8*) 0x2C)	//Transmit Data Buffer Register & Receive Data Buffer Register (RXB).
#define 	UCSRA						*((volatile u8*) 0x2B)	//USART Control and Status Register A
#define 	UCSRA_RXC					7						//USART Receive Complete
#define 	UCSRA_TXC					6						//USART Transmit Complete
#define 	UCSRA_UDRE					5						//USART Data Register Empty
#define 	UCSRA_FE					4						//Frame Error
#define 	UCSRA_DOR					3						//Data OverRun
#define 	UCSRA_PE					2						//Parity Error
#define 	UCSRA_U2X					1						//Double the USART Transmission Speed
#define 	UCSRA_MPCM					0						//Multi-processor Communication Mode

#define 	UCSRB						*((volatile u8*) 0x2A)	//USART Control and Status Register B
#define 	UCSRB_RXCIE					7						//RX Complete Interrupt Enable
#define 	UCSRB_TXCIE					6						//TX Complete Interrupt Enable
#define 	UCSRB_UDRIE					5						//USART Data Register Empty Interrupt Enable
#define 	UCSRB_RXEN					4						//Receiver Enable
#define 	UCSRB_TXEN					3						//Transmitter Enable
#define 	UCSRB_UCSZ2					2						//Character Size
#define 	UCSRB_RXB8					1						//Receive Data Bit 8
#define 	UCSRB_TXB8					0						//Transmit Data Bit 8

#define 	UCSRC						*((volatile u8*) 0x40)	//USART Control and Status Register C
#define 	UCSRC_URSEL					7						//Register Select
#define 	UCSRC_UMSEL					6						//USART Mode Select
#define 	UCSRC_UPM1					5						//Parity Mode
#define 	UCSRC_UPM0					4						//Parity Mode
#define 	UCSRC_USBS					3						//Stop Bit Select
#define 	UCSRC_UCSZ1					2						//Character Size
#define 	UCSRC_UCSZ0					1						//Character Size
#define 	UCSRC_UCPOL					0						//Clock Polarity

#define 	UBRRL						*((volatile u8*) 0x29)	//Baud Rate Register
#define 	UBRRH						*((volatile u8*) 0x40)	//Baud Rate Register
#define 	UBRR						*((volatile u16*) 0x29)	//Baud Rate Register

//#define 	UBRRH						7						//Register Select




#define 	BIT_5						5						//OPTIONS OF CHARACTER_SIZE
#define 	BIT_6						6
#define 	BIT_7						7
#define 	BIT_8						8
#define 	BIT_9						9


#define 	DISABLED					0						//OPTIONS OF PARITY_MODE
#define 	ODD_PARITY					3
#define 	EVEN_PARITY					2


#define 	ONE_BIT						0						//OPTIONS OF STOP_BITS
#define 	TWO_BITS					1


#define		BAUD_RATE_2400   			11						//OPTIONS OF BAUD_RATE
#define		BAUD_RATE_9600   			12
#define		BAUD_RATE_19200   			13
#define		BAUD_RATE_38400  			14
#define		BAUD_RATE_76800 			15
#define		BAUD_RATE_230400 			16
#define		BAUD_RATE_1M     			17






#endif /* USART_PRIVATE_H_ */
