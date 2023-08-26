/*
 * main.c
 *
 *  Created on: May 12, 2023
 *      Author: DELL
 */
#include"util/delay.h"
#include"bitscalcu.h"
#include"std_types.h"
#include"DIO_Interface.h"
#include"LCD_Interface.h"

void main(void){
	u8 hah2[8]={0,0,0,4,10,1,255,0};
	u8 sin[8]={0,0,0,21,21,21,31,0};
	u8 alf[8]={2,2,2,2,2,2,2,0};
	u8 maiam[8]={0,30,18,8,30,16,16,0};
	LCD_void_Init_8bits();
	//LCD_void_Write_Data('H');
	//LCD_void_Write_Data('o');
	//LCD_void_Write_Cmd(0b10000001);
	//LCD_void_Write_Cmd(0b10001000);
	//LCD_void_Write_Data('H');
	//LCD_void_Write_string("Hossam",0,0);
    //LCD_u32_Write_Number(-70);
	//LCD_void_Write_float_Number(0.7);
	//LCD_void_Write_string("Hossam",0,0);
	//LCD_void_Write_string("Hossam",0,1);


	/* LCD_void_Write_spcharchter(hah2,3,3,0);
	 LCD_void_Write_spcharchter(sin,2,2,0);
	 LCD_void_Write_spcharchter(alf,1,1,0);
	 LCD_void_Write_spcharchter(maiam,0,0,0);
     */
	while(1){

     for(u8 i=0;i<200;i++)
     {
    	 LCD_void_Write_string("hossam_mostafa",i,0);
    	 _delay_ms(500);
    	 LCD_void_clear();
    	 _delay_ms(500);
     }

      }


	}

