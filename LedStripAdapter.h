#pragma once

#include <Arduino.h>

class LedStripAdapter
{
public:
    virtual void changeLight(byte value) = 0;
};
