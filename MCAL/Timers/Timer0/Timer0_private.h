/*******************************************************************/
/*******************************************************************/
/*******************    Author: Mohamed Fathy    *******************/
/*******************    Layer:  MCAL             *******************/
/*******************    SWC:    Timer0           *******************/
/*******************    Version:1.00             *******************/
/*******************************************************************/
/*******************************************************************/



#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#define 	TCCR0								*((volatile u8*)0x53)		//Timer/Counter Control Register

#define 	TCCR0_FOC0							7							//Force Output Compare

#define 	TCCR0_WGM01							3							//Waveform Generation Mode
#define 	TCCR0_WGM00							6							//Waveform Generation Mode
#define 	NORMAL								10							//Configuration of WAVEFORM_GENERATION_MODE
#define 	CTC									11                          //Configuration of WAVEFORM_GENERATION_MODE
#define 	PWM_PHASE_CORRECT					12                          //Configuration of WAVEFORM_GENERATION_MODE
#define 	FAST_PWM							13                          //Configuration of WAVEFORM_GENERATION_MODE

#define 	TCCR0_COM01							5							//Compare Match Output Mode
#define 	TCCR0_COM00							4							//Compare Match Output Mode
#define 	OC0_DISCONNECTED					10							//Configuration of COMPARE_MATCH_OUTPUT_MODE
#define 	OC0_TOGGLE							11                          //Configuration of COMPARE_MATCH_OUTPUT_MODE
#define 	OC0_CLEAR							12                          //Configuration of COMPARE_MATCH_OUTPUT_MODE
#define 	OC0_SET								13                          //Configuration of COMPARE_MATCH_OUTPUT_MODE
#define 	INVERTED_MODE					 	14                          //Configuration of COMPARE_MATCH_OUTPUT_MODE
#define 	NON_INVERTED_MODE				 	15                          //Configuration of COMPARE_MATCH_OUTPUT_MODE


#define 	TCCR0_CS02							2							//Clock Select
#define 	TCCR0_CS01							1							//Clock Select
#define 	TCCR0_CS00							0							//Clock Select


#define 	TCNT0								*((volatile u8*)0x52)		//Timer/Counter Register


#define 	OCR0								*((volatile u8*)0x5C)		//Output Compare Register


#define 	TIMSK								*((volatile u8*)0x59)		//Timer/Counter Interrupt Mask Register

#define 	TIMSK_OCIE0							1							//Timer/Counter0 Output Compare Match Interrupt Enable

#define 	TIMSK_TOIE0							0							//Timer/Counter0 Overflow Interrupt Enable


#define 	TIFR								*((volatile u8*)0x58)		//Timer/Counter Interrupt Flag Register

#define 	TIFR_OCF0							1							//Output Compare Flag 0

#define 	TIFR_TOV0							0							//Timer/Counter0 Overflow Flag




#endif /* TIMER0_PRIVATE_H_ */

