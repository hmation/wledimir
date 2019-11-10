#include <ArduinoOTA.h>

void setupOTA()
{
    ArduinoOTA.onStart([]() {
        String type;
        if (ArduinoOTA.getCommand() == U_FLASH)
        {
            type = "sketch";
        }
        else
        { // U_SPIFFS
            type = "filesystem";
        }

        // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
        Serial.println("Start updating " + type);
    });
    ArduinoOTA.onEnd([]() {
        Serial.println("\nEnd");
    });
    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
        Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
    });
    ArduinoOTA.onError([](ota_error_t error) {
        Serial.printf("Err[%u]: ", error);
        if (error == OTA_AUTH_ERROR)
        {
            Serial.println("Auth Fail");
        }
        else if (error == OTA_BEGIN_ERROR)
        {
            Serial.println("Begin Fail");
        }
        else if (error == OTA_CONNECT_ERROR)
        {
            Serial.println("Connect Fail");
        }
        else if (error == OTA_RECEIVE_ERROR)
        {
            Serial.println("Receive Fail");
        }
        else if (error == OTA_END_ERROR)
        {
            Serial.println("End Fail");
        }
    });
    ArduinoOTA.begin();
}

void loopOTA()
{
    ArduinoOTA.handle();
}
