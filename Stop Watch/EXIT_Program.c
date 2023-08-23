/*
 * EXIT_Program.c
 *
 *  Created on: Jun 2, 2023
 *      Author: DELL
 */
#include"bitscalcu.h"
#include"std_types.h"
#include"EXIT_Private.h"
#include"EXIT_Config.h"
#include"EXIT_Interface.h"

void(*AvoidCallBack[3])(void);//call back function

void __vector_1(void){
	if(AvoidCallBack[0] != Null ){
		AvoidCallBack[0]();
	}
}

void __vector_2(void){
	if(AvoidCallBack[1] != Null ){
		AvoidCallBack[1]();
	}
}

void __vector_3(void){
	if(AvoidCallBack[2] != Null ){
		AvoidCallBack[2]();
	}
}

void EXIT_voidGlobal_En_Dis(u8 Copy_u8_En_Dis)
{
	switch(Copy_u8_En_Dis)
	{
	case EXIT_u8_Global_Dis:clear_bit(EXIT_u8_SREG,EXIT_u8Global_INT_Bit);   break;
	case EXIT_u8_Global_En:set_bit(EXIT_u8_SREG,EXIT_u8Global_INT_Bit)   ;   break;
	}
}
void EXIT_void_EN_Dis(u8 Copy_u8_INT_Index,u8 Copy_u8En_Dis)
{
	switch(Copy_u8_INT_Index)
	{
	case EXit_u8INT_0: assign_bit(EXIT_u8_GICR,EXIT_u8Global_PER_En_Dis_0,Copy_u8En_Dis);break;
	case EXit_u8INT_1: assign_bit(EXIT_u8_GICR,EXIT_u8Global_PER_En_Dis_1,Copy_u8En_Dis);break;
	case EXit_u8INT_2: assign_bit(EXIT_u8_GICR,EXIT_u8Global_PER_En_Dis_2,Copy_u8En_Dis);break;
	}
}
void EXIT_void_Set_Level(u8 Copy_u8INT_Index,u8 Copy_u8INT_Level)
{
	switch(Copy_u8INT_Index)
	{
	case EXit_u8INT_0:assign_bit(EXIT_u8_MCUCR,0,get_bit(Copy_u8INT_Level,0));
	                  assign_bit(EXIT_u8_MCUCR,1,get_bit(Copy_u8INT_Level,1));
	                               break;
	case EXit_u8INT_1:assign_bit(EXIT_u8_MCUCR,2,get_bit(Copy_u8INT_Level,2));
	                  assign_bit(EXIT_u8_MCUCR,3,get_bit(Copy_u8INT_Level,3));
	                               break;
	case EXit_u8INT_2:assign_bit(EXIT_u8_MCUCSR,6,Copy_u8INT_Level);break;
	}
}
void EXIT_voidSet_CallBack(u8 Copy_u8INT_Index,void (*pvoid_callBack)( void))
{
   AvoidCallBack[Copy_u8INT_Index]=pvoid_callBack;
}
