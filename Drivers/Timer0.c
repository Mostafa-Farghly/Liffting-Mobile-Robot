/*
 * Timer0.c
 *
 *	Description: Source file for AVR Timer0 driver
 *  Created on: Jan 30, 2020
 *  Author: Mostafa Alaa
 */


#include "Timer0.h"


#define SET_DUTYCYCLE(DUTYCYCLE) ((DUTYCYCLE * 255) / 100)


/*****************************************************
 * 				Functions Definitions				 *
 *****************************************************/

void PWM_Timer0_init(uint8 duty_cycle)
{
	/* Initial timer value */
	TCNT0 = 0;

	/* Set duty cycle */
	duty_cycle %= 101;
	OCR0  = SET_DUTYCYCLE(duty_cycle);

	/* Set OC0 as output pin */
	DDRB  = DDRB | (1 << PB3);

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1 << WGM00) | (1 << WGM01) | (1 << COM01) | (1 << CS01);
}

void PWM_Timer0_setDutyCycle(uint8 duty_cycle)
{
	/* Set duty cycle */
	duty_cycle %= 101;
	OCR0  = SET_DUTYCYCLE(duty_cycle);
}







