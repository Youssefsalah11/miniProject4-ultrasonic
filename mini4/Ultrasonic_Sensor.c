/*
 * Ultrasonic_Sensor.C
 *
 *  Created on: Oct 21, 2023
 *      Author: Maryam
 */

#include "Ultrasonic_Sensor.h"

#include "util/delay.h"
#include "gpio.h"
#include "icu.h"

#include "std_types.h"


uint16 high_time=0;
uint8 counter =0;


void Ultrasonic_init(void){
	ICU_ConfigType configICU;

	configICU.CLOCK=F_CPU_8;

	configICU.EDGE=RISING_EDGE;

	ICU_init(&configICU);
	ICU_setCallBack(ultrasonic_edge);
	GPIO_setupPinDirection(PORTB_ID,PIN5_ID,PIN_OUTPUT);
}

void ultrasonic_edge(void)
{
	counter++;
	if(counter==1)
	{
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(FALLING_EDGE);
	}
	else if(counter==2)
	{
		high_time=ICU_getInputCaptureValue();
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(RISING_EDGE);
	}


}


void Ultrasonic_Trigger(void){

	GPIO_writePin(PORTB_ID,PIN5_ID,LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(PORTB_ID,PIN5_ID,LOGIC_LOW);
}

uint16 Ultrasonic_readDistance(void){
	 Ultrasonic_Trigger();

	 while (counter!=2);

	 counter=0;

	return (float64)17000*((float64)high_time/(1000000));
}
