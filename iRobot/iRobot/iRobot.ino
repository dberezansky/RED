/*
 Name:		iRobot.ino
 Created:	10/31/2016 11:20:48 AM
 Author:	bcakid
*/
#include "LED.h"
#include "Sensor.h"


// Gadgets
Sensor sensor;
Led led;

void setup() 
{
	Serial.begin(9600);

	sensor.attach(10, 11);
	led.attach(13);
}

void loop() 
{
	float distance = sensor.getDistance();
	Serial.println(distance);

	if (distance < 25 && distance != 0)
		led.fastBlink();
	else if (distance < 50)
		led.slowBlink();

	delay(100);
}
