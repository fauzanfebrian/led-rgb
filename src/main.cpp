#include <main.h>

#define RED_PIN 9
#define GREEN_PIN 10
#define BLUE_PIN 11

#define LED_PIN 2

#define MIC_PIN A0

String jsonStr = "{\"name\":\"John\", \"age\":30, \"data\":{\"car\": \"BMW\", \"price\": 1000000}}";
JsonPerson person = jsonStr;

void setup()
{
    Serial.begin(9600);
    while (!Serial)
    {
        ; // Wait for the serial port to connect. Needed for native USB port only
    }
    Serial.println("Serial communication started.");

    // set the pins as output
    pinMode(MIC_PIN, INPUT);

    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);

    Serial.println("RGB LED is ready");
}

String inputString = "";
bool stringComplete = false;

void loop()
{
    int micValue = analogRead(MIC_PIN);

    // set the color of the LED
    setRGBValue(micValue, RED_PIN, GREEN_PIN, BLUE_PIN);

    if (stringComplete)
    {
        inputString.trim();
        if (inputString == "on")
        {
            analogWrite(LED_PIN, 255);
            Serial.println("LED is on");
        }
        else if (inputString == "off")
        {
            analogWrite(LED_PIN, 0);
            Serial.println("LED is off");
        }

        Serial.println(inputString);
        inputString = "";
        stringComplete = false;
    }
}

void serialEvent()
{
    while (Serial.available())
    {
        // Get the new byte
        char inChar = (char)Serial.read();

        if (inChar == '\n')
        {
            Serial.println("Enter");
            stringComplete = true;
        }
        else
        {
            inputString += inChar;
            Serial.print(inChar);
        }
    }
}
