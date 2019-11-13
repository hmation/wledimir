#pragma once

#include "LedStripAdapter.h"

class Esp8266PinLedStripAdapter : public LedStripAdapter
{
public:
    Esp8266PinLedStripAdapter(byte gpioPin);
    virtual void changeLight(byte value);

private:
    byte _gpioPin;
};