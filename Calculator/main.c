/*
 * main.c
 *
 *  Created on: May 22, 2023
 *      Author: DELL
 */
#include"bitscalcu.h"
#include"std_types.h"
#include "KEYPAD_Interface.h"
#include"DIO_Interface.h"
#include"LCD_Interface.h"
#include"util/delay.h"

void main(void)
{ LCD_void_Init_8bits();
KPD_Int();
u8 index=66,num=99,a[16],count=0,y=0,i,op=76,f,op_flag=0,s=88,operation_flag=0;
u8 flag=0,true_flag=0,second_flag=0,second_true_flag=0,t=0,total_flag=0,last_flag=0;
s32 total=0,first=0,second=0;
f32 float_total=0;
while(1)
{
	KPD_void_Get_kpd_status(a);
	for(i=0;i<16;i++)
	{
		if(a[i]==0)
		{
			index=i;
			flag=1;

		}
		if(flag==1)
		{
			if(index>=0&&index<=2)//number from 7to 9
			{
				num=index+7;
			}
			else if(index>=4&&index<=6) // number from 4 to 6
			{
				num=index;
			}
			else if(index>=8&&index<=10) //from 1 to 3
			{
				num=index-7;
			}
			else if(index==13)// number 0
				num=0;
			else if(index==3)// '/'
			{   op=1;
			op_flag=0;
			operation_flag=1;
			}
			else if(index==7)//'*'
			{  op=2;
			op_flag=0;
			operation_flag=1;
			}
			else if(index==11)//'-'
			{   op=3;
			op_flag=0;
			operation_flag=1;
			}
			else if(index==15)//'+'
			{   op=4;

			op_flag=0;
			operation_flag=1;
			}
			else if(index==14)/*when user press equal*/
			{   t=1;
				if(op==1)
				{
					if((first%2==0&&second%2==0)||(first%3==0&&second%3==0))
						total=first/second;
					else
					float_total=first/(f32) second;
				}
				else if (op==2)
				{
					total=first*second;
				}
				else if(op==3)
				{
					total=first-second;
				}
				else if(op==4)
				{
					total=first+second;
				}
				else
					total=first;

			}
			if(true_flag==0&&a[i]==0&&second_flag==0 && operation_flag==0&&t==0)//first number
			{    f=num;
				LCD_u32_Write_Number(num,count,y);
				true_flag=1;

				while(a[i]==0)
				{
					KPD_void_Get_kpd_status(a);
				}
				count++;
				first=(first*10)+f;
				true_flag=0;
			}/*when user chose one operation of cacuator*/
			else if(op_flag==0&&a[i]==0&&second_flag==0)
			{
				op_flag=1;
				if(op==1)
				{
					LCD_void_GoTo_postion(count,0);
					LCD_void_Write_Data('/');
				}
				else if(op==2)
				{
					LCD_void_GoTo_postion(count,0);
					LCD_void_Write_Data('*');
				}
				else if(op==3)
				{
					LCD_void_GoTo_postion(count,0);
					LCD_void_Write_Data('-');
				}
				else if(op==4)
				{
					LCD_void_GoTo_postion(count,0);
					LCD_void_Write_Data('+');
				}
				while(a[i]==0)
				{
					KPD_void_Get_kpd_status(a);
				}
				count++;
				second_flag=1;
				operation_flag=0;
				op_flag=0;
			}
			/*second number */
			else if(second_true_flag==0&&a[i]==0&&second_flag==1&&t==0)
			{    s=num;
				LCD_u32_Write_Number(num,count,y);
				second_true_flag=1;
				f=num;
				while(a[i]==0)
				{
					KPD_void_Get_kpd_status(a);
				}
				count++;
				second=(second*10)+s;
				second_true_flag=0;
			}
			else if(t==1 && total_flag==0 && a[i]==0)// finish of operation &prrint
			{    total_flag=1;
				LCD_void_GoTo_postion(count,0);
				LCD_void_Write_Data('=');

				while(a[i]==0)
				{
					KPD_void_Get_kpd_status(a);
				}
				count++;
				if(op!=1)
				LCD_u32_Write_Number(total,count,y);
				else
				{
					if((first%2==0&&second%2==0)||(first%3==0&&second%3==0))
						LCD_u32_Write_Number(total,count,y);
					else
						LCD_void_Write_float_Number(float_total);
				}

                t=0;
                total_flag=0;
                last_flag=1;
			}
		}
       if(last_flag==1)
       {
    	   _delay_ms(500);
    	    LCD_void_clear();
    	    index=66,num=99,count=0,y=0,i,op=76,f,op_flag=0,s=88,operation_flag=0;
    	    flag=0,true_flag=0,second_flag=0,second_true_flag=0,t=0,total_flag=0,last_flag=0;
    	    total=0,first=0,second=0;
       }
	}

}
}

