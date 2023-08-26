/*
 * main.c
 *
 *  Created on: May 19, 2023
 *      Author: DELL
 */
#include"bitscalcu.h"
#include"std_types.h"
#include "KEYPAD_Interface.h"
#include"DIO_Interface.h"
#include"LCD_Interface.h"
void main(void)
{ u8 a[16],first_flag=0,second_flag=0; //driving circuit && control circuit for microcontroller
LCD_void_Init_8bits();
KPD_Int();
KPD_void_Get_kpd_status(a); //calculator //second calcaulator when user press +it give answer
	while(1)
	{
	KPD_void_Get_kpd_status(a);
     if(a[0] == 0 && (first_flag==0)){
    	 LCD_void_Write_string("Key 0 Pressed",0,0);
    	first_flag=1;
     }





	}
}
