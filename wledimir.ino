void setup()
{
    // put your setup code here, to run once:
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
