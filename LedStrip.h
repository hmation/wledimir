#pragma once

#include <Arduino.h>
#include "LedStripAdapter.h"

class LedStrip
{

public:
    LedStrip();
    LedStrip(byte initialValue, LedStripAdapter *adapter);
    
    void manipulate(byte value, String effect);
    void controlLight();

private:
    volatile byte _toBeValue = 0;
    volatile byte _currentValue = 0;
    String _effect = "dim";

    LedStripAdapter *_adapter;
};
