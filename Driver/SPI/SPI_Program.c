/*
 * SPI_Program.c
 *
 *  Created on: Jun 17, 2023
 *      Author: DELL
 */
#include"util/delay.h"
#include"bitscalcu.h"
#include"std_types.h"
#include"DIO_Interface.h"
#include"SPI_Private.h"
#include"SPI_Interface.h"

void SPI_Master_INIT(void)
{
   SPI_SPCR=0b01010001;
   /* spi inteurpt disable,spi
   enable,
   MSB_First,
   Master_mode
   ,cpol=0,
   cpha=0,
   prescale=clk/16*/
}
void SPI_Slave_INIT(void)
{
	 SPI_SPCR=0b01000000;/*SPI INterupt Disable,
	 spi enable
	 msb first
	 slave mode
	 cpol=0,cpha=0,prescale=dontcare*/
}
u8 SPI_Transfer(u8 Data)
{
	SPI_SPDR=Data ;
	while(get_bit(SPI_SPSR,7)==0);//check for transmisinon complete
	return SPI_SPDR;
}
