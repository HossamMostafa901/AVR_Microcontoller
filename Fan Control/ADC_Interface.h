/*
 * ADC_Interface.h
 *
 *  Created on: Jun 3, 2023
 *      Author: DELL
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

typedef struct
{
	u8 * Channel;
	u16 * Result;
	u8 Length;
	void(*NotifictionFunc)(void);
}chain_t;

void ADC_voidInit(void);
u16 ADC_u8Read_sync_ch(u8 channel);
u16 ADC_u8Read_Async_ch(u8 channel, u16* Copy_pu8Reading, void (*Copy_pvNotificationFunc)(void));
u16 ADC_u8Startchain_Async(chain_t * Copy_chain);

#define ADC_bit_0 0
#define ADC_bit_1 1
#define ADC_bit_2 2
#define ADC_bit_3 3
#define ADC_bit_4 4
#define ADC_bit_5 5
#define ADC_bit_6 6
#define ADC_bit_7 7

#define ADC_Channel_0 0
#define ADC_Channel_1 1
#define ADC_Channel_2 2
#define ADC_Channel_3 3
#define ADC_Channel_4 4
#define ADC_Channel_5 5
#define ADC_Channel_6 6
#define ADC_Channel_7 7

#define RESOLUTION_10BITS	1024
#define RESOLUTION_8BITS	256



#endif /* ADC_INTERFACE_H_ */
