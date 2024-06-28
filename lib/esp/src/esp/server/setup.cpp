#include <Arduino.h>
#include <ESP8266WiFi.h>

namespace ESP {

void setupServer(WiFiServer &server) {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  while (!client.available()) {
    delay(1);
  }

  String req = client.readStringUntil('\r');
  client.flush();

  if (req.indexOf("") == 10) {
    Serial.println("invalid request");
    client.stop();
    return;
  }

  if (req.indexOf("/OFF") != -1) {
    Serial.println("You clicked OFF");
  }
  if (req.indexOf("/ON") != -1) {
    Serial.println("You clicked ON");
  }

  String s = "HTTP/1.1 200 OK\r\n";
  s += "Content-Type: application/json\r\n\r\n";
  s += "{\"status\":\"ok\"}";

  client.flush();

  // Send the response to the client
  client.print(s);
  delay(1);
}

}  // namespace ESP
