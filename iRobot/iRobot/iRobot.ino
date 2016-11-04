/*
 Name:		iRobot.ino
 Created:	10/31/2016 11:20:48 AM
 Author:	bcakid
*/
#include "Sensor.h"


// Gadgets
Sensor s;

void setup() 
{
	Serial.begin(9600);

	s.attach(11, 13);
}

void loop() 
{
	float distance = s.getDistance();
	Serial.println(distance);
	delay(100);
}
