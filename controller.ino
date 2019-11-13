#include <ESP8266WebServer.h>
#include <ArduinoJson.h>
#include "led.h"
#include "controller.h"
#include "RestPayloadValidator.h"

#define PORT 8080
#define ERR_CODE 400
#define SUC_CODE 200
#define PLAIN "plain"
#define APP_JSON "application/json"

#define JSON_LED "led"
#define JSON_VALUE "value"
#define JSON_EFFECT "effect"

ESP8266WebServer server(PORT);
StaticJsonDocument<150> json;
RestPayloadValidator payloadValidator = RestPayloadValidator();

void setupWebServer()
{
    server.on("/", handleRoot);
    server.on("/led", handlePost);
    server.onNotFound(handleNotFound);
    server.begin();
}

void loopWebServer()
{
    server.handleClient();
}

void handleRoot()
{
    server.send(SUC_CODE, APP_JSON, "{\"app\": \"Wledimir\"}");
}

void handleNotFound()
{
    failWith(ERR_CODE + 4, "Not found.");
}

/**jsonMessage
 * Sample JSON payload
 * 
 * {
 *  "led": 1,
 *  "value": 100,
 *  "effect": dim 
 * }
 * 
 */
void handlePost()
{
    if (server.hasArg(PLAIN) == false)
    {
        failWith(ERR_CODE, "Body not received.");
        return;
    }

    RestPayloadValidationResult validationResult = payloadValidator.validate(json, deserializeJson(json, server.arg(PLAIN)));

    if (validationResult.faulty)
    {
        failWith(validationResult.httpErrorCode, validationResult.message);
        delay(1000);
        return;
    }
    else
    {
        manipulateLed(json[JSON_LED], json[JSON_VALUE], json[JSON_EFFECT]);
        succeedWith(validationResult.message);
    }
}

boolean validate(byte led, int value)
{
    boolean retVal = true;
    if (led != 1 && led != 2)
    {
        failWith(ERR_CODE, "The led number has to be either 1 or 2.");
        retVal = false;
    }
    if (value < 0 || value > 100)
    {
        failWith(ERR_CODE, "The value has to be in range <0,100>.");
        retVal = false;
    }
    return retVal;
}

void succeedWith(String message)
{
    server.send(SUC_CODE, APP_JSON, "{\"message\": \"" + message + "\"}");
}

void failWith(int code, String message)
{
    server.send(code, APP_JSON, "{\"error\": \"" + message + "\"}");
}
