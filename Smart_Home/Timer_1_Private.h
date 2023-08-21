/*
 * Timer_1_Private.h
 *
 *  Created on: Jun 10, 2023
 *      Author: DELL
 */

#ifndef TIMER_1_PRIVATE_H_
#define TIMER_1_PRIVATE_H_

#define Timer_u8_TCCR1A     *((volatile u8 *)0x4F)
#define Timer_u8_TCCR1B     *((volatile u8 *)0x4E)

#define Timer_u8_SREG       *((volatile u8 *)0x5F)

#define Timer_u8_OCR1AH     *((volatile u8 *)0x4B)
#define Timer_u8_OCR1AL     *((volatile u16 *)0x4A)

#define Timer_u8_OCR1BH     *((volatile u8 *)0x49)
#define Timer_u8_OCR1BL     *((volatile u16 *)0x48)

#define Timer_u8_ICR1H      *((volatile u8 *)0x47)
#define Timer_u8_ICR1L      *((volatile u16 *)0x46)

#endif /* TIMER_1_PRIVATE_H_ */
