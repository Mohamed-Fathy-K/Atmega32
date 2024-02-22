/*******************************************************************/
/*******************************************************************/
/*******************    Author: Mohamed Fathy    *******************/
/*******************    Layer:  MCAL             *******************/
/*******************    SWC:    EXIT             *******************/
/*******************    Version:1.00             *******************/
/*******************************************************************/
/*******************************************************************/

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/*  Options
  			INT_SENSE_LOW_LEVEL
			INT_SENSE_ON_CHANGE
			INT_SENSE_FALLING_EDGE
			INT_SENSE_RISING_EDGE
 */

#define INT0_SENSE		INT_SENSE_RISING_EDGE
#define INT1_SENSE		INT_SENSE_FALLING_EDGE
#define INT2_SENSE		INT_SENSE_FALLING_EDGE

/*  Options
  			LOW_LEVEL
			ON_CHANGE
 */

#define GICR_INT0_STATUS		GICR_Enabled
#define GICR_INT1_STATUS		GICR_Enabled
#define GICR_INT2_STATUS		GICR_Enabled

#endif /* EXTI_CONFIG_H_ */
