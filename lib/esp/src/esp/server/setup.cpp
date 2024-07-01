#include <Arduino.h>
#include <ESP8266WiFi.h>

#include "request.h"
#include "web.h"

uint8_t RED_PIN = D1;
uint8_t GREEN_PIN = D2;
uint8_t BLUE_PIN = D3;

String extractRGBFromUrl(const String& url) {
  String rgbValue = "";
  int rgbIndex = url.indexOf("rgb=");
  if (rgbIndex != -1) {
    int startIndex = rgbIndex + 4;
    int endIndex = url.indexOf("&", startIndex);
    if (endIndex == -1) {
      endIndex = url.length();
    }
    rgbValue = url.substring(startIndex, endIndex);
  }
  return rgbValue;
}

void setupServer(WiFiServer& server) {
  WiFiClient client = server.accept();
  if (!client) {
    return;
  }

  ServerRequest req(client);

  Serial.println("Method: " + req.method);
  Serial.println("URL: " + req.url);
  Serial.println("Headers: " + req.headers);
  Serial.println("Body: " + req.body);

  String rgbValue = extractRGBFromUrl(req.url);

  if (rgbValue != "") {
    int red, green, blue;
    sscanf(extractRGBFromUrl(req.url).c_str(), "%d,%d,%d", &red, &green, &blue);

    Serial.println("Setup RGB: " + String(red) + ", " + String(green) + ", " + String(blue));

    analogWrite(RED_PIN, red);
    analogWrite(GREEN_PIN, green);
    analogWrite(BLUE_PIN, blue);
  }

  req.sendHtml(RGB_WEB_CONTENT);
}
