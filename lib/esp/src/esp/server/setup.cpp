#include <Arduino.h>
#include <ESP8266WiFi.h>

#include "request.h"

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

  String html = "<!DOCTYPE html>\n";
  html += "<html lang=\"en\">\n";
  html += "    <head>\n";
  html += "        <title>RGB Picker</title>\n";
  html += "        <script src=\"https://unpkg.com/vanilla-picker@2.12.3/dist/vanilla-picker.csp.min.js\"></script>\n";
  html += "        <link href=\"https://unpkg.com/vanilla-picker@2.12.3/dist/vanilla-picker.csp.css\" rel=\"stylesheet\" />\n";
  html += "    </head>\n";
  html += "    <body>\n";
  html += "        <div\n";
  html += "            id=\"parent\"\n";
  html += "            style=\"width: 400px; height: 400px; border-radius: 5px; max-width: 400px; max-height: 400px\"\n";
  html += "        ></div>\n";
  html += "        <script>\n";
  html += "            const urlParams = new URLSearchParams(window.location.search);\n";
  html += "            const rgb = urlParams.get('rgb') || '';\n";
  html += "            const [red, green, blue] = rgb ? rgb.split(',').map(Number) : [0, 0, 0];\n";
  html += "            const parent = document.querySelector('#parent');\n";
  html += "            const picker = new Picker({ parent, color: [red, green, blue, 1] });\n";
  html += "            parent.style.background = `rgba(${red}, ${green}, ${blue}, 1)`;\n";
  html += "            picker.onChange = function (color) {\n";
  html += "                parent.style.background = color.rgbaString;\n";
  html += "            }\n";
  html += "            picker.onDone = function (color) {\n";
  html += "                const [red, green, blue] = color?.rgba || [];\n";
  html += "                window.location.search = `rgb=${red},${green},${blue}`;\n";
  html += "            }\n";
  html += "            picker.show();\n";
  html += "        </script>\n";
  html += "    </body>\n";
  html += "</html>\n";

  req.sendHtml(html);
}
