/*
 * icu.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Maryam
 */

#ifndef ICU_H_
#define ICU_H_

#include "std_types.h"

typedef enum {
	FALLING_EDGE,RISING_EDGE
} Edge_Select;

typedef enum
{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}ICU_ClockType;

typedef struct {
	ICU_ClockType  CLOCK ;
	Edge_Select EDGE  ;

} ICU_ConfigType ;
void ICU_init(const ICU_ConfigType * Config_Ptr);
void ICU_setCallBack(void(*a_ptr)(void));
void ICU_clearTimerValue(void);
void ICU_setEdgeDetectionType(const Edge_Select EDGE);
uint16 ICU_getInputCaptureValue(void);
void ICU_deInit(void);
#endif /* ICU_H_ */
