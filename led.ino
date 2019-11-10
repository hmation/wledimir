#define led1 0
#define led2 2
#define DELAY 10

volatile int led1_toBeValue = 0;
volatile int led1_currentValue = 0;
volatile int led2_toBeValue = 0;
volatile int led2_currentValue = 0;

void setupLed()
{
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);

    analogWrite(led1, 0);
    analogWrite(led2, 0);
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
        analogWrite(led1, led1_currentValue);
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
        analogWrite(led2, led2_currentValue); // analogWrite values from 0 to 255
    }

    delay(delayMs);
}

// value might be from 0 to 100
// led might be eiter 1 or 2
void manipulateLed(int led, byte value, String effect)
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
