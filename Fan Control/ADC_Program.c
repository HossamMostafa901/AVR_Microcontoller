/*
 * ADC_Program.c
 *
 *  Created on: Jun 3, 2023
 *      Author: DELL
 */
#include"bitscalcu.h"
#include"std_types.h"
#include"ADC_Private.h"
#include"ADC_Config.h"
#include"ADC_Interface.h"

static void (*ADC_pvCallBackNotificationFile)(void)= NULL;
static u16* ADC_pu16Reading = NULL;
u8 ADC_u8BusyState = ADC_IDLE;

static u8 *ADC_pu8ChainChannelArr=NULL;  /*Global array to carry channel*/
static u8 ADC_ChainLenght;              /*Global variable to carry size of channel*/
static u16 * ADC_ChainResultArr=NULL;  /*Global array to carry channel Result*/
static u8 ADC_ChainConvIndex=0;       /*Global variable to carry current conversion*/

static ADC_ISRSource;

void ADC_voidInit(void)
{
	//adc enable
	set_bit(ADC_u8_ADCSRA,ADCSRA_ADEN);

	/* AUTO TRIGGER MODE OR SINGLE CONVERSION MODE */
#if ADC_AUTO_TRIGGER == AUTO_TRIGGER_ENABLE
	/* AUTO TRIGGER ENABLE (ADATE) */
	SET_BIT(ADC_u8_ADCSRA, ADCSRA_ADATE);
	/* MASK on Channel before Start conversion */
	ADC_u8ADMUX &= ADC_MUX_MASK;
	ADC_u8ADMUX |= AUTO_TRIGGER_CHANNEL;
	/* Setting Auto Trigger Source */
	ADC_u8_SFIOR  &= ADC_AUTO_TRIG_MASK;
	ADC_u8_SFIOR  |= ADC_AUTO_TRIGGER_SOURCE;
#elif ADC_AUTO_TRIGGER == AUTO_TRIGGER_DISABLE
	clear_bit(ADC_u8_ADCSRA, ADCSRA_ADATE);
#elif
#error "Wrong ADC_AUTO_TRIGGER CONFIG OPTION"
#endif
	//prescales 128
	ADC_u8_ADCSRA &=ADC_PRESCALER_MASK;	// Clear first 3bits b0 -> b2
	ADC_u8_ADCSRA |=ADC_PRESCALER_SELECTION;	// Set New Value (Divide by 128) or

	//set diffrence voltage
	clear_bit(ADC_u8_ADMUX,ADMUX_REFS1);
	set_bit(ADC_u8_ADMUX,ADMUX_REFS0);
	//left adjustment
	set_bit(ADC_u8_ADMUX,ADMUX_ADLAR);// if i want right adjust i shoud clear bit we use it mostly when we need 10 bit reslouation
}
u16 ADC_u8Read_sync_ch(u8 channel)
{
	u32 Loc_Counter=0;
	u16 res;
	/* BIT MASK First 5 bits b0 -> b4 */
	ADC_u8_ADMUX &=ADC_MUX_MASK;
	/* Set the required channel into the MUX bits */
	ADC_u8_ADMUX |=channel;
	//start conversion
	set_bit(ADC_u8_ADCSRA,ADCSRA_ADSC);

	/* POLLING -busy waiting- till the conversion complete flag is set or Counter Reaching Timeout value */
	while((get_bit(ADC_u8_ADCSRA,ADCSRA_ADIF)!=1)&&(Loc_Counter != ADC_u32TIMEOUT));
	{
		Loc_Counter++;
	}
	if( Loc_Counter == ADC_u32TIMEOUT )
	{
		/* Loop broken  timeout is reached */
		return TIMEOUT_ERROR;
	}
	else
	{
		/*Clear the ADC interrupt flag */
		set_bit(ADC_u8_ADCSRA,ADCSRA_ADIF);
	}
#if ADC_RESOLUTION == RESOLUTION_10BITS
	/* shift right bit 0 and 1 to bit bit6 & bit 7 */
	res=ADC_u8_ADCL>>6;
	/* shift left by 2 to take from d2 to d10*/
	res|=((u16) ADC_u8_ADCH<<(2));
	// there anther way by making pointer u16 that has same address of ADCL_u8_Low
#elif ADC_RESOLUTION == RESOLUTION_8BITS
	/* because in left adjust we need to take most signfint bit because error will be small*/
	res=ADC_u8_ADCH;
#endif
	return res;
}
u16 ADC_u8Read_Async_ch(u8 channel, u16* Copy_pu8Reading, void (*Copy_pvNotificationFunc)(void))
{

	u8 Loc_ErrorState=0;
	if( ADC_u8BusyState == ADC_IDLE )
	{
		if( ( Copy_pu8Reading == NULL ) || ( Copy_pvNotificationFunc == NULL) ){
			Loc_ErrorState = NULL_POINTER;
		}else
		{
			/* FLAG ADC as busy in order to make function off till ADC state is IDLE */
			ADC_u8BusyState = ADC_BUSY;

			/*MAke Isr Source Sigle conversion*/
			ADC_ISRSource=ADC_SingleChannel_Asyc;

			/* Initialise the global Reading variable */
			ADC_pu16Reading = Copy_pu8Reading;

			/* Initialise the global callback notification function */
			ADC_pvCallBackNotificationFile = Copy_pvNotificationFunc;
			/* BIT MASK First 5 bits b0 -> b4 */
			ADC_u8_ADMUX  &= ADC_MUX_MASK;
			/* Set the required channel into the MUX bits */
			ADC_u8_ADMUX |= channel;
			/* Start Conversion */
			set_bit(ADC_u8_ADCSRA, ADCSRA_ADSC);
			/* Enable ADC INTERRUPT */
			set_bit(ADC_u8_ADCSRA, ADCSRA_ADIE);
		}
	}else
	{
		Loc_ErrorState = BUSY_FUNC;
	}
	return Loc_ErrorState;
}
u16 ADC_u8Startchain_Async(chain_t * Copy_chain)
{
	u8 Loc_ErrorState=0;
	/* Check NULL Pointer*/
	if( Copy_chain ==NULL)
	{
		Loc_ErrorState = NULL_POINTER;
	}
	else
	{
		if( ADC_u8BusyState == ADC_IDLE)
		{
			/*Make ADC Busy*/
			ADC_u8BusyState = ADC_BUSY;
			/*make Isr source chain*/
			ADC_ISRSource=ADC_ChainAsyc;
			/*Initialize Chain*/
			ADC_pu8ChainChannelArr=Copy_chain->Channel;
			/*Initialize Chain result*/
			ADC_ChainResultArr=Copy_chain->Result;
			/*Initialize Chain Size*/
			ADC_ChainLenght=Copy_chain->Length;
			/*Initialize Chain callpack notification function*/
			ADC_pvCallBackNotificationFile=Copy_chain->NotifictionFunc;
			/*Initialize current Convesion index */
			ADC_ChainConvIndex=0;
			/* BIT MASK First 5 bits b0 -> b4 */
			ADC_u8_ADMUX  &= ADC_MUX_MASK;
			/* Set the required first channel into the MUX bits */
			ADC_u8_ADMUX |=ADC_pu8ChainChannelArr[ADC_ChainConvIndex];
			/* Start Conversion */
			set_bit(ADC_u8_ADCSRA, ADCSRA_ADSC);
			/* Enable ADC INTERRUPT */
			set_bit(ADC_u8_ADCSRA, ADCSRA_ADIE);
		}
		else
		{
			Loc_ErrorState = BUSY_FUNC;
		}
	}

	return Loc_ErrorState;
}

