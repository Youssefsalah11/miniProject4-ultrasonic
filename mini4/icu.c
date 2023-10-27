/*
 * icu.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Maryam
 */


#include "gpio.h"
#include "icu.h"
#include "avr/io.h"
#include "avr/interrupt.h"
#include "common_macros.h"

static volatile void(*a_ptr1)(void)=NULL_PTR;

ISR(TIMER1_CAPT_vect)
{
	if(a_ptr1!=NULL_PTR)
		a_ptr1();
}

void ICU_init(const ICU_ConfigType * Config_Ptr){

	CLEAR_BIT(DDRD,PIN6_ID);

	TCCR1A =(1<<FOC1A) | (1<< FOC1B);

	TCCR1B=(TCCR1B&0xbf)|(Config_Ptr->EDGE<<ICES1);

	TCCR1B=(TCCR1B&0xf8)|(Config_Ptr->CLOCK);

	ICR1=0;    TCNT1=0;

    SET_BIT(TIMSK,TICIE1);

}

void ICU_setCallBack(void(*a_ptr)(void))
{
	a_ptr1=a_ptr;
}
void ICU_setEdgeDetectionType(const Edge_Select EDGE){

	TCCR1B=(TCCR1B&0xbf)|(EDGE<<ICES1);
}
uint16 ICU_getInputCaptureValue(void)
{
	 return ICR1;
}
void ICU_clearTimerValue(void)
{
	TCNT1=0;
}
void ICU_deInit(void)
{
	  CLEAR_BIT(TIMSK,TICIE1);
}
