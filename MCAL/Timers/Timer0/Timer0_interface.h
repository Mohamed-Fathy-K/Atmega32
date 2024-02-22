/*******************************************************************/
/*******************************************************************/
/*******************    Author: Mohamed Fathy    *******************/
/*******************    Layer:  MCAL             *******************/
/*******************    SWC:    Timer0           *******************/
/*******************    Version:1.00             *******************/
/*******************************************************************/
/*******************************************************************/


#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

//#define TIMER0_PRELOAD		TCNT0


void	Timer0_voidInit(void);
ES_t	Timer0_OverflowCallback(void (*pfunISR)(void));
ES_t	Timer0_CompareMatchCallback(void (*pfunISR)(void));
void Timer0_voidSetPreloadValue(u8 Copy_u8PreloadValue);
ES_t	Timer0_PWM_enuGeneration(u8 Copy_u8DutyCycle);

#endif /* TIMER0_INTERFACE_H_ */

