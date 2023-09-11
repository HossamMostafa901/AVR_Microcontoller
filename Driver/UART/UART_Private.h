/*
 * UART_Private.h
 *
 *  Created on: Jun 16, 2023
 *      Author: DELL
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#define UART_UDR        *((volatile u8*)0x2C)
#define UART_UCSRA      *((volatile u8*)0x2B)
#define UART_UCSRB      *((volatile u8*)0x2A)
#define UART_UCSRC      *((volatile u8*)0x40)
#define UART_UBRRL      *((volatile u8*)0x29)
#define UART_UBRRH      *((volatile u8*)0x40)



#endif /* UART_PRIVATE_H_ */
