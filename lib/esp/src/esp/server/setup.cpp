#include <Arduino.h>
#include <ESP8266WiFi.h>

#include "request.h"

void setupServer(WiFiServer &server) {
  WiFiClient client = server.accept();
  if (!client) {
    return;
  }

  ServerRequest req(client);

  Serial.println("Method: " + req.method);
  Serial.println("URL: " + req.url);
  Serial.println("Headers: " + req.headers);
  Serial.println("Body: " + req.body);

  req.sendJson("{\"status\":\"ok\"}");
}
