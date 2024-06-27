#include <main.h>

#define RED_PIN 9
#define GREEN_PIN 10
#define BLUE_PIN 11

#define MIC_PIN A0

String jsonStr = "{\"name\":\"John\", \"age\":30, \"data\":{\"car\": \"BMW\", \"price\": 1000000}}";
JsonPerson person = jsonStr;

void setup()
{
    Serial.begin(9600);

    // set the pins as output
    pinMode(MIC_PIN, INPUT);

    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);
}

void loop()
{
    int micValue = analogRead(MIC_PIN);

    // set the color of the LED
    setRGBValue(micValue, RED_PIN, GREEN_PIN, BLUE_PIN);

    delay(100);
}
