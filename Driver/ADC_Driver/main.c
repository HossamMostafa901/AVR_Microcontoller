/*
  * main.c
 *
 *  Created on: Jun 3, 2023
 *      Author: DELL
 */
// SAR ADC :successive Approximation fixed time valdaite evry bit time fixed
// sampling freq>=2*signal freq (Nyquest_rate)
#include"bitscalcu.h"
#include"std_types.h"
#include"avr/delay.h"
#include"DIO_Interface.h"
#include"LCD_Interface.h"
#include"ADC_Interface.h"


void main()
{ ADC_voidInit();
LCD_void_Init_8bits();
DIO_u8Set_Pin_Direction(Group_A,DIO_U8_PIN0,INPUT);
DIO_u8Set_Pin_Direction(Group_C,DIO_U8_PIN0,OUTPUT);
DIO_u8Set_Pin_Direction(Group_C,DIO_U8_PIN1,OUTPUT);
DIO_u8Set_Pin_Direction(Group_C,DIO_U8_PIN2,OUTPUT);
u16 digital,prev_value,aanlog;
f32 anlog,temp;
while(1)
{
	digital= ADC_u8Read_sync_ch(ADC_Channel_0);
	//aanlog=(digital*5000.0)/1024.0;
	if(prev_value!=digital)
	{
		 LCD_void_clear();
    	  prev_value=digital;
    	 LCD_u32_Write_Number(digital,0,0);
	}

}
}
/* anlog=(digital*5.0)/1024;
   	  anlog*=1000;
   	  temp=(anlog/10.0);
   	  LCD_u32_Write_Number(temp,0,0);
   	  _delay_ms(10);
		 */

	//}
   /*if(aanlog>=0&&aanlog<=1500)
   {
   	DIO_u8Set_Pin_Value(Group_C,DIO_U8_PIN0,HIGH);
   	DIO_u8Set_Pin_Value(Group_C,DIO_U8_PIN1,LOW);
   	DIO_u8Set_Pin_Value(Group_C,DIO_U8_PIN2,LOW);
   }
   else if(aanlog>=1501&&aanlog<=2000)
   {
   	DIO_u8Set_Pin_Value(Group_C,DIO_U8_PIN0,LOW);
   	DIO_u8Set_Pin_Value(Group_C,DIO_U8_PIN1,HIGH);
   	DIO_u8Set_Pin_Value(Group_C,DIO_U8_PIN2,LOW);
   }
   else
   {
   	DIO_u8Set_Pin_Value(Group_C,DIO_U8_PIN0,LOW);
   	DIO_u8Set_Pin_Value(Group_C,DIO_U8_PIN1,LOW);
   	DIO_u8Set_Pin_Value(Group_C,DIO_U8_PIN2,HIGH);
   }


	//LCD_void_Write_float_Number(anlog);


	//LCD_void_Write_float_Number(temp);
*/
