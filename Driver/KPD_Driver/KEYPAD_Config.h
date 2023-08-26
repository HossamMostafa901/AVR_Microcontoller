/*
 * KEYPAD_Config.h
 *
 *  Created on: May 19, 2023
 *      Author: DELL
 */

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define KPD_u8_Active_Col 0
#define KPD_u8_Active_Row 1
#define KPD_u8_Col_NB 4
#define KPD_u8_Row_NB 4
#define KPD_u8_Pullup 0

#define KPD_u8Activation_Type KPD_u8_Active_Col
#define KPd_u8Connection_Type KPD_u8_Pullup
#define Col_Group Group_D
#define Row_Group Group_C

#define KPd_u8_Col0 DIO_U8_PIN0
#define KPd_u8_Col1 DIO_U8_PIN1
#define KPd_u8_Col2 DIO_U8_PIN2
#define KPd_u8_Col3 DIO_U8_PIN3

#define KPd_u8_Row0 DIO_U8_PIN0
#define KPd_u8_Row1 DIO_U8_PIN1
#define KPd_u8_Row2 DIO_U8_PIN2
#define KPd_u8_Row3 DIO_U8_PIN3

#endif /* KEYPAD_CONFIG_H_ */
