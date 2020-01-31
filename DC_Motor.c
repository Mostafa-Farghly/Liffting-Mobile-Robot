/*
 * DC_Motor.c
 *
 *	Description: Source file for DC-Motors (L293D) driver
 *				 Can control 2 DC-Motors
 *  Created on: Jan 30, 2020
 *  Author: Mostafa Alaa
 */


#include "DC_Motor.h"


/*****************************************************
 * 				Functions Definitions				 *
 *****************************************************/

void Motors_init(void)
{
	/* Set pins as output */
	SET_BIT(DDRA, PA0);
	SET_BIT(DDRA, PA1);
	SET_BIT(DDRA, PA2);
	SET_BIT(DDRA, PA3);

	/* Motors are stopped at the beginning */
	CLEAR_BIT(PORTA, PA0);
	CLEAR_BIT(PORTA, PA1);
	CLEAR_BIT(PORTA, PA2);
	CLEAR_BIT(PORTA, PA3);

	/* Initialize PWM pins */
	PWM_Timer0_init(0);
	PWM_Timer2_init(0);
}
