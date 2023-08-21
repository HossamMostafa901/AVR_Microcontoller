/*
 * main.c
 *
 *  Created on: Aug 1, 2023
 *      Author: DELL
 */
#include"bitscalcu.h"
#include"std_types.h"
#include"util/delay.h"
#include"DIO_Interface.h"
#include"LCD_Interface.h"
#include"UART_Interface.h"
#include"Samrthome_Interfce.h"
#include <string.h>

typedef struct
{
	u8 *name;
	u8 *pass;
}data;

data user[Numberofuser];
void main(void)
{                        /*     Inizalation       */
	LCD_Int_4bit(); //LCD iniilza in 4 bit mode
	UART_INT();   //Uart Inizlization for bleuthooth Module
	Servo_Int();  // servo Inizalion using Timer 1

	u8 Reciving[10],recivingchar=0;/*recinving array to recive from Uart& reciving option when system open */
	/* falgs */
	u8 index,wrong_username=1,right_username=0,first=1,count,system_open=0;
	/*Inialize user of system Name and Password*/
	user[0].name="Ahmed";
	user[0].pass="1234";
	user[1].name="Omar";
	user[1].pass="4567";
	user[2].name="Mark";
	user[2].pass="5678";
	/*Inialize user Buzzer&LED*/
	DIO_u8Set_Pin_Direction(Group_B,DIO_U8_PIN0,OUTPUT);//LED
	DIO_u8Set_Pin_Direction(Group_B,DIO_U8_PIN1,OUTPUT);//BUzzer

	LCD_void_clear();

	while(1)
	{

		UART_Recive_String(Reciving);

		for(u8 i=0;i<Numberofuser;i++)
		{first=1;
		if(strcmp(user[i].name,Reciving)==0)
		{
			wrong_username=0;
			index=i;
			right_username=1;
			break;
		}
		}
		if(wrong_username==1&&first==1)
		{
			LCD_void_clear();
			LCD_void_Write_string("wrong username",0,0);
			_delay_ms(1000);
			LCD_void_clear();
			LCD_void_Write_string("Try again",0,0);
			_delay_ms(1000);
			LCD_void_clear();
			first=0;
		}
		if(right_username==1)
		{

			LCD_void_Write_string("Hi ",0,0);
			LCD_void_Write_string(user[index].name,3,0);
			_delay_ms(1000);
			LCD_void_clear();
			LCD_void_Write_string("Plz enter Pass:",0,0);
			right_username=0;
			for(count=1;count<4;count++)
			{
				UART_Recive_String(Reciving);
				if(strcmp(user[index].pass,Reciving)==0)
				{
					count=1;
					LCD_void_clear();
					system_open=1;
					break;

				}
				else
				{

					LCD_void_clear();
					LCD_void_Write_string("Try again",0,0);
					_delay_ms(500);
					LCD_void_clear();

				}

			}
			if(count>3&&system_open==0)
			{ LCD_void_clear();
			DIO_u8Set_Pin_Value(Group_B,DIO_U8_PIN1,HIGH);
			LCD_void_Write_string("system locked",0,0);
			_delay_ms(1000);
			DIO_u8Set_Pin_Value(Group_B,DIO_U8_PIN1,LOW);
			LCD_void_clear();
			count=0;
			}
			while(system_open==1)
			{
				LCD_void_Write_string("welcome to Home",0,0);
				LCD_void_Write_string("plz choose choice",0,1);
				_delay_ms(750);
				LCD_void_clear();
				LCD_void_Write_string("1-ledon",0,0);
				LCD_void_Write_string("2-ledof",7,0);
				LCD_void_Write_string("3-Ex",12,0);
				LCD_void_Write_string("4-doorop",0,1);
				LCD_void_Write_string("5-doorcl",8,1);
				recivingchar=UART_Receive();
				;
				if(recivingchar>='1'&&recivingchar<='5')
				{
					if(recivingchar=='1')
					{
						LightON();
					}
					else if(recivingchar=='2')
					{
						LightOFF();
					}
					else if(recivingchar=='3')
					{
						LCD_void_clear();
						system_open=0;
					}
					else if(recivingchar=='4')
					{
						Door_OPened();
					}
					else if(recivingchar=='5')
					{
						Door_CLosed();
					}
				}
				else
				{
					LCD_void_clear();
					LCD_void_Write_string("wrong choice",0,0);
					_delay_ms(750);
				}


			}
		}
	}
}
