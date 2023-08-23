/*
 * Timer_0_Private.h
 *
 *  Created on: Jun 10, 2023
 *      Author: DELL
 */

#ifndef TIMER_0_PRIVATE_H_
#define TIMER_0_PRIVATE_H_

#define Timer_u8_TCCRO    *((volatile u8 *)0x53)
#define Timer_u8_TCNTO    *((volatile u8 *)0x52)
#define Timer_u8_TIMSK    *((volatile u8 *)0x59)
#define Timer_u8_SREG     *((volatile u8 *)0x5F)
#define Timer_u8_OCRO     *((volatile u8 *)0x5C)

#endif /* TIMER_0_PRIVATE_H_ */
