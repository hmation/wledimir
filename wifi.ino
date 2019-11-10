#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <DNSServer.h>
#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager

void setupWiFi()
{
    WiFiManager wifiManager;
    wifiManager.autoConnect();
}
