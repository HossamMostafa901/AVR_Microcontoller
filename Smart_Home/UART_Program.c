/*
 * UART_Program.c
 *
 *  Created on: Jun 16, 2023
 *      Author: DELL
 */
#include"util/delay.h"
#include"bitscalcu.h"
#include"std_types.h"
#include"DIO_Interface.h"
#include"UART_Private.h"
#include"UART_Interface.h"

/*tp=data/frame,min=5/9=55.5,max=9/11=81.8   */

void UART_INT(void)
{
 UART_UBRRH=0;//slect UBRH
 UART_UBRRL=51;//UBRR value=system freq/16*baudrate-1 bad=9600
 UART_UCSRC=0b10000110;/*select UCSRC ASync No parity,1 stop Bit*/
 UART_UCSRB=0b00011000;/*Reviceve Enable Transmit ,Data Bits*/

}
void UART_Transmit_charc(u8 Data)
{
	while(get_bit(UART_UCSRA,5)==0);//check if data regisiter Empty or not
	UART_UDR=Data;
	set_bit(UART_UCSRA,5);
}
u8 UART_Receive(void)
{
	while(get_bit(UART_UCSRA,7)==0);//rx complete
	set_bit(UART_UCSRA,5);
	return UART_UDR;
}
void UART_Send_String(u8 *str)
{
	u8 i=0;
	while(str[i]!='\0')
	{
		UART_Transmit_charc(str[i]);
			 i++;
	}
	//UART_Transmit_charc('\0');
}
void UART_Recive_String (char * str)
{
	u8 loccal_itratior=0;
	str[loccal_itratior]=UART_Receive();
	while(str[loccal_itratior]!='#')
	{
		loccal_itratior++;
		str[loccal_itratior]=UART_Receive();//^@
	}
	str[loccal_itratior]='\0';
}
