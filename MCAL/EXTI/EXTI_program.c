/*******************************************************************/
/*******************************************************************/
/*******************    Author: Mohamed Fathy    *******************/
/*******************    Layer:  MCAL             *******************/
/*******************    SWC:    EXIT             *******************/
/*******************    Version:1.00             *******************/
/*******************************************************************/
/*******************************************************************/

#include "STD_TYPES.h"
#include "errorStates.h"

#include "EXTI_private.h"
#include "EXTI_config.h"

#include "EXTI_interface.h"

void (*EXTI_pfuncINT0) (void) = 	NULL;
void (*EXTI_pfuncINT1) (void) = 	NULL;
void (*EXTI_pfuncINT2) (void) = 	NULL;

void EXTI_enuInt0Init(void)
{
#if 	INT0_SENSE == INT_SENSE_LOW_LEVEL

	MCUCR &= ~(1<<MCUCR_ISC00);
	MCUCR &= ~(1<<MCUCR_ISC01);

#elif	INT0_SENSE == ON_CHANGE

	MCUCR |= (1<<MCUCR_ISC00);
	MCUCR &= ~(1<<MCUCR_ISC01);

#elif	INT0_SENSE == INT_SENSE_FALLING_EDGE

	MCUCR &= ~(1<<MCUCR_ISC00);
	MCUCR |= (1<<MCUCR_ISC01);

#elif	INT0_SENSE == INT_SENSE_RISING_EDGE

	MCUCR |= (1<<MCUCR_ISC00);
	MCUCR |= (1<<MCUCR_ISC01);

#else

#error "Wrong INT0_SENSE configuration option"

#endif


#if		GICR_INT0_STATUS == GICR_Enabled

	GICR |=(1<<GICR_INT0);

#elif	GICR_INT0_STATUS == GICR_Disabled

	GICR &= ~(1<<GICR_INT0);

#else

#error "Wrong GICR_INT0 configuration option"

#endif

}

void EXTI_enuInt1Init(void)
{
#if 	INT1_SENSE == INT_SENSE_LOW_LEVEL

	MCUCR &= ~(1<<MCUCR_ISC10);
	MCUCR &= ~(1<<MCUCR_ISC11);

#elif	INT1_SENSE == INT_SENSE_ON_CHANGE

	MCUCR |= (1<<MCUCR_ISC10);
	MCUCR &= ~(1<<MCUCR_ISC11);

#elif	INT1_SENSE == INT_SENSE_FALLING_EDGE

	MCUCR &= ~(1<<MCUCR_ISC10);
	MCUCR |= (1<<MCUCR_ISC11);

#elif	INT1_SENSE == INT_SENSE_RISING_EDGE

	MCUCR |= (1<<MCUCR_ISC10);
	MCUCR |= (1<<MCUCR_ISC11);

#else

#error "Wrong INT1_SENSE configuration option"

#endif

#if		GICR_INT1_STATUS == GICR_Enabled

	GICR |=(1<<GICR_INT1);

#elif	GICR_INT1_STATUS == GICR_Disabled

	GICR &= ~(1<<GICR_INT1);

#else

#error "Wrong GICR_INT1 configuration option"

#endif
}

void EXTI_enuInt2Init(void)
{

#if 	INT2_SENSE == INT_SENSE_FALLING_EDGE

	MCUCSR &= ~(1<<MCUCSR_ISC2);

#elif	INT2_SENSE == INT_SENSE_RISING_EDGE

	MCUCSR |= (1<<MCUCSR_ISC2);

#else

#error "Wrong INT2_SENSE configuration option"

#endif

#if		GICR_INT2 == GICR_Enabled

	GICR |=(1<<GICR_INT2);

#elif	GICR_INT2 == GICR_Disabled

	GICR &= ~(1<<GICR_INT2);

#else

#error "Wrong GICR_INT2 configuration option"

#endif

}

ES_t EXTI_enuINT0SetCallback(void(*pfuncINT0)(void))
{
	if(pfuncINT0 == NULL)
	{
		return ES_NULL_POINTER;
	}
	else
	{
		EXTI_pfuncINT0 = pfuncINT0;
		return ES_OK;
	}
}

ES_t __vector_1	(void) __attribute__((signal));
ES_t __vector_1	(void)
{
	if(EXTI_pfuncINT0 == NULL)
	{
		return ES_NULL_POINTER;
	}
	else
	{
		EXTI_pfuncINT0();
		return ES_OK;
	}
}



ES_t EXTI_enuINT1SetCallback(void(*pfuncINT1)(void))
{
	if(pfuncINT1 == NULL)
	{
		return ES_NULL_POINTER;
	}
	else
	{
		EXTI_pfuncINT1 = pfuncINT1;
		return ES_OK;
	}
}

ES_t __vector_2	(void) __attribute__((signal));
ES_t __vector_2	(void)
{
	if(EXTI_pfuncINT1 == NULL)
	{
		return ES_NULL_POINTER;
	}
	else
	{
		EXTI_pfuncINT1();
		return ES_OK;
	}
}



ES_t EXTI_enuINT2SetCallback(void(*pfuncINT2)(void))
{
	if(pfuncINT2 == NULL)
	{
		return ES_NULL_POINTER;
	}
	else
	{
		EXTI_pfuncINT2 = pfuncINT2;
		return ES_OK;
	}
}

ES_t __vector_3	(void) __attribute__((signal));
ES_t __vector_3	(void)
{
	if(EXTI_pfuncINT2 == NULL)
	{
		return ES_NULL_POINTER;
	}
	else
	{
		EXTI_pfuncINT2();
		return ES_OK;
	}
}
