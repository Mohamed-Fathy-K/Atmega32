/*******************************************************************/
/*******************************************************************/
/*******************    Author: Mohamed Fathy    *******************/
/*******************    Layer:  MCAL             *******************/
/*******************    SWC:    Timer0           *******************/
/*******************    Version:1.00             *******************/
/*******************************************************************/
/*******************************************************************/


#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_

/*		Options					Description
 *
 *	 	NORMAL					overflow mode
 * 		PWM_PHASE_CORRECT
 * 		CTC						compare match mode
 * 		FAST_PWM
 */
#define WAVEFORM_GENERATION_MODE			FAST_PWM


/*		Options for non-PWM-Mode	Options for PWM Mode
 *
 *	 	OC0_DISCONNECTED            OC0_DISCONNECTED
 * 		OC0_TOGGLE                  INVERTED_MODE
 * 		OC0_CLEAR                   NON_INVERTED_MODE
 * 		OC0_SET
 */
#define COMPARE_MATCH_OUTPUT_MODE			NON_INVERTED_MODE


#define COMPARE_MATCH_VALUE			250		//FROM 0 TO 255

/*		Options 			Description
 *
 *	 	0            		No clock source (Timer/Counter stopped).
 * 		1                  	source clock (No prescaling)
 * 		2                  	source clock/8 From prescaler
 * 		3                   source clock/64 From prescaler
 * 		4                   source clock/256 From prescaler
 * 		5                   source clock/1024 From prescaler
 * 		6                   External clock source on T0 pin. Clock on falling edge.
 * 		7                   External clock source on T0 pin. Clock on rising edge.
 */
#define	CLOCK_SELECTION		2



#endif /* TIMER0_CONFIG_H_ */
