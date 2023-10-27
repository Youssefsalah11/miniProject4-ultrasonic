/*
 * Ultrasonic_Sensor.H
 *
 *  Created on: Oct 21, 2023
 *      Author: Maryam
 */

#ifndef ULTRASONIC_SENSOR_H_
#define ULTRASONIC_SENSOR_H_

#include "std_types.h"



void ultrasonic_edge(void);
void Ultrasonic_init(void);
void Ultrasonic_Trigger(void);
uint16 Ultrasonic_readDistance(void);

#endif /* ULTRASONIC_SENSOR_H_ */
