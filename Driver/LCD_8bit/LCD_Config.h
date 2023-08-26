/*
 * Config.h
 *
 *  Created on: May 12, 2023
 *      Author: DELL
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define LCD_u8_CTRL_PORT Group_A
#define LCD_u8_Rs_PIN DIO_U8_PIN0
#define LCD_u8_Rw_PIN DIO_U8_PIN1
#define LCD_u8_Enable_PIN DIO_U8_PIN2


#define LCD_u8_Data_Port  Group_B
#define LCD_u8_Data_PIN_0 DIO_U8_PIN0
#define LCD_u8_Data_PIN_1 DIO_U8_PIN1
#define LCD_u8_Data_PIN_2 DIO_U8_PIN2
#define LCD_u8_Data_PIN_3 DIO_U8_PIN3
#define LCD_u8_Data_PIN_4 DIO_U8_PIN4
#define LCD_u8_Data_PIN_5 DIO_U8_PIN5
#define LCD_u8_Data_PIN_6 DIO_U8_PIN6
#define LCD_u8_Data_PIN_7 DIO_U8_PIN7

#define function_set_8bit 0b00111000
#define display_8bit 0b00001100
#define clear_bit_8bit 0b00000001
#define entry_mode_8bit 0b00000110
/*
 u8 a[8]={LCD_u8_Data_PIN_0};
 * */

#endif /* LCD_CONFIG_H_ */