void __vector_16(void) __attribute__((signal));
void __vector_16(void){
	if(ADC_ISRSource==ADC_SingleChannel_Asyc)
	{
		/* Read ADC Result */
#if ADC_RESOLUTION == RESOLUTION_8BITS
		*ADC_pu16Reading = ADC_u8_ADCH;
#elif ADC_RESOLUTION == RESOLUTION_10BITS
		*ADC_pu16Reading = ADC;
#endif
		/* SET ADC State -> IDLE */
		ADC_u8BusyState = ADC_IDLE;
		/* Invoke the CallBack Notification Function */
		ADC_pvCallBackNotificationFile();

		/* Disable ADC Conversion Complete Interrupt */
		clear_bit(ADC_u8_ADCSRA, ADCSRA_ADIE);
		/*return estate */
		ADC_ISRSource=0;
	}
	else if(ADC_ISRSource==ADC_ChainAsyc)
	{
		/* Read ADC Last Result */
#if ADC_RESOLUTION == RESOLUTION_8BITS
		*ADC_ChainResultArr_= ADC_u8_ADCH;
#elif ADC_RESOLUTION == RESOLUTION_10BITS
		*ADC_ChainResultArr = ADC;
#endif
		/* Increment chain index */
		ADC_ChainConvIndex++;
		/* To check if I finished or not*/
		if(ADC_ChainConvIndex==ADC_ChainLenght )
		{
			/* SET ADC State -> IDLE */
			ADC_u8BusyState=ADC_IDLE;
			/* Invoke the CallBack Notification Function */
			ADC_pvCallBackNotificationFile();
			/* Disable ADC Conversion Complete Interrupt */
			clear_bit(ADC_u8_ADCSRA, ADCSRA_ADIE);
			/*return estate */
					ADC_ISRSource=0;
		}
		else
		{
			/* Chain is not finished*/
			/* BIT MASK First 5 bits b0 -> b4 */
			ADC_u8_ADMUX  &= ADC_MUX_MASK;
			/* Set the required first channel into the MUX bits */
			ADC_u8_ADMUX |=ADC_pu8ChainChannelArr[ADC_ChainConvIndex];
			/* Start Conversion */
			set_bit(ADC_u8_ADCSRA, ADCSRA_ADSC);

		}
	}
}
