/*
 * UART_Interface.h
 *
 *  Created on: Jun 16, 2023
 *      Author: DELL
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_INT(void);
void UART_Transmit_charc(u8 Data);
u8 UART_Receive(void);
void UART_Send_String(u8 *str);
void UART_Recive_String (char * str);

#endif /* UART_INTERFACE_H_ */
