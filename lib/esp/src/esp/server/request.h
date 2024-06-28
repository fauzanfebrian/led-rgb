#ifndef SERVER_REQUEST_H
#define SERVER_REQUEST_H

#include <ESP8266WiFi.h>

class ServerRequest {
 private:
  WiFiClient client;

 public:
  String headers;
  String url;
  String body;
  String method;

  ServerRequest(WiFiClient &client);
  ~ServerRequest();

  void sendJson(String json);
  void sendJson(String json, int statusCode);
};

#endif