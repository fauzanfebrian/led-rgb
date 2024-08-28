#include <Arduino.h>
#include <local-esp.h>

#include "ws2812.h"

WiFiServer server(80);

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;  // Wait for the serial port to connect. Needed for native USB port only
  }
  Serial.println("Serial communication started.");

  setupWifi();

  server.begin();

  setupLeds();
}

void loop() {
  setupServer(server);
}
