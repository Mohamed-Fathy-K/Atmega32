/*
 * USART_interface.h
 *
 *  Created on: Aug 5, 2023
 *      Author: mkotb
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

void USART_voidInit();
void USART_voidTransmit(u8 Copy_u8Data);
u8 USART_voidReceive(void);
#endif /* USART_INTERFACE_H_ */
