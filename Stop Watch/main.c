/*
 * main.c
 *
 *  Created on: Jun 18, 2023
 *      Author: DELL
 */
#include"bitscalcu.h"
#include"std_types.h"
#include"util/delay.h"
#include"rgisiter.h"
#include"DIO_Interface.h"
#include"EXIT_Interface.h"

u8 seconds;
u8 min;
u8 hour;
/*inturept compare match of Timer 1 every 1 sec */
void __vector_7(void)__attribute__((signal));
void __vector_7(void)
{
	seconds++ ;
	if(seconds==60)
	{
		min++;
		seconds=0;
	}
	if(min==60)
	{
		hour++;
		min=0;
		seconds=0;
	}
	if(hour==12)
	{
		hour=0;
		min=0;
		seconds=0;
	}
}

void Reset (void)
{
	seconds=0,min=0,hour=0;
}

void Pause (void)
{  /* to pause timer clear pre scale*/
	clear_bit(Timer_u8_TCCR1B,0);
	clear_bit(Timer_u8_TCCR1B,1);
	clear_bit(Timer_u8_TCCR1B,2);
}

void Resume (void)
{   /* to resume retuen prescale int0 1024*/
	set_bit(Timer_u8_TCCR1B,0);
	clear_bit(Timer_u8_TCCR1B,1);
	set_bit(Timer_u8_TCCR1B,2);
}

void main()
{
	/*make Port C&Port A output*/
	DIO_u8Set_Port_Direction(Group_A,PORTOUTPUT);
	DIO_u8Set_Port_Direction(Group_C,PORTOUTPUT);
	/*direction for interupt and make them input pull up*/
	DIO_u8Set_Pin_Direction(Group_B,DIO_U8_PIN0,INPUT);
	DIO_u8Set_Pin_Direction(Group_D,DIO_U8_PIN2,INPUT);
	DIO_u8Set_Pin_Direction(Group_D,DIO_U8_PIN3,INPUT);

	DIO_u8Set_Pin_Value(Group_B,DIO_U8_PIN0,HIGH);
	DIO_u8Set_Pin_Value(Group_D,DIO_U8_PIN2,HIGH);
	DIO_u8Set_Pin_Value(Group_D,DIO_U8_PIN3,HIGH);
	/*************************************************************************************/
	/* Make Timer 1 INIT */
	/* make initial value =0*/
	Timer_u8_TCNT1L=0;
	/* control regisiter of Timer 1  */
	Timer_u8_TCCR1A=0b00001000;//force on compare A
	/* compare match 0 non pwm mode
		    forc A&B 0
		    mode 4 ctc */
	Timer_u8_TCCR1B=0b00001101;
	/*
	 * no input cpture & noise cancel
	 * mode for 4 ctc mode
	 * prescale 1024
	 *
	 */
	Timer_u8_OCR1AL=1000;
	/*
	 * system frq=1Mhz
	 * tick_time=Prescale/systemfreq=1ms
	 * ocr=1sec/1ms=1000;
	 * */

	/*enable compare match intruput*/
	set_bit(Timer_u8_TIMSK,4);
	/*************************************************************************************/
	/* External Intruput*/

	/*level sensing ofthree  inturpurts*/
	EXIT_void_Set_Level(EXit_u8INT_0,INT0_FallingEdge);
	EXIT_void_Set_Level(EXit_u8INT_1,INT1_FallingEdge);
	EXIT_void_Set_Level(EXit_u8INT_2,INT2_FallingEdge);
	/*make call pack function*/
	EXIT_voidSet_CallBack(EXit_u8INT_0,Pause);
	EXIT_voidSet_CallBack(EXit_u8INT_1,Resume);
	EXIT_voidSet_CallBack(EXit_u8INT_2,Reset);
	/* enble global inturpet*/
	EXIT_voidGlobal_En_Dis(EXIT_u8_Global_En);
	/* enable three inturpet*/
	EXIT_void_EN_Dis(EXit_u8INT_0,Enable);
	EXIT_void_EN_Dis(EXit_u8INT_1,Enable);
	EXIT_void_EN_Dis(EXit_u8INT_2,Enable);
	while(1)
	{
		/*7 segment display*/
		DIO_u8_PORTA=(1<<0);
		DIO_u8_PORTC=seconds%10;
		_delay_ms(4);
		DIO_u8_PORTA=(1<<1);
		DIO_u8_PORTC=seconds/10;
		_delay_ms(4);
		DIO_u8_PORTA=(1<<2);
		DIO_u8_PORTC=min%10;
		_delay_ms(4);
		DIO_u8_PORTA=(1<<3);
		DIO_u8_PORTC=min/10;
		_delay_ms(4);
		DIO_u8_PORTA=(1<<4);
		DIO_u8_PORTC=hour%10;
		_delay_ms(4);
		DIO_u8_PORTA=(1<<5);
		DIO_u8_PORTC=hour/10;
		_delay_ms(4);
	}
}
