/*
 * Smarthome_program.c
 *
 *  Created on: Aug 1, 2023
 *      Author: DELL
 */

#include"bitscalcu.h"
#include"std_types.h"
#include"util/delay.h"
#include"Timer_1_Private.h"
#include"DIO_Interface.h"
#include"LCD_Interface.h"
#include"UART_Interface.h"
#include"Samrthome_Interfce.h"
#include <string.h>



void Servo_Int(void)
{
	/****************           Timer_int***************************          */
	DIO_u8Set_Pin_Direction(Group_D,DIO_U8_PIN5,OUTPUT);
	Timer_u8_TCCR1A=Timer1_iNTA;//prescale/8 timer1 mode 14->fastpwm/clear oncompare ,set ontop
	Timer_u8_TCCR1B=Timer1_iNTB;
	Timer_u8_ICR1L=Periodic_time;
	Timer_u8_OCR1AL=MOTOR_CLOSED;//door Closed motor vertical
}
void Door_OPened(void)
{
	Timer_u8_OCR1AL=MOTOR_OPENED;//Motor Horzinatal door opened
}
void Door_CLosed(void)
{
	Timer_u8_OCR1AL=MOTOR_CLOSED;//door Closed motor vertical
}
void LightON(void)
{
	DIO_u8Set_Pin_Value(Group_B,DIO_U8_PIN0,HIGH);//light on
}
void LightOFF(void)
{
	DIO_u8Set_Pin_Value(Group_B,DIO_U8_PIN0,LOW);//light of
}
