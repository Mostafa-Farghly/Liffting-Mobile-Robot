/*
 * DC_Motor.h
 *
 *	Description: Header file for DC-Motors (L293D) driver
 *				 Can control 2 DC-Motors
 *	L293D connections to micro-controller:
 *		PA0 --> IN1
 *		PA1 --> IN2
 *		PA2 --> IN3
 *		PA3 --> IN4
 *		PB3 (PWM) --> EN1
 *		PD7 (PWM) --> EN2
 *	Put Motor1 to the right and Motor2 to the left of your robot
 *
 *  Created on: Jan 30, 2020
 *  Author: Mostafa Alaa
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "Drivers/Config/micro_config.h"
#include "Drivers/General/common_macros.h"
#include "Drivers/General/std_types.h"
#include "Drivers/Timer0.h"
#include "Drivers/Timer2.h"


/* Motion macros */

/* Forward motion */
#define MOVE_FWD()	{								\
			SET_BIT(PORTA, PA0);					\
			CLEAR_BIT(PORTA, PA1);					\
			SET_BIT(PORTA, PA2);					\
			CLEAR_BIT(PORTA, PA3);					\
}

/* Backward motion */
#define MOVE_BWD()	{								\
			CLEAR_BIT(PORTA, PA0);					\
			SET_BIT(PORTA, PA1);					\
			CLEAR_BIT(PORTA, PA2);					\
			SET_BIT(PORTA, PA3);					\
}

/* Turn right */
#define TURN_RIGHT()	{							\
			SET_BIT(PORTA, PA0);					\
			CLEAR_BIT(PORTA, PA1);					\
			CLEAR_BIT(PORTA, PA2);					\
			CLEAR_BIT(PORTA, PA3);					\
}

/* Motors stop */
#define MOTORS_STOP()	{							\
			CLEAR_BIT(PORTA, PA0);					\
			CLEAR_BIT(PORTA, PA1);					\
			CLEAR_BIT(PORTA, PA2);					\
			CLEAR_BIT(PORTA, PA3);					\
}

/* Turn left */
#define TURN_LEFT()	{								\
			SET_BIT(PORTA, PA2);					\
			CLEAR_BIT(PORTA, PA3);					\
			CLEAR_BIT(PORTA, PA0);					\
			CLEAR_BIT(PORTA, PA1);					\
}

/*
 * Speed change macro
 * Does 3 levels of speed shift (35, 70, 100)%
 */
#define SHIFT_GEAR(x)	{							\
			if(x == '1')								\
			{										\
				PWM_Timer0_setDutyCycle(35);		\
				PWM_Timer2_setDutyCycle(35);		\
			}										\
			else if(x == '2')							\
			{										\
				PWM_Timer0_setDutyCycle(70);		\
				PWM_Timer2_setDutyCycle(70);		\
			}										\
			else									\
			{										\
				PWM_Timer0_setDutyCycle(100);		\
				PWM_Timer2_setDutyCycle(100);		\
			}										\
}


/*****************************************************
 * 				Functions Prototypes				 *
 *****************************************************/

/*
 * Initialize pins connected to motor
 */
void Motors_init(void);

#endif /* DC_MOTOR_H_ */
