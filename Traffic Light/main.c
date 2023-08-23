/*
 * main.c
 *
 *  Created on: May 7, 2023
 *      Author: DELL
 */
#include"avr/io.h"
#include"avr/delay.h"
#include"bitscalcu.h"
#include"std_types.h"

void main(void){
DDRA=0xff;
DDRB=0xff;
DDRC=0b00000111;
u8 a[10]={0b11000000,//0    //array for 7 segement common anode
			    0b11111001,//1
	            0b10100100,//2
	            0b10110000,//3
	            0b10011001,//4
				0b10010010,//5
				0b10000010,//6
				0b11111000,//7
				0b10000000,//8
				0b10010000,//9
	             };
u8 red=0,yellow=3,green=0,r=15,y=0,g=15;
	while(1)
{
    while(r>red)//15>0
    {
    	set_bit(PORTC,0);
    		   PORTA=a[r%10];
    		   PORTB=a[r/10];
    		   _delay_ms(1000);
    		   r--;
    }
	 clear_bit(PORTC,0);
	 r=15;
	 while(y<yellow)//0<3
	     {

	     	set_bit(PORTC,1);
	     		   PORTA=a[y];
	     		   PORTB=a[0];
	     		   _delay_ms(1000);
	     		   y++;
	     }
	 clear_bit(PORTC,1);
	 	 y=0;
	 	while(g>green)//15>0
	 	    {
	 	    	set_bit(PORTC,2);
	 	    		   PORTA=a[g%10];
	 	    		   PORTB=a[g/10];
	 	    		   _delay_ms(1000);
	 	    		   g--;
	 	    }
	 	clear_bit(PORTC,2);
	 		 	 g=15;
}



}


