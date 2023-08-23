/*
 * EXIT_Private.h
 *
 *  Created on: Jun 2, 2023
 *      Author: DELL
 */

#ifndef EXIT_PRIVATE_H_
#define EXIT_PRIVATE_H_

#define EXIT_u8_MCUCR  *(( volatile u8*)0x55)
#define EXIT_u8_MCUCSR *(( volatile u8*)0x54)
#define EXIT_u8_GICR   *(( volatile u8*)0x5B)
#define EXIT_u8_SREG   *(( volatile u8*)0x5F)
#define EXIT_u8_GIFR   *(( volatile u8*)0x5A)

void __vector_1(void)__attribute__((signal));
void __vector_2(void)__attribute__((signal));
void __vector_3(void)__attribute__((signal));

#endif /* EXIT_PRIVATE_H_ */
