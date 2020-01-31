/*
 * UART.h
 *
 *	Description: Header file for the UART AVR driver
 *  Created on: Jan 29, 2020
 *  Author: Mostafa Alaa
 */

#ifndef DRIVERS_UART_H_
#define DRIVERS_UART_H_

#include "Config/micro_config.h"
#include "General/std_types.h"
#include "General/common_macros.h"


/*****************************************************
 * 				Enumerations Used    				 *
 *****************************************************/
/*
 * Used by the UART initialization (UART_init) to specify
 * the communication type of the UART (Simplex or Complex)
 */
typedef enum
{
	Full_Duplex,
	Transmitter,
	Reciever
}UartCommType;

/*****************************************************
 * 				Functions Prototypes				 *
 *****************************************************/

/*
 * UART Initialization function
 * Initializes the UART to work in double speed,
 * 8-bit mode, with disabled parity check and
 * one stop bit
 * @param type: Full_Duplex to enable both receiving and transmitting
 * 				Transmitter to enable transmitting only
 * 				Receiver to enable receiving only
 */
void UART_init(const UartCommType type);

/*
 * Send a byte by UART (Transmitting must be enabled)
 * @param data: byte to be sent by UART
 */
void UART_sendByte(const uint8 data);

/*
 * Read the UART received byte (Receiving must be enabled)
 * @return the data received by the UART
 */
uint8 UART_recieveByte(void);


#endif /* DRIVERS_UART_H_ */
