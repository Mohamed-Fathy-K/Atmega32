/*
 * USART_program.c
 *
 *  Created on: Aug 5, 2023
 *      Author: mkotb
 */

#include "STD_TYPES.h"
#include "errorStates.h"
#include "USART_private.h"
#include "USART_config.h"
#include "USART_interface.h"

void USART_voidInit()
{
#if		CHARACTER_SIZE == BIT_5

	UCSRB &=~(1<<UCSRB_UCSZ2);
	UCSRC &=~(1<<UCSRC_UCSZ1);
	UCSRC &=~(1<<UCSRC_UCSZ0);

#elif	CHARACTER_SIZE == BIT_6

	UCSRB &=~(1<<UCSRB_UCSZ2);
	UCSRC &=~(1<<UCSRC_UCSZ1);
	UCSRC |=(1<<UCSRC_UCSZ0);

#elif	CHARACTER_SIZE == BIT_7

	UCSRB &=~(1<<UCSRB_UCSZ2);
	UCSRC |=(1<<UCSRC_UCSZ1);
	UCSRC &=~(1<<UCSRC_UCSZ0);

#elif	CHARACTER_SIZE == BIT_8
	UCSRB &=~(1<<UCSRB_UCSZ2);
	UCSRC |=(1<<UCSRC_UCSZ1);
	UCSRC |=(1<<UCSRC_UCSZ0);

#else
#error "Wrong Configuration of CHARACTER_SIZE in USART"
#endif


	UCSRC &=~(1<<UCSRC_UMSEL);		//Mode operation is set Asynchronous


#if		PARITY_MODE == DISABLED

	UCSRC &=~(1<<UCSRC_UPM1);
	UCSRC &=~(1<<UCSRC_UPM0);

#elif	PARITY_MODE == EVEN_PARITY

	UCSRC |=(1<<UCSRC_UPM1);
	UCSRC &=~(1<<UCSRC_UPM0);

#elif	PARITY_MODE == ODD_PARITY

	UCSRC |=(1<<UCSRC_UPM1);
	UCSRC |=(1<<UCSRC_UPM0);

#else
#error "Wrong Configuration of PARITY_MODE in USART"
#endif


#if		STOP_BITS == ONE_BIT

	UCSRC &=~(1<<UCSRC_USBS);

#elif	STOP_BITS == TWO_BITS

	UCSRC |=(1<<UCSRC_USBS);

#else
#error "Wrong Configuration of STOP_BITS in USART"
#endif


#if		CLOCK_POLARITY == BAUD_RATE_2400

	UBRR = 25;

#elif	BAUD_RATE == BAUD_RATE_9600

	UBRR = 6;

#else
#error "Wrong Configuration of BAUD_RATE in USART"
#endif


	UCSRB |=(1<<UCSRB_TXEN);
	UCSRB |=(1<<UCSRB_RXEN);

}


void USART_voidTransmit(u8 Copy_u8Data)
{
	while(!(UCSRA>>UCSRA_UDRE)){}
	UDR = Copy_u8Data;
}

u8 USART_voidReceive(void)
{
	while(!(UCSRA>>UCSRA_RXC)){}
	return UDR;
}

