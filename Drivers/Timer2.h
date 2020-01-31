/*
 * Timer2.h
 *
 *  Description: Header file for AVR Timer2 driver
 *  Created on: Jan 30, 2020
 *  Author: Mostafa Alaa
 */

#ifndef DRIVERS_TIMER2_H_
#define DRIVERS_TIMER2_H_

#include "Config/micro_config.h"
#include "General/std_types.h"
#include "General/common_macros.h"


/*****************************************************
 * 				Functions Prototypes				 *
 *****************************************************/

/*
 * Initialize Timer2 to work in fast PWM mode
 * with frequency =  488 HZ
 * @param duty_cycle: PWM duty cycle percentage
 * 					  range (0 --> 100)
 */
void PWM_Timer2_init(uint8 duty_cycle);

/*
 * Set PWM duty cycle
 * @param duty_cycle: PWM duty cycle percentage
 * 					  range (0 --> 100)
 */
void PWM_Timer2_setDutyCycle(uint8 duty_cycle);

#endif /* DRIVERS_TIMER2_H_ */
