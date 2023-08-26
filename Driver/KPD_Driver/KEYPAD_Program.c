/*
 * KEYPAD_Program.c

 *
 *  Created on: May 19, 2023
 *      Author: DELL
 */
#include"bitscalcu.h"
#include"std_types.h"
#include"KEYPAD_Config.h"
#include "KEYPAD_Interface.h"
#include"DIO_Interface.h"
#include"LCD_Interface.h"
u8 KPD_u8_Col_Pins[KPD_u8_Col_NB]={KPd_u8_Col0,KPd_u8_Col1,KPd_u8_Col2,KPd_u8_Col3};
u8 Kpd_u8_Row_pins[KPD_u8_Row_NB]={KPd_u8_Row0,KPd_u8_Row1,KPd_u8_Row2,KPd_u8_Row3};
void KPD_void_Get_kpd_status(u8 *Copy_pu8_kpd)
{u8 col_index,row_index;
u8 pin_val,Key_index;
#if KPD_u8Activation_Type==KPD_u8_Active_Col
for(col_index=0;col_index<KPD_u8_Col_NB;col_index++)
{
	//DIO_u8Set_Pin_Direction(Col_Group,KPD_u8_Col_Pins[col_index],LOW);
#if KPd_u8Connection_Type==KPD_u8_Pullup
	DIO_u8Set_Pin_Value(Col_Group,KPD_u8_Col_Pins[col_index],LOW);
	for(row_index=0;row_index<KPD_u8_Row_NB;row_index++)
	{
		DIO_u8Get_Pin_Value(Row_Group,Kpd_u8_Row_pins[row_index],&pin_val);
		Key_index=(row_index*4)+col_index;
		Copy_pu8_kpd[Key_index]=pin_val;
	}
	DIO_u8Set_Pin_Value(Col_Group,KPD_u8_Col_Pins[col_index],HIGH);
#endif
}
#endif
}
void KPD_Int(void)
{ u8 col_index,row_index;
#if KPD_u8Activation_Type==KPD_u8_Active_Col
	for(col_index=0;col_index<KPD_u8_Col_NB;col_index++)
	{
		DIO_u8Set_Pin_Direction(Col_Group,KPD_u8_Col_Pins[col_index],OUTPUT);
	}
#if KPd_u8Connection_Type==KPD_u8_Pullup
	for(row_index=0;row_index<KPD_u8_Row_NB;row_index++)
	{
		DIO_u8Set_Pin_Direction(Row_Group,Kpd_u8_Row_pins[row_index],INPUT);
		DIO_u8Set_Pin_Value(Row_Group,Kpd_u8_Row_pins[row_index],HIGH);
	}
#endif

#endif
}


