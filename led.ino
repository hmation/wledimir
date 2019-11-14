#include <Arduino.h>

#define LED_1_GPIO 0
#define LED_2_GPIO 2
#define DELAY 3

volatile int led1_toBeValue = 0;
volatile int led1_currentValue = 0;
volatile int led2_toBeValue = 0;
volatile int led2_currentValue = 0;

void setupLed()
{
    pinMode(LED_1_GPIO, OUTPUT);
    pinMode(LED_2_GPIO, OUTPUT);

    analogWrite(LED_1_GPIO, 0);
    analogWrite(LED_2_GPIO, 0);
}

void loopLed()
{
    byte delayMs = 0;

    if (led1_currentValue != led1_toBeValue)
    {
        if (led1_toBeValue > led1_currentValue)
        { // more light
            led1_currentValue = led1_currentValue + 1;
        }
        else
        { // less light
            led1_currentValue = led1_currentValue - 1;
        }
        delayMs = DELAY;
        analogWrite(LED_1_GPIO, led1_currentValue);
    }

    if (led2_currentValue != led2_toBeValue)
    {
        if (led2_toBeValue > led2_currentValue)
        { // more light
            led2_currentValue = led2_currentValue + 1;
        }
        else
        { // less light
            led2_currentValue = led2_currentValue - 1;
        }
        delayMs = DELAY;
        analogWrite(LED_2_GPIO, led2_currentValue);
    }

    delay(delayMs);
}

// value might be from 0 to 100
// led might be eiter 1 or 2
void manipulateLed(byte led, byte value, String effect)
{
    if (led == 1)
    {
        led1_toBeValue = value * 10;
    }

    if (led == 2)
    {
        led2_toBeValue = value * 10;
    }
    return;
}
