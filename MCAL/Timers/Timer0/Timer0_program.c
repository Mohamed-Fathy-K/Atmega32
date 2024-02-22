/*******************************************************************/
/*******************************************************************/
/*******************    Author: Mohamed Fathy    *******************/
/*******************    Layer:  MCAL             *******************/
/*******************    SWC:    Timer0           *******************/
/*******************    Version:1.00             *******************/
/*******************************************************************/
/*******************************************************************/

#include "STD_TYPES.h"
#include "errorStates.h"


#include "Timer0_private.h"
#include "Timer0_config.h"
#include "Timer0_interface.h"

void (*Timer0_pfunOverflowInterrupt)(void) = NULL;
void (*Timer0_pfunCompareMatchInterrupt)(void) = NULL;

void	Timer0_voidInit(void)
{
#if		WAVEFORM_GENERATION_MODE	== 	NORMAL

	TCCR0 &=~(1<<TCCR0_WGM01);		//choosing the overflow mode
	TCCR0 &=~(1<<TCCR0_WGM00);		//choosing the overflow mode

	TIMSK |=(1<<TIMSK_TOIE0);		//Overflow Interrupt Enable
#elif	WAVEFORM_GENERATION_MODE	==	CTC

	TCCR0 |=(1<<TCCR0_WGM01);		//choosing the compare match mode
	TCCR0 &=~(1<<TCCR0_WGM00);		//choosing the compare match mode

	TIMSK |=(1<<TIMSK_OCIE0);		//Compare Match Interrupt Enable

	#if COMPARE_MATCH_VALUE >= 0 && COMPARE_MATCH_VALUE <= 255
	OCR0	= COMPARE_MATCH_VALUE;	//setting the compare match value
	#else
	#error "Wrong Configuration of COMPARE_MATCH_VALUE"
	#endif

	#if		COMPARE_MATCH_OUTPUT_MODE	== OC0_DISCONNECTED

	TCCR0	&=~(1<<TCCR0_COM01);
	TCCR0	&=~(1<<TCCR0_COM00);

	#elif	COMPARE_MATCH_OUTPUT_MODE	== OC0_TOGGLE

	TCCR0	&=~(1<<TCCR0_COM01);
	TCCR0	|=(1<<TCCR0_COM00);

	#elif	COMPARE_MATCH_OUTPUT_MODE	== OC0_CLEAR

	TCCR0	|=(1<<TCCR0_COM01);
	TCCR0	&=~(1<<TCCR0_COM00);

	#elif	COMPARE_MATCH_OUTPUT_MODE	== OC0_SET

	TCCR0	|=(1<<TCCR0_COM01);
	TCCR0	|=(1<<TCCR0_COM00);

	#else
	#error "Wrong Configuration of COMPARE_MATCH_OUTPUT_MODE"

	#endif
#elif	WAVEFORM_GENERATION_MODE	==	FAST_PWM

	TCCR0 |=(1<<TCCR0_WGM01);			//choosing fast PWM mode
	TCCR0 |=(1<<TCCR0_WGM00);			//choosing fast PWM mode

	#if 	COMPARE_MATCH_OUTPUT_MODE	== NON_INVERTED_MODE

	 TCCR0	|=(1<<TCCR0_COM01);
     TCCR0	&=~(1<<TCCR0_COM00);

	#else
	#error "Wrong Configuration of COMPARE_MATCH_OUTPUT_MODE"
	#endif


#else
#error "Wrong Configuration of WAVEFORM_GENERATION_MODE"
#endif

#if CLOCK_SELECTION >=0 && CLOCK_SELECTION <= 7
	TCCR0 	&=~(0x07);								//select the clock
	TCCR0	|= CLOCK_SELECTION;						//select the clock
#else
#error "Wrong Configuration of CLOCK_SELECTION"
#endif

}

ES_t __vector_11 (void) __attribute__((signal));
ES_t __vector_11 (void)
{
	ES_t Local_enuErrorState  = ES_NOK;
	if(Timer0_pfunOverflowInterrupt == NULL)
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	else
	{
		Timer0_pfunOverflowInterrupt();
	}
	return Local_enuErrorState;
}

void Timer0_voidSetPreloadValue(u8 Copy_u8PreloadValue)
{
	TCNT0 = Copy_u8PreloadValue;
}

ES_t	Timer0_OverflowCallback(void (*pfunISR)(void))
{
	ES_t Local_enuErrorState  = ES_NOK;
	if(pfunISR == NULL)
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	else
	{
		Timer0_pfunOverflowInterrupt = pfunISR;
	}
	return Local_enuErrorState;
}

ES_t __vector_10 (void) __attribute__((signal));
ES_t __vector_10 (void)
{
	ES_t Local_enuErrorState  = ES_NOK;
	if(Timer0_pfunCompareMatchInterrupt == NULL)
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	else
	{
		Timer0_pfunCompareMatchInterrupt();
	}
	return Local_enuErrorState;
}


ES_t	Timer0_CompareMatchCallback(void (*pfunISR)(void))
{
	ES_t Local_enuErrorState  = ES_NOK;
	if(pfunISR == NULL)
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	else
	{
		Timer0_pfunCompareMatchInterrupt = pfunISR;
	}
	return Local_enuErrorState;
}


ES_t	Timer0_PWM_enuGeneration(u8 Copy_u8DutyCycle)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8DutyCycle >= 0 && Copy_u8DutyCycle <= 100)
	{
		Local_enuErrorState = ES_OK;

		if(COMPARE_MATCH_OUTPUT_MODE == NON_INVERTED_MODE)
		{
			OCR0 = (Copy_u8DutyCycle*256)/100;
		}
		else if(COMPARE_MATCH_OUTPUT_MODE == INVERTED_MODE)
		{

		}
		else
		{
			Local_enuErrorState = ES_NOK;
		}
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}
