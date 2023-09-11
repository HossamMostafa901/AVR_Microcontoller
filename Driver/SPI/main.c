/*
 * main.c
 *
 *  Created on: Jun 17, 2023
 *      Author: DELL
 */
#include"util/delay.h"
#include"bitscalcu.h"
#include"std_types.h"
#include"DIO_Interface.h"
#include"SPI_Interface.h"

void main(void)
{
	// slave
	/* clk=t/p,Miso,o/p,MOsi=I/p,ss:I/p*/
	//master
	/*clk =op,Miso,I/p,Mosi,O/p,ss:xx*/
	DIO_u8Set_Pin_Direction(Group_B,DIO_U8_PIN7,OUTPUT);
	DIO_u8Set_Pin_Direction(Group_B,DIO_U8_PIN6,INPUT);
	DIO_u8Set_Pin_Direction(Group_B,DIO_U8_PIN5,OUTPUT);
	DIO_u8Set_Pin_Direction(Group_B,DIO_U8_PIN4,OUTPUT);
	SPI_Master_INIT();
	while(1)
	{
		u8 chr;
     chr=  SPI_Transfer('M');
       /*if I were salve i cmake spi slave init smse transfer (s)*/
	}
}
