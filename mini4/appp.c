/*
 * appp.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Maryam
 */

/*
 * APP.C
 *
 *  Created on: Oct 21, 2023
 *      Author: Maryam
 */


#include "lcd.h"
#include "avr/io.h"
#include "util/delay.h"
#include "Ultrasonic_Sensor.h"

int main()
{
	Ultrasonic_init();
	 LCD_init();

	 LCD_displayString("distance: ");

	 SREG|=(1<<7);

while (1)
{
	LCD_moveCursor(1,11);

	LCD_intgerToString(Ultrasonic_readDistance());
	_delay_ms(500);

}


}

