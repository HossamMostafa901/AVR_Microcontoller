/*
 * main.c
 *
 *  Created on: May 30, 2023
 *      Author: DELL
 */
#include"util/delay.h"
#include"bitscalcu.h"
#include"std_types.h"
#include"DIO_Interface.h"
#include"Interface.h"

void main(void)
{  LCD_Int_4bit();
LCD_Write_Data_4bit('H');
LCD_Write_Data_4bit('o');

	while(1)
	{

	}
}

