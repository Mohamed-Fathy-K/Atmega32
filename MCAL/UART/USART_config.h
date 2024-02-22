/*
 * USART_config.h
 *
 *  Created on: Aug 5, 2023
 *      Author: mkotb
 */

#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_


/*	OPTIONS
 *
 * 	BIT_5
 * 	BIT_6
 * 	BIT_7
 * 	BIT_8
 */

#define CHARACTER_SIZE			BIT_8

/*	OPTIONS
 *
 * 	DISABLED
 * 	EVEN_PARITY
 * 	ODD_PARITY
 *
 */

#define PARITY_MODE				DISABLED

/*	OPTIONS
 *
 * 	ONE_BIT
 * 	TWO_BITS
 */

#define STOP_BITS				ONE_BIT


/*	OPTIONS
 *
 * 	BAUD_RATE_2400
 * 	BAUD_RATE_9600
 * 	BAUD_RATE_19.2k
 * 	BAUD_RATE_38.4k
 * 	BAUD_RATE_76.8k
 * 	BAUD_RATE_230.4k
 * 	BAUD_RATE_1M
 *
 */

#define BAUD_RATE			BAUD_RATE_9600

#endif /* USART_CONFIG_H_ */
