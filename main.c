/*
 * main.c
 *
 *	Description: "Lifting Robot" Application Code
 *  Created on: Jan 30, 2020
 *  Author: Mostafa Alaa
 */


#include "LiftingMechanism_AVR_drivers.h"


int main(void)
{
	/* Application Initialization */
	/* UART Initialization */
	UART_init((UartCommType)Reciever);

	/* Motion motors Initialization */
	Motors_init();

	/* Used variables */

	/*
	 * pressedButton: Holds the data received by the UART,
	 * which specifies which button is pressed in the mobile application
	 */
	uint8 pressedButton = UART_recieveByte();

	/* Application Loop */
	while(TRUE)
	{
		/* Receive data from bluetooth module by UART */
		//pressedButton = UART_recieveByte();

		if(pressedButton == '1' || pressedButton == '2' || pressedButton == '3')
		{
			/* Change PWM (Control speed) */
			SHIFT_GEAR(pressedButton);

			/* Read button */
			pressedButton = UART_recieveByte();
		}
		else if(pressedButton == '4')
		{
			/* Move Robot Forward */
			MOVE_FWD();

			/* Keep Moving while button is still pressed */
			while(pressedButton == '4')
			{
				pressedButton = UART_recieveByte();
			}
		}
		else if(pressedButton == '5')
		{
			/* Move Robot Backward */
			MOVE_BWD();

			/* Keep Moving while button is still pressed */
			while(pressedButton == '5')
			{
				pressedButton = UART_recieveByte();
			}
		}
		else if(pressedButton == '6')
		{
			/* Turn Robot Right */
			TURN_RIGHT();

			/* Keep Moving while button is still pressed */
			while(pressedButton == '6')
			{
				pressedButton = UART_recieveByte();
			}
		}
		else if(pressedButton == '7')
		{
			/* Turn Robot Right */
			TURN_LEFT();

			/* Keep Moving while button is still pressed */
			while(pressedButton == '7')
			{
				pressedButton = UART_recieveByte();
			}
		}
		else if(pressedButton == '0')
		{
			/* Stop Robot */
			MOTORS_STOP();
			/* Read button */
			pressedButton = UART_recieveByte();
		}
	}
}
