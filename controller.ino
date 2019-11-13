#include <ESP8266WebServer.h>
#include <ArduinoJson.h>
#include "led.h"
#include "controller.h"

#define PORT 8080
#define ERR_CODE 400
#define SUC_CODE 200
#define PLAIN "plain"
#define APP_JSON "application/json"

ESP8266WebServer server(PORT);
StaticJsonDocument<150> json;

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

    auto error = deserializeJson(json, server.arg(PLAIN));

    if (error)
    {
        failWith(ERR_CODE, "Cannot parse message.");
        delay(1000);
        return;
    }

    manipulateLed(json["led"], json["value"], json["effect"]);

    char message[] = "OK.";
    succeedWith(message);
}

void validate(byte led)
{
    if (led != 1 && led != 2)
    {
        failWith(ERR_CODE, "You can only choose 1 or 2 for led number");
    }
}

void succeedWith(char message[])
{
    server.send(SUC_CODE, APP_JSON, "{\"message\": \"" + String(message) + "\"}");
}

void failWith(int code, char message[])
{
    server.send(code, APP_JSON, "{\"error\": \"" + String(message) + "\"}");
}
