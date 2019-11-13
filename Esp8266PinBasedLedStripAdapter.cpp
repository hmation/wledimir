#include "Arduino.h"
#include "Esp8266PinBasedLedStripAdapter.h"

Esp8266PinLedStripAdapter::Esp8266PinLedStripAdapter(byte gpioPin)
{
    _gpioPin = gpioPin;
    pinMode(gpioPin, OUTPUT);
    analogWrite(_gpioPin, 0);
}

void Esp8266PinLedStripAdapter::changeLight(byte value)
{
    analogWrite(_gpioPin, value * 10);
};