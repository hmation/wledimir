#include "LedStrip.h"

LedStrip::LedStrip() : LedStrip::LedStrip(0, NULL)
{
}

LedStrip::LedStrip(byte initialValue, LedStripAdapter *adapter)
{
    _adapter = adapter;
    _currentValue = initialValue;
}

void LedStrip::manipulate(byte value, String effect)
{
    _toBeValue = value;
    _effect = effect;
}

void LedStrip::controlLight()
{
    if (_currentValue != _toBeValue)
    {
        _currentValue = _toBeValue > _currentValue ? _currentValue + 1 : _currentValue - 1;
        _adapter->changeLight(_currentValue);
    }
}
