/*
 * EXIT_Interface.h
 *
 *  Created on: Jun 2, 2023
 *      Author: DELL
 */

#ifndef EXIT_INTERFACE_H_
#define EXIT_INTERFACE_H_

#define EXIT_u8_Global_En 1
#define EXIT_u8_Global_Dis 0
#define Enable 1
#define disable 0

#define INT2_FallingEdge 0
#define INT2_RisingEdge  1

#define INT1_FallingEdge 0b10
#define INT1_RisingEdge  0b11
#define INT1_LowLevel  0b00
#define INT1_Ioc 0b01

#define INT0_FallingEdge 0b10
#define INT0_RisingEdge  0b11
#define INT0_LowLevel  0b00
#define INT0_Ioc 0b01

#define EXIT_u8Global_INT_Bit 7

#define EXit_u8INT_0 0
#define EXit_u8INT_1 1
#define EXit_u8INT_2 2

#define EXIT_u8Global_PER_En_Dis_0 6
#define EXIT_u8Global_PER_En_Dis_1 7
#define EXIT_u8Global_PER_En_Dis_2 5

#define Null ((void*)0)

void EXIT_void_Set_Level(u8 Copy_u8INT_Index,u8 Copy_u8INT_Level);
void EXIT_voidGlobal_En_Dis(u8 Copy_u8_En_Dis);
void EXIT_void_EN_Dis(u8 Copy_u8_INT_Index,u8 Copy_u8En_Dis);
#endif /* EXIT_INTERFACE_H_ */
