/*
 * Interface.h
 *
 *  Created on: May 12, 2023
 *      Author: DELL
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define LCD_Firstline 0
#define LCD_Secondline 1

void LCD_void_Init_8bits(void);
void LCD_void_Write_Cmd(u8 Copy_u8_Cmd);
void LCD_void_Write_Data(u8 Copy_u8_Data);
void LCD_void_Write(u8 Copy_u8_Value);
void LCD_void_Write_string(u8* copy_Pu8_Data,u8 copy_u8_xpos,u8 copy_u8_ypos);
void LCD_u32_Write_Number(s32 copy_u32_Num);
void LCD_void_Write_spcharchter(u8* copy_Pu8_spcharc,u8 pattern,u8 copy_u8_xPos, u8 copy_u8_yPos);

void LCD_void_GoTo_postion(u8 copy_u8_xPos, u8 copy_u8_yPos);
void LCD_void_clear(void);
void Reverse(u8 *str,u8 size);
void LCD_void_Write_float_Number(f32 copy_float_number);
#endif /* LCD_INTERFACE_H_ */
