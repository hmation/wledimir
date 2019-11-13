#include <Arduino.h>
#include "LedStrip.h"
#include "LedStripAdapter.h"
#include "Esp8266PinBasedLedStripAdapter.h"

#define LED_1_GPIO 0
#define LED_2_GPIO 2

#define DELAY 5

LedStrip ledStrip1;
LedStrip ledStrip2;

void setupLed()
{
    ledStrip1 = LedStrip((byte)0, new Esp8266PinLedStripAdapter(LED_1_GPIO));
    ledStrip2 = LedStrip((byte)0, new Esp8266PinLedStripAdapter(LED_2_GPIO));
}

void loopLed()
{
    ledStrip1.controlLight();
    ledStrip2.controlLight();

    delay(DELAY);
}

void manipulateLed(byte led, byte value, String effect)
{
    if (led == 1)
    {
        ledStrip1.manipulate(value, effect);
    }

    if (led == 2)
    {
        ledStrip2.manipulate(value, effect);
    }
}
