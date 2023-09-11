/*
 * DIO_Interface.h
 *
 *  Created on: May 6, 2023
 *      Author: DELL
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define Group_A 0
#define Group_B 1
#define Group_C 2
#define Group_D 3

#define HIGH   1
#define LOW    0

#define INPUT  0
#define OUTPUT 1

#define PORTOUTPUT 0xff
#define PORTINPUT  0

#define INVALID_PIN_ID 1
#define INVALID_PIN_VALUE 2

#define DIO_U8_PIN0   0
#define DIO_U8_PIN1   1
#define DIO_U8_PIN2   2
#define DIO_U8_PIN3   3
#define DIO_U8_PIN4   4
#define DIO_U8_PIN5   5
#define DIO_U8_PIN6   6
#define DIO_U8_PIN7   7


u8 DIO_u8Set_Pin_Value(u8 Copy_u8_Port_ID,u8 Copy_u8_Pin_ID,u8 Copy_u8_Pin_Val);
u8 DIO_u8Set_Pin_Direction(u8 Copy_u8_Port_ID,u8 Copy_u8_Pin_ID,u8 Copy_u8_Pin_Val);
u8 DIO_u8Get_Pin_Value(u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_ID,u8*Copy_Pu8_val);
void DIO_u8Set_Port_Value(u8 Copy_u8_Port_ID,u8 u8Port_Value);
void DIO_u8Set_Port_Direction(u8 Copy_u8_Port_ID,u8 u8Port_Direction);
u8 DIO_u8Get_Port_Value(u8 Copy_u8_Port_ID, u8 Copy_u8_Pin_ID,u8*Copy_Pu8_val);

#endif /* DIO_INTERFACE_H_ */
