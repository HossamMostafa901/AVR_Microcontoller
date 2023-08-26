/*
 * Config.h
 *
 *  Created on: May 30, 2023
 *      Author: DELL
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#define LCD_u8_CTRL_PORT Group_A
#define LCD_u8_Rs_PIN DIO_U8_PIN0
#define LCD_u8_Rw_PIN DIO_U8_PIN1
#define LCD_u8_Enable_PIN DIO_U8_PIN2

#define LCD_u8_Data_Port Group_B
#define LCD_u8_Data_PIN_4 DIO_U8_PIN0
#define LCD_u8_Data_PIN_5 DIO_U8_PIN1
#define LCD_u8_Data_PIN_6 DIO_U8_PIN2
#define LCD_u8_Data_PIN_7 DIO_U8_PIN3

//#define Lcd_function_set_line1 0b00100011//0x33
//#define Lcd_function_set_line2 0b00100010//0x32
//#define Lcd_function_set_line3 0b10000010//0x28

#define Lcd_display_line1 0
#define Lcd_display_line2 0b11000000

#define Lcd_display_clear_Line1 0
#define Lcd_display_clear_Line2 0b00010000

#define Lcd_entry_mode_line1 0
#define Lcd_entry_mode_line2 0b1000000

#define LCD_TWO_LINES_FOUR_BITS_MODE         0x28
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   0x32

#endif /* CONFIG_H_ */
