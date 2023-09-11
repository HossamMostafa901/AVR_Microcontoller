/*
 * main.c
 *
 *  Created on: Jun 16, 2023
 *      Author: DELL
 */
#include"bitscalcu.h"
#include"std_types.h"
#include"DIO_Interface.h"
#include"Interface.h"
#include"UART_Interface.h"

void main(void)
{ u8 a[10];
   LCD_Int_4bit();
	DIO_u8Set_Pin_Direction(Group_D,DIO_U8_PIN0,INPUT);
	DIO_u8Set_Pin_Direction(Group_D,DIO_U8_PIN1,OUTPUT);
	UART_INT();
	DIO_u8Set_Pin_Direction(Group_A,DIO_U8_PIN0,OUTPUT);
	DIO_u8Set_Pin_Direction(Group_A,DIO_U8_PIN1,OUTPUT);
	DIO_u8Set_Pin_Direction(Group_A,DIO_U8_PIN2,OUTPUT);
	while(1)
	{
		UART_Recive_String(a);
         LCD_void_Write_string(a,0,0);
      /*u8 c=UART_Receive();
       *
      UART_Transmit_charc(c);
      if(c=='R')
      {
    	  DIO_u8Set_Pin_Value(Group_A,DIO_U8_PIN0,HIGH);
      }
      else if(c=='y')
      {
    	  DIO_u8Set_Pin_Value(Group_A,DIO_U8_PIN1,HIGH);
      }
      else if(c=='G')
      {
    	  DIO_u8Set_Pin_Value(Group_A,DIO_U8_PIN2,HIGH);
      }
      */
	}
}

