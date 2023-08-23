/*
 * ADC_Private.h
 *
 *  Created on: Jun 3, 2023
 *      Author: DELL
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADC_u8_ADMUX       *(( volatile u8*)0x27)// MUILTIPLEXER SELECTION REGISTER
#define ADMUX_REFS1	7							// REFERENCE SELECTION BIT1
#define ADMUX_REFS0	6							// REFERENCE SELECTION BIT0
#define ADMUX_ADLAR	5							// ADC LEFT-ADJUST RESULT

#define ADC_u8_ADCSRA      *(( volatile u8*)0x26)// ADC CONTROL & STATUS REGISTER

#define ADCSRA_ADEN	    7							// ADC ENABLE
#define ADCSRA_ADSC	    6                 		  	// ADC START CONVERSION
#define ADCSRA_ADATE	5                   	// ADC AUTO TRIGGER ENABLE
#define ADCSRA_ADIF	    4                   		// ADC INTERRUPT FLAG
#define ADCSRA_ADIE	    3                   		// ADC INTERRUPT ENABLE
#define ADCSRA_ADPS2	2                   	// ADC PRESCALER SELECT BIT2 /* CLOCK SELECTION */
#define ADCSRA_ADPS1	1                   	// ADC PRESCALER SELECT BIT1
#define ADCSRA_ADPS0	0                   	// ADC PRESCALER SELECT BIT0

#define ADC_u8_ADCL        *(( volatile u8*)0x24)// ADC LOW REGISTER
#define ADC_u8_ADCH        *(( volatile u8*)0x25)// ADC HIGH REGISTER

#define ADC_u8_SFIOR       *(( volatile u8*)0x50)// ADC AUTO TRIGGER FLAG

#define DIV_2  	1
#define DIV_4  	2
#define DIV_8  	3
#define DIV_16 	4
#define DIV_32 	5
#define DIV_64 	6
#define	DIV_128	7

#define AUTO_TRIGGER_ENABLE		1
#define AUTO_TRIGGER_DISABLE	2

#define ADC_EVENT_ON_INTERRUPT	1
#define ADC_EVENT_ON_POLLING	2

/* ADC AUTO TRIGGER SOURCE */
#define ADTS_FREE_RUNNING_MODE					0
#define ADTS_ANALOG_COMPARATOR					1
#define ADTS_EXTI0								2
#define ADTS_TIMER_COUNTER0_COMPARE_MATCH		3
#define ADTS_TIMER_COUNTER0_OVERFLOW			4
#define ADTS_TIMER_COUNTER_COMPARE_MATCH_B		5
#define ADTS_TIMER_COUNTER1_OVERFLOW			6
#define ADTS_TIMER_COUNTER1_CAPTURE_EVENT		7

#define ADC_PRESCALER_MASK	0b11111000
#define ADC_MUX_MASK		0b11100000
#define ADC_AUTO_TRIG_MASK 	0b00011111
#define NULL ((void*)0)

#define ADC_IDLE	0
#define ADC_BUSY	1

#define ADC				*((volatile u16*) 0x24)	// ADCH & ADCL

#define ADC_SingleChannel_Asyc 0
#define ADC_ChainAsyc 1

#endif /* ADC_PRIVATE_H_ */
