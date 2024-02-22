/*
 * EXTI_interface.h
 *
 *  Created on: Apr 18, 2023
 *      Author: mkotb
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


void EXTI_enuInt0Init(void);
void EXTI_enuInt1Init(void);
void EXTI_enuInt2Init(void);

ES_t EXTI_enuINT0SetCallback(void(*pfuncINT0)(void));
ES_t EXTI_enuINT1SetCallback(void(*pfuncINT1)(void));
ES_t EXTI_enuINT2SetCallback(void(*pfuncINT2)(void));

#endif /* EXTI_INTERFACE_H_ */
