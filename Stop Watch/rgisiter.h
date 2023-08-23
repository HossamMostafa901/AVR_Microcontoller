/*
 * rgisiter.h
 *
 *  Created on: Jun 18, 2023
 *      Author: DELL
 */

#ifndef RGISITER_H_
#define RGISITER_H_

#define Timer_u8_TCCR1A     *((volatile u8 *)0x4F)
#define Timer_u8_TCCR1B     *((volatile u8 *)0x4E)

#define Timer_u8_OCR1AH     *((volatile u8 *)0x4B)
#define Timer_u8_OCR1AL     *((volatile u16 *)0x4A)

#define Timer_u8_OCR1BH     *((volatile u8 *)0x49)
#define Timer_u8_OCR1BL     *((volatile u16 *)0x48)

#define Timer_u8_ICR1H      *((volatile u8 *)0x47)
#define Timer_u8_ICR1L      *((volatile u16 *)0x46)

#define Timer_u8_TCNT1L     *((volatile u16 *)0x4C)
#define Timer_u8_TIMSK    *((volatile u8 *)0x59)

#define DIO_u8_PORTA   *(( volatile u8*)0x3B)
#define DIO_u8_PORTB   *(( volatile u8*)0x38)
#define DIO_u8_PORTC   *(( volatile u8*)0x35)
#define DIO_u8_PORTD   *(( volatile u8*)0x32)

void Reset (void);
void Pause (void);
void Resume (void);

#endif /* RGISITER_H_ */
