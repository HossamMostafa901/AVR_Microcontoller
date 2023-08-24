/*
 * main.c
 *
 *  Created on: May 6, 2023
 *      Author: DELL
 */
#include"util/delay.h"
#include"bitscalcu.h"
#include"std_types.h"
#include"DIO_Interface.h"

void main(void)
{ //HIGHBRIDGE USING TRANSISTOR //optocoupler pc817
	/*DIO_u8Set_Pin_Direction(Group_A, DIO_U8_PIN0, OUTPUT);
	DIO_u8Set_Pin_Direction(Group_A, DIO_U8_PIN1, OUTPUT);
	while(1)
	{
		DIO_u8Set_Pin_Value(Group_A,DIO_U8_PIN0, HIGH);
		DIO_u8Set_Pin_Value(Group_A,DIO_U8_PIN1, LOW);
		_delay_ms(1000);
		DIO_u8Set_Pin_Value(Group_A,DIO_U8_PIN0, LOW);
		DIO_u8Set_Pin_Value(Group_A,DIO_U8_PIN1, LOW);
		_delay_ms(1000);
		DIO_u8Set_Pin_Value(Group_A,DIO_U8_PIN0, LOW);
		DIO_u8Set_Pin_Value(Group_A,DIO_U8_PIN1, HIGH);
	}
	*/
	while(1)
	{

	}
}

