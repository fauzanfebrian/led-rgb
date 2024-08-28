#include <Arduino.h>
#include <ESP8266WiFi.h>

IPAddress setupWifi() {
  const char *ssid = WIFI_SSID;
  const char *password = WIFI_PASSWORD;

  IPAddress localIP(192, 168, 1, 5);
  IPAddress gateway(192, 168, 1, 1);
  IPAddress subnet(255, 255, 0, 0);
  IPAddress primaryDNS(8, 8, 8, 8);
  IPAddress secondaryDNS(8, 8, 4, 4);

  if (!WiFi.config(localIP, gateway, subnet, primaryDNS, secondaryDNS)) {
    Serial.println("STA Failed to configure");
  }

  WiFi.begin(ssid, password);

  Serial.print("Connecting to Wifi " + String(ssid));
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    delay(500);
  }
  Serial.println();

  Serial.println("Connected to the WiFi network");

  IPAddress ip = WiFi.localIP();

  Serial.print("IP address: ");
  Serial.println(ip);

  return ip;
}
