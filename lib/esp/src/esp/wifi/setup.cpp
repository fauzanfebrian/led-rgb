#include <Arduino.h>
#include <ESP8266WiFi.h>

IPAddress setupWifi() {
  const char *ssid = WIFI_SSID;
  const char *password = WIFI_PASSWORD;

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
