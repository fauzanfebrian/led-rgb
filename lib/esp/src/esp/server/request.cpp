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

ServerRequest::ServerRequest(WiFiClient &client) {
  this->client = client;

  String request = client.readStringUntil('\r');
  client.readStringUntil('\n');

  // Extract HTTP method and URL
  int methodEnd = request.indexOf(' ');
  String method = request.substring(0, methodEnd);
  int urlEnd = request.indexOf(' ', methodEnd + 1);
  String url = request.substring(methodEnd + 1, urlEnd);

  // Read the ss and body
  String headers = "";
  String body = "";
  while (client.available()) {
    String line = client.readStringUntil('\r');
    client.readStringUntil('\n');

    if (line.length() == 1 && line[0] == '\n') {
      while (client.available()) {
        body += client.readStringUntil('\r');
        client.readStringUntil('\n');
      }
      break;
    }

    headers += line + "\r\n";
  }

  this->url = url;
  this->method = method;
  this->headers = headers;
  this->body = body;
}

ServerRequest::~ServerRequest() {
  ;
}

void ServerRequest::sendJson(String json) {
  client.print("HTTP/1.1 200 OK\r\n");
  client.print("Content-Type: application/json\r\n");
  client.print("\r\n");
  client.print(json);
  client.stop();
}

void ServerRequest::sendJson(String json, int statusCode) {
  client.print("HTTP/1.1 " + String(statusCode) + " OK\r\n");
  client.print("Content-Type: application/json\r\n");
  client.print("\r\n");
  client.print(json);
  client.stop();
}
