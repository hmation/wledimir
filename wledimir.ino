#include <Arduino.h>
#include "controller.h"
#include "wifi.h"
#include "ota.h"
#include "led.h"

void setup()
{
    Serial.begin(115200);

    setupLed();
    setupWiFi();
    setupOTA();
    setupWebServer();
}

void loop()
{
    loopOTA();
    loopWebServer();
    loopLed();
}
