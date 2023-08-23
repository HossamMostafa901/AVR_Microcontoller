/*
 * main.c
 *
 *  Created on: Jun 25, 2023
 *      Author: DELL
 */
#include"bitscalcu.h"
#include"std_types.h"
#include"util/delay.h"
#include"Timer_0_Private.h"
#include"DIO_Interface.h"
#include"LCD_Interface.h"
#include"ADC_Interface.h"

void main(void)
{
	u8 t1=0,t2=0,t3=0,t4=0,t5=0;
	u16 digital,prev_value;
	f32 anlog,temp;
	/************************ Timer_0_Initial*******************/
	Timer_u8_TCCRO=0b01101010;/* overflow tim=256*tick_time tick_time =prescale/freq
	 *prescale=clk/8
	 *set oco on compare
	 *clear Top
	 */
	Timer_u8_OCRO=0;
	ADC_voidInit();// function for adc initizaltion
	DIO_u8Set_Pin_Direction(Group_B,DIO_U8_PIN3,OUTPUT);
	DIO_u8Set_Pin_Direction(Group_A,DIO_U8_PIN0,INPUT);
	LCD_void_Init_8bits();//function for lcd initial

	DIO_u8Set_Pin_Direction(Group_B,DIO_U8_PIN0,OUTPUT);
	DIO_u8Set_Pin_Direction(Group_B,DIO_U8_PIN1,OUTPUT);
	DIO_u8Set_Pin_Value(Group_B,DIO_U8_PIN0,HIGH);
	DIO_u8Set_Pin_Value(Group_B,DIO_U8_PIN1,LOW);
	while(1)
	{
		digital=ADC_u8Read_sync_ch(ADC_Channel_0);
		anlog=(digital*5.0)/1023;// to get anlog value by cross multplication
		anlog*=1000;
		temp=(anlog/10.0);
		if(temp<30)
		{
			Timer_u8_OCRO=0;

			if(prev_value!=digital)
			{
				LCD_void_clear();
				prev_value=digital;
				LCD_void_Write_string("fan is off",4,0);
				LCD_void_Write_string("temp =",4,1);
				LCD_u32_Write_Number(temp,9,1);
			}
			_delay_ms(5);
		}
		else if(temp>=30&&temp<60)
		{
			Timer_u8_OCRO=64;// duty cycle 25% overflow time*0.25
			if(prev_value!=digital)
			{
				LCD_void_clear();
				prev_value=digital;
				LCD_void_Write_string("fan is ON",4,0);
				LCD_void_Write_string("temp =",4,1);
				LCD_u32_Write_Number(temp,9,1);
			}
			_delay_ms(5);
		}
		else if(temp>=60&&temp<90)
		{
			Timer_u8_OCRO=128;// duty cycle 50% overflow time*0.5
			if(prev_value!=digital)
			{
				LCD_void_clear();
				prev_value=digital;
				LCD_void_Write_string("fan is ON",4,0);
				LCD_void_Write_string("temp =",4,1);
				LCD_u32_Write_Number(temp,9,1);
			}
			_delay_ms(5);
		}

		else if(temp>=90&&temp<125)
		{
			Timer_u8_OCRO=192;// duty cycle 75% overflow time*0.75
			if(prev_value!=digital)
			{
				LCD_void_clear();
				prev_value=digital;
				LCD_void_Write_string("fan is ON",4,0);
				LCD_void_Write_string("temp =",4,1);
				LCD_u32_Write_Number(temp,9,1);
			}
			_delay_ms(5);
		}
		else if(temp<=125)
				{
					Timer_u8_OCRO=254;// duty cycle 100% overflow time*1
					if(prev_value!=digital)
					{
						LCD_void_clear();
						prev_value=digital;
						LCD_void_Write_string("fan is ON",4,0);
						LCD_void_Write_string("temp =",4,1);
						LCD_u32_Write_Number(temp,9,1);
					}
					_delay_ms(5);
				}
	}
}
