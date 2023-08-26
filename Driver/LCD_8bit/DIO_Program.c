/*
 * DIO_Program.c
 *
 *  Created on: May 6, 2023
 *      Author: DELL
 */
#include"bitscalcu.h"
#include"std_types.h"
#include"DIO_Private.h"
#include"DIO_Config.h"
#include"DIO_Interface.h"

u8 DIO_u8Set_Pin_Value(u8 Copy_u8_Port_ID,u8 Copy_u8_Pin_ID,u8 Copy_u8_Pin_Val)
{
	if((Copy_u8_Pin_ID)>= DIO_U8_PIN0 && (Copy_u8_Pin_ID)<= DIO_U8_PIN7)
	{
		if((Copy_u8_Pin_Val)==HIGH || (Copy_u8_Pin_Val)==LOW)
		{
			switch(Copy_u8_Port_ID){

			case Group_A:assign_bit(DIO_u8_PORTA,Copy_u8_Pin_ID,Copy_u8_Pin_Val);break;
			case Group_B:assign_bit(DIO_u8_PORTB,Copy_u8_Pin_ID,Copy_u8_Pin_Val);break;
			case Group_C:assign_bit(DIO_u8_PORTC,Copy_u8_Pin_ID,Copy_u8_Pin_Val);break;
			case Group_D:assign_bit(DIO_u8_PORTD,Copy_u8_Pin_ID,Copy_u8_Pin_Val);break;

			}
		}
		else
		{
			return INVALID_PIN_VALUE;
		}

	}
	else
	{
		return INVALID_PIN_ID;
	}
	return(0);
}

u8 DIO_u8Set_Pin_Direction(u8 Copy_u8_Port_ID,u8 Copy_u8_Pin_ID,u8 Copy_u8_Pin_Val)
{
	if((Copy_u8_Pin_ID)>= DIO_U8_PIN0 && (Copy_u8_Pin_ID)<= DIO_U8_PIN7)
	{
		if((Copy_u8_Pin_Val)==HIGH || (Copy_u8_Pin_Val)==LOW)
		{
			switch(Copy_u8_Port_ID){

			case Group_A:assign_bit(DIO_u8_DDRA,Copy_u8_Pin_ID,Copy_u8_Pin_Val);break;
			case Group_B:assign_bit(DIO_u8_DDRB,Copy_u8_Pin_ID,Copy_u8_Pin_Val);break;
			case Group_C:assign_bit(DIO_u8_DDRC,Copy_u8_Pin_ID,Copy_u8_Pin_Val);break;
			case Group_D:assign_bit(DIO_u8_DDRD,Copy_u8_Pin_ID,Copy_u8_Pin_Val);break;

			}
		}
		else
		{
			return INVALID_PIN_VALUE;
		}

	}
	else
	{
		return INVALID_PIN_ID;
	}
	return(0);
}
u8 DIO_u8Get_Pin_Value(u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_ID,u8*Copy_Pu8_val)
{

if((Copy_u8_Pin_ID)>= DIO_U8_PIN0 && (Copy_u8_Pin_ID)<= DIO_U8_PIN7)
{
	switch(Copy_u8_Port_ID){

	case Group_A: *Copy_Pu8_val=get_bit(DIO_u8_PINA,Copy_u8_Pin_ID);break;
	case Group_B: *Copy_Pu8_val=get_bit(DIO_u8_PINB,Copy_u8_Pin_ID);break;
	case Group_C: *Copy_Pu8_val=get_bit(DIO_u8_PINC,Copy_u8_Pin_ID);break;
	case Group_D: *Copy_Pu8_val=get_bit(DIO_u8_PIND,Copy_u8_Pin_ID);break;
	}
}
else
{
	return INVALID_PIN_ID;
}

return 0;
}



void DIO_u8Set_Port_Value(u8 Copy_u8_Port_ID,u8 u8Port_Value)
{
	switch(Copy_u8_Port_ID){

	case Group_A: DIO_u8_PORTA = u8Port_Value ;break;
	case Group_B: DIO_u8_PORTB = u8Port_Value ;break;
	case Group_C: DIO_u8_PORTC = u8Port_Value ;break;
	case Group_D: DIO_u8_PORTD = u8Port_Value ;break;

	}
}
void DIO_u8Set_Port_Direction(u8 Copy_u8_Port_ID,u8 u8Port_Direction)
{
	switch(Copy_u8_Port_ID){

	case Group_A: DIO_u8_DDRA = u8Port_Direction ;break;
	case Group_B: DIO_u8_DDRB = u8Port_Direction ;break;
	case Group_C: DIO_u8_DDRC = u8Port_Direction ;break;
	case Group_D: DIO_u8_DDRD = u8Port_Direction ;break;

	}
}
u8 DIO_u8Get_Port_Value(u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_ID,u8*Copy_Pu8_val)
{
	if((Copy_u8_Pin_ID)>= DIO_U8_PIN0 && (Copy_u8_Pin_ID)<= DIO_U8_PIN7)
	{
		switch(Copy_u8_Port_ID){

		case Group_A: *Copy_Pu8_val=DIO_u8_PINA;break;
		case Group_B: *Copy_Pu8_val=DIO_u8_PINB;break;
		case Group_C: *Copy_Pu8_val=DIO_u8_PINC;break;
		case Group_D: *Copy_Pu8_val=DIO_u8_PIND;break;
		}
	}
	else
	{
		return INVALID_PIN_ID;
	}
 return 0;
}
