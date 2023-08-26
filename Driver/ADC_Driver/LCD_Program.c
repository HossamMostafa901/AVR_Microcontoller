/*
 * Program.c
 *
 *  Created on: May 12, 2023
 *      Author: DELL
 */

#include"bitscalcu.h"
#include"std_types.h"
#include"util/delay.h"
#include"DIO_Interface.h"
#include"LCD_Config.h"
#include"LCD_Private.h"
#include"LCD_Interface.h"

void LCD_void_Init_8bits(void)
{
	DIO_u8Set_Pin_Direction(LCD_u8_CTRL_PORT,LCD_u8_Rs_PIN,OUTPUT);//CHANGE TO DIO_U8_OUTPUT
	DIO_u8Set_Pin_Direction(LCD_u8_CTRL_PORT,LCD_u8_Rw_PIN,OUTPUT);
	DIO_u8Set_Pin_Direction(LCD_u8_CTRL_PORT,LCD_u8_Enable_PIN,OUTPUT);
	DIO_u8Set_Port_Direction(LCD_u8_Data_Port,PORTOUTPUT);
	_delay_ms(40);
	LCD_void_Write_Cmd(function_set_8bit);//function_set
	_delay_us(50);
	LCD_void_Write_Cmd(display_8bit);//display_on/of
	_delay_us(50);
	LCD_void_Write_Cmd(clear_bit_8bit);//clear_display
	_delay_ms(2);
	LCD_void_Write_Cmd(entry_mode_8bit);//entry_mode
}
void LCD_void_Write_Cmd(u8 Copy_u8_Cmd)
{
	DIO_u8Set_Pin_Value(LCD_u8_CTRL_PORT,LCD_u8_Rs_PIN,LOW);
	LCD_void_Write(Copy_u8_Cmd);
}
void LCD_void_Write_Data(u8 Copy_u8_Data)
{
	DIO_u8Set_Pin_Value(LCD_u8_CTRL_PORT,LCD_u8_Rs_PIN,HIGH);
	LCD_void_Write(Copy_u8_Data);
}
void LCD_void_Write(u8 Copy_u8_Value)
{
	DIO_u8Set_Pin_Value(LCD_u8_CTRL_PORT,LCD_u8_Rw_PIN,LOW);
	DIO_u8Set_Pin_Value(LCD_u8_Data_Port,LCD_u8_Data_PIN_0,get_bit(Copy_u8_Value,0));
	DIO_u8Set_Pin_Value(LCD_u8_Data_Port,LCD_u8_Data_PIN_1,get_bit(Copy_u8_Value,1));
	DIO_u8Set_Pin_Value(LCD_u8_Data_Port,LCD_u8_Data_PIN_2,get_bit(Copy_u8_Value,2));
	DIO_u8Set_Pin_Value(LCD_u8_Data_Port,LCD_u8_Data_PIN_3,get_bit(Copy_u8_Value,3));
	DIO_u8Set_Pin_Value(LCD_u8_Data_Port,LCD_u8_Data_PIN_4,get_bit(Copy_u8_Value,4));
	DIO_u8Set_Pin_Value(LCD_u8_Data_Port,LCD_u8_Data_PIN_5,get_bit(Copy_u8_Value,5));
	DIO_u8Set_Pin_Value(LCD_u8_Data_Port,LCD_u8_Data_PIN_6,get_bit(Copy_u8_Value,6));
	DIO_u8Set_Pin_Value(LCD_u8_Data_Port,LCD_u8_Data_PIN_7,get_bit(Copy_u8_Value,7));
	/*or for(u8 i=0;i<8;i++)
	 * u8 a[8];
	 * DIO_u8Set_Pin_Value(LCD_u8_Data_Port,a[i],get_bit(Copy_u8_Value,i));
	 */
	DIO_u8Set_Pin_Value(LCD_u8_CTRL_PORT,LCD_u8_Enable_PIN,HIGH);
	_delay_ms(1);
	DIO_u8Set_Pin_Value(LCD_u8_CTRL_PORT,LCD_u8_Enable_PIN,LOW);
}
void LCD_void_Write_string(u8* copy_Pu8_Data,u8 copy_u8_xpos,u8 copy_u8_ypos)
{// user x or y wrong

	if((copy_u8_xpos>=0&&copy_u8_xpos<=15)&&(copy_u8_ypos==0||copy_u8_ypos==1))
	{
		u8 local_u8_DDRAM_Address;
		u8 Local_u8CURNT_POS = copy_u8_xpos;
		u8 i=0;
		local_u8_DDRAM_Address=copy_u8_xpos+(copy_u8_ypos*64);
		local_u8_DDRAM_Address|=0b10000000;
		LCD_void_Write_Cmd(local_u8_DDRAM_Address);
		                    // if line finshed 1 or 2
		while(*copy_Pu8_Data !='\0')
		{
			LCD_void_Write_Data(*copy_Pu8_Data);
			*copy_Pu8_Data++;
			Local_u8CURNT_POS++;
			if(Local_u8CURNT_POS>=16)
			{


				LCD_void_GoTo_postion(i,LCD_Secondline);
				i++;
				if(i>15)
				{
					i=0;
					LCD_void_GoTo_postion(i,LCD_Firstline);
				}
			}
		}
	}
	else
	{
		LCD_void_GoTo_postion(0,0);
	}


}
void LCD_u32_Write_Number(s32 copy_u32_Num,u8 copy_u8_xpos,u8 copy_u8_ypos)// add postion of x postion of y
{
	u8 rem,i=0,str[20],negtive_flag=0;
	if(copy_u32_Num==0)//if number is zero
	{
		str[i]='0';
		i++;
	}
	else if(copy_u32_Num<0)
	{
		negtive_flag=1;
		copy_u32_Num=copy_u32_Num*-1;
	}

	while(copy_u32_Num!=0)
	{
		rem=copy_u32_Num%10;
		str[i]=rem+'0';
		i++;
		copy_u32_Num=copy_u32_Num/10;
	}
	if(negtive_flag==1)
	{
		str[i]='-';
		i++;
	}
	str[i]='\0';
	Reverse(str,i);

	LCD_void_Write_string(str,copy_u8_xpos,copy_u8_ypos);
}
void LCD_void_clear(void)
{
	LCD_void_Write_Cmd(clear_bit_8bit);
}
void Reverse(u8 *str,u8 size)
{
	for(u8 i=0;i<((size)/2);i++)
	{
		u8 temp=str[i];
		str[i]=str[size-i-1];
		str[size-1-i]=temp;
	}
	 /*u8 start=0,*ptr; //another method for reverse
		                                u8 end =size-1;
		                                while(start<end){
		                                swap(&ptr[start],&ptr[end])
		                                 start++;
		                                 end--;
		                                }

		                                */
}
void LCD_void_Write_float_Number(f32 copy_float_number)
{
	u32 num1;
	u8 str[10],rem1,rem2,i=0,zero_flag=1;
	num1=copy_float_number;
	if(num1==0)
	{
		str[i]='0';
		i++;
		zero_flag=0;
	}
	while(num1!=0)
	{
		rem1=num1%10;
		str[i]=rem1+'0';
		i++;
		num1/=10;
	}
	if(zero_flag==1)
	{
		Reverse(str,i);
	}

	str[i]='.';
	i++;
	num1=copy_float_number*10;
	rem2=num1%10;
	str[i]=rem2+'0';
	i++;
	num1=copy_float_number*100;
	rem2=num1%10;
	str[i]=rem2+'0';
	i++;

	LCD_void_Write_string(str,0,0);
}
void LCD_void_GoTo_postion(u8 copy_u8_xPos, u8 copy_u8_yPos)
{
	u8 local_u8_DDRAM_Address;
			local_u8_DDRAM_Address=copy_u8_xPos+(copy_u8_yPos*64);
			local_u8_DDRAM_Address|=0b10000000;
			LCD_void_Write_Cmd(local_u8_DDRAM_Address);
}
void LCD_void_Write_spcharchter(u8* copy_Pu8_spcharc,u8 pattern,u8 copy_u8_xPos, u8 copy_u8_yPos)
{
	u8 local_u8_zeroaddress=pattern*(8);
	(local_u8_zeroaddress)|=0b01000000;
	LCD_void_Write_Cmd(local_u8_zeroaddress);
	for(u8 i=0;i<8;i++)
	{
		LCD_void_Write_Data(copy_Pu8_spcharc[i]);
	}
	LCD_void_GoTo_postion( copy_u8_xPos,  copy_u8_yPos);
	LCD_void_Write_Data(pattern);
}
