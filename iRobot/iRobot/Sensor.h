#include "arduino.h"

// Ultrasonic sensor HC-SR04
class Sensor
{

public:
	void attach(int trigPin, int echoPin)
	{
		_trigPin = trigPin;
		_echoPin = echoPin;

		pinMode(trigPin, OUTPUT);
		pinMode(_echoPin, INPUT);

		digitalWrite(trigPin, LOW); 
		delay(2); 
	}

	float getDistance()
	{
		digitalWrite(_trigPin, HIGH); 
		delayMicroseconds(15); 
		digitalWrite(_trigPin, LOW);
		delayMicroseconds(10); 

		float pingTime = pulseIn(_echoPin, HIGH);
		float lenInInch = mcSec2in(pingTime);
		return in2cm(lenInInch);
	}

private:
	int _trigPin;
	int _echoPin;

	float speedOfSound = 776.5; // ml/h

	float mcSec2in(float pingTime)
	{
		pingTime = pingTime / 1000000;				//pingTime is in microseconds. Convert to seconds
		pingTime = pingTime / 3600;					//seconds to hours

		float targetDistance = speedOfSound * pingTime;   //distance in miles
		targetDistance = targetDistance / 2;			  //distance covered twice
		targetDistance = targetDistance * 63360;		  //distance in inches (63360 inches per mile)

		return targetDistance;
	}

	float in2cm(float in)
	{
		return in * 2.54;
	}
};

