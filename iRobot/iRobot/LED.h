#include "arduino.h"

class Led {

	private:

		int _pin;

		void blink(int offTime, int onTime) {
			turnOn();
			delay(onTime);

			turnOff();
			delay(offTime);
		}

		void turnOff() {
			digitalWrite(_pin, LOW);
		}

		void turnOn() {
			digitalWrite(_pin, HIGH);
		}

	public:
		void attach(int pin) {
			_pin = pin;
			pinMode(_pin, OUTPUT);

		}

		void slowBlink() {
			blink(200, 600);
		}

		void fastBlink() {
			blink(200, 200);
		}
};