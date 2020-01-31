/*
 * UART.c
 *
 *	Description: Source file for the UART AVR driver
 *  Created on: Jan 29, 2020
 *  Author: Mostafa Alaa
 */


#include "UART.h"
#include "Config/UART_Config.h"


#define BAUD_PRESCALE (((F_CPU / (UART_BAUDRATE * 8UL))) - 1)


/*****************************************************
 * 				Functions Definitions				 *
 *****************************************************/

void UART_init(const UartCommType type)
{
	/* U2X = 1 for double transmission speed */
		UCSRA = (1<<U2X);
		/************************** UCSRB Description **************************
		 * RXCIE = 0 Disable USART RX Complete Interrupt Enable
		 * TXCIE = 0 Disable USART Tx Complete Interrupt Enable
		 * UDRIE = 0 Disable USART Data Register Empty Interrupt Enable
		 * RXEN  = 1 Receiver Enable
		 * RXEN  = 1 Transmitter Enable
		 * UCSZ2 = 0 For 8-bit data mode
		 * RXB8 & TXB8 not used for 8-bit data mode
		 ***********************************************************************/
		if(type == Full_Duplex)
		{
			UCSRB = (1<<RXEN) | (1<<TXEN);
		}
		else if(type == Transmitter)
		{
			SET_BIT(UCSRB, TXEN);
		}
		else
		{
			SET_BIT(UCSRB, RXEN);
		}

		/************************** UCSRC Description **************************
		 * URSEL   = 1 The URSEL must be one when writing the UCSRC
		 * UMSEL   = 0 Asynchronous Operation
		 * UPM1:0  = 00 Disable parity bit
		 * USBS    = 0 One stop bit
		 * UCSZ1:0 = 11 For 8-bit data mode
		 * UCPOL   = 0 Used with the Synchronous operation only
		 ***********************************************************************/
		UCSRC = (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1);

		/*
		 * First 8 bits from the BAUD_PRESCALE inside UBRRL
		 * last 4 bits in UBRRH
		 */
		CLEAR_BIT(UBRRH, URSEL);
		UBRRH = BAUD_PRESCALE>>8;
		UBRRL = BAUD_PRESCALE;
}


void UART_sendByte(const uint8 data)
{
	/*
	 * Polling till Tx buffer (UDR) is empty and ready
	 * for transmitting a new byte
	 */
	while(BIT_IS_CLEAR(UCSRA,UDRE)){}

	/* Put the required data in the UDR register */
	UDR = data;
}


uint8 UART_recieveByte(void)
{
	/* Polling till UART receive data */
	while(BIT_IS_CLEAR(UCSRA,RXC)){}

	/* Return the received data from the Rx buffer (UDR) */
    return UDR;
}







